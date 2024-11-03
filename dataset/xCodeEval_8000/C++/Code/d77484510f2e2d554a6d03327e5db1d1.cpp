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
	subq	$24, %rsp
	.seh_stackalloc	24
	.seh_endprologue
	movl	n(%rip), %eax
	cmpl	%eax, %ecx
	movl	%eax, 12(%rsp)
	jg	.L12
	movl	m(%rip), %r13d
	movl	%ecx, %r12d
	movl	%r8d, %r14d
	movl	%edx, %r15d
	imull	%r8d, %r12d
	imull	%edx, %r14d
	imull	%r12d, %r15d
	cmpl	%r13d, %edx
	jg	.L12
	leaq	t1(%rip), %rdi
	leaq	t2(%rip), %rsi
	leaq	t3(%rip), %rbx
	leaq	t4(%rip), %r11
	.p2align 4,,10
.L10:
	movslq	%ecx, %rbp
	movl	%edx, %r9d
	imulq	$1007, %rbp, %rbp
	.p2align 4,,10
.L8:
	movl	%r9d, %r10d
	movslq	%r9d, %rax
	negl	%r10d
	addq	%rbp, %rax
	addl	%r8d, (%rdi,%rax,4)
	andl	%r9d, %r10d
	addl	%r12d, (%rsi,%rax,4)
	addl	%r10d, %r9d
	addl	%r14d, (%rbx,%rax,4)
	addl	%r15d, (%r11,%rax,4)
	cmpl	%r13d, %r9d
	jle	.L8
	movl	%ecx, %eax
	negl	%eax
	andl	%ecx, %eax
	addl	%eax, %ecx
	cmpl	12(%rsp), %ecx
	jle	.L10
.L12:
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
	movl	128(%rsp), %edi
	movl	%r8d, 112(%rsp)
	leal	1(%r9), %r15d
	negl	%edi
	cmpl	%eax, %ecx
	movl	%eax, 4(%rsp)
	movl	%edi, 8(%rsp)
	jg	.L21
	movl	128(%rsp), %r12d
	movl	128(%rsp), %eax
	movl	m(%rip), %r14d
	imull	%ecx, %r12d
	imull	%edx, %eax
	movl	%r12d, %r13d
	imull	%edx, %r13d
	cmpl	%r14d, %edx
	movl	%eax, 12(%rsp)
	jg	.L17
	leaq	t1(%rip), %r11
	movl	%ecx, %esi
	leaq	t2(%rip), %r10
	leaq	t3(%rip), %r9
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L19:
	movslq	%esi, %rdi
	movl	%edx, %ebx
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L18:
	movl	%ebx, %ebp
	movslq	%ebx, %r8
	negl	%ebp
	addq	%rdi, %r8
	addl	%r12d, (%r10,%r8,4)
	andl	%ebx, %ebp
	addl	%r13d, (%rax,%r8,4)
	addl	%ebp, %ebx
	movl	128(%rsp), %ebp
	addl	%ebp, (%r11,%r8,4)
	movl	12(%rsp), %ebp
	addl	%ebp, (%r9,%r8,4)
	cmpl	%r14d, %ebx
	jle	.L18
	movl	%esi, %r8d
	negl	%r8d
	andl	%esi, %r8d
	addl	%r8d, %esi
	cmpl	4(%rsp), %esi
	jle	.L19
.L17:
	movl	8(%rsp), %eax
	movl	%eax, %ebp
	imull	%r15d, %eax
	imull	%ecx, %ebp
	movl	%eax, %r12d
	movl	%ebp, %r13d
	imull	%r15d, %r13d
	cmpl	%r15d, %r14d
	jl	.L21
	leaq	t1(%rip), %r11
	leaq	t2(%rip), %r10
	leaq	t3(%rip), %r9
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L23:
	movslq	%ecx, %rsi
	movl	%r15d, %ebx
	imulq	$1007, %rsi, %rsi
	.p2align 4,,10
.L20:
	movl	%ebx, %edi
	movslq	%ebx, %r8
	negl	%edi
	addq	%rsi, %r8
	addl	%ebp, (%r10,%r8,4)
	andl	%ebx, %edi
	addl	%r12d, (%r9,%r8,4)
	addl	%edi, %ebx
	addl	%r13d, (%rax,%r8,4)
	movl	128(%rsp), %edi
	subl	%edi, (%r11,%r8,4)
	cmpl	%r14d, %ebx
	jle	.L20
	movl	%ecx, %r8d
	negl	%r8d
	andl	%ecx, %r8d
	addl	%r8d, %ecx
	cmpl	4(%rsp), %ecx
	jle	.L23
