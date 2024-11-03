__asm__(R"(
	.file	"CF1697D Guess The String.cpp"
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
.LFB13959:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.def	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEExNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE_EEEvT_SB_T0_T1_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEExNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE_EEEvT_SB_T0_T1_
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEExNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE_EEEvT_SB_T0_T1_:
.LFB13452:
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
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rcx, %rbx
	movq	%rdx, %rsi
	movq	%r8, %r13
	subq	%rcx, %rax
	movq	%r9, %rbp
	movq	%rdx, %r11
	cmpq	$64, %rax
	jle	.L4
	testq	%r8, %r8
	je	.L7
	movq	(%r9), %rdi
	leaq	4(%rcx), %r12
.L9:
	movq	%r11, %rax
	movslq	4(%rbx), %r8
	movslq	-4(%r11), %rcx
	subq	$1, %r13
	subq	%rbx, %rax
	movq	%rax, %rdx
	shrq	$63, %rax
	movl	(%rdi,%rcx,4), %r9d
	movq	%rcx, %r15
	sarq	$2, %rdx
	movl	(%rbx), %ecx
	movq	%r8, %r14
	addq	%rdx, %rax
	movl	(%rdi,%r8,4), %edx
	sarq	%rax
	leaq	(%rbx,%rax,4), %r10
	movslq	(%r10), %rax
	movq	%rax, %rsi
	movl	(%rdi,%rax,4), %eax
	cmpl	%eax, %edx
	jle	.L29
	cmpl	%r9d, %eax
	jg	.L34
	cmpl	%r9d, %edx
	jg	.L76
.L77:
	movl	%r14d, (%rbx)
	movl	%ecx, 4(%rbx)
	movl	-4(%r11), %r14d
.L31:
	movl	(%rdi,%r8,4), %r10d
	movslq	%ecx, %r8
	movq	%r11, %rdx
	movq	%r12, %rax
	cmpl	(%rdi,%r8,4), %r10d
	jge	.L54
	.p2align 4,,10
	.p2align 3
.L79:
	addq	$4, %rax
	.p2align 4,,10
	.p2align 3
.L36:
	movslq	(%rax), %r8
	movq	%rax, %rsi
	addq	$4, %rax
	movq	%r8, %rcx
	cmpl	(%rdi,%r8,4), %r10d
	jl	.L36
.L35:
	movslq	%r14d, %rax
	subq	$4, %rdx
	cmpl	(%rdi,%rax,4), %r10d
	jle	.L37
	.p2align 4,,10
	.p2align 3
.L38:
	movslq	-4(%rdx), %rax
	subq	$4, %rdx
	movq	%rax, %r14
	cmpl	(%rdi,%rax,4), %r10d
	jg	.L38
.L37:
	cmpq	%rsi, %rdx
	ja	.L78
	movq	%rbp, %r9
	movq	%r13, %r8
	movq	%r11, %rdx
	movq	%rsi, %rcx
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEExNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE_EEEvT_SB_T0_T1_
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$64, %rax
	jle	.L4
	testq	%r13, %r13
	je	.L7
	movq	%rsi, %r11
	jmp	.L9
.L29:
	cmpl	%r9d, %edx
	jg	.L77
	cmpl	%r9d, %eax
	jle	.L34
.L76:
	movl	%r15d, (%rbx)
	movl	%ecx, %r14d
	movl	%ecx, -4(%r11)
	movl	4(%rbx), %ecx
	movslq	(%rbx), %r8
	jmp	.L31
	.p2align 4,,10
	.p2align 3
.L78:
	movl	%r14d, (%rsi)
	leaq	4(%rsi), %rax
	movl	-4(%rdx), %r14d
	movl	%ecx, (%rdx)
	movslq	(%rbx), %r8
	movl	4(%rsi), %ecx
	movl	(%rdi,%r8,4), %r10d
	movslq	%ecx, %r8
	cmpl	(%rdi,%r8,4), %r10d
	jl	.L79
.L54:
	movq	%rax, %rsi
	jmp	.L35
.L34:
	movl	%esi, (%rbx)
	movl	%ecx, (%r10)
	movl	4(%rbx), %ecx
	movl	-4(%r11), %r14d
	movslq	(%rbx), %r8
	jmp	.L31
.L17:
	movq	56(%rsp), %rsi
	leaq	-4(%rsi), %r15
	.p2align 4,,10
	.p2align 3
.L28:
	movq	%r15, %r14
	movl	(%r15), %eax
	subq	%rbx, %r14
	movq	%r14, %r13
	movl	%eax, 40(%rsp)
	movl	(%rbx), %eax
	sarq	$2, %r13
	leaq	-1(%r13), %rcx
	movl	%eax, (%r15)
	movq	%r13, %rax
	movq	%rcx, %r12
	andl	$1, %eax
	shrq	$63, %r12
	movq	%rax, 48(%rsp)
	addq	%rcx, %r12
	sarq	%r12
	cmpq	$8, %r14
	jle	.L19
	xorl	%r9d, %r9d
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L50:
	movq	%rax, %r9
.L21:
	leaq	1(%r9), %rcx
	leaq	(%rcx,%rcx), %rax
	leaq	(%rbx,%rcx,8), %r8
	leaq	-1(%rax), %r10
	movslq	(%r8), %rbp
	leaq	(%rbx,%r10,4), %r11
	movslq	(%r11), %rdi
	movq	%rbp, %rcx
	movq	%rdi, %rsi
	movl	(%rdx,%rdi,4), %edi
	cmpl	%edi, (%rdx,%rbp,4)
	cmovg	%esi, %ecx
	cmovg	%r10, %rax
	cmovg	%r11, %r8
	movl	%ecx, (%rbx,%r9,4)
	cmpq	%r12, %rax
	jl	.L50
	cmpq	$0, 48(%rsp)
	jne	.L25
	subq	$2, %r13
	leaq	-1(%rax), %r9
	movq	%r13, %rcx
	sarq	%r9
	shrq	$63, %rcx
	addq	%r13, %rcx
	sarq	%rcx
	cmpq	%rcx, %rax
	je	.L24
.L43:
	movslq	40(%rsp), %rcx
	movq	%rax, %r11
	leaq	(%rdx,%rcx,4), %r10
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L81:
	movl	%ecx, (%rax)
	leaq	-1(%r9), %rcx
	movq	%r9, %r11
	movq	%rcx, %rax
	shrq	$63, %rax
	addq	%rcx, %rax
	sarq	%rax
	testq	%r9, %r9
	je	.L80
	movq	%rax, %r9
.L27:
	leaq	(%rbx,%r9,4), %r8
	leaq	(%rbx,%r11,4), %rax
	movl	(%r10), %esi
	movl	(%r8), %ecx
	movslq	%ecx, %r11
	cmpl	%esi, (%rdx,%r11,4)
	jg	.L81
.L23:
	movl	40(%rsp), %esi
	subq	$4, %r15
	movl	%esi, (%rax)
	cmpq	$4, %r14
	jg	.L28
.L4:
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L7:
	sarq	$2, %rax
	movq	%rsi, 56(%rsp)
	leaq	-2(%rax), %rdx
	leaq	-1(%rax), %r14
	notq	%rax
	movq	%rdx, %rdi
	andl	$1, %eax
	sarq	%r14
	movq	0(%rbp), %rdx
	sarq	%rdi
	movb	%al, 48(%rsp)
	leaq	(%rbx,%rdi,4), %r15
	movq	%rdi, %r13
	movq	%rdi, 40(%rsp)
	movl	(%r15), %r12d
	movq	%r15, %r8
	cmpq	%r14, %r13
	jge	.L10
.L84:
	movq	%r13, %r9
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L48:
	movq	%rax, %r9
.L12:
	leaq	1(%r9), %rcx
	leaq	(%rcx,%rcx), %rax
	leaq	(%rbx,%rcx,8), %r8
	leaq	-1(%rax), %r10
	movslq	(%r8), %rbp
	leaq	(%rbx,%r10,4), %r11
	movslq	(%r11), %rdi
	movq	%rbp, %rcx
	movq	%rdi, %rsi
	movl	(%rdx,%rdi,4), %edi
	cmpl	%edi, (%rdx,%rbp,4)
	cmovg	%esi, %ecx
	cmovg	%r10, %rax
	cmovg	%r11, %r8
	movl	%ecx, (%rbx,%r9,4)
	cmpq	%r14, %rax
	jl	.L48
	cmpq	%rax, 40(%rsp)
	jne	.L13
	cmpb	$0, 48(%rsp)
	jne	.L44
.L13:
	leaq	-1(%rax), %rcx
	sarq	%rcx
	cmpq	%rax, %r13
	jge	.L14
	movslq	%r12d, %r8
	movq	%rax, %r11
	leaq	(%rdx,%r8,4), %r9
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L83:
	movl	%r10d, (%rax)
	leaq	-1(%rcx), %r10
	movq	%rcx, %r11
	movq	%r10, %rax
	shrq	$63, %rax
	addq	%r10, %rax
	sarq	%rax
	cmpq	%rcx, %r13
	jge	.L82
	movq	%rax, %rcx
.L16:
	leaq	(%rbx,%rcx,4), %r8
	leaq	(%rbx,%r11,4), %rax
	movl	(%r9), %esi
	movl	(%r8), %r10d
	movslq	%r10d, %r11
	cmpl	%esi, (%rdx,%r11,4)
	jg	.L83
.L15:
	movl	%r12d, (%rax)
	subq	$4, %r15
	testq	%r13, %r13
	je	.L17
.L46:
	subq	$1, %r13
	movl	(%r15), %r12d
	movq	%r15, %r8
	cmpq	%r14, %r13
	jl	.L84
.L10:
	cmpq	%r13, 40(%rsp)
	jne	.L14
	cmpb	$0, 48(%rsp)
	movq	%r13, %rax
	jne	.L44
.L14:
	movl	%r12d, (%r8)
	subq	$4, %r15
	jmp	.L46
.L82:
	movq	%r8, %rax
	jmp	.L15
.L19:
	cmpq	$0, 48(%rsp)
	movq	%rbx, %rax
	jne	.L23
	cmpq	$2, %rcx
	ja	.L23
	movq	%rbx, %r8
	xorl	%eax, %eax
.L24:
	leaq	1(%rax,%rax), %rax
	movl	(%rbx,%rax,4), %ecx
	movl	%ecx, (%r8)
.L25:
	leaq	-1(%rax), %r9
	sarq	%r9
	jmp	.L43
.L80:
	movl	40(%rsp), %esi
	movq	%r8, %rax
	subq	$4, %r15
	movl	%esi, (%rax)
	cmpq	$4, %r14
	jg	.L28
	jmp	.L4
.L44:
	leaq	1(%rax,%rax), %rax
	leaq	(%rbx,%rax,4), %rcx
	movl	(%rcx), %r9d
	movl	%r9d, (%r8)
	movq	%rcx, %r8
	jmp	.L13
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	_ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseIiSaIiEED2Ev
_ZNSt12_Vector_baseIiSaIiEED2Ev:
.LFB12766:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L85
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L85:
	ret
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv:
.LFB12842:
	.seh_endprologue
	movq	(%rcx), %r8
	leaq	16(%rcx), %rax
	cmpq	%rax, %r8
	je	.L87
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	addq	$1, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L87:
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB13203:
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
	movq	8(%rcx), %rdi
	movq	(%rcx), %r13
	movq	%rdi, %rax
	subq	%r13, %rax
	movq	%rdx, %r12
	sarq	$2, %rax
	movq	%rcx, %rsi
	movq	%r8, %r14
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	je	.L103
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L101
	testq	%rax, %rax
	jne	.L94
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L100:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L104
	testq	%r9, %r9
	jg	.L96
	testq	%r13, %r13
	jne	.L99
.L97:
	movq	%rbp, (%rsi)
	movq	%rdi, 8(%rsi)
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
.L104:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L96
.L99:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L97
	.p2align 4,,10
	.p2align 3
.L96:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L97
	jmp	.L99
	.p2align 4,,10
	.p2align 3
.L101:
	movabsq	$9223372036854775804, %rbx
.L93:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L100
	.p2align 4,,10
	.p2align 3
.L94:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L93
.L103:
	leaq	.LC0(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "basic_string::_M_create\0"
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy:
.LFB13469:
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
	movq	8(%rcx), %rax
	movq	160(%rsp), %rsi
	movq	%rax, %r12
	leaq	(%rdx,%r8), %r14
	subq	%r8, %rsi
	movq	%rcx, %rbx
	movq	%rdx, %rdi
	movq	%r9, %rbp
	subq	%r14, %r12
	leaq	16(%rcx), %r13
	addq	%rax, %rsi
	cmpq	(%rcx), %r13
	je	.L119
	movq	16(%rcx), %rax
.L106:
	testq	%rsi, %rsi
	js	.L129
	cmpq	%rax, %rsi
	jbe	.L108
	addq	%rax, %rax
	cmpq	%rax, %rsi
	jnb	.L108
	testq	%rax, %rax
	js	.L109
	movq	%rax, %rsi
	.p2align 4,,10
	.p2align 3
.L108:
	movq	%rsi, %rcx
	addq	$1, %rcx
	js	.L109
	call	_Znwy
	movq	(%rbx), %r10
	movq	%rax, %r15
	testq	%rdi, %rdi
	je	.L112
	cmpq	$1, %rdi
	je	.L130
	movq	%r10, %rdx
	movq	%rdi, %r8
	movq	%rax, %rcx
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L112:
	testq	%rbp, %rbp
	je	.L114
	cmpq	$0, 160(%rsp)
	je	.L114
	cmpq	$1, 160(%rsp)
	leaq	(%r15,%rdi), %rcx
	je	.L131
	movq	160(%rsp), %r8
	movq	%rbp, %rdx
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L114:
	testq	%r12, %r12
	je	.L116
.L133:
	addq	160(%rsp), %rdi
	leaq	(%r10,%r14), %rdx
	leaq	(%r15,%rdi), %rcx
	cmpq	$1, %r12
	je	.L132
	movq	%r12, %r8
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L116:
	cmpq	%r10, %r13
	je	.L118
.L134:
	movq	16(%rbx), %rax
	movq	%r10, %rcx
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L118:
	movq	%r15, (%rbx)
	movq	%rsi, 16(%rbx)
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
.L109:
	call	_ZSt17__throw_bad_allocv
	.p2align 4,,10
	.p2align 3
.L119:
	movl	$15, %eax
	jmp	.L106
	.p2align 4,,10
	.p2align 3
.L130:
	movzbl	(%r10), %eax
	movb	%al, (%r15)
	jmp	.L112
	.p2align 4,,10
	.p2align 3
.L131:
	movzbl	0(%rbp), %eax
	movb	%al, (%rcx)
	testq	%r12, %r12
	je	.L116
	jmp	.L133
	.p2align 4,,10
	.p2align 3
.L132:
	movzbl	(%rdx), %eax
	movb	%al, (%rcx)
	cmpq	%r10, %r13
	jne	.L134
	jmp	.L118
.L129:
	leaq	.LC1(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "cannot create std::vector larger than max_size()\0"
.LC3:
	.ascii "? 2 \0"
.LC4:
	.ascii " \0"
.LC5:
	.ascii "? 1 \0"
.LC6:
	.ascii "! \0"
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
	subq	$248, %rsp
	.seh_stackalloc	248
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	104(%rsp), %rdx
	movq	$0, 232(%rax)
	movq	%rax, %rcx
	call	_ZNSirsERi
	movslq	104(%rsp), %rbx
	movq	%rbx, %rax
	shrq	$61, %rax
	jne	.L240
	movq	$0, 120(%rsp)
	leaq	0(,%rbx,4), %rdi
	movq	$0, 128(%rsp)
	testq	%rbx, %rbx
	je	.L137
	movq	%rdi, %rcx
	call	_Znwy
.LEHE0:
	subq	$1, %rbx
	leaq	(%rax,%rdi), %rsi
	movq	%rax, 72(%rsp)
	leaq	4(%rax), %rcx
	movq	%rax, 112(%rsp)
	movq	%rsi, 128(%rsp)
	movl	$0, (%rax)
	je	.L198
	cmpq	%rcx, %rsi
	je	.L138
	leaq	-4(%rdi), %r8
	xorl	%edx, %edx
	call	memset
.L138:
	movl	104(%rsp), %eax
	movq	%rsi, 120(%rsp)
	movq	$0, 144(%rsp)
	movq	$0, 152(%rsp)
	movq	$0, 160(%rsp)
	movl	$0, 108(%rsp)
	testl	%eax, %eax
	jle	.L241
	leaq	144(%rsp), %rax
	movl	$0, 64(%rsp)
	xorl	%ebx, %ebx
	movl	$0, 56(%rsp)
	movq	%rax, 88(%rsp)
	.p2align 4,,10
	.p2align 3
.L139:
	movq	$0, 216(%rsp)
	leaq	0(,%rbx,4), %rbp
	movq	$0, 224(%rsp)
	testq	%rbx, %rbx
	je	.L141
	movq	%rbp, %rcx
.LEHB1:
	call	_Znwy
.LEHE1:
	movq	%rax, %r14
	movq	%rax, 208(%rsp)
	leaq	(%rax,%rbp), %rax
	leaq	4(%r14), %rsi
	movq	%rax, 80(%rsp)
	movq	%rax, 224(%rsp)
	movq	%rsi, %rdi
	movl	$0, (%r14)
	cmpq	$1, %rbx
	je	.L142
	movq	%rax, %rbx
	cmpq	%rsi, %rax
	je	.L142
	leaq	-4(%rbp), %r8
	xorl	%edx, %edx
	movq	%rsi, %rcx
	movq	%rbx, %rdi
	call	memset
.L142:
	movq	%rdi, 216(%rsp)
	cmpq	%rdi, %r14
	je	.L143
	movq	%rdi, %rax
	subq	%r14, %rax
	leaq	-4(%rax), %rcx
	xorl	%eax, %eax
	shrq	$2, %rcx
	.p2align 4,,10
	.p2align 3
.L144:
	movq	%rax, %rdx
	movl	%eax, (%r14,%rax,4)
	addq	$1, %rax
	cmpq	%rdx, %rcx
	jne	.L144
	movq	%rdi, %rbx
	movl	$63, %r8d
	movq	%rdi, %rdx
	movq	%r14, %rcx
	subq	%r14, %rbx
	movq	88(%rsp), %r9
	movq	%rbx, %rax
	sarq	$2, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	subl	%eax, %r8d
	movslq	%r8d, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEExNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE_EEEvT_SB_T0_T1_
	cmpq	$64, %rbx
	jle	.L242
	movq	144(%rsp), %rbx
	leaq	64(%r14), %rbp
	movl	$4, %r13d
	jmp	.L151
	.p2align 4,,10
	.p2align 3
.L244:
	cmpq	%rsi, %r14
	je	.L147
	movq	%rsi, %r8
	leaq	(%r14,%r13), %rcx
	movq	%r14, %rdx
	subq	%r14, %r8
	call	memmove
.L147:
	addq	$4, %rsi
	movl	%r12d, (%r14)
	cmpq	%rsi, %rbp
	je	.L243
.L151:
	movslq	(%rsi), %rax
	movq	%rsi, %r9
	leaq	(%rbx,%rax,4), %r8
	movq	%rax, %r12
	movslq	(%r14), %rax
	movl	(%r8), %ecx
	cmpl	(%rbx,%rax,4), %ecx
	jg	.L244
	movslq	-4(%rsi), %r10
	leaq	-4(%rsi), %rax
	movq	%r10, %rdx
	cmpl	(%rbx,%r10,4), %ecx
	jle	.L149
	.p2align 4,,10
	.p2align 3
.L150:
	movl	%edx, 4(%rax)
	movq	%rax, %r9
	movslq	-4(%rax), %rcx
	subq	$4, %rax
	movq	%rcx, %rdx
	movl	(%rbx,%rcx,4), %ecx
	cmpl	%ecx, (%r8)
	jg	.L150
.L149:
	addq	$4, %rsi
	movl	%r12d, (%r9)
	cmpq	%rsi, %rbp
	jne	.L151
.L243:
	cmpq	%rbp, %rdi
	je	.L195
	.p2align 4,,10
	.p2align 3
.L152:
	movslq	0(%rbp), %rcx
	movl	-4(%rbp), %edx
	leaq	-4(%rbp), %rax
	leaq	(%rbx,%rcx,4), %r8
	movq	%rcx, %r10
	movslq	%edx, %rcx
	movl	(%r8), %esi
	cmpl	%esi, (%rbx,%rcx,4)
	jge	.L202
	.p2align 4,,10
	.p2align 3
.L155:
	movl	%edx, 4(%rax)
	movq	%rax, %r9
	movslq	-4(%rax), %rcx
	subq	$4, %rax
	movl	(%rbx,%rcx,4), %esi
	movq	%rcx, %rdx
	cmpl	%esi, (%r8)
	jg	.L155
	addq	$4, %rbp
	movl	%r10d, (%r9)
	cmpq	%rbp, %rdi
	jne	.L152
	jmp	.L195
	.p2align 4,,10
	.p2align 3
.L141:
	movq	$0, 208(%rsp)
	xorl	%edi, %edi
	movq	$0, 224(%rsp)
	movq	$0, 216(%rsp)
	movq	$0, 80(%rsp)
.L143:
	movq	%rdi, %r14
	.p2align 4,,10
	.p2align 3
.L195:
	movl	64(%rsp), %edi
	xorl	%esi, %esi
	testl	%edi, %edi
	jle	.L165
	movl	56(%rsp), %eax
	movq	.refptr._ZSt4cout(%rip), %rbp
	leal	1(%rax), %r15d
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rax
	movq	%rax, 48(%rsp)
	jmp	.L170
	.p2align 4,,10
	.p2align 3
.L246:
	movsbl	67(%r13), %edx
.L168:
	movq	%r12, %rcx
.LEHB2:
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	leaq	176(%rsp), %r12
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%r12, %rdx
	call	_ZNSirsERi
	leal	1(%rbx), %eax
	cmpl	176(%rsp), %eax
	cmovne	%eax, %esi
	cmove	%ebx, %edi
	cmpl	%edi, %esi
	jge	.L165
.L170:
	leal	(%rsi,%rdi), %eax
	movl	$4, %r8d
	leaq	.LC3(%rip), %rdx
	movq	%rbp, %rcx
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%eax, %ebx
	sarl	%ebx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movslq	%ebx, %rax
	movq	%rbp, %rcx
	movslq	(%r14,%rax,4), %rdx
	movq	144(%rsp), %rax
	movl	(%rax,%rdx,4), %edx
	addl	$1, %edx
	call	_ZNSolsEi
	movl	$1, %r8d
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rcx
	movq	%rax, %r12
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movl	%r15d, %edx
	movq	%r12, %rcx
	call	_ZNSolsEi
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %r13
	testq	%r13, %r13
	je	.L245
	cmpb	$0, 56(%r13)
	jne	.L246
	movq	%r13, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%r13), %rax
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	48(%rsp), %rax
	je	.L168
	movq	%r13, %rcx
	call	*%rax
.LEHE2:
	movsbl	%al, %edx
	jmp	.L168
	.p2align 4,,10
	.p2align 3
.L165:
	movslq	56(%rsp), %rax
	movq	72(%rsp), %rdi
	leaq	(%rdi,%rax,4), %rdx
	cmpl	%esi, 64(%rsp)
	je	.L247
	movslq	%esi, %rsi
	movl	56(%rsp), %edi
	movslq	(%r14,%rsi,4), %rax
	movl	%eax, (%rdx)
	movq	144(%rsp), %rdx
	movl	%edi, (%rdx,%rax,4)
.L173:
	testq	%r14, %r14
	je	.L174
	movq	80(%rsp), %rdx
	movq	%r14, %rcx
	subq	%r14, %rdx
	call	_ZdlPvy
.L174:
	movl	108(%rsp), %eax
	addl	$1, %eax
	movl	%eax, 56(%rsp)
	movl	%eax, 108(%rsp)
	cmpl	104(%rsp), %eax
	jge	.L248
	movslq	64(%rsp), %rbx
	movq	%rbx, %rax
	shrq	$61, %rax
	je	.L139
	leaq	.LC2(%rip), %rcx
.LEHB3:
	call	_ZSt20__throw_length_errorPKc
.LEHE3:
	.p2align 4,,10
	.p2align 3
.L242:
	movq	144(%rsp), %rbx
	movl	$4, %r12d
	cmpq	%rsi, %rdi
	jne	.L163
	jmp	.L195
	.p2align 4,,10
	.p2align 3
.L249:
	cmpq	%r14, %rsi
	je	.L159
	movq	%rsi, %r8
	leaq	(%r14,%r12), %rcx
	movq	%r14, %rdx
	subq	%r14, %r8
	call	memmove
.L159:
	movl	%ebp, (%r14)
.L160:
	addq	$4, %rsi
	cmpq	%rsi, %rdi
	je	.L195
.L163:
	movslq	(%rsi), %rax
	movq	%rsi, %r9
	leaq	(%rbx,%rax,4), %r8
	movq	%rax, %rbp
	movslq	(%r14), %rax
	movl	(%r8), %ecx
	cmpl	(%rbx,%rax,4), %ecx
	jg	.L249
	movslq	-4(%rsi), %r10
	leaq	-4(%rsi), %rax
	movq	%r10, %rdx
	cmpl	%ecx, (%rbx,%r10,4)
	jge	.L161
	.p2align 4,,10
	.p2align 3
.L162:
	movl	%edx, 4(%rax)
	movq	%rax, %r9
	movslq	-4(%rax), %rcx
	subq	$4, %rax
	movq	%rcx, %rdx
	movl	(%rbx,%rcx,4), %ecx
	cmpl	%ecx, (%r8)
	jg	.L162
.L161:
	movl	%ebp, (%r9)
	jmp	.L160
	.p2align 4,,10
	.p2align 3
.L202:
	movq	%rbp, %r9
	addq	$4, %rbp
	movl	%r10d, (%r9)
	cmpq	%rbp, %rdi
	jne	.L152
	jmp	.L195
	.p2align 4,,10
	.p2align 3
.L247:
	movl	64(%rsp), %eax
	movl	%eax, (%rdx)
	leal	1(%rax), %ebx
	movq	152(%rsp), %rdx
	cmpq	160(%rsp), %rdx
	je	.L172
	movl	56(%rsp), %eax
	addq	$4, %rdx
	movl	%ebx, 64(%rsp)
	movl	%eax, -4(%rdx)
	movq	%rdx, 152(%rsp)
	jmp	.L173
.L248:
	leaq	192(%rsp), %rax
	cmpl	$0, 64(%rsp)
	movq	$0, 184(%rsp)
	movq	%rax, 56(%rsp)
	movq	%rax, 176(%rsp)
	leaq	224(%rsp), %rax
	movb	$0, 192(%rsp)
	movq	%rax, 80(%rsp)
	movq	%rax, 208(%rsp)
	movq	$0, 216(%rsp)
	movb	$0, 224(%rsp)
	jle	.L250
	movslq	64(%rsp), %rax
	movq	.refptr._ZSt4cout(%rip), %rbp
	xorl	%edi, %edi
	leaq	176(%rsp), %r12
	leaq	208(%rsp), %rbx
	salq	$2, %rax
	movq	%rax, 48(%rsp)
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rax
	movq	%rax, 64(%rsp)
	jmp	.L184
	.p2align 4,,10
	.p2align 3
.L253:
	movsbl	67(%r15), %edx
.L181:
	movq	%r14, %rcx
	movq	%rbx, %r13
.LEHB4:
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	108(%rsp), %rdx
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	movq	184(%rsp), %rsi
	movq	176(%rsp), %rdx
	movl	$15, %eax
	cmpq	56(%rsp), %rdx
	movzbl	108(%rsp), %r15d
	cmovne	192(%rsp), %rax
	leaq	1(%rsi), %r14
	cmpq	%rax, %r14
	ja	.L251
.L183:
	movb	%r15b, (%rdx,%rsi)
	movq	176(%rsp), %rax
	addq	$4, %rdi
	movq	%r14, 184(%rsp)
	movb	$0, 1(%rax,%rsi)
	cmpq	48(%rsp), %rdi
	je	.L185
.L184:
	movl	$4, %r8d
	leaq	.LC5(%rip), %rdx
	movq	%rbp, %rcx
	movq	%rbx, %r13
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	144(%rsp), %rax
	movq	%rbp, %rcx
	movl	(%rax,%rdi), %edx
	addl	$1, %edx
	call	_ZNSolsEi
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r15
	testq	%r15, %r15
	je	.L252
	cmpb	$0, 56(%r15)
	jne	.L253
	movq	%r15, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r15), %rax
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	64(%rsp), %rax
	je	.L181
	movq	%r15, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L181
	.p2align 4,,10
	.p2align 3
.L251:
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movq	%rsi, %rdx
	movq	%r12, %rcx
	movq	$1, 32(%rsp)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	movq	176(%rsp), %rdx
	jmp	.L183
.L250:
	leaq	176(%rsp), %r12
.L185:
	xorl	%esi, %esi
	cmpl	$0, 104(%rsp)
	leaq	208(%rsp), %r13
	movl	$15, %r14d
	jg	.L177
	jmp	.L178
	.p2align 4,,10
	.p2align 3
.L188:
	movb	%bpl, (%rax,%rbx)
	movq	208(%rsp), %rax
	addq	$1, %rsi
	movq	%rdi, 216(%rsp)
	movb	$0, 1(%rax,%rbx)
	cmpl	%esi, 104(%rsp)
	jle	.L178
.L177:
	movq	72(%rsp), %rax
	movq	176(%rsp), %rdx
	movq	216(%rsp), %rbx
	movslq	(%rax,%rsi,4), %rax
	leaq	1(%rbx), %rdi
	movzbl	(%rdx,%rax), %ebp
	movq	208(%rsp), %rax
	movq	%r14, %rdx
	cmpq	80(%rsp), %rax
	cmovne	224(%rsp), %rdx
	cmpq	%rdx, %rdi
	jbe	.L188
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movq	%rbx, %rdx
	movq	%r13, %rcx
	movq	$1, 32(%rsp)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	movq	208(%rsp), %rax
	jmp	.L188
.L241:
	leaq	192(%rsp), %rax
	movq	$0, 184(%rsp)
	leaq	176(%rsp), %r12
	movq	%rax, 176(%rsp)
	leaq	224(%rsp), %rax
	leaq	208(%rsp), %r13
	movq	%rax, 208(%rsp)
	leaq	144(%rsp), %rax
	movb	$0, 192(%rsp)
	movq	$0, 216(%rsp)
	movb	$0, 224(%rsp)
	movq	%rax, 88(%rsp)
.L178:
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC6(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	216(%rsp), %r8
	movq	208(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	%rax, %r14
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r14,%rax), %r15
	testq	%r15, %r15
	je	.L254
	cmpb	$0, 56(%r15)
	je	.L190
	movzbl	67(%r15), %eax
.L191:
	movsbl	%al, %edx
	movq	%r14, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	movq	%r13, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r12, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	88(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	leaq	112(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	xorl	%eax, %eax
	addq	$248, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L137:
	movq	$0, 112(%rsp)
	xorl	%esi, %esi
	movq	$0, 128(%rsp)
	movq	$0, 72(%rsp)
	jmp	.L138
.L190:
	movq	%r15, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r15), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %r8
	movl	$10, %eax
	cmpq	%rdx, %r8
	je	.L191
	movl	$10, %edx
	movq	%r15, %rcx
	call	*%r8
.LEHE4:
	jmp	.L191
.L198:
	movq	%rcx, %rsi
	jmp	.L138
.L172:
	movq	88(%rsp), %rcx
	leaq	108(%rsp), %r8
.LEHB5:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	%ebx, 64(%rsp)
	jmp	.L173
.L245:
	call	_ZSt16__throw_bad_castv
.LEHE5:
.L252:
	leaq	208(%rsp), %r13
.LEHB6:
	call	_ZSt16__throw_bad_castv
.L254:
	call	_ZSt16__throw_bad_castv
.LEHE6:
.L240:
	leaq	.LC2(%rip), %rcx
.LEHB7:
	call	_ZSt20__throw_length_errorPKc
.L214:
	movq	%r13, %rcx
	movq	%rax, %rbx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r12, %rcx
	movq	%rbx, %r12
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	jmp	.L193
.L212:
	leaq	208(%rsp), %rcx
	movq	%rax, %r12
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L193:
	movq	88(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	leaq	112(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE7:
.L213:
	movq	%rax, %r12
	jmp	.L193
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
	.uleb128 .L213-.LFB11909
	.uleb128 0
	.uleb128 .LEHB2-.LFB11909
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L212-.LFB11909
	.uleb128 0
	.uleb128 .LEHB3-.LFB11909
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L213-.LFB11909
	.uleb128 0
	.uleb128 .LEHB4-.LFB11909
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L214-.LFB11909
	.uleb128 0
	.uleb128 .LEHB5-.LFB11909
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L212-.LFB11909
	.uleb128 0
	.uleb128 .LEHB6-.LFB11909
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L214-.LFB11909
	.uleb128 0
	.uleb128 .LEHB7-.LFB11909
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE11909:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB13982:
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
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
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
