@ number1: R0, R1
@ number2: R2, R3

@ We have solution like this:
@ R0*R2 is the highest part, R2*R3 is the lowest part
@ R1*R2+R3*R0 is the middle part

umull r4, r5, r1, r3;
umull r6, r7, r0, r3;
umull r8, r9, r1, r2;
umull r10, r11, r0, r2;

adds r5, r5, r6;
addc r7, r7, #0;
adds r5, r5, r8;
addc r9, r9, #0;
adds r7, r7, r9;
adc r11, r11, #0;
adds r7, r7, r10;
adc r11, r11, #0;

kq -> r4, r5, r7, r11



