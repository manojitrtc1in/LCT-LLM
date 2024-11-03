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
.L4:
	testq	%rbx, %rbx
	je	.L7
	movq	24(%rbx), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	16(%rbx), %rdi
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rdi, %rbx
	jmp	.L4
.L7:
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
.L9:
	testq	%rcx, %rcx
	je	.L16
	movl	(%rdx), %r10d
	cmpl	%r10d, 32(%rcx)
	jl	.L10
	movq	16(%rcx), %r9
	jmp	.L11
.L10:
	movq	24(%rcx), %r9
	movq	%rax, %rcx
.L11:
	movq	%rcx, %rax
	movq	%r9, %rcx
	jmp	.L9
.L16:
	cmpq	%r8, %rax
	je	.L13
	movl	32(%rax), %ecx
	cmpl	%ecx, (%rdx)
	jge	.L15
.L13:
	movq	%r8, %rax
.L15:
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
.L18:
	testq	%rax, %rax
	je	.L30
	movl	32(%rax), %ecx
	cmpl	%ecx, (%r8)
	jge	.L19
	movq	16(%rax), %r9
	movb	$1, %cl
	jmp	.L20
.L19:
	movq	24(%rax), %r9
	xorl	%ecx, %ecx
.L20:
	movq	%rax, %rsi
	movq	%r9, %rax
	jmp	.L18
.L30:
	testb	%cl, %cl
	movq	%rsi, %rax
	je	.L22
	cmpq	24(%rdx), %rsi
	je	.L29
	movq	%rsi, %rcx
	movq	%r8, 40(%rsp)
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	40(%rsp), %r8
.L22:
	movl	(%r8), %edx
	cmpl	%edx, 32(%rax)
	jge	.L25
.L29:
	movq	$0, (%rbx)
	movq	%rsi, 8(%rbx)
	jmp	.L17
.L25:
	movq	%rax, (%rbx)
	movq	$0, 8(%rbx)
.L17:
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
	jne	.L32
	cmpq	$0, 40(%rsi)
	je	.L33
	movq	32(%rsi), %rax
	cmpl	%edi, 32(%rax)
	jl	.L34
	jmp	.L33
.L32:
	movl	32(%r13), %eax
	cmpl	%eax, %edi
	jge	.L35
	movq	24(%rsi), %rbx
	movq	%r8, 40(%rsp)
	cmpq	%rbx, %r13
	movq	%rbx, %rax
	je	.L38
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	%edi, 32(%rax)
	movq	40(%rsp), %r8
	jge	.L33
	xorl	%ebx, %ebx
	cmpq	$0, 24(%rax)
	je	.L38
	movq	%r13, %rax
	movq	%r13, %rbx
	jmp	.L38
.L35:
	cmpl	%edi, %eax
	jge	.L39
	movq	32(%rsi), %rax
	xorl	%ebx, %ebx
	movq	%r8, 40(%rsp)
	cmpq	%rax, %r13
	je	.L38
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %edi
	movq	%rax, %rbx
	movq	40(%rsp), %r8
	jge	.L33
	cmpq	$0, 24(%r13)
	jne	.L38
	movq	%r13, %rax
	xorl	%ebx, %ebx
.L38:
	testq	%rax, %rax
	je	.L39
.L44:
	testq	%rbx, %rbx
	jne	.L49
	cmpq	%r12, %rax
	je	.L49
	cmpl	32(%rax), %edi
	setl	%cl
	jmp	.L42
.L49:
	movb	$1, %cl
.L42:
	movq	%rax, %r8
	movzbl	%cl, %ecx
	movq	%r12, %r9
	movq	%rbp, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%rbp, %rax
	jmp	.L53
.L39:
	movq	%rbp, %rcx
	call	_ZdlPv
	movq	%rbx, %rax
	jmp	.L53
.L33:
	leaq	48(%rsp), %rcx
	movq	%rsi, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	48(%rsp), %rbx
	movq	56(%rsp), %rax
	jmp	.L38
.L34:
	xorl	%ebx, %ebx
	jmp	.L44