.L21:
	movl	112(%rsp), %eax
	leal	1(%rax), %r8d
	cmpl	4(%rsp), %r8d
	jg	.L36
	movl	8(%rsp), %eax
	movl	m(%rip), %ebp
	movl	%eax, %r13d
	imull	%edx, %eax
	imull	%r8d, %r13d
	movl	%eax, %r14d
	movl	%edx, %eax
	imull	%r13d, %eax
	cmpl	%ebp, %edx
	movl	%eax, 8(%rsp)
	jg	.L24
	leaq	t1(%rip), %r11
	movl	%r8d, %esi
	leaq	t2(%rip), %r10
	leaq	t3(%rip), %r9
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L26:
	movslq	%esi, %rdi
	movl	%edx, %ebx
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L25:
	movl	%ebx, %r12d
	movslq	%ebx, %rcx
	negl	%r12d
	addq	%rdi, %rcx
	addl	%r13d, (%r10,%rcx,4)
	andl	%ebx, %r12d
	addl	%r14d, (%r9,%rcx,4)
	addl	%r12d, %ebx
	movl	128(%rsp), %r12d
	subl	%r12d, (%r11,%rcx,4)
	movl	8(%rsp), %r12d
	addl	%r12d, (%rax,%rcx,4)
	cmpl	%ebp, %ebx
	jle	.L25
	movl	%esi, %ecx
	negl	%ecx
	andl	%esi, %ecx
	addl	%ecx, %esi
	cmpl	4(%rsp), %esi
	jle	.L26
.L24:
	movl	128(%rsp), %edi
	movl	128(%rsp), %r12d
	imull	%r8d, %edi
	imull	%r15d, %r12d
	movl	%edi, %r13d
	imull	%r15d, %r13d
	cmpl	%r15d, %ebp
	jl	.L36
	movl	128(%rsp), %r14d
	leaq	t1(%rip), %r11
	leaq	t2(%rip), %r10
	leaq	t3(%rip), %r9
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L29:
	movslq	%r8d, %rbx
	movl	%r15d, %ecx
	imulq	$1007, %rbx, %rbx
	.p2align 4,,10
.L28:
	movl	%ecx, %esi
	movslq	%ecx, %rdx
	negl	%esi
	addq	%rbx, %rdx
	addl	%r14d, (%r11,%rdx,4)
	andl	%ecx, %esi
	addl	%edi, (%r10,%rdx,4)
	addl	%esi, %ecx
	addl	%r12d, (%r9,%rdx,4)
	addl	%r13d, (%rax,%rdx,4)
	cmpl	%ebp, %ecx
	jle	.L28
	movl	%r8d, %edx
	negl	%edx
	andl	%r8d, %edx
	addl	%edx, %r8d
	cmpl	4(%rsp), %r8d
	jle	.L29
.L36:
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
	movl	%ecx, 72(%rsp)
	movl	%edx, 80(%rsp)
	je	.L42
	leal	1(%rcx), %esi
	movl	%edx, %edi
	xorl	%eax, %eax
	leaq	t1(%rip), %r14
	addl	$1, %edi
	leaq	t2(%rip), %r13
	movl	%edi, %r15d
	imull	%esi, %r15d
	leaq	t3(%rip), %r12
	leaq	t4(%rip), %rbp
	.p2align 4,,10
.L41:
	movl	80(%rsp), %edx
	testl	%edx, %edx
	je	.L39
	movslq	72(%rsp), %rbx
	movl	80(%rsp), %r8d
	imulq	$1007, %rbx, %rbx
	.p2align 4,,10
.L40:
	leal	-1(%r8), %ecx
	movslq	%r8d, %r9
	addq	%rbx, %r9
	movl	(%r14,%r9,4), %edx
	movl	0(%r13,%r9,4), %r11d
	movl	(%r12,%r9,4), %r10d
	imull	%r15d, %edx
	imull	%edi, %r11d
	imull	%esi, %r10d
	subl	%r11d, %edx
	subl	%r10d, %edx
	addl	0(%rbp,%r9,4), %edx
	addl	%edx, %eax
	andl	%ecx, %r8d
	jne	.L40
.L39:
	movl	72(%rsp), %ebx
	leal	-1(%rbx), %edx
	andl	%edx, 72(%rsp)
	jne	.L41
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L42:
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
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	%edx, %eax
	movl	%edx, 120(%rsp)
	subl	$1, %eax
	testl	%r8d, %r8d
	movl	%ecx, 112(%rsp)
	movl	%eax, 24(%rsp)
	je	.L66
	leal	1(%r8), %ebx
	movl	$0, 8(%rsp)
	movl	%r8d, %eax
	leal	1(%r9), %esi
	movl	%ebx, %r12d
	imull	%esi, %r12d
	leaq	t1(%rip), %r13
	movl	%esi, %r11d
	leaq	t2(%rip), %r14
	leaq	t3(%rip), %r15
	leaq	t4(%rip), %rdi
	.p2align 4,,10
