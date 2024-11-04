

__asm__(R"(
	.file	"tmp.cpp"
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB14355:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.align 2
	.p2align 4
	.def	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0:
.LFB14381:
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
	call	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$48, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L13
.L12:
	movq	16(%r14), %rbx
	movl	$48, %edx
	movq	%r14, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L11
	movq	%rbx, %r14
	jmp	.L14
.L9:
	movq	16(%r12), %r13
	movl	$48, %edx
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
	movl	$48, %edx
	movq	%r13, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L9
	movq	%r14, %r13
	jmp	.L16
.L8:
	movq	16(%rbp), %r12
	movl	$48, %edx
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
	movl	$48, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L10
	movq	%r14, %r15
	jmp	.L15
.L7:
	movq	16(%rdi), %rbp
	movl	$48, %edx
	movq	%rdi, %rcx
	call	_ZdlPvy
	testq	%rbp, %rbp
	je	.L6
	movq	%rbp, %rdi
	jmp	.L19
.L6:
	movq	16(%rsi), %rdi
	movl	$48, %edx
	movq	%rsi, %rcx
	call	_ZdlPvy
	testq	%rdi, %rdi
	je	.L5
	movq	%rdi, %rsi
	jmp	.L20
.L5:
	movq	112(%rsp), %rax
	movl	$48, %edx
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
	.def	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0:
.LFB14384:
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
	je	.L58
.L76:
	movq	112(%rsp), %rax
	movq	24(%rax), %rsi
	testq	%rsi, %rsi
	je	.L60
.L75:
	movq	24(%rsi), %rdi
	testq	%rdi, %rdi
	je	.L61
.L74:
	movq	24(%rdi), %rbp
	testq	%rbp, %rbp
	je	.L62
.L73:
	movq	24(%rbp), %r12
	testq	%r12, %r12
	je	.L63
.L72:
	movq	24(%r12), %r13
	testq	%r13, %r13
	je	.L64
.L71:
	movq	24(%r13), %r15
	testq	%r15, %r15
	je	.L65
.L70:
	movq	24(%r15), %r14
	testq	%r14, %r14
	je	.L66
.L69:
	movq	24(%r14), %rbx
	testq	%rbx, %rbx
	je	.L67
.L68:
	movq	24(%rbx), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
	movq	%rbx, %rcx
	movq	16(%rbx), %rbx
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rbx, %rbx
	jne	.L68
.L67:
	movq	16(%r14), %rbx
	movl	$40, %edx
	movq	%r14, %rcx
	call	_ZdlPvy
	testq	%rbx, %rbx
	je	.L66
	movq	%rbx, %r14
	jmp	.L69
.L64:
	movq	16(%r12), %r13
	movl	$40, %edx
	movq	%r12, %rcx
	call	_ZdlPvy
	testq	%r13, %r13
	je	.L63
	movq	%r13, %r12
	jmp	.L72
	.p2align 4,,10
	.p2align 3
.L65:
	movq	16(%r13), %r14
	movl	$40, %edx
	movq	%r13, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L64
	movq	%r14, %r13
	jmp	.L71
.L63:
	movq	16(%rbp), %r12
	movl	$40, %edx
	movq	%rbp, %rcx
	call	_ZdlPvy
	testq	%r12, %r12
	je	.L62
	movq	%r12, %rbp
	jmp	.L73
	.p2align 4,,10
	.p2align 3
.L66:
	movq	16(%r15), %r14
	movl	$40, %edx
	movq	%r15, %rcx
	call	_ZdlPvy
	testq	%r14, %r14
	je	.L65
	movq	%r14, %r15
	jmp	.L70
.L62:
	movq	16(%rdi), %rbp
	movl	$40, %edx
	movq	%rdi, %rcx
	call	_ZdlPvy
	testq	%rbp, %rbp
	je	.L61
	movq	%rbp, %rdi
	jmp	.L74
.L61:
	movq	16(%rsi), %rdi
	movl	$40, %edx
	movq	%rsi, %rcx
	call	_ZdlPvy
	testq	%rdi, %rdi
	je	.L60
	movq	%rdi, %rsi
	jmp	.L75
.L60:
	movq	112(%rsp), %rax
	movl	$40, %edx
	movq	16(%rax), %rsi
	movq	%rax, %rcx
	call	_ZdlPvy
	testq	%rsi, %rsi
	je	.L58
	movq	%rsi, 112(%rsp)
	jmp	.L76
.L58:
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
	.globl	_Z4readv
	.def	_Z4readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readv
_Z4readv:
.LFB11909:
	.seh_endprologue
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	.def	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev:
.LFB12840:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	8(%rcx), %rbx
	movq	(%rcx), %r12
	movq	%rcx, %rsi
	cmpq	%r12, %rbx
	je	.L115
	.p2align 4,,10
	.p2align 3
.L119:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L116
	movq	16(%r12), %rdx
	addq	$24, %r12
	subq	%rcx, %rdx
	call	_ZdlPvy
	cmpq	%r12, %rbx
	jne	.L119
.L118:
	movq	(%rsi), %r12
.L115:
	testq	%r12, %r12
	je	.L114
	movq	16(%rsi), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L116:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L119
	jmp	.L118
	.p2align 4,,10
	.p2align 3
.L114:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_
	.def	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_
_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_:
.LFB13394:
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
	movq	16(%rdx), %rbx
	movq	%rcx, %r12
	movq	%rdx, %rdi
	leaq	8(%rdx), %rbp
	movq	%r8, %rsi
	testq	%rbx, %rbx
	je	.L137
	movl	(%r8), %r10d
	jmp	.L123
	.p2align 4,,10
	.p2align 3
.L127:
	cmpl	%eax, %edx
	jge	.L124
	movq	16(%rbx), %rax
	movl	$1, %edx
	testq	%rax, %rax
	je	.L126
.L143:
	movq	%rax, %rbx
.L123:
	movl	32(%rbx), %ecx
	movl	%r10d, %edx
	movl	%ecx, %eax
	cmpl	%ecx, %r10d
	jne	.L127
	movl	4(%rsi), %edx
	movl	36(%rbx), %eax
	cmpl	%eax, %edx
	jne	.L127
	movl	8(%rsi), %edx
	movl	40(%rbx), %eax
	cmpl	%eax, %edx
	jne	.L127
	movl	12(%rsi), %edx
	movl	44(%rbx), %eax
	cmpl	%eax, %edx
	jne	.L127
.L124:
	movq	24(%rbx), %rax
	xorl	%edx, %edx
	testq	%rax, %rax
	jne	.L143
.L126:
	movq	%rbx, %r13
	testb	%dl, %dl
	jne	.L122
	cmpl	%ecx, %r10d
	je	.L144
.L131:
	cmpl	%r10d, %ecx
	jge	.L133
	testq	%r13, %r13
	je	.L145
.L130:
	movl	$1, %r14d
	cmpq	%r13, %rbp
	jne	.L146
.L134:
	movl	$48, %ecx
	call	_Znwy
	movdqu	(%rsi), %xmm0
	movq	%rbp, %r9
	movq	%r13, %r8
	movq	%rax, %rdx
	movl	%r14d, %ecx
	movq	%rax, %rbx
	movups	%xmm0, 32(%rax)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rdi)
	movq	%rbx, (%r12)
	movb	$1, 8(%r12)
