__asm__(R"(
	.file	"tmp.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB5360:
	.seh_endprologue
	movl	%edx, %eax
	ret
	.seh_endproc
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB7476:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.globl	_Z7dbg_outv
	.def	_Z7dbg_outv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7dbg_outv
_Z7dbg_outv:
.LFB6637:
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
.LFB6639:
	.seh_endprologue
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z6lowbitx
	.def	_Z6lowbitx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6lowbitx
_Z6lowbitx:
.LFB6643:
	.seh_endprologue
	movq	%rcx, %rax
	negq	%rax
	andq	%rcx, %rax
	ret
	.seh_endproc
	.section	.text$_Z4readIiJEEvRT_DpRT0_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z4readIiJEEvRT_DpRT0_
	.def	_Z4readIiJEEvRT_DpRT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readIiJEEvRT_DpRT0_
_Z4readIiJEEvRT_DpRT0_:
.LFB7001:
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
	movq	.refptr._ZSt3cin(%rip), %rsi
	xorl	%edi, %edi
	movl	$0, (%rcx)
	movq	%rcx, %rbx
	movq	%rsi, %rcx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L16
	movl	$1, %ebp
	.p2align 4,,10
	.p2align 3
.L15:
	cmpb	$45, %dl
	movq	%rsi, %rcx
	cmove	%ebp, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L15
	.p2align 4,,10
	.p2align 3
.L16:
	movl	(%rbx), %eax
	movq	%rsi, %rcx
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
	movl	%eax, (%rbx)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L16
	testb	%dil, %dil
	je	.L12
	negl	(%rbx)
.L12:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	_ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseIiSaIiEED2Ev
_ZNSt12_Vector_baseIiSaIiEED2Ev:
.LFB7019:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L24
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L24:
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB7193:
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
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	8(%rcx), %rdi
	movq	(%rcx), %r13
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rdx, %r12
	sarq	$2, %rax
	movq	%rcx, %rsi
	movq	%r8, %r14
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	je	.L40
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L38
	testq	%rax, %rax
	jne	.L31
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L37:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L41
	testq	%r9, %r9
	jg	.L33
	testq	%r13, %r13
	jne	.L36
.L34:
	movq	%rbp, (%rsi)
	movq	%rdi, 8(%rsi)
	movq	%rbx, 16(%rsi)
	addq	$56, %rsp
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
	.p2align 3
.L41:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L33
.L36:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L33:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L34
	jmp	.L36
	.p2align 4,,10
	.p2align 3
.L38:
	movabsq	$9223372036854775804, %rbx
.L30:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L37
	.p2align 4,,10
	.p2align 3
.L31:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L30
.L40:
	leaq	.LC0(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.section	.text$_Z6qprintIiEvT_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6qprintIiEvT_
	.def	_Z6qprintIiEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6qprintIiEvT_
_Z6qprintIiEvT_:
.LFB7207:
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
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	%ecx, %ebx
	testl	%ecx, %ecx
	js	.L51
.L43:
	movl	%ebx, %edi
	cmpl	$9, %ebx
	jg	.L48
.L49:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%rdi, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	jmp	_ZNSo3putEc
	.p2align 4,,10
	.p2align 3
.L48:
	movl	$3435973837, %ecx
	movq	%rdi, %rsi
	imulq	%rcx, %rsi
	shrq	$35, %rsi
	movl	%esi, %r13d
	cmpl	$99, %ebx
	jg	.L46
.L47:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%r13, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L49
	.p2align 4,,10
	.p2align 3
.L51:
	movl	$45, %edx
	movq	%r12, %rcx
	negl	%ebx
	call	_ZNSo3putEc
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L46:
	movq	%r13, %rbp
	imulq	%rcx, %rbp
	shrq	$35, %rbp
	movl	%ebp, %r14d
	cmpl	$999, %ebx
	jg	.L44
.L45:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%r14, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebp
	leal	48(%rbp), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L47
	.p2align 4,,10
	.p2align 3
.L44:
	imulq	%r14, %rcx
	shrq	$35, %rcx
	call	_Z6qprintIiEvT_
	jmp	.L45
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
.LFB6644:
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
	subq	$232, %rsp
	.seh_stackalloc	232
	.seh_endprologue
	leaq	88(%rsp), %rcx
.LEHB0:
	call	_Z4readIiJEEvRT_DpRT0_
	movl	88(%rsp), %edi
	leal	1(%rdi), %esi
	movslq	%esi, %rsi
	movq	%rsi, %rax
	shrq	$61, %rax
	jne	.L124
	leaq	0(,%rsi,4), %rbx
	movq	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	movq	%rbx, 32(%rsp)
	testq	%rsi, %rsi
	je	.L54
	movq	%rbx, %rcx
	call	_Znwy
.LEHE0:
	movq	%rax, %r13
	movq	%rax, 96(%rsp)
	movq	%rbx, %rax
	leaq	0(%r13,%rbx), %rcx
	movl	$0, 0(%r13)
	leaq	4(%r13), %rbx
	movq	%rcx, 40(%rsp)
	movq	%rcx, 112(%rsp)
	cmpq	$1, %rsi
	je	.L55
	cmpq	%rcx, %rbx
	je	.L56
	leaq	-4(%rax), %r8
	xorl	%edx, %edx
	movq	%rbx, %rcx
	call	memset
.L56:
	movq	40(%rsp), %rax
	movq	%rax, 104(%rsp)
	testl	%edi, %edi
	jle	.L57
	leal	-1(%rdi), %eax
	leaq	8(%r13,%rax,4), %rbp
	.p2align 4,,10
	.p2align 3
.L58:
	movq	%rbx, %rcx
.LEHB1:
	call	_Z4readIiJEEvRT_DpRT0_
	addq	$4, %rbx
	cmpq	%rbx, %rbp
	jne	.L58
.L57:
	movq	$0, 136(%rsp)
	movq	$0, 144(%rsp)
.L94:
	movq	32(%rsp), %rbx
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %r14
	movq	%rax, 128(%rsp)
	movq	%rax, 136(%rsp)
	leaq	(%rax,%rbx), %rax
	movq	%rax, 48(%rsp)
	movq	%rax, 144(%rsp)
	movl	$0, (%r14)
	cmpq	$1, %rsi
	je	.L59
	leaq	4(%r14), %rsi
	movq	%rsi, 72(%rsp)
	movq	%rsi, 56(%rsp)
	cmpq	%rsi, %rax
	je	.L60
	leaq	-4(%rbx), %r8
	xorl	%edx, %edx
	movq	%rsi, %rcx
	call	memset
.L60:
	movq	48(%rsp), %rax
	movq	%rax, 136(%rsp)
	testl	%edi, %edi
	jle	.L59
	leal	-1(%rdi), %r9d
	movl	$1, %eax
	leaq	2(%r9), %r8
	.p2align 4,,10
	.p2align 3
.L61:
	movslq	0(%r13,%rax,4), %rcx
	movq	%rcx, %rdx
	negq	%rdx
	andq	%rcx, %rdx
	movl	%edx, (%r14,%rax,4)
	addq	$1, %rax
	cmpq	%rax, %r8
	jne	.L61
	leaq	4(%r13), %rbx
	leaq	8(%r13,%r9,4), %rsi
	xorl	%r12d, %r12d
	movq	$0, 160(%rsp)
	movq	$0, 168(%rsp)
	leaq	160(%rsp), %rbp
	movq	$0, 176(%rsp)
	jmp	.L65
	.p2align 4,,10
	.p2align 3
.L63:
	addq	$4, %rbx
	cmpq	%rbx, %rsi
	je	.L125
.L65:
	movl	(%rbx), %eax
	testb	$1, %al
	jne	.L63
	cmpq	%r12, 176(%rsp)
	je	.L64
	movl	%eax, (%r12)
	addq	$4, %rbx
	addq	$4, %r12
	movq	%r12, 168(%rsp)
	cmpq	%rbx, %rsi
	jne	.L65
.L125:
	movq	160(%rsp), %r15
	cmpq	%r12, %r15
	je	.L126
	movq	%r12, %rax
	subq	%r15, %rax
	sarq	$2, %rax
	movq	%rax, %rbp
	movl	%eax, %ebx
	cmpl	%eax, %edi
	jg	.L79
	movq	%r15, %rbx
	movq	%r15, %rax
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L69:
	movslq	(%rax), %rdx
	addq	$4, %rax
	addq	%rdx, %rsi
	cmpq	%rax, %r12
	jne	.L69
	leaq	92(%rsp), %rax
	xorl	%edx, %edx
	movq	$0, 192(%rsp)
	xorl	%r9d, %r9d
	movq	%rax, 64(%rsp)
	leaq	192(%rsp), %rdi
	movq	$0, 200(%rsp)
	movq	$0, 208(%rsp)
	jmp	.L72
	.p2align 4,,10
	.p2align 3
.L70:
	addq	$4, %rbx
	cmpq	%rbx, %r12
	je	.L127
.L72:
	movl	(%rbx), %eax
	movl	%eax, %ecx
	movl	%eax, 92(%rsp)
	andl	$3, %ecx
	cmpl	$2, %ecx
	jne	.L70
	cmpq	%rdx, %r9
	je	.L71
	movl	%eax, (%r9)
	addq	$4, %rbx
	addq	$4, %r9
	movq	%r9, 200(%rsp)
	cmpq	%rbx, %r12
	jne	.L72
	.p2align 4,,10
	.p2align 3
.L127:
	movq	192(%rsp), %rcx
	movq	%r9, %rax
	movl	%ebp, %ebx
	subq	%rcx, %rax
	sarq	$2, %rax
	subl	%eax, %ebx
	cmpq	%r9, %rcx
	je	.L73
	movq	%rcx, %rax
	.p2align 4,,10
	.p2align 3
.L74:
	movslq	(%rax), %r8
	addq	$4, %rax
	subq	%r8, %rsi
	cmpq	%r9, %rax
	jne	.L74
	movslq	-4(%rax), %r9
	addq	%rsi, %r9
	movq	%r9, %r8
	negq	%r8
	andq	%r9, %r8
	bsrq	%r8, %r8
	subq	$4, %rax
	xorq	$63, %r8
	subq	%rcx, %rax
	subl	%r8d, %ebx
	sarq	$2, %rax
	leal	63(%rbx,%rax), %ebx
.L92:
	testq	%rcx, %rcx
	je	.L79
	subq	%rcx, %rdx
	call	_ZdlPvy
.L79:
	movq	176(%rsp), %rdx
	subq	%r15, %rdx
.L67:
	testq	%r15, %r15
	je	.L80
	movq	%r15, %rcx
	call	_ZdlPvy
.L80:
	movq	32(%rsp), %rdx
	movq	%r14, %rcx
	call	_ZdlPvy
	testl	%ebx, %ebx
	js	.L128
.L84:
	cmpl	$9, %ebx
	jg	.L90
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	%ebx, %edi
	jmp	.L91
	.p2align 4,,10
	.p2align 3
.L54:
	movq	$0, 96(%rsp)
	xorl	%r13d, %r13d
	xorl	%ebx, %ebx
	movq	$0, 112(%rsp)
	movq	$0, 40(%rsp)
.L55:
	movq	%rbx, 104(%rsp)
	movq	$0, 128(%rsp)
	movq	$0, 136(%rsp)
	movq	$0, 144(%rsp)
	testq	%rsi, %rsi
	jne	.L94
.L123:
	movq	.refptr._ZSt4cout(%rip), %r12
	xorl	%ebx, %ebx
	xorl	%edi, %edi
.L91:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%rdi, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	movl	$32, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
	movl	$10, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
.LEHE1:
	testq	%r13, %r13
	je	.L52
	movq	40(%rsp), %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	addq	$232, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L64:
	movq	%rbx, %r8
	movq	%r12, %rdx
	movq	%rbp, %rcx
	movq	%rbp, %r15
.LEHB2:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE2:
	movq	168(%rsp), %r12
	jmp	.L63
	.p2align 4,,10
	.p2align 3
.L52:
	addq	$232, %rsp
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
	.p2align 3
.L90:
	movl	%ebx, %edi
	movl	$3435973837, %eax
	movq	%rdi, %rsi
	imulq	%rax, %rsi
	shrq	$35, %rsi
	cmpl	$99, %ebx
	jg	.L88
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	%esi, %ebp
.L89:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%rbp, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
.LEHB3:
	call	_ZNSo3putEc
	jmp	.L91
	.p2align 4,,10
	.p2align 3
.L128:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negl	%ebx
	jmp	.L84
.L88:
	movl	%esi, %ebp
	movq	%rbp, %r12
	imulq	%rax, %r12
	shrq	$35, %r12
	movl	%r12d, %r14d
	cmpl	$999, %ebx
	jg	.L86
.L87:
	movl	$3435973837, %eax
	imulq	%r14, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %r12d
	leal	48(%r12), %edx
	movq	.refptr._ZSt4cout(%rip), %r12
	movzbl	%dl, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
.LEHE3:
	jmp	.L89
.L73:
	movq	72(%rsp), %rdi
	cmpq	%rdi, 48(%rsp)
	je	.L129
	movq	48(%rsp), %r9
	leaq	8(%r14), %rax
	cmpq	%rax, %r9
	je	.L76
	movq	56(%rsp), %r8
	.p2align 4,,10
	.p2align 3
.L78:
	movl	(%r8), %edi
	cmpl	%edi, (%rax)
	cmovl	%rax, %r8
	addq	$4, %rax
	cmpq	%rax, %r9
	jne	.L78
	movq	%r8, %rax
	subq	%r14, %rax
	sarq	$2, %rax
	cltq
	leaq	(%r14,%rax,4), %rax
	movq	%rax, 56(%rsp)
.L76:
	movq	56(%rsp), %rax
	movslq	(%rax), %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	subl	%eax, %ebx
	addl	$62, %ebx
	jmp	.L92
	.p2align 4,,10
	.p2align 3
.L71:
	movq	64(%rsp), %r8
	movq	%r9, %rdx
	movq	%rdi, %rcx
.LEHB4:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE4:
	movq	200(%rsp), %r9
	movq	208(%rsp), %rdx
	jmp	.L70
.L126:
	movq	176(%rsp), %rdx
	xorl	%ebx, %ebx
	subq	%r12, %rdx
	jmp	.L67
.L129:
	movq	48(%rsp), %rax
	movq	%rax, 56(%rsp)
	jmp	.L76
.L86:
	imulq	%r14, %rax
	shrq	$35, %rax
	movq	%rax, %rcx
.LEHB5:
	call	_Z6qprintIiEvT_
.LEHE5:
	jmp	.L87
.L124:
	leaq	.LC1(%rip), %rcx
.LEHB6:
	call	_ZSt20__throw_length_errorPKc
.L59:
	movq	32(%rsp), %rdx
	movq	%r14, %rcx
	call	_ZdlPvy
	jmp	.L123
.L100:
	movq	%rdi, %rcx
	movq	%rax, %r12
	leaq	160(%rsp), %r15
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L82:
	movq	%r15, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	leaq	128(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L83:
	leaq	96(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE6:
.L98:
	movq	%rax, %r12
	jmp	.L83
.L99:
	movq	%rax, %r12
	jmp	.L82
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA6644:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6644-.LLSDACSB6644
.LLSDACSB6644:
	.uleb128 .LEHB0-.LFB6644
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB6644
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L98-.LFB6644
	.uleb128 0
	.uleb128 .LEHB2-.LFB6644
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L99-.LFB6644
	.uleb128 0
	.uleb128 .LEHB3-.LFB6644
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L98-.LFB6644
	.uleb128 0
	.uleb128 .LEHB4-.LFB6644
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L100-.LFB6644
	.uleb128 0
	.uleb128 .LEHB5-.LFB6644
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L98-.LFB6644
	.uleb128 0
	.uleb128 .LEHB6-.LFB6644
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE6644:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "w\0"
.LC3:
	.ascii "testdata.log\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB6657:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$2, %ecx
	call	*__imp___acrt_iob_func(%rip)
	leaq	.LC2(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	movq	%rax, %r8
	call	freopen
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	44(%rsp), %rcx
	movq	$0, 232(%rax)
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	$0, 224(%rax)
	call	_Z4readIiJEEvRT_DpRT0_
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	leal	-2(%rax), %ebx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	je	.L136
	.p2align 4,,10
	.p2align 3
.L132:
	call	_Z8solutionv
	movl	%ebx, 44(%rsp)
	subl	$1, %ebx
	cmpl	$-2, %ebx
	jne	.L132
.L136:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB7477:
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
	.quad	_GLOBAL__sub_I__Z7dbg_outv
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
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
	.section	.rdata$.refptr._ZSt4clog, "dr"
	.globl	.refptr._ZSt4clog
	.linkonce	discard
.refptr._ZSt4clog:
	.quad	_ZSt4clog

)");