#include "Vtb_top.h"
#include "verilated.h"
#include <cstdint>

vluint64_t main_time = 0;

// Verilator sometimes expects this symbol when timing is enabled.
double sc_time_stamp() {
  return (double)main_time;
}

static void tick(Vtb_top* top) {
  top->clk = 0;
  top->eval();
  main_time++;

  top->clk = 1;
  top->eval();
  main_time++;
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  auto* top = new Vtb_top;

  // Start in reset
  top->rst_n = 0;

  // A few cycles in reset
  for (int i = 0; i < 5; i++) tick(top);

  // Release reset
  top->rst_n = 1;

  // Run until $finish
  while (!Verilated::gotFinish()) {
    tick(top);
  }

  delete top;
  return 0;
}
