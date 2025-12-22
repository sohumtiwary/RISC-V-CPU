.section .text
.global _start

_start:
    addi x1, x0, 5      # x1 = 5
    addi x2, x1, 7      # x2 = 12
    add  x3, x1, x2     # x3 = 17

    # infinite loop to stop execution
end:
    jal x0, end
