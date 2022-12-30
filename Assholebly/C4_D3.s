mov r0, #2000H
mov r1, #1000H
mov r2, #1004H
mov r3, #1008H
mov r4, #256
mov r5, #0
mov r11, #0
mov r12, #0
mov r13, #0

loop:
    ldr r6, [r0], #1;
    cmp r6, #0
    addlt r11, r11, #1;
    addeq r12, r12, #1;
    addgt r13, r13, #1;
    str r11, [r1];
    str r12, [r2];
    str r13, [r3];
    end.

