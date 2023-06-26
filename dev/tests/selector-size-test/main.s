Section .data
pString db "The value is %x", 10, 0;
data db 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF;

Section .text
global _WinMain
extern printf

_WinMain:
    push rbp;
    mov rbp, rsp;
    sub rsp, 32
    lea rcx, pString;
    mov rdx, [data];
    mov rax, 0
    call printf;
    mov rax, 0;
    mov edx, dword data[4];
    call printf;
    mov rax, 0;
    mov rdx, 0;
    mov dx, word data[6];
    call printf;
    mov rax, 0;
    mov rdx, 0;
    mov dl, byte data[7];
    call printf;
    add rsp, 32;
    pop rbp;
    ret;