.L54:
	testl	%r9d, %r9d
	je	.L51
	movslq	%eax, %rdx
	movl	%r9d, %r10d
	imulq	$1007, %rdx, %rsi
	movq	%rsi, 16(%rsp)
	.p2align 4,,10
.L52:
	leal	-1(%r10), %esi
	movslq	%r10d, %rcx
	addq	16(%rsp), %rcx
	movl	%esi, 28(%rsp)
	movl	0(%r13,%rcx,4), %edx
	movl	(%r14,%rcx,4), %ebp
	movl	(%r15,%rcx,4), %esi
	imull	%r12d, %edx
	imull	%r11d, %ebp
	imull	%ebx, %esi
	subl	%ebp, %edx
	subl	%esi, %edx
	addl	(%rdi,%rcx,4), %edx
	addl	%edx, 8(%rsp)
	andl	28(%rsp), %r10d
	jne	.L52
.L51:
	leal	-1(%rax), %edx
	andl	%edx, %eax
	jne	.L54
	movl	120(%rsp), %r15d
	leaq	t1(%rip), %r14
	leaq	t2(%rip), %r13
	leaq	t3(%rip), %r12
	leaq	t4(%rip), %rbp
	imull	%ebx, %r15d
	.p2align 4,,10
.L57:
	movl	24(%rsp), %r10d
	testl	%r10d, %r10d
	je	.L55
	movslq	%r8d, %rdx
	imulq	$1007, %rdx, %rdi
	movq	%rdi, 16(%rsp)
	.p2align 4,,10
.L56:
	movl	120(%rsp), %edi
	leal	-1(%r10), %ecx
	movslq	%r10d, %r11
	addq	16(%rsp), %r11
	movl	(%r14,%r11,4), %edx
	movl	(%r12,%r11,4), %esi
	imull	0(%r13,%r11,4), %edi
	imull	%r15d, %edx
	imull	%ebx, %esi
	subl	%edi, %edx
	subl	%esi, %edx
	addl	0(%rbp,%r11,4), %edx
	addl	%edx, %eax
	andl	%ecx, %r10d
	jne	.L56
.L55:
	leal	-1(%r8), %edx
	andl	%edx, %r8d
	jne	.L57
	movl	8(%rsp), %edi
	subl	%eax, %edi
	movl	%edi, %eax
.L50:
	movl	112(%rsp), %r10d
	subl	$1, %r10d
	je	.L88
	movl	112(%rsp), %r14d
	leal	1(%r9), %ebp
	xorl	%esi, %esi
	movl	%r10d, %edx
	leaq	t1(%rip), %r15
	leaq	t2(%rip), %r13
	leaq	t3(%rip), %r12
	imull	%ebp, %r14d
	movl	%r14d, %ebx
	.p2align 4,,10
.L62:
	testl	%r9d, %r9d
	je	.L59
	movslq	%edx, %rcx
	movl	%r9d, %r11d
	movl	%edx, %r8d
	imulq	$1007, %rcx, %rdi
	movq	%rdi, 8(%rsp)
	.p2align 4,,10
.L60:
	leal	-1(%r11), %edi
	movslq	%r11d, %rcx
	addq	8(%rsp), %rcx
	movl	%edi, 16(%rsp)
	movl	112(%rsp), %edi
	movl	(%r15,%rcx,4), %edx
	movl	0(%r13,%rcx,4), %r14d
	imull	(%r12,%rcx,4), %edi
	imull	%ebx, %edx
	imull	%ebp, %r14d
	subl	%r14d, %edx
	leaq	t4(%rip), %r14
	subl	%edi, %edx
	addl	(%r14,%rcx,4), %edx
	addl	%edx, %esi
	andl	16(%rsp), %r11d
	jne	.L60
	movl	%r8d, %edx
.L59:
	leal	-1(%rdx), %ecx
	andl	%ecx, %edx
	jne	.L62
	movl	120(%rsp), %r15d
	leaq	t1(%rip), %r14
	subl	%esi, %eax
	imull	112(%rsp), %r15d
	leaq	t2(%rip), %r13
	leaq	t3(%rip), %r12
	leaq	t4(%rip), %rbp
	.p2align 4,,10
.L65:
	movl	24(%rsp), %r11d
	testl	%r11d, %r11d
	je	.L63
	movslq	%r10d, %r9
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L64:
	movl	120(%rsp), %edi
	leal	-1(%r11), %r8d
	movslq	%r11d, %rbx
	addq	%r9, %rbx
	movl	112(%rsp), %esi
	movl	(%r14,%rbx,4), %ecx
	imull	0(%r13,%rbx,4), %edi
	imull	(%r12,%rbx,4), %esi
	imull	%r15d, %ecx
	subl	%edi, %ecx
	subl	%esi, %ecx
	addl	0(%rbp,%rbx,4), %ecx
	addl	%ecx, %edx
	andl	%r8d, %r11d
	jne	.L64
