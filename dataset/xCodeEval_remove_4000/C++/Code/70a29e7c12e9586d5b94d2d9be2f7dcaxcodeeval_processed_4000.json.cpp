__asm__(R"(
	.file	"bbb.cpp"
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB3161:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB3164:
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
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0:
.LFB3166:
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
	movq	%rcx, %rsi
	movl	$40, %ecx
	movq	%rdx, %r13
	movq	%r8, %rbx
	call	_Znwy
	leaq	8(%rsi), %r14
	movq	%r13, %rdi
	movq	%rax, %r12
	movq	(%rbx), %rax
	movl	$0, 36(%r12)
	movzbl	(%rax), %ebp
	movb	%bpl, 32(%r12)
	cmpq	%r13, %r14
	je	.L121
	movzbl	32(%r13), %ebx
	cmpb	%bl, %bpl
	jge	.L70
	movq	24(%rsi), %r13
	cmpq	%rdi, %r13
	je	.L96
	movq	%rdi, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpb	32(%rax), %bpl
	jg	.L122
	movq	16(%rsi), %rbx
	testq	%rbx, %rbx
	jne	.L77
	jmp	.L123
	.p2align 4,,10
	.p2align 3
.L103:
	movq	%rax, %rbx
.L77:
	movzbl	32(%rbx), %edx
	movq	24(%rbx), %rax
	cmpb	%dl, %bpl
	cmovl	16(%rbx), %rax
	setl	%cl
	testq	%rax, %rax
	jne	.L103
	movq	%rbx, %rdi
	testb	%cl, %cl
	jne	.L75
.L90:
	cmpb	%dl, %bpl
	jle	.L119
.L67:
	testq	%rdi, %rdi
	je	.L93
.L118:
	xorl	%r13d, %r13d
.L96:
	testq	%r13, %r13
	setne	%al
.L95:
	cmpq	%rdi, %r14
	je	.L109
	testb	%al, %al
	je	.L124
.L109:
	movl	$1, %ecx
.L86:
	movq	%r14, %r9
	movq	%rdi, %r8
	movq	%r12, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rsi)
	jmp	.L116
	.p2align 4,,10
	.p2align 3
.L70:
	jle	.L93
	cmpq	%r13, 32(%rsi)
	je	.L118
	movq	%r13, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpb	32(%rax), %bpl
	jge	.L83
	cmpq	$0, 24(%r13)
	je	.L85
	movq	%rax, %rdi
	movl	$1, %ecx
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L99:
	movq	%rax, %rbx
.L64:
	movzbl	32(%rbx), %edx
	movq	24(%rbx), %rax
	cmpb	%dl, %bpl
	cmovl	16(%rbx), %rax
	setl	%cl
	testq	%rax, %rax
	jne	.L99
	movq	%rbx, %rdi
	testb	%cl, %cl
	jne	.L62
.L65:
	cmpb	%bpl, %dl
	jl	.L67
.L119:
	movq	%rbx, %rdi
.L93:
	movq	%r12, %rcx
	movl	$40, %edx
	movq	%rdi, %r12
	call	_ZdlPvy
.L116:
	movq	%r12, %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
	.p2align 3
.L121:
	cmpq	$0, 40(%rsi)
	je	.L60
	movq	32(%rsi), %rdi
	cmpb	32(%rdi), %bpl
	jle	.L60
	xorl	%eax, %eax
	jmp	.L95
	.p2align 4,,10
	.p2align 3
.L60:
	movq	16(%rsi), %rbx
	testq	%rbx, %rbx
	jne	.L64
	movq	%r13, %rbx
.L62:
	cmpq	%rbx, 24(%rsi)
	je	.L117
	movq	%rbx, %rcx
	movq	%rbx, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movzbl	32(%rax), %edx
	movq	%rax, %rbx
	jmp	.L65
	.p2align 4,,10
	.p2align 3
.L122:
	cmpq	$0, 24(%rax)
	movq	%rdi, %r13
	jne	.L96
	movq	%rax, %rdi
	xorl	%eax, %eax
	jmp	.L95
	.p2align 4,,10
	.p2align 3
.L124:
	movzbl	32(%rdi), %ebx
.L85:
	xorl	%ecx, %ecx
	cmpb	%bl, %bpl
	setl	%cl
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L83:
	movq	16(%rsi), %rbx
	testq	%rbx, %rbx
	jne	.L89
	movq	%r14, %rbx
	jmp	.L87
	.p2align 4,,10
	.p2align 3
.L107:
	movq	%rax, %rbx
.L89:
	movzbl	32(%rbx), %edx
	movq	24(%rbx), %rax
	cmpb	%dl, %bpl
	cmovl	16(%rbx), %rax
	setl	%cl
	testq	%rax, %rax
	jne	.L107
	movq	%rbx, %rdi
	testb	%cl, %cl
	je	.L90
.L87:
	cmpq	%rbx, 24(%rsi)
	jne	.L91
.L117:
	movq	%rbx, %rdi
	jmp	.L67
.L123:
	movq	%r14, %rbx
.L75:
	movq	%r13, %rdi
	cmpq	%rbx, %r13
	je	.L67
.L91:
	movq	%rbx, %rcx
	movq	%rbx, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movzbl	32(%rax), %edx
	movq	%rax, %rbx
	jmp	.L90
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
	subq	$184, %rsp
	.seh_stackalloc	184
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rax
	xorl	%ecx, %ecx
	movq	.refptr._ZSt4cout(%rip), %r15
	leaq	88(%rsp), %r12
	movq	$0, 232(%rax)
	movq	$0, 224(%r15)
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	76(%rsp), %rdx
	call	_ZNSirsERi
