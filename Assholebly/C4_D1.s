mov r1, #1000H
mov r2, #2000H
mov r3, #1999H
bl loop
loop
    ldrb r4, [r1], #1
    strb r4, [r2], #1
    cmp r4, #0x00
    bne loop
    mov pc, lr 
    end.


@ Assume that R6 is the address of the array A
@ Assume that R7 is the address of the array B


