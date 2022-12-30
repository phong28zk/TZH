@ Compare two string using assembly language
@ If two strings are equal, print "Equal"
@ If two strings are not equal, print "Not Equal"

adr r0, 1000H
adr r1, 2000H
1000H DB "Hello", 0;
2000H DB "Hello", 0;
diff DB "No", 0;
same DB "Yes", 0;
res DB "kq", 0;
loop
    ldr r2, [r0], #1
    ldr r3, [r1], #1
    cmp r2, r3
    bne not_equal
    cmp r2, #0
    beq equal
    b loop
not_equal
    adr r0, diff
    b print
equal
    adr r0, same
print
    ldr r1, [r0], #1
    str r1, [r4], #1
    cmp r1, #0
    bne print
    b loop


