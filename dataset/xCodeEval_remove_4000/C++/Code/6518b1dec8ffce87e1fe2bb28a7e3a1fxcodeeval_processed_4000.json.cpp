__asm__(R"(
	.file	"main.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
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
	.align 4
_ZL1N:
	.long	35
	.globl	a
	.bss
	.align 32
a:
	.space 140
	.section .rdata,"dr"
.LC0:
	.ascii "YES\12\0"
.LC1:
	.ascii "01\0"
.LC2:
	.ascii "10\0"
.LC3:
	.ascii "NO\12\0"
	.section	.text$_Z5solvev,"x"
	.linkonce discard
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB8468:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	80(%rsp), %rbp
	.seh_setframe	%rbp, 80
	.seh_endprologue
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
.LEHB0:
	call	_ZNSirsERi
	movq	%rax, %rcx
	leaq	-32(%rbp), %rax
	movq	%rax, %rdx
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	-36(%rbp), %eax
	cmpl	$1, %eax
	jne	.L2
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L3
.L2:
	movl	-36(%rbp), %eax
	cmpl	$2, %eax
	jne	.L4
	leaq	-32(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	jne	.L5
	leaq	-32(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	.L6
.L5:
	movl	$1, %eax
	jmp	.L7
.L6:
	movl	$0, %eax
.L7:
	testb	%al, %al
	je	.L8
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L3
.L8:
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L3
.L4:
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.LEHE0:
.L3:
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L11
.L10:
	movq	%rax, %rbx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB1:
	call	_Unwind_Resume
	nop
.LEHE1:
.L11:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8468:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8468-.LLSDACSB8468
.LLSDACSB8468:
	.uleb128 .LEHB0-.LFB8468
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L10-.LFB8468
	.uleb128 0
	.uleb128 .LEHB1-.LFB8468
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE8468:
	.section	.text$_Z5solvev,"x"
	.linkonce discard
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8470:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movl	$0, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movl	$0, %edx
	movq	.refptr._ZSt3cin(%rip), %rax
	leaq	16(%rax), %rcx
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo
	movl	$0, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	leaq	8(%rax), %rcx
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
.L14:
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -4(%rbp)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L13
	call	_Z5solvev
	jmp	.L14
.L13:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,"x"
	.linkonce discard
	.globl	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.def	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_:
.LFB9047:
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
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc
	testl	%eax, %eax
	sete	%al
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB9823:
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
.LFB9822:
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
	jne	.L21
	cmpl	$65535, 24(%rbp)
	jne	.L21
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L21:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB9846:
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
	.ident	"GCC: (tdm64-1) 10.3.0"
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
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

	   		 			 				  	   	 			 				