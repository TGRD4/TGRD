	.file	"cake.c"
	.text
	.globl	sum
	.bss
	.align 4
	.type	sum, @object
	.size	sum, 4
sum:
	.zero	4
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"no!"
.LC2:
	.string	"ok!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$0, -80(%rbp)
	movl	$0, -76(%rbp)
	leaq	-92(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-92(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	movl	$0, -84(%rbp)
	jmp	.L2
.L3:
	movl	-84(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-64(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	addl	%eax, -80(%rbp)
	addl	$1, -84(%rbp)
.L2:
	movl	-92(%rbp), %eax
	cmpl	%eax, -84(%rbp)
	jl	.L3
	movl	-80(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L4
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L5
.L4:
	movl	$0, -88(%rbp)
	jmp	.L6
.L10:
	movq	-64(%rbp), %rax
	movl	-88(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	sum(%rip), %eax
	addl	%edx, %eax
	movl	%eax, sum(%rip)
	movl	-80(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %edx
	movl	sum(%rip), %eax
	cmpl	%eax, %edx
	jne	.L7
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L5
.L7:
	movl	-80(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %edx
	movl	sum(%rip), %eax
	cmpl	%eax, %edx
	jge	.L13
	movl	sum(%rip), %ecx
	movq	-64(%rbp), %rax
	movl	-88(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, sum(%rip)
	jmp	.L9
.L13:
	nop
.L9:
	addl	$1, -88(%rbp)
.L6:
	movl	-92(%rbp), %eax
	cmpl	%eax, -88(%rbp)
	jl	.L10
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
.L5:
	movq	%rbx, %rsp
	movq	-56(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
