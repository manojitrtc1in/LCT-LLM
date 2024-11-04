



__asm__( R"(
	.file	"\316\264\303\374\303\3731.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11461:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.def	__tcf_2;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_2
__tcf_2:
.LFB11463:
	.seh_endprologue
	movq	dfs_in(%rip), %rcx
	testq	%rcx, %rcx
	je	.L2
	jmp	_ZdlPv
.L2:
	ret
	.seh_endproc
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11462:
	.seh_endprologue
	movq	dfs_out(%rip), %rcx
	testq	%rcx, %rcx
	je	.L5
	jmp	_ZdlPv
.L5:
	ret
	.seh_endproc
	.globl	_Z5checkxxx
	.def	_Z5checkxxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5checkxxx
_Z5checkxxx:
.LFB10115:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rdx, %r11
	movq	%r8, %rbp
	cqto
	movq	%r11, %rbx
	sarq	$63, %rbp
	idivq	%rcx
	movq	%rcx, %rdx
	sarq	$63, %rbx
	sarq	$63, %rdx
	imulq	%rcx, %rax
	movq	%rax, %r9
	sarq	$63, %rax
	movq	%rax, %r10
	movl	$11, %eax
.L12:
	cmpq	%r10, %rbx
	jg	.L8
	jl	.L13
	cmpq	%r9, %r11
	jae	.L8
.L13:
	cmpq	%rbp, %r10
	jg	.L8
	jl	.L14
	cmpq	%r8, %r9
	ja	.L8
.L14:
	movq	%r9, %rax
	jmp	.L11
.L8:
	addq	%rcx, %r9
	adcq	%rdx, %r10
	decq	%rax
	jne	.L12
	orq	$-1, %rax
.L11:
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_
	.def	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_
_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_:
.LFB10819:
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
	movq	8(%rcx), %rbx
	subq	(%rcx), %rbx
	movq	%rcx, %rdi
	movq	%rdx, %rbp
	movq	%rbx, %rax
	movl	$1, %ebx
	sarq	$3, %rax
	cmovne	%rax, %rbx
	addq	%rax, %rbx
	jc	.L29
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbx
	jbe	.L18
.L29:
	movabsq	$2305843009213693951, %rbx
.L25:
	leaq	0(,%rbx,8), %rcx
	call	_Znwy
	movq	%rax, %rsi
.L26:
	movq	8(%rdi), %r8
	movq	(%rdi), %rcx
	movq	0(%rbp), %rdx
	movq	%r8, %rax
	subq	%rcx, %rax
	addq	%rsi, %rax
	je	.L20
	movq	%rdx, (%rax)
.L20:
	movq	%rcx, %rdx
	movq	%rsi, %rax
.L21:
	cmpq	%r8, %rdx
	je	.L41
	testq	%rax, %rax
	movq	(%rdx), %r9
	je	.L30
	movq	%r9, (%rax)
.L30:
	addq	$8, %rax
	addq	$8, %rdx
	jmp	.L21
.L41:
	subq	%rcx, %rdx
	andq	$-8, %rdx
	testq	%rcx, %rcx
	leaq	8(%rsi,%rdx), %rbp
	je	.L24
	call	_ZdlPv
.L24:
	leaq	(%rsi,%rbx,8), %rax
	movq	%rsi, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rax, 16(%rdi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L18:
	xorl	%esi, %esi
	testq	%rbx, %rbx
	je	.L26
	jmp	.L25
	.seh_endproc
	.weak	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIJRKxEEEvDpOT_
	.def	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIJRKxEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIJRKxEEEvDpOT_,_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_
	.text
	.globl	_Z7Fac_dfsxx
	.def	_Z7Fac_dfsxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7Fac_dfsxx
_Z7Fac_dfsxx:
.LFB10114:
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
	movq	8+dfs_in(%rip), %rax
	subq	dfs_in(%rip), %rax
	movq	%rdx, 88(%rsp)
	sarq	$4, %rax
	cmpq	%rax, %rcx
	je	.L43
	movq	%rcx, %rbp
	xorl	%esi, %esi
	movl	$1, %edi
	salq	$4, %rbp
	leaq	1(%rcx), %rbx
	jmp	.L44
.L43:
	movq	8+dfs_out(%rip), %rax
	cmpq	16+dfs_out(%rip), %rax
	je	.L45
	testq	%rax, %rax
	movq	88(%rsp), %rdx
	je	.L46
	movq	%rdx, (%rax)
.L46:
	addq	$8, %rax
	movq	%rax, 8+dfs_out(%rip)
	jmp	.L42
.L45:
	leaq	88(%rsp), %rdx
	leaq	dfs_out(%rip), %rcx
	call	_ZNSt6vectorIxSaIxEE19_M_emplace_back_auxIIRKxEEEvDpOT_
	jmp	.L42
.L44:
	movq	dfs_in(%rip), %rax
	cmpq	8(%rax,%rbp), %rsi
	jg	.L42
	movq	%rdi, %rdx
	movq	%rbx, %rcx
	incq	%rsi
	imulq	88(%rsp), %rdx
	call	_Z7Fac_dfsxx
	movq	%rbp, %rax
	addq	dfs_in(%rip), %rax
	imulq	(%rax), %rdi
	jmp	.L44
.L42:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E:
.LFB10826:
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
.L53:
	testq	%rbx, %rbx
	je	.L55
	movq	24(%rbx), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	16(%rbx), %rdi
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rdi, %rbx
	jmp	.L53
.L55:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.def	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_:
.LFB11044:
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
	movq	8(%rcx), %rbx
	subq	(%rcx), %rbx
	movq	%rcx, %rdi
	movq	%rdx, %rbp
	movq	%rbx, %rax
	movl	$1, %ebx
	sarq	$4, %rax
	cmovne	%rax, %rbx
	addq	%rax, %rbx
	jc	.L69
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, %rbx
	jbe	.L58
.L69:
	movabsq	$1152921504606846975, %rbx
.L65:
	movq	%rbx, %rcx
	salq	$4, %rcx
	call	_Znwy
	movq	%rax, %rsi
.L66:
	movq	8(%rdi), %r8
	movq	(%rdi), %rcx
	movq	%r8, %rax
	subq	%rcx, %rax
	addq	%rsi, %rax
	je	.L60
	movups	0(%rbp), %xmm0
	movups	%xmm0, (%rax)
.L60:
	movq	%rcx, %rdx
	movq	%rsi, %rax
.L61:
	cmpq	%r8, %rdx
	je	.L81
	testq	%rax, %rax
	je	.L70
	movups	(%rdx), %xmm1
	movups	%xmm1, (%rax)
.L70:
	addq	$16, %rax
	addq	$16, %rdx
	jmp	.L61
.L81:
	subq	%rcx, %rdx
	andq	$-16, %rdx
	testq	%rcx, %rcx
	leaq	16(%rsi,%rdx), %rbp
	je	.L64
	call	_ZdlPv
.L64:
	salq	$4, %rbx
	movq	%rsi, (%rdi)
	movq	%rbp, 8(%rdi)
	addq	%rbx, %rsi
	movq	%rsi, 16(%rdi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L58:
	xorl	%esi, %esi
	testq	%rbx, %rbx
	je	.L66
	jmp	.L65
	.seh_endproc
	.weak	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_
	.def	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_,_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.section	.text$_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB11163:
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
.L83:
	testq	%rax, %rax
	je	.L95
	movq	32(%rax), %rcx
	cmpq	%rcx, (%r8)
	jge	.L84
	movq	16(%rax), %r9
	movb	$1, %cl
	jmp	.L85
.L84:
	movq	24(%rax), %r9
	xorl	%ecx, %ecx
.L85:
	movq	%rax, %rsi
	movq	%r9, %rax
	jmp	.L83
.L95:
	testb	%cl, %cl
	movq	%rsi, %rax
	je	.L87
	cmpq	24(%rdx), %rsi
	je	.L94
	movq	%rsi, %rcx
	movq	%r8, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	40(%rsp), %r8
.L87:
	movq	(%r8), %rdx
	cmpq	%rdx, 32(%rax)
	jge	.L90
.L94:
	movq	$0, (%rbx)
	movq	%rsi, 8(%rbx)
	jmp	.L82
.L90:
	movq	%rax, (%rbx)
	movq	$0, 8(%rbx)
.L82:
	movq	%rbx, %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_:
.LFB10835:
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
	movl	$48, %ecx
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
	movq	(%rax), %rdi
	movq	$0, 40(%rbp)
	movq	%rdi, 32(%rbp)
	jne	.L97
	cmpq	$0, 40(%rsi)
	je	.L98
	movq	32(%rsi), %rax
	cmpq	%rdi, 32(%rax)
	jl	.L99
	jmp	.L98
.L97:
	movq	32(%r13), %rax
	cmpq	%rax, %rdi
	jge	.L100
	movq	24(%rsi), %rbx
	movq	%r8, 40(%rsp)
	cmpq	%rbx, %r13
	movq	%rbx, %rax
	je	.L103
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpq	%rdi, 32(%rax)
	movq	40(%rsp), %r8
	jge	.L98
	xorl	%ebx, %ebx
	cmpq	$0, 24(%rax)
	je	.L103
	movq	%r13, %rax
	movq	%r13, %rbx
	jmp	.L103
.L100:
	cmpq	%rdi, %rax
	jge	.L104
	movq	32(%rsi), %rax
	xorl	%ebx, %ebx
	movq	%r8, 40(%rsp)
	cmpq	%rax, %r13
	je	.L103
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpq	32(%rax), %rdi
	movq	%rax, %rbx
	movq	40(%rsp), %r8
	jge	.L98
	cmpq	$0, 24(%r13)
	jne	.L103
	movq	%r13, %rax
	xorl	%ebx, %ebx
.L103:
	testq	%rax, %rax
	je	.L104
.L109:
	testq	%rbx, %rbx
	jne	.L114
	cmpq	%r12, %rax
	je	.L114
	cmpq	32(%rax), %rdi
	setl	%cl
	jmp	.L107
.L114:
	movb	$1, %cl
.L107:
	movq	%rax, %r8
	movzbl	%cl, %ecx
	movq	%r12, %r9
	movq	%rbp, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%rbp, %rax
	jmp	.L118
.L104:
	movq	%rbp, %rcx
	call	_ZdlPv
	movq	%rbx, %rax
	jmp	.L118
.L98:
	leaq	48(%rsp), %rcx
	movq	%rsi, %rdx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	48(%rsp), %rbx
	movq	56(%rsp), %rax
	jmp	.L103
.L99:
	xorl	%ebx, %ebx
	jmp	.L109
.L118:
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.seh_endproc
	.weak	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.def	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.section	.text$_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
	.def	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_:
.LFB10541:
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	16(%rcx), %r8
	leaq	8(%rcx), %r9
	movq	%r9, %rax
.L120:
	testq	%r8, %r8
	je	.L127
	movq	(%rdx), %r11
	cmpq	%r11, 32(%r8)
	jl	.L121
	movq	16(%r8), %r10
	jmp	.L122
.L121:
	movq	24(%r8), %r10
	movq	%rax, %r8
.L122:
	movq	%r8, %rax
	movq	%r10, %r8
	jmp	.L120
.L127:
	cmpq	%r9, %rax
	je	.L124
	movq	32(%rax), %r11
	cmpq	%r11, (%rdx)
	jge	.L125
.L124:
	movq	%rdx, 56(%rsp)
	leaq	55(%rsp), %rdx
	leaq	56(%rsp), %r9
	leaq	_ZStL19piecewise_construct(%rip), %r8
	movq	%rdx, 32(%rsp)
	movq	%rax, %rdx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L125:
	addq	$40, %rax
	addq	$72, %rsp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "-1 -1\0"
	.text
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB10116:
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
	subq	$152, %rsp
	.seh_stackalloc	152
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	48(%rsp), %r13
	leaq	56(%rsp), %rsi
	leaq	104(%rsp), %rdi
	leaq	96(%rsp), %rbx
	movq	%r13, %rdx
.LEHB0:
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	64(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	72(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERx
.LEHE0:
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	48(%rsp), %r12
	rep stosl
	movq	56(%rsp), %rbp
	leaq	8(%rbx), %rax
	leaq	80(%rsp), %rdi
	movq	$0, 136(%rsp)
	movq	$2, 80(%rsp)
	movq	%rax, 120(%rsp)
	movq	%rax, 128(%rsp)
.L129:
	movq	80(%rsp), %rax
	movq	48(%rsp), %rdx
	imulq	%rax, %rax
	cmpq	%rdx, %rax
	jg	.L170
.L166:
	movq	48(%rsp), %rax
	movq	80(%rsp), %rcx
	cqto
	idivq	%rcx
	testq	%rdx, %rdx
	jne	.L171
	movq	%rdi, %rdx
	movq	%rbx, %rcx
	movq	%rax, 48(%rsp)
.LEHB1:
	call	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
	incq	(%rax)
	jmp	.L166
.L171:
	incq	%rcx
	movq	%rcx, 80(%rsp)
	jmp	.L129
.L170:
	decq	%rdx
	je	.L132
	movq	%r13, %rdx
	movq	%rbx, %rcx
	call	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
	incq	(%rax)
.L132:
	leaq	80(%rsp), %rdi
	movq	$2, 80(%rsp)
.L133:
	movq	80(%rsp), %rax
	movq	56(%rsp), %rdx
	imulq	%rax, %rax
	cmpq	%rdx, %rax
	jg	.L172
.L167:
	movq	56(%rsp), %rax
	movq	80(%rsp), %rcx
	cqto
	idivq	%rcx
	testq	%rdx, %rdx
	jne	.L173
	movq	%rdi, %rdx
	movq	%rbx, %rcx
	movq	%rax, 56(%rsp)
	call	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
	incq	(%rax)
	jmp	.L167
.L173:
	incq	%rcx
	movq	%rcx, 80(%rsp)
	jmp	.L133
.L172:
	decq	%rdx
	je	.L136
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	call	_ZNSt3mapIxxSt4lessIxESaISt4pairIKxxEEEixERS3_
	incq	(%rax)
.L136:
	movq	dfs_in(%rip), %rax
	movq	120(%rsp), %rsi
	leaq	8(%rbx), %rdi
	movq	%rbp, 56(%rsp)
	leaq	80(%rsp), %rbp
	movq	%r12, 48(%rsp)
	movq	%rax, 8+dfs_in(%rip)
	movq	dfs_out(%rip), %rax
	movq	%rax, 8+dfs_out(%rip)
.L137:
	cmpq	%rdi, %rsi
	je	.L174
	movq	40(%rsi), %rax
	movq	32(%rsi), %rdx
	testq	%rax, %rax
	je	.L138
	movq	8+dfs_in(%rip), %r8
	cmpq	16+dfs_in(%rip), %r8
	movq	%rdx, 80(%rsp)
	movq	%rax, 88(%rsp)
	je	.L139
	testq	%r8, %r8
	je	.L140
	movaps	80(%rsp), %xmm0
	movups	%xmm0, (%r8)
.L140:
	addq	$16, %r8
	movq	%r8, 8+dfs_in(%rip)
	jmp	.L138
.L139:
	leaq	dfs_in(%rip), %rcx
	movq	%rbp, %rdx
	call	_ZNSt6vectorISt4pairIxxESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
.L138:
	movq	%rsi, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %rsi
	jmp	.L137
.L174:
	movl	$1, %edx
	xorl	%ecx, %ecx
	call	_Z7Fac_dfsxx
	movq	8+dfs_out(%rip), %rax
	movq	56(%rsp), %r12
	movq	48(%rsp), %rbp
	movq	64(%rsp), %r14
	movq	72(%rsp), %r15
	movq	dfs_out(%rip), %rsi
	movq	%rax, 32(%rsp)
	movq	%r12, %rax
	imulq	%rbp, %rax
	movq	%rax, 40(%rsp)
.L143:
	cmpq	32(%rsp), %rsi
	je	.L175
	movq	(%rsi), %rdi
	movq	%r14, %r8
	movq	%rbp, %rdx
	movq	%rdi, %rcx
	call	_Z5checkxxx
	cmpq	$-1, %rax
	movq	%rax, %r13
	je	.L144
	movq	40(%rsp), %rax
	movq	%r15, %r8
	cqto
	idivq	%rdi
	movq	%r12, %rdx
	movq	%rax, %rcx
	call	_Z5checkxxx
	cmpq	$-1, %rax
	movq	%rax, %rdi
	jne	.L176
.L144:
	addq	$8, %rsi
	jmp	.L143
.L175:
	leaq	.LC0(%rip), %rcx
	call	puts
.LEHE1:
.L169:
	movq	112(%rsp), %rdx
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	nop
	addq	$152, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L150:
	movq	112(%rsp), %rdx
	movq	%rax, %rsi
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIxSt4pairIKxxESt10_Select1stIS2_ESt4lessIxESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rsi, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L176:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movq	%r13, %rdx
.LEHB3:
	call	_ZNSo9_M_insertIxEERSoT_
	movl	$32, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movq	%rdi, %rdx
	movq	%rax, %rcx
	call	_ZNSo9_M_insertIxEERSoT_
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE3:
	jmp	.L169
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10116:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10116-.LLSDACSB10116
.LLSDACSB10116:
	.uleb128 .LEHB0-.LFB10116
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB10116
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L150-.LFB10116
	.uleb128 0
	.uleb128 .LEHB2-.LFB10116
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB10116
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L150-.LFB10116
	.uleb128 0
.LLSDACSE10116:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10123:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	40(%rsp), %rdx
	call	_ZNSirsERx
.L178:
	movq	40(%rsp), %rax
	leaq	-1(%rax), %rdx
	testq	%rax, %rax
	movq	%rdx, 40(%rsp)
	je	.L180
	call	_Z5solvev
	jmp	.L178
.L180:
	addq	$56, %rsp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_dfs_out;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_dfs_out
_GLOBAL__sub_I_dfs_out:
.LFB11500:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	__tcf_1(%rip), %rcx
	movq	$0, dfs_out(%rip)
	movq	$0, 8+dfs_out(%rip)
	movq	$0, 16+dfs_out(%rip)
	call	atexit
	leaq	__tcf_2(%rip), %rcx
	movq	$0, dfs_in(%rip)
	movq	$0, 8+dfs_in(%rip)
	movq	$0, 16+dfs_in(%rip)
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_dfs_out
	.globl	dfs_in
	.bss
	.align 16
dfs_in:
	.space 24
	.globl	dfs_out
	.align 16
dfs_out:
	.space 24
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZNSi10_M_extractIxEERSiRT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERx;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
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