__asm__(R"(
	.file	"cf1720b.cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB42:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZN9__gnu_cxx5__ops16__iter_less_iterEv,"x"
	.linkonce discard
	.globl	_ZN9__gnu_cxx5__ops16__iter_less_iterEv
	.def	_ZN9__gnu_cxx5__ops16__iter_less_iterEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx5__ops16__iter_less_iterEv
_ZN9__gnu_cxx5__ops16__iter_less_iterEv:
.LFB592:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE
	.def	_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE
_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE:
.LFB595:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE,"x"
	.linkonce discard
	.globl	_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE
	.def	_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE
_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE:
.LFB604:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4__lgx,"x"
	.linkonce discard
	.globl	_ZSt4__lgx
	.def	_ZSt4__lgx;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4__lgx
_ZSt4__lgx:
.LFB715:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	movl	%eax, %edx
	movl	$63, %eax
	subl	%edx, %eax
	cltq
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZStL13allocator_arg:
	.space 1
_ZStL6ignore:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.align 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
_ZStL10defer_lock:
	.space 1
_ZStL11try_to_lock:
	.space 1
_ZStL10adopt_lock:
	.space 1
	.align 4
_ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
_ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
_ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
_ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
_ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
_ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
_ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
_ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
_ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
_ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
_ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
_ZNSt15regex_constantsL13match_defaultE:
	.space 4
	.align 4
_ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
_ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
_ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
_ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
_ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
_ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
_ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
_ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
_ZNSt15regex_constantsL14format_defaultE:
	.space 4
	.align 4
_ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
_ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
_ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
_ZNSt15regex_constantsL13error_collateE:
	.space 4
	.align 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 4
_ZNSt8__detailL19_S_invalid_state_idE:
	.long	-1
	.globl	a
	.bss
	.align 32
a:
	.space 400020
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
	.text
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB8476:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_Z4readIiEvRT_
	movl	$1, -4(%rbp)
.L12:
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L11
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	_Z4readIiEvRT_
	addl	$1, -4(%rbp)
	jmp	.L12
.L11:
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	addq	%rax, %rdx
	leaq	4+a(%rip), %rax
	movq	%rax, %rcx
	call	_ZSt4sortIPiEvT_S1_
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	4+a(%rip), %edx
	subl	%edx, %eax
	movl	%eax, %ecx
	movl	-8(%rbp), %eax
	subl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%ecx, %eax
	movl	8+a(%rip), %edx
	subl	%edx, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8477:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	-4(%rbp), %rax
	movq	%rax, %rcx
	call	_Z4readIiEvRT_
.L15:
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -4(%rbp)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L14
	call	_Z5solvev
	jmp	.L15
.L14:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z4readIiEvRT_,"x"
	.linkonce discard
	.globl	_Z4readIiEvRT_
	.def	_Z4readIiEvRT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readIiEvRT_
_Z4readIiEvRT_:
.LFB9050:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	$0, (%rax)
	movb	$0, -1(%rbp)
	call	getchar
	movb	%al, -2(%rbp)
.L20:
	cmpb	$47, -2(%rbp)
	jle	.L18
	cmpb	$57, -2(%rbp)
	jle	.L19
.L18:
	cmpb	$45, -2(%rbp)
	sete	%al
	movb	%al, -1(%rbp)
	call	getchar
	movb	%al, -2(%rbp)
	jmp	.L20
.L19:
	cmpb	$47, -2(%rbp)
	jle	.L21
	cmpb	$57, -2(%rbp)
	jg	.L21
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	leal	(%rax,%rax), %edx
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	sall	$3, %eax
	addl	%eax, %edx
	movzbl	-2(%rbp), %eax
	xorl	$48, %eax
	movsbl	%al, %eax
	addl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	call	getchar
	movb	%al, -2(%rbp)
	jmp	.L19
.L21:
	cmpb	$0, -1(%rbp)
	je	.L22
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	negl	%eax
	jmp	.L23
.L22:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
.L23:
	movq	16(%rbp), %rdx
	movl	%eax, (%rdx)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4sortIPiEvT_S1_,"x"
	.linkonce discard
	.globl	_ZSt4sortIPiEvT_S1_
	.def	_ZSt4sortIPiEvT_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4sortIPiEvT_S1_
_ZSt4sortIPiEvT_S1_:
.LFB9051:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	call	_ZN9__gnu_cxx5__ops16__iter_less_iterEv
	movq	40(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	.def	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
_ZSt6__sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_:
.LFB9324:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	32(%rbp), %rax
	cmpq	40(%rbp), %rax
	je	.L27
	movq	40(%rbp), %rax
	subq	32(%rbp), %rax
	sarq	$2, %rax
	movq	%rax, %rcx
	call	_ZSt4__lgx
	leaq	(%rax,%rax), %rdx
	movq	40(%rbp), %rax
	movl	%esi, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_
	movq	40(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
.L27:
	nop
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_,"x"
	.linkonce discard
	.globl	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_
	.def	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_
_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_:
.LFB9470:
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
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 48(%rbp)
	movq	%rdx, 56(%rbp)
	movq	%r8, 64(%rbp)
.L31:
	movq	56(%rbp), %rax
	subq	48(%rbp), %rax
	cmpq	$64, %rax
	jle	.L28
	cmpq	$0, 64(%rbp)
	jne	.L30
	movq	56(%rbp), %rdx
	movq	56(%rbp), %rax
	movl	%edi, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	48(%rbp), %rcx
	call	_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	jmp	.L28
.L30:
	subq	$1, 64(%rbp)
	movq	56(%rbp), %rax
	movl	%esi, %r8d
	movq	%rax, %rdx
	movq	48(%rbp), %rcx
	call	_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_
	movq	%rax, -8(%rbp)
	movq	64(%rbp), %rcx
	movq	56(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	%ebx, %r9d
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZSt16__introsort_loopIPixN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_
	movq	-8(%rbp), %rax
	movq	%rax, 56(%rbp)
	jmp	.L31
.L28:
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	.def	_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
_ZSt22__final_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_:
.LFB9471:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	40(%rbp), %rax
	subq	32(%rbp), %rax
	cmpq	$64, %rax
	jle	.L33
	movq	32(%rbp), %rax
	addq	$64, %rax
	movl	%r9d, %r8d
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	movq	32(%rbp), %rax
	leaq	64(%rax), %rcx
	movq	40(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rax, %rdx
	call	_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	jmp	.L35
.L33:
	movq	40(%rbp), %rax
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
.L35:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	.def	_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
_ZSt14__partial_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_:
.LFB9562:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	leaq	40(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_
	.def	_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_
_ZSt27__unguarded_partition_pivotIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_T0_:
.LFB9563:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	40(%rbp), %rax
	subq	32(%rbp), %rax
	sarq	$2, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	40(%rbp), %rax
	leaq	-4(%rax), %rcx
	movq	32(%rbp), %rax
	addq	$4, %rax
	movq	-8(%rbp), %rdx
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_
	movq	32(%rbp), %rax
	leaq	4(%rax), %rcx
	movq	40(%rbp), %rax
	movl	%ebx, %r9d
	movq	32(%rbp), %r8
	movq	%rax, %rdx
	call	_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	.def	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
_ZSt16__insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_:
.LFB9564:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	32(%rbp), %rax
	cmpq	40(%rbp), %rax
	je	.L45
	movq	32(%rbp), %rax
	addq	$4, %rax
	movq	%rax, -8(%rbp)
.L44:
	movq	-8(%rbp), %rax
	cmpq	40(%rbp), %rax
	je	.L39
	movq	-8(%rbp), %rdx
	leaq	48(%rbp), %rax
	movq	32(%rbp), %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L42
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movq	-8(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt13move_backwardIPiS0_ET0_T_S2_S1_
	leaq	-12(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L43
.L42:
	movl	%esi, %ecx
	call	_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE
	movq	-8(%rbp), %rax
	movl	%ebx, %edx
	movq	%rax, %rcx
	call	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_
.L43:
	addq	$4, -8(%rbp)
	jmp	.L44
.L45:
	nop
.L39:
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	.def	_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
_ZSt26__unguarded_insertion_sortIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_:
.LFB9565:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	32(%rbp), %rax
	movq	%rax, -8(%rbp)
.L48:
	movq	-8(%rbp), %rax
	cmpq	40(%rbp), %rax
	je	.L49
	movl	%esi, %ecx
	call	_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE
	movq	-8(%rbp), %rax
	movl	%ebx, %edx
	movq	%rax, %rcx
	call	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_
	addq	$4, -8(%rbp)
	jmp	.L48
.L49:
	nop
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	.def	_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
_ZSt13__heap_selectIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_:
.LFB9628:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	leaq	40(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	movq	24(%rbp), %rax
	movq	%rax, -8(%rbp)
.L53:
	movq	-8(%rbp), %rax
	cmpq	32(%rbp), %rax
	jnb	.L54
	movq	-8(%rbp), %rdx
	leaq	40(%rbp), %rax
	movq	16(%rbp), %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L52
	leaq	40(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_
.L52:
	addq	$4, -8(%rbp)
	jmp	.L53
.L54:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_,"x"
	.linkonce discard
	.globl	_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	.def	_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
_ZSt11__sort_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_:
.LFB9629:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
.L57:
	movq	24(%rbp), %rax
	subq	16(%rbp), %rax
	cmpq	$4, %rax
	jle	.L58
	subq	$4, 24(%rbp)
	movq	32(%rbp), %rcx
	movq	24(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_
	jmp	.L57
.L58:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	.def	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_:
.LFB9631:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	setl	%al
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_
	.def	_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_
_ZSt22__move_median_to_firstIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_S4_T0_:
.LFB9630:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movq	32(%rbp), %rcx
	movq	24(%rbp), %rdx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L62
	movq	40(%rbp), %rcx
	movq	32(%rbp), %rdx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L63
	movq	32(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	jmp	.L68
.L63:
	movq	40(%rbp), %rcx
	movq	24(%rbp), %rdx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L65
	movq	40(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	jmp	.L68
.L65:
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	jmp	.L68
.L62:
	movq	40(%rbp), %rcx
	movq	24(%rbp), %rdx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L66
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	jmp	.L68
.L66:
	movq	40(%rbp), %rcx
	movq	32(%rbp), %rdx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L67
	movq	40(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	jmp	.L68
.L67:
	movq	32(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
.L68:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_,"x"
	.linkonce discard
	.globl	_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_
	.def	_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_
_ZSt21__unguarded_partitionIPiN9__gnu_cxx5__ops15_Iter_less_iterEET_S4_S4_S4_T0_:
.LFB9632:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
.L71:
	movq	32(%rbp), %rdx
	leaq	40(%rbp), %rax
	movq	%rdx, %r8
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L70
	addq	$4, 16(%rbp)
	jmp	.L71
.L70:
	subq	$4, 24(%rbp)
.L73:
	movq	24(%rbp), %rcx
	movq	32(%rbp), %rdx
	leaq	40(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L72
	subq	$4, 24(%rbp)
	jmp	.L73
.L72:
	movq	16(%rbp), %rax
	cmpq	24(%rbp), %rax
	jb	.L74
	movq	16(%rbp), %rax
	jmp	.L76
.L74:
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt9iter_swapIPiS0_EvT_T0_
	addq	$4, 16(%rbp)
	jmp	.L71
.L76:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.def	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_:
.LFB9633:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt13move_backwardIPiS0_ET0_T_S2_S1_,"x"
	.linkonce discard
	.globl	_ZSt13move_backwardIPiS0_ET0_T_S2_S1_
	.def	_ZSt13move_backwardIPiS0_ET0_T_S2_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13move_backwardIPiS0_ET0_T_S2_S1_
_ZSt13move_backwardIPiS0_ET0_T_S2_S1_:
.LFB9634:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt12__miter_baseIPiET_S1_
	movq	%rax, %rbx
	movq	32(%rbp), %rcx
	call	_ZSt12__miter_baseIPiET_S1_
	movq	48(%rbp), %rdx
	movq	%rdx, %r8
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_,"x"
	.linkonce discard
	.globl	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_
	.def	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_
_ZSt25__unguarded_linear_insertIPiN9__gnu_cxx5__ops14_Val_less_iterEEvT_T0_:
.LFB9635:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
	subq	$4, -8(%rbp)
.L83:
	movq	-8(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	leaq	24(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_
	testb	%al, %al
	je	.L82
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, 16(%rbp)
	subq	$4, -8(%rbp)
	jmp	.L83
.L82:
	leaq	-12(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_,"x"
	.linkonce discard
	.globl	_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	.def	_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
_ZSt11__make_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_:
.LFB9729:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	subq	16(%rbp), %rax
	cmpq	$4, %rax
	jle	.L89
	movq	24(%rbp), %rax
	subq	16(%rbp), %rax
	sarq	$2, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	subq	$2, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, -8(%rbp)
.L88:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
	leaq	-20(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %ecx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	%ecx, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	cmpq	$0, -8(%rbp)
	je	.L90
	subq	$1, -8(%rbp)
	jmp	.L88
.L89:
	nop
	jmp	.L84
.L90:
	nop
.L84:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_,"x"
	.linkonce discard
	.globl	_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_
	.def	_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_
_ZSt10__pop_heapIPiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_RT0_:
.LFB9730:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	16(%rbp), %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	leaq	-4(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	subq	16(%rbp), %rax
	sarq	$2, %rax
	movl	%edx, %r9d
	movq	%rax, %r8
	movl	$0, %edx
	movq	16(%rbp), %rcx
	call	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt9iter_swapIPiS0_EvT_T0_,"x"
	.linkonce discard
	.globl	_ZSt9iter_swapIPiS0_EvT_T0_
	.def	_ZSt9iter_swapIPiS0_EvT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt9iter_swapIPiS0_EvT_T0_
_ZSt9iter_swapIPiS0_EvT_T0_:
.LFB9731:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt12__miter_baseIPiET_S1_,"x"
	.linkonce discard
	.globl	_ZSt12__miter_baseIPiET_S1_
	.def	_ZSt12__miter_baseIPiET_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__miter_baseIPiET_S1_
_ZSt12__miter_baseIPiET_S1_:
.LFB9732:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_,"x"
	.linkonce discard
	.globl	_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_
	.def	_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_
_ZSt22__copy_move_backward_aILb1EPiS0_ET1_T0_S2_S1_:
.LFB9733:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt12__niter_baseIPiET_S1_
	movq	%rax, %rsi
	movq	40(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt12__niter_baseIPiET_S1_
	movq	%rax, %rbx
	movq	32(%rbp), %rcx
	call	_ZSt12__niter_baseIPiET_S1_
	movq	%rsi, %r8
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_
	movq	%rax, %rdx
	leaq	48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt12__niter_wrapIPiET_RKS1_S1_
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_
	.def	_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_
_ZNK9__gnu_cxx5__ops14_Val_less_iterclIiPiEEbRT_T0_:
.LFB9735:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	setl	%al
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_,"x"
	.linkonce discard
	.globl	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	.def	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
_ZSt13__adjust_heapIPixiN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_:
.LFB9794:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	leaq	96(%rsp), %rbp
	.seh_setframe	%rbp, 96
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movl	%r9d, 56(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, -8(%rbp)
.L102:
	movq	48(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, -8(%rbp)
	jge	.L100
	movq	-8(%rbp), %rax
	addq	$1, %rax
	addq	%rax, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rax, %rdx
	leaq	-33(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops15_Iter_less_iterclIPiS3_EEbT_T0_
	testb	%al, %al
	je	.L101
	subq	$1, -8(%rbp)
.L101:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movq	40(%rbp), %rdx
	leaq	0(,%rdx,4), %rcx
	movq	32(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	movq	%rax, 40(%rbp)
	jmp	.L102
.L100:
	movq	48(%rbp), %rax
	andl	$1, %eax
	testq	%rax, %rax
	jne	.L103
	movq	48(%rbp), %rax
	subq	$2, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, -8(%rbp)
	jne	.L103
	movq	-8(%rbp), %rax
	addq	$1, %rax
	addq	%rax, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movq	40(%rbp), %rdx
	leaq	0(,%rdx,4), %rcx
	movq	32(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	subq	$1, %rax
	movq	%rax, 40(%rbp)
.L103:
	leaq	-33(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_
	leaq	-17(%rbp), %rax
	movl	%ebx, %edx
	movq	%rax, %rcx
	call	_ZN9__gnu_cxx5__ops14_Iter_less_valC1ENS0_15_Iter_less_iterE
	leaq	56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %r8d
	movq	-16(%rbp), %rcx
	movq	40(%rbp), %rax
	leaq	-17(%rbp), %rdx
	movq	%rdx, 32(%rsp)
	movl	%r8d, %r9d
	movq	%rcx, %r8
	movq	%rax, %rdx
	movq	32(%rbp), %rcx
	call	_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_
	nop
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_,"x"
	.linkonce discard
	.globl	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	.def	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_:
.LFB9795:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	leaq	-4(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	movl	%edx, (%rax)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt12__niter_baseIPiET_S1_,"x"
	.linkonce discard
	.globl	_ZSt12__niter_baseIPiET_S1_
	.def	_ZSt12__niter_baseIPiET_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__niter_baseIPiET_S1_
_ZSt12__niter_baseIPiET_S1_:
.LFB9796:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_,"x"
	.linkonce discard
	.globl	_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_
	.def	_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_
_ZSt23__copy_move_backward_a1ILb1EPiS0_ET1_T0_S2_S1_:
.LFB9797:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt12__niter_wrapIPiET_RKS1_S1_,"x"
	.linkonce discard
	.globl	_ZSt12__niter_wrapIPiET_RKS1_S1_
	.def	_ZSt12__niter_wrapIPiET_RKS1_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__niter_wrapIPiET_RKS1_S1_
_ZSt12__niter_wrapIPiET_RKS1_S1_:
.LFB9798:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_
	.def	_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_
_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_less_iterEEONSt16remove_referenceIT_E4typeEOS5_:
.LFB9820:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_,"x"
	.linkonce discard
	.globl	_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_
	.def	_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_
_ZSt11__push_heapIPixiN9__gnu_cxx5__ops14_Iter_less_valEEvT_T0_S5_T1_RT2_:
.LFB9821:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movq	24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, -8(%rbp)
.L117:
	movq	24(%rbp), %rax
	cmpq	32(%rbp), %rax
	jle	.L114
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	leaq	40(%rbp), %rcx
	movq	48(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_
	testb	%al, %al
	je	.L114
	movl	$1, %eax
	jmp	.L115
.L114:
	movl	$0, %eax
.L115:
	testb	%al, %al
	je	.L116
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movq	24(%rbp), %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	movq	%rax, 24(%rbp)
	movq	24(%rbp), %rax
	subq	$1, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, -8(%rbp)
	jmp	.L117
.L116:
	leaq	40(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movq	24(%rbp), %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_,"x"
	.linkonce discard
	.globl	_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_
	.def	_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_
_ZSt23__copy_move_backward_a2ILb1EPiS0_ET1_T0_S2_S1_:
.LFB9822:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_
	.def	_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_
_ZNK9__gnu_cxx5__ops14_Iter_less_valclIPiiEEbT_RT0_:
.LFB9826:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	setl	%al
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_,"x"
	.linkonce discard
	.globl	_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_
	.def	_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_
_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIiEEPT_PKS3_S6_S4_:
.LFB9827:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	subq	16(%rbp), %rax
	sarq	$2, %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L123
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	salq	$2, %rax
	negq	%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	addq	%rcx, %rax
	movq	%rdx, %r8
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	memmove
.L123:
	movq	-8(%rbp), %rax
	salq	$2, %rax
	negq	%rax
	movq	%rax, %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB9856:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB9855:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L128
	cmpl	$65535, 24(%rbp)
	jne	.L128
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L128:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB9879:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_a
	.ident	"GCC: (Rev5, Built by MSYS2 project) 10.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	)");
