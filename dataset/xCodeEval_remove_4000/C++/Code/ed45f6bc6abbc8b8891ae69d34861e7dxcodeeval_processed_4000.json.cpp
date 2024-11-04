__asm__(R"(
	.file	"CF1688D.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB4636:
	.seh_endprologue
	movl	%edx, %eax
	ret
	.seh_endproc
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB8555:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.globl	_Z7dbg_outv
	.def	_Z7dbg_outv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7dbg_outv
_Z7dbg_outv:
.LFB7648:
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	.refptr._ZSt4clog(%rip), %r13
	movq	0(%r13), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%r13), %r12
	testq	%r12, %r12
	je	.L9
	cmpb	$0, 56(%r12)
	je	.L6
	movsbl	67(%r12), %edx
.L7:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L7
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L7
.L9:
	call	_ZSt16__throw_bad_castv
	nop
	.seh_endproc
	.p2align 4
	.globl	_Z4readv
	.def	_Z4readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readv
_Z4readv:
.LFB7650:
	.seh_endprologue
	ret
	.seh_endproc
	.section	.text$_Z6qprintIxEvT_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6qprintIxEvT_
	.def	_Z6qprintIxEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6qprintIxEvT_
_Z6qprintIxEvT_:
.LFB8261:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	.refptr._ZSt4cout(%rip), %r12
	movq	%rcx, %rbx
	testq	%rcx, %rcx
	js	.L20
.L12:
	cmpq	$9, %rbx
	jg	.L21
.L18:
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	jmp	_ZNSo3putEc
	.p2align 4,,10
	.p2align 3
.L21:
	movabsq	$-3689348814741910323, %rcx
	movq	%rbx, %rax
	mulq	%rcx
	movq	%rdx, %rsi
	shrq	$3, %rsi
	cmpq	$99, %rbx
	jg	.L22
.L16:
	movabsq	$-3689348814741910323, %rdx
	movq	%rsi, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rsi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L20:
	movl	$45, %edx
	movq	%r12, %rcx
	negq	%rbx
	call	_ZNSo3putEc
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L22:
	movq	%rsi, %rax
	mulq	%rcx
	movq	%rdx, %rdi
	shrq	$3, %rdi
	cmpq	$999, %rbx
	jg	.L23
