__asm__(R"(
	.file	"C.cpp"
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB13892:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv:
.LFB12817:
	.seh_endprologue
	movq	(%rcx), %r8
	leaq	16(%rcx), %rax
	cmpq	%rax, %r8
	je	.L3
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	addq	$1, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L3:
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	_ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseIiSaIiEED2Ev
_ZNSt12_Vector_baseIiSaIiEED2Ev:
.LFB13161:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L5
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L5:
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "basic_string::_M_create\0"
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy:
.LFB13416:
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
	je	.L21
	movq	16(%rcx), %rax
.L8:
	testq	%rsi, %rsi
	js	.L31
	cmpq	%rax, %rsi
	jbe	.L10
	addq	%rax, %rax
	cmpq	%rax, %rsi
	jnb	.L10
	testq	%rax, %rax
	js	.L11
	movq	%rax, %rsi
	.p2align 4,,10
	.p2align 3
.L10:
	movq	%rsi, %rcx
	addq	$1, %rcx
	js	.L11
	call	_Znwy
	movq	(%rbx), %r10
	movq	%rax, %r15
	testq	%rdi, %rdi
	je	.L14
	cmpq	$1, %rdi
	je	.L32
	movq	%r10, %rdx
	movq	%rdi, %r8
	movq	%rax, %rcx
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L14:
	testq	%rbp, %rbp
	je	.L16
	cmpq	$0, 160(%rsp)
	je	.L16
	cmpq	$1, 160(%rsp)
	leaq	(%r15,%rdi), %rcx
	je	.L33
	movq	160(%rsp), %r8
	movq	%rbp, %rdx
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L16:
	testq	%r12, %r12
	je	.L18
.L35:
	addq	160(%rsp), %rdi
	leaq	(%r10,%r14), %rdx
	leaq	(%r15,%rdi), %rcx
	cmpq	$1, %r12
	je	.L34
	movq	%r12, %r8
	movq	%r10, 40(%rsp)
	call	memcpy
	movq	40(%rsp), %r10
.L18:
	cmpq	%r10, %r13
	je	.L20
.L36:
	movq	16(%rbx), %rax
	movq	%r10, %rcx
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L20:
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
.L11:
	call	_ZSt17__throw_bad_allocv
	.p2align 4,,10
	.p2align 3
.L21:
	movl	$15, %eax
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L32:
	movzbl	(%r10), %eax
	movb	%al, (%r15)
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L33:
	movzbl	0(%rbp), %eax
	movb	%al, (%rcx)
	testq	%r12, %r12
	je	.L18
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L34:
	movzbl	(%rdx), %eax
	movb	%al, (%rcx)
	cmpq	%r10, %r13
	jne	.L36
	jmp	.L20
.L31:
	leaq	.LC0(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB13419:
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
	je	.L51
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L49
	testq	%rax, %rax
	jne	.L42
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L48:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L52
	testq	%r9, %r9
	jg	.L44
	testq	%r13, %r13
	jne	.L47
.L45:
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
.L52:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L44
.L47:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L44:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L45
	jmp	.L47
	.p2align 4,,10
	.p2align 3
.L49:
	movabsq	$9223372036854775804, %rbx
.L41:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L48
	.p2align 4,,10
	.p2align 3
.L42:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L41
.L51:
	leaq	.LC1(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "NO\0"
.LC3:
	.ascii "YES\0"
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
	subq	$344, %rsp
	.seh_stackalloc	344
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	132(%rsp), %rdx
	movq	$0, 232(%rax)
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	132(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 132(%rsp)
	testl	%eax, %eax
	je	.L109
	leaq	136(%rsp), %rax
	movl	$15, %r15d
	movq	%rax, 120(%rsp)
	leaq	208(%rsp), %rax
	movq	%rax, 104(%rsp)
	leaq	224(%rsp), %rax
	movq	%rax, 80(%rsp)
	leaq	256(%rsp), %rax
	movq	%rax, 88(%rsp)
	leaq	240(%rsp), %rax
	movq	%rax, 112(%rsp)
.L54:
	movq	120(%rsp), %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
.LEHE0:
	movq	80(%rsp), %rax
	movq	104(%rsp), %rdx
	movq	$0, 216(%rsp)
	movq	.refptr._ZSt3cin(%rip), %rcx
	movb	$0, 224(%rsp)
	movq	%rax, 208(%rsp)
	movq	88(%rsp), %rax
	movq	$0, 248(%rsp)
	movq	%rax, 240(%rsp)
	movb	$0, 256(%rsp)
.LEHB1:
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	112(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$4, %ecx
	movq	$0, 152(%rsp)
	movq	$0, 160(%rsp)
	call	_Znwy
.LEHE1:
	movl	$0, (%rax)
	leaq	4(%rax), %rdx
	movl	$4, %ecx
	movq	%rax, 144(%rsp)
	movq	%rdx, 160(%rsp)
	movq	%rdx, 152(%rsp)
	movq	$0, 184(%rsp)
	movq	$0, 192(%rsp)
.LEHB2:
	call	_Znwy
.LEHE2:
	leaq	4(%rax), %rdx
	movq	%rax, 176(%rsp)
	movl	$0, (%rax)
	leaq	288(%rsp), %rax
	movq	%rax, 48(%rsp)
	movq	%rax, 272(%rsp)
	leaq	320(%rsp), %rax
	movq	%rax, 56(%rsp)
	movq	%rax, 304(%rsp)
	movl	136(%rsp), %eax
	movq	%rdx, 192(%rsp)
	movq	%rdx, 184(%rsp)
	movq	$0, 280(%rsp)
	movb	$0, 288(%rsp)
	movq	$0, 312(%rsp)
	movb	$0, 320(%rsp)
	testl	%eax, %eax
	jle	.L87
	leaq	140(%rsp), %rax
	xorl	%ebx, %ebx
	movq	%rax, 96(%rsp)
	leaq	144(%rsp), %rax
	movq	%rax, 72(%rsp)
	jmp	.L68
	.p2align 4,,10
	.p2align 3
.L115:
	movq	280(%rsp), %rdi
	movq	272(%rsp), %rax
	movq	%r15, %rdx
	cmpq	48(%rsp), %rax
	cmovne	288(%rsp), %rdx
	leaq	1(%rdi), %rbp
	cmpq	%rdx, %rbp
	ja	.L112
.L58:
	movb	%sil, (%rax,%rdi)
	movq	272(%rsp), %rax
	movq	%rbp, 280(%rsp)
	movq	152(%rsp), %rdx
	movb	$0, 1(%rax,%rdi)
	movl	$0, 140(%rsp)
	cmpq	160(%rsp), %rdx
	je	.L59
	movl	$0, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 152(%rsp)
.L61:
	movq	240(%rsp), %rax
	movzbl	(%rax,%rbx), %esi
	cmpb	$98, %sil
	je	.L62
	movq	312(%rsp), %rdi
	movq	304(%rsp), %rax
	movq	%r15, %rdx
	cmpq	56(%rsp), %rax
	cmovne	320(%rsp), %rdx
	leaq	1(%rdi), %rbp
	cmpq	%rdx, %rbp
	ja	.L113
.L64:
	movb	%sil, (%rax,%rdi)
	movq	304(%rsp), %rax
	movq	%rbp, 312(%rsp)
	movq	184(%rsp), %rdx
	movb	$0, 1(%rax,%rdi)
	movl	$0, 140(%rsp)
	cmpq	192(%rsp), %rdx
	je	.L65
	movl	$0, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 184(%rsp)
.L67:
	addq	$1, %rbx
	cmpl	%ebx, 136(%rsp)
	jle	.L114
.L68:
	movq	208(%rsp), %rax
	movzbl	(%rax,%rbx), %esi
	cmpb	$98, %sil
	jne	.L115
	movq	152(%rsp), %rax
	addl	$1, -4(%rax)
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L62:
	movq	184(%rsp), %rax
	addq	$1, %rbx
	addl	$1, -4(%rax)
	cmpl	%ebx, 136(%rsp)
	jg	.L68
.L114:
	movq	272(%rsp), %rbx
	movq	280(%rsp), %r8
	movq	304(%rsp), %rdx
	cmpq	312(%rsp), %r8
	je	.L116
.L69:
	movl	$2, %r8d
	leaq	.LC2(%rip), %rdx
.L72:
	movq	.refptr._ZSt4cout(%rip), %rbx
	leaq	144(%rsp), %rax
	leaq	272(%rsp), %r13
	movq	%rax, 64(%rsp)
	leaq	304(%rsp), %r12
	leaq	176(%rsp), %r14
	movq	%rbx, %rcx
.LEHB3:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	144(%rsp), %rax
	leaq	140(%rsp), %rdx
	movq	%rbx, %rcx
	movl	$1, %r8d
	movb	$10, 140(%rsp)
	leaq	272(%rsp), %r13
	leaq	304(%rsp), %r12
	movq	%rax, 64(%rsp)
	leaq	176(%rsp), %r14
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	304(%rsp), %rcx
	cmpq	56(%rsp), %rcx
	je	.L76
	movq	320(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L76:
	movq	272(%rsp), %rcx
	cmpq	48(%rsp), %rcx
	je	.L77
	movq	288(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L77:
	movq	176(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L78
	movq	192(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L78:
	movq	144(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L79
	movq	160(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L79:
	movq	240(%rsp), %rcx
	cmpq	88(%rsp), %rcx
	je	.L80
	movq	256(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L80:
	movq	208(%rsp), %rcx
	cmpq	80(%rsp), %rcx
	je	.L81
	movq	224(%rsp), %rax
	leaq	1(%rax), %rdx
	call	_ZdlPvy
.L81:
	movl	132(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 132(%rsp)
	testl	%eax, %eax
	jne	.L54
.L109:
	xorl	%eax, %eax
	addq	$344, %rsp
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
.L113:
	movq	72(%rsp), %rax
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movq	%rdi, %rdx
	leaq	304(%rsp), %r12
	leaq	272(%rsp), %r13
	movq	$1, 32(%rsp)
	movq	%r12, %rcx
	movq	%rax, 64(%rsp)
	leaq	176(%rsp), %r14
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	movq	304(%rsp), %rax
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L112:
	movq	72(%rsp), %rax
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movq	%rdi, %rdx
	leaq	272(%rsp), %r13
	leaq	304(%rsp), %r12
	movq	$1, 32(%rsp)
	movq	%r13, %rcx
	movq	%rax, 64(%rsp)
	leaq	176(%rsp), %r14
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEyyPKcy
	movq	272(%rsp), %rax
	jmp	.L58
	.p2align 4,,10
	.p2align 3
.L59:
	movq	72(%rsp), %rcx
	movq	96(%rsp), %r8
	leaq	272(%rsp), %r13
	leaq	304(%rsp), %r12
	leaq	176(%rsp), %r14
	movq	%rcx, 64(%rsp)
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L65:
	movq	72(%rsp), %rax
	leaq	176(%rsp), %r14
	movq	96(%rsp), %r8
	leaq	272(%rsp), %r13
	movq	%r14, %rcx
	leaq	304(%rsp), %r12
	movq	%rax, 64(%rsp)
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE3:
	jmp	.L67
.L116:
	testq	%r8, %r8
	je	.L55
	movq	%rbx, %rcx
	call	memcmp
	testl	%eax, %eax
	jne	.L69
.L55:
	movq	144(%rsp), %rcx
	movq	152(%rsp), %rax
	subq	%rcx, %rax
	sarq	$2, %rax
	cmpl	$1, %eax
	jle	.L111
	leal	-2(%rax), %r9d
	movq	176(%rsp), %r8
	xorl	%eax, %eax
	xorl	%edx, %edx
	jmp	.L75
	.p2align 4,,10
	.p2align 3
.L117:
	cmpb	$97, (%rbx,%rax)
	je	.L69
.L74:
	leaq	1(%rax), %r10
	cmpq	%r9, %rax
	je	.L111
.L90:
	movq	%r10, %rax
.L75:
	addl	(%rcx,%rax,4), %edx
	subl	(%r8,%rax,4), %edx
	testl	%edx, %edx
	jg	.L117
	je	.L74
	cmpb	$99, (%rbx,%rax)
	je	.L69
	leaq	1(%rax), %r10
	cmpq	%r9, %rax
	jne	.L90
.L111:
	movl	$3, %r8d
	leaq	.LC3(%rip), %rdx
	jmp	.L72
.L87:
	movq	48(%rsp), %rbx
	jmp	.L55
.L93:
	movq	%r12, %rcx
	movq	%rax, %rbx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r13, %rcx
	movq	%rbx, %r12
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r14, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L84:
	movq	64(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L85:
	movq	112(%rsp), %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	104(%rsp), %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	%r12, %rcx
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
.L92:
	movq	%rax, %r12
	leaq	144(%rsp), %rax
	movq	%rax, 64(%rsp)
	jmp	.L84
.L91:
	movq	%rax, %r12
	jmp	.L85
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
	.uleb128 .L91-.LFB11909
	.uleb128 0
	.uleb128 .LEHB2-.LFB11909
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L92-.LFB11909
	.uleb128 0
	.uleb128 .LEHB3-.LFB11909
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L93-.LFB11909
	.uleb128 0
	.uleb128 .LEHB4-.LFB11909
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE11909:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB13915:
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
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	memcmp;	.scl	2;	.type	32;	.endef
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
