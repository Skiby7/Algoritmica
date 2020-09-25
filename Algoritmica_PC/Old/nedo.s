	.file	"nedo.c"
	.text
	.p2align 4
	.globl	nedofunky
	.type	nedofunky, @function
nedofunky:
.LFB11:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leal	-1(%rsi), %r13d
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	testl	%r13d, %r13d
	jle	.L1
	movq	%rdi, %r11
	movl	%esi, %r8d
	movq	%rdi, %rbx
	xorl	%r10d, %r10d
	.p2align 4,,10
	.p2align 3
.L6:
	movl	%r10d, %r9d
	addl	$1, %r10d
	movl	(%rbx), %ebp
	cmpl	%r10d, %r8d
	jle	.L8
	leaq	4(%rbx), %r12
	movl	%ebp, %esi
	movl	%r10d, %edx
	movq	%r12, %rax
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L15:
	movslq	%r9d, %rcx
	addl	$1, %edx
	addq	$4, %rax
	leaq	(%r11,%rcx,4), %rdi
	cmpl	%edx, %r8d
	je	.L3
.L5:
	movl	(%rax), %ecx
	movq	%rax, %rdi
	cmpl	%esi, %ecx
	jge	.L15
	movl	%edx, %r9d
	addl	$1, %edx
	movl	%ecx, %esi
	addq	$4, %rax
	cmpl	%edx, %r8d
	jne	.L5
.L3:
	movl	%ebp, (%rdi)
	movl	%esi, (%rbx)
	movq	%r12, %rbx
	cmpl	%r13d, %r10d
	jne	.L6
.L1:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	.cfi_restore_state
	movq	%rbx, %rdi
	movl	%ebp, %esi
	leaq	4(%rbx), %r12
	movl	%ebp, (%rdi)
	movl	%esi, (%rbx)
	movq	%r12, %rbx
	cmpl	%r13d, %r10d
	jne	.L6
	jmp	.L1
	.cfi_endproc
.LFE11:
	.size	nedofunky, .-nedofunky
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Mi dica, mi dica: "
.LC1:
	.string	"%d %d %d"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Ecco qui i tre nani in ordine:\n%d %d %d"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$.LC0, %edi
	xorl	%eax, %eax
	call	printf
	leaq	12(%rsp), %rcx
	leaq	8(%rsp), %rdx
	xorl	%eax, %eax
	leaq	4(%rsp), %rsi
	movl	$.LC1, %edi
	call	__isoc99_scanf
	leaq	4(%rsp), %rdi
	movl	$3, %esi
	call	nedofunky
	movl	12(%rsp), %ecx
	movl	8(%rsp), %edx
	xorl	%eax, %eax
	movl	4(%rsp), %esi
	movl	$.LC2, %edi
	call	printf
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.1 20200723 (Red Hat 10.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
