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
	.section .rdata,"dr"
.LC0:
	.ascii "C.cpp\0"
.LC1:
	.ascii "son[u].front() != fa\0"
.LC2:
	.ascii "son1 != fa && son2 != fa\0"
.LC3:
	.ascii "false\0"
	.text
	.align 2
	.p2align 4
	.def	_ZZ8solutionvENKUlT_iiiE0_clIS0_EEvS_iii;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZZ8solutionvENKUlT_iiiE0_clIS0_EEvS_iii
_ZZ8solutionvENKUlT_iiiE0_clIS0_EEvS_iii:
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
	subq	$88, %rsp
	.seh_stackalloc	88
	.seh_endprologue
	leaq	.LC0(%rip), %r14
	leaq	.LC2(%rip), %r13
	movl	192(%rsp), %ebx
	movq	%rcx, %rsi
	movq	%rdx, %r12
	movl	%r8d, %ebp
.L10:
	movq	(%rsi), %rcx
	movslq	%ebp, %rdx
	leaq	(%rdx,%rdx,2), %rdi
	movq	8(%rsi), %rdx
	movl	(%rcx), %eax
	movq	(%rdx), %r11
	cmpl	%eax, %ebx
	cmovge	%ebx, %eax
	salq	$3, %rdi
	addq	%rdi, %r11
	movq	8(%r11), %r10
	movq	(%r11), %rdx
	movl	%eax, (%rcx)
	cmpq	%r10, %rdx
	je	.L3
	movq	%r10, %r8
	subq	%rdx, %r8
	cmpq	$4, %r8
	je	.L15
	cmpq	$8, %r8
	jne	.L7
	movslq	(%rdx), %rdi
	movl	-4(%r10), %r15d
	cmpl	%r9d, %edi
	je	.L11
	cmpl	%r9d, %r15d
	je	.L11
.L8:
	movq	16(%r12), %rax
	movslq	%r15d, %rcx
	movl	%ebp, %r9d
	leaq	48(%rsp), %rdx
	movdqu	(%r12), %xmm0
	movl	%edi, %r8d
	movq	%rax, 64(%rsp)
	movaps	%xmm0, 48(%rsp)
	movq	16(%rsi), %rax
	movq	(%rax), %rax
	movl	(%rax,%rcx,4), %r11d
	movq	%r12, %rcx
	addl	%ebx, %r11d
	movl	%r11d, %eax
	subl	$1, %eax
	movl	%eax, 32(%rsp)
	call	_ZZ8solutionvENKUlT_iiiE0_clIS0_EEvS_iii
	movq	16(%rsi), %rax
	movl	%ebp, %r9d
	movq	%r12, %rsi
	movl	%r15d, %ebp
	movq	(%rax), %rax
	addl	(%rax,%rdi,4), %ebx
	subl	$1, %ebx
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L7:
	movl	$128, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	*__imp__assert(%rip)
	nop
.L3:
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
	.p2align 4,,10
	.p2align 3
.L15:
	movslq	(%rdx), %rdx
	cmpl	%r9d, %edx
	je	.L16
.L6:
	movq	16(%rsi), %r8
	movq	(%r8), %r8
	addl	(%r8,%rdx,4), %ebx
	subl	$1, %ebx
	cmpl	%eax, %ebx
	cmovl	%eax, %ebx
	movl	%ebx, (%rcx)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L11:
	movl	$124, %r8d
	movq	%r14, %rdx
	movq	%r13, %rcx
	call	*__imp__assert(%rip)
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L16:
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	movl	$119, %r8d
	call	*__imp__assert(%rip)
	movq	8(%rsi), %rax
	movq	(%rsi), %rcx
	movq	(%rax), %rax
	movq	(%rax,%rdi), %rax
	movslq	(%rax), %rdx
	movl	(%rcx), %eax
	jmp	.L6
	.seh_endproc
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
	je	.L19
	cmpl	$1, %r8d
	je	.L20
	cmpl	$2, %r8d
	je	.L23
	cmpl	$3, %r8d
	jne	.L22
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L22
	movl	$40, %edx
	call	_ZdlPvy
.L22:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L19:
	leaq	_ZTIZ8solutionvEUliiE_(%rip), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L20:
	movq	(%rdx), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L23:
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
	jmp	.L22
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
	je	.L29
	movl	$3, %r8d
	movq	%rcx, %rdx
	call	*%rax
	nop
