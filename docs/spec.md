# RV32I CPU Specification

## Scope
This project implements a 32-bit RISC-V CPU with a verification-driven
development flow. Initial bring-up uses a single-cycle core, followed
by a 5-stage pipelined implementation.

## Supported ISA (Milestone 0)
- R-type: ADD, SUB
- I-type: ADDI
- Memory: LW, SW
- Control: BEQ, JAL

## Architectural Rules
- 32 general-purpose registers (x0–x31)
- Register x0 is hardwired to zero
- Little-endian memory
- PC increments by 4 unless modified by control-flow instructions
- All instructions complete in one cycle (Milestone 0 only)

## Memory Model (Milestone 0)
- Separate instruction and data memory
- Instruction memory is read-only
- Data memory supports word-aligned LW/SW
