__asm__(R"(
	.file	"tmp.cpp"
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB13943:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "cannot create std::vector larger than max_size()\0"
	.text
	.align 2
	.p2align 4
	.def	_ZNSt6vectorI1ZSaIS0_EEC1EyRKS1_.isra.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorI1ZSaIS0_EEC1EyRKS1_.isra.0
_ZNSt6vectorI1ZSaIS0_EEC1EyRKS1_.isra.0:
.LFB13974:
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
	movq	%rcx, %rbx
	shrq	$61, %rax
	jne	.L8
	movq	$0, (%rcx)
	leaq	0(,%rdx,4), %rsi
	movq	$0, 8(%rcx)
	movq	$0, 16(%rcx)
	testq	%rdx, %rdx
	je	.L5
	movq	%rsi, %rcx
	call	_Znwy
	movq	%rsi, %r8
	xorl	%edx, %edx
	leaq	(%rax,%rsi), %rdi
	movq	%rax, (%rbx)
	movq	%rax, %rcx
	movq	%rdi, 16(%rbx)
	call	memset
.L6:
	movq	%rdi, 8(%rbx)
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
.L5:
	movq	$0, (%rcx)
	xorl	%edi, %edi
	movq	$0, 16(%rcx)
	jmp	.L6
.L8:
	leaq	.LC0(%rip), %rcx
	call	_ZSt20__throw_length_errorPKc
	nop
	.seh_endproc
	.p2align 4
	.globl	_Z4normi
	.def	_Z4normi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4normi
_Z4normi:
.LFB11909:
	.seh_endprologue
	leal	1000000007(%rcx), %eax
	testl	%ecx, %ecx
	js	.L9
	leal	-1000000007(%rcx), %eax
	cmpl	$1000000006, %ecx
	cmovle	%ecx, %eax
.L9:
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	_ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseIiSaIiEED2Ev
_ZNSt12_Vector_baseIiSaIiEED2Ev:
.LFB13189:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L13
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L13:
	ret
	.seh_endproc
	.section	.text$_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
	.def	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev:
.LFB13202:
	.seh_endprologue
	movq	(%rcx), %r8
	testq	%r8, %r8
	je	.L15
	movq	16(%rcx), %rdx
	movq	%r8, %rcx
	subq	%r8, %rdx
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L15:
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC1:
	.ascii "tmp.cpp\0"
.LC2:
	.ascii "x != 0\0"
.LC3:
	.ascii "\12\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB11930:
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
	subq	$152, %rsp
	.seh_stackalloc	152
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %r12
	leaq	44(%rsp), %rdx
	movq	$0, 232(%r12)
	movq	%r12, %rcx
	call	_ZNSirsERi
	movl	44(%rsp), %esi
	leal	1(%rsi), %ebx
	movslq	%ebx, %rbx
	movq	%rbx, %rax
	shrq	$61, %rax
	jne	.L59
	movq	$0, 56(%rsp)
	leaq	0(,%rbx,4), %r13
	movq	$0, 64(%rsp)
	testq	%rbx, %rbx
	je	.L19
	movq	%r13, %rcx
	call	_Znwy
.LEHE0:
	subq	$1, %rbx
	leaq	(%rax,%r13), %rdi
	movq	%rax, 48(%rsp)
	movq	%rax, %rbp
	leaq	4(%rax), %rcx
	movq	%rdi, 64(%rsp)
	movl	$0, (%rax)
	je	.L42
	cmpq	%rcx, %rdi
	je	.L58
	leaq	-4(%r13), %r8
	xorl	%edx, %edx
	call	memset
	movl	44(%rsp), %esi
.L20:
	movq	%rdi, 56(%rsp)
	testl	%esi, %esi
	js	.L21
	movq	%rbp, %rdi
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L22:
	movq	%rdi, %rdx
	movq	%r12, %rcx
.LEHB1:
	call	_ZNSirsERi
	movl	44(%rsp), %esi
	addl	$1, %ebx
	addq	$4, %rdi
	cmpl	%ebx, %esi
	jge	.L22
.L21:
	addl	0(%rbp), %esi
	leaq	80(%rsp), %r12
	leal	1(%rsi), %ebx
	movq	%r12, %rcx
	movslq	%ebx, %r14
	movq	%r14, %rdx
	call	_ZNSt6vectorI1ZSaIS0_EEC1EyRKS1_.isra.0
.LEHE1:
	leaq	112(%rsp), %r13
	movq	%r14, %rdx
	movq	%r13, %rcx
.LEHB2:
	call	_ZNSt6vectorI1ZSaIS0_EEC1EyRKS1_.isra.0
.LEHE2:
	movq	80(%rsp), %rdi
	movl	$1, (%rdi)
	testl	%esi, %esi
	jle	.L23
	movl	%ebx, %r9d
	movl	$2, %r8d
	movl	$1, %eax
	movl	$1, %ecx
	movabsq	$-8543223828751151131, %r10
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L28:
	cmpl	$1000000006, %r8d
	leal	-1000000007(%rcx), %edx
	cmovg	%edx, %ecx
	addq	$1, %r8
.L24:
	movslq	%ecx, %rcx
	imulq	%rax, %rcx
	movq	%rcx, %rax
	imulq	%r10
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	imulq	$1000000007, %rdx, %rdx
	subq	%rdx, %rcx
	movl	%ecx, -4(%rdi,%r8,4)
	movslq	%ecx, %rax
	movl	%r8d, %ecx
	cmpq	%r8, %r9
	jne	.L28
.L23:
	movslq	%esi, %rbx
	leaq	0(,%rbx,4), %r14
	leaq	(%rdi,%r14), %r15
	movl	(%r15), %eax
	testl	%eax, %eax
	je	.L60
.L25:
	movl	(%r15), %ecx
	movl	$30, %r10d
	movl	$1, %r8d
	movl	$1000000005, %r9d
	movabsq	$-8543223828751151131, %r11
	.p2align 4,,10
	.p2align 3
.L29:
	movslq	%ecx, %rcx
	testb	$1, %r9b
	je	.L30
	movslq	%r8d, %r8
	imulq	%rcx, %r8
	movq	%r8, %rax
	imulq	%r11
	movq	%r8, %rax
	sarq	$63, %rax
	addq	%r8, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	imulq	$1000000007, %rdx, %rdx
	subl	%edx, %r8d
.L30:
	movq	%r9, %rax
	imulq	%rcx, %rcx
	shrq	$63, %rax
	addq	%r9, %rax
	sarq	%rax
	movq	%rax, %r9
	movq	%rcx, %rax
	imulq	%r11
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	imulq	$1000000007, %rdx, %rdx
	subl	%edx, %ecx
	subl	$1, %r10d
	jne	.L29
	movq	112(%rsp), %r9
	movl	%r8d, (%r9,%r14)
	testl	%esi, %esi
	jle	.L31
	movabsq	$-8543223828751151131, %r10
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L61:
	leal	-1000000007(%rbx), %eax
	cltq
	imulq	%rax, %rcx
	movq	%rcx, %rax
	imulq	%r10
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	imulq	$1000000007, %rdx, %rdx
	subq	%rdx, %rcx
	movl	%ecx, -4(%r9,%rbx,4)
	movl	%ecx, %r8d
.L33:
	subq	$1, %rbx
.L34:
	movslq	%r8d, %rcx
	cmpl	$1000000006, %ebx
	jg	.L61
	imulq	%rbx, %rcx
	movq	%rcx, %rax
	imulq	%r10
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	leal	-1(%rbx), %eax
	imulq	$1000000007, %rdx, %rdx
	subq	%rdx, %rcx
	movl	%ecx, -4(%r9,%rbx,4)
	movl	%ecx, %r8d
	testl	%eax, %eax
	jg	.L33
.L31:
	movslq	44(%rsp), %r11
	testl	%r11d, %r11d
	js	.L43
	movabsq	$-8543223828751151131, %rbx
	xorl	%r8d, %r8d
	xorl	%r10d, %r10d
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L37:
	leal	-1000000007(%r10), %eax
	cmpl	$1000000006, %r10d
	cmovg	%eax, %r10d
.L36:
	leaq	1(%r8), %rax
	cmpq	%r11, %r8
	je	.L35
.L44:
	movq	%rax, %r8
.L38:
	movl	0(%rbp,%r8,4), %esi
	testl	%esi, %esi
	jle	.L36
	leal	(%rsi,%r8), %eax
	subl	$1, %esi
	cltq
	movslq	%esi, %rsi
	movslq	(%rdi,%rax,4), %rcx
	movslq	4(%r9,%r8,4), %rax
	imulq	%rax, %rcx
	movq	%rcx, %rax
	imulq	%rbx
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	movslq	(%r9,%rsi,4), %rax
	imulq	$1000000007, %rdx, %rdx
	subq	%rdx, %rcx
	imulq	%rax, %rcx
	movq	%rcx, %rax
	imulq	%rbx
	movq	%rcx, %rax
	sarq	$63, %rax
	addq	%rcx, %rdx
	sarq	$29, %rdx
	subq	%rax, %rdx
	imulq	$1000000007, %rdx, %rdx
	subq	%rdx, %rcx
	addl	%ecx, %r10d
	jns	.L37
	addl	$1000000007, %r10d
	leaq	1(%r8), %rax
	cmpq	%r11, %r8
	jne	.L44
.L35:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	%r10d, %edx
.LEHB3:
	call	_ZNSolsEi
	movq	%rax, %rcx
	movl	$1, %r8d
	leaq	.LC3(%rip), %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movq	%r13, %rcx
	call	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
	movq	%r12, %rcx
	call	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
	leaq	48(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	xorl	%eax, %eax
	addq	$152, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L19:
	movq	$0, 48(%rsp)
	xorl	%ebp, %ebp
	xorl	%edi, %edi
	movq	$0, 64(%rsp)
	jmp	.L20
.L60:
	movl	$36, %r8d
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	*__imp__assert(%rip)
.LEHE3:
	jmp	.L25
.L42:
	movq	%rcx, %rdi
.L58:
	movl	44(%rsp), %esi
	jmp	.L20
.L43:
	xorl	%r10d, %r10d
	jmp	.L35
.L59:
	leaq	.LC0(%rip), %rcx
.LEHB4:
	call	_ZSt20__throw_length_errorPKc
.L45:
	movq	%rax, %r12
.L41:
	leaq	48(%rsp), %rcx
	call	_ZNSt12_Vector_baseIiSaIiEED2Ev
	movq	%r12, %rcx
	call	_Unwind_Resume
.LEHE4:
.L46:
	movq	%rax, %rbx
	jmp	.L40
.L47:
	movq	%r13, %rcx
	movq	%rax, %rbx
	call	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
.L40:
	movq	%r12, %rcx
	movq	%rbx, %r12
	call	_ZNSt12_Vector_baseI1ZSaIS0_EED2Ev
	jmp	.L41
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA11930:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE11930-.LLSDACSB11930
.LLSDACSB11930:
	.uleb128 .LEHB0-.LFB11930
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB11930
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L45-.LFB11930
	.uleb128 0
	.uleb128 .LEHB2-.LFB11930
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L46-.LFB11930
	.uleb128 0
	.uleb128 .LEHB3-.LFB11930
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L47-.LFB11930
	.uleb128 0
	.uleb128 .LEHB4-.LFB11930
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE11930:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z4normi;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z4normi
_GLOBAL__sub_I__Z4normi:
.LFB13966:
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
	.quad	_GLOBAL__sub_I__Z4normi
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
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
