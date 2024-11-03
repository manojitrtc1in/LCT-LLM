__asm__( R"(
	.file	"\316\264\303\374\303\3731.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11345:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E:
.LFB10776:
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
.L3:
	testq	%rbx, %rbx
	je	.L6
	movq	24(%rbx), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	16(%rbx), %rdi
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rdi, %rbx
	jmp	.L3
.L6:
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
.LFB10794:
	.seh_endprologue
	leaq	8(%rcx), %r8
	movq	16(%rcx), %rcx
	movq	%r8, %rax
.L8:
	testq	%rcx, %rcx
	je	.L15
	movl	(%rdx), %r10d
	cmpl	%r10d, 32(%rcx)
	jl	.L9
	movq	16(%rcx), %r9
	jmp	.L10
.L9:
	movq	24(%rcx), %r9
	movq	%rax, %rcx
.L10:
	movq	%rcx, %rax
	movq	%r9, %rcx
	jmp	.L8
.L15:
	cmpq	%r8, %rax
	je	.L12
	movl	32(%rax), %ecx
	cmpl	%ecx, (%rdx)
	jge	.L14
.L12:
	movq	%r8, %rax
.L14:
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E:
.LFB10984:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movb	$1, %r10b
	testq	%rdx, %rdx
	movq	%r9, %rbx
	movq	%rcx, %rsi
	leaq	8(%rcx), %r9
	jne	.L17
	cmpq	%r9, %r8
	je	.L17
	movl	32(%r8), %eax
	cmpl	%eax, 32(%rbx)
	setl	%r10b
.L17:
	movzbl	%r10b, %ecx
	movq	%rbx, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%rbx, %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB11092:
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
.L21:
	testq	%rax, %rax
	je	.L33
	movl	32(%rax), %ecx
	cmpl	%ecx, (%r8)
	jge	.L22
	movq	16(%rax), %r9
	movb	$1, %cl
	jmp	.L23
.L22:
	movq	24(%rax), %r9
	xorl	%ecx, %ecx
.L23:
	movq	%rax, %rsi
	movq	%r9, %rax
	jmp	.L21
.L33:
	testb	%cl, %cl
	movq	%rsi, %rax
	je	.L25
	cmpq	24(%rdx), %rsi
	je	.L32
	movq	%rsi, %rcx
	movq	%r8, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	40(%rsp), %r8
.L25:
	movl	(%r8), %edx
	cmpl	%edx, 32(%rax)
	jge	.L28
.L32:
	movq	$0, (%rbx)
	movq	%rsi, 8(%rbx)
	jmp	.L20
.L28:
	movq	%rax, (%rbx)
	movq	$0, 8(%rbx)
.L20:
	movq	%rbx, %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_:
.LFB10972:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	8(%rdx), %rax
	movq	%r8, %rsi
	movq	%rcx, %rbx
	movq	%r9, %r8
	cmpq	%rax, %rsi
	jne	.L35
	cmpq	$0, 40(%rdx)
	je	.L36
	movq	32(%rdx), %rax
	movl	(%r9), %edi
	cmpl	%edi, 32(%rax)
	jl	.L37
	jmp	.L36
.L35:
	movl	(%r9), %edi
	movl	32(%rsi), %eax
	cmpl	%eax, %edi
	jge	.L38
	cmpq	24(%rdx), %rsi
	je	.L42
	movq	%rsi, %rcx
	movq	%rdx, 32(%rsp)
	movq	%r9, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	%edi, 32(%rax)
	movq	32(%rsp), %rdx
	movq	40(%rsp), %r8
	jge	.L36
	cmpq	$0, 24(%rax)
	je	.L37
.L42:
	movq	%rsi, (%rbx)
	jmp	.L50
.L38:
	cmpl	%edi, %eax
	jge	.L44
	cmpq	32(%rdx), %rsi
	je	.L51
	movq	%rsi, %rcx
	movq	%rdx, 32(%rsp)
	movq	%r9, 40(%rsp)
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %edi
	movq	32(%rsp), %rdx
	movq	40(%rsp), %r8
	jge	.L36
	cmpq	$0, 24(%rsi)
	jne	.L48
.L51:
	movq	$0, (%rbx)
.L50:
	movq	%rsi, 8(%rbx)
	jmp	.L34
.L48:
	movq	%rax, (%rbx)
	jmp	.L49
.L44:
	movq	%rsi, (%rcx)
	movq	$0, 8(%rcx)
	jmp	.L34
.L37:
	movq	$0, (%rbx)
.L49:
	movq	%rax, 8(%rbx)
	jmp	.L34
.L36:
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
.L34:
	movq	%rbx, %rax
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi
	.def	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi
_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi:
.LFB10540:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	16(%rcx), %rax
	leaq	8(%rcx), %r9
	movq	%r9, %r8
.L53:
	testq	%rax, %rax
	je	.L64
	movl	(%rdx), %esi
	cmpl	%esi, 32(%rax)
	jl	.L54
	movq	16(%rax), %r10
	jmp	.L55
.L54:
	movq	24(%rax), %r10
	movq	%r8, %rax
.L55:
	movq	%rax, %r8
	movq	%r10, %rax
	jmp	.L53
.L64:
	cmpq	%r9, %r8
	movq	%r8, %rbx
	je	.L57
	movl	32(%r8), %eax
	cmpl	%eax, (%rdx)
	jge	.L58
.L57:
	movq	%rdx, %rbx
	movq	%rcx, %rsi
	movl	$40, %ecx
	movq	%r8, 40(%rsp)
	call	_Znwy
	movq	%rax, %rdi
	movl	(%rbx), %eax
	movq	40(%rsp), %r8
	leaq	48(%rsp), %rcx
	leaq	32(%rdi), %r9
	movb	$0, 36(%rdi)
	movq	%rsi, %rdx
	movl	%eax, 32(%rdi)
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	movq	56(%rsp), %r8
	movq	48(%rsp), %rbx
	testq	%r8, %r8
	je	.L65
	movq	%rbx, %rdx
	movq	%rdi, %r9
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rbx
	jmp	.L58
.L65:
	movq	%rdi, %rcx
	call	_ZdlPv
.L58:
	leaq	36(%rbx), %rax
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	.def	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_:
.LFB10524:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	16(%rcx), %rax
	leaq	8(%rcx), %r9
	movq	%r9, %r8
.L67:
	testq	%rax, %rax
	je	.L78
	movl	(%rdx), %esi
	cmpl	%esi, 32(%rax)
	jl	.L68
	movq	16(%rax), %r10
	jmp	.L69
.L68:
	movq	24(%rax), %r10
	movq	%r8, %rax
.L69:
	movq	%rax, %r8
	movq	%r10, %rax
	jmp	.L67
.L78:
	cmpq	%r9, %r8
	movq	%r8, %rbx
	je	.L71
	movl	32(%r8), %eax
	cmpl	%eax, (%rdx)
	jge	.L72
.L71:
	movq	%rdx, %rbx
	movq	%rcx, %rsi
	movl	$40, %ecx
	movq	%r8, 40(%rsp)
	call	_Znwy
	movq	%rax, %rdi
	movl	(%rbx), %eax
	movq	40(%rsp), %r8
	leaq	48(%rsp), %rcx
	leaq	32(%rdi), %r9
	movb	$0, 36(%rdi)
	movq	%rsi, %rdx
	movl	%eax, 32(%rdi)
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	movq	56(%rsp), %r8
	movq	48(%rsp), %rbx
	testq	%r8, %r8
	je	.L79
	movq	%rbx, %rdx
	movq	%rdi, %r9
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rbx
	jmp	.L72
.L79:
	movq	%rdi, %rcx
	call	_ZdlPv
.L72:
	leaq	36(%rbx), %rax
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10114:
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
	.seh_endprologue
	leaq	48(%rsp), %rsi
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	32(%rsp), %rdx
	leaq	8(%rsi), %rbp
.LEHB0:
	call	_ZNSirsERi
.L81:
	movl	32(%rsp), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, 32(%rsp)
	je	.L110
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	36(%rsp), %rdx
	leaq	56(%rsp), %rdi
	leaq	4+a(%rip), %rbx
	xorl	%r13d, %r13d
	call	_ZNSirsERi
	leaq	40(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
.LEHE0:
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	$0, 88(%rsp)
	rep stosl
	leaq	8(%rsi), %rax
	movl	$1, %edi
	movq	%rax, 72(%rsp)
	movq	%rax, 80(%rsp)
.L82:
	movslq	36(%rsp), %rax
	cmpl	%eax, %edi
	jg	.L111
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%rbx, %rdx
.LEHB1:
	call	_ZNSirsERi
	movq	%rbx, %rdx
	movq	%rsi, %rcx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %al
	movq	%rbx, %rdx
	movq	%rsi, %rcx
	xorl	$1, %eax
	movzbl	%al, %eax
	addl	%eax, %r13d
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	incl	%edi
	addq	$4, %rbx
	jmp	.L82
.L111:
	xorl	%edx, %edx
	cmpl	40(%rsp), %r13d
	je	.L105
	leaq	a(%rip), %r12
	leaq	44(%rsp), %r14
	movl	(%r12,%rax,4), %ebx
	movq	%r12, %rdi
	decl	%ebx
.L86:
	movl	40(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movq	%rsi, %rcx
	movl	%edx, 44(%rsp)
	movq	%r14, %rdx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	%rbp, %rax
	je	.L112
	decl	%ebx
	jmp	.L86
.L112:
	movl	40(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movslq	36(%rsp), %rax
	movq	%rax, %rcx
	movl	(%r12,%rax,4), %eax
	decl	%ecx
	cmpl	%eax, %edx
	jl	.L99
	subl	%eax, %edx
.L105:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	jmp	.L85
.L91:
	leal	-1(%rcx), %r15d
	movq	%r14, %rdx
	movq	%rsi, %rcx
	movl	$0, (%r8,%rax,4)
	movl	$0, 44(%rsp)
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi
	movb	(%rax), %al
	movq	%r14, %rdx
	movq	%rsi, %rcx
	movl	$0, 44(%rsp)
	xorl	$1, %eax
	movzbl	%al, %eax
	addl	%eax, %r13d
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixEOi
	movb	$1, (%rax)
	movl	%r15d, %ecx
.L99:
	movslq	%ecx, %rax
	leaq	a(%rip), %r8
	movl	(%rdi,%rax,4), %edx
	incl	%edx
	cmpl	40(%rsp), %edx
	movl	%edx, (%rdi,%rax,4)
	je	.L91
	leaq	(%r8,%rax,4), %r15
	movq	%rsi, %rcx
	movq	%r15, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %dil
	movq	%r15, %rdx
	movq	%rsi, %rcx
	xorl	$1, %edi
	movzbl	%dil, %edi
	addl	%r13d, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	cmpl	40(%rsp), %edi
	movb	$1, (%rax)
	jne	.L93
	movslq	36(%rsp), %rax
	subl	(%r12,%rax,4), %edi
	movl	%edi, %edx
	jmp	.L109
.L93:
	movl	40(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movq	%rsi, %rcx
	movl	%edx, 44(%rsp)
	movq	%r14, %rdx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	%rbp, %rax
	je	.L113
	decl	%ebx
	jmp	.L93
.L113:
	movl	40(%rsp), %ecx
	movl	%ebx, %eax
	xorl	%r8d, %r8d
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movslq	36(%rsp), %rax
	movl	(%r12,%rax,4), %r9d
	cmpl	%r9d, %edx
	setl	%r8b
	imull	%r8d, %edx
	addl	%ecx, %edx
	subl	%r9d, %edx
.L109:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE1:
	movl	$0, a(%rip)
.L85:
	movq	64(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	jmp	.L81
.L98:
	movq	64(%rsp), %rdx
	movq	%rax, %rbx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rbx, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L110:
	xorl	%eax, %eax
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
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10114:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10114-.LLSDACSB10114
.LLSDACSB10114:
	.uleb128 .LEHB0-.LFB10114
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB10114
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L98-.LFB10114
	.uleb128 0
	.uleb128 .LEHB2-.LFB10114
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE10114:
	.section	.text.startup,"x"
	.seh_endproc
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB11376:
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
	.globl	p
	.bss
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
	.space 4000000
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
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