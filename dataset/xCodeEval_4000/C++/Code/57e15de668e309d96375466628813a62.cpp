__asm__(R"(
	.file	"CF1688D.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB4636:
	.seh_endprologue
	movl	%edx, %eax
	ret
	.seh_endproc
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB8555:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.globl	_Z7dbg_outv
	.def	_Z7dbg_outv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7dbg_outv
_Z7dbg_outv:
.LFB7648:
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	.refptr._ZSt4clog(%rip), %r13
	movq	0(%r13), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%r13), %r12
	testq	%r12, %r12
	je	.L9
	cmpb	$0, 56(%r12)
	je	.L6
	movsbl	67(%r12), %edx
.L7:
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	addq	$40, %rsp
	popq	%r12
	popq	%r13
	jmp	_ZNSo5flushEv
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%r12, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%r12), %rax
	movl	$10, %edx
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L7
	movq	%r12, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L7
.L9:
	call	_ZSt16__throw_bad_castv
	nop
	.seh_endproc
	.p2align 4
	.globl	_Z4readv
	.def	_Z4readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readv
_Z4readv:
.LFB7650:
	.seh_endprologue
	ret
	.seh_endproc
	.section	.text$_Z4readIiJEEvRT_DpRT0_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z4readIiJEEvRT_DpRT0_
	.def	_Z4readIiJEEvRT_DpRT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readIiJEEvRT_DpRT0_
_Z4readIiJEEvRT_DpRT0_:
.LFB8082:
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
	movq	.refptr._ZSt3cin(%rip), %rsi
	xorl	%edi, %edi
	movl	$0, (%rcx)
	movq	%rcx, %rbx
	movq	%rsi, %rcx
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L15
	movl	$1, %ebp
	.p2align 4,,10
	.p2align 3
.L14:
	cmpb	$45, %dl
	movq	%rsi, %rcx
	cmove	%ebp, %edi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L14
	.p2align 4,,10
	.p2align 3
.L15:
	movl	(%rbx), %eax
	movq	%rsi, %rcx
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
	movl	%eax, (%rbx)
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L15
	testb	%dil, %dil
	je	.L11
	negl	(%rbx)
.L11:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6qprintIxEvT_,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6qprintIxEvT_
	.def	_Z6qprintIxEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6qprintIxEvT_
_Z6qprintIxEvT_:
.LFB8261:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	.refptr._ZSt4cout(%rip), %r12
	movq	%rcx, %rbx
	testq	%rcx, %rcx
	js	.L32
.L24:
	cmpq	$9, %rbx
	jg	.L33
.L30:
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	jmp	_ZNSo3putEc
	.p2align 4,,10
	.p2align 3
.L33:
	movabsq	$-3689348814741910323, %rcx
	movq	%rbx, %rax
	mulq	%rcx
	movq	%rdx, %rsi
	shrq	$3, %rsi
	cmpq	$99, %rbx
	jg	.L34
