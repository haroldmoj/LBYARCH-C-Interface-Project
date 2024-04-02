; Mojica, Harold C. | Yung Cheng, Adrian U. | S15
section .text

bits 64
default rel

global asm_kernel
asm_kernel:
    push rbp
    mov rbp, rsp
    
    mov rdi, rcx
    mov rsi, rdx
    mov edx, r8d
    
    xor rax, rax
    
    mov ecx, 3
    
start:
    movss xmm0, dword [rdi + rcx * 4 - 12]
    addss xmm0, dword [rdi + rcx * 4 - 8] 
    addss xmm0, dword [rdi + rcx * 4 - 4] 
    addss xmm0, dword [rdi + rcx * 4]     
    addss xmm0, dword [rdi + rcx * 4 + 4] 
    addss xmm0, dword [rdi + rcx * 4 + 8] 
    addss xmm0, dword [rdi + rcx * 4 + 12]

    movss dword [rsi + rcx * 4 - 12], xmm0

    inc ecx
    cmp ecx, edx
    jl start
    
    pop rbp
    ret