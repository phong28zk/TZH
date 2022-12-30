ldr r0=value1;
ldr r1, [r0];
ldr r2, [r0, #4];
ldr r0=value2;
ldr r3, [r0];
ldr r4, [r0, #4];
adds r5, r2, r4;
adc r6, r1, r3;
ldr r0, =result;

str r5, [r0];
str r6, [r0, #4];
end.