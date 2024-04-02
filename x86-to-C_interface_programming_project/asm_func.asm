; Mojica, Harold C. | Yung Cheng, Adrian U. | S15

;%include "C:\Program Files\NASM\io64.inc"
section .data
displayCurrent db "Current: %1.2lf", 10, 0
displaySum db "Sum: %1.2lf", 10, 0
separator db "-------", 10, 0

; ENTER X HERE (VECTOR VALUES)
X dq 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0
; ENTER N HERE (X SIZE)
n dq 8

Y times 10 dq  0.0
float_zero dq 0.0
;X dq 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0
;X dq 9.0, 1.0, 6.0, 4.0, 17.0, 2.0, 6.0, 8.0, 60.0


i dq 0
yIndex dq 0

offset dq 0


scanfp db "%lf", 0
scanstr db "%s", 0

section .text
bits 64
default rel

global asm_kernel
extern printf, scanf
asm_kernel:
    mov rbp, rsp; for correct debugging
    mov rsi, 3
    sub rsp, 8 * 7
    
while_loop:
    movsd xmm0, [float_zero]
    mov r8, -3
    mov r10, [n] ; <replace with [n]
    sub r10, 3
    cmp rsi, r10 ; <- replace with n - 3, since the function requires all to have values, and an index more than n - 3 gives null/0
    je exit
    
    inner_while:
        ; current i
        mov rbx, rsi
        
        cmp rbx, 0
        jge cont_inner_while
        
        ; jmp negative_index
        
;       negative_index:
;            mov r9, [n] ; <- replace with [n]
;            dec r9
;            add rbx, r9
;            
;            PRINT_DEC 8, rbx
;            NEWLINE
;            
;            jmp cont_inner_while
        
    cont_inner_while:
        add rbx, r8
        ; Increment R8
        inc r8
        ; Move r8 to offset
        mov qword [offset], r8
        
;        ; Print Current Number from indexing (tracing)
;        mov rdx, [tempX + rbx * 8]
;        mov rcx, displayCurrent
;        call printf
        
        movsd xmm1, [X + rbx * 8]
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
        mov rcx, separator
        call printf
        NEWLINE
        inc qword [yIndex]
        jmp cont_while_loop
    
    
cont_while_loop:
    inc rsi
    jmp while_loop
    
exit:
    add rsp, 8 * 7
    
    xor rax, rax
    ret