.L29:
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
	je	.L39
	cmpb	$0, 56(%r12)
	je	.L36
	movsbl	67(%r12), %edx
.L37:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L36:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L37
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L37
.L39:
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
	je	.L42
	.p2align 4,,10
	.p2align 3
.L44:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L43
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L43:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L44
	movq	(%rsi), %r12
.L42:
	testq	%r12, %r12
	je	.L41
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
.L41:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r12
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
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
	je	.L64
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L62
	testq	%rax, %rax
	jne	.L55
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L61:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L65
	testq	%r9, %r9
	jg	.L57
	testq	%r13, %r13
	jne	.L60
.L58:
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
.L65:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L57
.L60:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L58
	.p2align 4,,10
	.p2align 3
.L57:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L58
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L62:
	movabsq	$9223372036854775804, %rbx
.L54:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L55:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L54
.L64:
	leaq	.LC4(%rip), %rcx
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
	jne	.L72
	jmp	.L66
	.p2align 4,,10
	.p2align 3
.L77:
	movl	%ebp, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L70:
	movq	32(%r12), %rcx
	movl	44(%rsp), %eax
	movl	%ebp, 72(%rsp)
	cmpq	$0, 16(%rcx)
	movl	%eax, 76(%rsp)
	je	.L76
	movq	%r13, %rdx
	movq	%r14, %r8
	call	*24(%rcx)
	movq	(%r12), %rdx
	movslq	%ebp, %rax
	movq	(%rdx), %rdx
	movl	(%rdx,%rax,4), %eax
	addl	%eax, (%rdx,%rbx)
.L68:
	addq	$4, %r15
	cmpq	%r15, %rdi
	je	.L66
.L72:
	movl	(%r15), %ebp
	movl	%ebp, 68(%rsp)
	cmpl	%ebp, %esi
	je	.L68
	movq	24(%r12), %rdx
	movq	48(%rsp), %rcx
	addq	(%rdx), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	jne	.L77
	movq	56(%rsp), %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	68(%rsp), %ebp
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L66:
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
.L76:
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
	je	.L78
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L78:
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
	js	.L89
.L81:
	movl	%ebx, %edi
	cmpl	$9, %ebx
	jg	.L86
.L87:
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
.L86:
	movl	$3435973837, %ecx
	movq	%rdi, %rsi
	imulq	%rcx, %rsi
	shrq	$35, %rsi
	movl	%esi, %r13d
	cmpl	$99, %ebx
	jg	.L84
.L85:
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
	jmp	.L87
	.p2align 4,,10
	.p2align 3
.L89:
	movl	$45, %edx
	movq	%r12, %rcx
	negl	%ebx
	call	_ZNSo3putEc
	jmp	.L81
	.p2align 4,,10
	.p2align 3
.L84:
	movq	%r13, %rbp
	imulq	%rcx, %rbp
	shrq	$35, %rbp
	movl	%ebp, %r14d
	cmpl	$999, %ebx
	jg	.L82
.L83:
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
	jmp	.L85
	.p2align 4,,10
	.p2align 3
.L82:
	imulq	%r14, %rcx
	shrq	$35, %rcx
	call	_Z6qprintIiEvT_
	jmp	.L83
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC5:
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
	subq	$312, %rsp
	.seh_stackalloc	312
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
	ja	.L193
	movq	$0, 112(%rsp)
	leaq	(%rax,%rax,2), %rsi
	movq	$0, 120(%rsp)
	salq	$3, %rsi
	movq	$0, 128(%rsp)
	testq	%rax, %rax
	je	.L92
	movq	%rsi, %rcx
	call	_Znwy
.LEHE0:
	leaq	(%rax,%rsi), %rdx
	movq	%rax, 112(%rsp)
	movq	%rdx, 128(%rsp)
	.p2align 4,,10
	.p2align 3
.L93:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L93
	movl	96(%rsp), %edx
	movq	%rax, 120(%rsp)
	movabsq	$384307168202282325, %rax
	leal	1(%rdx), %r9d
	movl	%edx, %ecx
	movslq	%r9d, %r9
	cmpq	%rax, %r9
	ja	.L194
	movq	$0, 144(%rsp)
	leaq	(%r9,%r9,2), %r8
	movq	$0, 152(%rsp)
	leaq	0(,%r8,8), %rsi
	movq	$0, 160(%rsp)
	testq	%r9, %r9
	je	.L95
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
.L96:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%r8, %rax
	jne	.L96
