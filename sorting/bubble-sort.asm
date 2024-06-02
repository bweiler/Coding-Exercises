.section .data
arr:
    .word 64, 34, 25, 12, 22, 11, 90
n:
    .word 7

.section .text
.globl _start

_start:
    // Load the address of the array into a register
    LDR r0, =arr
    // Load the number of elements into a register
    LDR r1, =n
    LDR r1, [r1]

    // Outer loop: iterate over each element
outer_loop:
    // Initialize flag for swapped elements
    MOV r2, #0

    // Inner loop: iterate over each element except the last one
    MOV r3, r1    // r3 holds the number of comparisons for this iteration
    SUBS r3, r3, #1    // Decrement r3 by 1
inner_loop:
    // Load the current array element into r4
    LDR r4, [r0], #4    // Load the word at the address in r0 into r4 and increment r0 by 4 bytes

    // Compare current element with the next element
    LDR r5, [r0]
    CMP r4, r5
    BLE no_swap    // Branch if r4 <= r5 (no swap needed)

    // Swap the elements
    STR r5, [r0, #-4]!    // Store the value of r5 at the address in r0-4 and decrement r0 by 4 bytes
    STR r4, [r0]

    // Set flag to indicate that a swap occurred
    MOV r2, #1

no_swap:
    SUBS r3, r3, #1    // Decrement the comparison counter
    BNE inner_loop    // Branch to inner_loop if r3 != 0 (more comparisons needed)

    // If no swap occurred, the array is sorted
    CMP r2, #0
    BEQ sorted

    // Decrement the number of elements
    SUBS r1, r1, #1

    // Repeat the outer loop
    B outer_loop

sorted:
    // End program execution
    MOV r0, #0x18    // SVC number for "exit" syscall
    MOV r7, #0x1     // "exit" syscall number
    SWI 0            // Make a syscall
