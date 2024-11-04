__asm__(R"(
	.file	"c.cpp"
	.text
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB21:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
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
_ZL4maxn:
	.long	200010
	.section	.text$_ZN3dsu4initEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3dsu4initEi
	.def	_ZN3dsu4initEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3dsu4initEi
_ZN3dsu4initEi:
.LFB8747:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 24(%rbp)
	movl	%edx, 32(%rbp)
	movl	$1, %ebx
.L5:
	cmpl	32(%rbp), %ebx
	jg	.L6
	movq	24(%rbp), %rdx
	movslq	%ebx, %rax
	movl	%ebx, (%rdx,%rax,4)
	movq	24(%rbp), %rax
	movslq	%ebx, %rdx
	addq	$200008, %rdx
	movl	$1, 8(%rax,%rdx,4)
	addl	$1, %ebx
	jmp	.L5
.L6:
	nop
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN3dsu4findEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3dsu4findEi
	.def	_ZN3dsu4findEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3dsu4findEi
_ZN3dsu4findEi:
.LFB8748:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rdx
	movl	24(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	cmpl	%eax, 24(%rbp)
	je	.L8
	movq	16(%rbp), %rdx
	movl	24(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN3dsu4findEi
	movl	%eax, %ecx
	movq	16(%rbp), %rdx
	movl	24(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	movq	16(%rbp), %rdx
	movl	24(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	jmp	.L10
.L8:
	movl	24(%rbp), %eax
.L10:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN3dsu5mergeEii,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3dsu5mergeEii
	.def	_ZN3dsu5mergeEii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3dsu5mergeEii
_ZN3dsu5mergeEii:
.LFB8749:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN3dsu4findEi
	movl	%eax, 24(%rbp)
	movl	32(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN3dsu4findEi
	movl	%eax, 32(%rbp)
	movl	24(%rbp), %edx
	movl	32(%rbp), %eax
	cmpl	%eax, %edx
	je	.L12
	movl	24(%rbp), %edx
	movq	16(%rbp), %rax
	movslq	%edx, %rdx
	addq	$200008, %rdx
	movl	8(%rax,%rdx,4), %ecx
	movl	32(%rbp), %edx
	movq	16(%rbp), %rax
	movslq	%edx, %rdx
	addq	$200008, %rdx
	movl	8(%rax,%rdx,4), %eax
	cmpl	%eax, %ecx
	jle	.L13
	leaq	32(%rbp), %rdx
	leaq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
.L13:
	movl	24(%rbp), %eax
	movl	32(%rbp), %ecx
	movq	16(%rbp), %rdx
	cltq
	movl	%ecx, (%rdx,%rax,4)
	movl	32(%rbp), %edx
	movq	16(%rbp), %rax
	movslq	%edx, %rdx
	addq	$200008, %rdx
	movl	8(%rax,%rdx,4), %ecx
	movl	24(%rbp), %edx
	movq	16(%rbp), %rax
	movslq	%edx, %rdx
	addq	$200008, %rdx
	movl	8(%rax,%rdx,4), %eax
	movl	32(%rbp), %edx
	addl	%eax, %ecx
	movq	16(%rbp), %rax
	movslq	%edx, %rdx
	addq	$200008, %rdx
	movl	%ecx, 8(%rax,%rdx,4)
	movl	$1, %eax
	jmp	.L14
.L12:
	movl	$0, %eax
.L14:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	d
	.bss
	.align 32
d:
	.space 1600080
	.globl	to
	.align 32
to:
	.space 1600080
	.globl	m
	.align 4
m:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	t_case
	.align 4
t_case:
	.space 4
	.globl	mst
	.align 32
mst:
	.space 200010
	.globl	e
	.align 32
e:
	.space 3200160
	.globl	hd
	.align 32
hd:
	.space 800040
	.globl	len
	.align 4
len:
	.space 4
	.section	.text$_Z7addedgeii,"x"
	.linkonce discard
	.globl	_Z7addedgeii
	.def	_Z7addedgeii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7addedgeii
_Z7addedgeii:
.LFB8750:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	len(%rip), %eax
	addl	$1, %eax
	movl	%eax, len(%rip)
	movl	len(%rip), %eax
	movl	16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	hd(%rip), %rdx
	movl	(%rcx,%rdx), %ecx
	movslq	%eax, %rdx
	leaq	0(,%rdx,8), %r8
	leaq	e(%rip), %rdx
	movl	24(%rbp), %r9d
	movl	%r9d, (%r8,%rdx)
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	4+e(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	movl	len(%rip), %ecx
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	hd(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	dep
	.bss
	.align 32
dep:
	.space 800040
	.globl	dfn
	.align 4
dfn:
	.space 4
	.globl	fa
	.align 32
fa:
	.space 800040
	.globl	rev
	.align 32
rev:
	.space 800040
	.globl	seg
	.align 32
seg:
	.space 800040
	.globl	siz
	.align 32
siz:
	.space 800040
	.globl	son
	.align 32
son:
	.space 800040
	.globl	top
	.align 32
top:
	.space 800040
	.text
	.globl	_Z4dfs1ii
	.def	_Z4dfs1ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4dfs1ii
_Z4dfs1ii:
.LFB8751:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -64(%rbp)
	movl	%edx, -56(%rbp)
	movl	-56(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	leal	1(%rax), %ecx
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	fa(%rip), %rax
	movl	-56(%rbp), %ecx
	movl	%ecx, (%rdx,%rax)
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	$1, (%rdx,%rax)
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	hd(%rip), %rax
	movl	(%rdx,%rax), %ebx
.L19:
	testl	%ebx, %ebx
	je	.L20
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	%eax, -56(%rbp)
	je	.L18
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	-64(%rbp), %edx
	movl	%eax, %ecx
	call	_Z4dfs1ii
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%eax, %ecx
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	son(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	%eax, %ecx
	jle	.L18
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	son(%rip), %rax
	movl	%ecx, (%rdx,%rax)
.L18:
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	4+e(%rip), %rax
	movl	(%rdx,%rax), %ebx
	jmp	.L19
.L20:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z4dfs2ii
	.def	_Z4dfs2ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4dfs2ii
_Z4dfs2ii:
.LFB8752:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -64(%rbp)
	movl	%edx, -56(%rbp)
	movl	dfn(%rip), %eax
	addl	$1, %eax
	movl	%eax, dfn(%rip)
	movl	dfn(%rip), %ecx
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	movl	dfn(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	rev(%rip), %rax
	movl	-64(%rbp), %ecx
	movl	%ecx, (%rdx,%rax)
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	-56(%rbp), %ecx
	movl	%ecx, (%rdx,%rax)
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	son(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	je	.L26
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	son(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	-56(%rbp), %edx
	movl	%eax, %ecx
	call	_Z4dfs2ii
	movl	-64(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	hd(%rip), %rax
	movl	(%rdx,%rax), %ebx
.L25:
	testl	%ebx, %ebx
	je	.L26
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	jne	.L24
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	e(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rcx
	leaq	e(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	%eax, %ecx
	call	_Z4dfs2ii
.L24:
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	4+e(%rip), %rax
	movl	(%rdx,%rax), %ebx
	jmp	.L25
.L26:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3lcaii,"x"
	.linkonce discard
	.globl	_Z3lcaii
	.def	_Z3lcaii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3lcaii
_Z3lcaii:
.LFB8753:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
.L30:
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	%eax, %ecx
	je	.L28
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	%eax, %ecx
	jge	.L29
	leaq	24(%rbp), %rax
	movq	%rax, %rdx
	leaq	16(%rbp), %rcx
	call	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
.L29:
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	fa(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, 16(%rbp)
	jmp	.L30
.L28:
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	%eax, %ecx
	jge	.L31
	movl	16(%rbp), %eax
	jmp	.L33
.L31:
	movl	24(%rbp), %eax
.L33:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3kthii,"x"
	.linkonce discard
	.globl	_Z3kthii
	.def	_Z3kthii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3kthii
_Z3kthii:
.LFB8754:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
.L36:
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	cmpl	%eax, 24(%rbp)
	jle	.L35
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	fa(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	subl	%eax, 24(%rbp)
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	top(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	fa(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, 16(%rbp)
	jmp	.L36
.L35:
	movl	16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %eax
	subl	24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	rev(%rip), %rax
	movl	(%rdx,%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	c1
	.bss
	.align 32
c1:
	.space 1600080
	.globl	c2
	.align 32
c2:
	.space 1600080
	.section	.text$_Z3addiii,"x"
	.linkonce discard
	.globl	_Z3addiii
	.def	_Z3addiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3addiii
_Z3addiii:
.LFB8755:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 24(%rbp)
	movl	%edx, 32(%rbp)
	movl	%r8d, 40(%rbp)
	movl	24(%rbp), %ebx
.L40:
	movl	n(%rip), %eax
	cmpl	%eax, %ebx
	jg	.L39
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c1(%rip), %rax
	movq	(%rdx,%rax), %rdx
	movl	40(%rbp), %eax
	cltq
	leaq	(%rdx,%rax), %rcx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c1(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c2(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	24(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rdx
	movl	40(%rbp), %eax
	cltq
	imulq	%rdx, %rax
	addq	%rax, %rcx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c2(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movl	%ebx, %eax
	negl	%eax
	andl	%ebx, %eax
	addl	%eax, %ebx
	jmp	.L40
.L39:
	movl	32(%rbp), %eax
	leal	1(%rax), %ebx
.L42:
	movl	n(%rip), %eax
	cmpl	%eax, %ebx
	jg	.L43
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c1(%rip), %rax
	movq	(%rdx,%rax), %rdx
	movl	40(%rbp), %eax
	cltq
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c1(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c2(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	32(%rbp), %eax
	movslq	%eax, %rdx
	movl	40(%rbp), %eax
	cltq
	imulq	%rdx, %rax
	subq	%rax, %rcx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	c2(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movl	%ebx, %eax
	negl	%eax
	andl	%ebx, %eax
	addl	%eax, %ebx
	jmp	.L42
.L43:
	nop
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5queryii,"x"
	.linkonce discard
	.globl	_Z5queryii
	.def	_Z5queryii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5queryii
_Z5queryii:
.LFB8756:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$24, %rsp
	.seh_stackalloc	24
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -80(%rbp)
	movl	%edx, -72(%rbp)
	movq	$0, -120(%rbp)
	movl	-72(%rbp), %ebx
.L46:
	testl	%ebx, %ebx
	je	.L45
	movl	-72(%rbp), %eax
	cltq
	movslq	%ebx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	c1(%rip), %rdx
	movq	(%rcx,%rdx), %rdx
	imulq	%rdx, %rax
	movslq	%ebx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	c2(%rip), %rdx
	movq	(%rcx,%rdx), %rdx
	subq	%rdx, %rax
	addq	%rax, -120(%rbp)
	leal	-1(%rbx), %eax
	andl	%eax, %ebx
	jmp	.L46
.L45:
	movl	-80(%rbp), %eax
	leal	-1(%rax), %ebx
.L48:
	testl	%ebx, %ebx
	je	.L47
	movl	-80(%rbp), %eax
	subl	$1, %eax
	cltq
	movslq	%ebx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	c1(%rip), %rdx
	movq	(%rcx,%rdx), %rdx
	imulq	%rdx, %rax
	movslq	%ebx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	c2(%rip), %rdx
	movq	(%rcx,%rdx), %rdx
	subq	%rdx, %rax
	subq	%rax, -120(%rbp)
	leal	-1(%rbx), %eax
	andl	%eax, %ebx
	jmp	.L48
.L47:
	movq	-120(%rbp), %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d%d\0"
.LC1:
	.ascii "c.cpp\0"
.LC2:
	.ascii "fa[p]==x\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8757:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	m(%rip), %r8
	leaq	n(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	movl	n(%rip), %eax
	movl	%eax, %edx
	leaq	d(%rip), %rcx
	call	_ZN3dsu4initEi
	movl	$1, %ebx
.L53:
	movl	m(%rip), %eax
	cmpl	%eax, %ebx
	jg	.L51
	movslq	%ebx, %rax
	salq	$3, %rax
	leaq	4(%rax), %rdx
	leaq	to(%rip), %rax
	addq	%rax, %rdx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rcx
	leaq	to(%rip), %rax
	addq	%rcx, %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	4+to(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	to(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%ecx, %r8d
	movl	%eax, %edx
	leaq	d(%rip), %rcx
	call	_ZN3dsu5mergeEii
	testb	%al, %al
	je	.L52
	movslq	%ebx, %rax
	leaq	mst(%rip), %rdx
	movb	$1, (%rax,%rdx)
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	4+to(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rcx
	leaq	to(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	%eax, %ecx
	call	_Z7addedgeii
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	to(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rcx
	leaq	4+to(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	%eax, %ecx
	call	_Z7addedgeii
.L52:
	addl	$1, %ebx
	jmp	.L53
.L51:
	movl	$0, %edx
	movl	$1, %ecx
	call	_Z4dfs1ii
	movl	$1, %edx
	movl	$1, %ecx
	call	_Z4dfs2ii
	movl	$1, %ebx
.L63:
	movl	m(%rip), %eax
	cmpl	%eax, %ebx
	jg	.L54
	movslq	%ebx, %rax
	leaq	mst(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L55
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	to(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, -4(%rbp)
	movslq	%ebx, %rax
	leaq	0(,%rax,8), %rdx
	leaq	4+to(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	_Z3lcaii
	movl	%eax, %esi
	movl	-4(%rbp), %eax
	cmpl	%eax, %esi
	je	.L56
	movl	-8(%rbp), %eax
	cmpl	%eax, %esi
	jne	.L57
.L56:
	movl	-8(%rbp), %eax
	cmpl	%eax, %esi
	jne	.L58
	leaq	-8(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
.L58:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	dep(%rip), %rax
	movl	(%rdx,%rax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	leal	-1(%rax), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	call	_Z3kthii
	movl	%eax, %esi
	movslq	%esi, %rax
	leaq	0(,%rax,4), %rdx
	leaq	fa(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	-4(%rbp), %eax
	cmpl	%eax, %edx
	je	.L61
	movl	$94, %r8d
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	_assert
.L61:
	movslq	%esi, %rax
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movslq	%esi, %rax
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%ecx, %eax
	leal	-1(%rax), %edx
	movslq	%esi, %rax
	leaq	0(,%rax,4), %rcx
	leaq	seg(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	_Z3addiii
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%ecx, %eax
	leal	-1(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	seg(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	$-1, %r8d
	movl	%eax, %ecx
	call	_Z3addiii
	jmp	.L55
.L57:
	movl	n(%rip), %eax
	movl	$1, %r8d
	movl	%eax, %edx
	movl	$1, %ecx
	call	_Z3addiii
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%ecx, %eax
	leal	-1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	seg(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	$-1, %r8d
	movl	%eax, %ecx
	call	_Z3addiii
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %ecx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	siz(%rip), %rax
	movl	(%rdx,%rax), %eax
	addl	%ecx, %eax
	leal	-1(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	seg(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	$-1, %r8d
	movl	%eax, %ecx
	call	_Z3addiii
.L55:
	addl	$1, %ebx
	jmp	.L63
.L54:
	movl	$1, %ebx
.L67:
	movl	n(%rip), %eax
	cmpl	%eax, %ebx
	jg	.L64
	movslq	%ebx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	seg(%rip), %rax
	movl	(%rdx,%rax), %edx
	movslq	%ebx, %rax
	leaq	0(,%rax,4), %rcx
	leaq	seg(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	%eax, %ecx
	call	_Z5queryii
	testq	%rax, %rax
	jne	.L65
	movl	$49, %eax
	jmp	.L66
.L65:
	movl	$48, %eax
.L66:
	movl	%eax, %ecx
	call	putchar
	addl	$1, %ebx
	jmp	.L67
.L64:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.def	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_:
.LFB9317:
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
	.section	.text$_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_,"x"
	.linkonce discard
	.globl	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	.def	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_:
.LFB9316:
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
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB10128:
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
.LFB10127:
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
	jne	.L75
	cmpl	$65535, 24(%rbp)
	jne	.L75
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L75:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_d;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_d
_GLOBAL__sub_I_d:
.LFB10151:
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
	.quad	_GLOBAL__sub_I_d
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	_assert;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");
