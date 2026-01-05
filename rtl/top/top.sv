module top #(
  parameter IMEM_HEX = ""
) (
  input  logic clk,
  input  logic rst_n
);

  logic [31:0] pc;
  logic [31:0] instr;

  logic        dmem_we;
  logic [31:0] dmem_addr;
  logic [31:0] dmem_wdata;
  logic [31:0] dmem_rdata;

  imem #(
    .DEPTH_WORDS(256),
    .HEX_FILE(IMEM_HEX)
  ) imem_i (
    .addr(pc),
    .instr(instr)
  );

  dmem #(
    .DEPTH_WORDS(256)
  ) dmem_i (
    .clk(clk),
    .we(dmem_we),
    .addr(dmem_addr),
    .wdata(dmem_wdata),
    .rdata(dmem_rdata)
  );

  core core_i (
    .clk(clk),
    .rst_n(rst_n),
    .instr(instr),
    .pc(pc),
    .dmem_we(dmem_we),
    .dmem_addr(dmem_addr),
    .dmem_wdata(dmem_wdata),
    .dmem_rdata(dmem_rdata)
  );

endmodule
