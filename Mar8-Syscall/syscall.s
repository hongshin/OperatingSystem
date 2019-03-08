.intel_syntax noprefix

.text
    .globl mysyscall

	mysyscall:
        mov rax,rdi
        mov rdi,rsi
        mov rsi,rdx
        mov rdx,rcx
        mov r10,r8
        mov r8,r9
        syscall
        ret
