# RV32I CPU (5-stage pipeline) + Verification

A SystemVerilog RV32I CPU project focused on **integration** and **verification**:
- Directed + constrained-random testing
- Assertions (SVA)
- Functional coverage
- Scoreboard / reference-model checking
- CI automation (GitHub Actions)

## Repo layout
- `rtl/` — synthesizable CPU RTL
- `tb/` — testbench (directed, random, assertions, coverage, scoreboard)
- `tests/` — assembly + test vectors
- `sim/` — simulation scripts / Makefile
- `docs/` — spec, microarchitecture, verification plan

## Quickstart (will work after Milestone 0)
```bash
make -C sim test
