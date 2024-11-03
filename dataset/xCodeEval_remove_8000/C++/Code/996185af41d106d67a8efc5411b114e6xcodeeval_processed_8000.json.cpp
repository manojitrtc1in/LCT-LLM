__asm__(R"(
	.file	"A.cpp"
	.text
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11212:
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
.LLSDA11212:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE11212-.LLSDACSB11212
.LLSDACSB11212:
.LLSDACSE11212:
	.text
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11211:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.def	_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_T2_.isra.63;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_T2_.isra.63
_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_T2_.isra.63:
.LFB11308:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	$2, %r11d
	movl	$2, %ebp
	leaq	-1(%rdx), %rax
	movq	%rdx, %r10
	movq	%r9, %rsi
	sarq	$32, %rsi
	movl	%r9d, %ebx
	cqto
	movl	%esi, %edi
	idivq	%r11
	movq	%rax, %r11
.L4:
	cmpq	%r8, %r10
	jg	.L5
.L7:
	leaq	(%rcx,%r10,8), %rax
	movl	%r9d, (%rax)
	movl	%esi, 4(%rax)
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L5:
	leaq	(%rcx,%r11,8), %rax
	movl	(%rax), %edx
	cmpl	%ebx, %edx
	jl	.L6
	cmpl	%edx, %ebx
	jl	.L7
	cmpl	%edi, 4(%rax)
	jge	.L7
.L6:
	leaq	(%rcx,%r10,8), %r10
	movl	%edx, (%r10)
	movl	4(%rax), %eax
	movl	%eax, 4(%r10)
	leaq	-1(%r11), %rax
	movq	%r11, %r10
	cqto
	idivq	%rbp
	movq	%rax, %r11
	jmp	.L4
	.seh_endproc
	.def	__tcf_2;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_2
__tcf_2:
.LFB11213:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	xorl	%ebx, %ebx
.L13:
	leaq	4800096+e(%rip), %rax
	movq	(%rax,%rbx), %rcx
	testq	%rcx, %rcx
	je	.L12
	call	_ZdlPv
.L12:
	subq	$24, %rbx
	cmpq	$-4800120, %rbx
	jne	.L13
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section	.text$_ZN2IO2gcEv,"x"
	.linkonce discard
	.globl	_ZN2IO2gcEv
	.def	_ZN2IO2gcEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN2IO2gcEv
_ZN2IO2gcEv:
.LFB10021:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	_ZN2IO2iSE(%rip), %rax
	cmpq	_ZN2IO2iTE(%rip), %rax
	jne	.L19
	leaq	_ZN2IO4ibufE(%rip), %rbx
	movq	%rbx, _ZN2IO2iSE(%rip)
	call	*__imp___iob_func(%rip)
	movl	$1, %edx
	movq	%rbx, %rcx
	movq	%rax, %r9
	movl	$1048577, %r8d
	call	fread
	movq	_ZN2IO2iSE(%rip), %rdx
	addq	%rax, %rbx
	movb	$-1, %al
	movq	%rbx, _ZN2IO2iTE(%rip)
	cmpq	%rbx, %rdx
	je	.L20
	leaq	1(%rdx), %rax
	movq	%rax, _ZN2IO2iSE(%rip)
	movb	(%rdx), %al
	jmp	.L20
.L19:
	leaq	1(%rax), %rdx
	movq	%rdx, _ZN2IO2iSE(%rip)
	movb	(%rax), %al
.L20:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.text
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
.L24:
	testq	%rcx, %rcx
	je	.L30
	testb	$1, %cl
	je	.L25
	movq	%r9, %rax
	imulq	%r10, %rax
	cqto
	idivq	%r8
	movq	%rdx, %r9
.L25:
	movq	%r10, %rax
	sarq	%rcx
	imulq	%r10, %rax
	cqto
	idivq	%r8
	movq	%rdx, %r10
	jmp	.L24
.L30:
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
.L34:
	testq	%rdx, %rdx
	movq	%rcx, %rax
	movq	%rdx, %rcx
	je	.L32
	cqto
	idivq	%rcx
	jmp	.L34
.L32:
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
.L37:
	testq	%r9, %r9
	je	.L36
	movq	%r8, %rax
	movq	%r9, %r8
	cqto
	idivq	%r9
	movq	%rdx, %r9
	jmp	.L37
.L36:
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
.L39:
	cmpl	%r9d, %ebx
	leaq	_ZN4Comb3facE(%rip), %r8
	jl	.L43
	leaq	-8+_ZN4Comb3facE(%rip), %rax
	movq	%r9, %rdi
	imulq	(%rax,%r9,8), %rdi
	movq	%rdi, %rax
	cqto
	idivq	%rsi
	movq	%rdx, (%r8,%r9,8)
	incq	%r9
	jmp	.L39
.L43:
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
.L41:
	cmpl	$1, %ecx
	jle	.L44
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
	jmp	.L41
.L44:
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
	jbe	.L46
	leaq	1248+rnd(%rip), %r11
	movq	%r8, %rdx
	movq	%r8, %r9
	movabsq	$-5403634167711393303, %rbx
.L48:
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
	jne	.L48
	leaq	1240+rnd(%rip), %r10
	movabsq	$-5403634167711393303, %r11
.L50:
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
	jne	.L50
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
.L46:
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
	.section	.text$_ZN2IO5qreadIiIiEEEvRT_DpRT0_,"x"
	.linkonce discard
	.globl	_ZN2IO5qreadIiIiEEEvRT_DpRT0_
	.def	_ZN2IO5qreadIiIiEEEvRT_DpRT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN2IO5qreadIiIiEEEvRT_DpRT0_
_ZN2IO5qreadIiIiEEEvRT_DpRT0_:
.LFB10434:
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
	movl	$1, %ebx
	movq	%rcx, %rbp
	movq	%rdx, %rsi
.L59:
	call	_ZN2IO2gcEv
	movsbl	%al, %edx
	subl	$48, %edx
	cmpl	$9, %edx
	jbe	.L69
	movl	%ebx, %edx
	negl	%edx
	cmpb	$45, %al
	cmove	%edx, %ebx
	jmp	.L59
.L69:
	xorl	%edi, %edi
.L62:
	leal	0(,%rdi,8), %edx
	xorl	$48, %eax
	movsbl	%al, %eax
	leal	(%rdx,%rdi,2), %edi
	addl	%eax, %edi
	call	_ZN2IO2gcEv
	movsbl	%al, %edx
	subl	$48, %edx
	cmpl	$9, %edx
	jbe	.L62
	imull	%edi, %ebx
	movl	%ebx, 0(%rbp)
	movl	$1, %ebx
.L63:
	call	_ZN2IO2gcEv
	movsbl	%al, %edx
	subl	$48, %edx
	cmpl	$9, %edx
	jbe	.L70
	movl	%ebx, %edx
	negl	%edx
	cmpb	$45, %al
	cmove	%edx, %ebx
	jmp	.L63
.L70:
	xorl	%edi, %edi
.L66:
	leal	0(,%rdi,8), %edx
	xorl	$48, %eax
	movsbl	%al, %eax
	leal	(%rdx,%rdi,2), %edi
	addl	%eax, %edi
	call	_ZN2IO2gcEv
	movsbl	%al, %edx
	subl	$48, %edx
	cmpl	$9, %edx
	jbe	.L66
	imull	%edi, %ebx
	movl	%ebx, (%rsi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.weak	_ZN2IO5qreadIiJiEEEvRT_DpRT0_
	.def	_ZN2IO5qreadIiJiEEEvRT_DpRT0_;	.scl	2;	.type	32;	.endef
	.set	_ZN2IO5qreadIiJiEEEvRT_DpRT0_,_ZN2IO5qreadIiIiEEEvRT_DpRT0_
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	.def	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev:
.LFB10652:
	.seh_endprologue
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L71
	jmp	_ZdlPv
.L71:
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_:
.LFB10674:
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
	movq	8(%rcx), %rbx
	subq	(%rcx), %rbx
	movq	%rcx, %rdi
	movq	%rdx, %rbp
	movq	%rbx, %rax
	movl	$1, %ebx
	sarq	$2, %rax
	cmovne	%rax, %rbx
	addq	%rax, %rbx
	jc	.L86
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %rbx
	jbe	.L75
.L86:
	movabsq	$4611686018427387903, %rbx
.L82:
	leaq	0(,%rbx,4), %rcx
	call	_Znwy
	movq	%rax, %rsi
.L83:
	movq	8(%rdi), %r8
	movq	(%rdi), %rcx
	movl	0(%rbp), %edx
	movq	%r8, %rax
	subq	%rcx, %rax
	addq	%rsi, %rax
	je	.L77
	movl	%edx, (%rax)
.L77:
	movq	%rcx, %rdx
	movq	%rsi, %rax
.L78:
	cmpq	%r8, %rdx
	je	.L98
	testq	%rax, %rax
	movl	(%rdx), %r9d
	je	.L87
	movl	%r9d, (%rax)
.L87:
	addq	$4, %rax
	addq	$4, %rdx
	jmp	.L78
.L98:
	subq	%rcx, %rdx
	andq	$-4, %rdx
	testq	%rcx, %rcx
	leaq	4(%rsi,%rdx), %rbp
	je	.L81
	call	_ZdlPv
.L81:
	leaq	(%rsi,%rbx,4), %rax
	movq	%rsi, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rax, 16(%rdi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L75:
	xorl	%esi, %esi
	testq	%rbx, %rbx
	je	.L83
	jmp	.L82
	.seh_endproc
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.section	.text$_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_,"x"
	.linkonce discard
	.globl	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_
	.def	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_
_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_:
.LFB10942:
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
	.seh_endprologue
	movl	$2, %edi
	leaq	-1(%r8), %rax
	movq	%rdx, %rsi
	movq	%rsi, %r10
	cqto
	idivq	%rdi
.L100:
	cmpq	%rax, %r10
	jge	.L105
	leaq	2(%r10,%r10), %rbx
	leaq	-1(%rbx), %r11
	leaq	(%rcx,%rbx,8), %rbp
	leaq	(%rcx,%r11,8), %rdi
	movl	0(%rbp), %r12d
	movl	(%rdi), %edx
	cmpl	%edx, %r12d
	jl	.L101
	cmpl	%r12d, %edx
	jl	.L104
	movl	4(%rdi), %edi
	cmpl	%edi, 4(%rbp)
	cmovge	%rbx, %r11
	jmp	.L101
.L104:
	movq	%rbx, %r11
.L101:
	leaq	(%rcx,%r11,8), %rbx
	leaq	(%rcx,%r10,8), %r10
	movl	(%rbx), %edx
	movl	%edx, (%r10)
	movl	4(%rbx), %edx
	movl	%edx, 4(%r10)
	movq	%r11, %r10
	jmp	.L100
.L105:
	testb	$1, %r8b
	movq	%r10, %rbx
	jne	.L103
	leaq	-2(%r8), %rax
	movl	$2, %r11d
	cqto
	idivq	%r11
	cmpq	%rax, %r10
	jne	.L103
	leaq	1(%r10,%r10), %r10
	leaq	(%rcx,%rbx,8), %rax
	leaq	(%rcx,%r10,8), %rdx
	movl	(%rdx), %r8d
	movl	%r8d, (%rax)
	movl	4(%rdx), %edx
	movl	%edx, 4(%rax)
.L103:
	movq	%rsi, %r8
	movq	%r10, %rdx
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	jmp	_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_T2_.isra.63
	.seh_endproc
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.def	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_:
.LFB10944:
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
	movq	8(%rcx), %rbx
	subq	(%rcx), %rbx
	movq	%rcx, %rdi
	movq	%rdx, %rbp
	movq	%rbx, %rax
	movl	$1, %ebx
	sarq	$3, %rax
	cmovne	%rax, %rbx
	addq	%rax, %rbx
	jc	.L119
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rbx
	jbe	.L108
.L119:
	movabsq	$2305843009213693951, %rbx
.L115:
	leaq	0(,%rbx,8), %rcx
	call	_Znwy
	movq	%rax, %rsi
.L116:
	movq	8(%rdi), %r8
	movq	(%rdi), %rcx
	movq	%r8, %rax
	subq	%rcx, %rax
	addq	%rsi, %rax
	je	.L110
	movq	0(%rbp), %rdx
	movq	%rdx, (%rax)
.L110:
	movq	%rcx, %rdx
	movq	%rsi, %rax
.L111:
	cmpq	%r8, %rdx
	je	.L131
	testq	%rax, %rax
	je	.L120
	movq	(%rdx), %r9
	movq	%r9, (%rax)
.L120:
	addq	$8, %rax
	addq	$8, %rdx
	jmp	.L111
.L131:
	subq	%rcx, %rdx
	andq	$-8, %rdx
	testq	%rcx, %rcx
	leaq	8(%rsi,%rdx), %rbp
	je	.L114
	call	_ZdlPv
.L114:
	leaq	(%rsi,%rbx,8), %rax
	movq	%rsi, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rax, 16(%rdi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L108:
	xorl	%esi, %esi
	testq	%rbx, %rbx
	je	.L116
	jmp	.L115
	.seh_endproc
	.weak	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_
	.def	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_,_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.section	.text$_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
	.def	_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_:
.LFB10424:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	8(%rcx), %rax
	cmpq	16(%rcx), %rax
	movq	%rcx, %rbx
	je	.L133
	testq	%rax, %rax
	je	.L134
	movq	(%rdx), %rdx
	movq	%rdx, (%rax)
.L134:
	addq	$8, %rax
	movq	%rax, 8(%rbx)
	jmp	.L135
.L133:
	call	_ZNSt6vectorISt4pairIiiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
.L135:
	movq	8(%rbx), %rax
	movq	(%rbx), %rcx
	xorl	%r8d, %r8d
	movq	%rax, %rdx
	movq	-8(%rax), %r9
	subq	%rcx, %rdx
	sarq	$3, %rdx
	decq	%rdx
	call	_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_T2_.isra.63
	nop
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.text
	.globl	_Z3dijv
	.def	_Z3dijv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3dijv
_Z3dijv:
.LFB10044:
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
	leaq	72(%rsp), %r13
	movq	$0, 72(%rsp)
	movq	$0, 80(%rsp)
	movq	$0, 88(%rsp)
	movq	$0, 96(%rsp)
	leaq	96(%rsp), %rbp
	movq	%r13, %rcx
	movq	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	call	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	leaq	f(%rip), %rdx
	movl	$800020, %ecx
	movb	$63, %al
	movl	$0, 72(%rsp)
	movq	%rdx, %rdi
	rep stosb
	movslq	n(%rip), %rcx
	movq	%rdx, %rdi
	movl	$0, (%rdx,%rcx,4)
	movl	%ecx, 76(%rsp)
	movq	%r13, %rdx
	movq	%rbp, %rcx
.LEHB0:
	call	_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
	leaq	deg(%rip), %r15
.L142:
	movq	104(%rsp), %r8
	movq	96(%rsp), %rcx
	cmpq	%r8, %rcx
	je	.L151
	movq	%r8, %rax
	movslq	4(%rcx), %rbx
	subq	%rcx, %rax
	cmpq	$15, %rax
	jle	.L141
	movl	(%rcx), %eax
	movq	-8(%r8), %r9
	subq	$8, %r8
	xorl	%edx, %edx
	movl	%eax, (%r8)
	movl	4(%rcx), %eax
	movl	%eax, 4(%r8)
	subq	%rcx, %r8
	movb	$0, 32(%rsp)
	sarq	$3, %r8
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_
.L141:
	leaq	vis(%rip), %rax
	subq	$8, 104(%rsp)
	cmpb	$0, (%rax,%rbx)
	jne	.L142
	movb	$1, (%rax,%rbx)
	leaq	e(%rip), %rsi
	imulq	$24, %rbx, %rax
	addq	%rsi, %rax
	movq	8(%rax), %rsi
	movq	(%rax), %r12
	movq	%rsi, 56(%rsp)
.L143:
	cmpq	56(%rsp), %r12
	je	.L142
	movslq	(%r12), %rsi
	leaq	deg(%rip), %r14
	movl	(%r15,%rsi,4), %eax
	addl	(%rdi,%rbx,4), %eax
	cmpl	%eax, (%rdi,%rsi,4)
	jle	.L144
	leaq	f(%rip), %rcx
	movq	%r13, %rdx
	movl	%esi, 76(%rsp)
	movl	%eax, (%rcx,%rsi,4)
	negl	%eax
	movq	%rbp, %rcx
	movl	%eax, 72(%rsp)
	call	_ZNSt14priority_queueISt4pairIiiESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
.LEHE0:
.L144:
	decl	(%r14,%rsi,4)
	addq	$4, %r12
	jmp	.L143
.L151:
	movq	%rbp, %rcx
	call	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	nop
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
.L148:
	movq	%rax, %rbx
	movq	%rbp, %rcx
	call	_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	movq	%rbx, %rcx
.LEHB1:
	call	_Unwind_Resume
	nop
.LEHE1:
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10044:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10044-.LLSDACSB10044
.LLSDACSB10044:
	.uleb128 .LEHB0-.LFB10044
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L148-.LFB10044
	.uleb128 0
	.uleb128 .LEHB1-.LFB10044
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE10044:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10054:
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
	leaq	e(%rip), %rsi
	movl	$1, %ebx
	call	__main
	leaq	44(%rsp), %rdi
	leaq	m(%rip), %rdx
	leaq	n(%rip), %rcx
	movq	%rsi, %rbp
	call	_ZN2IO5qreadIiIiEEEvRT_DpRT0_
.L153:
	cmpl	m(%rip), %ebx
	jg	.L161
	leaq	40(%rsp), %r12
	movq	%rdi, %rdx
	movq	%r12, %rcx
	call	_ZN2IO5qreadIiIiEEEvRT_DpRT0_
	movslq	44(%rsp), %r8
	imulq	$24, %r8, %rax
	leaq	(%rsi,%rax), %rcx
	movq	8(%rcx), %rax
	cmpq	16(%rcx), %rax
	je	.L154
	testq	%rax, %rax
	movl	40(%rsp), %edx
	je	.L155
	movl	%edx, (%rax)
.L155:
	imulq	$24, %r8, %r8
	addq	$4, %rax
	movq	%rax, 8(%rbp,%r8)
	jmp	.L156
.L154:
	movq	%r12, %rdx
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
.L156:
	movslq	40(%rsp), %rdx
	leaq	deg(%rip), %rax
	incl	%ebx
	incl	(%rax,%rdx,4)
	jmp	.L153
.L161:
	call	_Z3dijv
	movl	4+f(%rip), %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movl	$10, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN2IO4ibufE;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN2IO4ibufE
_GLOBAL__sub_I__ZN2IO4ibufE:
.LFB11244:
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
.L163:
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
	jne	.L163
	leaq	e(%rip), %rax
	leaq	4800120+e(%rip), %rdx
	movq	$312, 2496+rnd(%rip)
.L164:
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	addq	$24, %rax
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L164
	leaq	__tcf_2(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN2IO4ibufE
	.globl	deg
	.bss
	.align 64
deg:
	.space 800020
	.globl	vis
	.align 64
vis:
	.space 200005
	.globl	f
	.align 64
f:
	.space 800020
	.globl	e
	.align 64
e:
	.space 4800120
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
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.def	_ZNSt6chrono3_V212steady_clock3nowEv;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
)");