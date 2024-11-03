__asm__(R"(
	.file	"CF1690G Count the Trains.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB2867:
	.seh_endprologue
	movl	%edx, %eax
	ret
	.seh_endproc
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB14047:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB14079:
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
	movq	%rcx, 112(%rsp)
	testq	%rcx, %rcx
	je	.L4
.L22:
	movq	112(%rsp), %rax
	movq	24(%rax), %rsi
	testq	%rsi, %rsi
	je	.L6
.L21:
	movq	24(%rsi), %rdi
	testq	%rdi, %rdi
	je	.L7
.L20:
	movq	24(%rdi), %rbp
	testq	%rbp, %rbp
	je	.L8
.L19:
	movq	24(%rbp), %r12
	testq	%r12, %r12
	je	.L9
.L18:
	movq	24(%r12), %r13
	testq	%r13, %r13
	je	.L10
.L17:
	movq	24(%r13), %r15
	testq	%r15, %r15
	je	.L11
.L16:
	movq	24(%r15), %r14
	testq	%r14, %r14
	je	.L12
.L15:
	movq	24(%r14), %rbx
	testq	%rbx, %rbx
	je	.L13
.L14:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L14
.L13:
	movq	16(%r14), %rbx
	movl	$40, %edx
	movq	%r14, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L12
	movq	%rbx, %r14
	jmp	.L15
.L10:
	movq	16(%r12), %r13
	movl	$40, %edx
	movq	%r12, %rcx
	call	_ZdlPvy
	testq	%r13, %r13
	je	.L9
	movq	%r13, %r12
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L11:
	movq	16(%r13), %r14
	movl	$40, %edx
	movq	%r13, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L10
	movq	%r14, %r13
	jmp	.L17
.L9:
	movq	16(%rbp), %r12
	movl	$40, %edx
	movq	%rbp, %rcx
	call	_ZdlPvy
	testq	%r12, %r12
	je	.L8
	movq	%r12, %rbp
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L12:
	movq	16(%r15), %r14
	movl	$40, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L11
	movq	%r14, %r15
	jmp	.L16
.L8:
	movq	16(%rdi), %rbp
	movl	$40, %edx
	movq	%rdi, %rcx
	call	_ZdlPvy
	testq	%rbp, %rbp
	je	.L7
	movq	%rbp, %rdi
	jmp	.L20
.L7:
	movq	16(%rsi), %rdi
	movl	$40, %edx
	movq	%rsi, %rcx
	call	_ZdlPvy
	testq	%rdi, %rdi
	je	.L6
	movq	%rdi, %rsi
	jmp	.L21
.L6:
	movq	112(%rsp), %rax
	movl	$40, %edx
	movq	16(%rax), %rsi
	movq	%rax, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L4
	movq	%rsi, 112(%rsp)
	jmp	.L22
.L4:
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
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB13677:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	16(%rdx), %rbx
	movq	%rcx, %r12
	movq	%r8, %rsi
	testq	%rbx, %rbx
	je	.L72
	movl	(%r8), %r9d
	jmp	.L63
	.p2align 4,,10
	.p2align 3
.L69:
	movq	%rax, %rbx
.L63:
	movl	32(%rbx), %ecx
	movq	24(%rbx), %rax
	cmpl	%ecx, %r9d
	cmovl	16(%rbx), %rax
	setl	%r10b
	testq	%rax, %rax
	jne	.L69
	movq	%rbx, %r8
	testb	%r10b, %r10b
	jne	.L61
	cmpl	%r9d, %ecx
	jl	.L73
.L67:
	movq	%r12, %rax
	movq	%rbx, (%r12)
	movq	$0, 8(%r12)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.p2align 4,,10
	.p2align 3
.L72:
	leaq	8(%rdx), %rbx
.L61:
	cmpq	%rbx, 24(%rdx)
	je	.L74
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	(%rsi), %r9d
	movq	%rbx, %r8
	movl	32(%rax), %ecx
	movq	%rax, %rbx
	cmpl	%r9d, %ecx
	jge	.L67
.L73:
	movq	%r12, %rax
	movq	$0, (%r12)
	movq	%r8, 8(%r12)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.p2align 4,,10
	.p2align 3
.L74:
	movq	%r12, %rax
	movq	$0, (%r12)
	movq	%rbx, 8(%r12)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.seh_endproc
	.text
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0:
.LFB14082:
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
	movq	%rcx, %rbx
	movl	$40, %ecx
	movq	%r8, %rdi
	movq	%rdx, %rsi
	call	_Znwy
	leaq	8(%rbx), %r13
	movq	%rax, %r12
	movq	(%rdi), %rax
	movq	%rsi, %rdi
	movl	$0, 36(%r12)
	leaq	32(%r12), %r15
	movl	(%rax), %ebp
	movl	%ebp, 32(%r12)
	cmpq	%r13, %rsi
	je	.L99
	movl	32(%rsi), %r14d
	cmpl	%r14d, %ebp
	jge	.L80
	movq	24(%rbx), %rax
	cmpq	%rax, %rsi
	je	.L91
	movq	%rsi, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rax, %r8
	cmpl	32(%rax), %ebp
	jg	.L100
.L85:
	movq	%r15, %r8
	leaq	32(%rsp), %rcx
	movq	%rbx, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	40(%rsp), %rax
	movq	32(%rsp), %rdi
	movq	%rax, %r8
	testq	%rax, %rax
	je	.L84
.L83:
	testq	%rdi, %rdi
	setne	%al
.L89:
	cmpq	%r8, %r13
	je	.L94
	testb	%al, %al
	je	.L101
.L94:
	movl	$1, %ecx
.L87:
	movq	%r13, %r9
	movq	%r12, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rbx)
	jmp	.L98
	.p2align 4,,10
	.p2align 3
