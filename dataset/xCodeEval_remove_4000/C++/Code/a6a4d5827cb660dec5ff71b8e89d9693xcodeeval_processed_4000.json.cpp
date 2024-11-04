__asm__(R"(
	.file	"cf1720b.cpp"
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB9901:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.def	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0
_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0:
.LFB9934:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	-1(%r8), %rax
	movq	%r8, %rbp
	movq	%rdx, %r11
	movq	%rax, %rdi
	andl	$1, %ebp
	shrq	$63, %rdi
	addq	%rax, %rdi
	sarq	%rdi
	cmpq	%rdi, %rdx
	jge	.L4
	movq	%rdx, %rbx
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L16:
	subq	$1, %rax
	leaq	(%rcx,%rax,4), %r10
	movl	(%r10), %edx
	movl	%edx, (%rcx,%rbx,4)
	cmpq	%rdi, %rax
	jge	.L6
.L7:
	movq	%rax, %rbx
.L8:
	leaq	1(%rbx), %rdx
	leaq	(%rdx,%rdx), %rax
	salq	$3, %rdx
	leaq	(%rcx,%rdx), %r10
	movl	(%r10), %esi
	cmpl	-4(%rcx,%rdx), %esi
	jl	.L16
	movl	%esi, (%rcx,%rbx,4)
	cmpq	%rdi, %rax
	jl	.L7
.L6:
	testq	%rbp, %rbp
	je	.L12
.L9:
	leaq	-1(%rax), %rdx
	movq	%rdx, %r8
	shrq	$63, %r8
	addq	%rdx, %r8
	sarq	%r8
	cmpq	%r11, %rax
	jg	.L11
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L18:
	movl	%edx, (%r10)
	leaq	-1(%r8), %rdx
	movq	%rdx, %rax
	shrq	$63, %rax
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, %rdx
	movq	%r8, %rax
	cmpq	%r8, %r11
	jge	.L17
	movq	%rdx, %r8
.L11:
	leaq	(%rcx,%r8,4), %rbx
	leaq	(%rcx,%rax,4), %r10
	movl	(%rbx), %edx
	cmpl	%r9d, %edx
	jl	.L18
.L10:
	movl	%r9d, (%r10)
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	leaq	(%rcx,%rdx,4), %r10
	testq	%rbp, %rbp
	jne	.L10
	movq	%r11, %rax
	.p2align 4,,10
	.p2align 3
.L12:
	leaq	-2(%r8), %rdx
	movq	%rdx, %r8
	shrq	$63, %r8
	addq	%rdx, %r8
	sarq	%r8
	cmpq	%r8, %rax
	jne	.L9
	leaq	2(%rax,%rax), %rax
	movl	-4(%rcx,%rax,4), %edx
	subq	$1, %rax
	movl	%edx, (%r10)
	leaq	(%rcx,%rax,4), %r10
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L17:
	movq	%rbx, %r10
	movl	%r9d, (%r10)
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.p2align 4
	.def	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.0
_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.0:
.LFB9927:
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
	movq	%rdx, %rax
	movq	%rcx, %rdi
	movq	%rdx, %r10
	movq	%r8, %r12
	subq	%rcx, %rax
	cmpq	$64, %rax
	jle	.L19
	leaq	4(%rcx), %rbp
	testq	%r8, %r8
	je	.L48
.L23:
	sarq	$3, %rax
	movl	4(%rdi), %ecx
	movl	-4(%r10), %r8d
	subq	$1, %r12
	leaq	(%rdi,%rax,4), %r9
	movl	(%rdi), %edx
	movl	(%r9), %eax
	cmpl	%eax, %ecx
	jge	.L28
	cmpl	%r8d, %eax
	jl	.L47
	cmpl	%r8d, %ecx
	jge	.L31
.L46:
	movl	%r8d, (%rdi)
	movl	%edx, -4(%r10)
	movl	(%rdi), %ecx
.L32:
	movq	%rbp, %rbx
	movq	%r10, %rax
	.p2align 4,,10
	.p2align 3
.L30:
	movl	(%rbx), %r9d
	movq	%rbx, %rsi
	cmpl	%ecx, %r9d
	jl	.L35
	subq	$4, %rax
	cmpl	%edx, %ecx
	jge	.L36
	.p2align 4,,10
	.p2align 3
.L37:
	movl	-4(%rax), %edx
	subq	$4, %rax
	cmpl	%ecx, %edx
	jg	.L37
.L36:
	cmpq	%rbx, %rax
	jbe	.L49
	movl	%edx, (%rbx)
	movl	-4(%rax), %edx
	movl	%r9d, (%rax)
	movl	(%rdi), %ecx
.L35:
	addq	$4, %rbx
	jmp	.L30
	.p2align 4,,10
	.p2align 3
.L49:
	movq	%r12, %r8
	movq	%r10, %rdx
	movq	%rbx, %rcx
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.0
	movq	%rbx, %rax
	subq	%rdi, %rax
	cmpq	$64, %rax
	jle	.L19
	testq	%r12, %r12
	je	.L21
	movq	%rbx, %r10
	jmp	.L23
.L28:
	cmpl	%r8d, %ecx
	jge	.L33
	movd	%edx, %xmm1
	movd	%ecx, %xmm0
	punpckldq	%xmm1, %xmm0
	movq	%xmm0, (%rdi)
	movl	-4(%r10), %edx
	jmp	.L32
.L33:
	cmpl	%r8d, %eax
	jl	.L46
.L47:
	movl	%eax, (%rdi)
	movl	%edx, (%r9)
	movl	(%rdi), %ecx
	movl	-4(%r10), %edx
	jmp	.L32
.L48:
	movq	%rdx, %rsi
.L21:
	sarq	$2, %rax
	movq	%rdi, %rcx
	leaq	-2(%rax), %rbp
	movq	%rax, %r8
	movq	%rax, %rbx
	sarq	%rbp
	movl	(%rdi,%rbp,4), %r9d
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0
.L24:
	subq	$1, %rbp
	movq	%rbx, %r8
	movq	%rdi, %rcx
	movl	(%rdi,%rbp,4), %r9d
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0
	testq	%rbp, %rbp
	jne	.L24
	.p2align 4,,10
	.p2align 3
.L25:
	subq	$4, %rsi
	movl	(%rdi), %eax
	movl	(%rsi), %r9d
	xorl	%edx, %edx
	movq	%rsi, %rbx
	movq	%rdi, %rcx
	subq	%rdi, %rbx
	movl	%eax, (%rsi)
	movq	%rbx, %r8
	sarq	$2, %r8
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.isra.0
	cmpq	$4, %rbx
	jg	.L25
.L19:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
.L31:
	movd	%edx, %xmm2
	movd	%ecx, %xmm0
	punpckldq	%xmm2, %xmm0
	movq	%xmm0, (%rdi)
	movl	-4(%r10), %edx
	jmp	.L32
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB50:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	leaq	88(%rsp), %rbx
	movq	%rdx, 88(%rsp)
	movq	%rcx, %r12
	movl	$1, %ecx
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	movq	%rbx, 40(%rsp)
	call	*__imp___acrt_iob_func(%rip)
	movq	%rbx, %r8
	movq	%r12, %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
	.text
	.p2align 4
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB8592:
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
	call	getchar
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L80
	.p2align 4,,10
	.p2align 3
.L53:
	call	getchar
	movl	%ebx, %edx
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	ja	.L53
	cmpb	$45, %dl
	sete	%sil
.L52:
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L54:
	leal	0(,%rdi,8), %eax
	xorl	$48, %ebx
	leal	(%rax,%rdi,2), %edi
	movsbl	%bl, %ebx
	call	getchar
	addl	%ebx, %edi
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L54
	movl	%edi, %eax
	leaq	4+a(%rip), %r13
	movl	$1, %ebp
	negl	%eax
	testb	%sil, %sil
	movq	%r13, %rsi
	cmovne	%eax, %edi
	testl	%edi, %edi
	jle	.L63
	.p2align 4,,10
	.p2align 3
.L64:
	movl	$0, (%rsi)
	call	getchar
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L81
	.p2align 4,,10
	.p2align 3
.L60:
	call	getchar
	movl	%ebx, %edx
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	ja	.L60
	cmpb	$45, %dl
	sete	%r12b
	.p2align 4,,10
	.p2align 3
.L61:
	movl	(%rsi), %eax
	xorl	$48, %ebx
	movsbl	%bl, %ebx
	leal	0(,%rax,8), %edx
	leal	(%rdx,%rax,2), %eax
	addl	%eax, %ebx
	movl	%ebx, (%rsi)
	call	getchar
	movl	%eax, %ebx
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L61
	movl	(%rsi), %eax
	movl	%eax, %edx
	negl	%edx
	testb	%r12b, %r12b
	cmovne	%edx, %eax
	addl	$1, %ebp
	addq	$4, %rsi
	movl	%eax, -4(%rsi)
	cmpl	%edi, %ebp
	jle	.L64
.L63:
	leal	1(%rdi), %eax
	leaq	a(%rip), %rbx
	cltq
	leaq	(%rbx,%rax,4), %rbp
	cmpq	%r13, %rbp
	je	.L100
	movq	%rbp, %rsi
	movl	$63, %r8d
	movq	%rbp, %rdx
	subq	%r13, %rsi
	leaq	4+a(%rip), %rcx
	movq	%rsi, %rax
	sarq	$2, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	subl	%eax, %r8d
	movslq	%r8d, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.0
	cmpq	$64, %rsi
	jg	.L103
	leaq	8+a(%rip), %r15
	movl	4+a(%rip), %eax
	cmpq	%r15, %rbp
	je	.L72
	movl	$4, %r12d
	leaq	-4(%r15), %rsi
	jmp	.L79
	.p2align 4,,10
	.p2align 3
.L104:
	movq	%r15, %r8
	leaq	0(%r13,%r12), %rcx
	movq	%rsi, %rdx
	subq	%r13, %r8
	call	memmove
	movl	%r14d, 4+a(%rip)
	movl	%r14d, %eax
.L76:
	addq	$4, %r15
	cmpq	%r15, %rbp
	je	.L72
.L79:
	movl	(%r15), %r14d
	cmpl	%eax, %r14d
	jl	.L104
	movl	-4(%r15), %edx
	leaq	-4(%r15), %rax
	cmpl	%edx, %r14d
	jge	.L84
	.p2align 4,,10
	.p2align 3
.L78:
	movl	%edx, 4(%rax)
	movq	%rax, %rcx
	movl	-4(%rax), %edx
	subq	$4, %rax
	cmpl	%edx, %r14d
	jl	.L78
.L77:
	movl	%r14d, (%rcx)
	movl	4+a(%rip), %eax
	jmp	.L76
	.p2align 4,,10
	.p2align 3
.L81:
	xorl	%r12d, %r12d
	jmp	.L61
.L100:
	movl	4+a(%rip), %eax
.L72:
	movslq	%edi, %rdx
	leaq	.LC0(%rip), %rcx
	movl	(%rbx,%rdx,4), %edx
	subl	%eax, %edx
	leal	-1(%rdi), %eax
	cltq
	addl	(%rbx,%rax,4), %edx
	subl	8+a(%rip), %edx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	jmp	_Z6printfPKcz
.L103:
	leaq	8+a(%rip), %rsi
	leaq	60(%rsi), %r12
	leaq	-4(%rsi), %r14
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L105:
	movq	%rsi, %r8
	movl	$4, %eax
	movq	%r14, %rdx
	addq	$4, %rsi
	subq	%r13, %r8
	leaq	0(%r13,%rax), %rcx
	call	memmove
	movl	%r15d, 4+a(%rip)
	cmpq	%r12, %rsi
	je	.L102
.L70:
	movl	(%rsi), %r15d
	cmpl	4+a(%rip), %r15d
	jl	.L105
	movl	-4(%rsi), %edx
	leaq	-4(%rsi), %rax
	cmpl	%r15d, %edx
	jle	.L82
	.p2align 4,,10
	.p2align 3
.L69:
	movl	%edx, 4(%rax)
	movq	%rax, %rcx
	movl	-4(%rax), %edx
	subq	$4, %rax
	cmpl	%edx, %r15d
	jl	.L69
.L68:
	addq	$4, %rsi
	movl	%r15d, (%rcx)
	cmpq	%r12, %rsi
	jne	.L70
	.p2align 4,,10
	.p2align 3
.L102:
	cmpq	%rsi, %rbp
	je	.L100
	movl	(%rsi), %ecx
	movl	-4(%rsi), %edx
	leaq	-4(%rsi), %rax
	cmpl	%ecx, %edx
	jle	.L83
	.p2align 4,,10
	.p2align 3
.L74:
	movl	%edx, 4(%rax)
	movq	%rax, %r8
	movl	-4(%rax), %edx
	subq	$4, %rax
	cmpl	%edx, %ecx
	jl	.L74
	movl	%ecx, (%r8)
	addq	$4, %rsi
	jmp	.L102
.L83:
	movq	%rsi, %r8
	addq	$4, %rsi
	movl	%ecx, (%r8)
	jmp	.L102
.L80:
	xorl	%esi, %esi
	jmp	.L52
.L82:
	movq	%rsi, %rcx
	jmp	.L68
.L84:
	movq	%r15, %rcx
	jmp	.L77
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8593:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	getchar
	movl	%eax, %esi
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L122
	.p2align 4,,10
	.p2align 3
.L108:
	call	getchar
	movl	%esi, %edx
	movl	%eax, %esi
	subl	$48, %eax
	cmpb	$9, %al
	ja	.L108
	cmpb	$45, %dl
	sete	%dil
.L107:
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L110:
	leal	0(,%rbx,8), %eax
	xorl	$48, %esi
	leal	(%rax,%rbx,2), %ebx
	movsbl	%sil, %esi
	call	getchar
	addl	%esi, %ebx
	movl	%eax, %esi
	subl	$48, %eax
	cmpb	$9, %al
	jbe	.L110
	movl	%ebx, %eax
	negl	%eax
	testb	%dil, %dil
	cmovne	%eax, %ebx
	testl	%ebx, %ebx
	je	.L112
	.p2align 4,,10
	.p2align 3
.L113:
	call	_Z5solvev
	subl	$1, %ebx
	jne	.L113
.L112:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
.L122:
	xorl	%edi, %edi
	jmp	.L107
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB9924:
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
	.quad	_GLOBAL__sub_I_a
	.globl	a
	.bss
	.align 32
a:
	.space 400020
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (Rev5, Built by MSYS2 project) 10.3.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");