.L63:
	leal	-1(%r10), %ecx
	andl	%ecx, %r10d
	jne	.L65
	addl	%edx, %eax
.L88:
	addq	$40, %rsp
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
.L66:
	xorl	%eax, %eax
	jmp	.L50
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
	movl	n(%rip), %r11d
	testl	%r11d, %r11d
	jle	.L189
	movl	m(%rip), %esi
	movl	$-2, 52(%rsp)
	movl	$1, %r13d
	movl	$1, 48(%rsp)
	leaq	t1(%rip), %r12
	movl	$0, 84(%rsp)
	leaq	t2(%rip), %r14
	movq	%rbx, 72(%rsp)
	leaq	t3(%rip), %rdi
	.p2align 4,,10
.L116:
	leal	1(%r13), %eax
	testl	%esi, %esi
	movl	%eax, 44(%rsp)
	jle	.L91
	movl	52(%rsp), %ebx
	movl	%eax, %esi
	negl	%eax
	leal	2(%rax,%rax), %ebp
	leal	(%rsi,%rsi), %eax
	movl	%eax, 56(%rsp)
	leaq	124(%rsp), %rax
	movl	%ebx, 80(%rsp)
	movl	48(%rsp), %ebx
	movq	%rax, 64(%rsp)
	movl	%ebx, 60(%rsp)
	movl	$1, %ebx
	jmp	.L92
	.p2align 4,,10
.L94:
	movl	m(%rip), %esi
	cmpl	%r8d, %esi
	jl	.L238
.L115:
	movl	44(%rsp), %esi
	subl	%r13d, %ebp
	addl	%esi, 56(%rsp)
	movl	48(%rsp), %ebx
	addl	%ebx, 60(%rsp)
	movl	52(%rsp), %ebx
	addl	%ebx, 80(%rsp)
	movl	%r8d, %ebx
.L92:
	movq	64(%rsp), %rdx
	movq	72(%rsp), %rcx
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	cmpb	$42, 124(%rsp)
	leal	1(%rbx), %r8d
	jne	.L94
	movl	n(%rip), %r11d
	addl	$1, 84(%rsp)
	cmpl	48(%rsp), %r11d
	movl	m(%rip), %esi
	jl	.L239
	cmpl	%esi, %ebx
	jg	.L98
	movl	%r8d, 88(%rsp)
	movl	60(%rsp), %r8d
	leaq	t4(%rip), %rdx
	movl	%r13d, %r9d
	.p2align 4,,10
.L100:
	movslq	%r9d, %r10
	movl	%ebx, %ecx
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L99:
	movl	%ecx, %r15d
	movslq	%ecx, %rax
	negl	%r15d
	addq	%r10, %rax
	addl	$1, (%r12,%rax,4)
	andl	%ecx, %r15d
	addl	%r13d, (%r14,%rax,4)
	addl	%r15d, %ecx
	addl	%ebx, (%rdi,%rax,4)
	addl	%r8d, (%rdx,%rax,4)
	cmpl	%esi, %ecx
	jle	.L99
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r11d, %r9d
	jle	.L100
	movl	88(%rsp), %r8d
.L98:
	cmpl	%r8d, %esi
	jl	.L185
	leaq	t4(%rip), %rdx
	movl	%r13d, %r9d
	.p2align 4,,10
.L104:
	movslq	%r9d, %r10
	movl	%r8d, %ecx
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L102:
	movl	%ecx, %r15d
	movslq	%ecx, %rax
	negl	%r15d
	addq	%r10, %rax
	subl	$1, (%r12,%rax,4)
	andl	%ecx, %r15d
	subl	%r13d, (%r14,%rax,4)
	addl	%r15d, %ecx
	subl	%r8d, (%rdi,%rax,4)
	addl	%ebp, (%rdx,%rax,4)
	cmpl	%esi, %ecx
	jle	.L102
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r11d, %r9d
	jle	.L104
	cmpl	44(%rsp), %r11d
	jl	.L115
.L97:
	cmpl	%esi, %ebx
	jg	.L106
	movl	%ebp, 88(%rsp)
	movl	44(%rsp), %r9d
	leaq	t4(%rip), %rdx
	movl	%r8d, 96(%rsp)
	movl	80(%rsp), %ebp
	movl	52(%rsp), %r8d
	.p2align 4,,10