.L14:
	movabsq	$-3689348814741910323, %rdx
	movq	%rdi, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rdi
	leal	48(%rdi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L23:
	movq	%rdi, %rax
	mulq	%rcx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L14
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "cannot create std::vector larger than max_size()\0"
	.text
	.p2align 4
	.globl	_Z8solutionv
	.def	_Z8solutionv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8solutionv
_Z8solutionv:
.LFB7654:
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
	subq	$104, %rsp
	.seh_stackalloc	104
	movaps	%xmm6, 64(%rsp)
	.seh_savexmm	%xmm6, 64
	movaps	%xmm7, 80(%rsp)
	.seh_savexmm	%xmm7, 80
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rbx
	xorl	%esi, %esi
	movq	%rbx, %rcx
.LEHB0:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L25
	movl	$1, %edi
	.p2align 4,,10
	.p2align 3
.L27:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%edi, %esi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L27
.L25:
	xorl	%r13d, %r13d
	.p2align 4,,10
	.p2align 3
.L28:
	leal	0(%r13,%r13,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %edi
	call	_ZNSi3getEv
	leal	-48(%rdi), %r13d
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L28
	movl	$48, %eax
	movq	%rbx, %rcx
	subl	%edi, %eax
	testb	%sil, %sil
	cmovne	%eax, %r13d
	xorl	%esi, %esi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L30
	movl	$1, %edi
	.p2align 4,,10
	.p2align 3
.L32:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%edi, %esi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L32
.L30:
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L33:
	leal	(%r12,%r12,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %edi
	call	_ZNSi3getEv
	leal	-48(%rdi), %r12d
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L33
	movl	$48, %eax
	subl	%edi, %eax
	leal	1(%r13), %edi
	testb	%sil, %sil
	movslq	%edi, %rdi
	cmovne	%eax, %r12d
	movq	%rdi, %rax
	shrq	$61, %rax
	jne	.L122
	leaq	0(,%rdi,4), %rsi
	movq	%rsi, 56(%rsp)
	testq	%rdi, %rdi
	je	.L77
	movq	%rsi, %rcx
	call	_Znwy
.LEHE0:
	movq	%rax, %r14
	movq	%rsi, %rax
	leaq	(%r14,%rsi), %rsi
	movl	$0, (%r14)
	movq	%rsi, 40(%rsp)
	movq	%rsi, %rcx
	leaq	4(%r14), %rsi
	cmpq	$1, %rdi
	je	.L36
	movq	%rcx, %rdi
	cmpq	%rsi, %rcx
	je	.L78
	leaq	-4(%rax), %r8
	xorl	%edx, %edx
	movq	%rsi, %rcx
	call	memset
	movq	%rdi, 48(%rsp)
.L37:
	testl	%r13d, %r13d
	jle	.L38
	leal	-1(%r13), %eax
	movl	$1, %ebp
	leaq	8(%r14,%rax,4), %r15
	.p2align 4,,10
	.p2align 3
.L44:
	movl	$0, (%rsi)
	movq	%rbx, %rcx
.LEHB1:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L42
	.p2align 4,,10
	.p2align 3
.L41:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%ebp, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L41
	.p2align 4,,10
	.p2align 3
.L42:
	movl	(%rsi), %eax
	movq	%rbx, %rcx
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
	movl	%eax, (%rsi)
	call	_ZNSi3getEv
.LEHE1:
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L42
	testb	%dil, %dil
	je	.L43
	negl	(%rsi)
.L43:
	addq	$4, %rsi
	cmpq	%r15, %rsi
	jne	.L44
.L38:
	cmpl	%r12d, %r13d
	jge	.L123
.L45:
	movq	48(%rsp), %rdi
	leaq	4(%r14), %r8
	cmpq	%rdi, %r8
	je	.L56
	leaq	-8(%rdi), %rdx
	movq	%r14, %rax
	subq	%r14, %rdx
	movq	%rdx, %rcx
	shrq	$2, %rcx
	addq	$1, %rcx
	cmpq	$8, %rdx
	jbe	.L83
	movq	%rcx, %rdx
	pxor	%xmm1, %xmm1
	pxor	%xmm4, %xmm4
	shrq	$2, %rdx
	salq	$4, %rdx
	addq	%r14, %rdx
	.p2align 4,,10
	.p2align 3
.L58:
	movdqu	4(%rax), %xmm0
	movdqa	%xmm4, %xmm2
	addq	$16, %rax
	pcmpgtd	%xmm0, %xmm2
	movdqa	%xmm0, %xmm3
	punpckldq	%xmm2, %xmm3
	punpckhdq	%xmm2, %xmm0
	paddq	%xmm3, %xmm1
	paddq	%xmm0, %xmm1
	cmpq	%rdx, %rax
	jne	.L58
	movdqa	%xmm1, %xmm0
	movq	%rcx, %rax
	psrldq	$8, %xmm0
	andq	$-4, %rax
	paddq	%xmm0, %xmm1
	leaq	(%r8,%rax,4), %r8
	movq	%xmm1, %rbx
	cmpq	%rcx, %rax
	je	.L59
.L57:
	movslq	(%r8), %rax
	movq	48(%rsp), %rdi
	addq	%rax, %rbx
	leaq	4(%r8), %rax
	cmpq	%rax, %rdi
	je	.L59
	movslq	4(%r8), %rax
	addq	%rax, %rbx
	leaq	8(%r8), %rax
	cmpq	%rax, %rdi
	je	.L59
	movslq	8(%r8), %rax
	addq	%rax, %rbx
.L59:
	testl	%r13d, %r13d
	jle	.L62
.L60:
	testl	%r13d, %r13d
	movl	$1, %ecx
	cmovg	%r13d, %ecx
	cmpl	$4, %r13d
	jle	.L85
	movl	%ecx, %edx
	movdqa	.LC0(%rip), %xmm2
	pxor	%xmm1, %xmm1
	xorl	%eax, %eax
	movd	%r12d, %xmm5
	movdqa	.LC2(%rip), %xmm6
	shrl	$2, %edx
	pshufd	$0, %xmm5, %xmm7
	pxor	%xmm5, %xmm5
	.p2align 4,,10
	.p2align 3
.L64:
	movdqa	%xmm2, %xmm3
	movdqa	%xmm7, %xmm0
	paddd	%xmm6, %xmm2
	addl	$1, %eax
	psubd	%xmm3, %xmm0
	movdqa	%xmm5, %xmm3
	pcmpgtd	%xmm0, %xmm3
	movdqa	%xmm0, %xmm4
	punpckldq	%xmm3, %xmm4
	punpckhdq	%xmm3, %xmm0
	paddq	%xmm4, %xmm1
	paddq	%xmm0, %xmm1
	cmpl	%edx, %eax
	jne	.L64
	movdqa	%xmm1, %xmm0
	movl	%ecx, %edx
	psrldq	$8, %xmm0
	andl	$-4, %edx
	paddq	%xmm0, %xmm1
	movq	%xmm1, %rax
	addq	%rax, %rbx
	leal	1(%rdx), %eax
	cmpl	%ecx, %edx
	je	.L62
.L63:
	movl	%r12d, %edx
	leal	1(%rax), %ecx
	subl	%eax, %edx
	movslq	%edx, %rdx
	addq	%rdx, %rbx
	cmpl	%ecx, %r13d
	jl	.L62
	movl	%r12d, %edx
	subl	%ecx, %edx
	leal	2(%rax), %ecx
	movslq	%edx, %rdx
	addq	%rdx, %rbx
	cmpl	%r13d, %ecx
	jg	.L62
	movl	%r12d, %edx
	addl	$3, %eax
	subl	%ecx, %edx
	movslq	%edx, %rdx
	addq	%rdx, %rbx
	cmpl	%r13d, %eax
	jg	.L62
	subl	%eax, %r12d
	movslq	%r12d, %rax
	addq	%rax, %rbx
.L62:
	testq	%rbx, %rbx
	js	.L124
.L66:
	cmpq	$9, %rbx
	jg	.L72
	leal	48(%rbx), %edx
	movq	.refptr._ZSt4cout(%rip), %r12
	movzbl	%dl, %edx
.L61:
	movq	%r12, %rcx
.LEHB2:
	call	_ZNSo3putEc
.L121:
	movl	$32, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
	movl	$10, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
	testq	%r14, %r14
	je	.L24
	movq	40(%rsp), %rdx
	movaps	64(%rsp), %xmm6
	movq	%r14, %rcx
	movaps	80(%rsp), %xmm7
	subq	%r14, %rdx
	addq	$104, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	jmp	_ZdlPvy
.L77:
	movq	$0, 40(%rsp)
	xorl	%r14d, %r14d
	xorl	%esi, %esi
.L36:
	movq	%rsi, 48(%rsp)
	cmpl	%r12d, %r13d
	jl	.L45
.L123:
	testl	%r12d, %r12d
	jle	.L80
	leal	-1(%r12), %r10d
	cmpl	$2, %r10d
	jbe	.L81
	leaq	4(%r14), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm4, %xmm4
	movl	%r12d, %edx
	shrl	$2, %edx
	subl	$1, %edx
	salq	$4, %rdx
	leaq	20(%r14,%rdx), %rdx
	.p2align 4,,10
	.p2align 3
.L48:
	movdqu	(%rax), %xmm0
	movdqa	%xmm4, %xmm2
	addq	$16, %rax
	pcmpgtd	%xmm0, %xmm2
	movdqa	%xmm0, %xmm3
	punpckldq	%xmm2, %xmm3
	punpckhdq	%xmm2, %xmm0
	paddq	%xmm3, %xmm1
	paddq	%xmm0, %xmm1
	cmpq	%rax, %rdx
	jne	.L48
	movdqa	%xmm1, %xmm0
	movl	%r12d, %ecx
	psrldq	$8, %xmm0
	andl	$-4, %ecx
	paddq	%xmm0, %xmm1
	leal	1(%rcx), %edx
	movq	%xmm1, %rax
	cmpl	%r12d, %ecx
	je	.L46
.L47:
	movslq	%edx, %rcx
	leaq	0(,%rcx,4), %r8
	movslq	(%r14,%rcx,4), %rcx
	addq	%rcx, %rax
	leal	1(%rdx), %ecx
	cmpl	%r12d, %ecx
	jg	.L46
	movslq	4(%r14,%r8), %rcx
	addl	$2, %edx
	addq	%rcx, %rax
	cmpl	%r12d, %edx
	jg	.L46
	movslq	8(%r14,%r8), %rdx
	addq	%rdx, %rax
.L46:
	cmpl	%r12d, %r13d
	jle	.L82
	subl	$1, %r13d
	leaq	4(%r14), %rdx
	movq	%rax, %r8
	subl	%r12d, %r13d
	movslq	%r12d, %r12
	leaq	8(%r14,%r13,4), %r9
	.p2align 4,,10
	.p2align 3
.L51:
	movslq	(%rdx), %rcx
	subq	%rcx, %rax
	movslq	(%rdx,%r12,4), %rcx
	addq	%rcx, %rax
	cmpq	%rax, %r8
	cmovl	%rax, %r8
	addq	$4, %rdx
	cmpq	%rdx, %r9
	jne	.L51
.L50:
	movslq	%r10d, %rax
	imulq	%r12, %rax
	movq	%rax, %rbx
	shrq	$63, %rbx
	addq	%rax, %rbx
	sarq	%rbx
	addq	%r8, %rbx
	js	.L125
.L52:
	cmpq	$9, %rbx
	jg	.L126
.L53:
	movq	%rbx, %rax
	movq	.refptr._ZSt4cout(%rip), %r12
	movabsq	$-3689348814741910323, %rdx
	mulq	%rdx
	movq	%r12, %rcx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L121
.L24:
	movaps	64(%rsp), %xmm6
	movaps	80(%rsp), %xmm7
	addq	$104, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L72:
	movabsq	$-3689348814741910323, %rcx
	movq	%rbx, %rax
	mulq	%rcx
	movq	%rdx, %rsi
	shrq	$3, %rsi
	cmpq	$99, %rbx
	jg	.L127
.L71:
	movq	%rsi, %rax
	movq	.refptr._ZSt4cout(%rip), %r12
	movabsq	$-3689348814741910323, %rdx
	mulq	%rdx
	movq	%r12, %rcx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rsi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	jmp	.L61
.L127:
	movq	%rsi, %rax
	mulq	%rcx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L71
.L124:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negq	%rbx
	jmp	.L66
.L126:
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	mulq	%rdx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L53
.L125:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
.LEHE2:
	negq	%rbx
	jmp	.L52
.L56:
	xorl	%ebx, %ebx
	testl	%r13d, %r13d
	jg	.L60
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	$48, %edx
	jmp	.L61
.L83:
	xorl	%ebx, %ebx
	jmp	.L57
.L85:
	movl	$1, %eax
	jmp	.L63
.L78:
	movq	%rcx, 48(%rsp)
	jmp	.L37
.L80:
	xorl	%eax, %eax
	leal	-1(%r12), %r10d
	jmp	.L46
.L82:
	movq	%rax, %r8
	movslq	%r12d, %r12
	jmp	.L50
.L81:
	xorl	%eax, %eax
	movl	$1, %edx
	jmp	.L47
.L122:
	leaq	.LC1(%rip), %rcx
.LEHB3:
	call	_ZSt20__throw_length_errorPKc
.L86:
	movq	40(%rsp), %rdx
	movq	%rax, %r12
	subq	%r14, %rdx
	testq	%r14, %r14
	je	.L69
.L74:
	movq	%r14, %rcx
	call	_ZdlPvy
.L69:
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE3:
.L87:
	movq	56(%rsp), %rdx
	movq	%rax, %r12
	jmp	.L74
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA7654:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7654-.LLSDACSB7654
.LLSDACSB7654:
	.uleb128 .LEHB0-.LFB7654
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7654
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L87-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L86-.LFB7654
	.uleb128 0
	.uleb128 .LEHB3-.LFB7654
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE7654:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC3:
	.ascii "w\0"
.LC4:
	.ascii "testdata.log\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB7656:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movl	$2, %ecx
	call	*__imp___acrt_iob_func(%rip)
	leaq	.LC3(%rip), %rdx
	leaq	.LC4(%rip), %rcx
	movq	%rax, %r8
	call	freopen
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	44(%rsp), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	$0, 232(%rcx)
	movq	$0, 224(%rax)
	call	_ZNSirsERi
	jmp	.L135
	.p2align 4,,10
	.p2align 3
.L136:
	call	_Z8solutionv
.L135:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L136
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB8556:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_1(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z7dbg_outv
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 16
.LC0:
	.long	1
	.long	2
	.long	3
	.long	4
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt4clog, "dr"
	.globl	.refptr._ZSt4clog
	.linkonce	discard
.refptr._ZSt4clog:
	.quad	_ZSt4clog
)");