.LEHE0:
	leaq	96(%rsp), %rax
	movl	$0, 44(%rsp)
	movq	%rax, 56(%rsp)
	leaq	112(%rsp), %rax
	movq	%rax, 48(%rsp)
	movl	76(%rsp), %eax
	testl	%eax, %eax
	jle	.L160
	.p2align 4,,10
	.p2align 3
.L126:
	movq	48(%rsp), %rax
	movq	56(%rsp), %rdx
	movq	$0, 104(%rsp)
	movq	.refptr._ZSt3cin(%rip), %rcx
	movb	$0, 112(%rsp)
	movq	%rax, 96(%rsp)
.LEHB1:
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.LEHE1:
	leaq	136(%rsp), %rsi
	movq	96(%rsp), %rax
	leaq	80(%rsp), %r8
	movl	$0, 136(%rsp)
	leaq	128(%rsp), %rbp
	movq	%rsi, %rdx
	movq	$0, 144(%rsp)
	movq	%rbp, %rcx
	movq	%rsi, 152(%rsp)
	movq	%rsi, 160(%rsp)
	movq	$0, 168(%rsp)
	movq	%rax, 80(%rsp)
.LEHB2:
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	96(%rsp), %r14
	addl	$1, 36(%rax)
	leaq	1(%r14), %r11
	movzbl	1(%r14), %r8d
	cmpb	(%r14), %r8b
	je	.L152
	movl	$1, %ebx
	.p2align 4,,10
	.p2align 3
.L134:
	movl	%ebx, %edi
	movl	%ebx, %r13d
	cmpq	%rbx, 104(%rsp)
	jbe	.L127
	movq	144(%rsp), %rax
	movq	%rsi, %r10
	testq	%rax, %rax
	je	.L128
	.p2align 4,,10
	.p2align 3
.L132:
	movq	16(%rax), %rdx
	movq	24(%rax), %rcx
	cmpb	32(%rax), %r8b
	jg	.L129
.L179:
	movq	%rax, %r10
	testq	%rdx, %rdx
	je	.L131
	movq	%rdx, %rax
	movq	16(%rax), %rdx
	movq	24(%rax), %rcx
	cmpb	32(%rax), %r8b
	jle	.L179
.L129:
	testq	%rcx, %rcx
	je	.L131
	movq	%rcx, %rax
	jmp	.L132
	.p2align 4,,10
	.p2align 3
.L131:
	cmpq	%rsi, %r10
	je	.L128
	cmpb	32(%r10), %r8b
	jge	.L133
.L128:
	movq	%r12, %r8
	movq	%r10, %rdx
	movq	%rbp, %rcx
	movq	%r11, 88(%rsp)
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_.isra.0
	movq	96(%rsp), %r14
	movq	%rax, %r10
.L133:
	addq	$1, %rbx
	addl	$1, 36(%r10)
	leal	1(%rdi), %r13d
	leaq	(%r14,%rbx), %r11
	movzbl	(%r11), %r8d
	cmpb	(%r14), %r8b
	jne	.L134
.L127:
	movq	152(%rsp), %rcx
	cmpq	%rsi, %rcx
	je	.L135
	movl	$-1, %ebx
	.p2align 4,,10
	.p2align 3
.L136:
	movl	36(%rcx), %eax
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %rcx
	cmpq	%rsi, %rax
	jne	.L136
	cmpl	$1, %ebx
	jle	.L135
.L178:
	movl	$2, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%r15, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.L175:
	movl	$1, %r8d
	leaq	.LC1(%rip), %rdx
	movq	%r15, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	144(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L145
.L142:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L142
.L145:
	movq	96(%rsp), %rcx
	cmpq	48(%rsp), %rcx
	je	.L180
	movq	112(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
	addl	$1, 44(%rsp)
	movl	44(%rsp), %eax
	cmpl	%eax, 76(%rsp)
	jg	.L126
.L160:
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
.L180:
	addl	$1, 44(%rsp)
	movl	44(%rsp), %eax
	cmpl	%eax, 76(%rsp)
	jg	.L126
	jmp	.L160
.L135:
	movq	104(%rsp), %rax
	movslq	%r13d, %rdx
	movq	%r14, %rcx
	subq	%rdx, %rcx
	cmpq	%rax, %rdx
	jnb	.L139
	.p2align 4,,10
	.p2align 3
.L138:
	movzbl	(%rcx,%rdx), %edi
	cmpb	%dil, (%r14,%rdx)
	jne	.L178
	addq	$1, %rdx
	cmpq	%rdx, %rax
	ja	.L138
.L139:
	movl	$3, %r8d
	leaq	.LC2(%rip), %rdx
	movq	%r15, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE2:
	jmp	.L175
.L152:
	movl	$1, %r13d
	jmp	.L127
.L158:
	movq	144(%rsp), %rcx
	movq	%rax, %r12
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
.L149:
	movq	96(%rsp), %rcx
	cmpq	48(%rsp), %rcx
	je	.L150
	movq	112(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L150:
	movq	%r12, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L157:
	movq	%rax, %r12
	jmp	.L149
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
	.uleb128 .L157-.LFB2499
	.uleb128 0
	.uleb128 .LEHB2-.LFB2499
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L158-.LFB2499
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
.LFB3162:
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
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
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