.L28:
	movabsq	$-3689348814741910323, %rdx
	movq	%rsi, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rsi
	leal	48(%rsi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L30
	.p2align 4,,10
	.p2align 3
.L32:
	movl	$45, %edx
	movq	%r12, %rcx
	negq	%rbx
	call	_ZNSo3putEc
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L34:
	movq	%rsi, %rax
	mulq	%rcx
	movq	%rdx, %rdi
	shrq	$3, %rdi
	cmpq	$999, %rbx
	jg	.L35
.L26:
	movabsq	$-3689348814741910323, %rdx
	movq	%rdi, %rax
	movq	%r12, %rcx
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rdi
	leal	48(%rdi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L35:
	movq	%rdi, %rax
	mulq	%rcx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L26
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "cannot create std::vector larger than max_size()\0"
	.text
	.p2align 4
	.globl	_Z8solutionv
	.def	_Z8solutionv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8solutionv
_Z8solutionv:
.LFB7654:
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
	movq	.refptr._ZSt3cin(%rip), %rbx
	xorl	%esi, %esi
	movq	%rbx, %rcx
.LEHB0:
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L37
	movl	$1, %edi
	.p2align 4,,10
	.p2align 3
.L39:
	cmpb	$45, %dl
	movq	%rbx, %rcx
	cmove	%edi, %esi
	call	_ZNSi3getEv
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L39
.L37:
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L40:
	leal	(%rdi,%rdi,4), %eax
	movq	%rbx, %rcx
	leal	(%rdx,%rax,2), %r12d
	call	_ZNSi3getEv
	leal	-48(%r12), %edi
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L40
	movl	$48, %eax
	leaq	44(%rsp), %rcx
	subl	%r12d, %eax
	testb	%sil, %sil
	cmovne	%eax, %edi
	call	_Z4readIiJEEvRT_DpRT0_
	leal	1(%rdi), %esi
	movslq	%esi, %rsi
	movq	%rsi, %rax
	shrq	$61, %rax
	jne	.L106
	leaq	0(,%rsi,4), %r13
	testq	%rsi, %rsi
	je	.L73
	movq	%r13, %rcx
	call	_Znwy
.LEHE0:
	movl	$0, (%rax)
	movq	%rax, %r12
	leaq	(%rax,%r13), %rbp
	leaq	4(%rax), %rbx
	cmpq	$1, %rsi
	je	.L43
	cmpq	%rbp, %rbx
	je	.L44
	leaq	-4(%r13), %r8
	xorl	%edx, %edx
	movq	%rbx, %rcx
	call	memset
.L44:
	testl	%edi, %edi
	jle	.L74
	leal	-1(%rdi), %eax
	leaq	8(%r12,%rax,4), %rsi
	.p2align 4,,10
	.p2align 3
.L46:
	movq	%rbx, %rcx
.LEHB1:
	call	_Z4readIiJEEvRT_DpRT0_
.LEHE1:
	addq	$4, %rbx
	cmpq	%rbx, %rsi
	jne	.L46
.L74:
	movslq	44(%rsp), %r8
	movq	%rbp, %rsi
	cmpl	%edi, %r8d
	jle	.L107
.L47:
	leaq	4(%r12), %rax
	xorl	%ebx, %ebx
	cmpq	%rbp, %rax
	je	.L56
	.p2align 4,,10
	.p2align 3
.L57:
	movslq	(%rax), %rcx
	addq	$4, %rax
	addq	%rcx, %rbx
	cmpq	%rbp, %rax
	jne	.L57
	testl	%edi, %edi
	jle	.L61
.L59:
	movslq	%r8d, %rdx
	leaq	-1(%rdx), %rax
	.p2align 4,,10
	.p2align 3
.L62:
	addq	%rax, %rbx
	movl	%edx, %ecx
	subq	$1, %rax
	subl	%eax, %ecx
	cmpl	%edi, %ecx
	jle	.L62
.L61:
	testq	%rbx, %rbx
	js	.L108
.L63:
	cmpq	$9, %rbx
	jg	.L71
	leal	48(%rbx), %edx
	movq	.refptr._ZSt4cout(%rip), %r13
	movzbl	%dl, %edx
.L60:
	movq	%r13, %rcx
.LEHB2:
	call	_ZNSo3putEc
.L105:
	movl	$32, %edx
	movq	%r13, %rcx
	call	_ZNSo3putEc
	movl	$10, %edx
	movq	%r13, %rcx
	call	_ZNSo3putEc
	testq	%r12, %r12
	je	.L36
	subq	%r12, %rsi
	movq	%r12, %rcx
	movq	%rsi, %rdx
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	jmp	_ZdlPvy
	.p2align 4,,10
	.p2align 3
.L73:
	xorl	%ebp, %ebp
	xorl	%r12d, %r12d
	xorl	%ebx, %ebx
.L43:
	movslq	44(%rsp), %r8
	movq	%rbp, %rsi
	movq	%rbx, %rbp
	cmpl	%edi, %r8d
	jg	.L47
	.p2align 4,,10
	.p2align 3
.L107:
	testl	%r8d, %r8d
	jle	.L75
	leal	-1(%r8), %eax
	leaq	4(%r12), %rcx
	movq	%rax, %r11
	leaq	8(%r12,%rax,4), %r9
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L49:
	movslq	(%rcx), %rdx
	addq	$4, %rcx
	addq	%rdx, %rax
	cmpq	%rcx, %r9
	jne	.L49
.L48:
	cmpl	%edi, %r8d
	jge	.L76
	subl	%r8d, %edi
	leaq	4(%r12), %rdx
	movq	%rax, %r9
	leal	-1(%rdi), %ecx
	leaq	8(%r12,%rcx,4), %r10
	.p2align 4,,10
	.p2align 3
.L51:
	movslq	(%rdx), %rcx
	subq	%rcx, %rax
	movslq	(%rdx,%r8,4), %rcx
	addq	%rcx, %rax
	cmpq	%rax, %r9
	cmovl	%rax, %r9
	addq	$4, %rdx
	cmpq	%r10, %rdx
	jne	.L51
.L50:
	movslq	%r11d, %r11
	imulq	%r8, %r11
	movq	%r11, %rbx
	shrq	$63, %rbx
	addq	%r11, %rbx
	sarq	%rbx
	addq	%r9, %rbx
	js	.L109
.L52:
	cmpq	$9, %rbx
	jg	.L110
.L53:
	movq	%rbx, %rax
	movq	.refptr._ZSt4cout(%rip), %r13
	movabsq	$-3689348814741910323, %rdx
	mulq	%rdx
	movq	%r13, %rcx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L36:
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
	.p2align 3
.L71:
	movabsq	$-3689348814741910323, %rcx
	movq	%rbx, %rax
	mulq	%rcx
	movq	%rdx, %rdi
	shrq	$3, %rdi
	cmpq	$99, %rbx
	jg	.L111
.L70:
	movq	%rdi, %rax
	movq	.refptr._ZSt4cout(%rip), %r13
	movabsq	$-3689348814741910323, %rdx
	mulq	%rdx
	movq	%r13, %rcx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rdi
	leal	48(%rdi), %edx
	movzbl	%dl, %edx
	call	_ZNSo3putEc
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	mulq	%rdx
	shrq	$3, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	movq	%rbx, %rdx
	addl	$48, %edx
	movzbl	%dl, %edx
	jmp	.L60
.L111:
	movq	%rdi, %rax
	mulq	%rcx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L108:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
	negq	%rbx
	jmp	.L63
	.p2align 4,,10
	.p2align 3
.L110:
	movabsq	$-3689348814741910323, %rdx
	movq	%rbx, %rax
	mulq	%rdx
	movq	%rdx, %rcx
	shrq	$3, %rcx
	call	_Z6qprintIxEvT_
	jmp	.L53
.L109:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$45, %edx
	call	_ZNSo3putEc
.LEHE2:
	negq	%rbx
	jmp	.L52
.L56:
	movq	.refptr._ZSt4cout(%rip), %r13
	movl	$48, %edx
	testl	%edi, %edi
	jg	.L59
	jmp	.L60
.L76:
	movq	%rax, %r9
	jmp	.L50
.L75:
	xorl	%eax, %eax
	leal	-1(%r8), %r11d
	jmp	.L48
.L106:
	leaq	.LC0(%rip), %rcx
.LEHB3:
	call	_ZSt20__throw_length_errorPKc
.L78:
	subq	%r12, %rsi
	movq	%rax, %r14
	movq	%rsi, %rdx
	testq	%r12, %r12
	je	.L68
.L66:
	movq	%r12, %rcx
	call	_ZdlPvy
.L68:
	movq	%r14, %rcx
	call	_Unwind_Resume
.LEHE3:
.L79:
	movq	%rax, %r14
	movq	%r13, %rdx
	jmp	.L66
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA7654:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7654-.LLSDACSB7654
.LLSDACSB7654:
	.uleb128 .LEHB0-.LFB7654
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB7654
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L79-.LFB7654
	.uleb128 0
	.uleb128 .LEHB2-.LFB7654
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L78-.LFB7654
	.uleb128 0
	.uleb128 .LEHB3-.LFB7654
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE7654:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC1:
	.ascii "w\0"
.LC2:
	.ascii "testdata.log\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB7656:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movl	$2, %ecx
	call	*__imp___acrt_iob_func(%rip)
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	movq	%rax, %r8
	call	freopen
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	44(%rsp), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	$0, 232(%rcx)
	movq	$0, 224(%rax)
	call	_ZNSirsERi
	jmp	.L119
	.p2align 4,,10
	.p2align 3
.L120:
	call	_Z8solutionv
.L119:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L120
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z7dbg_outv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7dbg_outv
_GLOBAL__sub_I__Z7dbg_outv:
.LFB8556:
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
	.quad	_GLOBAL__sub_I__Z7dbg_outv
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 11.2.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZNSi3getEv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
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
	.section	.rdata$.refptr._ZSt4clog, "dr"
	.globl	.refptr._ZSt4clog
	.linkonce	discard
.refptr._ZSt4clog:
	.quad	_ZSt4clog
)");
