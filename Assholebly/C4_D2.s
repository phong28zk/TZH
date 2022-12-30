mov r0, #1000H
mov r1, #2000H
mov r2, #2004H
mov r3, #512

loop:
    ldr r5, [r0], #4
    cmp r5, #0
    addgts r6, r6, r5
    cmp r3, #0
    bne loop
    beq save
save:
    str r6, [r2]
    b exit
exit
    b end
    

@ add r5 vào r6 tới khi r6 tràn
@ lưu r6 vào 1 mảng mới ( r8 = 5000H )
@ reset r6 ( LSL 32 bit )
@ Tiếp tục cộng r5 vào r6 đến khi tràn và tiếp tục lưu vào mảng r8
@ Sau khi thực hiện xong mảng r0, cộng các phần tử ở mảng R8 bằng 64 bit
@ r5 = 2^32 => cộng phát tràn luôn