.L80:
	jle	.L84
	movq	32(%rbx), %r8
	cmpq	%r8, %rsi
	je	.L92
	movq	%rsi, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %r8
	cmpl	32(%rax), %ebp
	jge	.L85
	cmpq	$0, 24(%rsi)
	jne	.L94
	movq	%rsi, %r8
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L84:
	movq	%r12, %rcx
	movl	$40, %edx
	movq	%rdi, %r12
	call	_ZdlPvy
.L98:
	movq	%r12, %rax
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
.L99:
	cmpq	$0, 40(%rbx)
	je	.L85
	movq	32(%rbx), %r8
	cmpl	32(%r8), %ebp
	jle	.L85
.L78:
	xorl	%eax, %eax
	jmp	.L89
	.p2align 4,,10
	.p2align 3
.L100:
	cmpq	$0, 24(%rax)
	je	.L78
	movq	%rsi, %r8
	jmp	.L83
	.p2align 4,,10
	.p2align 3
.L101:
	movl	32(%r8), %r14d
.L86:
	xorl	%ecx, %ecx
	cmpl	%r14d, %ebp
	setl	%cl
	jmp	.L87
	.p2align 4,,10
	.p2align 3
.L91:
	movq	%rax, %r8
.L81:
	movq	%rax, %rdi
	jmp	.L83
	.p2align 4,,10
	.p2align 3
.L92:
	xorl	%eax, %eax
	jmp	.L81
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "cannot create std::vector larger than max_size()\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB11909:
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
	subq	$184, %rsp
	.seh_stackalloc	184
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %r13
	leaq	88(%rsp), %rdx
	movq	%r13, %rcx
.LEHB0:
	call	_ZNSirsERi
	leaq	92(%rsp), %rax
	movl	88(%rsp), %edx
	movl	$0, 44(%rsp)
	movq	%rax, 56(%rsp)
	leaq	96(%rsp), %rax
	movq	.refptr._ZSt4cout(%rip), %rbp
	movq	%rax, 64(%rsp)
	testl	%edx, %edx
	jle	.L190
