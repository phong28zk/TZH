mov r0, value0
mov r1, value1
mov r2, value2
mov r3, value3

mov r4, r0;
mov r5, r0;
cmp r4, r1;
movgt r4, r1;
cmp r4, r2;
movgt r4, r2;
cmp r4, r3;
movgt r4, r3;
cmp r5, r1;
movlt r5, r1;
cmp r5, r2;
movlt r5, r2;
cmp r5, r3;
movlt r5, r3;