.L53:
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
.L55:
	testq	%r8, %r8
	je	.L62
	movl	(%rdx), %r11d
	cmpl	%r11d, 32(%r8)
	jl	.L56
	movq	16(%r8), %r10
	jmp	.L57
.L56:
	movq	24(%r8), %r10
	movq	%rax, %r8
.L57:
	movq	%r8, %rax
	movq	%r10, %r8
	jmp	.L55
.L62:
	cmpq	%r9, %rax
	je	.L59
	movl	32(%rax), %r11d
	cmpl	%r11d, (%rdx)
	jge	.L60
.L59:
	movq	%rdx, 56(%rsp)
	leaq	55(%rsp), %rdx
	leaq	56(%rsp), %r9
	leaq	_ZStL19piecewise_construct(%rip), %r8
	movq	%rdx, 32(%rsp)
	movq	%rax, %rdx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
.L60:
	addq	$36, %rax
	addq	$72, %rsp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%lld\12\0"
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
.L64:
	movl	64(%rsp), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, 64(%rsp)
	je	.L85
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	68(%rsp), %rdx
	leaq	88(%rsp), %rdi
	leaq	4+a(%rip), %rbx
	xorl	%ebp, %ebp
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
	movl	$1, %edi
	movq	%rax, 104(%rsp)
	movq	%rax, 112(%rsp)
.L65:
	movslq	68(%rsp), %rax
	cmpl	%eax, %edi
	jg	.L86
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
	addl	%eax, %ebp
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	incl	%edi
	addq	$4, %rbx
	jmp	.L65
.L86:
	cmpl	72(%rsp), %ebp
	jne	.L67
	movq	.refptr._ZSt4cout(%rip), %rcx
	xorl	%edx, %edx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	jmp	.L68
.L67:
	leaq	a(%rip), %r12
	movl	(%r12,%rax,4), %ebx
	leaq	76(%rsp), %rax
	movq	%r12, %r14
	movq	%rax, 40(%rsp)
	decl	%ebx
.L69:
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
	je	.L87
	decl	%ebx
	jmp	.L69
.L87:
	movl	72(%rsp), %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	leal	(%rdx,%rcx), %eax
	cltd
	idivl	%ecx
	movslq	68(%rsp), %rax
	movq	%rax, %rdi
	movl	(%r12,%rax,4), %eax
	cmpl	%eax, %edx
	jl	.L71
	leaq	.LC0(%rip), %rcx
	subl	%eax, %edx
	call	_Z6printfPKcz
	jmp	.L68
.L71:
	decl	%edi
	leaq	a(%rip), %r15
	xorl	%r13d, %r13d
	movslq	%edi, %rax
	salq	$2, %rax
	movq	%rax, 56(%rsp)
.L72:
	movslq	%edi, %rax
	movl	(%r14,%rax,4), %ecx
	leal	1(%rcx), %edx
	cmpl	72(%rsp), %edx
	movl	%edx, (%r14,%rax,4)
	jne	.L88
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
	addl	%eax, %ebp
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	$1, (%rax)
	decl	%edi
	subq	$4, %r13
	jmp	.L72
.L88:
	leaq	a(%rip), %rdx
	movq	%rsi, %rcx
	leaq	(%rdx,%rax,4), %rdi
	movq	%rdi, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
	movb	(%rax), %dl
	movq	%rsi, %rcx
	xorl	$1, %edx
	movzbl	%dl, %edx
	addl	%edx, %ebp
	movq	%rdi, %rdx
	call	_ZNSt3mapIibSt4lessIiESaISt4pairIKibEEEixERS3_
.LEHE1:
	cmpl	72(%rsp), %ebp
	movb	$1, (%rax)
	jne	.L75
	movslq	68(%rsp), %rax
	movl	%ebp, %edx
	subl	(%r12,%rax,4), %edx
	jmp	.L84
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
	je	.L89
	decl	%ebx
	jmp	.L75
.L89:
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
	jmp	.L84
.L78:
	addl	%ecx, %edx
	subl	%r8d, %edx
.L84:
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	movl	$0, a(%rip)
.L68:
	movq	96(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	jmp	.L64
.L82:
	movq	96(%rsp), %rdx
	movq	%rax, %rbx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKibESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	%rbx, %rcx
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L85:
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
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
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