__asm__(R"(
	.file	"code.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.align 4
__ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
__ZStL10defer_lock:
	.space 1
__ZStL11try_to_lock:
	.space 1
__ZStL10adopt_lock:
	.space 1
	.align 4
__ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
__ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
__ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
__ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
__ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
__ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
__ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
__ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
__ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
__ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
__ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
__ZNSt15regex_constantsL13match_defaultE:
	.space 4
	.align 4
__ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
__ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
__ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
__ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
__ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
__ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
__ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
__ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
__ZNSt15regex_constantsL14format_defaultE:
	.space 4
	.align 4
__ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
__ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
__ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
__ZNSt15regex_constantsL13error_collateE:
	.space 4
	.align 4
__ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
__ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
__ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
__ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
__ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
__ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
__ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
__ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
__ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
__ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
__ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
__ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 4
__ZNSt8__detailL19_S_invalid_state_idE:
	.long	-1
	.def	___main;	.scl	2;	.type	32;	.endef
LC0:
	.ascii "? \0"
LC1:
	.ascii " \0"
LC2:
	.ascii "I love taylor swifth\0"
LC3:
	.ascii "! \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7686:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA7686
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$96, %esp
	call	___main
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
LEHB0:
	call	__ZNSirsERi
	subl	$4, %esp
L13:
	movl	-48(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -48(%ebp)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L2
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$1, -12(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	$0, -36(%ebp)
L12:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jg	L3
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -40(%ebp)
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jne	L4
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L3
L4:
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	movl	$0, -24(%ebp)
	movl	-40(%ebp), %eax
	subl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -28(%ebp)
L7:
	cmpl	$0, -28(%ebp)
	je	L5
	subl	$1, -28(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
LEHE0:
	subl	$4, %esp
	movl	-56(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jg	L6
	movl	-56(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jl	L6
	addl	$1, -24(%ebp)
L6:
	movl	-56(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	L7
L5:
	movl	-12(%ebp), %eax
	movl	%eax, -32(%ebp)
L9:
	movl	-32(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jg	L8
	leal	-41(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcEC1Ev
	leal	-80(%ebp), %eax
	leal	-41(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$LC2, (%esp)
	movl	%eax, %ecx
LEHB1:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
LEHE1:
	subl	$8, %esp
	leal	-41(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	leal	-80(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addl	$1, -32(%ebp)
	jmp	L9
L8:
	movl	-24(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	L10
	movl	-40(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L12
L10:
	movl	-40(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	L12
L3:
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB2:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	jmp	L13
L2:
	movl	$0, %eax
	jmp	L17
L16:
	movl	%eax, %ebx
	leal	-41(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE2:
L17:
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7686:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA7686:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE7686-LLSDACSB7686
LLSDACSB7686:
	.uleb128 LEHB0-LFB7686
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB7686
	.uleb128 LEHE1-LEHB1
	.uleb128 L16-LFB7686
	.uleb128 0
	.uleb128 LEHB2-LFB7686
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE7686:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB8232:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8232:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB8231:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L21
	cmpl	$65535, 12(%ebp)
	jne	L21
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L21:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8231:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB8233:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8233:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef

	)");

