module tb_top(
  input  logic clk,
  input  logic rst_n
);

  top #(
    .IMEM_HEX("../tests/vectors/add_basic.hex")
  ) dut (
    .clk(clk),
    .rst_n(rst_n)
  );

  arch_sva sva();

  initial begin
    // No clock gen here (C++ drives clk)
    // Reset is also driven from C++ now, so don't assign rst_n here.

    // Wait a few cycles after reset release
    repeat (5) @(posedge clk);

    // Run enough cycles for the program
    repeat (20) @(posedge clk);

    if (dut.core_i.regs[1] !== 32'd5)  $fatal(1, "[SB] x1 expected 5, got %0d", dut.core_i.regs[1]);
    if (dut.core_i.regs[2] !== 32'd12) $fatal(1, "[SB] x2 expected 12, got %0d", dut.core_i.regs[2]);
    if (dut.core_i.regs[3] !== 32'd17) $fatal(1, "[SB] x3 expected 17, got %0d", dut.core_i.regs[3]);

    $display("[PASS] add_basic checks passed.");
    $finish;
  end

endmodule