.L103:
	movq	56(%rsp), %rdx
	movq	%r13, %rcx
	call	_ZNSirsERi
	movq	64(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movslq	92(%rsp), %rbx
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbx
	ja	.L198
	leaq	0(,%rbx,4), %rdi
	testq	%rbx, %rbx
	je	.L154
	movq	%rdi, %rcx
	call	_Znwy
.LEHE0:
	movq	%rax, %r12
	leaq	(%rax,%rdi), %rax
	movq	%rax, 48(%rsp)
	movl	$0, (%r12)
	cmpq	$1, %rbx
	je	.L106
	leaq	4(%r12), %rcx
	movl	92(%rsp), %ebx
	cmpq	%rax, %rcx
	je	.L107
	leaq	-4(%rdi), %r8
	xorl	%edx, %edx
	call	memset
.L107:
	testl	%ebx, %ebx
	jle	.L105
	movq	%r12, %rsi
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L108:
	movq	%rsi, %rdx
	movq	%r13, %rcx
.LEHB1:
	call	_ZNSirsERi
.LEHE1:
	movl	92(%rsp), %eax
	addl	$1, %ebx
	addq	$4, %rsi
	cmpl	%ebx, %eax
	jg	.L108
	leaq	136(%rsp), %rbx
	movl	$0, 136(%rsp)
	movq	$0, 144(%rsp)
	movq	%rbx, 152(%rsp)
	movq	%rbx, 160(%rsp)
	movq	$0, 168(%rsp)
	movl	$0, 120(%rsp)
	testl	%eax, %eax
	jle	.L118
	movl	$1100000000, %edx
	xorl	%ecx, %ecx
	leaq	120(%rsp), %r15
	leaq	104(%rsp), %rdi
	leaq	128(%rsp), %r14
	jmp	.L109
.L199:
	movl	120(%rsp), %ecx
	addl	$1, %ecx
	movl	%ecx, 120(%rsp)
	cmpl	92(%rsp), %ecx
	jge	.L118
.L109:
	movslq	%ecx, %rax
	movl	(%r12,%rax,4), %esi
	cmpl	%edx, %esi
	jge	.L199
	movq	144(%rsp), %rdx
	movq	%rbx, %r10
	testq	%rdx, %rdx
	jne	.L116
	jmp	.L114
	.p2align 4,,10
	.p2align 3
.L201:
	movq	%r8, %rdx
	testq	%rdx, %rdx
	je	.L200
.L116:
	movq	16(%rdx), %rax
	movq	24(%rdx), %r8
	cmpl	32(%rdx), %ecx
	jg	.L201
	movq	%rdx, %r10
	movq	%rax, %rdx
	testq	%rdx, %rdx
	jne	.L116
.L200:
	cmpq	%rbx, %r10
	je	.L114
	cmpl	32(%r10), %ecx
	jge	.L117
.L114:
	movq	%rdi, %r8
	movq	%r10, %rdx
	movq	%r14, %rcx
	movq	%r15, 104(%rsp)
.LEHB2:
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	%rax, %r10
.L117:
	movl	%esi, 36(%r10)
	movslq	120(%rsp), %rax
	movq	%rax, %rcx
	movl	(%r12,%rax,4), %edx
	addl	$1, %ecx
	movl	%ecx, 120(%rsp)
	cmpl	92(%rsp), %ecx
	jl	.L109
.L118:
	leaq	120(%rsp), %rax
	movq	.refptr._ZSt4cout(%rip), %rsi
	xorl	%edi, %edi
	leaq	100(%rsp), %r14
	movq	%rax, 72(%rsp)
	movl	96(%rsp), %eax
	leaq	104(%rsp), %r15
	testl	%eax, %eax
	jle	.L111
	.p2align 4,,10
	.p2align 3
.L110:
	movq	%r14, %rdx
	movq	%r13, %rcx
	call	_ZNSirsERi
	movq	%rax, %rcx
	movq	%r15, %rdx
	call	_ZNSirsERi
	movl	100(%rsp), %eax
	movq	144(%rsp), %rdx
	leal	-1(%rax), %r8d
	movslq	%r8d, %rax
	movl	%r8d, 100(%rsp)
	leaq	(%r12,%rax,4), %rax
	movl	(%rax), %esi
	subl	104(%rsp), %esi
	movl	%esi, (%rax)
	testq	%rdx, %rdx
	je	.L121
	movq	%rdx, %rax
	movq	%rbx, %r10
	jmp	.L123
	.p2align 4,,10
	.p2align 3
.L203:
	movq	%r9, %rax
	testq	%rax, %rax
	je	.L202
.L123:
	movq	16(%rax), %rcx
	movq	24(%rax), %r9
	cmpl	32(%rax), %r8d
	jg	.L203
	movq	%rax, %r10
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L123
.L202:
	movq	%rdx, %rax
	cmpq	%rbx, %r10
	je	.L161
	cmpl	32(%r10), %r8d
	movq	%rbx, %r10
	jl	.L131
	jmp	.L126
	.p2align 4,,10
	.p2align 3
.L205:
	movq	%r9, %rax
	testq	%rax, %rax
	je	.L204
.L131:
	movq	16(%rax), %rcx
	movq	24(%rax), %r9
	cmpl	32(%rax), %r8d
	jge	.L205
	movq	%rax, %r10
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L131
.L204:
	movq	%r10, %rcx
	movq	%rdx, 32(%rsp)
	movl	%r8d, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	40(%rsp), %r8d
	movq	32(%rsp), %rdx
	cmpl	36(%rax), %esi
	jge	.L129
	movq	%rdx, %rax
	movq	%rbx, %r9
	jmp	.L136
.L207:
	movq	%r10, %rax
	testq	%rax, %rax
	je	.L206
.L136:
	movq	16(%rax), %rcx
	movq	24(%rax), %r10
	cmpl	32(%rax), %r8d
	jg	.L207
	movq	%rax, %r9
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L136
.L206:
	cmpq	%rbx, %r9
	je	.L133
	cmpl	32(%r9), %r8d
	jge	.L137
.L133:
	movq	72(%rsp), %r8
	leaq	128(%rsp), %rcx
	movq	%r9, %rdx
	movq	%r14, 120(%rsp)
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	144(%rsp), %rdx
	movq	%rax, %r9
.L137:
	movl	%esi, 36(%r9)
	testq	%rdx, %rdx
	jne	.L208
	.p2align 4,,10
	.p2align 3
.L134:
	movq	168(%rsp), %rdx
	movq	%rbp, %rcx
	movq	%rbp, %rsi
	call	_ZNSo9_M_insertIyEERSoT_
	movl	96(%rsp), %eax
	leal	-1(%rax), %edx
	cmpl	%edi, %edx
	jg	.L209
.L141:
	addl	$1, %edi
	cmpl	%edi, %eax
	jg	.L110
.L111:
	movq	(%rsi), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%rsi), %r14
	testq	%r14, %r14
	je	.L210
	cmpb	$0, 56(%r14)
	je	.L142
	movsbl	67(%r14), %edx
