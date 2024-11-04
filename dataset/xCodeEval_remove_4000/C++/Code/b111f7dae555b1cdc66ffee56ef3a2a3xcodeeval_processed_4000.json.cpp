__asm__( R"(
	.file	"\316\264\303\374\303\3731.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11308:
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
.LFB10774:
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
.LFB10792:
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
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB11065:
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
.L17:
	testq	%rax, %rax
	je	.L29
	movl	32(%rax), %ecx
	cmpl	%ecx, (%r8)
	jge	.L18
	movq	16(%rax), %r9
	movb	$1, %cl
	jmp	.L19
.L18:
	movq	24(%rax), %r9
	xorl	%ecx, %ecx
.L19:
	movq	%rax, %rsi
	movq	%r9, %rax
	jmp	.L17
.L29:
	testb	%cl, %cl
	movq	%rsi, %rax
	je	.L21
	cmpq	24(%rdx), %rsi
	je	.L28
	movq	%rsi, %rcx
	movq	%r8, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	40(%rsp), %r8
.L21:
	movl	(%r8), %edx
	cmpl	%edx, 32(%rax)
	jge	.L24
.L28:
	movq	$0, (%rbx)
	movq	%rsi, 8(%rbx)
	jmp	.L16
.L24:
	movq	%rax, (%rbx)
	movq	$0, 8(%rbx)
.L16:
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
.LFB10785:
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
	jne	.L31
	cmpq	$0, 40(%rsi)
	je	.L32
	movq	32(%rsi), %rax
	cmpl	%edi, 32(%rax)
	jl	.L33
	jmp	.L32
.L31:
	movl	32(%r13), %eax
	cmpl	%eax, %edi
	jge	.L34
	movq	24(%rsi), %rbx
	movq	%r8, 40(%rsp)
	cmpq	%rbx, %r13
	movq	%rbx, %rax
	je	.L37
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	%edi, 32(%rax)
	movq	40(%rsp), %r8
	jge	.L32
	xorl	%ebx, %ebx
	cmpq	$0, 24(%rax)
	je	.L37
	movq	%r13, %rax
	movq	%r13, %rbx
	jmp	.L37
.L34:
	cmpl	%edi, %eax
	jge	.L38
	movq	32(%rsi), %rax
	xorl	%ebx, %ebx
	movq	%r8, 40(%rsp)
	cmpq	%rax, %r13
	je	.L37
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %edi
	movq	%rax, %rbx
	movq	40(%rsp), %r8
	jge	.L32
	cmpq	$0, 24(%r13)
	jne	.L37
	movq	%r13, %rax
	xorl	%ebx, %ebx
.L37:
	testq	%rax, %rax
	je	.L38
.L43:
	testq	%rbx, %rbx
	jne	.L48
	cmpq	%r12, %rax
	je	.L48
	cmpl	32(%rax), %edi
	setl	%cl
	jmp	.L41
.L48:
	movb	$1, %cl
.L41:
	movq	%rax, %r8
	movzbl	%cl, %ecx
	movq	%r12, %r9
	movq	%rbp, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%rbp, %rax
	jmp	.L52
.L38:
	movq	%rbp, %rcx
	call	_ZdlPv
	movq	%rbx, %rax
	jmp	.L52
.L32:
	leaq	48(%rsp), %rcx
	movq	%rsi, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	48(%rsp), %rbx
	movq	56(%rsp), %rax
	jmp	.L37
.L33:
	xorl	%ebx, %ebx
	jmp	.L43
.L52:
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
.LFB10524:
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	16(%rcx), %r8
	leaq	8(%rcx), %r9
	movq	%r9, %rax
.L54:
	testq	%r8, %r8
	je	.L61
	movl	(%rdx), %r11d
	cmpl	%r11d, 32(%r8)
	jl	.L55
	movq	16(%r8), %r10
	jmp	.L56
.L55:
	movq	24(%r8), %r10
	movq	%rax, %r8
.L56:
	movq	%r8, %rax
	movq	%r10, %r8
	jmp	.L54
.L61:
	cmpq	%r9, %rax
	je	.L58
	movl	32(%rax), %r11d
	cmpl	%r11d, (%rdx)
	jge	.L59
.L58:
	movq	%rdx, 56(%rsp)
	leaq	55(%rsp), %rdx
	leaq	56(%rsp), %r9
	leaq	_ZStL19piecewise_construct(%rip), %r8
	movq	%rdx, 32(%rsp)
	movq	%rax, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L59:
	addq	$36, %rax
	addq	$72, %rsp
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
	subq	$136, %rsp
	.seh_stackalloc	136
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	64(%rsp), %rdx
	leaq	80(%rsp), %rsi
.LEHB0:
	call	_ZNSirsERi
	leaq	8(%rsi), %rax
	movq	%rax, 48(%rsp)
.L63:
	movl	64(%rsp), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, 64(%rsp)
	je	.L96
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	68(%rsp), %rdx
	leaq	88(%rsp), %rdi
	leaq	4+a(%rip), %rbx
	movl	$1, %ebp
	call	_ZNSirsERi
	leaq	72(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
.LEHE0:
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	$0, 120(%rsp)
	rep stosl
	leaq	8(%rsi), %rax
	xorl	%edi, %edi
	movq	%rax, 104(%rsp)
	movq	%rax, 112(%rsp)
.L64:
	movslq	68(%rsp), %rax
	cmpl	%eax, %ebp
	jg	.L97
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
	addl	%eax, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	incl	%ebp
	addq	$4, %rbx
	jmp	.L64
.L97:
	xorl	%edx, %edx
	cmpl	72(%rsp), %edi
	je	.L89
	leaq	a(%rip), %r12
	movl	(%r12,%rax,4), %ebx
	leaq	76(%rsp), %rax
	movq	%r12, %r14
	movq	%rax, 40(%rsp)
	decl	%ebx
.L68:
	movl	72(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movq	%rsi, %rcx
	movl	%edx, 76(%rsp)
	movq	40(%rsp), %rdx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	48(%rsp), %rax
	je	.L98
	decl	%ebx
	jmp	.L68
.L98:
	movl	72(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movslq	68(%rsp), %rax
	movq	%rax, %rbp
	movl	(%r12,%rax,4), %eax
	cmpl	%eax, %edx
	jl	.L70
	subl	%eax, %edx
.L89:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	jmp	.L67
.L70:
	decl	%ebp
	leaq	a(%rip), %r15
	xorl	%r13d, %r13d
	movslq	%ebp, %rax
	salq	$2, %rax
	movq	%rax, 56(%rsp)
.L72:
	movslq	%ebp, %rax
	movl	(%r14,%rax,4), %ecx
	leal	1(%rcx), %edx
	cmpl	72(%rsp), %edx
	movl	%edx, (%r14,%rax,4)
	jne	.L99
	movl	$0, (%r15,%rax,4)
	movq	56(%rsp), %rax
	movq	%rsi, %rcx
	addq	%r13, %rax
	addq	%r15, %rax
	movq	%rax, %rdx
	movq	%rax, 32(%rsp)
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %al
	movq	32(%rsp), %rdx
	movq	%rsi, %rcx
	xorl	$1, %eax
	movzbl	%al, %eax
	addl	%eax, %edi
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	decl	%ebp
	subq	$4, %r13
	jmp	.L72
.L99:
	leaq	a(%rip), %rdx
	movq	%rsi, %rcx
	leaq	(%rdx,%rax,4), %rbp
	movq	%rbp, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %dl
	movq	%rsi, %rcx
	xorl	$1, %edx
	movzbl	%dl, %edx
	addl	%edx, %edi
	movq	%rbp, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	cmpl	72(%rsp), %edi
	movb	$1, (%rax)
	jne	.L75
	movslq	68(%rsp), %rax
	subl	(%r12,%rax,4), %edi
	movl	%edi, %edx
	jmp	.L91
.L75:
	movl	72(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movq	%rsi, %rcx
	movl	%edx, 76(%rsp)
	movq	40(%rsp), %rdx
	call	_ZNKSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE4findERS1_
	cmpq	48(%rsp), %rax
	je	.L100
	decl	%ebx
	jmp	.L75
.L100:
	movl	72(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movslq	68(%rsp), %rax
	movl	(%r12,%rax,4), %r8d
	cmpl	%r8d, %edx
	jl	.L78
	subl	%r8d, %ecx
	movl	%ecx, %edx
.L91:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE1:
	movl	$0, a(%rip)
	jmp	.L67
.L78:
	addl	%ecx, %edx
	subl	%r8d, %edx
	jmp	.L91
.L67:
	movq	96(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	jmp	.L63
.L82:
	movq	96(%rsp), %rdx
	movq	%rax, %rbx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rbx, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L96:
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
	.uleb128 .L82-.LFB10114
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
.LFB11339:
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
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
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