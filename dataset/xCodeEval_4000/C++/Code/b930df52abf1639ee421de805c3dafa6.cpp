__asm__(R"(
	.file	"C.cpp"
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
.LFB8684:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
.LFB8316:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	%rcx, %rbx
	testl	%r8d, %r8d
	je	.L5
	cmpl	$1, %r8d
	je	.L6
	cmpl	$2, %r8d
	je	.L9
	cmpl	$3, %r8d
	jne	.L8
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L8
	movl	$40, %edx
	call	_ZdlPvy
.L8:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L5:
	leaq	_ZTIZ8solutionvEUliiE_(%rip), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movq	(%rdx), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movq	(%rdx), %rsi
	movl	$40, %ecx
	call	_Znwy
	movdqu	(%rsi), %xmm0
	movups	%xmm0, (%rax)
	movdqu	16(%rsi), %xmm1
	movups	%xmm1, 16(%rax)
	movq	32(%rsi), %rdx
	movq	%rdx, 32(%rax)
	movq	%rax, (%rbx)
	jmp	.L8
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "C.cpp\0"
.LC1:
	.ascii "false\0"
	.text
	.align 2
	.p2align 4
	.def	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii:
.LFB8116:
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
	movq	16(%rdx), %rbp
	movl	%r9d, %ebx
	movq	(%rcx), %r9
	movq	%rcx, %rsi
	movslq	%r8d, %r8
	movq	%rdx, %rdi
	leaq	(%r8,%r8,2), %rdx
	movl	(%r9), %eax
	cmpl	%eax, %ebx
	cmovge	%ebx, %eax
	movl	%eax, (%r9)
	movl	%eax, %ecx
	movq	8(%rsi), %rax
	movq	(%rax), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	cmpq	%rdx, %rax
	je	.L15
	movq	%rdx, %r8
	subq	%rax, %r8
	cmpq	$4, %r8
	je	.L25
	cmpq	$8, %r8
	je	.L26
.L18:
	movl	$128, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	addq	$136, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	rex.W jmp	*__imp__assert(%rip)
	.p2align 4,,10
	.p2align 3
.L26:
	movslq	(%rax), %r13
	movq	16(%rsi), %rax
	movq	%rbp, 112(%rsp)
	movslq	-4(%rdx), %r15
	movq	(%rdi), %r14
	movq	(%rax), %rcx
	movq	8(%rdi), %r10
	leaq	0(%r13,%r13,2), %r8
	movl	(%r14), %eax
	movdqu	(%rdi), %xmm0
	movl	(%rcx,%r15,4), %r12d
	movq	(%r10), %rdx
	movaps	%xmm0, 96(%rsp)
	addl	%ebx, %r12d
	leaq	(%rdx,%r8,8), %r8
	subl	$1, %r12d
	movq	8(%r8), %r9
	movq	(%r8), %r8
	cmpl	%eax, %r12d
	cmovge	%r12d, %eax
	movl	%eax, (%r14)
	cmpq	%r8, %r9
	je	.L19
	movq	%r9, %r11
	subq	%r8, %r11
	cmpq	$4, %r11
	je	.L27
	cmpq	$8, %r11
	je	.L28
	movq	%r10, 32(%rsp)
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	movl	$128, %r8d
	call	*__imp__assert(%rip)
	movq	16(%rsi), %rax
	movq	32(%rsp), %r10
	movdqu	(%rdi), %xmm0
	movq	(%rax), %rcx
	movq	(%r10), %rdx
	movl	(%r14), %eax
.L19:
	addl	(%rcx,%r13,4), %ebx
	leaq	(%r15,%r15,2), %rcx
	movq	16(%rdi), %r9
	movaps	%xmm0, 96(%rsp)
	subl	$1, %ebx
	leaq	(%rdx,%rcx,8), %rdx
	cmpl	%ebx, %eax
	movq	8(%rdx), %rcx
	movq	(%rdx), %rdx
	movq	%r9, 112(%rsp)
	cmovl	%ebx, %eax
	movl	%eax, (%r14)
	cmpq	%rdx, %rcx
	je	.L15
	movq	%rcx, %r8
	subq	%rdx, %r8
	cmpq	$4, %r8
	je	.L29
	cmpq	$8, %r8
	jne	.L18
	movslq	(%rdx), %rsi
	movq	0(%rbp), %rax
	leaq	64(%rsp), %r13
	leaq	96(%rsp), %r12
	movslq	-4(%rcx), %rdx
	movq	%r9, 80(%rsp)
	movl	%esi, %r8d
	movaps	%xmm0, 64(%rsp)
	movl	(%rax,%rdx,4), %ecx
	movq	%rdx, %rdi
	movq	%r13, %rdx
	addl	%ebx, %ecx
	leal	-1(%rcx), %r9d
	movq	%r12, %rcx
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	movq	112(%rsp), %rax
	movl	%edi, %r8d
	movq	%r13, %rdx
	movdqa	96(%rsp), %xmm2
	movq	%r12, %rcx
	movq	%rax, 80(%rsp)
	movq	0(%rbp), %rax
	movaps	%xmm2, 64(%rsp)
	addl	(%rax,%rsi,4), %ebx
	leal	-1(%rbx), %r9d
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	nop
.L15:
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
	.p2align 4,,10
	.p2align 3
.L25:
	movq	16(%rsi), %r8
	movslq	(%rax), %rdx
	movq	(%r8), %rax
	addl	(%rax,%rdx,4), %ebx
	subl	$1, %ebx
	cmpl	%ecx, %ebx
	cmovl	%ecx, %ebx
	movl	%ebx, (%r9)
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L28:
	movslq	-4(%r9), %rcx
	movq	0(%rbp), %rdx
	movq	%r10, 56(%rsp)
	movl	(%r8), %r8d
	movaps	%xmm0, 64(%rsp)
	movl	(%rdx,%rcx,4), %r9d
	movl	%ecx, 52(%rsp)
	leaq	64(%rsp), %rdx
	leaq	96(%rsp), %rcx
	movl	%r8d, 48(%rsp)
	addl	%r12d, %r9d
	movq	%rdx, 40(%rsp)
	subl	$1, %r9d
	movq	%rcx, 32(%rsp)
	movq	%rbp, 80(%rsp)
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	movq	112(%rsp), %r9
	movslq	48(%rsp), %r8
	movdqa	96(%rsp), %xmm1
	movq	40(%rsp), %rdx
	movq	%r9, 80(%rsp)
	movq	0(%rbp), %r9
	movq	32(%rsp), %rcx
	movaps	%xmm1, 64(%rsp)
	addl	(%r9,%r8,4), %r12d
	movl	52(%rsp), %r8d
	leal	-1(%r12), %r9d
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	movq	16(%rsi), %rax
	movq	56(%rsp), %r10
	movdqu	(%rdi), %xmm0
	movq	(%rax), %rcx
	movq	(%r10), %rdx
	movl	(%r14), %eax
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L29:
	movslq	(%rdx), %rcx
	movq	0(%rbp), %rdx
	addl	(%rdx,%rcx,4), %ebx
	subl	$1, %ebx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	%ebx, (%r14)
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L27:
	movslq	(%r8), %r9
	movq	0(%rbp), %r8
	addl	(%r8,%r9,4), %r12d
	subl	$1, %r12d
	cmpl	%r12d, %eax
	cmovl	%r12d, %eax
	movl	%eax, (%r14)
	jmp	.L19
	.seh_endproc
	.section	.text$_ZNSt14_Function_baseD2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt14_Function_baseD2Ev
	.def	_ZNSt14_Function_baseD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt14_Function_baseD2Ev
_ZNSt14_Function_baseD2Ev:
.LFB2753:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	16(%rcx), %rax
	testq	%rax, %rax
	je	.L30
	movl	$3, %r8d
	movq	%rcx, %rdx
	call	*%rax
	nop
.L30:
	addq	$40, %rsp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2753:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2753-.LLSDACSB2753
.LLSDACSB2753:
.LLSDACSE2753:
	.section	.text$_ZNSt14_Function_baseD2Ev,"x"
	.linkonce discard
	.seh_endproc
	.text
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
	je	.L40
	cmpb	$0, 56(%r12)
	je	.L37
	movsbl	67(%r12), %edx
.L38:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L37:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L38
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L38
.L40:
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
	.section	.text$_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	.def	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev:
.LFB8087:
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
	je	.L43
	.p2align 4,,10
	.p2align 3
.L45:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L44
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L44:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L45
	movq	(%rsi), %r12
.L43:
	testq	%r12, %r12
	je	.L42
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
.L42:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB8290:
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
	je	.L65
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L63
	testq	%rax, %rax
	jne	.L56
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L62:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L66
	testq	%r9, %r9
	jg	.L58
	testq	%r13, %r13
	jne	.L61
.L59:
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
.L66:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L58
.L61:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L58:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L59
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L63:
	movabsq	$9223372036854775804, %rbx
.L55:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L56:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L55
.L65:
	leaq	.LC2(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.text
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_
_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_:
.LFB8312:
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
	subq	$88, %rsp
	.seh_stackalloc	88
	.seh_endprologue
	movq	(%rcx), %r12
	movslq	(%rdx), %rax
	movl	(%r8), %esi
	movq	(%r12), %rdx
	leaq	(%rax,%rax,2), %rbp
	leaq	0(,%rax,4), %rbx
	movq	(%rdx), %rdx
	movl	%eax, 44(%rsp)
	leaq	76(%rsp), %r14
	leaq	72(%rsp), %r13
	movl	$1, (%rdx,%rax,4)
	movq	8(%r12), %rdx
	movq	(%rdx), %rcx
	movslq	%esi, %rdx
	movl	(%rcx,%rdx,4), %edx
	addl	$1, %edx
	movl	%edx, (%rcx,%rax,4)
	leaq	0(,%rbp,8), %rax
	movq	%rax, %rdi
	movq	%rax, 48(%rsp)
	movq	16(%r12), %rax
	addq	(%rax), %rdi
	movq	%rdi, %rax
	movq	8(%rdi), %rdi
	movq	(%rax), %r15
	leaq	68(%rsp), %rax
	movq	%rax, 56(%rsp)
	cmpq	%rdi, %r15
	jne	.L73
	jmp	.L67
	.p2align 4,,10
	.p2align 3
.L78:
	movl	%ebp, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L71:
	movq	32(%r12), %rcx
	movl	44(%rsp), %eax
	movl	%ebp, 72(%rsp)
	cmpq	$0, 16(%rcx)
	movl	%eax, 76(%rsp)
	je	.L77
	movq	%r13, %rdx
	movq	%r14, %r8
	call	*24(%rcx)
	movq	(%r12), %rdx
	movslq	%ebp, %rax
	movq	(%rdx), %rdx
	movl	(%rdx,%rax,4), %eax
	addl	%eax, (%rdx,%rbx)
.L69:
	addq	$4, %r15
	cmpq	%r15, %rdi
	je	.L67
.L73:
	movl	(%r15), %ebp
	movl	%ebp, 68(%rsp)
	cmpl	%ebp, %esi
	je	.L69
	movq	24(%r12), %rdx
	movq	48(%rsp), %rcx
	addq	(%rdx), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	jne	.L78
	movq	56(%rsp), %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	68(%rsp), %ebp
	jmp	.L71
	.p2align 4,,10
	.p2align 3
.L67:
	addq	$88, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L77:
	call	_ZSt25__throw_bad_function_callv
	nop
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	_ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseIiSaIiEED2Ev
_ZNSt12_Vector_baseIiSaIiEED2Ev:
.LFB8302:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L79
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L79:
	ret
	.seh_endproc
	.section	.text$_Z6qprintIiEvT_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6qprintIiEvT_
	.def	_Z6qprintIiEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6qprintIiEvT_
_Z6qprintIiEvT_:
.LFB8322:
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
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	%ecx, %ebx
	testl	%ecx, %ecx
	js	.L90
.L82:
	movl	%ebx, %edi
	cmpl	$9, %ebx
	jg	.L87
.L88:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%rdi, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	jmp	_ZNSo3putEc
	.p2align 4,,10
	.p2align 3
.L87:
	movl	$3435973837, %ecx
	movq	%rdi, %rsi
	imulq	%rcx, %rsi
	shrq	$35, %rsi
	movl	%esi, %r13d
	cmpl	$99, %ebx
	jg	.L85
.L86:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%r13, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L90:
	movl	$45, %edx
	movq	%r12, %rcx
	negl	%ebx
	call	_ZNSo3putEc
	jmp	.L82
	.p2align 4,,10
	.p2align 3
.L85:
	movq	%r13, %rbp
	imulq	%rcx, %rbp
	shrq	$35, %rbp
	movl	%ebp, %r14d
	cmpl	$999, %ebx
	jg	.L83
.L84:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%r14, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebp
	leal	48(%rbp), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L83:
	imulq	%r14, %rcx
	shrq	$35, %rcx
	call	_Z6qprintIiEvT_
	jmp	.L84
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC3:
	.ascii "cannot create std::vector larger than max_size()\0"
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
	subq	$344, %rsp
	.seh_stackalloc	344
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rbx
	movq	%rbx, %rcx
	leaq	96(%rsp), %rdx
.LEHB0:
	call	_ZNSirsERi
	movl	96(%rsp), %edx
	movabsq	$384307168202282325, %rcx
	leal	1(%rdx), %eax
	cltq
	cmpq	%rcx, %rax
	ja	.L208
	movq	$0, 112(%rsp)
	leaq	(%rax,%rax,2), %rsi
	movq	$0, 120(%rsp)
	salq	$3, %rsi
	movq	$0, 128(%rsp)
	testq	%rax, %rax
	je	.L93
	movq	%rsi, %rcx
	call	_Znwy
.LEHE0:
	leaq	(%rax,%rsi), %rdx
	movq	%rax, 112(%rsp)
	movq	%rdx, 128(%rsp)
	.p2align 4,,10
	.p2align 3
.L94:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L94
	movl	96(%rsp), %edx
	movq	%rax, 120(%rsp)
	movabsq	$384307168202282325, %rax
	leal	1(%rdx), %r9d
	movl	%edx, %ecx
	movslq	%r9d, %r9
	cmpq	%rax, %r9
	ja	.L209
	movq	$0, 144(%rsp)
	leaq	(%r9,%r9,2), %r8
	movq	$0, 152(%rsp)
	leaq	0(,%r8,8), %rsi
	movq	$0, 160(%rsp)
	testq	%r9, %r9
	je	.L96
	movq	%rsi, %rcx
.LEHB1:
	call	_Znwy
.LEHE1:
	leaq	(%rax,%rsi), %r8
	movl	96(%rsp), %edx
	movq	%rax, 144(%rsp)
	movq	%r8, 160(%rsp)
	movl	%edx, %ecx
	.p2align 4,,10
	.p2align 3
.L97:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%r8, %rax
	jne	.L97
.L152:
	movq	%r8, 152(%rsp)
	cmpl	$1, %ecx
	jle	.L98
	movl	$1, %r13d
	movl	$1, %r12d
	movl	$48, %r14d
	leaq	304(%rsp), %r15
	.p2align 4,,10
	.p2align 3
.L113:
	movl	$0, 272(%rsp)
	movq	%rbx, %rcx
.LEHB2:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L99
	.p2align 4,,10
	.p2align 3
.L101:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L101
.L99:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L102:
	leal	(%rsi,%rsi,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %ebp
	leal	-48(%rbp), %esi
	movl	%esi, 272(%rsp)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L102
	testb	%dil, %dil
	je	.L103
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 272(%rsp)
.L103:
	movl	$0, 304(%rsp)
	movq	%rbx, %rcx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L104
	.p2align 4,,10
	.p2align 3
.L106:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L106
.L104:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L107:
	leal	(%rsi,%rsi,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %ebp
	leal	-48(%rbp), %esi
	movl	%esi, 304(%rsp)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L107
	testb	%dil, %dil
	je	.L108
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 304(%rsp)
.L108:
	movslq	272(%rsp), %rax
	movq	112(%rsp), %r8
	movq	%rax, %rsi
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L109
	movslq	304(%rsp), %rax
	addq	$4, %rdx
	movl	%eax, -4(%rdx)
	movq	%rdx, 8(%rcx)
.L110:
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L111
	movl	%esi, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L112:
	movl	96(%rsp), %edx
	addl	$1, %r13d
	movl	%edx, %ecx
	cmpl	%r13d, %edx
	jg	.L113
.L98:
	leal	1(%rcx), %eax
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L210
	movq	$0, 176(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 184(%rsp)
	movq	$0, 192(%rsp)
	testq	%rax, %rax
	je	.L115
	movq	%rsi, %rcx
	call	_Znwy
.LEHE2:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 176(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 192(%rsp)
	cmpq	%rax, %rbx
	je	.L204
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L204:
	movl	96(%rsp), %edx
.L116:
	leal	1(%rdx), %eax
	movq	%rbx, 184(%rsp)
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L211
	movq	$0, 208(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 216(%rsp)
	movq	$0, 224(%rsp)
	testq	%rax, %rax
	je	.L118
	movq	%rsi, %rcx
.LEHB3:
	call	_Znwy
.LEHE3:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 208(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 224(%rsp)
	cmpq	%rax, %rbx
	je	.L119
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L119:
	movl	$40, %ecx
	movq	%rbx, 216(%rsp)
	movq	$0, 320(%rsp)
.LEHB4:
	call	_Znwy
.LEHE4:
	leaq	304(%rsp), %r12
	leaq	176(%rsp), %r13
	movq	%rax, 304(%rsp)
	leaq	112(%rsp), %r15
	movq	%r13, (%rax)
	leaq	104(%rsp), %rdx
	movq	%r12, %rcx
	leaq	208(%rsp), %rbp
	leaq	144(%rsp), %r14
	movq	%r15, 16(%rax)
	movq	%rbp, 8(%rax)
	leaq	108(%rsp), %r8
	movq	%r14, 24(%rax)
	movq	%r12, 32(%rax)
	leaq	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_(%rip), %rax
	movq	%rax, 328(%rsp)
	leaq	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rax, 320(%rsp)
	movl	$1, 104(%rsp)
	movl	$1, 108(%rsp)
.LEHB5:
	call	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_
	movq	144(%rsp), %rax
	movl	$0, 100(%rsp)
	movq	32(%rax), %rcx
	movq	24(%rax), %rdx
	cmpq	%rdx, %rcx
	je	.L156
	movq	%rcx, %r8
	subq	%rdx, %r8
	cmpq	$4, %r8
	je	.L212
	cmpq	$8, %r8
	je	.L213
.L126:
	movl	$128, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	*__imp__assert(%rip)
.L206:
	movl	100(%rsp), %ebx
.L133:
	testl	%ebx, %ebx
	js	.L214
.L125:
	cmpl	$9, %ebx
	jg	.L151
	movq	.refptr._ZSt4cout(%rip), %rsi
	movl	%ebx, %edi
.L123:
	movl	$3435973837, %eax
	movq	%rsi, %rcx
	imulq	%rdi, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	movl	$32, %edx
	movq	%rsi, %rcx
	call	_ZNSo3putEc
	movl	$10, %edx
	movq	%rsi, %rcx
	call	_ZNSo3putEc
.LEHE5:
	movq	320(%rsp), %rax
	testq	%rax, %rax
	je	.L134
	movl	$3, %r8d
	movq	%r12, %rdx
	movq	%r12, %rcx
	call	*%rax
.L134:
	movq	208(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L135
	movq	224(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L135:
	movq	176(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L136
	movq	192(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L136:
	movq	152(%rsp), %rbx
	movq	144(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L137
	.p2align 4,,10
	.p2align 3
.L139:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L138
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L138:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L139
	movq	144(%rsp), %r12
.L137:
	testq	%r12, %r12
	je	.L140
	movq	160(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
.L140:
	movq	120(%rsp), %rbx
	movq	112(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L141
	.p2align 4,,10
	.p2align 3
.L143:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L142
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L142:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L143
	movq	112(%rsp), %r12
.L141:
	testq	%r12, %r12
	je	.L91
	movq	128(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
	nop
.L91:
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
.L111:
	leaq	272(%rsp), %r8
.LEHB6:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L112
	.p2align 4,,10
	.p2align 3
.L109:
	movq	%r15, %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE6:
	movslq	304(%rsp), %rax
	movq	112(%rsp), %r8
	jmp	.L110
.L115:
	movq	$0, 176(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 192(%rsp)
	jmp	.L116
.L118:
	movq	$0, 208(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 224(%rsp)
	jmp	.L119
.L151:
	movl	%ebx, %edi
	movl	$3435973837, %eax
	movq	%rdi, %rsi
	imulq	%rax, %rsi
	shrq	$35, %rsi
	cmpl	$99, %ebx
	jg	.L149
	movl	%esi, %eax
	movq	%rax, 32(%rsp)
.L150:
	movl	$3435973837, %eax
	imulq	32(%rsp), %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	leal	48(%rsi), %edx
	movq	.refptr._ZSt4cout(%rip), %rsi
	movzbl	%dl, %edx
	movq	%rsi, %rcx
.LEHB7:
	call	_ZNSo3putEc
	jmp	.L123
.L212:
	movslq	(%rdx), %rdx
	movq	176(%rsp), %rax
	movl	(%rax,%rdx,4), %ebx
	subl	$1, %ebx
	testl	%ebx, %ebx
	jg	.L215
.L156:
	movq	.refptr._ZSt4cout(%rip), %rsi
	xorl	%ebx, %ebx
	xorl	%edi, %edi
	jmp	.L123
.L214:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negl	%ebx
	jmp	.L125
.L149:
	movl	%esi, %ecx
	imulq	%rcx, %rax
	movq	%rcx, 32(%rsp)
	shrq	$35, %rax
	movq	%rax, %rcx
	call	_Z6qprintIiEvT_
	jmp	.L150
.L213:
	movslq	-4(%rcx), %rdi
	movq	176(%rsp), %rcx
	movq	%r14, 248(%rsp)
	movl	(%rdx), %r8d
	xorl	%edx, %edx
	movq	%r13, 256(%rsp)
	movl	(%rcx,%rdi,4), %ebx
	leal	-1(%rbx), %esi
	leaq	100(%rsp), %rbx
	movq	%rbx, 40(%rsp)
	testl	%esi, %esi
	movq	%rbx, 240(%rsp)
	movslq	%r8d, %rbx
	cmovns	%esi, %edx
	leaq	(%rbx,%rbx,2), %r8
	leaq	(%rax,%r8,8), %r8
	movl	%edx, 100(%rsp)
	movq	8(%r8), %r9
	movq	(%r8), %r8
	cmpq	%r8, %r9
	je	.L127
	movq	%r9, %r10
	subq	%r8, %r10
	cmpq	$4, %r10
	je	.L216
	cmpq	$8, %r10
	je	.L217
	movl	$128, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	*__imp__assert(%rip)
.L205:
	movq	176(%rsp), %rcx
	movl	100(%rsp), %edx
	movq	144(%rsp), %rax
.L127:
	movl	(%rcx,%rbx,4), %esi
	movq	40(%rsp), %rbx
	movq	%r14, 280(%rsp)
	movq	%r13, 288(%rsp)
	subl	$1, %esi
	movq	%rbx, 272(%rsp)
	movl	%edx, %ebx
	cmpl	%esi, %edx
	leaq	(%rdi,%rdi,2), %rdx
	leaq	(%rax,%rdx,8), %rax
	cmovl	%esi, %ebx
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movl	%ebx, 100(%rsp)
	cmpq	%rax, %rdx
	je	.L133
	movq	%rdx, %r8
	subq	%rax, %r8
	cmpq	$4, %r8
	je	.L218
	cmpq	$8, %r8
	jne	.L126
	movdqa	272(%rsp), %xmm2
	movl	(%rax), %r11d
	movslq	-4(%rdx), %rax
	movq	%r13, 80(%rsp)
	movl	%r11d, %r8d
	movl	%r11d, 40(%rsp)
	movl	(%rcx,%rax,4), %ebx
	movq	%rax, %rdi
	leaq	64(%rsp), %rcx
	movaps	%xmm2, 64(%rsp)
	movq	%rcx, 32(%rsp)
	movq	%rcx, %rdx
	addl	%esi, %ebx
	movl	%ebx, %eax
	leaq	272(%rsp), %rbx
	leal	-1(%rax), %r9d
	movq	%rbx, %rcx
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	movq	288(%rsp), %rax
	movq	176(%rsp), %rdx
	movl	%edi, %r8d
	movq	%rbx, %rcx
	movdqa	272(%rsp), %xmm3
	movq	%rax, 80(%rsp)
	movslq	40(%rsp), %rax
	movaps	%xmm3, 64(%rsp)
	addl	(%rdx,%rax,4), %esi
	movq	32(%rsp), %rdx
	movl	%esi, %r9d
	subl	$1, %r9d
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	jmp	.L206
.L93:
	movq	$0, 112(%rsp)
	movl	$-1, %ecx
	movq	$0, 128(%rsp)
	movq	$0, 120(%rsp)
.L96:
	movq	$0, 144(%rsp)
	xorl	%r8d, %r8d
	movq	$0, 160(%rsp)
	jmp	.L152
.L215:
	movl	%ebx, 100(%rsp)
	jmp	.L125
.L217:
	movslq	-4(%r9), %rax
	movl	(%r8), %edx
	movq	%r13, 80(%rsp)
	movdqa	240(%rsp), %xmm0
	movl	(%rcx,%rax,4), %r11d
	movl	%eax, 52(%rsp)
	leaq	64(%rsp), %rcx
	movl	%edx, %r8d
	movl	%edx, 48(%rsp)
	movq	%rcx, %rdx
	addl	%esi, %r11d
	movq	%rcx, 32(%rsp)
	movl	%r11d, %eax
	leaq	240(%rsp), %r11
	movaps	%xmm0, 64(%rsp)
	leal	-1(%rax), %r9d
	movq	%r11, %rcx
	movq	%r11, 56(%rsp)
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
	movq	256(%rsp), %rax
	movq	176(%rsp), %rdx
	movdqa	240(%rsp), %xmm1
	movl	52(%rsp), %r8d
	movq	%rax, 80(%rsp)
	movslq	48(%rsp), %rax
	movq	56(%rsp), %rcx
	movaps	%xmm1, 64(%rsp)
	addl	(%rdx,%rax,4), %esi
	movq	32(%rsp), %rdx
	movl	%esi, %r9d
	subl	$1, %r9d
	call	_ZZ8solutionvENKUlT_iiE0_clIS0_EEvS_ii
.LEHE7:
	jmp	.L205
.L218:
	movslq	(%rax), %rax
	addl	(%rcx,%rax,4), %esi
	movl	%esi, %eax
	subl	$1, %eax
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	%ebx, 100(%rsp)
	jmp	.L133
.L216:
	movslq	(%r8), %r8
	addl	(%rcx,%r8,4), %esi
	movl	%esi, %r8d
	subl	$1, %r8d
	cmpl	%r8d, %edx
	cmovl	%r8d, %edx
	movl	%edx, 100(%rsp)
	jmp	.L127
.L210:
	leaq	.LC3(%rip), %rcx
.LEHB8:
	call	_ZSt20__throw_length_errorPKc
.LEHE8:
.L211:
	leaq	.LC3(%rip), %rcx
.LEHB9:
	call	_ZSt20__throw_length_errorPKc
.LEHE9:
.L208:
	leaq	.LC3(%rip), %rcx
.LEHB10:
	call	_ZSt20__throw_length_errorPKc
.LEHE10:
.L209:
	leaq	.LC3(%rip), %rcx
.LEHB11:
	call	_ZSt20__throw_length_errorPKc
.LEHE11:
.L158:
	movq	%rax, %r12
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
.L147:
	movq	%r14, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
.L148:
	movq	%r15, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	movq	%r12, %rcx
.LEHB12:
	call	_Unwind_Resume
.LEHE12:
.L160:
	movq	%rax, %rbx
	movq	%r12, %rcx
	call	_ZNSt14_Function_baseD2Ev
	movq	%rbx, %r12
.L122:
	movq	%rbp, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L146:
	movq	%r13, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	jmp	.L147
.L161:
	leaq	304(%rsp), %rcx
	movq	%rax, %r12
	leaq	176(%rsp), %r13
	call	_ZNSt14_Function_baseD2Ev
	leaq	208(%rsp), %rbp
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
	jmp	.L122
.L159:
	movq	%rax, %r12
	leaq	176(%rsp), %r13
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
	jmp	.L146
.L157:
	movq	%rax, %r12
	leaq	112(%rsp), %r15
	jmp	.L148
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
	.uleb128 .L157-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L158-.LFB7654
	.uleb128 0
	.uleb128 .LEHB3-.LFB7654
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L159-.LFB7654
	.uleb128 0
	.uleb128 .LEHB4-.LFB7654
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L161-.LFB7654
	.uleb128 0
	.uleb128 .LEHB5-.LFB7654
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L160-.LFB7654
	.uleb128 0
	.uleb128 .LEHB6-.LFB7654
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L158-.LFB7654
	.uleb128 0
	.uleb128 .LEHB7-.LFB7654
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L160-.LFB7654
	.uleb128 0
	.uleb128 .LEHB8-.LFB7654
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L158-.LFB7654
	.uleb128 0
	.uleb128 .LEHB9-.LFB7654
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L159-.LFB7654
	.uleb128 0
	.uleb128 .LEHB10-.LFB7654
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB11-.LFB7654
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L157-.LFB7654
	.uleb128 0
	.uleb128 .LEHB12-.LFB7654
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE7654:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "w\0"
.LC5:
	.ascii "testdata.log\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB7664:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movl	$2, %ecx
	call	*__imp___acrt_iob_func(%rip)
	leaq	.LC4(%rip), %rdx
	leaq	.LC5(%rip), %rcx
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
	jmp	.L226
	.p2align 4,,10
	.p2align 3
.L227:
	call	_Z8solutionv
.L226:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L227
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB8685:
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
	.section .rdata,"dr"
	.align 8
_ZTIZ8solutionvEUliiE_:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSZ8solutionvEUliiE_
	.align 16
_ZTSZ8solutionvEUliiE_:
	.ascii "*Z8solutionvEUliiE_\0"
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt4clog, "dr"
	.globl	.refptr._ZSt4clog
	.linkonce	discard
.refptr._ZSt4clog:
	.quad	_ZSt4clog
)");
