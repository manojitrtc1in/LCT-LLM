__asm__(R"(
	.file	"0CF\261\310\310\374\323\303qwq.cpp"
	.text
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11022:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	*__imp___iob_func(%rip)
	movq	_ZN2IO2oSE(%rip), %r8
	leaq	_ZN2IO4obufE(%rip), %rbx
	leaq	48(%rax), %r9
	movl	$1, %edx
	movq	%rbx, %rcx
	subq	%rbx, %r8
	call	fwrite
	movq	%rbx, _ZN2IO2oSE(%rip)
	addq	$32, %rsp
	popq	%rbx
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA11022:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE11022-.LLSDACSB11022
.LLSDACSB11022:
.LLSDACSE11022:
	.text
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11021:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.globl	_Z4qmulxxx
	.def	_Z4qmulxxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4qmulxxx
_Z4qmulxxx:
.LFB10033:
	.seh_endprologue
	movq	%rdx, %r9
	sarq	$25, %rdx
	movq	%rdx, %rax
	andl	$33554431, %r9d
	imulq	%rcx, %rax
	cqto
	idivq	%r8
	movq	%rdx, %rax
	salq	$25, %rax
	cqto
	idivq	%r8
	movq	%rcx, %rax
	imulq	%r9, %rax
	movq	%rdx, %r10
	cqto
	idivq	%r8
	leaq	(%r10,%rdx), %rax
	cqto
	idivq	%r8
	movq	%rdx, %rax
	ret
	.seh_endproc
	.globl	_Z4qpowxxx
	.def	_Z4qpowxxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4qpowxxx
_Z4qpowxxx:
.LFB10034:
	.seh_endprologue
	movl	$1, %r9d
	movq	%rdx, %r10
.L5:
	testq	%rcx, %rcx
	je	.L12
	testb	$1, %cl
	je	.L6
	movq	%r9, %rax
	imulq	%r10, %rax
	cqto
	idivq	%r8
	movq	%rdx, %r9
.L6:
	movq	%r10, %rax
	sarq	%rcx
	imulq	%r10, %rax
	cqto
	idivq	%r8
	movq	%rdx, %r10
	jmp	.L5
.L12:
	movq	%r9, %rax
	cqto
	idivq	%r8
	movq	%rdx, %rax
	ret
	.seh_endproc
	.globl	_Z3gcdxx
	.def	_Z3gcdxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3gcdxx
_Z3gcdxx:
.LFB10035:
	.seh_endprologue
.L16:
	testq	%rdx, %rdx
	movq	%rcx, %rax
	movq	%rdx, %rcx
	je	.L14
	cqto
	idivq	%rcx
	jmp	.L16
.L14:
	ret
	.seh_endproc
	.globl	_Z3lcmxx
	.def	_Z3lcmxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3lcmxx
_Z3lcmxx:
.LFB10036:
	.seh_endprologue
	movq	%rdx, %r10
	movq	%rdx, %r9
	movq	%rcx, %r8
.L19:
	testq	%r9, %r9
	je	.L18
	movq	%r8, %rax
	movq	%r9, %r8
	cqto
	idivq	%r9
	movq	%rdx, %r9
	jmp	.L19
.L18:
	movq	%rcx, %rax
	cqto
	idivq	%r8
	imulq	%r10, %rax
	ret
	.seh_endproc
	.globl	_ZN4Comb4initEii
	.def	_ZN4Comb4initEii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4Comb4initEii
_ZN4Comb4initEii:
.LFB10037:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	$1, 8+_ZN4Comb3InvE(%rip)
	movq	$1, 8+_ZN4Comb3facE(%rip)
	movl	$2, %r9d
	movslq	%edx, %rsi
	movl	%ecx, %ebx
	movq	$1, _ZN4Comb3InvE(%rip)
	movq	%rsi, %rcx
	movl	%esi, _ZN4Comb1pE(%rip)
	movq	$1, _ZN4Comb3facE(%rip)
.L21:
	cmpl	%r9d, %ebx
	leaq	_ZN4Comb3facE(%rip), %r8
	jl	.L25
	leaq	-8+_ZN4Comb3facE(%rip), %rax
	movq	%r9, %rdi
	imulq	(%rax,%r9,8), %rdi
	movq	%rdi, %rax
	cqto
	idivq	%rsi
	movq	%rdx, (%r8,%r9,8)
	incq	%r9
	jmp	.L21
.L25:
	movslq	%ebx, %rdi
	subl	$2, %ecx
	movq	(%r8,%rdi,8), %rdx
	movslq	%ecx, %rcx
	movq	%rsi, %r8
	call	_Z4qpowxxx
	leal	-1(%rbx), %ecx
	leaq	_ZN4Comb3InvE(%rip), %r10
	movslq	%ecx, %r9
	movq	%rax, (%r10,%rdi,8)
	incq	%r9
.L23:
	cmpl	$1, %ecx
	jle	.L26
	leal	1(%rcx), %eax
	movq	%r9, %rbx
	movslq	%ecx, %r8
	decq	%r9
	decl	%ecx
	cltq
	imulq	(%r10,%rax,8), %rbx
	movq	%rbx, %rax
	cqto
	idivq	%rsi
	movq	%rdx, (%r10,%r8,8)
	jmp	.L23
.L26:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.globl	_Z7My_Randx
	.def	_Z7My_Randx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7My_Randx
_Z7My_Randx:
.LFB10040:
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	cmpq	$311, 2496+rnd(%rip)
	leaq	rnd(%rip), %r8
	jbe	.L28
	leaq	1248+rnd(%rip), %r11
	movq	%r8, %rdx
	movq	%r8, %r9
	movabsq	$-5403634167711393303, %rbx
.L30:
	movq	(%r9), %rax
	movq	8(%r9), %r10
	andq	$-2147483648, %rax
	andl	$2147483647, %r10d
	orq	%r10, %rax
	movq	%rax, %r10
	shrq	%r10
	xorq	1248(%r9), %r10
	andl	$1, %eax
	cmovne	%rbx, %rax
	addq	$8, %r9
	xorq	%r10, %rax
	movq	%rax, -8(%r9)
	cmpq	%r11, %r9
	jne	.L30
	leaq	1240+rnd(%rip), %r10
	movabsq	$-5403634167711393303, %r11
.L32:
	movq	1248(%rdx), %rax
	movq	1256(%rdx), %r9
	andq	$-2147483648, %rax
	andl	$2147483647, %r9d
	orq	%r9, %rax
	movq	%rax, %r9
	shrq	%r9
	xorq	(%rdx), %r9
	andl	$1, %eax
	cmovne	%r11, %rax
	addq	$8, %rdx
	xorq	%r9, %rax
	movq	%rax, 1240(%rdx)
	cmpq	%r10, %rdx
	jne	.L32
	movq	2488+rnd(%rip), %rax
	movq	rnd(%rip), %rdx
	movabsq	$-5403634167711393303, %r9
	movq	$0, 2496+rnd(%rip)
	andl	$2147483647, %edx
	andq	$-2147483648, %rax
	orq	%rdx, %rax
	movq	%rax, %rdx
	shrq	%rdx
	xorq	1240+rnd(%rip), %rdx
	andl	$1, %eax
	cmovne	%r9, %rax
	xorq	%rdx, %rax
	movq	%rax, 2488+rnd(%rip)
.L28:
	movq	2496+rnd(%rip), %rax
	movq	(%r8,%rax,8), %r9
	leaq	1(%rax), %rdx
	movabsq	$6148914691236517205, %rax
	movq	%rdx, 2496+rnd(%rip)
	movq	%r9, %r8
	shrq	$29, %r8
	andq	%rax, %r8
	movabsq	$8202884508482404352, %rax
	movq	%r8, %rdx
	xorq	%r9, %rdx
	movq	%rdx, %r8
	salq	$17, %r8
	andq	%r8, %rax
	xorq	%rdx, %rax
	movq	%rax, %rdx
	movq	%rax, %r8
	movabsq	$-2270628950310912, %rax
	salq	$37, %rdx
	andq	%rdx, %rax
	xorq	%r8, %rax
	movq	%rax, %rdx
	shrq	$43, %rdx
	xorq	%rdx, %rax
	xorl	%edx, %edx
	divq	%rcx
	movq	%rdx, %rax
	popq	%rbx
	ret
	.seh_endproc
	.globl	_Z8InitHashRyRiS_
	.def	_Z8InitHashRyRiS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8InitHashRyRiS_
_Z8InitHashRyRiS_:
.LFB10043:
	.seh_endprologue
	movabsq	$212370440130137957, %rax
	movq	$131, (%rcx)
	movl	$233317, (%rdx)
	movq	%rax, (%r8)
	ret
	.seh_endproc
	.section	.text$_ZStltIiiEbRKSt4pairIT_T0_ES5_,"x"
	.linkonce discard
	.globl	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	.def	_ZStltIiiEbRKSt4pairIT_T0_ES5_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZStltIiiEbRKSt4pairIT_T0_ES5_
_ZStltIiiEbRKSt4pairIT_T0_ES5_:
.LFB10847:
	.seh_endprologue
	movl	(%rcx), %r8d
	movl	(%rdx), %r9d
	movb	$1, %al
	cmpl	%r9d, %r8d
	jl	.L41
	xorl	%eax, %eax
	cmpl	%r8d, %r9d
	jl	.L41
	movl	4(%rdx), %eax
	cmpl	%eax, 4(%rcx)
	setl	%al
.L41:
	ret
	.seh_endproc
	.text
	.def	_ZSt25__unguarded_linear_insertIPSt4pairIiiEN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.9;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt25__unguarded_linear_insertIPSt4pairIiiEN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.9
_ZSt25__unguarded_linear_insertIPSt4pairIiiEN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.9:
.LFB11063:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	(%rcx), %rax
	leaq	-8(%rcx), %rbx
	leaq	40(%rsp), %rdi
	movq	%rax, 40(%rsp)
.L45:
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L47
	movl	(%rbx), %eax
	subq	$8, %rbx
	movl	%eax, 16(%rbx)
	movl	12(%rbx), %eax
	movl	%eax, 20(%rbx)
	jmp	.L45
.L47:
	movl	40(%rsp), %eax
	movl	%eax, 8(%rbx)
	movl	44(%rsp), %eax
	movl	%eax, 12(%rbx)
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_,"x"
	.linkonce discard
	.globl	_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_
	.def	_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_
_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_:
.LFB10844:
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
	movq	%rdx, %rbp
	movq	%rcx, %rbx
	movq	%r8, %rdx
	movq	%rbp, %rcx
	movq	%r9, %rsi
	movq	%r8, %rdi
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	movq	%rsi, %rdx
	movl	(%rbx), %r12d
	je	.L49
	movq	%rdi, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L50
.L54:
	movl	(%rdi), %eax
	movl	%eax, (%rbx)
	movl	%r12d, (%rdi)
	movl	4(%rdi), %edx
	movl	4(%rbx), %eax
	movl	%edx, 4(%rbx)
	movl	%eax, 4(%rdi)
	jmp	.L48
.L50:
	movq	%rsi, %rdx
	movq	%rbp, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L52
.L53:
	movl	(%rsi), %eax
	movl	%eax, (%rbx)
	movl	%r12d, (%rsi)
	movl	4(%rsi), %edx
	movl	4(%rbx), %eax
	movl	%edx, 4(%rbx)
	movl	%eax, 4(%rsi)
	jmp	.L48
.L49:
	movq	%rbp, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L58
.L52:
	movl	0(%rbp), %eax
	movl	%eax, (%rbx)
	movl	%r12d, 0(%rbp)
	movl	4(%rbp), %edx
	movl	4(%rbx), %eax
	movl	%edx, 4(%rbx)
	movl	%eax, 4(%rbp)
	jmp	.L48
.L58:
	movq	%rsi, %rdx
	movq	%rdi, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L54
	jmp	.L53
.L48:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.seh_endproc
	.text
	.def	_ZSt16__insertion_sortIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_.isra.11.constprop.28;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_.isra.11.constprop.28
_ZSt16__insertion_sortIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_.isra.11.constprop.28:
.LFB11079:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	8+l(%rip), %rax
	leaq	16+l(%rip), %rbx
	movq	%rcx, %rdi
	cmpq	%rax, %rcx
	movq	%rax, %rsi
	je	.L59
.L68:
	cmpq	%rdi, %rbx
	je	.L59
	leaq	8+l(%rip), %rdx
	movq	%rbx, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L61
	movq	%rbx, %rdx
	movl	(%rbx), %r8d
	movl	4(%rbx), %ecx
	subq	%rsi, %rdx
	movq	%rbx, %rax
	sarq	$3, %rdx
.L62:
	testq	%rdx, %rdx
	jle	.L69
	subq	$8, %rax
	movl	(%rax), %r9d
	decq	%rdx
	movl	%r9d, 8(%rax)
	movl	4(%rax), %r9d
	movl	%r9d, 12(%rax)
	jmp	.L62
.L69:
	movl	%r8d, 8+l(%rip)
	movl	%ecx, 12+l(%rip)
	jmp	.L64
.L61:
	movq	%rbx, %rcx
	call	_ZSt25__unguarded_linear_insertIPSt4pairIiiEN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.9
.L64:
	addq	$8, %rbx
	jmp	.L68
.L59:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_,"x"
	.linkonce discard
	.globl	_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_
	.def	_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_
_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_:
.LFB10921:
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
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	leaq	-1(%r8), %rax
	movq	%rdx, %rbp
	movq	%rcx, %rsi
	movl	$2, %ecx
	movq	%rbp, %rbx
	cqto
	idivq	%rcx
	movq	%rax, %rdi
.L71:
	cmpq	%rdi, %rbx
	jge	.L85
	leaq	2(%rbx,%rbx), %r12
	movq	%r9, 40(%rsp)
	movq	%r8, 32(%rsp)
	leaq	0(,%r12,8), %r10
	leaq	-8(%rsi,%r10), %rdx
	leaq	(%rsi,%r10), %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	leaq	-1(%r12), %rcx
	testb	%al, %al
	leaq	(%rsi,%rbx,8), %rax
	movq	40(%rsp), %r9
	movq	32(%rsp), %r8
	cmove	%r12, %rcx
	leaq	(%rsi,%rcx,8), %rdx
	movq	%rcx, %rbx
	movl	(%rdx), %r10d
	movl	%r10d, (%rax)
	movl	4(%rdx), %edx
	movl	%edx, 4(%rax)
	jmp	.L71
.L85:
	testb	$1, %r8b
	jne	.L74
	leaq	-2(%r8), %rax
	movl	$2, %ecx
	cqto
	idivq	%rcx
	cmpq	%rax, %rbx
	jne	.L74
	leaq	2(%rbx,%rbx), %rax
	leaq	(%rsi,%rbx,8), %rdx
	leaq	-8(%rsi,%rax,8), %rcx
	leaq	-1(%rax), %rbx
	movl	(%rcx), %r8d
	movl	%r8d, (%rdx)
	movl	4(%rcx), %ecx
	movl	%ecx, 4(%rdx)
.L74:
	leaq	-1(%rbx), %rax
	movl	$2, %ecx
	leaq	56(%rsp), %r13
	movq	%r9, 56(%rsp)
	movl	$2, %r12d
	cqto
	idivq	%rcx
	movq	%rax, %rdi
.L75:
	cmpq	%rbp, %rbx
	jg	.L76
.L77:
	movl	56(%rsp), %edx
	leaq	(%rsi,%rbx,8), %rax
	movl	%edx, (%rax)
	movl	60(%rsp), %edx
	movl	%edx, 4(%rax)
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
.L76:
	leaq	(%rsi,%rdi,8), %r14
	movq	%r13, %rdx
	movq	%r14, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L77
	movl	(%r14), %edx
	leaq	(%rsi,%rbx,8), %rax
	movq	%rdi, %rbx
	movl	%edx, (%rax)
	movl	4(%r14), %edx
	movl	%edx, 4(%rax)
	leaq	-1(%rdi), %rax
	cqto
	idivq	%r12
	movq	%rax, %rdi
	jmp	.L75
	.seh_endproc
	.text
	.def	_ZSt16__introsort_loopIPSt4pairIiiExN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_T1_.isra.23;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPSt4pairIiiExN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_T1_.isra.23
_ZSt16__introsort_loopIPSt4pairIiiExN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_T1_.isra.23:
.LFB11077:
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
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	8(%rcx), %r13
	movq	%rcx, %rbx
	movq	%rdx, %rsi
	movq	%r8, %r12
.L87:
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$135, %rax
	jle	.L86
	testq	%r12, %r12
	jne	.L88
	sarq	$3, %rax
	leaq	-2(%rax), %rbp
	movq	%rax, %rdi
	sarq	%rbp
.L90:
	movq	(%rbx,%rbp,8), %r9
	movb	$0, 32(%rsp)
	movq	%rdi, %r8
	movq	%rbp, %rdx
	movq	%rbx, %rcx
	call	_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_
	testq	%rbp, %rbp
	je	.L91
	decq	%rbp
	jmp	.L90
.L91:
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$15, %rax
	jle	.L86
	movl	(%rbx), %eax
	subq	$8, %rsi
	movq	(%rsi), %r9
	movq	%rsi, %r8
	xorl	%edx, %edx
	movq	%rbx, %rcx
	subq	%rbx, %r8
	movl	%eax, (%rsi)
	movl	4(%rbx), %eax
	sarq	$3, %r8
	movl	%eax, 4(%rsi)
	movb	$0, 32(%rsp)
	call	_ZSt13__adjust_heapIPSt4pairIiiExS1_N9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S7_T1_T2_
	jmp	.L91
.L88:
	sarq	$4, %rax
	leaq	-8(%rsi), %r9
	movb	$0, 32(%rsp)
	leaq	(%rbx,%rax,8), %r8
	movq	%r13, %rdx
	movq	%rbx, %rcx
	decq	%r12
	movq	%r13, %rdi
	movq	%rsi, %r14
	call	_ZSt22__move_median_to_firstIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_S6_S6_T0_
.L93:
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	leaq	-8(%r14), %rbp
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L95
.L94:
	addq	$8, %rdi
	jmp	.L93
.L95:
	movq	%rbp, %rdx
	movq	%rbx, %rcx
	call	_ZStltIiiEbRKSt4pairIT_T0_ES5_
	testb	%al, %al
	je	.L104
	subq	$8, %rbp
	jmp	.L95
.L104:
	cmpq	%rbp, %rdi
	movq	%rbp, %r14
	jae	.L103
	movl	(%rdi), %eax
	movl	0(%rbp), %edx
	movl	%edx, (%rdi)
	movl	%eax, 0(%rbp)
	movl	4(%rbp), %edx
	movl	4(%rdi), %eax
	movl	%edx, 4(%rdi)
	movl	%eax, 4(%rbp)
	jmp	.L94
.L103:
	movq	%rsi, %rdx
	movq	%r12, %r8
	movq	%rdi, %rcx
	call	_ZSt16__introsort_loopIPSt4pairIiiExN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_T1_.isra.23
	movq	%rdi, %rsi
	jmp	.L87
.L86:
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "? \0"
.LC1:
	.ascii "! \0"
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10047:
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
	leaq	8+l(%rip), %rsi
	movl	$1, %ebx
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	n(%rip), %rdx
	movq	%rsi, %r12
	call	_ZNSirsERi
	leaq	m(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movq	.refptr._ZSt4cout(%rip), %rdi
	movq	%rdi, %r13
	movq	%rdi, %r14
.L106:
	movslq	m(%rip), %rax
	cmpl	%eax, %ebx
	jg	.L127
	leaq	.LC0(%rip), %rdx
	movq	%rdi, %rcx
	movl	$1, %ebp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L107:
	cmpl	%ebp, %ebx
	jle	.L128
	movl	$48, %edx
	movq	%r13, %rcx
	incl	%ebp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	.L107
.L128:
	movq	.refptr._ZSt4cout(%rip), %rcx
	leal	1(%rbx), %r15d
	movl	$49, %edx
	movl	%r15d, %ebp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.L109:
	cmpl	m(%rip), %ebp
	jg	.L129
	movl	$48, %edx
	movq	%r14, %rcx
	incl	%ebp
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	.L109
.L129:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%rsi, %rdx
	addq	$8, %rsi
	call	_ZNSirsERi
	movl	%ebx, -4(%rsi)
	movl	%r15d, %ebx
	jmp	.L106
.L127:
	leaq	l(%rip), %rsi
	leaq	8+l(%rip), %rcx
	leaq	8(%rsi,%rax,8), %rbx
	cmpq	%r12, %rbx
	je	.L113
	movq	%rbx, %rdi
	movl	$63, %r8d
	movq	%rbx, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rax
	sarq	$3, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPSt4pairIiiExN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_T1_.isra.23
	cmpq	$135, %rdi
	jle	.L114
	leaq	136+l(%rip), %rcx
	leaq	136+l(%rip), %rdi
	call	_ZSt16__insertion_sortIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_.isra.11.constprop.28
.L115:
	cmpq	%rbx, %rdi
	je	.L113
	movq	%rdi, %rcx
	addq	$8, %rdi
	call	_ZSt25__unguarded_linear_insertIPSt4pairIiiEN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_.isra.9
	jmp	.L115
.L114:
	movq	%rbx, %rcx
	call	_ZSt16__insertion_sortIPSt4pairIiiEN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S6_T0_.isra.11.constprop.28
.L113:
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC0(%rip), %rdx
	movl	$1, %ebx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L118:
	cmpl	m(%rip), %ebx
	jg	.L130
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$49, %edx
	incl	%ebx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	.L118
.L130:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	all(%rip), %rdx
	call	_ZNSirsERi
	movl	m(%rip), %ebx
	xorl	%eax, %eax
.L120:
	incq	%rax
	cmpl	%eax, %ebx
	jl	.L131
	leaq	chs(%rip), %rdx
	movl	$1, (%rdx,%rax,4)
	jmp	.L120
.L131:
	movl	all(%rip), %ebp
	movl	8+l(%rip), %edi
	leaq	44(%rsp), %r13
	movq	.refptr._ZSt4cout(%rip), %r12
.L122:
	cmpl	$1, %ebx
	jle	.L132
	movslq	%ebx, %r14
	leaq	chs(%rip), %rax
	movq	.refptr._ZSt4cout(%rip), %rcx
	movslq	4(%rsi,%r14,8), %rdx
	xorl	%r15d, %r15d
	movl	$0, (%rax,%rdx,4)
	leaq	.LC0(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L123:
	leal	1(%r15), %eax
	cmpl	m(%rip), %eax
	jg	.L133
	leaq	4+chs(%rip), %rax
	movq	%r12, %rcx
	movl	(%rax,%r15,4), %edx
	incq	%r15
	call	_ZNSolsEi
	jmp	.L123
.L133:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%r13, %rdx
	call	_ZNSirsERi
	movl	(%rsi,%r14,8), %eax
	movl	44(%rsp), %edx
	subl	%eax, %ebp
	addl	%edi, %eax
	cmpl	%ebp, %edx
	movl	%edx, %ebp
	cmove	%eax, %edi
	decl	%ebx
	jmp	.L122
.L132:
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC1(%rip), %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%edi, %edx
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	xorl	%eax, %eax
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
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN2IO4ibufE;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN2IO4ibufE
_GLOBAL__sub_I__ZN2IO4ibufE:
.LFB11053:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	__tcf_1(%rip), %rcx
	call	atexit
	call	_ZNSt6chrono3_V212steady_clock3nowEv
	incq	%rax
	movl	$1, %ecx
	movabsq	$6364136223846793005, %r10
	movq	%rax, rnd(%rip)
	movl	$312, %r9d
.L135:
	leaq	-8+rnd(%rip), %rax
	xorl	%edx, %edx
	movq	(%rax,%rcx,8), %rax
	movq	%rax, %r8
	shrq	$62, %r8
	xorq	%r8, %rax
	imulq	%r10, %rax
	movq	%rax, %r8
	movq	%rcx, %rax
	divq	%r9
	leaq	rnd(%rip), %rax
	addq	%r8, %rdx
	movq	%rdx, (%rax,%rcx,8)
	incq	%rcx
	cmpq	$312, %rcx
	jne	.L135
	movq	$312, 2496+rnd(%rip)
	xorl	%eax, %eax
.L136:
	leaq	l(%rip), %rdx
	movl	$0, (%rdx,%rax)
	leaq	4+l(%rip), %rdx
	movl	$0, (%rdx,%rax)
	addq	$8, %rax
	cmpq	$4040, %rax
	jne	.L136
	addq	$40, %rsp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN2IO4ibufE
	.globl	chs
	.bss
	.align 64
chs:
	.space 2020
	.globl	all
	.align 4
all:
	.space 4
	.globl	id
	.align 64
id:
	.space 2020
	.globl	l
	.align 64
l:
	.space 4040
	.globl	m
	.align 4
m:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	rnd
	.align 64
rnd:
	.space 2504
	.globl	_ZN4Comb3InvE
	.align 64
_ZN4Comb3InvE:
	.space 8000040
	.globl	_ZN4Comb3facE
	.align 64
_ZN4Comb3facE:
	.space 8000040
	.globl	_ZN4Comb1pE
	.align 4
_ZN4Comb1pE:
	.space 4
	.globl	_ZN2IO10io_flusherE
_ZN2IO10io_flusherE:
	.space 1
	.globl	_ZN2IO3_qrE
	.align 4
_ZN2IO3_qrE:
	.space 4
	.globl	_ZN2IO3_stE
	.align 16
_ZN2IO3_stE:
	.space 55
	.globl	_ZN2IO2oTE
	.data
	.align 8
_ZN2IO2oTE:
	.quad	_ZN2IO4obufE+1048576
	.globl	_ZN2IO2oSE
	.align 8
_ZN2IO2oSE:
	.quad	_ZN2IO4obufE
	.globl	_ZN2IO4obufE
	.bss
	.align 64
_ZN2IO4obufE:
	.space 1048577
	.globl	_ZN2IO2iTE
	.align 8
_ZN2IO2iTE:
	.space 8
	.globl	_ZN2IO2iSE
	.align 8
_ZN2IO2iSE:
	.space 8
	.globl	_ZN2IO4ibufE
	.align 64
_ZN2IO4ibufE:
	.space 1048577
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.def	_ZNSt6chrono3_V212steady_clock3nowEv;	.scl	2;	.type	32;	.endef
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