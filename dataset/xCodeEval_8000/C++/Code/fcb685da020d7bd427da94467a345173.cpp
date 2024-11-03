__asm__(R"(	.file	"test.cpp"
	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB7187:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
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
	.text
	.p2align 4,,15
	.globl	_Z4readv
	.def	_Z4readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readv
_Z4readv:
.LFB6858:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	$1, %esi
	call	getchar
	movsbl	%al, %edx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L4
	movl	$-1, %ebx
	.p2align 4,,10
.L6:
	cmpb	$45, %dl
	cmove	%ebx, %esi
	call	getchar
	movsbl	%al, %edx
	subl	$48, %eax
	cmpb	$9, %al
	ja	.L6
.L4:
	xorl	%ebx, %ebx
	.p2align 4,,10
.L7:
	leal	(%rbx,%rbx,4), %eax
	leal	-48(%rdx,%rax,2), %ebx
	call	getchar
	movsbl	%al, %edx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L7
	movl	%esi, %eax
	imull	%ebx, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z5readlv
	.def	_Z5readlv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5readlv
_Z5readlv:
.LFB6859:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	$1, %esi
	call	getchar
	movsbq	%al, %rdx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L16
	movq	$-1, %rbx
	.p2align 4,,10
.L18:
	cmpb	$45, %dl
	cmove	%rbx, %rsi
	call	getchar
	movsbq	%al, %rdx
	subl	$48, %eax
	cmpb	$9, %al
	ja	.L18
.L16:
	xorl	%ebx, %ebx
	.p2align 4,,10
.L19:
	leaq	(%rbx,%rbx,4), %rax
	leaq	-48(%rdx,%rax,2), %rbx
	call	getchar
	movsbq	%al, %rdx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L19
	movq	%rsi, %rax
	imulq	%rbx, %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
	.def	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev:
.LFB7001:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rdi
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L26
	movq	72(%rdi), %rax
	movq	40(%rdi), %rbx
	leaq	8(%rax), %rsi
	cmpq	%rbx, %rsi
	jbe	.L28
	.p2align 4,,10
.L29:
	movq	(%rbx), %rcx
	addq	$8, %rbx
	call	_ZdlPv
	cmpq	%rbx, %rsi
	ja	.L29
	movq	(%rdi), %rcx
.L28:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	jmp	_ZdlPv
	.p2align 4,,10
.L26:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy
	.def	_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy
_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy:
.LFB7058:
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
	movl	$8, %eax
	movq	%rcx, %rdi
	movq	%rdx, %rcx
	movq	%rdx, %rbp
	shrq	$5, %rcx
	leaq	1(%rcx), %rbx
	addq	$3, %rcx
	cmpq	$8, %rcx
	cmovb	%rax, %rcx
	movq	%rcx, 8(%rdi)
	salq	$3, %rcx
.LEHB0:
	call	_Znwy
.LEHE0:
	movq	8(%rdi), %rdx
	movq	%rax, (%rdi)
	subq	%rbx, %rdx
	shrq	%rdx
	leaq	(%rax,%rdx,8), %r12
	leaq	(%r12,%rbx,8), %rsi
	cmpq	%rsi, %r12
	jae	.L32
	movq	%r12, %rbx
	.p2align 4,,10
.L33:
	movl	$512, %ecx
.LEHB1:
	call	_Znwy
.LEHE1:
	movq	%rax, (%rbx)
	addq	$8, %rbx
	cmpq	%rbx, %rsi
	ja	.L33
.L32:
	movq	%r12, 40(%rdi)
	movq	(%r12), %rdx
	andl	$31, %ebp
	salq	$4, %rbp
	leaq	512(%rdx), %rax
	movq	%rdx, 24(%rdi)
	movq	%rax, 32(%rdi)
	leaq	-8(%rsi), %rax
	movq	%rax, 72(%rdi)
	movq	-8(%rsi), %rax
	movq	%rdx, 16(%rdi)
	leaq	512(%rax), %rcx
	movq	%rax, 56(%rdi)
	addq	%rbp, %rax
	movq	%rax, 48(%rdi)
	movq	%rcx, 64(%rdi)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
.L41:
	movq	%rax, %rcx
	call	__cxa_begin_catch
	cmpq	%r12, %rbx
	jbe	.L38
.L43:
	movq	(%r12), %rcx
	addq	$8, %r12
	call	_ZdlPv
	cmpq	%r12, %rbx
	ja	.L43
.L38:
.LEHB2:
	call	__cxa_rethrow
.LEHE2:
.L42:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rcx
	call	__cxa_begin_catch
	movq	(%rdi), %rcx
	call	_ZdlPv
	movq	$0, (%rdi)
	movq	$0, 8(%rdi)
.LEHB3:
	call	__cxa_rethrow
.LEHE3:
.L40:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rcx
.LEHB4:
	call	_Unwind_Resume
	nop
.LEHE4:
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA7058:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT7058-.LLSDATTD7058
.LLSDATTD7058:
	.byte	0x1
	.uleb128 .LLSDACSE7058-.LLSDACSB7058
.LLSDACSB7058:
	.uleb128 .LEHB0-.LFB7058
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7058
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L41-.LFB7058
	.uleb128 0x1
	.uleb128 .LEHB2-.LFB7058
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L42-.LFB7058
	.uleb128 0x3
	.uleb128 .LEHB3-.LFB7058
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L40-.LFB7058
	.uleb128 0
	.uleb128 .LEHB4-.LFB7058
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE7058:
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT7058:
	.section	.text$_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv
	.def	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv
_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv:
.LFB7069:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rbx
	movq	24(%rcx), %rcx
	call	_ZdlPv
	movq	40(%rbx), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, 40(%rbx)
	movq	8(%rax), %rax
	leaq	512(%rax), %rdx
	movq	%rax, 24(%rbx)
	movq	%rax, 16(%rbx)
	movq	%rdx, 32(%rbx)
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section	.text$_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_
	.def	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_
_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_:
.LFB7074:
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
	movq	%rcx, %rbx
	movq	%r8, %rdi
	movq	8(%rcx), %rcx
	movq	72(%rbx), %rsi
	movq	(%rbx), %r8
	movq	%rdx, %rbp
	movq	%rcx, %rdx
	movq	%rsi, %rax
	subq	%r8, %rax
	sarq	$3, %rax
	subq	%rax, %rdx
	cmpq	$1, %rdx
	jbe	.L68
.L49:
	movl	$512, %ecx
	call	_Znwy
	movq	%rax, 8(%rsi)
	movq	48(%rbx), %rax
	testq	%rax, %rax
	je	.L56
	movl	0(%rbp), %ecx
	movq	(%rdi), %rdx
	movl	%ecx, (%rax)
	movq	%rdx, 8(%rax)
.L56:
	movq	72(%rbx), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, 72(%rbx)
	movq	8(%rax), %rax
	leaq	512(%rax), %rdx
	movq	%rax, 56(%rbx)
	movq	%rax, 48(%rbx)
	movq	%rdx, 64(%rbx)
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
.L68:
	movq	40(%rbx), %rdx
	movq	%rsi, %rax
	subq	%rdx, %rax
	sarq	$3, %rax
	leaq	2(%rax), %r13
	leaq	1(%rax), %r12
	leaq	(%r13,%r13), %rax
	cmpq	%rax, %rcx
	ja	.L69
	testq	%rcx, %rcx
	je	.L57
	leaq	2(%rcx,%rcx), %rsi
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rsi
	ja	.L70
.L54:
	leaq	0(,%rsi,8), %rcx
	call	_Znwy
	movq	%rsi, %rdx
	movq	%rax, %r14
	subq	%r13, %rdx
	shrq	%rdx
	leaq	(%rax,%rdx,8), %r13
	movq	72(%rbx), %rax
	movq	40(%rbx), %rdx
	leaq	8(%rax), %r8
	subq	%rdx, %r8
	movq	%r8, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	jne	.L71
.L55:
	movq	(%rbx), %rcx
	call	_ZdlPv
	movq	%r14, (%rbx)
	movq	%rsi, 8(%rbx)
.L67:
	salq	$3, %r12
.L53:
	movq	%r13, 40(%rbx)
	movq	0(%r13), %rax
	leaq	-8(%r13,%r12), %rsi
	movq	%rsi, 72(%rbx)
	movq	%rax, 24(%rbx)
	addq	$512, %rax
	movq	%rax, 32(%rbx)
	movq	(%rsi), %rax
	movq	%rax, 56(%rbx)
	addq	$512, %rax
	movq	%rax, 64(%rbx)
	jmp	.L49
	.p2align 4,,10
.L69:
	subq	%r13, %rcx
	shrq	%rcx
	leaq	(%r8,%rcx,8), %r13
	cmpq	%r13, %rdx
	jbe	.L51
	leaq	8(%rsi), %r8
	subq	%rdx, %r8
	movq	%r8, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L67
	movq	%r13, %rcx
	salq	$3, %r12
	call	memmove
	jmp	.L53
	.p2align 4,,10
.L57:
	movl	$3, %esi
	jmp	.L54
	.p2align 4,,10
.L71:
	movq	%r13, %rcx
	call	memmove
	jmp	.L55
	.p2align 4,,10
.L51:
	leaq	8(%rsi), %r8
	salq	$3, %r12
	subq	%rdx, %r8
	movq	%r8, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L53
	movq	%r12, %rcx
	subq	%r8, %rcx
	addq	%r13, %rcx
	call	memmove
	jmp	.L53
.L70:
	call	_ZSt17__throw_bad_allocv
	nop
	.seh_endproc
	.weak	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIJRiRxEEEvDpOT_
	.def	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIJRiRxEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIJRiRxEEEvDpOT_,_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%lld\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB6860:
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
	subq	$216, %rsp
	.seh_stackalloc	216
	.seh_endprologue
	call	__main
.LEHB5:
	call	_Z4readv
	movl	%eax, n(%rip)
	call	_Z4readv
	movl	%eax, k(%rip)
	movl	n(%rip), %eax
	testl	%eax, %eax
	jle	.L76
	leaq	8+a(%rip), %rsi
	movl	$1, %ebx
	.p2align 4,,10
.L75:
	call	_Z5readlv
	addl	$1, %ebx
	movq	%rax, (%rsi)
	addq	$8, %rsi
	cmpl	%ebx, n(%rip)
	jge	.L75
.L76:
	leaq	128(%rsp), %r13
	leaq	48(%rsp), %rbp
	xorl	%edx, %edx
	movq	$0, 128(%rsp)
	movq	$0, 136(%rsp)
	movq	%r13, %rcx
	movq	$0, 144(%rsp)
	movq	$0, 152(%rsp)
	movq	$0, 160(%rsp)
	movq	$0, 168(%rsp)
	movq	$0, 176(%rsp)
	movq	$0, 184(%rsp)
	movq	$0, 192(%rsp)
	movq	$0, 200(%rsp)
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy
.LEHE5:
	xorl	%edx, %edx
	movq	%rbp, %rcx
	movq	$0, 48(%rsp)
	movq	$0, 56(%rsp)
	movq	$0, 64(%rsp)
	movq	$0, 72(%rsp)
	movq	$0, 80(%rsp)
	movq	$0, 88(%rsp)
	movq	$0, 96(%rsp)
	movq	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	movq	$0, 120(%rsp)
.LEHB6:
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EE17_M_initialize_mapEy
.LEHE6:
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L77
	movq	144(%rsp), %r10
	movq	64(%rsp), %r9
	movq	72(%rsp), %r8
	movq	80(%rsp), %rcx
	movq	88(%rsp), %rdx
	movq	%r10, 64(%rsp)
	movq	152(%rsp), %r10
	movq	%r9, 144(%rsp)
	movq	96(%rsp), %r9
	movq	%r8, 152(%rsp)
	movq	104(%rsp), %r8
	movq	%r10, 72(%rsp)
	movq	160(%rsp), %r10
	movq	%rcx, 160(%rsp)
	movq	112(%rsp), %rcx
	movq	%r10, 80(%rsp)
	movq	168(%rsp), %r10
	movq	%rdx, 168(%rsp)
	movq	120(%rsp), %rdx
	movq	%r10, 88(%rsp)
	movq	176(%rsp), %r10
	movq	%r9, 176(%rsp)
	movq	%r10, 96(%rsp)
	movq	184(%rsp), %r10
	movq	%r8, 184(%rsp)
	movq	%r10, 104(%rsp)
	movq	192(%rsp), %r10
	movq	%rcx, 192(%rsp)
	movq	%r10, 112(%rsp)
	movq	200(%rsp), %r10
	movq	%rdx, 200(%rsp)
	movq	48(%rsp), %rdx
	movq	%r10, 120(%rsp)
	movq	%rax, 48(%rsp)
	movq	56(%rsp), %rax
	movq	%rdx, 128(%rsp)
	movq	136(%rsp), %rdx
	movq	%rax, 136(%rsp)
	movq	%rdx, 56(%rsp)
.L77:
	movq	%r13, %rcx
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
	movl	n(%rip), %r9d
	movl	k(%rip), %r8d
	cmpl	%r8d, %r9d
	movl	%r9d, 44(%rsp)
	movl	%r8d, %r14d
	jl	.L105
	leaq	a(%rip), %rdi
	leaq	44(%rsp), %r15
	xorl	%ebx, %ebx
	xorl	%esi, %esi
	xorl	%r12d, %r12d
.L102:
	movslq	%r9d, %rax
	subq	%rbx, %rsi
	movq	96(%rsp), %r10
	subq	%rsi, (%rdi,%rax,8)
	movq	64(%rsp), %rcx
	jmp	.L79
	.p2align 4,,10
.L125:
	addq	$16, %rcx
	movq	%rcx, 64(%rsp)
.L79:
	cmpq	%rcx, %r10
	je	.L124
.L83:
	leal	(%r9,%r14), %eax
	cmpl	(%rcx), %eax
	jg	.L106
	movq	80(%rsp), %rax
	subq	8(%rcx), %rbx
	subq	$16, %rax
	cmpq	%rax, %rcx
	jne	.L125
	movq	%rbp, %rcx
	call	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv
	movq	96(%rsp), %r10
	movq	64(%rsp), %rcx
	movl	k(%rip), %r8d
	movl	44(%rsp), %r9d
	cmpq	%rcx, %r10
	movl	%r8d, %r14d
	jne	.L83
.L124:
	cmpl	%r14d, %r9d
	movq	%r10, %rax
	movl	%r9d, %r11d
	jne	.L126
.L84:
	leal	-1(%r9), %r14d
	testl	%r14d, %r14d
	jle	.L107
	.p2align 4,,10
.L93:
	movslq	%r14d, %rdx
	subq	%rbx, %rsi
	subq	%rsi, (%rdi,%rdx,8)
	jmp	.L91
	.p2align 4,,10
.L127:
	addq	$16, %rax
	movq	%rax, 64(%rsp)
.L91:
	cmpq	%rcx, %rax
	je	.L98
.L97:
	leal	(%r11,%r14), %edx
	cmpl	(%rax), %edx
	jg	.L98
	movq	80(%rsp), %rdx
	subq	8(%rax), %rbx
	subq	$16, %rdx
	cmpq	%rdx, %rax
	jne	.L127
	movq	%rbp, %rcx
	call	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_pop_front_auxEv
	movq	96(%rsp), %rcx
	movq	64(%rsp), %rax
	movl	k(%rip), %r8d
	cmpq	%rcx, %rax
	movl	%r8d, %r11d
	jne	.L97
	.p2align 4,,10
.L98:
	subl	$1, %r14d
	jne	.L93
	movl	44(%rsp), %eax
	movl	%r11d, %r14d
	leal	-1(%rax), %r9d
.L90:
	testl	%r11d, %r11d
	jle	.L108
	leal	-1(%r11), %r10d
	movl	$1, %ecx
	xorl	%r11d, %r11d
	addq	$2, %r10
	.p2align 4,,10
.L101:
	movq	(%rdi,%rcx,8), %rax
	testq	%rax, %rax
	jle	.L100
	subq	$1, %rax
	cqto
	idivq	%rcx
	addq	$1, %rax
	cmpq	%rax, %r11
	cmovl	%rax, %r11
.L100:
	addq	$1, %rcx
	cmpq	%r10, %rcx
	jne	.L101
	addq	%r11, %r12
.L128:
	cmpl	%r9d, %r14d
	movl	%r9d, 44(%rsp)
	jle	.L102
.L78:
	leaq	.LC0(%rip), %rcx
	movq	%r12, %rdx
	call	_Z6printfPKcz
	movq	%rbp, %rcx
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
	xorl	%eax, %eax
	addq	$216, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L106:
	cmpl	%r14d, %r9d
	movq	%rcx, %rax
	movl	%r9d, %r11d
	movq	%r10, %rcx
	je	.L84
.L126:
	movslq	%r9d, %rax
	movq	(%rdi,%rax,8), %rax
	testq	%rax, %rax
	jle	.L89
	subq	$1, %rax
	movslq	%r14d, %rcx
	cqto
	idivq	%rcx
	movslq	%r8d, %rdx
	movq	112(%rsp), %rcx
	addq	$1, %rax
	imulq	%rax, %rdx
	addq	%rax, %r12
	addq	%rax, %rbx
	movq	%rax, 128(%rsp)
	addq	%rdx, %rsi
	leaq	-16(%rcx), %rdx
	cmpq	%rdx, %r10
	je	.L87
	testq	%r10, %r10
	je	.L88
	movl	44(%rsp), %edx
	movq	%rax, 8(%r10)
	movl	%edx, (%r10)
.L88:
	addq	$16, %r10
	movq	%r10, 96(%rsp)
.L89:
	subl	$1, %r9d
	cmpl	%r9d, %r14d
	movl	%r9d, 44(%rsp)
	jle	.L102
	jmp	.L78
.L87:
	movq	%r13, %r8
	movq	%r15, %rdx
	movq	%rbp, %rcx
.LEHB7:
	call	_ZNSt5dequeISt4pairIixESaIS1_EE16_M_push_back_auxIIRiRxEEEvDpOT_
.LEHE7:
	movl	k(%rip), %r8d
	movl	44(%rsp), %r9d
	movl	%r8d, %r14d
	jmp	.L89
.L108:
	xorl	%r11d, %r11d
	addq	%r11, %r12
	jmp	.L128
.L105:
	xorl	%r12d, %r12d
	jmp	.L78
.L109:
	movq	%rax, %rbx
	movq	%r13, %rcx
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
	movq	%rbx, %rcx
.LEHB8:
	call	_Unwind_Resume
.L107:
	movl	%r14d, %r9d
	movl	%r11d, %r14d
	jmp	.L90
.L110:
	movq	%rax, %rbx
	movq	%rbp, %rcx
	call	_ZNSt11_Deque_baseISt4pairIixESaIS1_EED2Ev
	movq	%rbx, %rcx
	call	_Unwind_Resume
	nop
.LEHE8:
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA6860:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE6860-.LLSDACSB6860
.LLSDACSB6860:
	.uleb128 .LEHB5-.LFB6860
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB6860
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L109-.LFB6860
	.uleb128 0
	.uleb128 .LEHB7-.LFB6860
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L110-.LFB6860
	.uleb128 0
	.uleb128 .LEHB8-.LFB6860
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE6860:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I__Z4readv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z4readv
_GLOBAL__sub_I__Z4readv:
.LFB7188:
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
	.quad	_GLOBAL__sub_I__Z4readv
	.globl	a
	.bss
	.align 64
a:
	.space 2400080
	.globl	k
	.align 4
k:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");