.L142:
	movq	%r8, 152(%rsp)
	cmpl	$1, %ecx
	jle	.L97
	movl	$1, %r13d
	movl	$1, %r12d
	movl	$48, %r14d
	leaq	272(%rsp), %r15
	.p2align 4,,10
	.p2align 3
.L112:
	movl	$0, 240(%rsp)
	movq	%rbx, %rcx
.LEHB2:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L98
	.p2align 4,,10
	.p2align 3
.L100:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L100
.L98:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L101:
	leal	(%rsi,%rsi,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %ebp
	leal	-48(%rbp), %esi
	movl	%esi, 240(%rsp)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L101
	testb	%dil, %dil
	je	.L102
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 240(%rsp)
.L102:
	movl	$0, 272(%rsp)
	movq	%rbx, %rcx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L103
	.p2align 4,,10
	.p2align 3
.L105:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L105
.L103:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L106:
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
	jbe	.L106
	testb	%dil, %dil
	je	.L107
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 272(%rsp)
.L107:
	movslq	240(%rsp), %rax
	movq	112(%rsp), %r8
	movq	%rax, %rsi
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L108
	movslq	272(%rsp), %rax
	addq	$4, %rdx
	movl	%eax, -4(%rdx)
	movq	%rdx, 8(%rcx)
.L109:
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L110
	movl	%esi, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L111:
	movl	96(%rsp), %edx
	addl	$1, %r13d
	movl	%edx, %ecx
	cmpl	%r13d, %edx
	jg	.L112
.L97:
	leal	1(%rcx), %eax
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L195
	movq	$0, 176(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 184(%rsp)
	movq	$0, 192(%rsp)
	testq	%rax, %rax
	je	.L114
	movq	%rsi, %rcx
	call	_Znwy
.LEHE2:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 176(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 192(%rsp)
	cmpq	%rax, %rbx
	je	.L192
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L192:
	movl	96(%rsp), %edx
.L115:
	leal	1(%rdx), %eax
	movq	%rbx, 184(%rsp)
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L196
	movq	$0, 208(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 216(%rsp)
	movq	$0, 224(%rsp)
	testq	%rax, %rax
	je	.L117
	movq	%rsi, %rcx
.LEHB3:
	call	_Znwy
.LEHE3:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 208(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 224(%rsp)
	cmpq	%rax, %rbx
	je	.L118
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L118:
	movl	$40, %ecx
	movq	%rbx, 216(%rsp)
	movq	$0, 288(%rsp)
.LEHB4:
	call	_Znwy
.LEHE4:
	leaq	272(%rsp), %r12
	leaq	176(%rsp), %r13
	movq	%rax, 272(%rsp)
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
	movq	%rax, 296(%rsp)
	leaq	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rax, 288(%rsp)
	movl	$1, 104(%rsp)
	movl	$1, 108(%rsp)
.LEHB5:
	call	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_
	leaq	100(%rsp), %rax
	leaq	64(%rsp), %rdx
	movl	$0, 32(%rsp)
	movl	$1, %r9d
	movq	%rax, 240(%rsp)
	leaq	240(%rsp), %rcx
	movl	$1, %r8d
	movq	%r14, 248(%rsp)
	movdqa	240(%rsp), %xmm0
	movl	$0, 100(%rsp)
	movq	%r13, 256(%rsp)
	movq	%r13, 80(%rsp)
	movaps	%xmm0, 64(%rsp)
	call	_ZZ8solutionvENKUlT_iiiE0_clIS0_EEvS_iii
	movl	100(%rsp), %ebx
	testl	%ebx, %ebx
	js	.L197
.L122:
	cmpl	$9, %ebx
	jg	.L140
	movq	.refptr._ZSt4cout(%rip), %rsi
	movl	%ebx, %edi
.L141:
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
	movq	288(%rsp), %rax
	testq	%rax, %rax
	je	.L123
	movl	$3, %r8d
	movq	%r12, %rdx
	movq	%r12, %rcx
	call	*%rax
.L123:
	movq	208(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L124
	movq	224(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L124:
	movq	176(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L125
	movq	192(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L125:
	movq	152(%rsp), %rbx
	movq	144(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L126
	.p2align 4,,10
	.p2align 3
.L128:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L127
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L127:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L128
	movq	144(%rsp), %r12
.L126:
	testq	%r12, %r12
	je	.L129
	movq	160(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
.L129:
	movq	120(%rsp), %rbx
	movq	112(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L130
	.p2align 4,,10
	.p2align 3
.L132:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L131
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L131:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L132
	movq	112(%rsp), %r12
.L130:
	testq	%r12, %r12
	je	.L90
	movq	128(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
	nop
.L90:
	addq	$312, %rsp
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
.L110:
	leaq	240(%rsp), %r8
.LEHB6:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L111
	.p2align 4,,10
	.p2align 3
.L108:
	movq	%r15, %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE6:
	movslq	272(%rsp), %rax
	movq	112(%rsp), %r8
	jmp	.L109
.L114:
	movq	$0, 176(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 192(%rsp)
	jmp	.L115
.L117:
	movq	$0, 208(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 224(%rsp)
	jmp	.L118
.L140:
	movl	%ebx, %edi
	movl	$3435973837, %eax
	movq	%rdi, %rsi
	imulq	%rax, %rsi
	shrq	$35, %rsi
	cmpl	$99, %ebx
	jg	.L138
	movl	%esi, %eax
	movq	%rax, 56(%rsp)
.L139:
	movl	$3435973837, %eax
	imulq	56(%rsp), %rax
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
	jmp	.L141
.L197:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negl	%ebx
	jmp	.L122
.L138:
	movl	%esi, %ecx
	imulq	%rcx, %rax
	movq	%rcx, 56(%rsp)
	shrq	$35, %rax
	movq	%rax, %rcx
	call	_Z6qprintIiEvT_
.LEHE7:
	jmp	.L139
.L92:
	movq	$0, 112(%rsp)
	movl	$-1, %ecx
	movq	$0, 128(%rsp)
	movq	$0, 120(%rsp)
.L95:
	movq	$0, 144(%rsp)
	xorl	%r8d, %r8d
	movq	$0, 160(%rsp)
	jmp	.L142
.L194:
	leaq	.LC5(%rip), %rcx
.LEHB8:
	call	_ZSt20__throw_length_errorPKc
.LEHE8:
.L195:
	leaq	.LC5(%rip), %rcx
.LEHB9:
	call	_ZSt20__throw_length_errorPKc
.LEHE9:
.L196:
	leaq	.LC5(%rip), %rcx
.LEHB10:
	call	_ZSt20__throw_length_errorPKc
.LEHE10:
.L193:
	leaq	.LC5(%rip), %rcx
.LEHB11:
	call	_ZSt20__throw_length_errorPKc
.L145:
	movq	%rax, %r12
	leaq	112(%rsp), %r15
.L137:
	movq	%r15, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE11:
.L146:
	movq	%rax, %r12
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
	jmp	.L136
.L147:
	movq	%rax, %r12
	leaq	176(%rsp), %r13
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
.L135:
	movq	%r13, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L136:
	movq	%r14, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	jmp	.L137
.L148:
	movq	%rax, %rbx
	movq	%r12, %rcx
	call	_ZNSt14_Function_baseD2Ev
	movq	%rbx, %r12
.L121:
	movq	%rbp, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	jmp	.L135
.L149:
	leaq	272(%rsp), %rcx
	movq	%rax, %r12
	leaq	176(%rsp), %r13
	call	_ZNSt14_Function_baseD2Ev
	leaq	208(%rsp), %rbp
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %r14
	jmp	.L121
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
	.uleb128 .L145-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L146-.LFB7654
	.uleb128 0
	.uleb128 .LEHB3-.LFB7654
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L147-.LFB7654
	.uleb128 0
	.uleb128 .LEHB4-.LFB7654
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L149-.LFB7654
	.uleb128 0
	.uleb128 .LEHB5-.LFB7654
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L148-.LFB7654
	.uleb128 0
	.uleb128 .LEHB6-.LFB7654
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L146-.LFB7654
	.uleb128 0
	.uleb128 .LEHB7-.LFB7654
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L148-.LFB7654
	.uleb128 0
	.uleb128 .LEHB8-.LFB7654
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L145-.LFB7654
	.uleb128 0
	.uleb128 .LEHB9-.LFB7654
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L146-.LFB7654
	.uleb128 0
	.uleb128 .LEHB10-.LFB7654
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L147-.LFB7654
	.uleb128 0
	.uleb128 .LEHB11-.LFB7654
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSE7654:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC6:
	.ascii "w\0"
.LC7:
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
	leaq	.LC6(%rip), %rdx
	leaq	.LC7(%rip), %rcx
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
	jmp	.L205
	.p2align 4,,10
	.p2align 3
.L206:
	call	_Z8solutionv
.L205:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L206
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
