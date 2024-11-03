__asm__(R"(	.file	"cf-1610H.cpp"
	.text
	.p2align 4,,15
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11373:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	7200216+G(%rip), %rbx
	leaq	-24+G(%rip), %rsi
	.p2align 4,,10
.L3:
	movq	(%rbx), %rcx
	testq	%rcx, %rcx
	je	.L2
	call	_ZdlPv
.L2:
	subq	$24, %rbx
	cmpq	%rsi, %rbx
	jne	.L3
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11372:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4,,15
	.def	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
_ZNSt14_Function_base13_Base_managerIZ4mainEUliE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
.LFB10813:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	cmpl	$1, %r8d
	je	.L12
	jle	.L17
	cmpl	$2, %r8d
	movq	%rcx, %rbx
	je	.L15
	cmpl	$3, %r8d
	jne	.L11
	movq	(%rcx), %rcx
	call	_ZdlPv
.L11:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L15:
	movq	(%rdx), %rsi
	movl	$8, %ecx
	call	_Znwy
	movq	(%rsi), %rdx
	movq	%rdx, (%rax)
	movq	%rax, (%rbx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L17:
	testl	%r8d, %r8d
	jne	.L11
	leaq	_ZTIZ4mainEUliE_(%rip), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L12:
	movq	(%rdx), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.def	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
_ZNSt14_Function_base13_Base_managerIZ4mainEUliE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation:
.LFB10831:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	cmpl	$1, %r8d
	je	.L20
	jle	.L25
	cmpl	$2, %r8d
	movq	%rcx, %rbx
	je	.L23
	cmpl	$3, %r8d
	jne	.L19
	movq	(%rcx), %rcx
	call	_ZdlPv
.L19:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L23:
	movq	(%rdx), %rsi
	movl	$8, %ecx
	call	_Znwy
	movq	(%rsi), %rdx
	movq	%rdx, (%rax)
	movq	%rax, (%rbx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L25:
	testl	%r8d, %r8d
	jne	.L19
	leaq	_ZTIZ4mainEUliE0_(%rip), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L20:
	movq	(%rdx), %rax
	movq	%rax, (%rcx)
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB7:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rdx, 72(%rsp)
	leaq	72(%rsp), %rdx
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rdx, 40(%rsp)
	call	__mingw_vscanf
	addq	$56, %rsp
	ret
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
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
	.section	.text$_ZNKSt8functionIFviEEclEi,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNKSt8functionIFviEEclEi
	.def	_ZNKSt8functionIFviEEclEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt8functionIFviEEclEi
_ZNKSt8functionIFviEEclEi:
.LFB10530:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	cmpq	$0, 16(%rcx)
	je	.L30
	movq	24(%rcx), %rax
	addq	$40, %rsp
	rex.W jmp *%rax
.L30:
	call	_ZSt25__throw_bad_function_callv
	nop
	.seh_endproc
	.text
	.p2align 4,,15
	.def	_ZNSt17_Function_handlerIFviEZ4mainEUliE_E9_M_invokeERKSt9_Any_datai;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviEZ4mainEUliE_E9_M_invokeERKSt9_Any_datai
_ZNSt17_Function_handlerIFviEZ4mainEUliE_E9_M_invokeERKSt9_Any_datai:
.LFB10812:
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
	movl	tim(%rip), %eax
	movq	(%rcx), %r13
	leaq	sz(%rip), %rdi
	movslq	%edx, %rbp
	leaq	tid(%rip), %rdx
	movl	$1, (%rdi,%rbp,4)
	addl	$1, %eax
	movl	%eax, (%rdx,%rbp,4)
	movl	%eax, tim(%rip)
	leaq	fa(%rip), %rax
	leaq	dep(%rip), %rdx
	movslq	(%rax,%rbp,4), %rax
	movl	(%rdx,%rax,4), %eax
	addl	$1, %eax
	movl	%eax, (%rdx,%rbp,4)
	leaq	0(%rbp,%rbp,2), %rdx
	leaq	G(%rip), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	8(%rax), %r12
	movq	(%rax), %rsi
	cmpq	%r12, %rsi
	je	.L31
	.p2align 4,,10
.L35:
	movslq	(%rsi), %rbx
	movq	0(%r13), %rcx
	addq	$4, %rsi
	movl	%ebx, %edx
	call	_ZNKSt8functionIFviEEclEi
	movl	(%rdi,%rbx,4), %eax
	addl	%eax, (%rdi,%rbp,4)
	cmpq	%rsi, %r12
	jne	.L35
.L31:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.seh_endproc
	.p2align 4,,15
	.def	_ZNSt17_Function_handlerIFviEZ4mainEUliE0_E9_M_invokeERKSt9_Any_datai;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt17_Function_handlerIFviEZ4mainEUliE0_E9_M_invokeERKSt9_Any_datai
_ZNSt17_Function_handlerIFviEZ4mainEUliE0_E9_M_invokeERKSt9_Any_datai:
.LFB10830:
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
	leaq	G(%rip), %rax
	movq	(%rcx), %r12
	leaq	cnt(%rip), %r14
	movslq	%edx, %r15
	leaq	(%r15,%r15,2), %rdx
	movq	%r15, %rdi
	leaq	(%rax,%rdx,8), %rbp
	movq	8(%rbp), %rsi
	movq	0(%rbp), %r13
	cmpq	%rsi, %r13
	je	.L42
	.p2align 4,,10
.L48:
	movslq	0(%r13), %rbx
	movq	(%r12), %rcx
	addq	$4, %r13
	movl	%ebx, %edx
	call	_ZNKSt8functionIFviEEclEi
	movl	(%r14,%rbx,4), %eax
	addl	(%r14,%r15,4), %eax
	cmpq	%r13, %rsi
	movl	%eax, (%r14,%r15,4)
	jne	.L48
	movq	0(%rbp), %rcx
	movq	8(%rbp), %r10
	cmpq	%r10, %rcx
	jne	.L44
	jmp	.L42
	.p2align 4,,10
.L43:
	addq	$4, %rcx
	cmpq	%rcx, %r10
	je	.L42
.L44:
	movslq	(%rcx), %rdx
	cmpl	%eax, (%r14,%rdx,4)
	jne	.L43
	leaq	cur(%rip), %r8
	movl	(%r8,%r15,4), %r9d
	cmpl	%r9d, (%r8,%rdx,4)
	cmovge	(%r8,%rdx,4), %r9d
	addq	$4, %rcx
	cmpq	%rcx, %r10
	movl	%r9d, (%r8,%r15,4)
	jne	.L44
.L42:
	cmpl	$1, %edi
	jle	.L40
	leaq	dep(%rip), %rax
	leaq	cur(%rip), %rdx
	movl	(%rax,%r15,4), %eax
	subl	$1, %eax
	cmpl	%eax, (%rdx,%r15,4)
	je	.L52
.L40:
	leaq	mx(%rip), %rax
	movl	(%rax,%r15,4), %eax
	testl	%eax, %eax
	je	.L37
	leaq	cur(%rip), %rdx
	cmpl	%eax, (%rdx,%r15,4)
	cmovge	(%rdx,%r15,4), %eax
	movl	%eax, (%rdx,%r15,4)
.L37:
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
	.p2align 4,,10
.L52:
	leaq	cnt(%rip), %rax
	addl	$1, ans(%rip)
	movl	$0, (%rdx,%r15,4)
	addl	$1, (%rax,%r15,4)
	jmp	.L40
	.seh_endproc
	.section	.text$_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_:
.LFB10805:
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
	movq	8(%rcx), %r10
	movq	(%rcx), %r11
	movq	%rcx, %rsi
	movq	%r10, %rax
	subq	%r11, %rax
	movq	%rax, %rbx
	sarq	$2, %rbx
	testq	%rbx, %rbx
	je	.L61
	leaq	(%rbx,%rbx), %rcx
	cmpq	%rcx, %rbx
	jbe	.L75
.L63:
	movq	$-4, %rbx
.L54:
	movq	%rbx, %rcx
	movq	%rdx, 40(%rsp)
	call	_Znwy
	movq	8(%rsi), %r10
	movq	(%rsi), %r11
	movq	%rax, %rdi
	movq	40(%rsp), %rdx
	leaq	4(%rdi), %rbp
	movq	%r10, %rax
	subq	%r11, %rax
.L55:
	addq	%rdi, %rax
	movl	(%rdx), %edx
	je	.L56
	movl	%edx, (%rax)
.L56:
	cmpq	%r10, %r11
	je	.L57
	movq	%r11, %rdx
	movq	%rdi, %r8
	.p2align 4,,10
.L59:
	testq	%r8, %r8
	movl	(%rdx), %r9d
	je	.L58
	movl	%r9d, (%r8)
.L58:
	addq	$4, %rdx
	addq	$4, %r8
	cmpq	%rdx, %r10
	jne	.L59
	leaq	4(%r11), %rax
	subq	%rax, %r10
	shrq	$2, %r10
	leaq	8(%rdi,%r10,4), %rbp
.L57:
	testq	%r11, %r11
	je	.L60
	movq	%r11, %rcx
	call	_ZdlPv
.L60:
	addq	%rdi, %rbx
	movq	%rdi, (%rsi)
	movq	%rbp, 8(%rsi)
	movq	%rbx, 16(%rsi)
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L61:
	movl	$4, %ebx
	jmp	.L54
.L75:
	movabsq	$4611686018427387903, %r8
	cmpq	%r8, %rcx
	ja	.L63
	salq	$3, %rbx
	testq	%rcx, %rcx
	jne	.L54
	movl	$4, %ebp
	xorl	%edi, %edi
	jmp	.L55
	.seh_endproc
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.section	.text$_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.def	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_:
.LFB11004:
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
	movq	(%rcx), %r8
	movq	8(%rcx), %rbx
	movq	%rcx, %rsi
	subq	%r8, %rbx
	movq	%rbx, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L82
	leaq	(%rax,%rax), %rcx
	movq	$-8, %rbp
	cmpq	%rcx, %rax
	ja	.L77
	movabsq	$2305843009213693951, %r9
	cmpq	%r9, %rcx
	ja	.L77
	movq	%rax, %rbp
	xorl	%edi, %edi
	salq	$4, %rbp
	testq	%rcx, %rcx
	jne	.L77
	.p2align 4,,10
.L78:
	movq	%rdi, %rcx
	addq	%rbx, %rcx
	je	.L79
	movq	(%rdx), %rdx
	movq	%rdx, (%rcx)
.L79:
	testq	%rax, %rax
	movq	%r8, %rcx
	jne	.L95
.L80:
	testq	%rcx, %rcx
	leaq	8(%rdi,%rbx), %rbx
	je	.L81
	call	_ZdlPv
.L81:
	movq	%rdi, (%rsi)
	addq	%rbp, %rdi
	movq	%rbx, 8(%rsi)
	movq	%rdi, 16(%rsi)
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L82:
	movl	$8, %ebp
.L77:
	movq	%rbp, %rcx
	movq	%rdx, 40(%rsp)
	call	_Znwy
	movq	(%rsi), %r8
	movq	8(%rsi), %rbx
	movq	%rax, %rdi
	movq	40(%rsp), %rdx
	subq	%r8, %rbx
	movq	%rbx, %rax
	sarq	$3, %rax
	jmp	.L78
	.p2align 4,,10
.L95:
	movq	%rcx, %rdx
	movq	%rbx, %r8
	movq	%rdi, %rcx
	call	memmove
	movq	(%rsi), %rcx
	jmp	.L80
	.seh_endproc
	.weak	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_
	.def	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_,_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d %d\0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "-1\0"
.LC3:
	.ascii "%d\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10114:
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
	subq	$152, %rsp
	.seh_stackalloc	152
	.seh_endprologue
	leaq	fa(%rip), %rbx
	leaq	G(%rip), %rsi
	call	__main
	leaq	m(%rip), %r8
	leaq	n(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	leaq	112(%rsp), %rdi
.LEHB0:
	call	_Z5scanfPKcz
	cmpl	$1, n(%rip)
	movl	$2, 112(%rsp)
	movl	$2, %eax
	jle	.L102
	.p2align 4,,10
.L165:
	cltq
	leaq	.LC1(%rip), %rcx
	leaq	(%rbx,%rax,4), %rdx
	call	_Z5scanfPKcz
.LEHE0:
	movslq	112(%rsp), %rdx
	movq	%rdx, %rax
	movslq	(%rbx,%rdx,4), %rdx
	leaq	(%rdx,%rdx,2), %rcx
	leaq	(%rsi,%rcx,8), %rcx
	movq	8(%rcx), %r8
	cmpq	16(%rcx), %r8
	je	.L99
	testq	%r8, %r8
	je	.L100
	movl	%eax, (%r8)
	movl	112(%rsp), %eax
.L100:
	leaq	(%rdx,%rdx,2), %rdx
	addq	$4, %r8
	movq	%r8, 8(%rsi,%rdx,8)
.L101:
	addl	$1, %eax
	cmpl	%eax, n(%rip)
	movl	%eax, 112(%rsp)
	jge	.L165
.L102:
	movl	$8, %ecx
	movq	$0, 96(%rsp)
.LEHB1:
	call	_Znwy
.LEHE1:
	leaq	80(%rsp), %rdi
	movl	$1, %edx
	movq	%rdi, (%rax)
	movq	%rax, 80(%rsp)
	leaq	_ZNSt17_Function_handlerIFviEZ4mainEUliE_E9_M_invokeERKSt9_Any_datai(%rip), %rax
	movq	%rdi, %rcx
	movq	%rax, 104(%rsp)
	leaq	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rax, 96(%rsp)
.LEHB2:
	call	_ZNKSt8functionIFviEEclEi
.LEHE2:
	movl	m(%rip), %eax
	movq	$0, 48(%rsp)
	movq	$0, 56(%rsp)
	movq	$0, 64(%rsp)
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, m(%rip)
	je	.L117
	leaq	44(%rsp), %rsi
	leaq	40(%rsp), %rbx
	leaq	112(%rsp), %rbp
	leaq	48(%rsp), %r12
	jmp	.L106
	.p2align 4,,10
.L186:
	movl	(%r11,%r9,4), %r13d
	addl	%r8d, %r13d
	cmpl	%r13d, %r10d
	jge	.L111
	leaq	mx(%rip), %rcx
	leaq	dep(%rip), %r8
	movl	(%rcx,%rax,4), %edx
	cmpl	%edx, (%r8,%r9,4)
	cmovge	(%r8,%r9,4), %edx
	movl	%edx, (%rcx,%rax,4)
.L112:
	movl	m(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, m(%rip)
	je	.L117
.L106:
	leaq	.LC0(%rip), %rcx
	movq	%rsi, %r8
	movq	%rbx, %rdx
.LEHB3:
	call	_Z5scanfPKcz
	movslq	44(%rsp), %r9
	leaq	fa(%rip), %r8
	movl	40(%rsp), %ecx
	cmpl	%ecx, (%r8,%r9,4)
	movq	%r9, %rdx
	je	.L108
	movslq	%ecx, %rax
	cmpl	(%r8,%rax,4), %r9d
	je	.L108
	leaq	tid(%rip), %r10
	leaq	sz(%rip), %r11
	movl	(%r10,%r9,4), %r8d
	movl	(%r10,%rax,4), %r10d
	cmpl	%r10d, %r8d
	jle	.L186
.L110:
	addl	(%r11,%rax,4), %r10d
	cmpl	%r10d, %r8d
	jge	.L113
	leaq	mx(%rip), %rcx
	leaq	dep(%rip), %r8
	movl	(%rcx,%r9,4), %edx
	cmpl	%edx, (%r8,%rax,4)
	cmovge	(%r8,%rax,4), %edx
	movl	%edx, (%rcx,%r9,4)
	jmp	.L112
	.p2align 4,,10
.L111:
	cmpl	%r10d, %r8d
	jge	.L110
.L113:
	movq	56(%rsp), %rax
	cmpq	64(%rsp), %rax
	movl	%ecx, 112(%rsp)
	movl	%edx, 116(%rsp)
	je	.L114
	testq	%rax, %rax
	je	.L115
	movq	112(%rsp), %rdx
	movq	%rdx, (%rax)
.L115:
	addq	$8, %rax
	movq	%rax, 56(%rsp)
	jmp	.L112
	.p2align 4,,10
.L114:
	movq	%rbp, %rdx
	movq	%r12, %rcx
	call	_ZNSt6vectorISt5arrayIiLy2EESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
.LEHE3:
	jmp	.L112
	.p2align 4,,10
.L117:
	movl	$8, %ecx
	movq	$0, 128(%rsp)
.LEHB4:
	call	_Znwy
.LEHE4:
	leaq	112(%rsp), %rbx
	movl	$1, %edx
	movq	%rbx, (%rax)
	movq	%rax, 112(%rsp)
	leaq	_ZNSt17_Function_handlerIFviEZ4mainEUliE0_E9_M_invokeERKSt9_Any_datai(%rip), %rax
	movq	%rbx, %rcx
	movq	%rax, 136(%rsp)
	leaq	_ZNSt14_Function_base13_Base_managerIZ4mainEUliE0_E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation(%rip), %rax
	movq	%rax, 128(%rsp)
.LEHB5:
	call	_ZNKSt8functionIFviEEclEi
.LEHE5:
	movq	48(%rsp), %rax
	movq	56(%rsp), %r10
	movl	ans(%rip), %edx
	cmpq	%r10, %rax
	je	.L122
	movslq	(%rax), %r8
	movslq	4(%rax), %rcx
	leaq	cnt(%rip), %r9
	addq	$8, %rax
	movl	(%r9,%rcx,4), %ecx
	addl	(%r9,%r8,4), %ecx
	cmpl	%edx, %ecx
	jne	.L125
	jmp	.L123
	.p2align 4,,10
.L126:
	movslq	(%r8), %rcx
	movslq	4(%r8), %r8
	addq	$8, %rax
	movl	(%r9,%r8,4), %r8d
	addl	(%r9,%rcx,4), %r8d
	cmpl	%edx, %r8d
	je	.L123
.L125:
	cmpq	%rax, %r10
	movq	%rax, %r8
	jne	.L126
.L122:
	leaq	.LC3(%rip), %rcx
	call	_Z6printfPKcz
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L127
	movl	$3, %r8d
	movq	%rbx, %rdx
	movq	%rbx, %rcx
	call	*%rax
.L127:
	movq	48(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L128
	call	_ZdlPv
.L128:
	movq	96(%rsp), %rax
	testq	%rax, %rax
	je	.L151
	movl	$3, %r8d
	movq	%rdi, %rdx
	movq	%rdi, %rcx
	call	*%rax
.L151:
	xorl	%eax, %eax
	addq	$152, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.p2align 4,,10
.L99:
	movq	%rdi, %rdx
.LEHB6:
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
.LEHE6:
	movl	112(%rsp), %eax
	jmp	.L101
.L123:
	addl	$1, %edx
	movl	%edx, ans(%rip)
	jmp	.L122
.L108:
	leaq	.LC2(%rip), %rcx
.LEHB7:
	call	puts
.LEHE7:
	xorl	%ecx, %ecx
	call	exit
.L137:
	movq	%rax, %rbx
.L121:
	movq	48(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L133
	call	_ZdlPv
.L133:
	movq	96(%rsp), %rax
	testq	%rax, %rax
	je	.L134
	movl	$3, %r8d
	movq	%rdi, %rdx
	movq	%rdi, %rcx
	call	*%rax
.L134:
	movq	%rbx, %rcx
.LEHB8:
	call	_Unwind_Resume
.LEHE8:
.L138:
	movq	%rax, %rsi
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L131
	movl	$3, %r8d
	movq	%rbx, %rdx
	movq	%rbx, %rcx
	call	*%rax
.L131:
	movq	%rsi, %rbx
	jmp	.L121
.L140:
	movq	%rax, %rbx
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L121
	leaq	112(%rsp), %rcx
	movl	$3, %r8d
	movq	%rcx, %rdx
	call	*%rax
	jmp	.L121
.L136:
	movq	%rax, %rbx
	jmp	.L133
.L139:
	movq	96(%rsp), %r9
	movq	%rax, %rbx
	testq	%r9, %r9
	je	.L134
	leaq	80(%rsp), %rcx
	movl	$3, %r8d
	movq	%rcx, %rdx
	call	*%r9
	jmp	.L134
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
	.uleb128 .L139-.LFB10114
	.uleb128 0
	.uleb128 .LEHB2-.LFB10114
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L136-.LFB10114
	.uleb128 0
	.uleb128 .LEHB3-.LFB10114
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L137-.LFB10114
	.uleb128 0
	.uleb128 .LEHB4-.LFB10114
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L140-.LFB10114
	.uleb128 0
	.uleb128 .LEHB5-.LFB10114
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L138-.LFB10114
	.uleb128 0
	.uleb128 .LEHB6-.LFB10114
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB10114
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L137-.LFB10114
	.uleb128 0
	.uleb128 .LEHB8-.LFB10114
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE10114:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_n;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_n
_GLOBAL__sub_I_n:
.LFB11404:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	G(%rip), %rax
	leaq	7200240+G(%rip), %rdx
	.p2align 4,,10
.L188:
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	addq	$24, %rax
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L188
	leaq	__tcf_1(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_n
	.section .rdata,"dr"
_ZTSZ4mainEUliE_:
	.ascii "*Z4mainEUliE_\0"
_ZTSZ4mainEUliE0_:
	.ascii "*Z4mainEUliE0_\0"
	.align 16
_ZTIZ4mainEUliE0_:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSZ4mainEUliE0_
	.align 16
_ZTIZ4mainEUliE_:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSZ4mainEUliE_
	.globl	G
	.bss
	.align 64
G:
	.space 7200240
	.globl	cur
	.align 64
cur:
	.space 1200040
	.globl	cnt
	.align 64
cnt:
	.space 1200040
	.globl	mx
	.align 64
mx:
	.space 1200040
	.globl	sz
	.align 64
sz:
	.space 1200040
	.globl	tid
	.align 64
tid:
	.space 1200040
	.globl	tim
	.align 4
tim:
	.space 4
	.globl	dep
	.align 64
dep:
	.space 1200040
	.globl	fa
	.align 64
fa:
	.space 1200040
	.globl	ans
	.align 4
ans:
	.space 4
	.globl	m
	.align 4
m:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__mingw_vscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_ZSt25__throw_bad_function_callv;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");