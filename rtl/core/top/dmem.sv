module dmem #(
  parameter int DEPTH_WORDS = 256
) (
  input  logic        clk,
  input  logic        we,
  input  logic [31:0] addr,
  input  logic [31:0] wdata,
  output logic [31:0] rdata
);

  logic [31:0] mem [0:DEPTH_WORDS-1];

  logic [$clog2(DEPTH_WORDS)-1:0] word_addr;
  assign word_addr = addr[($clog2(DEPTH_WORDS)+1):2];

  // Combinational read
  always_comb begin
    rdata = mem[word_addr];
  end

  // Sync write
  always_ff @(posedge clk) begin
    if (we) mem[word_addr] <= wdata;
  end

endmodule
