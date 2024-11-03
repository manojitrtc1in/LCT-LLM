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
.LFB8709:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
.LFB8339:
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
	movl	$32, %edx
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
	leaq	_ZTIZ8solutionvEUliiiE0_(%rip), %rax
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
	movl	$32, %ecx
	call	_Znwy
	movdqu	(%rsi), %xmm0
	movups	%xmm0, (%rax)
	movdqu	16(%rsi), %xmm1
	movups	%xmm1, 16(%rax)
	movq	%rax, (%rbx)
	jmp	.L8
	.seh_endproc
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
.LFB8329:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	%rcx, %rbx
	testl	%r8d, %r8d
	je	.L16
	cmpl	$1, %r8d
	je	.L17
	cmpl	$2, %r8d
	je	.L20
	cmpl	$3, %r8d
	jne	.L19
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L19
	movl	$40, %edx
	call	_ZdlPvy
.L19:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	leaq	_ZTIZ8solutionvEUliiE_(%rip), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	movq	(%rdx), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L20:
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
	jmp	.L19
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
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E9_M_invokeERKSt9_Any_dataOiS6_S6_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E9_M_invokeERKSt9_Any_dataOiS6_S6_
_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E9_M_invokeERKSt9_Any_dataOiS6_S6_:
.LFB8336:
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
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	(%rcx), %rbp
	movl	(%r9), %ebx
	movl	(%rdx), %edi
	movl	(%r8), %r10d
	movq	0(%rbp), %r9
	movl	(%r9), %eax
	cmpl	%eax, %ebx
	cmovge	%ebx, %eax
	movl	%eax, (%r9)
	movl	%eax, %ecx
	movslq	%edi, %rax
	leaq	(%rax,%rax,2), %rsi
	movq	8(%rbp), %rax
	salq	$3, %rsi
	movq	(%rax), %rdx
	addq	%rsi, %rdx
	movq	%rdx, %rax
	movq	8(%rdx), %rdx
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	je	.L26
	movq	%rdx, %r8
	subq	%rax, %r8
	cmpq	$4, %r8
	je	.L39
	cmpq	$8, %r8
	jne	.L30
	movslq	(%rax), %rsi
	movl	-4(%rdx), %r12d
	cmpl	%esi, %r10d
	je	.L35
	cmpl	%r12d, %r10d
	je	.L35
