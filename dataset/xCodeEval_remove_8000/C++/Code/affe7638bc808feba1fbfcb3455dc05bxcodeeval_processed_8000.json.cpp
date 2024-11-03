__asm__(R"(
	.file	"1.cpp"
	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB10191:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6lowbiti
	.def	_Z6lowbiti;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6lowbiti
_Z6lowbiti:
.LFB8905:
	.seh_endprologue
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z3addiii
	.def	_Z3addiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3addiii
_Z3addiii:
.LFB8906:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	n(%rip), %r15d
	cmpl	%r15d, %ecx
	jg	.L4
	movl	m(%rip), %r12d
	movl	%ecx, %ebp
	movl	%r8d, %r13d
	movl	%edx, %r14d
	imull	%r8d, %ebp
	imull	%edx, %r13d
	imull	%ebp, %r14d
	cmpl	%r12d, %edx
	jg	.L4
	leaq	t1(%rip), %rsi
	leaq	t2(%rip), %rbx
	leaq	t3(%rip), %r11
	leaq	t4(%rip), %r10
	.p2align 4,,10
.L9:
	movslq	%ecx, %rdi
	movl	%edx, %r9d
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L7:
	movslq	%r9d, %rax
	addq	%rdi, %rax
	addl	%r8d, (%rsi,%rax,4)
	addl	%ebp, (%rbx,%rax,4)
	addl	%r13d, (%r11,%rax,4)
	addl	%r14d, (%r10,%rax,4)
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r12d, %r9d
	jle	.L7
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r15d, %ecx
	jle	.L9
.L4:
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z8real_addiiiii
	.def	_Z8real_addiiiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8real_addiiiii
_Z8real_addiiiii:
.LFB8907:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$24, %rsp
	.seh_stackalloc	24
	.seh_endprologue
	movl	n(%rip), %eax
	movl	128(%rsp), %r15d
	addl	$1, %r9d
	negl	%r15d
	cmpl	%eax, %ecx
	movl	%r8d, 112(%rsp)
	movl	%eax, 8(%rsp)
	jg	.L19
	movl	128(%rsp), %r12d
	movl	128(%rsp), %eax
	movl	m(%rip), %r14d
	imull	%ecx, %r12d
	imull	%edx, %eax
	movl	%r12d, %r13d
	imull	%edx, %r13d
	cmpl	%r14d, %edx
	movl	%eax, 12(%rsp)
	jg	.L15
	leaq	t1(%rip), %rbx
	movl	%ecx, %edi
	leaq	t2(%rip), %r11
	leaq	t3(%rip), %r10
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L17:
	movslq	%edi, %rbp
	movl	%edx, %esi
	movl	%edx, 104(%rsp)
	imulq	$1007, %rbp, %rbp
	.p2align 4,,10
.L16:
	movslq	%esi, %r8
	movl	128(%rsp), %edx
	addq	%rbp, %r8
	addl	%edx, (%rbx,%r8,4)
	addl	%r12d, (%r11,%r8,4)
	addl	%r13d, (%rax,%r8,4)
	movl	12(%rsp), %edx
	addl	%edx, (%r10,%r8,4)
	movl	%esi, %r8d
	negl	%r8d
	andl	%esi, %r8d
	addl	%r8d, %esi
	cmpl	%r14d, %esi
	jle	.L16
	movl	%edi, %r8d
	movl	104(%rsp), %edx
	negl	%r8d
	andl	%edi, %r8d
	addl	%r8d, %edi
	cmpl	8(%rsp), %edi
	jle	.L17
.L15:
	movl	%ecx, %ebp
	movl	%r15d, %r12d
	imull	%r15d, %ebp
	imull	%r9d, %r12d
	movl	%ebp, %r13d
	imull	%r9d, %r13d
	cmpl	%r9d, %r14d
	jl	.L19
	leaq	t1(%rip), %rbx
	leaq	t2(%rip), %r11
	leaq	t3(%rip), %r10
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L21:
	movslq	%ecx, %rdi
	movl	%r9d, %esi
	movl	%edx, 12(%rsp)
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L18:
	movslq	%esi, %r8
	movl	128(%rsp), %edx
	addq	%rdi, %r8
	subl	%edx, (%rbx,%r8,4)
	addl	%ebp, (%r11,%r8,4)
	addl	%r12d, (%r10,%r8,4)
	addl	%r13d, (%rax,%r8,4)
	movl	%esi, %r8d
	negl	%r8d
	andl	%esi, %r8d
	addl	%r8d, %esi
	cmpl	%r14d, %esi
	jle	.L18
	movl	%ecx, %r8d
	movl	12(%rsp), %edx
	negl	%r8d
	andl	%ecx, %r8d
	addl	%r8d, %ecx
	cmpl	8(%rsp), %ecx
	jle	.L21
.L19:
	movl	112(%rsp), %eax
	leal	1(%rax), %r8d
	cmpl	8(%rsp), %r8d
	jg	.L11
	movl	%r15d, %r13d
	movl	m(%rip), %ebp
	movl	%r15d, %r14d
	movl	%edx, %r15d
	imull	%r8d, %r13d
	imull	%edx, %r14d
	imull	%r13d, %r15d
	cmpl	%ebp, %edx
	jg	.L22
	leaq	t1(%rip), %rbx
	movl	%r8d, %edi
	leaq	t2(%rip), %r11
	leaq	t3(%rip), %r10
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L24:
	movslq	%edi, %r12
	movl	%edx, %esi
	movl	%edx, 104(%rsp)
	imulq	$1007, %r12, %r12
	.p2align 4,,10
.L23:
	movslq	%esi, %rcx
	movl	128(%rsp), %edx
	addq	%r12, %rcx
	subl	%edx, (%rbx,%rcx,4)
	addl	%r13d, (%r11,%rcx,4)
	addl	%r14d, (%r10,%rcx,4)
	addl	%r15d, (%rax,%rcx,4)
	movl	%esi, %ecx
	negl	%ecx
	andl	%esi, %ecx
	addl	%ecx, %esi
	cmpl	%ebp, %esi
	jle	.L23
	movl	%edi, %ecx
	movl	104(%rsp), %edx
	negl	%ecx
	andl	%edi, %ecx
	addl	%ecx, %edi
	cmpl	8(%rsp), %edi
	jle	.L24
.L22:
	movl	128(%rsp), %edi
	movl	128(%rsp), %r12d
	imull	%r8d, %edi
	imull	%r9d, %r12d
	movl	%edi, %r13d
	imull	%r9d, %r13d
	cmpl	%r9d, %ebp
	jl	.L11
	movl	128(%rsp), %esi
	leaq	t1(%rip), %rbx
	leaq	t2(%rip), %r11
	leaq	t3(%rip), %r10
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L27:
	movslq	%r8d, %r14
	movl	%r9d, %ecx
	imulq	$1007, %r14, %r14
	.p2align 4,,10
.L26:
	movslq	%ecx, %rdx
	addq	%r14, %rdx
	addl	%esi, (%rbx,%rdx,4)
	addl	%edi, (%r11,%rdx,4)
	addl	%r12d, (%r10,%rdx,4)
	addl	%r13d, (%rax,%rdx,4)
	movl	%ecx, %edx
	negl	%edx
	andl	%ecx, %edx
	addl	%edx, %ecx
	cmpl	%ebp, %ecx
	jle	.L26
	movl	%r8d, %edx
	negl	%edx
	andl	%r8d, %edx
	addl	%edx, %r8d
	cmpl	8(%rsp), %r8d
	jle	.L27
.L11:
	addq	$24, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z3askii
	.def	_Z3askii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3askii
_Z3askii:
.LFB8908:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	testl	%ecx, %ecx
	je	.L39
	leal	1(%rdx), %ebx
	xorl	%eax, %eax
	leal	1(%rcx), %r11d
	movl	%ebx, %r13d
	imull	%r11d, %r13d
	leaq	t1(%rip), %r12
	leaq	t2(%rip), %rbp
	leaq	t3(%rip), %rdi
	leaq	t4(%rip), %rsi
	.p2align 4,,10
.L38:
	testl	%edx, %edx
	je	.L36
	movslq	%ecx, %r10
	movl	%edx, %r9d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L37:
	movslq	%r9d, %r14
	addq	%r10, %r14
	movl	(%r12,%r14,4), %r8d
	movl	0(%rbp,%r14,4), %r15d
	imull	%r13d, %r8d
	imull	%ebx, %r15d
	subl	%r15d, %r8d
	movl	(%rdi,%r14,4), %r15d
	imull	%r11d, %r15d
	subl	%r15d, %r8d
	addl	(%rsi,%r14,4), %r8d
	addl	%r8d, %eax
	leal	-1(%r9), %r8d
	andl	%r8d, %r9d
	jne	.L37
.L36:
	leal	-1(%rcx), %r8d
	andl	%r8d, %ecx
	jne	.L38
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L39:
	xorl	%eax, %eax
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z8real_askiiii
	.def	_Z8real_askiiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8real_askiiii
_Z8real_askiiii:
.LFB8909:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$24, %rsp
	.seh_stackalloc	24
	.seh_endprologue
	leal	-1(%rdx), %eax
	testl	%r8d, %r8d
	movl	%ecx, 96(%rsp)
	movl	%eax, 8(%rsp)
	je	.L62
	leal	1(%r8), %ebx
	movl	%r8d, %eax
	movl	$0, 12(%rsp)
	leal	1(%r9), %edi
	movl	%ebx, %r13d
	imull	%edi, %r13d
	leaq	t1(%rip), %r12
	leaq	t2(%rip), %rbp
	leaq	t3(%rip), %r15
	.p2align 4,,10
.L50:
	testl	%r9d, %r9d
	je	.L47
	movslq	%eax, %r11
	movl	%r9d, %r10d
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L48:
	movslq	%r10d, %rsi
	addq	%r11, %rsi
	movl	(%r12,%rsi,4), %ecx
	movl	0(%rbp,%rsi,4), %r14d
	imull	%r13d, %ecx
	imull	%edi, %r14d
	subl	%r14d, %ecx
	movl	(%r15,%rsi,4), %r14d
	imull	%ebx, %r14d
	subl	%r14d, %ecx
	leaq	t4(%rip), %r14
	addl	(%r14,%rsi,4), %ecx
	addl	%ecx, 12(%rsp)
	leal	-1(%r10), %ecx
	andl	%ecx, %r10d
	jne	.L48
.L47:
	leal	-1(%rax), %ecx
	andl	%ecx, %eax
	jne	.L50
	leaq	t1(%rip), %r13
	movl	%edx, %r14d
	imull	%ebx, %r14d
	leaq	t2(%rip), %r12
	leaq	t3(%rip), %rbp
	leaq	t4(%rip), %rdi
	.p2align 4,,10
.L53:
	movl	8(%rsp), %esi
	testl	%esi, %esi
	je	.L51
	movslq	%r8d, %r11
	movl	%esi, %r10d
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L52:
	movslq	%r10d, %rsi
	addq	%r11, %rsi
	movl	0(%r13,%rsi,4), %ecx
	movl	(%r12,%rsi,4), %r15d
	imull	%r14d, %ecx
	imull	%edx, %r15d
	subl	%r15d, %ecx
	movl	0(%rbp,%rsi,4), %r15d
	imull	%ebx, %r15d
	subl	%r15d, %ecx
	addl	(%rdi,%rsi,4), %ecx
	addl	%ecx, %eax
	leal	-1(%r10), %ecx
	andl	%ecx, %r10d
	jne	.L52
.L51:
	leal	-1(%r8), %ecx
	andl	%ecx, %r8d
	jne	.L53
	movl	12(%rsp), %edi
	subl	%eax, %edi
	movl	%edi, %eax
.L46:
	movl	96(%rsp), %r11d
	subl	$1, %r11d
	je	.L45
	movl	96(%rsp), %r13d
	leal	1(%r9), %ebp
	movl	%r11d, %ecx
	xorl	%edi, %edi
	leaq	t2(%rip), %r15
	imull	%ebp, %r13d
	.p2align 4,,10
.L58:
	testl	%r9d, %r9d
	je	.L55
	movslq	%ecx, %rbx
	movl	%r9d, %r10d
	imulq	$1007, %rbx, %rbx
	.p2align 4,,10
.L56:
	leaq	t1(%rip), %r14
	movslq	%r10d, %rsi
	movl	%r13d, %r8d
	leaq	t3(%rip), %r12
	addq	%rbx, %rsi
	imull	(%r14,%rsi,4), %r8d
	movl	(%r15,%rsi,4), %r14d
	imull	%ebp, %r14d
	subl	%r14d, %r8d
	movl	96(%rsp), %r14d
	imull	(%r12,%rsi,4), %r14d
	subl	%r14d, %r8d
	leaq	t4(%rip), %r14
	addl	(%r14,%rsi,4), %r8d
	addl	%r8d, %edi
	leal	-1(%r10), %r8d
	andl	%r8d, %r10d
	jne	.L56
.L55:
	leal	-1(%rcx), %r8d
	andl	%r8d, %ecx
	jne	.L58
	movl	96(%rsp), %r13d
	leaq	t1(%rip), %r12
	subl	%edi, %eax
	movl	8(%rsp), %r14d
	leaq	t2(%rip), %rbp
	leaq	t3(%rip), %rdi
	leaq	t4(%rip), %rsi
	imull	%edx, %r13d
	.p2align 4,,10
.L61:
	testl	%r14d, %r14d
	je	.L59
	movslq	%r11d, %rbx
	movl	%r14d, %r10d
	imulq	$1007, %rbx, %rbx
	.p2align 4,,10
.L60:
	movslq	%r10d, %r9
	addq	%rbx, %r9
	movl	(%r12,%r9,4), %r8d
	movl	0(%rbp,%r9,4), %r15d
	imull	%r13d, %r8d
	imull	%edx, %r15d
	subl	%r15d, %r8d
	movl	96(%rsp), %r15d
	imull	(%rdi,%r9,4), %r15d
	subl	%r15d, %r8d
	addl	(%rsi,%r9,4), %r8d
	addl	%r8d, %ecx
	leal	-1(%r10), %r8d
	andl	%r8d, %r10d
	jne	.L60
.L59:
	leal	-1(%r11), %r8d
	andl	%r8d, %r11d
	jne	.L61
	addl	%ecx, %eax
.L45:
	addq	$24, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L62:
	xorl	%eax, %eax
	jmp	.L46
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8910:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rbx
	leaq	n(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	$0, 232(%rbx)
	movq	%rbx, %rcx
	movq	$0, 224(%rax)
	call	_ZNSirsERi
	leaq	m(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	leaq	q(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	n(%rip), %r10d
	testl	%r10d, %r10d
	jle	.L184
	movl	m(%rip), %r12d
	movq	%rbx, 64(%rsp)
	movl	$1, %edi
	movl	$-2, 48(%rsp)
	leaq	t1(%rip), %rbx
	movl	$1, 44(%rsp)
	leaq	t2(%rip), %r15
	movl	$0, 76(%rsp)
	leaq	t3(%rip), %rbp
	.p2align 4,,10
.L111:
	leal	1(%rdi), %esi
	testl	%r12d, %r12d
	movl	%esi, 40(%rsp)
	jle	.L86
	leal	(%rsi,%rsi), %r13d
	movl	%esi, %eax
	movl	$1, %esi
	negl	%eax
	leal	2(%rax,%rax), %r14d
	movl	48(%rsp), %eax
	movl	%eax, 72(%rsp)
	movl	44(%rsp), %eax
	movl	%eax, 52(%rsp)
	leaq	124(%rsp), %rax
	movq	%rax, 56(%rsp)
	jmp	.L87
	.p2align 4,,10
.L89:
	movl	m(%rip), %r12d
	cmpl	%r8d, %r12d
	jl	.L232
.L110:
	addl	40(%rsp), %r13d
	subl	%edi, %r14d
	movl	44(%rsp), %esi
	addl	%esi, 52(%rsp)
	movl	48(%rsp), %esi
	addl	%esi, 72(%rsp)
	movl	%r8d, %esi
.L87:
	movq	56(%rsp), %rdx
	movq	64(%rsp), %rcx
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	cmpb	$42, 124(%rsp)
	leal	1(%rsi), %r8d
	jne	.L89
	addl	$1, 76(%rsp)
	movl	n(%rip), %r10d
	cmpl	44(%rsp), %r10d
	movl	m(%rip), %r12d
	jl	.L233
	cmpl	%r12d, %esi
	jg	.L93
	movl	%r8d, 80(%rsp)
	movl	52(%rsp), %r8d
	movl	%edi, %r9d
	leaq	t4(%rip), %rdx
	.p2align 4,,10
.L95:
	movslq	%r9d, %r11
	movl	%esi, %ecx
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L94:
	movslq	%ecx, %rax
	addq	%r11, %rax
	addl	$1, (%rbx,%rax,4)
	addl	%edi, (%r15,%rax,4)
	addl	%esi, 0(%rbp,%rax,4)
	addl	%r8d, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r12d, %ecx
	jle	.L94
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r10d, %r9d
	jle	.L95
	movl	80(%rsp), %r8d
.L93:
	cmpl	%r8d, %r12d
	jl	.L180
	leaq	t4(%rip), %rdx
	movl	%edi, %r9d
	.p2align 4,,10
.L99:
	movslq	%r9d, %r11
	movl	%r8d, %ecx
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L97:
	movslq	%ecx, %rax
	addq	%r11, %rax
	subl	$1, (%rbx,%rax,4)
	subl	%edi, (%r15,%rax,4)
	subl	%r8d, 0(%rbp,%rax,4)
	addl	%r14d, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r12d, %ecx
	jle	.L97
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r10d, %r9d
	jle	.L99
	cmpl	40(%rsp), %r10d
	jl	.L110
.L92:
	cmpl	%r12d, %esi
	jg	.L101
	movl	%edi, 80(%rsp)
	movl	40(%rsp), %r9d
	leaq	t4(%rip), %rdx
	movl	%r8d, 88(%rsp)
	movl	72(%rsp), %edi
	movl	48(%rsp), %r8d
	.p2align 4,,10
.L103:
	movslq	%r9d, %r11
	movl	%esi, %ecx
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L102:
	movslq	%ecx, %rax
	addq	%r11, %rax
	subl	$1, (%rbx,%rax,4)
	addl	%r8d, (%r15,%rax,4)
	subl	%esi, 0(%rbp,%rax,4)
	addl	%edi, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r12d, %ecx
	jle	.L102
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r10d, %r9d
	jle	.L103
	movl	80(%rsp), %edi
	movl	88(%rsp), %r8d
.L101:
	cmpl	%r8d, %r12d
	jl	.L86
	movl	40(%rsp), %esi
	leaq	t4(%rip), %rdx
	movl	%esi, %r9d
	.p2align 4,,10
.L108:
	movslq	%r9d, %r11
	movl	%r8d, %ecx
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L106:
	movslq	%ecx, %rax
	addq	%r11, %rax
	addl	$1, (%rbx,%rax,4)
	addl	%esi, (%r15,%rax,4)
	addl	%r8d, 0(%rbp,%rax,4)
	addl	%r13d, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r12d, %ecx
	jle	.L106
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r10d, %r9d
	jle	.L108
	jmp	.L110
	.p2align 4,,10
.L232:
	movl	n(%rip), %r10d
.L86:
	movl	40(%rsp), %edi
	addl	$1, 44(%rsp)
	subl	$1, 48(%rsp)
	cmpl	%edi, %r10d
	jge	.L111
.L85:
	movl	q(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, q(%rip)
	je	.L228
	leaq	124(%rsp), %rax
	movq	%rax, 96(%rsp)
	leaq	120(%rsp), %rax
	movq	%rax, 88(%rsp)
	leaq	119(%rsp), %rax
	movq	%rax, 80(%rsp)
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	t1(%rip), %r12
	leaq	t2(%rip), %r13
	leaq	t3(%rip), %rbx
	movq	%rax, 104(%rsp)
	.p2align 4,,10
.L88:
	movq	88(%rsp), %rdx
	movq	104(%rsp), %rcx
	call	_ZNSirsERi
	movq	96(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	120(%rsp), %r8d
	movl	124(%rsp), %eax
	testl	%r8d, %r8d
	movl	%r8d, 40(%rsp)
	leal	1(%rax), %r10d
	movl	%r10d, 72(%rsp)
	je	.L112
	leal	1(%r8), %esi
	movl	%r10d, %edi
	movl	%r8d, 44(%rsp)
	xorl	%ebp, %ebp
	imull	%esi, %edi
	movl	%esi, 52(%rsp)
	leaq	t4(%rip), %r11
	.p2align 4,,10
.L116:
	testl	%eax, %eax
	je	.L113
	movslq	%r8d, %r9
	movl	%eax, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L114:
	movslq	%ecx, %r14
	addq	%r9, %r14
	movl	(%r12,%r14,4), %edx
	movl	0(%r13,%r14,4), %r15d
	imull	%edi, %edx
	imull	%r10d, %r15d
	subl	%r15d, %edx
	movl	(%rbx,%r14,4), %r15d
	imull	%esi, %r15d
	subl	%r15d, %edx
	addl	(%r11,%r14,4), %edx
	addl	%edx, %ebp
	leal	-1(%rcx), %edx
	andl	%edx, %ecx
	jne	.L114
.L113:
	leal	-1(%r8), %edx
	andl	%edx, %r8d
	jne	.L116
	movl	40(%rsp), %r10d
	leal	-1(%rax), %edx
	movl	%ebp, 48(%rsp)
	subl	%esi, %edi
	movl	%edx, 56(%rsp)
	leaq	t4(%rip), %r14
	movl	%edx, %ebp
	.p2align 4,,10
.L119:
	testl	%ebp, %ebp
	je	.L117
	movslq	%r10d, %r11
	movl	%ebp, %r9d
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L118:
	movslq	%r9d, %rcx
	addq	%r11, %rcx
	movl	(%r12,%rcx,4), %edx
	movl	0(%r13,%rcx,4), %r15d
	imull	%edi, %edx
	imull	%eax, %r15d
	subl	%r15d, %edx
	movl	(%rbx,%rcx,4), %r15d
	imull	%esi, %r15d
	subl	%r15d, %edx
	addl	(%r14,%rcx,4), %edx
	addl	%edx, %r8d
	leal	-1(%r9), %edx
	andl	%edx, %r9d
	jne	.L118
.L117:
	leal	-1(%r10), %edx
	andl	%edx, %r10d
	jne	.L119
	movl	48(%rsp), %ebp
	movl	40(%rsp), %r10d
	subl	%r8d, %ebp
	subl	$1, %r10d
	movl	%ebp, 48(%rsp)
	je	.L120
.L179:
	movl	72(%rsp), %r14d
	movl	%r10d, %r8d
	xorl	%edi, %edi
	movl	%r10d, 64(%rsp)
	movl	44(%rsp), %esi
	leaq	t4(%rip), %rbp
	movl	40(%rsp), %r11d
	imull	%r14d, %esi
	.p2align 4,,10
.L124:
	testl	%eax, %eax
	je	.L121
	movslq	%r8d, %r10
	movl	%eax, %r9d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L122:
	movslq	%r9d, %rcx
	addq	%r10, %rcx
	movl	(%r12,%rcx,4), %edx
	movl	0(%r13,%rcx,4), %r15d
	imull	%esi, %edx
	imull	%r14d, %r15d
	subl	%r15d, %edx
	movl	(%rbx,%rcx,4), %r15d
	imull	%r11d, %r15d
	subl	%r15d, %edx
	addl	0(%rbp,%rcx,4), %edx
	addl	%edx, %edi
	leal	-1(%r9), %edx
	andl	%edx, %r9d
	jne	.L122
.L121:
	leal	-1(%r8), %edx
	andl	%edx, %r8d
	jne	.L124
	movl	48(%rsp), %r14d
	movl	64(%rsp), %r10d
	subl	44(%rsp), %esi
	movl	56(%rsp), %ebp
	subl	%edi, %r14d
	movl	%r14d, 48(%rsp)
	movl	40(%rsp), %r14d
	leaq	t4(%rip), %rdi
	.p2align 4,,10
.L127:
	testl	%ebp, %ebp
	je	.L125
	movslq	%r10d, %r11
	movl	%ebp, %r9d
	imulq	$1007, %r11, %r11
	.p2align 4,,10
.L126:
	movslq	%r9d, %rcx
	addq	%r11, %rcx
	movl	(%r12,%rcx,4), %edx
	movl	0(%r13,%rcx,4), %r15d
	imull	%esi, %edx
	imull	%eax, %r15d
	subl	%r15d, %edx
	movl	(%rbx,%rcx,4), %r15d
	imull	%r14d, %r15d
	subl	%r15d, %edx
	addl	(%rdi,%rcx,4), %edx
	addl	%edx, %r8d
	leal	-1(%r9), %edx
	andl	%edx, %r9d
	jne	.L126
.L125:
	leal	-1(%r10), %edx
	andl	%edx, %r10d
	jne	.L127
	movl	48(%rsp), %r14d
	leal	(%r8,%r14), %edi
	movl	%edi, 48(%rsp)
.L120:
	movl	48(%rsp), %edx
	movl	n(%rip), %r15d
	testl	%edx, %edx
	je	.L128
	cmpl	%r15d, 40(%rsp)
	jg	.L137
	movl	m(%rip), %r11d
	movl	44(%rsp), %esi
	imull	%eax, %esi
	cmpl	%r11d, %eax
	jg	.L132
	movl	40(%rsp), %edi
	leaq	t4(%rip), %rdx
	movl	%edi, %r9d
	.p2align 4,,10
.L134:
	movslq	%r9d, %r10
	movl	%eax, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L133:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	subl	$1, (%r12,%rcx,4)
	subl	%edi, 0(%r13,%rcx,4)
	subl	%eax, (%rbx,%rcx,4)
	subl	%esi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L133
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L134
.L132:
	movl	72(%rsp), %esi
	movl	44(%rsp), %edi
	imull	%esi, %edi
	cmpl	%esi, %r11d
	jl	.L137
	movl	40(%rsp), %ebp
	leaq	t4(%rip), %rdx
	movl	%ebp, %r9d
	.p2align 4,,10
.L138:
	movslq	%r9d, %r10
	movl	%esi, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L136:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	addl	$1, (%r12,%rcx,4)
	addl	%ebp, 0(%r13,%rcx,4)
	addl	%esi, (%rbx,%rcx,4)
	addl	%edi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L136
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L138
.L137:
	cmpl	%r15d, 52(%rsp)
	jg	.L130
	movl	52(%rsp), %edi
	movl	m(%rip), %r11d
	movl	%edi, %esi
	imull	%eax, %esi
	cmpl	%r11d, %eax
	jg	.L141
	leaq	t4(%rip), %rdx
	movl	%edi, %r9d
	.p2align 4,,10
.L143:
	movslq	%r9d, %r10
	movl	%eax, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L142:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	addl	$1, (%r12,%rcx,4)
	addl	%edi, 0(%r13,%rcx,4)
	addl	%eax, (%rbx,%rcx,4)
	addl	%esi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L142
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L143
.L141:
	movl	72(%rsp), %ebp
	movl	40(%rsp), %r8d
	movl	%ebp, %r9d
	notl	%r8d
	imull	%r8d, %r9d
	cmpl	%ebp, %r11d
	jl	.L130
	movl	52(%rsp), %r10d
	leaq	t4(%rip), %rdx
	notl	%eax
	movl	%eax, %esi
	.p2align 4,,10
.L146:
	movslq	%r10d, %rdi
	movl	%ebp, %ecx
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L145:
	movslq	%ecx, %rax
	addq	%rdi, %rax
	subl	$1, (%r12,%rax,4)
	addl	%r8d, 0(%r13,%rax,4)
	addl	%esi, (%rbx,%rax,4)
	addl	%r9d, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r11d, %ecx
	jle	.L145
	movl	%r10d, %eax
	negl	%eax
	andl	%r10d, %eax
	addl	%eax, %r10d
	cmpl	%r15d, %r10d
	jle	.L146
.L130:
	subl	$1, 76(%rsp)
.L140:
	movl	76(%rsp), %eax
	cltd
	idivl	%r15d
	testl	%r15d, %r15d
	movl	%eax, 40(%rsp)
	movl	%edx, %eax
	movl	%edx, 48(%rsp)
	je	.L185
	movl	40(%rsp), %r14d
	leal	1(%r15), %esi
	movl	%r15d, %r9d
	xorl	%r11d, %r11d
	leaq	t4(%rip), %rdi
	movl	%r15d, 44(%rsp)
	movl	%edx, 52(%rsp)
	leal	1(%r14), %r10d
	movl	%r10d, %ebp
	imull	%esi, %ebp
	.p2align 4,,10
.L169:
	testl	%r14d, %r14d
	je	.L167
	movslq	%r9d, %r8
	movl	%r14d, %ecx
	imulq	$1007, %r8, %r8
	.p2align 4,,10
.L168:
	movslq	%ecx, %rdx
	addq	%r8, %rdx
	movl	(%r12,%rdx,4), %eax
	movl	0(%r13,%rdx,4), %r15d
	imull	%ebp, %eax
	imull	%r10d, %r15d
	subl	%r15d, %eax
	movl	(%rbx,%rdx,4), %r15d
	imull	%esi, %r15d
	subl	%r15d, %eax
	addl	(%rdi,%rdx,4), %eax
	addl	%eax, %r11d
	leal	-1(%rcx), %eax
	andl	%eax, %ecx
	jne	.L168
.L167:
	leal	-1(%r9), %eax
	andl	%eax, %r9d
	jne	.L169
	movl	52(%rsp), %eax
	movl	44(%rsp), %r15d
	movl	%r11d, 44(%rsp)
	.p2align 4,,10
.L170:
	leal	-1(%r15), %edx
	andl	%edx, %r15d
	jne	.L170
.L166:
	movl	48(%rsp), %edx
	testl	%edx, %edx
	je	.L171
	movl	40(%rsp), %esi
	leal	1(%rdx), %edi
	xorl	%r11d, %r11d
	movl	%eax, 52(%rsp)
	leaq	t4(%rip), %r14
	leal	2(%rsi), %ebp
	movl	%ebp, %esi
	imull	%edi, %esi
	.p2align 4,,10
.L174:
	testl	%r10d, %r10d
	je	.L172
	movslq	%edx, %r9
	movl	%r10d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L173:
	movslq	%r8d, %rcx
	addq	%r9, %rcx
	movl	(%r12,%rcx,4), %eax
	movl	0(%r13,%rcx,4), %r15d
	imull	%esi, %eax
	imull	%ebp, %r15d
	subl	%r15d, %eax
	movl	(%rbx,%rcx,4), %r15d
	imull	%edi, %r15d
	subl	%r15d, %eax
	addl	(%r14,%rcx,4), %eax
	addl	%eax, %r11d
	leal	-1(%r8), %eax
	andl	%eax, %r8d
	jne	.L173
.L172:
	leal	-1(%rdx), %eax
	andl	%eax, %edx
	jne	.L174
	movl	%r11d, 48(%rsp)
	movl	52(%rsp), %eax
	subl	%edi, %esi
	movl	40(%rsp), %r11d
	leaq	t4(%rip), %rbp
	.p2align 4,,10
.L177:
	testl	%r11d, %r11d
	je	.L175
	movslq	%eax, %r9
	movl	%r11d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L176:
	movslq	%r8d, %r14
	addq	%r9, %r14
	movl	(%r12,%r14,4), %ecx
	movl	0(%r13,%r14,4), %r15d
	imull	%esi, %ecx
	imull	%r10d, %r15d
	subl	%r15d, %ecx
	movl	(%rbx,%r14,4), %r15d
	imull	%edi, %r15d
	subl	%r15d, %ecx
	addl	0(%rbp,%r14,4), %ecx
	addl	%ecx, %edx
	leal	-1(%r8), %ecx
	andl	%ecx, %r8d
	jne	.L176
.L175:
	leal	-1(%rax), %ecx
	andl	%ecx, %eax
	jne	.L177
	movl	48(%rsp), %eax
	subl	%edx, %eax
	addl	%eax, 44(%rsp)
.L171:
	movl	76(%rsp), %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	subl	44(%rsp), %edx
	call	_ZNSolsEi
	movq	80(%rsp), %rdx
	movl	$1, %r8d
	movb	$10, 119(%rsp)
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	q(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, q(%rip)
	jne	.L88
.L228:
	xorl	%eax, %eax
	addq	$136, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L128:
	cmpl	%r15d, 40(%rsp)
	jg	.L156
	movl	m(%rip), %r11d
	movl	44(%rsp), %esi
	imull	%eax, %esi
	cmpl	%r11d, %eax
	jg	.L151
	movl	40(%rsp), %edi
	leaq	t4(%rip), %rdx
	movl	%edi, %r9d
	.p2align 4,,10
.L153:
	movslq	%r9d, %r10
	movl	%eax, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L152:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	addl	$1, (%r12,%rcx,4)
	addl	%edi, 0(%r13,%rcx,4)
	addl	%eax, (%rbx,%rcx,4)
	addl	%esi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L152
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L153
.L151:
	movl	72(%rsp), %r14d
	movl	44(%rsp), %edi
	imull	%r14d, %edi
	cmpl	%r14d, %r11d
	jl	.L156
	movl	40(%rsp), %ebp
	leaq	t4(%rip), %rdx
	movl	%eax, %esi
	notl	%esi
	movl	%ebp, %r9d
	.p2align 4,,10
.L157:
	movslq	%r9d, %r10
	movl	%r14d, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L155:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	subl	$1, (%r12,%rcx,4)
	subl	%ebp, 0(%r13,%rcx,4)
	addl	%esi, (%rbx,%rcx,4)
	subl	%edi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L155
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L157
.L156:
	cmpl	%r15d, 52(%rsp)
	jg	.L149
	movl	40(%rsp), %esi
	movl	m(%rip), %r11d
	notl	%esi
	movl	%esi, %edi
	imull	%eax, %edi
	cmpl	%r11d, %eax
	jg	.L159
	movl	52(%rsp), %r9d
	leaq	t4(%rip), %rdx
	.p2align 4,,10
.L161:
	movslq	%r9d, %r10
	movl	%eax, %r8d
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L160:
	movslq	%r8d, %rcx
	addq	%r10, %rcx
	subl	$1, (%r12,%rcx,4)
	addl	%esi, 0(%r13,%rcx,4)
	subl	%eax, (%rbx,%rcx,4)
	addl	%edi, (%rdx,%rcx,4)
	movl	%r8d, %ecx
	negl	%ecx
	andl	%r8d, %ecx
	addl	%ecx, %r8d
	cmpl	%r11d, %r8d
	jle	.L160
	movl	%r9d, %ecx
	negl	%ecx
	andl	%r9d, %ecx
	addl	%ecx, %r9d
	cmpl	%r15d, %r9d
	jle	.L161
.L159:
	movl	52(%rsp), %eax
	movl	72(%rsp), %esi
	movl	%eax, %r10d
	imull	%esi, %r10d
	cmpl	%esi, %r11d
	jl	.L149
	leaq	t4(%rip), %rdx
	movl	%eax, %r8d
	movl	%eax, %edi
	.p2align 4,,10
.L164:
	movslq	%r8d, %r9
	movl	%esi, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L163:
	movslq	%ecx, %rax
	addq	%r9, %rax
	addl	$1, (%r12,%rax,4)
	addl	%edi, 0(%r13,%rax,4)
	addl	%esi, (%rbx,%rax,4)
	addl	%r10d, (%rdx,%rax,4)
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	%r11d, %ecx
	jle	.L163
	movl	%r8d, %eax
	negl	%eax
	andl	%r8d, %eax
	addl	%eax, %r8d
	cmpl	%r15d, %r8d
	jle	.L164
.L149:
	addl	$1, 76(%rsp)
	jmp	.L140
	.p2align 4,,10
.L233:
	cmpl	40(%rsp), %r10d
	jge	.L92
	cmpl	%r8d, %r12d
	jge	.L110
	jmp	.L85
	.p2align 4,,10
.L180:
	cmpl	40(%rsp), %r10d
	jge	.L92
	jmp	.L85
	.p2align 4,,10
.L185:
	movl	40(%rsp), %edi
	movl	$0, 44(%rsp)
	leal	1(%rdi), %r10d
	jmp	.L166
	.p2align 4,,10
.L112:
	leal	-1(%rax), %edi
	movl	$0, 48(%rsp)
	movl	$-1, %r10d
	movl	%edi, 56(%rsp)
	movl	$0, 44(%rsp)
	movl	$1, 52(%rsp)
	jmp	.L179
.L184:
	movl	$0, 76(%rsp)
	jmp	.L85
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB10214:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_a
	.globl	t4
	.bss
	.align 32
t4:
	.space 4056196
	.globl	t3
	.align 32
t3:
	.space 4056196
	.globl	t2
	.align 32
t2:
	.space 4056196
	.globl	t1
	.align 32
t1:
	.space 4056196
	.globl	st
	.align 32
st:
	.space 1014049
	.globl	q
	.align 4
q:
	.space 4
	.globl	m
	.align 4
m:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	a
	.align 32
a:
	.space 4028
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
)");
