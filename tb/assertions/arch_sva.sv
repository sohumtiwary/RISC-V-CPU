module arch_sva;

  always_ff @(posedge tb_top.clk or negedge tb_top.rst_n) begin
    if (!tb_top.rst_n) begin
      // nothing during reset
    end else begin
      if (tb_top.dut.core_i.regs[0] !== 32'd0) begin
        $fatal(1, "[ASSERT] x0 is not zero! x0=%0d", tb_top.dut.core_i.regs[0]);
      end
    end
  end

endmodule