.L108:
	movslq	%r9d, %r10
	movl	%ebx, %ecx
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L107:
	movl	%ecx, %r15d
	movslq	%ecx, %rax
	negl	%r15d
	addq	%r10, %rax
	subl	$1, (%r12,%rax,4)
	andl	%ecx, %r15d
	subl	%ebx, (%rdi,%rax,4)
	addl	%r15d, %ecx
	addl	%r8d, (%r14,%rax,4)
	addl	%ebp, (%rdx,%rax,4)
	cmpl	%esi, %ecx
	jle	.L107
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r11d, %r9d
	jle	.L108
	movl	88(%rsp), %ebp
	movl	96(%rsp), %r8d
.L106:
	cmpl	%r8d, %esi
	jl	.L91
	movl	44(%rsp), %r15d
	movl	%ebp, 88(%rsp)
	leaq	t4(%rip), %rdx
	movl	56(%rsp), %ebp
	movl	%r15d, %r9d
	.p2align 4,,10
.L113:
	movslq	%r9d, %r10
	movl	%r8d, %ecx
	imulq	$1007, %r10, %r10
	.p2align 4,,10
.L111:
	movl	%ecx, %ebx
	movslq	%ecx, %rax
	negl	%ebx
	addq	%r10, %rax
	addl	$1, (%r12,%rax,4)
	andl	%ecx, %ebx
	addl	%r15d, (%r14,%rax,4)
	addl	%ebx, %ecx
	addl	%r8d, (%rdi,%rax,4)
	addl	%ebp, (%rdx,%rax,4)
	cmpl	%esi, %ecx
	jle	.L111
	movl	%r9d, %eax
	negl	%eax
	andl	%r9d, %eax
	addl	%eax, %r9d
	cmpl	%r11d, %r9d
	jle	.L113
	movl	88(%rsp), %ebp
	jmp	.L115
	.p2align 4,,10
.L238:
	movl	n(%rip), %r11d
.L91:
	movl	44(%rsp), %r13d
	addl	$1, 48(%rsp)
	subl	$1, 52(%rsp)
	cmpl	%r13d, %r11d
	jge	.L116
