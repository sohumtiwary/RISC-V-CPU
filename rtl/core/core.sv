module core (
  input  logic        clk,
  input  logic        rst_n,

  input  logic [31:0] instr,

  output logic [31:0] pc,

  // dmem interface (Milestone 0 keeps it simple; not used by add_basic)
  output logic        dmem_we,
  output logic [31:0] dmem_addr,
  output logic [31:0] dmem_wdata,
  input  logic [31:0] dmem_rdata
);

  // Register file
  logic [31:0] regs [0:31];

  // Debug taps (optional but useful)
  // Access in TB as: dut.core_i.regs[1]
  // (no extra ports needed)

  // Decode
  logic [6:0] opcode;
  logic [2:0] funct3;
  logic [6:0] funct7;
  logic [4:0] rd, rs1, rs2;

  assign opcode = instr[6:0];
  assign rd     = instr[11:7];
  assign funct3 = instr[14:12];
  assign rs1    = instr[19:15];
  assign rs2    = instr[24:20];
  assign funct7 = instr[31:25];

  // Immediates
  logic [31:0] imm_i, imm_j;
  always_comb begin
    imm_i = {{20{instr[31]}}, instr[31:20]};
    imm_j = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
  end

  // Read operands (x0 reads as 0)
  logic [31:0] rs1_val, rs2_val;
  always_comb begin
    rs1_val = (rs1 == 5'd0) ? 32'd0 : regs[rs1];
    rs2_val = (rs2 == 5'd0) ? 32'd0 : regs[rs2];
  end

  // Control / writeback
  logic        reg_we;
  logic [31:0] reg_wdata;
  logic [31:0] next_pc;

  // Defaults
  always_comb begin
    dmem_we    = 1'b0;
    dmem_addr  = 32'd0;
    dmem_wdata = 32'd0;

    reg_we     = 1'b0;
    reg_wdata  = 32'd0;

    next_pc    = pc + 32'd4;

    unique case (opcode)
      7'b0010011: begin // OP-IMM (ADDI only for M0)
        if (funct3 == 3'b000) begin
          reg_we    = 1'b1;
          reg_wdata = rs1_val + imm_i;
        end
      end

      7'b0110011: begin // OP (ADD only for M0)
        if (funct3 == 3'b000 && funct7 == 7'b0000000) begin
          reg_we    = 1'b1;
          reg_wdata = rs1_val + rs2_val;
        end
      end

      7'b1101111: begin // JAL
        reg_we    = 1'b1;
        reg_wdata = pc + 32'd4;  // link address
        next_pc   = pc + imm_j;
      end

      default: begin
        // NOP / unimplemented -> do nothing
      end
    endcase
  end

  // Sequential state update
  integer i;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      pc <= 32'd0;
      for (i = 0; i < 32; i++) regs[i] <= 32'd0;
    end else begin
      pc <= next_pc;

      // Enforce x0 hardwired to 0 by ignoring writes to rd==0
      if (reg_we && (rd != 5'd0)) begin
        regs[rd] <= reg_wdata;
      end

      // Also keep x0 pinned (belt + suspenders)
      regs[0] <= 32'd0;
    end
  end

endmodule
