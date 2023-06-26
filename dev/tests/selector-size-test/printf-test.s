	.file	"printf-test.c"
	.intel_syntax noprefix
	.text
	.globl	h
	.data
	.align 4
h:
	.long	10
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Var test: %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	mov	eax, DWORD PTR h[rip]
	mov	edx, eax
	lea	rax, .LC0[rip]
	mov	rcx, rax
	int3;
	call	printf
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 12.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
