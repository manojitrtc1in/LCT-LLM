__asm__(R"(
	.file	"CF1688C Manipulating History.cpp"
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
.LFB8664:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB8670:
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
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
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
	je	.L64
	cmpb	$0, 56(%r12)
	je	.L61
	movsbl	67(%r12), %edx
.L62:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L61:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L62
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L62
.L64:
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
	.section	.text$_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
	.def	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB8492:
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
	je	.L79
	movzbl	(%r8), %r9d
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L76:
	movq	%rax, %rbx
.L70:
	movzbl	32(%rbx), %ecx
	movq	24(%rbx), %rax
	cmpb	%cl, %r9b
	cmovl	16(%rbx), %rax
	setl	%r10b
	testq	%rax, %rax
	jne	.L76
	movq	%rbx, %r8
	testb	%r10b, %r10b
	jne	.L68
	cmpb	%r9b, %cl
	jl	.L80
.L74:
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
.L79:
	leaq	8(%rdx), %rbx
.L68:
	cmpq	%rbx, 24(%rdx)
	je	.L81
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movzbl	(%rsi), %r9d
	movq	%rbx, %r8
	movzbl	32(%rax), %ecx
	movq	%rax, %rbx
	cmpb	%r9b, %cl
	jge	.L74
.L80:
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
.L81:
	movq	%r12, %rax
	movq	$0, (%r12)
	movq	%rbx, 8(%r12)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "\12\0"
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
	subq	$184, %rsp
	.seh_stackalloc	184
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %r12
	xorl	%ebx, %ebx
	movq	%r12, %rcx
.LEHB0:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L83
	movl	$1, %esi
	.p2align 4,,10
	.p2align 3
.L85:
	cmpb	$45, %dl
	movq	%r12, %rcx
	cmove	%esi, %ebx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L85
.L83:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L86:
	leal	(%rsi,%rsi,4), %eax
	movq	%r12, %rcx
	leal	(%rdx,%rax,2), %edi
	call	_ZNSi3getEv
.LEHE0:
	leal	-48(%rdi), %esi
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L86
	movl	$48, %eax
	leaq	136(%rsp), %rbp
	movl	$0, 136(%rsp)
	subl	%edi, %eax
	testb	%bl, %bl
	leaq	96(%rsp), %rdi
	movq	$0, 144(%rsp)
	cmovne	%eax, %esi
	movq	%rdi, 48(%rsp)
	leaq	112(%rsp), %rdi
	movq	%rdi, 40(%rsp)
	leaq	128(%rsp), %rdi
	leal	1(%rsi,%rsi), %eax
	movq	%rbp, 152(%rsp)
	movq	%rbp, 160(%rsp)
	movq	$0, 168(%rsp)
	movl	%eax, 76(%rsp)
	movl	$0, 72(%rsp)
	movq	%rdi, 64(%rsp)
	testl	%eax, %eax
	jle	.L148
.L88:
	movq	40(%rsp), %rax
	movq	48(%rsp), %rdx
	movq	%r12, %rcx
	movq	$0, 104(%rsp)
	movb	$0, 112(%rsp)
	movq	%rax, 96(%rsp)
.LEHB1:
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	96(%rsp), %rcx
	movq	104(%rsp), %r13
	addq	%rcx, %r13
	cmpq	%rcx, %r13
	je	.L90
	movq	%rcx, %rdi
	leaq	80(%rsp), %r14
	.p2align 4,,10
	.p2align 3
.L106:
	movq	144(%rsp), %rax
	movzbl	(%rdi), %esi
	movq	%rbp, %rbx
	testq	%rax, %rax
	jne	.L93
	jmp	.L91
	.p2align 4,,10
	.p2align 3
.L151:
	movq	%rcx, %rax
	testq	%rax, %rax
	je	.L150
.L93:
	movq	16(%rax), %rdx
	movq	24(%rax), %rcx
	cmpb	32(%rax), %sil
	jg	.L151
	movq	%rax, %rbx
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L93
.L150:
	cmpq	%rbp, %rbx
	je	.L91
	cmpb	32(%rbx), %sil
	jge	.L94
.L91:
	movl	$40, %ecx
	call	_Znwy
.LEHE1:
	movb	%sil, 32(%rax)
	movq	%rax, %r15
	leaq	32(%rax), %r8
	movl	$0, 36(%rax)
	cmpq	%rbp, %rbx
	je	.L152
	cmpb	32(%rbx), %sil
	movq	%r8, 56(%rsp)
	jge	.L99
	cmpq	%rbx, 152(%rsp)
	je	.L149
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	56(%rsp), %r8
	cmpb	32(%rax), %sil
	jle	.L102
	cmpq	$0, 24(%rax)
	cmove	%rax, %rbx
	cmpq	$1, 24(%rax)
	sbbl	%eax, %eax
	addl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L116:
	cmpq	%rbp, %rbx
	je	.L128
	testb	%al, %al
	je	.L153
.L128:
	movl	$1, %ecx
.L104:
	movq	%rbx, %r8
	movq	%rbp, %r9
	movq	%r15, %rdx
	movq	%r15, %rbx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 168(%rsp)
.L94:
	addq	$1, %rdi
	addl	$1, 36(%rbx)
	cmpq	%rdi, %r13
	jne	.L106
	movq	96(%rsp), %rcx
.L90:
	cmpq	40(%rsp), %rcx
	je	.L107
	movq	112(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L107:
	addl	$1, 72(%rsp)
	movl	72(%rsp), %eax
	cmpl	76(%rsp), %eax
	jne	.L88
	movq	152(%rsp), %r12
	cmpq	%rbp, %r12
	je	.L148
	movq	.refptr._ZSt4cout(%rip), %r13
	jmp	.L110
	.p2align 4,,10
	.p2align 3
.L109:
	movq	%r12, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %r12
	cmpq	%rbp, %rax
	je	.L108
.L110:
	movzbl	32(%r12), %eax
	testb	$1, 36(%r12)
	je	.L109
	movq	48(%rsp), %rdx
	movl	$1, %r8d
	movq	%r13, %rcx
	movb	%al, 96(%rsp)
.LEHB2:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	%r12, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %r12
	cmpq	%rbp, %rax
	jne	.L110
.L108:
	movl	$1, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%r13, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE2:
	movq	144(%rsp), %rbx
	testq	%rbx, %rbx
	je	.L82
.L111:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L111
.L82:
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
.L99:
	jle	.L103
	cmpq	%rbx, 160(%rsp)
	je	.L125
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	56(%rsp), %r8
	cmpb	32(%rax), %sil
	jl	.L154
.L102:
	movq	64(%rsp), %rdx
	movq	%r14, %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	88(%rsp), %rbx
	movq	80(%rsp), %rdx
	movq	%rbx, %rax
.L98:
	testq	%rax, %rax
	je	.L127
	testq	%rdx, %rdx
	setne	%al
	jmp	.L116
.L127:
	movq	%rdx, %rbx
.L103:
	movl	$40, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	jmp	.L94
	.p2align 4,,10
	.p2align 3
.L152:
	cmpq	$0, 168(%rsp)
	je	.L96
	movq	160(%rsp), %rbx
	cmpb	32(%rbx), %sil
	jle	.L96
.L125:
	xorl	%eax, %eax
	jmp	.L116
	.p2align 4,,10
	.p2align 3
.L96:
	movq	64(%rsp), %rdx
	movq	%r14, %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE24_M_get_insert_unique_posERS1_
	movq	88(%rsp), %rax
	movq	80(%rsp), %rdx
	movq	%rax, %rbx
	jmp	.L98
.L154:
	cmpq	$0, 24(%rbx)
	je	.L125
	movq	%rax, %rbx
.L149:
	movl	$1, %eax
	jmp	.L116
.L153:
	xorl	%ecx, %ecx
	cmpb	32(%rbx), %sil
	setl	%cl
	jmp	.L104
.L148:
	movq	.refptr._ZSt4cout(%rip), %r13
	jmp	.L108
.L130:
	movq	%rax, %r12
.L115:
	movq	144(%rsp), %rcx
	call	_ZNSt8_Rb_treeIcSt4pairIKciESt10_Select1stIS2_ESt4lessIcESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%r12, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L129:
	movq	96(%rsp), %rcx
	movq	%rax, %r12
	cmpq	40(%rsp), %rcx
	je	.L115
	movq	112(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
	jmp	.L115
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
	.uleb128 .L129-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L130-.LFB7654
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
.LC1:
	.ascii "w\0"
.LC2:
	.ascii "testdata.log\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB7687:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movl	$2, %ecx
	call	*__imp___acrt_iob_func(%rip)
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
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
	jmp	.L162
	.p2align 4,,10
	.p2align 3
.L163:
	call	_Z8solutionv
.L162:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L163
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB8665:
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
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
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