.L90:
	movl	q(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, q(%rip)
	je	.L237
	leaq	124(%rsp), %rax
	movq	%rax, 96(%rsp)
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	t1(%rip), %r14
	leaq	t2(%rip), %r15
	leaq	t3(%rip), %rbx
	movq	%rax, 104(%rsp)
	leaq	120(%rsp), %rax
	movq	%rax, 88(%rsp)
	leaq	119(%rsp), %rax
	movq	%rax, 72(%rsp)
	.p2align 4,,10
.L93:
	movq	88(%rsp), %rdx
	movq	104(%rsp), %rcx
	call	_ZNSirsERi
	movq	96(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	124(%rsp), %r12d
	movl	120(%rsp), %r13d
	leal	1(%r12), %eax
	testl	%r13d, %r13d
	movl	%eax, 44(%rsp)
	je	.L117
	leal	1(%r13), %esi
	movl	%eax, %edi
	xorl	%r11d, %r11d
	movl	%r13d, 52(%rsp)
	imull	%esi, %edi
	movl	%r13d, %ecx
	movl	%esi, 60(%rsp)
	movl	%r13d, 48(%rsp)
	.p2align 4,,10
.L121:
	testl	%r12d, %r12d
	je	.L118
	movslq	%ecx, %r9
	movl	%r12d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L119:
	movl	44(%rsp), %r13d
	leal	-1(%r8), %edx
	movslq	%r8d, %r10
	addq	%r9, %r10
	movl	(%r14,%r10,4), %eax
	movl	(%rbx,%r10,4), %ebp
	imull	(%r15,%r10,4), %r13d
	imull	%edi, %eax
	imull	%esi, %ebp
	subl	%r13d, %eax
	subl	%ebp, %eax
	leaq	t4(%rip), %rbp
	addl	0(%rbp,%r10,4), %eax
	addl	%eax, %r11d
	andl	%edx, %r8d
	jne	.L119
.L118:
	leal	-1(%rcx), %eax
	andl	%eax, %ecx
	jne	.L121
	movl	48(%rsp), %r13d
	leal	-1(%r12), %eax
	subl	%esi, %edi
	movl	%r11d, 56(%rsp)
	movl	%eax, 80(%rsp)
	movl	%edi, 48(%rsp)
	movl	%r13d, %r10d
	movl	%r13d, 64(%rsp)
	movl	%eax, %r13d
	.p2align 4,,10
.L124:
	testl	%r13d, %r13d
	je	.L122
	movslq	%r10d, %r9
	movl	%r13d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L123:
	movl	48(%rsp), %eax
	leal	-1(%r8), %edx
	movslq	%r8d, %r11
	addq	%r9, %r11
	movl	(%r15,%r11,4), %ebp
	movl	(%rbx,%r11,4), %edi
	imull	(%r14,%r11,4), %eax
	imull	%r12d, %ebp
	imull	%esi, %edi
	subl	%ebp, %eax
	subl	%edi, %eax
	leaq	t4(%rip), %rdi
	addl	(%rdi,%r11,4), %eax
	addl	%eax, %ecx
	andl	%edx, %r8d
	jne	.L123
.L122:
	leal	-1(%r10), %eax
	andl	%eax, %r10d
	jne	.L124
	movl	64(%rsp), %r13d
	movl	56(%rsp), %eax
	movl	%r13d, %r10d
	subl	%ecx, %eax
	subl	$1, %r10d
	movl	%eax, 56(%rsp)
	je	.L125
.L184:
	movl	44(%rsp), %ebp
	xorl	%edi, %edi
	movl	%r10d, %ecx
	movl	%r10d, 64(%rsp)
	movl	52(%rsp), %eax
	imull	%ebp, %eax
	movl	%eax, 48(%rsp)
	.p2align 4,,10
.L129:
	testl	%r12d, %r12d
	je	.L126
	movslq	%ecx, %r9
	movl	%r12d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L127:
	movl	48(%rsp), %eax
	leal	-1(%r8), %edx
	movslq	%r8d, %r10
	addq	%r9, %r10
	movl	(%r15,%r10,4), %esi
	movl	(%rbx,%r10,4), %r11d
	imull	(%r14,%r10,4), %eax
	imull	%ebp, %esi
	imull	%r13d, %r11d
	subl	%esi, %eax
	leaq	t4(%rip), %rsi
	subl	%r11d, %eax
	addl	(%rsi,%r10,4), %eax
	addl	%eax, %edi
	andl	%edx, %r8d
	jne	.L127
.L126:
	leal	-1(%rcx), %eax
	andl	%eax, %ecx
	jne	.L129
	movl	48(%rsp), %esi
	subl	52(%rsp), %esi
	movl	56(%rsp), %eax
	movl	64(%rsp), %r10d
	movl	%esi, 48(%rsp)
	movl	80(%rsp), %esi
	subl	%edi, %eax
	movl	%eax, 56(%rsp)
	.p2align 4,,10
.L132:
	testl	%esi, %esi
	je	.L130
	movslq	%r10d, %r9
	movl	%esi, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L131:
	movl	48(%rsp), %eax
	leal	-1(%r8), %edx
	movslq	%r8d, %r11
	addq	%r9, %r11
	movl	(%r15,%r11,4), %ebp
	movl	(%rbx,%r11,4), %edi
	imull	(%r14,%r11,4), %eax
	imull	%r12d, %ebp
	imull	%r13d, %edi
	subl	%ebp, %eax
	subl	%edi, %eax
	leaq	t4(%rip), %rdi
	addl	(%rdi,%r11,4), %eax
	addl	%eax, %ecx
	andl	%edx, %r8d
	jne	.L131
.L130:
	leal	-1(%r10), %eax
	andl	%eax, %r10d
	jne	.L132
	addl	56(%rsp), %ecx
	movl	%ecx, 56(%rsp)
.L125:
	movl	56(%rsp), %eax
	movl	n(%rip), %ebp
	testl	%eax, %eax
	je	.L133
	cmpl	%ebp, %r13d
	jg	.L142
	movl	m(%rip), %r11d
	movl	52(%rsp), %esi
	imull	%r12d, %esi
	cmpl	%r11d, %r12d
	jg	.L137
	leaq	t4(%rip), %rax
	movl	%r13d, %r10d
	.p2align 4,,10
.L139:
	movslq	%r10d, %r9
	movl	%r12d, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L138:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	subl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	subl	%r13d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	subl	%r12d, (%rbx,%rdx,4)
	subl	%esi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L138
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L139
.L137:
	movl	44(%rsp), %esi
	movl	52(%rsp), %edi
	imull	%esi, %edi
	cmpl	%esi, %r11d
	jl	.L142
	leaq	t4(%rip), %rax
	movl	%r13d, %r10d
	.p2align 4,,10
.L143:
	movslq	%r10d, %r9
	movl	%esi, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L141:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	addl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	addl	%r13d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	addl	%esi, (%rbx,%rdx,4)
	addl	%edi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L141
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L143
.L142:
	cmpl	%ebp, 60(%rsp)
	jg	.L135
	movl	60(%rsp), %edi
	movl	m(%rip), %r11d
	movl	%edi, %esi
	imull	%r12d, %esi
	cmpl	%r11d, %r12d
	jg	.L146
	leaq	t4(%rip), %rax
	movl	%edi, %r10d
	.p2align 4,,10
.L148:
	movslq	%r10d, %r9
	movl	%r12d, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L147:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	addl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	addl	%edi, (%r15,%rdx,4)
	addl	%r8d, %ecx
	addl	%r12d, (%rbx,%rdx,4)
	addl	%esi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L147
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L148
.L146:
	movl	%r13d, %r9d
	movl	44(%rsp), %r13d
	notl	%r9d
	movl	%r13d, %r10d
	imull	%r9d, %r10d
	cmpl	%r13d, %r11d
	jl	.L135
	leaq	t4(%rip), %rax
	movl	%r12d, %esi
	movl	60(%rsp), %r12d
	notl	%esi
	.p2align 4,,10
.L151:
	movslq	%r12d, %rdi
	movl	%r13d, %ecx
	imulq	$1007, %rdi, %rdi
	.p2align 4,,10
.L150:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%rdi, %rdx
	subl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	addl	%r9d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	addl	%esi, (%rbx,%rdx,4)
	addl	%r10d, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L150
	movl	%r12d, %edx
	negl	%edx
	andl	%r12d, %edx
	addl	%edx, %r12d
	cmpl	%ebp, %r12d
	jle	.L151
.L135:
	subl	$1, 84(%rsp)
.L145:
	movl	84(%rsp), %eax
	cltd
	idivl	%ebp
	testl	%ebp, %ebp
	movl	%edx, 48(%rsp)
	movl	%edx, %r13d
	movl	%eax, 56(%rsp)
	je	.L190
	leal	1(%rax), %r10d
	xorl	%esi, %esi
	movl	%ebp, %r9d
	movl	%ebp, 52(%rsp)
	leal	1(%rbp), %r12d
	movl	%r10d, %edi
	movl	%edx, 60(%rsp)
	movl	%eax, %r13d
	imull	%r12d, %edi
	movl	%edi, 44(%rsp)
	.p2align 4,,10
.L174:
	testl	%r13d, %r13d
	je	.L172
	movslq	%r9d, %r8
	movl	%r13d, %ecx
	imulq	$1007, %r8, %r8
	.p2align 4,,10
.L173:
	movl	44(%rsp), %eax
	leal	-1(%rcx), %edx
	movslq	%ecx, %r11
	addq	%r8, %r11
	movl	(%r15,%r11,4), %ebp
	movl	(%rbx,%r11,4), %edi
	imull	(%r14,%r11,4), %eax
	imull	%r10d, %ebp
	imull	%r12d, %edi
	subl	%ebp, %eax
	subl	%edi, %eax
	leaq	t4(%rip), %rdi
	addl	(%rdi,%r11,4), %eax
	addl	%eax, %esi
	andl	%edx, %ecx
	jne	.L173
.L172:
	leal	-1(%r9), %eax
	andl	%eax, %r9d
	jne	.L174
	movl	60(%rsp), %r13d
	movl	52(%rsp), %ebp
	movl	%esi, 52(%rsp)
	.p2align 4,,10
.L175:
	leal	-1(%rbp), %eax
	andl	%eax, %ebp
	jne	.L175
.L171:
	movl	48(%rsp), %edx
	testl	%edx, %edx
	je	.L176
	movl	56(%rsp), %esi
	leal	1(%rdx), %eax
	xorl	%edi, %edi
	movl	%r13d, 48(%rsp)
	movl	%eax, 44(%rsp)
	leal	2(%rsi), %r12d
	imull	%r12d, %eax
	movl	%eax, %esi
	.p2align 4,,10
.L179:
	testl	%r10d, %r10d
	je	.L177
	movslq	%edx, %r9
	movl	%r10d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L178:
	movl	44(%rsp), %ebp
	leal	-1(%r8), %ecx
	movslq	%r8d, %r11
	addq	%r9, %r11
	movl	(%r14,%r11,4), %eax
	movl	(%r15,%r11,4), %r13d
	imull	(%rbx,%r11,4), %ebp
	imull	%esi, %eax
	imull	%r12d, %r13d
	subl	%r13d, %eax
	subl	%ebp, %eax
	leaq	t4(%rip), %rbp
	addl	0(%rbp,%r11,4), %eax
	addl	%eax, %edi
	andl	%ecx, %r8d
	jne	.L178
.L177:
	leal	-1(%rdx), %eax
	andl	%eax, %edx
	jne	.L179
	movl	48(%rsp), %r13d
	movl	%r10d, 48(%rsp)
	leaq	t4(%rip), %r12
	subl	44(%rsp), %esi
	movl	%edi, 60(%rsp)
	movl	56(%rsp), %r10d
	.p2align 4,,10
.L182:
	testl	%r10d, %r10d
	je	.L180
	movslq	%r13d, %r9
	movl	%r10d, %r8d
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L181:
	movl	48(%rsp), %ebp
	leal	-1(%r8), %ecx
	movslq	%r8d, %r11
	addq	%r9, %r11
	movl	44(%rsp), %edi
	movl	(%r14,%r11,4), %eax
	imull	(%r15,%r11,4), %ebp
	imull	(%rbx,%r11,4), %edi
	imull	%esi, %eax
	subl	%ebp, %eax
	subl	%edi, %eax
	addl	(%r12,%r11,4), %eax
	addl	%eax, %edx
	andl	%ecx, %r8d
	jne	.L181
.L180:
	leal	-1(%r13), %eax
	andl	%eax, %r13d
	jne	.L182
	movl	60(%rsp), %eax
	subl	%edx, %eax
	addl	%eax, 52(%rsp)
.L176:
	movl	84(%rsp), %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	subl	52(%rsp), %edx
	call	_ZNSolsEi
	movq	72(%rsp), %rdx
	movl	$1, %r8d
	movb	$10, 119(%rsp)
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	q(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, q(%rip)
	jne	.L93
.L237:
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
.L133:
	cmpl	%ebp, %r13d
	jg	.L161
	movl	m(%rip), %r11d
	movl	52(%rsp), %esi
	imull	%r12d, %esi
	cmpl	%r11d, %r12d
	jg	.L156
	leaq	t4(%rip), %rax
	movl	%r13d, %r10d
	.p2align 4,,10
.L158:
	movslq	%r10d, %r9
	movl	%r12d, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L157:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	addl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	addl	%r13d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	addl	%r12d, (%rbx,%rdx,4)
	addl	%esi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L157
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L158
.L156:
	movl	44(%rsp), %ecx
	movl	52(%rsp), %edi
	imull	%ecx, %edi
	cmpl	%ecx, %r11d
	jl	.L161
	movl	%r12d, %esi
	movl	%r12d, 48(%rsp)
	movl	%r13d, %r10d
	movl	%ecx, %r12d
	leaq	t4(%rip), %rax
	notl	%esi
	.p2align 4,,10
.L162:
	movslq	%r10d, %r9
	movl	%r12d, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L160:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	subl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	subl	%r13d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	subl	%edi, (%rax,%rdx,4)
	addl	%esi, (%rbx,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L160
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L162
	movl	48(%rsp), %r12d
.L161:
	cmpl	%ebp, 60(%rsp)
	jg	.L154
	movl	m(%rip), %r11d
	movl	%r13d, %esi
	notl	%esi
	movl	%esi, %edi
	imull	%r12d, %edi
	cmpl	%r11d, %r12d
	jg	.L164
	movl	60(%rsp), %r10d
	leaq	t4(%rip), %rax
	.p2align 4,,10
.L166:
	movslq	%r10d, %r9
	movl	%r12d, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L165:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	subl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	subl	%r12d, (%rbx,%rdx,4)
	addl	%r8d, %ecx
	addl	%esi, (%r15,%rdx,4)
	addl	%edi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L165
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L166
.L164:
	movl	60(%rsp), %ecx
	movl	44(%rsp), %edi
	movl	%ecx, %esi
	imull	%edi, %esi
	cmpl	%edi, %r11d
	jl	.L154
	leaq	t4(%rip), %rax
	movl	%ecx, %r10d
	movl	%ecx, %r12d
	.p2align 4,,10
.L169:
	movslq	%r10d, %r9
	movl	%edi, %ecx
	imulq	$1007, %r9, %r9
	.p2align 4,,10
.L168:
	movl	%ecx, %r8d
	movslq	%ecx, %rdx
	negl	%r8d
	addq	%r9, %rdx
	addl	$1, (%r14,%rdx,4)
	andl	%ecx, %r8d
	addl	%r12d, (%r15,%rdx,4)
	addl	%r8d, %ecx
	addl	%edi, (%rbx,%rdx,4)
	addl	%esi, (%rax,%rdx,4)
	cmpl	%r11d, %ecx
	jle	.L168
	movl	%r10d, %edx
	negl	%edx
	andl	%r10d, %edx
	addl	%edx, %r10d
	cmpl	%ebp, %r10d
	jle	.L169
.L154:
	addl	$1, 84(%rsp)
	jmp	.L145
	.p2align 4,,10
.L239:
	cmpl	44(%rsp), %r11d
	jge	.L97
	cmpl	%r8d, %esi
	jge	.L115
	jmp	.L90
	.p2align 4,,10
.L185:
	cmpl	44(%rsp), %r11d
	jge	.L97
	jmp	.L90
	.p2align 4,,10
.L190:
	movl	$0, 52(%rsp)
	leal	1(%rax), %r10d
	jmp	.L171
	.p2align 4,,10
.L117:
	leal	-1(%r12), %eax
	movl	$0, 56(%rsp)
	movl	$-1, %r10d
	movl	%eax, 80(%rsp)
	movl	$0, 52(%rsp)
	movl	$1, 60(%rsp)
	jmp	.L184
.L189:
	movl	$0, 84(%rsp)
	jmp	.L90
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