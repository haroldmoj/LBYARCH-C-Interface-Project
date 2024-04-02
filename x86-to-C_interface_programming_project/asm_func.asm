; Mojica, Harold C. | Yung Cheng, Adrian U. | S15

;%include "io64.inc"
section .data
displayCurrent db "Current: %1.2f", 10, 0
displaySum db "Sum: %1.2f", 10, 0
separator db "-------", 10, 0

; ENTER X HERE (VECTOR VALUES)
X dd 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0
; ENTER N HERE (X SIZE)
n dd 8

Y times 10 dd  0.0
float_zero dd 0.0


i dd 0
yIndex dd 0

offset dd 0


scanfp db "%f", 0
scanstr db "%s", 0

section .text
bits 64
default rel

global asm_kernel
extern printf, scanf
asm_kernel:
    mov rbp, rsp; for correct debugging
    mov esi, 3
    sub esp, 8 * 7
    
while_loop:
    movss xmm0, [float_zero]
    mov r8d, -3
    mov r10d, [n] ; <- replace with [n]
    sub r10d, 3
    cmp esi, r10d ; <- replace with n - 3, since the function requires all to have values, and an index more than n - 3 gives null/0
    je exit
    
    inner_while:
        ; current i
        mov ebx, esi
        
        cmp ebx, 0
        jge cont_inner_while
        
        ; jmp negative_index
        
    cont_inner_while:
        add ebx, r8d
        ; Increment r8d
        inc r8d
        ; Move r8d to offset
        mov dword [offset], r8d
        
        movss xmm1, [X + ebx * 4]
        addss xmm0, xmm1
        
        ; return offset to r8d
        mov r8d, dword [offset]        
                
        cmp r8d, 4
        je end_inner_loop
     
        jmp inner_while
        
    end_inner_loop:
        ; Print Current Sum
        mov ebx, [yIndex]
        movss dword [Y + ebx * 4], xmm0
        mov edx, [Y + ebx * 4]
        mov ecx, displaySum
        call printf
        mov ecx, separator
        call printf
        inc dword [yIndex]
        jmp cont_while_loop
    
cont_while_loop:
    inc esi
    jmp while_loop
    
exit:
    add esp, 8 * 7
    
    xor rax, rax
    ret