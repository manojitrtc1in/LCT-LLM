__asm__( R"(
	.file	"\316\264\303\374\303\3731.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11306:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB7:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rdx, 72(%rsp)
	leaq	72(%rsp), %rdx
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rdx, 40(%rsp)
	call	__mingw_vscanf
	addq	$56, %rsp
	ret
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB13:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rdx, 72(%rsp)
	leaq	72(%rsp), %rdx
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rdx, 40(%rsp)
	call	__mingw_vprintf
	addq	$56, %rsp
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E:
.LFB10775:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rsi
	movq	%rdx, %rbx
.L5:
	testq	%rbx, %rbx
	je	.L8
	movq	24(%rbx), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	16(%rbx), %rdi
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rdi, %rbx
	jmp	.L5
.L8:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	.def	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_:
.LFB10791:
	.seh_endprologue
	leaq	8(%rcx), %r8
	movq	16(%rcx), %rcx
	movq	%r8, %rax
.L10:
	testq	%rcx, %rcx
	je	.L17
	movl	(%rdx), %r10d
	cmpl	%r10d, 32(%rcx)
	jl	.L11
	movq	16(%rcx), %r9
	jmp	.L12
.L11:
	movq	24(%rcx), %r9
	movq	%rax, %rcx
.L12:
	movq	%rcx, %rax
	movq	%r9, %rcx
	jmp	.L10
.L17:
	cmpq	%r8, %rax
	je	.L14
	movl	32(%rax), %ecx
	cmpl	%ecx, (%rdx)
	jge	.L16
.L14:
	movq	%r8, %rax
.L16:
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB11063:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	16(%rdx), %rax
	leaq	8(%rdx), %rsi
	movq	%rcx, %rbx
	movb	$1, %cl
.L19:
	testq	%rax, %rax
	je	.L31
	movl	32(%rax), %ecx
	cmpl	%ecx, (%r8)
	jge	.L20
	movq	16(%rax), %r9
	movb	$1, %cl
	jmp	.L21
.L20:
	movq	24(%rax), %r9
	xorl	%ecx, %ecx
.L21:
	movq	%rax, %rsi
	movq	%r9, %rax
	jmp	.L19
.L31:
	testb	%cl, %cl
	movq	%rsi, %rax
	je	.L23
	cmpq	24(%rdx), %rsi
	je	.L30
	movq	%rsi, %rcx
	movq	%r8, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	40(%rsp), %r8
.L23:
	movl	(%r8), %edx
	cmpl	%edx, 32(%rax)
	jge	.L26
.L30:
	movq	$0, (%rbx)
	movq	%rsi, 8(%rbx)
	jmp	.L18
.L26:
	movq	%rax, (%rbx)
	movq	$0, 8(%rbx)
.L18:
	movq	%rbx, %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_:
.LFB10786:
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
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	%rcx, %rsi
	movl	$40, %ecx
	movq	%rdx, %r13
	movq	%r9, 40(%rsp)
	leaq	8(%rsi), %r12
	movq	%r13, %rbx
	call	_Znwy
	movq	40(%rsp), %r9
	movq	%rax, %rbp
	leaq	32(%rax), %r8
	cmpq	%r12, %r13
	movq	(%r9), %rax
	movl	(%rax), %edi
	movb	$0, 36(%rbp)
	movl	%edi, 32(%rbp)
	jne	.L33
	cmpq	$0, 40(%rsi)
	je	.L34
	movq	32(%rsi), %rax
	cmpl	%edi, 32(%rax)
	jl	.L35
	jmp	.L34
.L33:
	movl	32(%r13), %eax
	cmpl	%eax, %edi
	jge	.L36
	movq	24(%rsi), %rbx
	movq	%r8, 40(%rsp)
	cmpq	%rbx, %r13
	movq	%rbx, %rax
	je	.L39
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	%edi, 32(%rax)
	movq	40(%rsp), %r8
	jge	.L34
	xorl	%ebx, %ebx
	cmpq	$0, 24(%rax)
	je	.L39
	movq	%r13, %rax
	movq	%r13, %rbx
	jmp	.L39
.L36:
	cmpl	%edi, %eax
	jge	.L40
	movq	32(%rsi), %rax
	xorl	%ebx, %ebx
	movq	%r8, 40(%rsp)
	cmpq	%rax, %r13
	je	.L39
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %edi
	movq	%rax, %rbx
	movq	40(%rsp), %r8
	jge	.L34
	cmpq	$0, 24(%r13)
	jne	.L39
	movq	%r13, %rax
	xorl	%ebx, %ebx
.L39:
	testq	%rax, %rax
	je	.L40
.L45:
	testq	%rbx, %rbx
	jne	.L50
	cmpq	%r12, %rax
	je	.L50
	cmpl	32(%rax), %edi
	setl	%cl
	jmp	.L43
.L50:
	movb	$1, %cl
.L43:
	movq	%rax, %r8
	movzbl	%cl, %ecx
	movq	%r12, %r9
	movq	%rbp, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%rbp, %rax
	jmp	.L54
.L40:
	movq	%rbp, %rcx
	call	_ZdlPv
	movq	%rbx, %rax
	jmp	.L54
.L34:
	leaq	48(%rsp), %rcx
	movq	%rsi, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	48(%rsp), %rbx
	movq	56(%rsp), %rax
	jmp	.L39
.L35:
	xorl	%ebx, %ebx
	jmp	.L45
.L54:
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.seh_endproc
	.weak	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.section	.text$_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	.def	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_:
.LFB10527:
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	16(%rcx), %r8
	leaq	8(%rcx), %r9
	movq	%r9, %rax
.L56:
	testq	%r8, %r8
	je	.L63
	movl	(%rdx), %r11d
	cmpl	%r11d, 32(%r8)
	jl	.L57
	movq	16(%r8), %r10
	jmp	.L58
.L57:
	movq	24(%r8), %r10
	movq	%rax, %r8
.L58:
	movq	%r8, %rax
	movq	%r10, %r8
	jmp	.L56
.L63:
	cmpq	%r9, %rax
	je	.L60
	movl	32(%rax), %r11d
	cmpl	%r11d, (%rdx)
	jge	.L61
.L60:
	movq	%rdx, 56(%rsp)
	leaq	55(%rsp), %rdx
	leaq	56(%rsp), %r9
	leaq	_ZStL19piecewise_construct(%rip), %r8
	movq	%rdx, 32(%rsp)
	movq	%rax, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L61:
	addq	$36, %rax
	addq	$72, %rsp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
.LC1:
	.ascii "%d%d\0"
.LC2:
	.ascii "0\0"
.LC3:
	.ascii "%d\12\0"
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10117:
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
	leaq	80(%rsp), %rbx
	leaq	t_case(%rip), %rdx
	leaq	.LC0(%rip), %rcx
.LEHB0:
	call	_Z5scanfPKcz
	leaq	8(%rbx), %rax
	movq	%rax, 48(%rsp)
.L65:
	movl	t_case(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, t_case(%rip)
	je	.L88
	leaq	.LC1(%rip), %rcx
	leaq	p(%rip), %r8
	leaq	n(%rip), %rdx
	leaq	88(%rsp), %rdi
	leaq	4+a(%rip), %rsi
	movl	$1, %ebp
	call	_Z5scanfPKcz
.LEHE0:
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	$0, 120(%rsp)
	rep stosl
	leaq	8(%rbx), %rax
	movl	$0, a(%rip)
	xorl	%edi, %edi
	movq	%rax, 104(%rsp)
	movq	%rax, 112(%rsp)
.L66:
	movslq	n(%rip), %rax
	cmpl	%eax, %ebp
	jg	.L89
	leaq	.LC0(%rip), %rcx
	movq	%rsi, %rdx
.LEHB1:
	call	_Z5scanfPKcz
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	cmpb	$1, (%rax)
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	adcl	$0, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	incl	%ebp
	addq	$4, %rsi
	jmp	.L66
.L89:
	movl	p(%rip), %ecx
	cmpl	%ecx, %edi
	jne	.L69
	leaq	.LC2(%rip), %rcx
	call	puts
	jmp	.L70
.L69:
	leaq	a(%rip), %rbp
	leaq	76(%rsp), %r13
	movl	0(%rbp,%rax,4), %eax
	movq	%rbp, %r14
	decl	%eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movl	%edx, 76(%rsp)
.L71:
	movq	%r13, %rdx
	movq	%rbx, %rcx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	48(%rsp), %rax
	movl	76(%rsp), %edx
	je	.L90
	movl	p(%rip), %ecx
	leal	-1(%rdx), %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movl	%edx, 76(%rsp)
	jmp	.L71
.L90:
	movslq	n(%rip), %rax
	movq	%rax, %rsi
	movl	0(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	.L86
	decl	%esi
	leaq	a(%rip), %r15
	xorl	%r12d, %r12d
	movslq	%esi, %rax
	salq	$2, %rax
	movq	%rax, 56(%rsp)
.L75:
	movslq	%esi, %rax
	movl	(%r14,%rax,4), %ecx
	leal	1(%rcx), %edx
	cmpl	p(%rip), %edx
	movl	%edx, (%r14,%rax,4)
	jne	.L91
	movl	$0, (%r15,%rax,4)
	movq	56(%rsp), %rax
	movq	%rbx, %rcx
	addq	%r12, %rax
	addq	%r15, %rax
	movq	%rax, %rdx
	movq	%rax, 40(%rsp)
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %al
	movq	40(%rsp), %rdx
	movq	%rbx, %rcx
	xorl	$1, %eax
	movzbl	%al, %eax
	addl	%eax, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	decl	%esi
	subq	$4, %r12
	jmp	.L75
.L91:
	leaq	a(%rip), %rdx
	movq	%rbx, %rcx
	leaq	(%rdx,%rax,4), %rsi
	movq	%rsi, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %al
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	xorl	$1, %eax
	movzbl	%al, %eax
	addl	%eax, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
.LEHE1:
	cmpl	p(%rip), %edi
	movb	$1, (%rax)
	jne	.L84
	movslq	n(%rip), %rax
	subl	0(%rbp,%rax,4), %edi
	movl	%edi, %edx
	jmp	.L87
.L84:
	movq	%r13, %rdx
	movq	%rbx, %rcx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	48(%rsp), %rax
	movl	p(%rip), %ecx
	movl	76(%rsp), %edx
	je	.L92
	leal	-1(%rdx), %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movl	%edx, 76(%rsp)
	jmp	.L84
.L92:
	movslq	n(%rip), %rax
	movl	0(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jl	.L79
	subl	%eax, %ecx
	movl	%ecx, %edx
	jmp	.L87
.L79:
	addl	%ecx, %edx
.L86:
	subl	%eax, %edx
.L87:
	leaq	.LC3(%rip), %rcx
	call	_Z6printfPKcz
.L70:
	movq	96(%rsp), %rdx
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	jmp	.L65
.L83:
	movq	96(%rsp), %rdx
	movq	%rax, %rsi
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rsi, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L88:
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
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10117:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10117-.LLSDACSB10117
.LLSDACSB10117:
	.uleb128 .LEHB0-.LFB10117
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB10117
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L83-.LFB10117
	.uleb128 0
	.uleb128 .LEHB2-.LFB10117
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE10117:
	.section	.text.startup,"x"
	.seh_endproc
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB11337:
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
	.globl	t_case
	.bss
	.align 4
t_case:
	.space 4
	.globl	p
	.align 4
p:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	a
	.align 64
a:
	.space 800040
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef

)");