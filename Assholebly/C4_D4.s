mov r1, #1000H          // Dia chi o nho dau tien cua mang
mov r2, #8000H          // Dia chi luu gia tri can tinh
mov r3, #1024           // So phan tu cua mang
mov r4, #0      
mov r6, #0              // Value 
loop:  
    ldr r7, [r1], #2;   // r7 = M[r1], r1=r1+2;
    mov r8, r7;         // r8 = r7
    and r8, r8, 1;      // r8 = r8 & 1
    cmp r8, 0;          // cmp r8 with 0, if r8=0 add r7 to r6
    addeq r6, r6, r7;
    add r4, r4, #1;     // r4 = r4 + 1
    cmp r4, r3;         // cmp r4 with r3
    bne loop;           // if r4 != r3, loop
    b end;              // if r4 = r3, end
end:
    str r7, [r2];
