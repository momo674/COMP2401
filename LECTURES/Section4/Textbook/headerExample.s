	.file	"headerExample.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "DEBUG\12\0"
.LC1:
	.ascii "x + *y = %d\12\0"
.LC2:
	.ascii "Days = %d, PI = %f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$15, -12(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movabsq	$4614256650576692846, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm0
	movapd	%xmm0, %xmm2
	movq	%rax, %r8
	movl	$7, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