.L121:
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
.L137:
	movq	%rbp, %rbx
.L122:
	movq	%rbx, %r13
	cmpq	%rbx, 24(%rdi)
	je	.L130
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	(%rsi), %r10d
	movl	32(%rax), %ecx
	movq	%rax, %rbx
	cmpl	%ecx, %r10d
	jne	.L131
.L144:
	movl	36(%rbx), %ecx
	movl	4(%rsi), %r10d
	cmpl	%r10d, %ecx
	jne	.L131
	movl	40(%rbx), %ecx
	movl	8(%rsi), %r10d
	cmpl	%r10d, %ecx
	jne	.L131
	movl	44(%rbx), %ecx
	movl	12(%rsi), %r10d
	cmpl	%r10d, %ecx
	jne	.L131
.L133:
	movq	%rbx, (%r12)
	movb	$0, 8(%r12)
	jmp	.L121
.L146:
	movl	(%rsi), %edx
	movl	32(%r13), %eax
	cmpl	%eax, %edx
	je	.L147
.L135:
	xorl	%r14d, %r14d
	cmpl	%eax, %edx
	setl	%r14b
	jmp	.L134
.L147:
	movl	4(%rsi), %edx
	movl	36(%r13), %eax
	cmpl	%eax, %edx
	jne	.L135
	movl	8(%rsi), %edx
	movl	40(%r13), %eax
	cmpl	%eax, %edx
	jne	.L135
	movl	12(%rsi), %edx
	movl	44(%r13), %eax
	xorl	%r14d, %r14d
	cmpl	%eax, %edx
	jne	.L135
	jmp	.L134
.L145:
	xorl	%ebx, %ebx
	jmp	.L133
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	.def	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_:
.LFB13674:
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
	je	.L164
	movl	(%r8), %r10d
	jmp	.L151
	.p2align 4,,10
	.p2align 3
.L155:
	cmpl	%eax, %r9d
	jge	.L152
	movq	16(%rbx), %rax
	movl	$1, %r8d
	testq	%rax, %rax
	je	.L154
.L165:
	movq	%rax, %rbx
.L151:
	movl	32(%rbx), %ecx
	movl	%r10d, %r9d
	movl	%ecx, %eax
	cmpl	%ecx, %r10d
	jne	.L155
	movl	4(%rsi), %r9d
	movl	36(%rbx), %eax
	cmpl	%eax, %r9d
	jne	.L155
.L152:
	movq	24(%rbx), %rax
	xorl	%r8d, %r8d
	testq	%rax, %rax
	jne	.L165
.L154:
	movq	%rbx, %r9
	testb	%r8b, %r8b
	jne	.L150
	cmpl	%ecx, %r10d
	je	.L166
.L159:
	cmpl	%r10d, %ecx
	jl	.L167
.L160:
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
.L164:
	leaq	8(%rdx), %rbx
.L150:
	cmpq	%rbx, 24(%rdx)
	je	.L168
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	(%rsi), %r10d
	movq	%rbx, %r9
	movl	32(%rax), %ecx
	movq	%rax, %rbx
	cmpl	%ecx, %r10d
	jne	.L159
.L166:
	movl	36(%rbx), %ecx
	movl	4(%rsi), %r10d
	cmpl	%r10d, %ecx
	je	.L160
	cmpl	%r10d, %ecx
	jge	.L160
.L167:
	movq	%r12, %rax
	movq	$0, (%r12)
	movq	%r9, 8(%r12)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.p2align 4,,10
	.p2align 3
.L168:
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
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
.LFB13708:
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
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	.seh_endprologue
	movq	8(%rcx), %rdi
	movq	(%rcx), %r13
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rdx, %r12
	sarq	$3, %rax
	movq	%rcx, %rsi
	movq	%r8, %rbp
	movabsq	$1152921504606846975, %rdx
	cmpq	%rdx, %rax
	je	.L183
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r14
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r14
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L181
	testq	%rax, %rax
	jne	.L174
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
.L180:
	movq	0(%rbp), %rax
	leaq	8(%rcx,%r14), %r15
	subq	%r12, %rdi
	movq	16(%rsi), %rbp
	movq	%rcx, %xmm6
	movq	%rax, (%rcx,%r14)
	leaq	(%r15,%rdi), %rax
	movq	%rax, %xmm0
	punpcklqdq	%xmm0, %xmm6
	testq	%r14, %r14
	jg	.L184
	testq	%rdi, %rdi
	jg	.L176
	testq	%r13, %r13
	jne	.L179
.L177:
	movups	%xmm6, (%rsi)
	movaps	32(%rsp), %xmm6
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
.L184:
	movq	%r14, %r8
	movq	%r13, %rdx
	call	memmove
	testq	%rdi, %rdi
	jg	.L176
.L179:
	movq	%rbp, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L177
	.p2align 4,,10
	.p2align 3
.L176:
	movq	%rdi, %r8
	movq	%r12, %rdx
	movq	%r15, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L177
	jmp	.L179
	.p2align 4,,10
	.p2align 3
.L181:
	movabsq	$9223372036854775800, %rbx
.L173:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rcx
	addq	%rax, %rbx
	jmp	.L180
	.p2align 4,,10
	.p2align 3
.L174:
	movabsq	$1152921504606846975, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,8), %rbx
	jmp	.L173
