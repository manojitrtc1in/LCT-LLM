__asm__(R"(	.file	"A.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11115:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	.def	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev:
.LFB10638:
	.seh_endprologue
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L2
	jmp	_ZdlPv
.L2:
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev
	.def	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev
_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev:
.LFB10657:
	.seh_endprologue
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L5
	jmp	_ZdlPv
.L5:
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy
	.def	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy
_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy:
.LFB10794:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	testq	%rdx, %rdx
	movq	%rcx, %rsi
	movq	%rdx, %rbx
	je	.L10
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %rdx
	jbe	.L9
	call	_ZSt17__throw_bad_allocv
.L9:
	leaq	0(,%rdx,4), %rcx
	call	_Znwy
	jmp	.L8
.L10:
	xorl	%eax, %eax
.L8:
	movq	%rax, (%rsi)
	movq	%rax, 8(%rsi)
	leaq	(%rax,%rbx,4), %rax
	movq	%rax, 16(%rsi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.text
	.align 2
	.def	_ZNSt6vectorI14dynamic_modintILj0EESaIS1_EEC4EyRKS2_.isra.62;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorI14dynamic_modintILj0EESaIS1_EEC4EyRKS2_.isra.62
_ZNSt6vectorI14dynamic_modintILj0EESaIS1_EEC4EyRKS2_.isra.62:
.LFB11209:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	%rcx, %rbx
	movq	$0, (%rcx)
	movq	$0, 8(%rcx)
	movq	$0, 16(%rcx)
	movq	%rdx, %rsi
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy
	movq	(%rbx), %rax
.L12:
	testq	%rsi, %rsi
	je	.L18
	testq	%rax, %rax
	je	.L13
	movl	$0, (%rax)
.L13:
	decq	%rsi
	addq	$4, %rax
	jmp	.L12
.L18:
	movq	16(%rbx), %rax
	movq	%rax, 8(%rbx)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_,"x"
	.linkonce discard
	.globl	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_
	.def	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_
_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_:
.LFB10927:
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
	movq	%rcx, %rsi
	movq	%rdx, %rbp
	movq	%r8, %rdi
	movq	%rcx, %rbx
.L20:
	testq	%rbp, %rbp
	je	.L40
	testq	%rbx, %rbx
	je	.L21
	movq	8(%rdi), %rdx
	subq	(%rdi), %rdx
	movq	%rbx, %rcx
	movq	$0, (%rbx)
	movq	$0, 8(%rbx)
	movq	$0, 16(%rbx)
	sarq	$2, %rdx
.LEHB0:
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EE17_M_create_storageEy
.LEHE0:
	movq	(%rbx), %rcx
	movq	(%rdi), %r8
	movq	8(%rdi), %r9
	movq	%r8, %rax
	movq	%rcx, %rdx
.L22:
	cmpq	%r9, %rax
	je	.L41
	testq	%rdx, %rdx
	je	.L32
	movl	(%rax), %r10d
	movl	%r10d, (%rdx)
.L32:
	addq	$4, %rdx
	addq	$4, %rax
	jmp	.L22
.L41:
	subq	%r8, %rax
	andq	$-4, %rax
	addq	%rcx, %rax
	movq	%rax, 8(%rbx)
.L21:
	decq	%rbp
	addq	$24, %rbx
	jmp	.L20
.L30:
	movq	%rax, %rcx
	call	__cxa_begin_catch
.L28:
	cmpq	%rbx, %rsi
	je	.L42
	movq	%rsi, %rcx
	addq	$24, %rsi
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	jmp	.L28
.L42:
.LEHB1:
	call	__cxa_rethrow
.LEHE1:
.L31:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rcx
.LEHB2:
	call	_Unwind_Resume
	nop
.LEHE2:
.L40:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA10927:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT10927-.LLSDATTD10927
.LLSDATTD10927:
	.byte	0x1
	.uleb128 .LLSDACSE10927-.LLSDACSB10927
.LLSDACSB10927:
	.uleb128 .LEHB0-.LFB10927
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L30-.LFB10927
	.uleb128 0x1
	.uleb128 .LEHB1-.LFB10927
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L31-.LFB10927
	.uleb128 0
	.uleb128 .LEHB2-.LFB10927
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE10927:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT10927:
	.section	.text$_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_,"x"
	.linkonce discard
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii " \12\0"
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10045:
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
	subq	$120, %rsp
	.seh_stackalloc	120
	.seh_endprologue
	xorl	%esi, %esi
	call	__main
	xorl	%ecx, %ecx
	leaq	40(%rsp), %rdi
.LEHB3:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rbx
	leaq	36(%rsp), %rdx
	movq	%rbx, %rcx
	movq	$0, 232(%rbx)
	call	_ZNSirsERi
	movslq	36(%rsp), %rdx
	movq	%rdi, %rcx
	movl	%edx, _ZN14dynamic_modintILj0EE1PE(%rip)
	call	_ZNSt6vectorI14dynamic_modintILj0EESaIS1_EEC4EyRKS2_.isra.62
.LEHE3:
.L44:
	movslq	36(%rsp), %rdx
	cmpl	%esi, %edx
	jle	.L72
	movq	40(%rsp), %rax
	movq	%rbx, %rcx
	leaq	(%rax,%rsi,4), %rdx
.LEHB4:
	call	_ZNSi10_M_extractIjEERSiRT_
	incq	%rsi
	jmp	.L44
.L72:
	leaq	88(%rsp), %rsi
	movq	%rsi, %rcx
	call	_ZNSt6vectorI14dynamic_modintILj0EESaIS1_EEC4EyRKS2_.isra.62
.LEHE4:
	movslq	36(%rsp), %rbx
	movq	$0, 64(%rsp)
	movq	$0, 72(%rsp)
	movq	$0, 80(%rsp)
	testq	%rbx, %rbx
	je	.L64
	movabsq	$768614336404564650, %rax
	cmpq	%rax, %rbx
	jbe	.L47
.LEHB5:
	call	_ZSt17__throw_bad_allocv
.L47:
	imulq	$24, %rbx, %rcx
	call	_Znwy
.LEHE5:
	jmp	.L46
.L64:
	xorl	%eax, %eax
.L46:
	imulq	$24, %rbx, %rdx
	movq	%rsi, %r8
	movq	%rax, %rcx
	movq	%rax, 64(%rsp)
	movq	%rax, 72(%rsp)
	addq	%rax, %rdx
	movq	%rdx, 80(%rsp)
	movq	%rbx, %rdx
.LEHB6:
	call	_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorI14dynamic_modintILj0EESaIS4_EEyS6_EEvT_T0_RKT1_
.LEHE6:
	movq	80(%rsp), %rax
	movq	%rsi, %rcx
	xorl	%ebx, %ebx
	movq	%rax, 72(%rsp)
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	jmp	.L48
.L68:
	leaq	64(%rsp), %rcx
	movq	%rax, %rbx
	call	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev
	jmp	.L50
.L55:
	movl	_ZN14dynamic_modintILj0EE1PE(%rip), %r9d
	movq	%rsi, %rax
	movq	64(%rsp), %r11
	subq	%rbx, %rax
	leaq	0(,%rsi,4), %r10
	movq	%r15, %r14
	cqto
	addq	40(%rsp), %r14
	movq	%r10, %r13
	addq	(%r11,%rbp), %r13
	idivq	%r9
	movq	%rbx, %rax
	leaq	(%rdx,%r9), %r8
	testq	%rdx, %rdx
	cmovns	%rdx, %r8
	cqto
	idivq	%r9
	movl	%r8d, %r8d
	leaq	(%rdx,%r9), %rax
	testq	%rdx, %rdx
	cmovns	%rdx, %rax
	xorl	%edx, %edx
	movl	%eax, %eax
	imulq	%r8, %rax
	movl	%r9d, %r8d
	divq	%r9
	movl	(%r14), %eax
	subl	%eax, %r8d
	cmpl	%r8d, %edx
	jb	.L71
	subl	%r9d, %eax
.L71:
	addl	%edx, %eax
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	%eax, 0(%r13)
	movl	36(%rsp), %eax
	decl	%eax
	cmpl	%eax, %r12d
	sete	%al
	movzbl	%al, %eax
	movsbl	(%rdx,%rax), %r12d
	movq	(%r11,%rbp), %rax
	movl	(%rax,%r10), %edx
.LEHB7:
	call	_ZNSo9_M_insertImEERSoT_
	movl	%r12d, %edx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.LEHE7:
	incq	%rsi
.L57:
	cmpl	36(%rsp), %esi
	movl	%esi, %r12d
	jl	.L55
	incq	%rbx
.L48:
	cmpl	%ebx, 36(%rsp)
	jle	.L56
	imulq	$24, %rbx, %rbp
	leaq	0(,%rbx,4), %r15
	xorl	%esi, %esi
	jmp	.L57
.L56:
	movq	72(%rsp), %rsi
	movq	64(%rsp), %rbx
.L58:
	cmpq	%rsi, %rbx
	je	.L73
	movq	%rbx, %rcx
	addq	$24, %rbx
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	jmp	.L58
.L66:
	movq	%rax, %rbx
.L50:
	movq	%rsi, %rcx
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	jmp	.L60
.L67:
	movq	72(%rsp), %rbp
	movq	64(%rsp), %rsi
	movq	%rax, %rbx
.L62:
	cmpq	%rbp, %rsi
	je	.L74
	movq	%rsi, %rcx
	addq	$24, %rsi
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	jmp	.L62
.L74:
	leaq	64(%rsp), %rcx
	call	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev
	jmp	.L60
.L65:
	movq	%rax, %rbx
.L60:
	movq	%rdi, %rcx
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	movq	%rbx, %rcx
.LEHB8:
	call	_Unwind_Resume
.LEHE8:
.L73:
	leaq	64(%rsp), %rcx
	call	_ZNSt12_Vector_baseISt6vectorI14dynamic_modintILj0EESaIS2_EESaIS4_EED2Ev
	movq	%rdi, %rcx
	call	_ZNSt12_Vector_baseI14dynamic_modintILj0EESaIS1_EED2Ev
	xorl	%eax, %eax
	addq	$120, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10045:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10045-.LLSDACSB10045
.LLSDACSB10045:
	.uleb128 .LEHB3-.LFB10045
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB10045
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L65-.LFB10045
	.uleb128 0
	.uleb128 .LEHB5-.LFB10045
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L66-.LFB10045
	.uleb128 0
	.uleb128 .LEHB6-.LFB10045
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L68-.LFB10045
	.uleb128 0
	.uleb128 .LEHB7-.LFB10045
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L67-.LFB10045
	.uleb128 0
	.uleb128 .LEHB8-.LFB10045
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE10045:
	.section	.text.startup,"x"
	.seh_endproc
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB11146:
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
	.quad	_GLOBAL__sub_I_main
	.globl	_ZN14dynamic_modintILj0EE1PE
	.section	.data$_ZN14dynamic_modintILj0EE1PE,"w"
	.linkonce same_size
	.align 4
_ZN14dynamic_modintILj0EE1PE:
	.space 4
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSi10_M_extractIjEERSiRT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertImEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
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