.L31:
	movq	16(%rbp), %rcx
	movslq	%r12d, %rdx
	movq	24(%rbp), %rax
	movq	(%rcx), %rcx
	movl	(%rcx,%rdx,4), %r11d
	movl	%esi, 52(%rsp)
	movl	%edi, 56(%rsp)
	addl	%ebx, %r11d
	movl	%r11d, %edx
	subl	$1, %edx
	cmpq	$0, 16(%rax)
	movl	%edx, 60(%rsp)
	je	.L34
	leaq	52(%rsp), %rdx
	movq	%rax, %rcx
	leaq	60(%rsp), %r9
	leaq	56(%rsp), %r8
	call	*24(%rax)
	movq	16(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	(%rdx), %rdx
	addl	(%rdx,%rsi,4), %ebx
	movl	%r12d, 40(%rsp)
	subl	$1, %ebx
	cmpq	$0, 16(%rax)
	movl	%edi, 44(%rsp)
	movl	%ebx, 48(%rsp)
	je	.L34
	leaq	40(%rsp), %rdx
	leaq	48(%rsp), %r9
	movq	%rax, %rcx
	leaq	44(%rsp), %r8
	call	*24(%rax)
	nop
.L26:
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	movl	$128, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	rex.W jmp	*__imp__assert(%rip)
	.p2align 4,,10
	.p2align 3
.L39:
	movslq	(%rax), %rax
	cmpl	%eax, %r10d
	je	.L40
.L29:
	movq	16(%rbp), %rdx
	movq	(%rdx), %rdx
	addl	(%rdx,%rax,4), %ebx
	subl	$1, %ebx
	cmpl	%ecx, %ebx
	cmovl	%ecx, %ebx
	movl	%ebx, (%r9)
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.p2align 4,,10
	.p2align 3
.L35:
	movl	$124, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	*__imp__assert(%rip)
	jmp	.L31
	.p2align 4,,10
	.p2align 3
.L40:
	leaq	.LC1(%rip), %rcx
	movl	$119, %r8d
	leaq	.LC0(%rip), %rdx
	call	*__imp__assert(%rip)
	movq	8(%rbp), %rax
	movq	0(%rbp), %r9
	movq	(%rax), %rax
	movl	(%r9), %ecx
	movq	(%rax,%rsi), %rax
	movslq	(%rax), %rax
	jmp	.L29
.L34:
	call	_ZSt25__throw_bad_function_callv
	nop
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
	je	.L41
	movl	$3, %r8d
	movq	%rcx, %rdx
	call	*%rax
	nop
.L41:
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
	je	.L51
	cmpb	$0, 56(%r12)
	je	.L48
	movsbl	67(%r12), %edx
.L49:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L48:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L49
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L49
.L51:
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
.LFB8091:
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
	je	.L54
	.p2align 4,,10
	.p2align 3
.L56:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L55
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L55:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L56
	movq	(%rsi), %r12
.L54:
	testq	%r12, %r12
	je	.L53
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
.L53:
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
.LFB8303:
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
	je	.L76
	testq	%rax, %rax
	movl	$1, %edx
	movq	%r12, %r15
	cmovne	%rax, %rdx
	addq	%rdx, %rax
	setc	%dl
	subq	%r13, %r15
	movzbl	%dl, %edx
	testq	%rdx, %rdx
	jne	.L74
	testq	%rax, %rax
	jne	.L67
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.L73:
	movl	(%r14), %eax
	subq	%r12, %rdi
	leaq	4(%rbp,%r15), %r10
	movq	16(%rsi), %r14
	movq	%rdi, %r9
	leaq	(%r10,%rdi), %rdi
	movl	%eax, 0(%rbp,%r15)
	testq	%r15, %r15
	jg	.L77
	testq	%r9, %r9
	jg	.L69
	testq	%r13, %r13
	jne	.L72
.L70:
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
.L77:
	movq	%r15, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	movq	%r9, 40(%rsp)
	movq	%r10, 32(%rsp)
	call	memmove
	movq	40(%rsp), %r9
	movq	32(%rsp), %r10
	testq	%r9, %r9
	jg	.L69
.L72:
	movq	%r14, %rdx
	movq	%r13, %rcx
	subq	%r13, %rdx
	call	_ZdlPvy
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L69:
	movq	%r9, %r8
	movq	%r12, %rdx
	movq	%r10, %rcx
	call	memcpy
	testq	%r13, %r13
	je	.L70
	jmp	.L72
	.p2align 4,,10
	.p2align 3
.L74:
	movabsq	$9223372036854775804, %rbx
.L66:
	movq	%rbx, %rcx
	call	_Znwy
	movq	%rax, %rbp
	addq	%rax, %rbx
	jmp	.L73
	.p2align 4,,10
	.p2align 3
.L67:
	movabsq	$2305843009213693951, %rdx
	cmpq	%rdx, %rax
	cmova	%rdx, %rax
	leaq	0(,%rax,4), %rbx
	jmp	.L66
.L76:
	leaq	.LC4(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.text
	.p2align 4
	.def	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_
_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_:
.LFB8325:
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
	jne	.L84
	jmp	.L78
	.p2align 4,,10
	.p2align 3
.L89:
	movl	%ebp, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L82:
	movq	32(%r12), %rcx
	movl	44(%rsp), %eax
	movl	%ebp, 72(%rsp)
	cmpq	$0, 16(%rcx)
	movl	%eax, 76(%rsp)
	je	.L88
	movq	%r13, %rdx
	movq	%r14, %r8
	call	*24(%rcx)
	movq	(%r12), %rdx
	movslq	%ebp, %rax
	movq	(%rdx), %rdx
	movl	(%rdx,%rax,4), %eax
	addl	%eax, (%rdx,%rbx)
.L80:
	addq	$4, %r15
	cmpq	%r15, %rdi
	je	.L78
.L84:
	movl	(%r15), %ebp
	movl	%ebp, 68(%rsp)
	cmpl	%ebp, %esi
	je	.L80
	movq	24(%r12), %rdx
	movq	48(%rsp), %rcx
	addq	(%rdx), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	jne	.L89
	movq	56(%rsp), %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	68(%rsp), %ebp
	jmp	.L82
	.p2align 4,,10
	.p2align 3
.L78:
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
.L88:
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
.LFB8315:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L90
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L90:
	ret
	.seh_endproc
	.section	.text$_Z6qprintIiEvT_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6qprintIiEvT_
	.def	_Z6qprintIiEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6qprintIiEvT_
_Z6qprintIiEvT_:
.LFB8340:
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
	js	.L101
.L93:
	movl	%ebx, %edi
	cmpl	$9, %ebx
	jg	.L98
.L99:
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
.L98:
	movl	$3435973837, %ecx
	movq	%rdi, %rsi
	imulq	%rcx, %rsi
	shrq	$35, %rsi
	movl	%esi, %r13d
	cmpl	$99, %ebx
	jg	.L96
.L97:
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
	jmp	.L99
	.p2align 4,,10
	.p2align 3
.L101:
	movl	$45, %edx
	movq	%r12, %rcx
	negl	%ebx
	call	_ZNSo3putEc
	jmp	.L93
	.p2align 4,,10
	.p2align 3
.L96:
	movq	%r13, %rbp
	imulq	%rcx, %rbp
	shrq	$35, %rbp
	movl	%ebp, %r14d
	cmpl	$999, %ebx
	jg	.L94
.L95:
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
	jmp	.L97
	.p2align 4,,10
	.p2align 3
.L94:
	imulq	%r14, %rcx
	shrq	$35, %rcx
	call	_Z6qprintIiEvT_
	jmp	.L95
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
	subq	$280, %rsp
	.seh_stackalloc	280
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rbx
	movq	%rbx, %rcx
	leaq	52(%rsp), %rdx
.LEHB0:
	call	_ZNSirsERi
	movl	52(%rsp), %edx
	movabsq	$384307168202282325, %rcx
	leal	1(%rdx), %eax
	cltq
	cmpq	%rcx, %rax
	ja	.L215
	movq	$0, 80(%rsp)
	leaq	(%rax,%rax,2), %rsi
	movq	$0, 88(%rsp)
	salq	$3, %rsi
	movq	$0, 96(%rsp)
	testq	%rax, %rax
	je	.L104
	movq	%rsi, %rcx
	call	_Znwy
.LEHE0:
	leaq	(%rax,%rsi), %rdx
	movq	%rax, 80(%rsp)
	movq	%rdx, 96(%rsp)
	.p2align 4,,10
	.p2align 3
.L105:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L105
	movl	52(%rsp), %edx
	movq	%rax, 88(%rsp)
	movabsq	$384307168202282325, %rax
	leal	1(%rdx), %r9d
	movl	%edx, %ecx
	movslq	%r9d, %r9
	cmpq	%rax, %r9
	ja	.L216
	movq	$0, 112(%rsp)
	leaq	(%r9,%r9,2), %r8
	movq	$0, 120(%rsp)
	leaq	0(,%r8,8), %rsi
	movq	$0, 128(%rsp)
	testq	%r9, %r9
	je	.L107
	movq	%rsi, %rcx
.LEHB1:
	call	_Znwy
.LEHE1:
	leaq	(%rax,%rsi), %r8
	movl	52(%rsp), %edx
	movq	%rax, 112(%rsp)
	movq	%r8, 128(%rsp)
	movl	%edx, %ecx
	.p2align 4,,10
	.p2align 3
.L108:
	movq	$0, (%rax)
	addq	$24, %rax
	movq	$0, -16(%rax)
	movq	$0, -8(%rax)
	cmpq	%r8, %rax
	jne	.L108
.L158:
	movq	%r8, 120(%rsp)
	cmpl	$1, %ecx
	jle	.L109
	movl	$1, %r13d
	movl	$1, %r12d
	movl	$48, %r14d
	leaq	240(%rsp), %r15
	.p2align 4,,10
	.p2align 3
.L124:
	movl	$0, 208(%rsp)
	movq	%rbx, %rcx
.LEHB2:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L110
	.p2align 4,,10
	.p2align 3
.L112:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L112
.L110:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L113:
	leal	(%rsi,%rsi,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %ebp
	leal	-48(%rbp), %esi
	movl	%esi, 208(%rsp)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L113
	testb	%dil, %dil
	je	.L114
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 208(%rsp)
.L114:
	movl	$0, 240(%rsp)
	movq	%rbx, %rcx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	xorl	%edi, %edi
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L115
	.p2align 4,,10
	.p2align 3
.L117:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%r12d, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L117
.L115:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L118:
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
	jbe	.L118
	testb	%dil, %dil
	je	.L119
	movl	%r14d, %eax
	subl	%ebp, %eax
	movl	%eax, 240(%rsp)
.L119:
	movslq	208(%rsp), %rax
	movq	80(%rsp), %r8
	movq	%rax, %rsi
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L120
	movslq	240(%rsp), %rax
	addq	$4, %rdx
	movl	%eax, -4(%rdx)
	movq	%rdx, 8(%rcx)
.L121:
	leaq	(%rax,%rax,2), %rax
	leaq	(%r8,%rax,8), %rcx
	movq	8(%rcx), %rdx
	cmpq	16(%rcx), %rdx
	je	.L122
	movl	%esi, (%rdx)
	addq	$4, %rdx
	movq	%rdx, 8(%rcx)
.L123:
	movl	52(%rsp), %edx
	addl	$1, %r13d
	movl	%edx, %ecx
	cmpl	%r13d, %edx
	jg	.L124
.L109:
	leal	1(%rcx), %eax
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L217
	movq	$0, 144(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 152(%rsp)
	movq	$0, 160(%rsp)
	testq	%rax, %rax
	je	.L126
	movq	%rsi, %rcx
	call	_Znwy
.LEHE2:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 144(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 160(%rsp)
	cmpq	%rax, %rbx
	je	.L214
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L214:
	movl	52(%rsp), %edx
.L127:
	leal	1(%rdx), %eax
	movq	%rbx, 152(%rsp)
	cltq
	movq	%rax, %rdi
	shrq	$61, %rdi
	jne	.L218
	movq	$0, 176(%rsp)
	leaq	0(,%rax,4), %rsi
	movq	$0, 184(%rsp)
	movq	$0, 192(%rsp)
	testq	%rax, %rax
	je	.L129
	movq	%rsi, %rcx
.LEHB3:
	call	_Znwy
.LEHE3:
	leaq	(%rax,%rsi), %rbx
	movq	%rax, 176(%rsp)
	movq	%rax, %rcx
	movq	%rbx, 192(%rsp)
	cmpq	%rax, %rbx
	je	.L130
	movq	%rsi, %r8
	xorl	%edx, %edx
	call	memset
.L130:
	movl	$40, %ecx
	movq	%rbx, 184(%rsp)
	movq	$0, 224(%rsp)
.LEHB4:
	call	_Znwy
.LEHE4:
	leaq	176(%rsp), %rdi
	leaq	208(%rsp), %r13
	movq	%rax, 208(%rsp)
	leaq	144(%rsp), %rsi
	leaq	80(%rsp), %rbp
	movq	%rdi, 8(%rax)
	movq	%r13, %rcx
	leaq	112(%rsp), %r15
	movq	%rsi, (%rax)
	leaq	60(%rsp), %rdx
	movq	%rbp, 16(%rax)
	leaq	64(%rsp), %r8
	movq	%r15, 24(%rax)
	movq	%r13, 32(%rax)
	leaq	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_(%rip), %rax
	movq	%rax, 232(%rsp)
	leaq	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rdi, 32(%rsp)
	movq	%rax, 224(%rsp)
	movl	$1, 60(%rsp)
	movl	$1, 64(%rsp)
.LEHB5:
	call	_ZNSt17_Function_handlerIFviiEZ8solutionvEUliiE_E9_M_invokeERKSt9_Any_dataOiS6_
.LEHE5:
	movl	$32, %ecx
	movl	$0, 56(%rsp)
	movq	$0, 256(%rsp)
.LEHB6:
	call	_Znwy
.LEHE6:
	leaq	56(%rsp), %rdx
	leaq	240(%rsp), %r14
	movq	%r15, 8(%rax)
	movq	%rdx, (%rax)
	leaq	76(%rsp), %r9
	leaq	68(%rsp), %rdx
	movq	%r14, %rcx
	movq	%rsi, 16(%rax)
	leaq	72(%rsp), %r8
	movq	%r14, 24(%rax)
	movq	%rax, 240(%rsp)
	leaq	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E9_M_invokeERKSt9_Any_dataOiS6_S6_(%rip), %rax
	movq	%rax, 264(%rsp)
	leaq	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rax, 256(%rsp)
	movl	$1, 68(%rsp)
	movl	$1, 72(%rsp)
	movl	$0, 76(%rsp)
.LEHB7:
	call	_ZNSt17_Function_handlerIFviiiEZ8solutionvEUliiiE0_E9_M_invokeERKSt9_Any_dataOiS6_S6_
	movl	56(%rsp), %ebx
	testl	%ebx, %ebx
	js	.L219
.L137:
	cmpl	$9, %ebx
	jg	.L156
	movq	.refptr._ZSt4cout(%rip), %r12
	movl	%ebx, %edi
.L157:
	movl	$3435973837, %eax
	movq	%r12, %rcx
	imulq	%rdi, %rax
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	movl	$32, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
	movl	$10, %edx
	movq	%r12, %rcx
	call	_ZNSo3putEc
.LEHE7:
	movq	256(%rsp), %rax
	testq	%rax, %rax
	je	.L138
	movl	$3, %r8d
	movq	%r14, %rdx
	movq	%r14, %rcx
	call	*%rax
.L138:
	movq	224(%rsp), %rax
	testq	%rax, %rax
	je	.L139
	movl	$3, %r8d
	movq	%r13, %rdx
	movq	%r13, %rcx
	call	*%rax
.L139:
	movq	176(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L140
	movq	192(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L140:
	movq	144(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L141
	movq	160(%rsp), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L141:
	movq	120(%rsp), %rbx
	movq	112(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L142
	.p2align 4,,10
	.p2align 3
.L144:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L143
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L143:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L144
	movq	112(%rsp), %r12
.L142:
	testq	%r12, %r12
	je	.L145
	movq	128(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
.L145:
	movq	88(%rsp), %rbx
	movq	80(%rsp), %r12
	cmpq	%r12, %rbx
	je	.L146
	.p2align 4,,10
	.p2align 3
.L148:
	movq	(%r12), %rcx
	testq	%rcx, %rcx
	je	.L147
	movq	16(%r12), %rdx
	subq	%rcx, %rdx
	call	_ZdlPvy
.L147:
	addq	$24, %r12
	cmpq	%r12, %rbx
	jne	.L148
	movq	80(%rsp), %r12
.L146:
	testq	%r12, %r12
	je	.L102
	movq	96(%rsp), %rdx
	movq	%r12, %rcx
	subq	%r12, %rdx
	call	_ZdlPvy
	nop
.L102:
	addq	$280, %rsp
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
.L122:
	leaq	208(%rsp), %r8
.LEHB8:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L123
	.p2align 4,,10
	.p2align 3
.L120:
	movq	%r15, %r8
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE8:
	movslq	240(%rsp), %rax
	movq	80(%rsp), %r8
	jmp	.L121
.L126:
	movq	$0, 144(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 160(%rsp)
	jmp	.L127
.L129:
	movq	$0, 176(%rsp)
	xorl	%ebx, %ebx
	movq	$0, 192(%rsp)
	jmp	.L130
.L156:
	movl	%ebx, %edi
	movl	$3435973837, %eax
	movq	%rdi, %rdx
	imulq	%rax, %rdx
	shrq	$35, %rdx
	movq	%rdx, %r12
	cmpl	$99, %ebx
	jg	.L154
	movl	%edx, %eax
	movq	%rax, 40(%rsp)
.L155:
	movl	$3435973837, %eax
	imulq	40(%rsp), %rax
	movl	%r12d, %edx
	movq	.refptr._ZSt4cout(%rip), %r12
	movq	%r12, %rcx
	shrq	$35, %rax
	leal	(%rax,%rax,4), %eax
	addl	%eax, %eax
	subl	%eax, %edx
	addl	$48, %edx
	movzbl	%dl, %edx
.LEHB9:
	call	_ZNSo3putEc
	jmp	.L157
.L219:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negl	%ebx
	jmp	.L137
.L154:
	movl	%r12d, %ecx
	imulq	%rcx, %rax
	movq	%rcx, 40(%rsp)
	shrq	$35, %rax
	movq	%rax, %rcx
	call	_Z6qprintIiEvT_
.LEHE9:
	jmp	.L155
.L104:
	movq	$0, 80(%rsp)
	movl	$-1, %ecx
	movq	$0, 96(%rsp)
	movq	$0, 88(%rsp)
.L107:
	movq	$0, 112(%rsp)
	xorl	%r8d, %r8d
	movq	$0, 128(%rsp)
	jmp	.L158
.L216:
	leaq	.LC5(%rip), %rcx
.LEHB10:
	call	_ZSt20__throw_length_errorPKc
.LEHE10:
.L217:
	leaq	.LC5(%rip), %rcx
.LEHB11:
	call	_ZSt20__throw_length_errorPKc
.LEHE11:
.L218:
	leaq	.LC5(%rip), %rcx
.LEHB12:
	call	_ZSt20__throw_length_errorPKc
.LEHE12:
.L215:
	leaq	.LC5(%rip), %rcx
.LEHB13:
	call	_ZSt20__throw_length_errorPKc
.L161:
	movq	%rax, %r12
	leaq	80(%rsp), %rbp
.L153:
	movq	%rbp, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE13:
.L163:
	movq	%rax, %r12
	leaq	80(%rsp), %rbp
	leaq	112(%rsp), %r15
	leaq	144(%rsp), %rsi
.L151:
	movq	%rsi, %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
.L152:
	movq	%r15, %rcx
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	jmp	.L153
.L166:
	leaq	208(%rsp), %rcx
	movq	%rax, %r12
	leaq	80(%rsp), %rbp
	call	_ZNSt14_Function_baseD2Ev
	leaq	176(%rsp), %rax
	leaq	112(%rsp), %r15
	movq	%rax, 32(%rsp)
	leaq	144(%rsp), %rsi
.L133:
	movq	32(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	jmp	.L151
.L164:
	movq	%rax, %rbx
	jmp	.L136
.L167:
	leaq	240(%rsp), %rcx
	movq	%rax, %rbx
	call	_ZNSt14_Function_baseD2Ev
.L136:
	movq	%r13, %rcx
	movq	%rbx, %r12
	call	_ZNSt14_Function_baseD2Ev
	jmp	.L133
.L162:
	movq	%rax, %r12
	leaq	80(%rsp), %rbp
	leaq	112(%rsp), %r15
	jmp	.L152
.L165:
	movq	%r14, %rcx
	movq	%rax, %rbx
	call	_ZNSt14_Function_baseD2Ev
	jmp	.L136
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
	.uleb128 .L161-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L162-.LFB7654
	.uleb128 0
	.uleb128 .LEHB3-.LFB7654
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L163-.LFB7654
	.uleb128 0
	.uleb128 .LEHB4-.LFB7654
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L166-.LFB7654
	.uleb128 0
	.uleb128 .LEHB5-.LFB7654
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L164-.LFB7654
	.uleb128 0
	.uleb128 .LEHB6-.LFB7654
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L167-.LFB7654
	.uleb128 0
	.uleb128 .LEHB7-.LFB7654
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L165-.LFB7654
	.uleb128 0
	.uleb128 .LEHB8-.LFB7654
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L162-.LFB7654
	.uleb128 0
	.uleb128 .LEHB9-.LFB7654
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L165-.LFB7654
	.uleb128 0
	.uleb128 .LEHB10-.LFB7654
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L161-.LFB7654
	.uleb128 0
	.uleb128 .LEHB11-.LFB7654
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L162-.LFB7654
	.uleb128 0
	.uleb128 .LEHB12-.LFB7654
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L163-.LFB7654
	.uleb128 0
	.uleb128 .LEHB13-.LFB7654
	.uleb128 .LEHE13-.LEHB13
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
.LFB7668:
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
	jmp	.L227
	.p2align 4,,10
	.p2align 3
.L228:
	call	_Z8solutionv
.L227:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L228
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB8710:
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
	.align 8
_ZTIZ8solutionvEUliiiE0_:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSZ8solutionvEUliiiE0_
	.align 16
_ZTSZ8solutionvEUliiiE0_:
	.ascii "*Z8solutionvEUliiiE0_\0"
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
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