.L183:
	leaq	.LC0(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.section	.text$_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_,"x"
	.linkonce discard
	.p2align 4
	.globl	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_
	.def	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_
_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_:
.LFB14034:
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
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	.seh_endprologue
	movq	%rcx, %rbp
	movq	%rdx, %rsi
	movq	%r8, %rdi
	testq	%rdx, %rdx
	je	.L198
	movq	8(%r8), %rbx
	movq	(%r8), %r14
	movq	%rcx, %r12
	pxor	%xmm6, %xmm6
	movabsq	$9223372036854775804, %r13
	jmp	.L192
	.p2align 4,,10
	.p2align 3
.L210:
	cmpq	%r13, %rbx
	ja	.L209
	movq	%rbx, %rcx
.LEHB0:
	call	_Znwy
	movq	%rax, %rcx
.L187:
	movq	%rcx, %xmm0
	addq	%rcx, %rbx
	punpcklqdq	%xmm0, %xmm0
	movq	%rbx, 16(%r12)
	movups	%xmm0, (%r12)
	movq	8(%rdi), %rbx
	movq	(%rdi), %r14
	movq	%rbx, %r15
	subq	%r14, %r15
	cmpq	%r14, %rbx
	je	.L208
	movq	%r15, %r8
	movq	%r14, %rdx
	call	memmove
	movq	%rax, %rcx
.L208:
	addq	%r15, %rcx
	addq	$24, %r12
	movq	%rcx, -16(%r12)
	subq	$1, %rsi
	je	.L185
.L192:
	movq	$0, 16(%r12)
	movups	%xmm6, (%r12)
	subq	%r14, %rbx
	jne	.L210
	xorl	%ecx, %ecx
	jmp	.L187
	.p2align 4,,10
	.p2align 3
.L198:
	movq	%rcx, %r12
.L185:
	movaps	32(%rsp), %xmm6
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
.L209:
	testq	%rbx, %rbx
	jns	.L189
	call	_ZSt28__throw_bad_array_new_lengthv
	.p2align 4,,10
	.p2align 3
.L189:
	call	_ZSt17__throw_bad_allocv
.LEHE0:
.L200:
	movq	%rax, %rcx
	call	__cxa_begin_catch
.L194:
	cmpq	%rbp, %r12
	je	.L211
	movq	0(%rbp), %rcx
	movq	16(%rbp), %rdx
	subq	%rcx, %rdx
	testq	%rcx, %rcx
	je	.L195
	call	_ZdlPvy
.L195:
	addq	$24, %rbp
	jmp	.L194
.L211:
.LEHB1:
	call	__cxa_rethrow
.LEHE1:
.L201:
	movq	%rax, %r12
	call	__cxa_end_catch
	movq	%r12, %rcx
.LEHB2:
	call	_Unwind_Resume
	nop
.LEHE2:
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA14034:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT14034-.LLSDATTD14034
.LLSDATTD14034:
	.byte	0x1
	.uleb128 .LLSDACSE14034-.LLSDACSB14034
.LLSDACSB14034:
	.uleb128 .LEHB0-.LFB14034
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L200-.LFB14034
	.uleb128 0x1
	.uleb128 .LEHB1-.LFB14034
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L201-.LFB14034
	.uleb128 0
	.uleb128 .LEHB2-.LFB14034
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE14034:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT14034:
	.section	.text$_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_,"x"
	.linkonce discard
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "cannot create std::vector larger than max_size()\0"
.LC2:
	.ascii "0\12\0"
.LC3:
	.ascii "2\12\0"
.LC4:
	.ascii "1 \0"
.LC5:
	.ascii "\12\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB11911:
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
	subq	$488, %rsp
	.seh_stackalloc	488
	movaps	%xmm6, 448(%rsp)
	.seh_savexmm	%xmm6, 448
	movaps	%xmm7, 464(%rsp)
	.seh_savexmm	%xmm7, 464
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
.LEHB3:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rdi
	leaq	208(%rsp), %rdx
	movq	$0, 232(%rdi)
	movq	%rdi, %rcx
	call	_ZNSirsERi
	leaq	212(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movslq	212(%rsp), %rsi
	movq	%rsi, %rax
	shrq	$61, %rax
	jne	.L468
	pxor	%xmm0, %xmm0
	leaq	0(,%rsi,4), %rbp
	movq	$0, 416(%rsp)
	movaps	%xmm0, 400(%rsp)
	testq	%rsi, %rsi
	je	.L214
	movq	%rbp, %rcx
	call	_Znwy
.LEHE3:
	subq	$1, %rsi
	leaq	(%rax,%rbp), %rbx
	movq	%rax, 400(%rsp)
	leaq	4(%rax), %rcx
	movq	%rbx, 416(%rsp)
	movl	$0, (%rax)
	je	.L368
	cmpq	%rcx, %rbx
	je	.L215
	leaq	-4(%rbp), %r8
	xorl	%edx, %edx
	call	memset
.L215:
	movslq	208(%rsp), %r12
	movq	%rbx, 408(%rsp)
	movabsq	$384307168202282325, %rax
	cmpq	%rax, %r12
	ja	.L469
	pxor	%xmm0, %xmm0
	leaq	(%r12,%r12,2), %r13
	movq	$0, 256(%rsp)
	movaps	%xmm0, 240(%rsp)
	salq	$3, %r13
	testq	%r12, %r12
	je	.L369
	movq	%r13, %rcx
.LEHB4:
	call	_Znwy
.LEHE4:
	movq	%rax, %r14
.L217:
	leaq	(%r14,%r13), %rax
	movq	%r12, %rdx
	movq	%r14, %rcx
	movq	%r14, 240(%rsp)
	movq	%rax, 256(%rsp)
	leaq	400(%rsp), %rax
	movq	%rax, %r8
	movq	%rax, 112(%rsp)
.LEHB5:
	call	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEyS4_EET_S6_T0_RKT1_
.LEHE5:
	movq	400(%rsp), %rcx
	movq	%rax, 248(%rsp)
	testq	%rcx, %rcx
	je	.L219
	movq	416(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L219:
	movl	208(%rsp), %r9d
	testl	%r9d, %r9d
	jle	.L223
	movl	212(%rsp), %eax
	movq	%r14, 32(%rsp)
	xorl	%r15d, %r15d
	movl	$1, %ebp
	testl	%eax, %eax
	jle	.L470
	.p2align 4,,10
	.p2align 3
.L238:
	movq	32(%rsp), %rax
	xorl	%r12d, %r12d
	movq	(%rax), %rbx
	.p2align 4,,10
	.p2align 3
.L232:
	leaq	0(,%r12,4), %r13
	movq	%rdi, %rcx
	addq	%r13, %rbx
	movl	$0, (%rbx)
.LEHB6:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%esi, %esi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L228
	.p2align 4,,10
	.p2align 3
.L227:
	cmpb	$45, %dl
	movq	%rdi, %rcx
	cmove	%ebp, %esi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L227
	.p2align 4,,10
	.p2align 3
.L228:
	movl	(%rbx), %eax
	movq	%rdi, %rcx
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
	movl	%eax, (%rbx)
	call	_ZNSi3getEv
.LEHE6:
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L228
	testb	%sil, %sil
	je	.L229
	negl	(%rbx)
.L229:
	movq	32(%rsp), %rax
	addq	$1, %r12
	movq	(%rax), %rbx
	subl	$1, (%rbx,%r13)
	movl	212(%rsp), %eax
	cmpl	%r12d, %eax
	jg	.L232
	movl	208(%rsp), %r9d
	addl	$1, %r15d
	cmpl	%r9d, %r15d
	jge	.L234
	addq	$24, 32(%rsp)
	testl	%eax, %eax
	jg	.L238
.L470:
	addl	$1, %r15d
	cmpl	%r9d, %r15d
	jge	.L234
	movq	$0, 288(%rsp)
	pxor	%xmm0, %xmm0
	movaps	%xmm0, 272(%rsp)
.L236:
	leaq	272(%rsp), %rsi
	movq	%r14, %rbp
	xorl	%r12d, %r12d
	xorl	%edi, %edi
	movq	$0, 104(%rsp)
	movq	%rsi, 32(%rsp)
	testl	%eax, %eax
	jle	.L367
	.p2align 4,,10
	.p2align 3
.L251:
	leal	1(%rdi), %r15d
	movl	$1, %esi
	xorl	%ebx, %ebx
	movslq	%r15d, %rdx
	leaq	(%rdx,%rdx,2), %rdx
	leaq	(%r14,%rdx,8), %r13
	.p2align 4,,10
	.p2align 3
.L249:
	movq	0(%rbp), %rcx
	movd	%edi, %xmm0
	movd	%ebx, %xmm2
	leaq	0(,%rbx,4), %r8
	punpckldq	%xmm2, %xmm0
	movl	(%rcx,%rbx,4), %edx
	testl	%edx, %edx
	je	.L248
	testl	%edi, %edi
	je	.L243
	movq	-24(%rbp), %r10
	cmpl	(%r10,%r8), %edx
	jg	.L248
.L243:
	leal	-1(%r9), %r10d
	cmpl	%r10d, %edi
	jge	.L244
	movq	0(%r13), %r10
	cmpl	(%r10,%r8), %edx
	jg	.L248
.L244:
	movl	%ebx, %r10d
	testq	%rbx, %rbx
	je	.L245
	cmpl	-4(%rcx,%r8), %edx
	jg	.L248
.L245:
	leal	-1(%rax), %r8d
	cmpl	%r10d, %r8d
	jle	.L246
	movslq	%esi, %r10
	movl	%esi, %r8d
	cmpl	(%rcx,%r10,4), %edx
	jg	.L242
.L246:
	movq	%xmm0, 400(%rsp)
	cmpq	104(%rsp), %r12
	je	.L247
	movq	400(%rsp), %rdx
	addq	$8, %r12
	movq	%rdx, -8(%r12)
	movq	%r12, 280(%rsp)
.L248:
	movl	%esi, %r8d
.L242:
	addq	$1, %rbx
	addl	$1, %esi
	cmpl	%r8d, %eax
	jg	.L249
	movl	%r15d, %edi
	cmpl	%r9d, %r15d
	jge	.L367
	addq	$24, %rbp
	testl	%eax, %eax
	jg	.L251
.L367:
	movq	272(%rsp), %rax
	movq	%rax, 120(%rsp)
	cmpq	%r12, %rax
	je	.L237
	movq	%r12, %rax
	subq	120(%rsp), %rax
	cmpq	$40, %rax
	ja	.L471
	leaq	312(%rsp), %rax
	movl	$0, 312(%rsp)
	leaq	352(%rsp), %r13
	movq	%rax, 328(%rsp)
	movq	%rax, 336(%rsp)
	movq	120(%rsp), %rax
	movq	$0, 320(%rsp)
	movq	(%rax), %xmm0
	leaq	360(%rsp), %rax
	movq	$0, 344(%rsp)
	movq	%rax, 152(%rsp)
	pshufd	$0xe5, %xmm0, %xmm3
	movq	%rax, 376(%rsp)
	movd	%xmm0, %esi
	movd	%xmm3, %edi
	movq	%rax, 384(%rsp)
	movd	%xmm3, %eax
	movl	$0, 360(%rsp)
	orl	%esi, %eax
	movq	$0, 368(%rsp)
	movq	$0, 392(%rsp)
	js	.L255
	cmpl	%esi, 208(%rsp)
	jg	.L472
.L255:
	testl	%esi, %esi
	js	.L262
	leal	1(%rdi), %r15d
	movd	%esi, %xmm0
	movd	%r15d, %xmm3
	punpckldq	%xmm3, %xmm0
	cmpl	%esi, 208(%rsp)
	jle	.L263
	testl	%r15d, %r15d
	jns	.L473
.L263:
	leal	-1(%rdi), %r15d
	movd	%esi, %xmm0
	movd	%r15d, %xmm5
	punpckldq	%xmm5, %xmm0
	cmpl	%esi, 208(%rsp)
	jle	.L270
	testl	%r15d, %r15d
	jns	.L474
.L270:
	leal	1(%rsi), %r15d
	movd	%edi, %xmm3
	movd	%r15d, %xmm0
	punpckldq	%xmm3, %xmm0
.L363:
	cmpl	208(%rsp), %r15d
	jge	.L277
	testl	%edi, %edi
	jns	.L475
.L277:
	subl	$1, %esi
	movd	%edi, %xmm3
	movd	%esi, %xmm0
	punpckldq	%xmm3, %xmm0
	js	.L284
	cmpl	208(%rsp), %esi
	jge	.L284
	testl	%edi, %edi
	jns	.L476
.L284:
	movq	376(%rsp), %rax
	leaq	240(%rsp), %rsi
	movq	%rsi, 56(%rsp)
	movq	%rax, 160(%rsp)
	cmpq	152(%rsp), %rax
	je	.L289
.L288:
	movq	160(%rsp), %rax
	movl	36(%rax), %esi
	movl	32(%rax), %r15d
	movl	208(%rsp), %eax
	movl	%esi, 128(%rsp)
	testl	%eax, %eax
	jle	.L294
	movslq	%r15d, %rax
	movq	%r14, 64(%rsp)
	imulq	$24, %rax, %rax
	movl	$0, 100(%rsp)
	addq	%r14, %rax
	movq	%rax, 80(%rsp)
	movslq	%esi, %rax
	salq	$2, %rax
	movq	%rax, 72(%rsp)
	movl	212(%rsp), %eax
	testl	%eax, %eax
	jle	.L294
.L351:
	movl	128(%rsp), %eax
	cmpl	100(%rsp), %r15d
	movq	$0, 40(%rsp)
	movd	%r15d, %xmm7
	leaq	408(%rsp), %rbx
	movl	%eax, %esi
	movd	%eax, %xmm3
	leaq	224(%rsp), %rax
	cmovne	%r15d, %esi
	movq	%rax, 136(%rsp)
	punpckldq	%xmm3, %xmm7
	leaq	192(%rsp), %rax
	movq	%rax, 144(%rsp)
	movl	%esi, 168(%rsp)
	.p2align 4,,10
	.p2align 3
.L349:
	movq	40(%rsp), %rax
	movl	100(%rsp), %r11d
	movl	$1, %esi
	movq	120(%rsp), %r8
	movl	128(%rsp), %r9d
	movd	%r11d, %xmm6
	movd	%eax, %xmm1
	movl	%eax, 132(%rsp)
	movl	%eax, %r10d
	punpckldq	%xmm1, %xmm6
	punpcklqdq	%xmm7, %xmm6
	.p2align 4,,10
	.p2align 3
.L297:
	movl	4(%r8), %edx
	movl	(%r8), %eax
	movl	%edx, %edi
	movl	%eax, %ebp
	subl	%r9d, %edi
	movl	%edi, %ecx
	negl	%ecx
	cmovs	%edi, %ecx
	subl	%r15d, %ebp
	movl	%ebp, %edi
	negl	%edi
	cmovs	%ebp, %edi
	addl	%edi, %ecx
	cmpl	$1, %ecx
	jle	.L296
	subl	%r10d, %edx
	movl	%edx, %ecx
	negl	%ecx
	cmovns	%ecx, %edx
	subl	%r11d, %eax
	movl	%eax, %ecx
	negl	%ecx
	cmovns	%ecx, %eax
	addl	%edx, %eax
	cmpl	$2, %eax
	movl	$0, %eax
	cmovge	%eax, %esi
.L296:
	addq	$8, %r8
	cmpq	%r8, %r12
	jne	.L297
	movq	80(%rsp), %rdi
	movq	64(%rsp), %rcx
	movaps	%xmm6, 224(%rsp)
	movq	72(%rsp), %rax
	addq	(%rdi), %rax
	movq	40(%rsp), %rdi
	movq	(%rcx), %rdx
	movl	(%rax), %r8d
	salq	$2, %rdi
	addq	%rdi, %rdx
	movq	%rdi, 88(%rsp)
	movl	(%rdx), %ecx
	movl	%r8d, (%rdx)
	movl	%ecx, (%rax)
	movq	136(%rsp), %rax
	movq	%rax, 32(%rsp)
.L341:
	movq	(%rax), %xmm0
	movq	%rbx, 424(%rsp)
	movl	$0, 408(%rsp)
	pshufd	$0xe5, %xmm0, %xmm3
	movd	%xmm0, %edi
	movd	%xmm3, %eax
	movq	$0, 416(%rsp)
	orl	%edi, %eax
	movq	%rbx, 432(%rsp)
	movd	%xmm3, %ebp
	movq	$0, 440(%rsp)
	js	.L298
	cmpl	%edi, 208(%rsp)
	jg	.L477
.L298:
	testl	%edi, %edi
	js	.L305
	leal	1(%rbp), %eax
	movd	%edi, %xmm0
	movd	%eax, %xmm5
	punpckldq	%xmm5, %xmm0
	cmpl	%edi, 208(%rsp)
	jle	.L306
	testl	%eax, %eax
	jns	.L478
.L306:
	leal	-1(%rbp), %eax
	movd	%edi, %xmm0
	movd	%eax, %xmm5
	punpckldq	%xmm5, %xmm0
	cmpl	%edi, 208(%rsp)
	jle	.L313
	testl	%eax, %eax
	jns	.L479
.L313:
	leal	1(%rdi), %eax
	movd	%ebp, %xmm1
	movd	%eax, %xmm0
	punpckldq	%xmm1, %xmm0
.L360:
	cmpl	208(%rsp), %eax
	jge	.L320
	testl	%ebp, %ebp
	jns	.L480
.L320:
	subl	$1, %edi
	movd	%ebp, %xmm4
	movd	%edi, %xmm0
	punpckldq	%xmm4, %xmm0
	js	.L327
	cmpl	208(%rsp), %edi
	jge	.L327
	testl	%ebp, %ebp
	jns	.L481
.L327:
	movq	424(%rsp), %rcx
	cmpq	%rbx, %rcx
	je	.L332
	movl	208(%rsp), %eax
	movq	%r12, 48(%rsp)
	leal	-1(%rax), %edi
	movl	212(%rsp), %eax
	leal	-1(%rax), %ebp
	jmp	.L339
	.p2align 4,,10
	.p2align 3
.L483:
	xorl	%eax, %eax
	cmpl	4(%r10,%r13), %r8d
	cmovle	%eax, %esi
.L335:
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	cmpq	%rbx, %rax
	je	.L482
.L339:
	movslq	32(%rcx), %rax
	movl	36(%rcx), %r9d
	movq	%rax, %rdx
	leaq	(%rax,%rax,2), %rax
	movq	(%r14,%rax,8), %r10
	leaq	0(,%rax,8), %r11
	movslq	%r9d, %rax
	leaq	0(,%rax,4), %r13
	movl	(%r10,%rax,4), %r8d
	testl	%r8d, %r8d
	je	.L335
	testl	%edx, %edx
	jle	.L336
	movq	-24(%r14,%r11), %r12
	cmpl	(%r12,%rax,4), %r8d
	jg	.L335
.L336:
	cmpl	%edi, %edx
	jge	.L337
	movq	24(%r14,%r11), %rdx
	cmpl	(%rdx,%rax,4), %r8d
	jg	.L335
.L337:
	testl	%r9d, %r9d
	jle	.L338
	cmpl	-4(%r10,%r13), %r8d
	jg	.L335
.L338:
	cmpl	%ebp, %r9d
	jl	.L483
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	xorl	%esi, %esi
	movq	%rax, %rcx
	cmpq	%rbx, %rax
	jne	.L339
	.p2align 4,,10
	.p2align 3
.L482:
	movq	48(%rsp), %r12
.L332:
	movq	416(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L343
.L340:
	movq	24(%rdi), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
	movq	%rdi, %rcx
	movq	16(%rdi), %rdi
	movl	$40, %edx
	call	_ZdlPvy
	testq	%rdi, %rdi
	jne	.L340
.L343:
	addq	$8, 32(%rsp)
	movq	32(%rsp), %rax
	cmpq	%rax, 56(%rsp)
	jne	.L341
	movq	80(%rsp), %rdi
	movq	72(%rsp), %rax
	movq	88(%rsp), %rdx
	addq	(%rdi), %rax
	movq	64(%rsp), %rdi
	movl	(%rax), %r8d
	addq	(%rdi), %rdx
	movl	(%rdx), %ecx
	movl	%r8d, (%rdx)
	movl	%ecx, (%rax)
	testb	%sil, %sil
	jne	.L484
.L344:
	addq	$1, 40(%rsp)
	movl	212(%rsp), %eax
	movq	40(%rsp), %rsi
	cmpl	%esi, %eax
	jg	.L349
	addl	$1, 100(%rsp)
	movl	100(%rsp), %esi
	cmpl	%esi, 208(%rsp)
	jle	.L294
	addq	$24, 64(%rsp)
	testl	%eax, %eax
	jg	.L351
.L294:
	movq	160(%rsp), %rcx
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	movq	152(%rsp), %rsi
	movq	%rax, 160(%rsp)
	cmpq	%rsi, %rax
	jne	.L288
.L289:
	movq	368(%rsp), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
	cmpq	$0, 344(%rsp)
	je	.L485
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	$2, %r8d
	leaq	.LC4(%rip), %rdx
	movq	%r12, %rcx
.LEHB7:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	344(%rsp), %rdx
	movq	%r12, %rcx
	call	_ZNSo9_M_insertIyEERSoT_
	movq	%rax, %rcx
	movl	$1, %r8d
	leaq	.LC5(%rip), %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE7:
	jmp	.L352
	.p2align 4,,10
	.p2align 3
.L247:
	movq	112(%rsp), %r8
	movq	32(%rsp), %rcx
	movq	%r12, %rdx
.LEHB8:
	call	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
.LEHE8:
	movq	288(%rsp), %rdx
	movl	212(%rsp), %eax
	movl	208(%rsp), %r9d
	movq	280(%rsp), %r12
	movq	%rdx, 104(%rsp)
	jmp	.L248
	.p2align 4,,10
	.p2align 3
.L305:
	leal	1(%rdi), %eax
	movd	%ebp, %xmm4
	movd	%eax, %xmm0
	punpckldq	%xmm4, %xmm0
	testl	%eax, %eax
	jne	.L320
	jmp	.L360
	.p2align 4,,10
	.p2align 3
.L479:
	cmpl	212(%rsp), %eax
	jge	.L313
	movq	112(%rsp), %rdx
	movq	144(%rsp), %rcx
	leaq	216(%rsp), %r8
	movl	%eax, 48(%rsp)
	movq	%xmm0, 216(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %r13
	movq	192(%rsp), %rdx
	testq	%r13, %r13
	je	.L313
	testq	%rdx, %rdx
	movl	48(%rsp), %eax
	setne	%cl
	cmpq	%rbx, %r13
	sete	%dl
	orb	%dl, %cl
	movb	%cl, 175(%rsp)
	je	.L315
.L318:
	movl	$40, %ecx
.LEHB9:
	call	_Znwy
	movq	%rax, %rdx
	movq	216(%rsp), %rax
	movq	%rbx, %r9
	movq	%r13, %r8
	movzbl	175(%rsp), %ecx
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 440(%rsp)
	jmp	.L313
.L477:
	cmpl	%ebp, 212(%rsp)
	jle	.L298
	movq	112(%rsp), %rdx
	movq	144(%rsp), %rcx
	leaq	216(%rsp), %r8
	movq	%xmm0, 216(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %r13
	movq	192(%rsp), %rdx
	testq	%r13, %r13
	je	.L298
	testq	%rdx, %rdx
	setne	%dl
	cmpq	%rbx, %r13
	sete	%al
	orb	%al, %dl
	movb	%dl, 48(%rsp)
	je	.L300
.L303:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movzbl	48(%rsp), %ecx
	movq	%rbx, %r9
	movq	%r13, %r8
	movq	216(%rsp), %rax
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 440(%rsp)
	jmp	.L298
.L478:
	cmpl	%eax, 212(%rsp)
	jle	.L306
	movq	112(%rsp), %rdx
	movq	144(%rsp), %rcx
	leaq	216(%rsp), %r8
	movl	%eax, 48(%rsp)
	movq	%xmm0, 216(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %r13
	movq	192(%rsp), %rdx
	testq	%r13, %r13
	je	.L306
	cmpq	%rbx, %r13
	movl	48(%rsp), %eax
	sete	%cl
	testq	%rdx, %rdx
	setne	%dl
	orb	%dl, %cl
	movb	%cl, 175(%rsp)
	je	.L308
.L311:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movq	216(%rsp), %rax
	movq	%rbx, %r9
	movq	%r13, %r8
	movzbl	175(%rsp), %ecx
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 440(%rsp)
	jmp	.L306
.L480:
	cmpl	212(%rsp), %ebp
	jge	.L320
	movq	112(%rsp), %rdx
	movq	144(%rsp), %rcx
	leaq	216(%rsp), %r8
	movl	%eax, 48(%rsp)
	movq	%xmm0, 216(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %r13
	movq	192(%rsp), %rdx
	testq	%r13, %r13
	je	.L320
	testq	%rdx, %rdx
	movl	48(%rsp), %eax
	setne	%cl
	cmpq	%rbx, %r13
	sete	%dl
	orb	%dl, %cl
	movb	%cl, 175(%rsp)
	je	.L322
.L325:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movq	216(%rsp), %rax
	movq	%rbx, %r9
	movq	%r13, %r8
	movzbl	175(%rsp), %ecx
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 440(%rsp)
	jmp	.L320
.L481:
	cmpl	212(%rsp), %ebp
	jge	.L327
	movq	112(%rsp), %rdx
	movq	144(%rsp), %rcx
	leaq	216(%rsp), %r8
	movq	%xmm0, 216(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %r13
	movq	192(%rsp), %rdx
	testq	%r13, %r13
	je	.L327
	testq	%rdx, %rdx
	setne	%dl
	cmpq	%rbx, %r13
	sete	%al
	orb	%al, %dl
	movb	%dl, 48(%rsp)
	je	.L486
.L329:
	movl	$40, %ecx
	call	_Znwy
.LEHE9:
	movq	%rax, %rdx
	movzbl	48(%rsp), %ecx
	movq	%rbx, %r9
	movq	%r13, %r8
	movq	216(%rsp), %rax
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 440(%rsp)
	jmp	.L327
.L484:
	movl	100(%rsp), %esi
	movl	%esi, %eax
	cmpl	%esi, %r15d
	je	.L487
.L345:
	cmpl	%eax, 168(%rsp)
	jge	.L346
	movd	100(%rsp), %xmm1
	movdqa	%xmm7, %xmm0
	movd	132(%rsp), %xmm3
	leaq	176(%rsp), %rcx
	movq	112(%rsp), %r8
	leaq	304(%rsp), %rdx
	punpckldq	%xmm3, %xmm1
	punpcklqdq	%xmm1, %xmm0
	movaps	%xmm0, 400(%rsp)
.LEHB10:
	call	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_
	jmp	.L344
.L346:
	movq	112(%rsp), %r8
	leaq	176(%rsp), %rcx
	leaq	304(%rsp), %rdx
	movaps	%xmm6, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE16_M_insert_uniqueIS2_EESt4pairISt17_Rb_tree_iteratorIS2_EbEOT_
.LEHE10:
	jmp	.L344
.L487:
	movl	40(%rsp), %esi
	cmpl	%esi, 128(%rsp)
	je	.L346
	movl	132(%rsp), %eax
	jmp	.L345
.L214:
	movq	$0, 400(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 416(%rsp)
	jmp	.L215
.L369:
	xorl	%r14d, %r14d
	jmp	.L217
.L471:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$2, %r8d
	leaq	.LC3(%rip), %rdx
.LEHB11:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE11:
	movq	120(%rsp), %r12
.L253:
	leaq	240(%rsp), %rax
	movq	%rax, 56(%rsp)
	testq	%r12, %r12
	jne	.L488
.L354:
	movq	56(%rsp), %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	nop
	movaps	448(%rsp), %xmm6
	movaps	464(%rsp), %xmm7
	xorl	%eax, %eax
	addq	$488, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L262:
	leal	1(%rsi), %r15d
	movd	%edi, %xmm3
	movd	%r15d, %xmm0
	punpckldq	%xmm3, %xmm0
	testl	%r15d, %r15d
	jne	.L277
	jmp	.L363
.L368:
	movq	%rcx, %rbx
	jmp	.L215
.L476:
	cmpl	%edi, 212(%rsp)
	jle	.L284
	movq	112(%rsp), %r8
	movq	%r13, %rdx
	leaq	192(%rsp), %rcx
	movq	%xmm0, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %rbx
	movq	192(%rsp), %rax
	testq	%rbx, %rbx
	je	.L284
	testq	%rax, %rax
	setne	%bpl
	cmpq	152(%rsp), %rbx
	sete	%al
	orb	%al, %bpl
	je	.L489
.L286:
	movl	$40, %ecx
.LEHB12:
	call	_Znwy
	movq	%rax, %rdx
	movq	400(%rsp), %rax
	movzbl	%bpl, %ecx
	movq	%rbx, %r8
	movq	152(%rsp), %r9
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 392(%rsp)
	jmp	.L284
.L475:
	cmpl	212(%rsp), %edi
	jge	.L277
	movq	112(%rsp), %r8
	movq	%r13, %rdx
	leaq	192(%rsp), %rcx
	movq	%xmm0, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %rbx
	movq	192(%rsp), %rax
	testq	%rbx, %rbx
	je	.L277
	testq	%rax, %rax
	setne	%bpl
	cmpq	152(%rsp), %rbx
	sete	%al
	orb	%al, %bpl
	je	.L279
.L282:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movq	400(%rsp), %rax
	movzbl	%bpl, %ecx
	movq	%rbx, %r8
	movq	152(%rsp), %r9
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 392(%rsp)
	jmp	.L277
.L474:
	cmpl	212(%rsp), %r15d
	jge	.L270
	movq	112(%rsp), %r8
	movq	%r13, %rdx
	leaq	192(%rsp), %rcx
	movq	%xmm0, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %rbx
	movq	192(%rsp), %rax
	testq	%rbx, %rbx
	je	.L270
	testq	%rax, %rax
	setne	%bpl
	cmpq	152(%rsp), %rbx
	sete	%al
	orb	%al, %bpl
	je	.L272
.L275:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movq	400(%rsp), %rax
	movzbl	%bpl, %ecx
	movq	%rbx, %r8
	movq	152(%rsp), %r9
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 392(%rsp)
	jmp	.L270
.L473:
	cmpl	212(%rsp), %r15d
	jge	.L263
	movq	112(%rsp), %r8
	movq	%r13, %rdx
	leaq	192(%rsp), %rcx
	movq	%xmm0, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %rbx
	movq	192(%rsp), %rax
	testq	%rbx, %rbx
	je	.L263
	testq	%rax, %rax
	setne	%bpl
	cmpq	152(%rsp), %rbx
	sete	%al
	orb	%al, %bpl
	je	.L265
.L268:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rdx
	movq	400(%rsp), %rax
	movzbl	%bpl, %ecx
	movq	%rbx, %r8
	movq	152(%rsp), %r9
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 392(%rsp)
	jmp	.L263
.L488:
	movq	288(%rsp), %rdx
	subq	%r12, %rdx
.L353:
	movq	%r12, %rcx
	call	_ZdlPvy
	jmp	.L354
.L486:
	movl	32(%r13), %eax
	cmpl	%edi, %eax
	je	.L490
.L330:
	cmpl	%eax, %edi
	setl	48(%rsp)
	jmp	.L329
.L322:
	movl	32(%r13), %edx
	cmpl	%edx, %eax
	je	.L324
.L326:
	cmpl	%edx, %eax
	setl	175(%rsp)
	jmp	.L325
.L308:
	movl	32(%r13), %edx
	cmpl	%edi, %edx
	je	.L310
	movl	%edi, %eax
.L312:
	cmpl	%eax, %edx
	setg	175(%rsp)
	jmp	.L311
.L315:
	movl	32(%r13), %edx
	cmpl	%edi, %edx
	je	.L317
	movl	%edi, %eax
.L319:
	cmpl	%edx, %eax
	setl	175(%rsp)
	jmp	.L318
.L300:
	movl	32(%r13), %eax
	cmpl	%edi, %eax
	je	.L302
	movl	%edi, %edx
.L304:
	cmpl	%eax, %edx
	setl	48(%rsp)
	jmp	.L303
.L472:
	cmpl	%edi, 212(%rsp)
	jle	.L255
	movq	112(%rsp), %r8
	movq	%r13, %rdx
	leaq	192(%rsp), %rcx
	movq	%xmm0, 400(%rsp)
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE24_M_get_insert_unique_posERKS1_
	movq	200(%rsp), %rbx
	movq	192(%rsp), %rax
	testq	%rbx, %rbx
	je	.L255
	cmpq	152(%rsp), %rbx
	sete	%bpl
	testq	%rax, %rax
	setne	%al
	orb	%al, %bpl
	je	.L257
.L260:
	movl	$40, %ecx
	call	_Znwy
.LEHE12:
	movq	%rax, %rdx
	movq	400(%rsp), %rax
	movzbl	%bpl, %ecx
	movq	%rbx, %r8
	movq	152(%rsp), %r9
	movq	%rax, 32(%rdx)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 392(%rsp)
	jmp	.L255
.L223:
	movq	$0, 288(%rsp)
	pxor	%xmm0, %xmm0
	movaps	%xmm0, 272(%rsp)
.L467:
	xorl	%r12d, %r12d
.L237:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$2, %r8d
	leaq	.LC2(%rip), %rdx
.LEHB13:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE13:
	jmp	.L253
.L490:
	movl	36(%r13), %eax
	cmpl	%eax, %ebp
	je	.L329
	movl	%ebp, %edi
	jmp	.L330
.L310:
	movl	36(%r13), %edx
	cmpl	%eax, %edx
	jne	.L312
	jmp	.L311
.L324:
	movl	36(%r13), %edx
	movl	%ebp, %eax
	cmpl	%edx, %ebp
	jne	.L326
	jmp	.L325
.L317:
	movl	36(%r13), %edx
	cmpl	%edx, %eax
	jne	.L319
	jmp	.L318
.L302:
	movl	36(%r13), %eax
	movl	%ebp, %edx
	cmpl	%eax, %ebp
	jne	.L304
	jmp	.L303
.L485:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$2, %r8d
	leaq	.LC3(%rip), %rdx
.LEHB14:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
.LEHE14:
.L352:
	movq	320(%rsp), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
	movq	104(%rsp), %rdx
	movq	120(%rsp), %r12
	subq	%r12, %rdx
	jmp	.L353
.L272:
	movl	32(%rbx), %eax
	cmpl	%esi, %eax
	je	.L274
	movl	%esi, %r15d
.L276:
	cmpl	%eax, %r15d
	setl	%bpl
	jmp	.L275
.L265:
	movl	32(%rbx), %eax
	cmpl	%esi, %eax
	je	.L267
	movl	%esi, %r15d
.L269:
	cmpl	%r15d, %eax
	setg	%bpl
	jmp	.L268
.L274:
	movl	36(%rbx), %eax
	cmpl	%eax, %r15d
	jne	.L276
	jmp	.L275
.L267:
	movl	36(%rbx), %eax
	cmpl	%eax, %r15d
	jne	.L269
	jmp	.L268
.L279:
	movl	32(%rbx), %eax
	cmpl	%eax, %r15d
	je	.L281
.L283:
	cmpl	%eax, %r15d
	setl	%bpl
	jmp	.L282
.L257:
	movl	32(%rbx), %eax
	cmpl	%esi, %eax
	je	.L259
	movl	%esi, %edx
.L261:
	cmpl	%edx, %eax
	setg	%bpl
	jmp	.L260
.L489:
	movl	32(%rbx), %eax
	cmpl	%esi, %eax
	je	.L491
.L287:
	cmpl	%eax, %esi
	setl	%bpl
	jmp	.L286
.L281:
	movl	36(%rbx), %eax
	movl	%edi, %r15d
	cmpl	%eax, %edi
	jne	.L283
	jmp	.L282
.L259:
	movl	36(%rbx), %eax
	movl	%edi, %edx
	cmpl	%edi, %eax
	jne	.L261
	jmp	.L260
.L491:
	movl	36(%rbx), %eax
	cmpl	%edi, %eax
	je	.L286
	movl	%edi, %esi
	jmp	.L287
.L468:
	leaq	.LC1(%rip), %rcx
.LEHB15:
	call	_ZSt20__throw_length_errorPKc
.LEHE15:
.L469:
	leaq	.LC1(%rip), %rcx
.LEHB16:
	call	_ZSt20__throw_length_errorPKc
.LEHE16:
.L234:
	movq	$0, 288(%rsp)
	pxor	%xmm0, %xmm0
	movaps	%xmm0, 272(%rsp)
	testl	%r9d, %r9d
	jg	.L236
	jmp	.L467
.L380:
	movq	%rax, %rbx
	leaq	240(%rsp), %rax
	movq	%rax, 56(%rsp)
.L358:
	movq	56(%rsp), %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	movq	%rbx, %rcx
.LEHB17:
	call	_Unwind_Resume
.L383:
	movq	%rax, %rbx
.L291:
	movq	320(%rsp), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIS0_IiLy2EELy2EES2_St9_IdentityIS2_ESt4lessIS2_ESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E.isra.0
.L356:
	movq	272(%rsp), %rcx
	movq	288(%rsp), %rdx
	subq	%rcx, %rdx
	testq	%rcx, %rcx
	je	.L358
	call	_ZdlPvy
	jmp	.L358
.L385:
	movq	368(%rsp), %rcx
	movq	%rax, %rbx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
	leaq	240(%rsp), %rax
	movq	%rax, 56(%rsp)
	jmp	.L291
.L384:
	movq	%rax, %r12
	testq	%r14, %r14
	je	.L222
	movq	%r13, %rdx
	movq	%r14, %rcx
	call	_ZdlPvy
.L222:
	movq	400(%rsp), %rcx
	movq	416(%rsp), %rdx
	subq	%rcx, %rdx
	testq	%rcx, %rcx
	je	.L355
	call	_ZdlPvy
.L355:
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE17:
.L386:
	movq	416(%rsp), %rcx
	movq	%rax, %rbx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
.L334:
	movq	368(%rsp), %rcx
	call	_ZNSt8_Rb_treeISt5arrayIiLy2EES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E.isra.0
	jmp	.L291
.L382:
	movq	%rax, %rbx
	jmp	.L334
.L381:
	movq	%rax, %rbx
	leaq	240(%rsp), %rax
	movq	%rax, 56(%rsp)
	jmp	.L356
.L379:
	movq	%rax, %r12
	jmp	.L222
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA11911:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE11911-.LLSDACSB11911
.LLSDACSB11911:
	.uleb128 .LEHB3-.LFB11911
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB11911
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L379-.LFB11911
	.uleb128 0
	.uleb128 .LEHB5-.LFB11911
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L384-.LFB11911
	.uleb128 0
	.uleb128 .LEHB6-.LFB11911
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L380-.LFB11911
	.uleb128 0
	.uleb128 .LEHB7-.LFB11911
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L383-.LFB11911
	.uleb128 0
	.uleb128 .LEHB8-.LFB11911
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L381-.LFB11911
	.uleb128 0
	.uleb128 .LEHB9-.LFB11911
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L386-.LFB11911
	.uleb128 0
	.uleb128 .LEHB10-.LFB11911
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L382-.LFB11911
	.uleb128 0
	.uleb128 .LEHB11-.LFB11911
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L381-.LFB11911
	.uleb128 0
	.uleb128 .LEHB12-.LFB11911
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L385-.LFB11911
	.uleb128 0
	.uleb128 .LEHB13-.LFB11911
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L381-.LFB11911
	.uleb128 0
	.uleb128 .LEHB14-.LFB11911
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L383-.LFB11911
	.uleb128 0
	.uleb128 .LEHB15-.LFB11911
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB16-.LFB11911
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L379-.LFB11911
	.uleb128 0
	.uleb128 .LEHB17-.LFB11911
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0
	.uleb128 0
.LLSDACSE11911:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z4readv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z4readv
_GLOBAL__sub_I__Z4readv:
.LFB14378:
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
	.quad	_GLOBAL__sub_I__Z4readv
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZSt28__throw_bad_array_new_lengthv;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIyEERSoT_;	.scl	2;	.type	32;	.endef
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
