__asm__(R"(
	.file	"bbb.cpp"
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB3160:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB3163:
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
	je	.L3
.L21:
	movq	112(%rsp), %rax
	movq	24(%rax), %rsi
	testq	%rsi, %rsi
	je	.L5
.L20:
	movq	24(%rsi), %rdi
	testq	%rdi, %rdi
	je	.L6
.L19:
	movq	24(%rdi), %rbp
	testq	%rbp, %rbp
	je	.L7
.L18:
	movq	24(%rbp), %r12
	testq	%r12, %r12
	je	.L8
.L17:
	movq	24(%r12), %r13
	testq	%r13, %r13
	je	.L9
.L16:
	movq	24(%r13), %r15
	testq	%r15, %r15
	je	.L10
.L15:
	movq	24(%r15), %r14
	testq	%r14, %r14
	je	.L11
.L14:
	movq	24(%r14), %rbx
	testq	%rbx, %rbx
	je	.L12
.L13:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L13
.L12:
	movq	16(%r14), %rbx
	movl	$40, %edx
	movq	%r14, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L11
	movq	%rbx, %r14
	jmp	.L14
.L9:
	movq	16(%r12), %r13
	movl	$40, %edx
	movq	%r12, %rcx
	call	_ZdlPvy
	testq	%r13, %r13
	je	.L8
	movq	%r13, %r12
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L10:
	movq	16(%r13), %r14
	movl	$40, %edx
	movq	%r13, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L9
	movq	%r14, %r13
	jmp	.L16
.L8:
	movq	16(%rbp), %r12
	movl	$40, %edx
	movq	%rbp, %rcx
	call	_ZdlPvy
	testq	%r12, %r12
	je	.L7
	movq	%r12, %rbp
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L11:
	movq	16(%r15), %r14
	movl	$40, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L10
	movq	%r14, %r15
	jmp	.L15
.L7:
	movq	16(%rdi), %rbp
	movl	$40, %edx
	movq	%rdi, %rcx
	call	_ZdlPvy
	testq	%rbp, %rbp
	je	.L6
	movq	%rbp, %rdi
	jmp	.L19
.L6:
	movq	16(%rsi), %rdi
	movl	$40, %edx
	movq	%rsi, %rcx
	call	_ZdlPvy
	testq	%rdi, %rdi
	je	.L5
	movq	%rdi, %rsi
	jmp	.L20
.L5:
	movq	112(%rsp), %rax
	movl	$40, %edx
	movq	16(%rax), %rsi
	movq	%rax, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L3
	movq	%rsi, 112(%rsp)
	jmp	.L21
.L3:
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
	.section	.text$_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB3041:
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
	je	.L71
	movzbl	(%r8), %r9d
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L68:
	movq	%rax, %rbx
.L62:
	movzbl	32(%rbx), %ecx
	movq	24(%rbx), %rax
	cmpb	%cl, %r9b
	cmovl	16(%rbx), %rax
	setl	%r10b
	testq	%rax, %rax
	jne	.L68
	movq	%rbx, %r8
	testb	%r10b, %r10b
	jne	.L60
	cmpb	%r9b, %cl
	jl	.L72
.L66:
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
.L71:
	leaq	8(%rdx), %rbx
.L60:
	cmpq	%rbx, 24(%rdx)
	je	.L73
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movzbl	(%rsi), %r9d
	movq	%rbx, %r8
	movzbl	32(%rax), %ecx
	movq	%rax, %rbx
	cmpb	%r9b, %cl
	jge	.L66
.L72:
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
.L73:
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
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0:
.LFB3165:
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
	movzbl	(%rax), %ebp
	movb	%bpl, 32(%r12)
	cmpq	%r13, %rsi
	je	.L98
	movzbl	32(%rsi), %r14d
	cmpb	%r14b, %bpl
	jge	.L79
	movq	24(%rbx), %rax
	cmpq	%rax, %rsi
	je	.L90
	movq	%rsi, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rax, %r8
	cmpb	32(%rax), %bpl
	jg	.L99
.L84:
	movq	%r15, %r8
	leaq	32(%rsp), %rcx
	movq	%rbx, %rdx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	40(%rsp), %rax
	movq	32(%rsp), %rdi
	movq	%rax, %r8
	testq	%rax, %rax
	je	.L83
.L82:
	testq	%rdi, %rdi
	setne	%al
.L88:
	cmpq	%r8, %r13
	je	.L93
	testb	%al, %al
	je	.L100
.L93:
	movl	$1, %ecx
.L86:
	movq	%r13, %r9
	movq	%r12, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rbx)
	jmp	.L97
	.p2align 4,,10
	.p2align 3
.L79:
	jle	.L83
	movq	32(%rbx), %r8
	cmpq	%r8, %rsi
	je	.L91
	movq	%rsi, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %r8
	cmpb	32(%rax), %bpl
	jge	.L84
	cmpq	$0, 24(%rsi)
	jne	.L93
	movq	%rsi, %r8
	jmp	.L85
	.p2align 4,,10
	.p2align 3
.L83:
	movq	%r12, %rcx
	movl	$40, %edx
	movq	%rdi, %r12
	call	_ZdlPvy
.L97:
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
.L98:
	cmpq	$0, 40(%rbx)
	je	.L84
	movq	32(%rbx), %r8
	cmpb	32(%r8), %bpl
	jle	.L84
.L77:
	xorl	%eax, %eax
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L99:
	cmpq	$0, 24(%rax)
	je	.L77
	movq	%rsi, %r8
	jmp	.L82
	.p2align 4,,10
	.p2align 3
.L100:
	movzbl	32(%r8), %r14d
