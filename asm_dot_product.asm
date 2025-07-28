section .text
bits 64
default rel
global asm_dot_product

; Returns the dot product of two n-element vectors a and b
asm_dot_product:
    xorps xmm3, xmm3 ; Clears garbage in XMM0 register
    
    l1: 
        movsd xmm1, [rdx]
        movsd xmm2, [r8]
        
        mulsd xmm1, xmm2
        addsd xmm0, xmm1
        
        add rdx, 8
        add r8, 8
        
        loop l1
    
    movsd [r9], xmm0 ; Store to memory location

    ret