__asm__(R"(
	.file	"C.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11288:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.globl	_Z3qryxx
	.def	_Z3qryxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3qryxx
_Z3qryxx:
.LFB10114:
	.seh_endprologue
	xorl	%eax, %eax
	cmpq	%rdx, %rcx
	jg	.L3
	leaq	sum(%rip), %r8
	movq	(%r8,%rdx,8), %rax
	subq	-8(%r8,%rcx,8), %rax
.L3:
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_
	.def	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_
_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_:
.LFB10771:
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
	movq	16(%rdx), %r10
	movb	$1, %al
	leaq	8(%rdx), %r13
	movq	%rcx, %rbx
	movq	%rdx, %rsi
	movq	%r8, %r12
	movq	%r13, %rbp
.L7:
	testq	%r10, %r10
	je	.L18
	movq	32(%r10), %rax
	cmpq	%rax, (%r12)
	jge	.L8
	movq	16(%r10), %rdx
	movb	$1, %al
	jmp	.L9
.L8:
	movq	24(%r10), %rdx
	xorl	%eax, %eax
.L9:
	movq	%r10, %rbp
	movq	%rdx, %r10
	jmp	.L7
.L18:
	testb	%al, %al
	je	.L16
	movq	24(%rsi), %rdi
	cmpq	%rdi, %rbp
	je	.L12
	movq	%rbp, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	jmp	.L11
.L16:
	movq	%rbp, %rax
.L11:
	movq	(%r12), %rdx
	cmpq	%rdx, 32(%rax)
	jge	.L13
	movq	%rbp, %rdi
.L12:
	cmpq	%r13, %rdi
	movb	$1, %bpl
	je	.L14
	movq	32(%rdi), %rax
	cmpq	%rax, (%r12)
	setl	%bpl
.L14:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %r14
	movq	(%r12), %rax
	movzbl	%bpl, %ecx
	movq	%r13, %r9
	movq	%rdi, %r8
	movq	%r14, %rdx
	movq	%rax, 32(%r14)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	incq	40(%rsi)
	movq	%r14, (%rbx)
	movb	$1, 8(%rbx)
	jmp	.L6
.L13:
	movq	%rax, (%rbx)
	movb	$0, 8(%rbx)
.L6:
	movq	%rbx, %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE
	.def	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE
_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE:
.LFB10933:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rsi
	movq	%rdx, %rbx
.L20:
	testq	%rbx, %rbx
	je	.L22
	movq	24(%rbx), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE
	movq	16(%rbx), %rdi
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rdi, %rbx
	jmp	.L20
.L22:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx
	.def	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx
_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx:
.LFB10784:
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
	movq	16(%rcx), %r9
	leaq	8(%rcx), %rbp
	movq	%rcx, %rsi
	movq	%rbp, %rdi
	movq	%r9, %rbx
.L24:
	testq	%rbx, %rbx
	je	.L48
	movq	32(%rbx), %rax
	movq	(%rdx), %r8
	cmpq	%r8, %rax
	jge	.L25
	movq	24(%rbx), %rax
	movq	%rdi, %rbx
	jmp	.L26
.L25:
	cmpq	%rax, %r8
	movq	16(%rbx), %rax
	jl	.L26
	movq	24(%rbx), %rcx
.L28:
	testq	%rcx, %rcx
	je	.L32
	cmpq	32(%rcx), %r8
	jge	.L29
	movq	16(%rcx), %rdx
	jmp	.L30
.L29:
	movq	24(%rcx), %rdx
	movq	%rdi, %rcx
.L30:
	movq	%rcx, %rdi
	movq	%rdx, %rcx
	jmp	.L28
.L35:
	cmpq	%r8, 32(%rax)
	jl	.L33
	movq	16(%rax), %rdx
.L34:
	movq	%rax, %rbx
	movq	%rdx, %rax
.L32:
	testq	%rax, %rax
	jne	.L35
	jmp	.L36
.L33:
	movq	24(%rax), %rdx
	movq	%rbx, %rax
	jmp	.L34
.L26:
	movq	%rbx, %rdi
	movq	%rax, %rbx
	jmp	.L24
.L48:
	movq	%rdi, %rbx
.L36:
	cmpq	24(%rsi), %rbx
	movq	40(%rsi), %r12
	jne	.L40
	cmpq	%rbp, %rdi
	je	.L49
.L40:
	cmpq	%rdi, %rbx
	je	.L42
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	movq	%rbx, %rcx
	movq	%rbp, %rdx
	movq	%rax, %r13
	call	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_
	movq	%rax, %rcx
	movq	%r13, %rbx
	call	_ZdlPv
	decq	40(%rsi)
	jmp	.L40
.L49:
	movq	%r9, %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE
	movq	%rbp, 24(%rsi)
	movq	$0, 16(%rsi)
	movq	%rbp, 32(%rsi)
	movq	$0, 40(%rsi)
.L42:
	movq	%r12, %rax
	subq	40(%rsi), %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.seh_endproc
	.text
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB10115:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	p(%rip), %rbx
	leaq	n(%rip), %rdx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	_ZNSirsERx
.L51:
	addq	$8, %rbx
	cmpq	n(%rip), %rsi
	jg	.L76
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%rbx, %rdx
	incq	%rsi
	call	_ZNSirsERx
	jmp	.L51
.L76:
	leaq	q(%rip), %rbx
	movl	$1, %esi
	movq	%rbx, %rbp
.L53:
	movq	n(%rip), %rdx
	addq	$8, %rbx
	cmpq	%rdx, %rsi
	jg	.L77
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	%rbx, %rdx
	incq	%rsi
	call	_ZNSirsERx
	jmp	.L53
.L77:
	movl	$1, %eax
.L55:
	cmpq	%rdx, %rax
	jg	.L78
	movq	(%rdi,%rax,8), %r8
	movq	0(%rbp,%rax,8), %r9
	leaq	nxt(%rip), %rcx
	incq	%rax
	movq	%r9, (%rcx,%r8,8)
	jmp	.L55
.L78:
	leaq	32(%rsp), %rbx
	leaq	56(%rsp), %rsi
	movq	$0, cnt(%rip)
	movq	$0, ans(%rip)
	movq	$1, 56(%rsp)
.L57:
	movq	n(%rip), %rax
	cmpq	%rax, 56(%rsp)
	jg	.L79
	leaq	S(%rip), %rdx
	movq	%rsi, %r8
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE16_M_insert_uniqueIRKxEESt4pairISt17_Rb_tree_iteratorIxEbEOT_
	incq	56(%rsp)
	jmp	.L57
.L79:
	leaq	8+S(%rip), %rbp
	leaq	56(%rsp), %rdi
	movq	%rbp, %rbx
.L59:
	cmpq	$0, 40+S(%rip)
	je	.L80
	movq	24+S(%rip), %rax
	leaq	S(%rip), %rcx
	movq	%rdi, %rdx
	movl	$1, %esi
	movq	32(%rax), %rax
	movq	%rax, 56(%rsp)
	call	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx
.L66:
	movq	56(%rsp), %rdx
	leaq	nxt(%rip), %rax
	leaq	8+S(%rip), %rcx
	movq	(%rax,%rdx,8), %r8
	movq	16+S(%rip), %rax
	movq	%r8, 56(%rsp)
.L60:
	testq	%rax, %rax
	je	.L81
	cmpq	%r8, 32(%rax)
	jl	.L61
	movq	16(%rax), %rdx
	jmp	.L62
.L61:
	movq	24(%rax), %rdx
	movq	%rcx, %rax
.L62:
	movq	%rax, %rcx
	movq	%rdx, %rax
	jmp	.L60
.L81:
	cmpq	%rbx, %rcx
	movq	%rbx, %rax
	je	.L64
	cmpq	32(%rcx), %r8
	movq	%rcx, %rax
	cmovl	%rbp, %rax
.L64:
	cmpq	%rbx, %rax
	je	.L65
	leaq	S(%rip), %rcx
	movq	%rdi, %rdx
	incq	%rsi
	call	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE5eraseERKx
	jmp	.L66
.L65:
	andb	$1, %sil
	je	.L59
	incq	cnt(%rip)
	jmp	.L59
.L80:
	movq	n(%rip), %r8
	movl	$1, %eax
.L69:
	cmpq	%r8, %rax
	jg	.L82
	leaq	-8+sum(%rip), %rdx
	movq	%rax, %rcx
	addq	(%rdx,%rax,8), %rcx
	leaq	sum(%rip), %rdx
	movq	%rcx, (%rdx,%rax,8)
	incq	%rax
	jmp	.L69
.L82:
	movq	%r8, %rax
	subq	cnt(%rip), %rax
	movl	$2, %ecx
	cqto
	idivq	%rcx
	movq	%r8, %rcx
	movq	%r8, %rdx
	subq	%rax, %rcx
	movq	%rax, %rsi
	incq	%rcx
	call	_Z3qryxx
	movq	%rsi, %rdx
	movq	%rax, %rbx
	movl	$1, %ecx
	call	_Z3qryxx
	movq	.refptr._ZSt4cout(%rip), %rcx
	subq	%rax, %rbx
	leaq	(%rbx,%rbx), %rdx
	movq	%rdx, ans(%rip)
	call	_ZNSo9_M_insertIxEERSoT_
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10116:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	T(%rip), %rdx
	call	_ZNSirsERx
.L84:
	movq	T(%rip), %rax
	leaq	-1(%rax), %rdx
	testq	%rax, %rax
	movq	%rdx, T(%rip)
	je	.L86
	call	_Z5solvev
	jmp	.L84
.L86:
	addq	$40, %rsp
	ret
	.seh_endproc
	.text
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11292:
	.seh_endprologue
	movq	16+S(%rip), %rdx
	leaq	S(%rip), %rcx
	jmp	_ZNSt8_Rb_treeIxxSt9_IdentityIxESt4lessIxESaIxEE8_M_eraseEPSt13_Rb_tree_nodeIxE
	.seh_endproc
	.section	.text.startup,"x"
	.def	_GLOBAL__sub_I_T;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_T
_GLOBAL__sub_I_T:
.LFB11323:
	pushq	%rdi
	.seh_pushreg	%rdi
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	8+S(%rip), %rdx
	xorl	%eax, %eax
	movl	$8, %ecx
	movq	$0, 40+S(%rip)
	movq	%rdx, %rdi
	rep stosl
	leaq	__tcf_1(%rip), %rcx
	movq	%rdx, 24+S(%rip)
	movq	%rdx, 32+S(%rip)
	addq	$32, %rsp
	popq	%rdi
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_T
	.globl	sum
	.bss
	.align 64
sum:
	.space 800080
	.globl	S
	.align 16
S:
	.space 48
	.globl	ans
	.align 8
ans:
	.space 8
	.globl	cnt
	.align 8
cnt:
	.space 8
	.globl	nxt
	.align 64
nxt:
	.space 800080
	.globl	q
	.align 64
q:
	.space 800080
	.globl	p
	.align 64
p:
	.space 800080
	.globl	n
	.align 8
n:
	.space 8
	.globl	T
	.align 8
T:
	.space 8
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERx;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
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
