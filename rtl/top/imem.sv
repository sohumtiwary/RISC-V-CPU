module imem #(
  parameter int DEPTH_WORDS = 256,
  parameter HEX_FILE = ""
) (
  input  logic [31:0] addr,
  output logic [31:0] instr
);

  logic [31:0] mem [0:DEPTH_WORDS-1];

  // Word address (PC is byte addr)
  logic [$clog2(DEPTH_WORDS)-1:0] word_addr;
  assign word_addr = addr[($clog2(DEPTH_WORDS)+1):2];

  // Combinational read
  always_comb begin
    instr = mem[word_addr];
  end

  initial begin
    if (HEX_FILE != "") begin
      $display("[IMEM] Loading hex: %s", HEX_FILE);
      $readmemh(HEX_FILE, mem);
    end else begin
      $display("[IMEM] No HEX_FILE provided; IMEM contents undefined.");
    end
  end

endmodule