.L143:
	movq	%rsi, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	movq	144(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L147
.L144:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L144
.L147:
	testq	%r12, %r12
	je	.L146
	movq	48(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
.L146:
	addl	$1, 44(%rsp)
	movl	44(%rsp), %eax
	cmpl	%eax, 88(%rsp)
	jg	.L103
.L190:
	xorl	%eax, %eax
	addq	$184, %rsp
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
.L212:
	movq	%r9, %rax
	testq	%rax, %rax
	je	.L211
.L126:
	movq	16(%rax), %rcx
	movq	24(%rax), %r9
	cmpl	32(%rax), %r8d
	jg	.L212
	movq	%rax, %r10
	movq	%rcx, %rax
	testq	%rax, %rax
	jne	.L126
.L211:
	cmpq	%rbx, %r10
	je	.L127
	cmpl	32(%r10), %r8d
	jge	.L128
.L127:
	leaq	128(%rsp), %rcx
	leaq	112(%rsp), %r8
	movq	%r10, %rdx
	movq	%r14, 112(%rsp)
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	144(%rsp), %rdx
	movq	%rax, %r10
.L128:
	movl	%esi, 36(%r10)
	.p2align 4,,10
	.p2align 3
.L129:
	testq	%rdx, %rdx
	je	.L134
.L208:
	movslq	100(%rsp), %r8
	movq	%rbx, %r9
	jmp	.L140
	.p2align 4,,10
	.p2align 3
.L214:
	movq	%rcx, %rdx
	testq	%rdx, %rdx
	je	.L213
.L140:
	movq	16(%rdx), %rax
	movq	24(%rdx), %rcx
	cmpl	32(%rdx), %r8d
	jge	.L214
	movq	%rdx, %r9
	movq	%rax, %rdx
	testq	%rdx, %rdx
	jne	.L140
.L213:
	cmpq	%rbx, %r9
	je	.L134
	movl	(%r12,%r8,4), %eax
	cmpl	%eax, 36(%r9)
	jl	.L134
	movq	%r9, %rcx
	movq	%rbx, %rdx
	call	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_
	movl	$40, %edx
	movq	%rax, %rcx
	call	_ZdlPvy
	movq	144(%rsp), %rdx
	subq	$1, 168(%rsp)
	jmp	.L129
.L209:
	leaq	87(%rsp), %rdx
	movl	$1, %r8d
	movq	%rbp, %rcx
	movb	$32, 87(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	96(%rsp), %eax
	jmp	.L141
.L161:
	movq	%rbx, %r10
	jmp	.L131
.L142:
	movq	%r14, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r14), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L143
	movq	%r14, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L143
.L154:
	movq	$0, 48(%rsp)
	xorl	%r12d, %r12d
.L105:
	leaq	136(%rsp), %rbx
	movl	$0, 136(%rsp)
	movq	$0, 144(%rsp)
	movq	%rbx, 152(%rsp)
	movq	%rbx, 160(%rsp)
	movq	$0, 168(%rsp)
	jmp	.L118
.L121:
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	36(%rax), %esi
	jge	.L134
	movq	%rbx, %r9
	jmp	.L133
.L106:
	movl	92(%rsp), %ebx
	jmp	.L107
.L210:
	call	_ZSt16__throw_bad_castv
.LEHE2:
.L198:
	leaq	.LC0(%rip), %rcx
.LEHB3:
	call	_ZSt20__throw_length_errorPKc
.L171:
	movq	144(%rsp), %rcx
	movq	%rax, %r13
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	48(%rsp), %rdx
	subq	%r12, %rdx
	testq	%r12, %r12
	je	.L151
.L150:
	movq	%r12, %rcx
	call	_ZdlPvy
.L151:
	movq	%r13, %rcx
	call	_Unwind_Resume
.LEHE3:
.L172:
	movq	%rax, %r13
	movq	%rdi, %rdx
	jmp	.L150
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA11909:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE11909-.LLSDACSB11909
.LLSDACSB11909:
	.uleb128 .LEHB0-.LFB11909
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB11909
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L172-.LFB11909
	.uleb128 0
	.uleb128 .LEHB2-.LFB11909
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L171-.LFB11909
	.uleb128 0
	.uleb128 .LEHB3-.LFB11909
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE11909:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB14070:
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
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIyEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
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
