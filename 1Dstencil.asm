; Harold, Mojica C. | Yung Cheng, Adrian U. | S15

%include "io64.inc"
section .data
displayCurrent db "Current: %1.2lf", 10, 0
displaySum db "Sum: %1.2lf", 10, 0
X times 30 dq  0.0
Y times 30 dq  0.0
float_zero dq 0.0
tempX dq 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0

n dq 0
tempN dq 8
i dq 0
yIndex dq 0

offset dq 0


scanfp db "%lf", 0
scanstr db "%s", 0

section .text
bits 64
default rel

global main
extern printf, scanf
main:
    mov rbp, rsp; for correct debugging
    mov rsi, 0
    sub rsp, 8 * 7
    
while_loop:
    movsd xmm0, [float_zero]
    mov r8, -3
    cmp rsi, 5 ; n - 3, since the function requires all to have values, and an index more than n - 3 gives null/0
    je exit
    
    inner_while:
        ; current i
        mov rbx, rsi
        ; i + rsi(-3 to 3)
        add rbx, r8
        cmp rbx, 0
        jl negative_index
        
        jmp cont_inner_while
        
        negative_index:
            mov r9, 8
            dec r9
            add rbx, r9
            
;            PRINT_DEC 8, rbx
;            NEWLINE
            
            jmp cont_inner_while
        
    cont_inner_while:
        ; Increment R8
        inc r8
        ; Move r8 to offset for printing
        mov qword [offset], r8
        
;        ; Print Current Number from indexing (tracing)
;        mov rdx, [tempX + rbx * 8]
;        mov rcx, displayCurrent
;        call printf
        
        movsd xmm1, [tempX + rbx * 8]
        addsd xmm0, xmm1
        
        ; return offset to r8
        mov r8, qword [offset]
;        PRINT_DEC 8, r8
;        NEWLINE
        
                
        cmp r8, 4
        je end_inner_loop

        
        jmp inner_while
        
    end_inner_loop:
        ; Print Current Sum
        mov rbx, [yIndex]
        movsd qword [Y + rbx * 8], xmm0
        mov rdx, [Y + rbx * 8]
        mov rcx, displaySum
        call printf
        PRINT_STRING "-------"
        NEWLINE
        jmp cont_while_loop
    
    
cont_while_loop:
    inc rsi
    jmp while_loop
    
exit:
    add rsp, 8 * 7
    
    xor rax, rax
    ret