.L85:
	xorl	%ecx, %ecx
	cmpb	%r14b, %bpl
	setl	%cl
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L90:
	movq	%rax, %r8
.L80:
	movq	%rax, %rdi
	jmp	.L82
	.p2align 4,,10
	.p2align 3
.L91:
	xorl	%eax, %eax
	jmp	.L80
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "NO\0"
.LC1:
	.ascii "\12\0"
.LC2:
	.ascii "YES\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2499:
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
	subq	$168, %rsp
	.seh_stackalloc	168
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	60(%rsp), %rdx
.LEHB0:
	call	_ZNSirsERi
.LEHE0:
	movl	60(%rsp), %eax
	testl	%eax, %eax
	jle	.L129
	leaq	80(%rsp), %rax
	xorl	%r13d, %r13d
	leaq	72(%rsp), %r12
	movq	%rax, 40(%rsp)
	leaq	96(%rsp), %rax
	movq	%rax, 32(%rsp)
	.p2align 4,,10
	.p2align 3
.L119:
	movq	32(%rsp), %rax
	movq	40(%rsp), %rdx
	movq	$0, 88(%rsp)
	movq	.refptr._ZSt3cin(%rip), %rcx
	movb	$0, 96(%rsp)
	movq	%rax, 80(%rsp)
.LEHB1:
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.LEHE1:
	leaq	120(%rsp), %rsi
	movq	80(%rsp), %rax
	leaq	112(%rsp), %rbp
	movl	$0, 120(%rsp)
	leaq	64(%rsp), %r8
	movq	%rsi, %rdx
	movq	%rbp, %rcx
	movq	$0, 128(%rsp)
	movq	%rsi, 136(%rsp)
	movq	%rsi, 144(%rsp)
	movq	$0, 152(%rsp)
	movq	%rax, 64(%rsp)
.LEHB2:
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	80(%rsp), %r15
	addl	$1, 36(%rax)
	leaq	1(%r15), %r11
	movzbl	1(%r15), %r8d
	cmpb	%r8b, (%r15)
	je	.L122
	movl	$1, %ebx
	.p2align 4,,10
	.p2align 3
.L108:
	movl	%ebx, %edi
	movl	%ebx, %r14d
	cmpq	%rbx, 88(%rsp)
	jbe	.L103
	movq	128(%rsp), %rax
	movq	%rsi, %r10
	testq	%rax, %rax
	jne	.L106
	jmp	.L104
	.p2align 4,,10
	.p2align 3
.L143:
	movq	%rcx, %rax
	testq	%rax, %rax
	je	.L142
.L106:
	movq	16(%rax), %rdx
	movq	24(%rax), %rcx
	cmpb	32(%rax), %r8b
	jg	.L143
	movq	%rax, %r10
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L106
.L142:
	cmpq	%rsi, %r10
	je	.L104
	cmpb	32(%r10), %r8b
	jge	.L107
.L104:
	movq	%r12, %r8
	movq	%r10, %rdx
	movq	%rbp, %rcx
	movq	%r11, 72(%rsp)
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	80(%rsp), %r15
	movq	%rax, %r10
.L107:
	addq	$1, %rbx
	addl	$1, 36(%r10)
	leal	1(%rdi), %r14d
	leaq	(%r15,%rbx), %r11
	movzbl	(%r11), %r8d
	cmpb	(%r15), %r8b
	jne	.L108
.L103:
	movq	136(%rsp), %rcx
	cmpq	%rsi, %rcx
	je	.L109
	movl	$-1, %ebx
	.p2align 4,,10
	.p2align 3
.L110:
	movl	36(%rcx), %eax
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %rcx
	cmpq	%rsi, %rax
	jne	.L110
	cmpl	$1, %ebx
	jle	.L109
	movq	.refptr._ZSt4cout(%rip), %rbx
	movl	$2, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	$1, %r8d
	leaq	.LC1(%rip), %rdx
	movq	%rbx, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.L117:
	movq	128(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L115
.L114:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L114
.L115:
	movq	80(%rsp), %rcx
	cmpq	32(%rsp), %rcx
	je	.L118
	movq	96(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L118:
	addl	$1, %r13d
	cmpl	%r13d, 60(%rsp)
	jg	.L119
.L129:
	xorl	%eax, %eax
	addq	$168, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L109:
	movq	88(%rsp), %rax
	movslq	%r14d, %rdx
	movq	%r15, %rcx
	subq	%rdx, %rcx
	cmpq	%rax, %rdx
	jb	.L112
	jmp	.L113
	.p2align 4,,10
	.p2align 3
.L116:
	addq	$1, %rdx
	cmpq	%rdx, %rax
	jbe	.L113
.L112:
	movzbl	(%rcx,%rdx), %edi
	cmpb	%dil, (%r15,%rdx)
	je	.L116
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC0(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L141:
	movq	%rax, %rcx
	leaq	.LC1(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L117
.L113:
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC2(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.LEHE2:
	jmp	.L141
.L122:
	movl	$1, %r14d
	jmp	.L103
.L128:
	movq	128(%rsp), %rcx
	movq	%rax, %r12
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
.L121:
	movq	40(%rsp), %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r12, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L127:
	movq	%rax, %r12
	jmp	.L121
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2499:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2499-.LLSDACSB2499
.LLSDACSB2499:
	.uleb128 .LEHB0-.LFB2499
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2499
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L127-.LFB2499
	.uleb128 0
	.uleb128 .LEHB2-.LFB2499
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L128-.LFB2499
	.uleb128 0
	.uleb128 .LEHB3-.LFB2499
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE2499:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB3161:
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
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv;	.scl	2;	.type	32;	.endef
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