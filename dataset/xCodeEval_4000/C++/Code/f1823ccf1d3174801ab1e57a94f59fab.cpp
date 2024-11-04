__asm(R"(
	.file	"A Simple Task.cpp"
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z6printfPKcz
	.def	__Z6printfPKcz;	.scl	2;	.type	32;	.endef
__Z6printfPKcz:
	pushl	%ebx
	subl	$24, %esp
	movl	$1, (%esp)
	leal	36(%esp), %ebx
	call	*__imp____acrt_iob_func
	movl	32(%esp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	___mingw_vfprintf
	addl	$24, %esp
	popl	%ebx
	ret
	.text
	.p2align 4,,15
	.globl	__ZN2IO1RERi
	.def	__ZN2IO1RERi;	.scl	2;	.type	32;	.endef
__ZN2IO1RERi:
	pushl	%esi
	pushl	%ebx
	subl	$4, %esp
	movl	16(%esp), %ebx
	call	_getchar
	leal	-48(%eax), %edx
	movl	$0, (%ebx)
	cmpl	$45, %eax
	je	L6
	cmpl	$9, %edx
	ja	L10
	jmp	L6
	.p2align 4,,10
L27:
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L6
	cmpl	$45, %eax
	je	L6
L10:
	cmpl	$-1, %eax
	jne	L27
L5:
	addl	$4, %esp
	popl	%ebx
	popl	%esi
	ret
	.p2align 4,,10
L6:
	cmpl	$-1, %eax
	je	L5
	movl	$1, %esi
	cmpl	$45, %eax
	jne	L26
	jmp	L28
	.p2align 4,,10
L13:
	movl	(%ebx), %edx
	leal	(%edx,%edx,4), %edx
	leal	-48(%eax,%edx,2), %eax
	movl	%eax, (%ebx)
	call	_getchar
	leal	-48(%eax), %edx
L26:
	cmpl	$9, %edx
	jbe	L13
	imull	(%ebx), %esi
	movl	%esi, (%ebx)
	addl	$4, %esp
	popl	%ebx
	popl	%esi
	ret
	.p2align 4,,10
L28:
	call	_getchar
	movl	$-1, %esi
	leal	-48(%eax), %edx
	jmp	L26
	.p2align 4,,15
	.globl	__ZN2IO1RERx
	.def	__ZN2IO1RERx;	.scl	2;	.type	32;	.endef
__ZN2IO1RERx:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	48(%esp), %esi
	call	_getchar
	movl	%eax, %ecx
	movl	$0, (%esi)
	subl	$48, %eax
	movl	$0, 4(%esi)
	cmpl	$45, %ecx
	je	L30
	cmpl	$9, %eax
	jbe	L30
	cmpl	$-1, %ecx
	je	L29
	.p2align 4,,10
L31:
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L50
	cmpl	$45, %eax
	je	L50
	cmpl	$-1, %eax
	jne	L31
L29:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L50:
	movl	%eax, %ecx
	movl	%edx, %eax
L30:
	cmpl	$-1, %ecx
	je	L29
	movl	$1, %edi
	xorl	%ebp, %ebp
	cmpl	$45, %ecx
	je	L53
L36:
	cmpl	$9, %eax
	ja	L38
	movl	%edi, 8(%esp)
	movl	%ebp, 12(%esp)
	.p2align 4,,10
L37:
	movl	$10, %eax
	mull	(%esi)
	imull	$10, 4(%esi), %ebx
	movl	%eax, %edi
	movl	%edx, %ebp
	movl	%ecx, %eax
	addl	%ebx, %ebp
	cltd
	addl	%edi, %eax
	adcl	%ebp, %edx
	addl	$-48, %eax
	adcl	$-1, %edx
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	call	_getchar
	movl	%eax, %ecx
	leal	-48(%eax), %eax
	cmpl	$9, %eax
	jbe	L37
	movl	8(%esp), %edi
	movl	12(%esp), %ebp
L38:
	movl	4(%esi), %eax
	imull	(%esi), %ebp
	imull	%edi, %eax
	addl	%eax, %ebp
	movl	%edi, %eax
	mull	(%esi)
	addl	%ebp, %edx
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L53:
	call	_getchar
	movl	$-1, %edi
	movl	$-1, %ebp
	movl	%eax, %ecx
	leal	-48(%eax), %eax
	jmp	L36
	.p2align 4,,15
	.globl	__ZN2IO1WEv
	.def	__ZN2IO1WEv;	.scl	2;	.type	32;	.endef
__ZN2IO1WEv:
	ret
	.p2align 4,,15
	.globl	__ZN2IO1WERKi
	.def	__ZN2IO1WERKi;	.scl	2;	.type	32;	.endef
__ZN2IO1WERKi:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	112(%esp), %eax
	movl	(%eax), %ebx
	testl	%ebx, %ebx
	je	L63
	js	L64
L57:
	xorl	%ecx, %ecx
	leal	16(%esp), %edi
	movl	$-858993459, %ebp
	jmp	L58
	.p2align 4,,10
L60:
	movl	%esi, %ecx
L58:
	movl	%ebx, %eax
	leal	1(%ecx), %esi
	mull	%ebp
	shrl	$3, %edx
	leal	(%edx,%edx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	addl	$48, %ebx
	movb	%bl, 15(%esp,%esi)
	movl	%edx, %ebx
	testl	%edx, %edx
	jne	L60
	leal	(%edi,%ecx), %ebx
	jmp	L59
	.p2align 4,,10
L61:
	movl	%eax, %ebx
L59:
	movsbl	(%ebx), %eax
	movl	%eax, (%esp)
	call	_putchar
	leal	-1(%ebx), %eax
	cmpl	%ebx, %edi
	jne	L61
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L64:
	movl	$45, (%esp)
	negl	%ebx
	call	_putchar
	jmp	L57
	.p2align 4,,10
L63:
	movl	$48, 112(%esp)
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_putchar
	.def	___umoddi3;	.scl	2;	.type	32;	.endef
	.def	___moddi3;	.scl	2;	.type	32;	.endef
	.def	___udivdi3;	.scl	2;	.type	32;	.endef
	.def	___divdi3;	.scl	2;	.type	32;	.endef
	.p2align 4,,15
	.globl	__ZN2IO1WERKx
	.def	__ZN2IO1WERKx;	.scl	2;	.type	32;	.endef
__ZN2IO1WERKx:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	128(%esp), %eax
	movl	4(%eax), %edi
	movl	(%eax), %esi
	movl	%edi, %eax
	orl	%esi, %eax
	je	L73
	testl	%edi, %edi
	js	L74
L67:
	xorl	%ebx, %ebx
	jmp	L68
	.p2align 4,,10
L70:
	movl	%ebp, %ebx
L68:
	movl	%esi, (%esp)
	leal	31(%esp), %eax
	leal	1(%ebx), %ebp
	movl	%edi, 4(%esp)
	leal	(%eax,%ebp), %ecx
	movl	$10, 8(%esp)
	movl	$0, 12(%esp)
	movl	%ecx, 28(%esp)
	call	___moddi3
	movl	28(%esp), %ecx
	addl	$48, %eax
	movb	%al, (%ecx)
	movl	%esi, (%esp)
	movl	%edi, 4(%esp)
	movl	$10, 8(%esp)
	movl	$0, 12(%esp)
	call	___divdi3
	movl	%eax, %esi
	movl	%edx, %eax
	movl	%edx, %edi
	orl	%esi, %eax
	jne	L70
	leal	32(%esp), %eax
	addl	%eax, %ebx
	jmp	L69
	.p2align 4,,10
L71:
	movl	%eax, %ebx
L69:
	movsbl	(%ebx), %eax
	movl	%eax, (%esp)
	call	_putchar
	leal	32(%esp), %edx
	leal	-1(%ebx), %eax
	cmpl	%ebx, %edx
	jne	L71
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L74:
	movl	$45, (%esp)
	call	_putchar
	negl	%esi
	adcl	$0, %edi
	negl	%edi
	jmp	L67
	.p2align 4,,10
L73:
	movl	$48, 128(%esp)
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_putchar
	.section .rdata,"dr"
LC0:
	.ascii "%lf\0"
	.text
	.p2align 4,,15
	.globl	__ZN2IO1WERKd
	.def	__ZN2IO1WERKd;	.scl	2;	.type	32;	.endef
__ZN2IO1WERKd:
	subl	$28, %esp
	movl	32(%esp), %eax
	movsd	(%eax), %xmm0
	movl	$LC0, (%esp)
	movsd	%xmm0, 4(%esp)
	call	__Z6printfPKcz
	addl	$28, %esp
	ret
	.p2align 4,,15
	.globl	__ZN2IO1WERKc
	.def	__ZN2IO1WERKc;	.scl	2;	.type	32;	.endef
__ZN2IO1WERKc:
	movl	4(%esp), %eax
	movsbl	(%eax), %eax
	movl	%eax, 4(%esp)
	jmp	_putchar
	.section .rdata,"dr"
LC1:
	.ascii "%s\0"
	.text
	.p2align 4,,15
	.globl	__ZN2IO1WERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__ZN2IO1WERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__ZN2IO1WERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
	subl	$28, %esp
	movl	32(%esp), %eax
	movl	(%eax), %eax
	movl	$LC1, (%esp)
	movl	%eax, 4(%esp)
	call	__Z6printfPKcz
	addl	$28, %esp
	ret
	.p2align 4,,15
	.globl	__Z9TimeBeginv
	.def	__Z9TimeBeginv;	.scl	2;	.type	32;	.endef
__Z9TimeBeginv:
	subl	$12, %esp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, __ZN9Alphagocc6tStartE
	movl	%edx, __ZN9Alphagocc6tStartE+4
	addl	$12, %esp
	ret
	.p2align 4,,15
	.globl	__Z7TimeEndv
	.def	__Z7TimeEndv;	.scl	2;	.type	32;	.endef
__Z7TimeEndv:
	subl	$12, %esp
	call	__ZNSt6chrono3_V212system_clock3nowEv
	subl	__ZN9Alphagocc6tStartE, %eax
	sbbl	__ZN9Alphagocc6tStartE+4, %edx
	addl	$12, %esp
	ret
	.section	.text$_ZN2IO4__RIIiEEvRT_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZN2IO4__RIIiEEvRT_
	.def	__ZN2IO4__RIIiEEvRT_;	.scl	2;	.type	32;	.endef
__ZN2IO4__RIIiEEvRT_:
	pushl	%esi
	pushl	%ebx
	subl	$4, %esp
	movl	16(%esp), %ebx
	call	_getchar
	leal	-48(%eax), %edx
	movl	$0, (%ebx)
	cmpl	$45, %eax
	je	L85
	cmpl	$9, %edx
	ja	L89
	jmp	L85
	.p2align 4,,10
L106:
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L85
	cmpl	$45, %eax
	je	L85
L89:
	cmpl	$-1, %eax
	jne	L106
L84:
	addl	$4, %esp
	popl	%ebx
	popl	%esi
	ret
	.p2align 4,,10
L85:
	cmpl	$-1, %eax
	je	L84
	movl	$1, %esi
	cmpl	$45, %eax
	jne	L105
	jmp	L107
	.p2align 4,,10
L92:
	movl	(%ebx), %edx
	leal	(%edx,%edx,4), %edx
	leal	-48(%eax,%edx,2), %eax
	movl	%eax, (%ebx)
	call	_getchar
	leal	-48(%eax), %edx
L105:
	cmpl	$9, %edx
	jbe	L92
	imull	(%ebx), %esi
	movl	%esi, (%ebx)
	addl	$4, %esp
	popl	%ebx
	popl	%esi
	ret
	.p2align 4,,10
L107:
	call	_getchar
	movl	$-1, %esi
	leal	-48(%eax), %edx
	jmp	L105
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$144, %esp
	call	___main
	leal	72(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN2IO4__RIIiEEvRT_
	leal	76(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN2IO4__RIIiEEvRT_
	movl	$_G, %edx
	movl	$900, %ecx
	xorl	%eax, %eax
	movl	%edx, %edi
	rep stosl
	movl	76(%esp), %edi
	testl	%edi, %edi
	jle	L130
	.p2align 4,,10
L113:
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L112
	cmpl	$45, %eax
	je	L112
	cmpl	$-1, %eax
	jne	L113
L153:
	call	_getchar
	movl	$-1, %ebx
	leal	-48(%eax), %edx
	cmpl	$45, %eax
	je	L121
L207:
	cmpl	$9, %edx
	ja	L200
	jmp	L121
	.p2align 4,,10
L122:
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L121
	cmpl	$45, %eax
	je	L121
L200:
	cmpl	$-1, %eax
	jne	L122
L155:
	movl	$-1, %edx
L123:
	imull	$30, %edx, %eax
	addl	$1, %esi
	addl	%ebx, %eax
	imull	$30, %ebx, %ebx
	movl	$1, _G(,%eax,4)
	addl	%ebx, %edx
	movl	$1, _G(,%edx,4)
	cmpl	%esi, 76(%esp)
	jg	L113
L130:
	movl	72(%esp), %edx
	testl	%edx, %edx
	jle	L110
	xorl	%ecx, %ecx
	movl	$1, %ebx
	.p2align 4,,10
L111:
	movl	%ebx, %eax
	sall	%cl, %eax
	imull	$30, %eax, %eax
	addl	%ecx, %eax
	addl	$1, %ecx
	movl	$1, _dp(,%eax,8)
	movl	$0, _dp+4(,%eax,8)
	cmpl	%ecx, %edx
	jne	L111
L110:
	movl	$1, %eax
	movl	%edx, %ecx
	movl	_ans, %ebx
	movl	_ans+4, %esi
	sall	%cl, %eax
	movl	%eax, 28(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 20(%esp)
	testl	%eax, %eax
	jle	L201
	imull	$120, %edx, %eax
	movl	$_dp, 32(%esp)
	xorl	%esi, %esi
	movl	%eax, 52(%esp)
	.p2align 4,,10
L143:
	testl	%edx, %edx
	jle	L133
	movl	%esi, %eax
	andl	$1, %eax
	movl	%eax, 44(%esp)
	jne	L156
	xorl	%eax, %eax
	jmp	L135
	.p2align 4,,10
L193:
	btl	%eax, %esi
	jc	L157
L135:
	addl	$1, %eax
	cmpl	%eax, %edx
	jne	L193
L134:
	xorl	%ecx, %ecx
	xorl	%ebx, %ebx
	.p2align 4,,10
L137:
	movl	%esi, %eax
	sarl	%cl, %eax
	addl	$1, %ecx
	andl	$1, %eax
	addl	%eax, %ebx
	cmpl	%ecx, %edx
	jne	L137
	movl	44(%esp), %eax
	movl	32(%esp), %edi
	movl	%ebx, 36(%esp)
	movl	%esi, 56(%esp)
	sall	$2, %eax
	movl	%eax, 40(%esp)
	xorl	%eax, %eax
	jmp	L142
	.p2align 4,,10
L138:
	addl	$8, %edi
	addl	$120, %eax
	cmpl	%eax, 52(%esp)
	je	L202
L142:
	movl	4(%edi), %ebx
	movl	(%edi), %ecx
	movl	%ebx, %esi
	orl	%ecx, %esi
	je	L138
	movl	40(%esp), %esi
	movl	_G(%esi,%eax), %esi
	testl	%esi, %esi
	je	L139
	cmpl	$2, 36(%esp)
	jle	L139
	addl	%ecx, 16(%esp)
	adcl	%ebx, 20(%esp)
L139:
	cmpl	$1, %edx
	je	L138
	movl	%eax, 48(%esp)
	movl	44(%esp), %eax
	movl	$1, %ecx
	movl	56(%esp), %esi
	movl	%edx, 60(%esp)
	movl	%eax, 56(%esp)
	.p2align 4,,10
L141:
	cmpl	%ecx, 56(%esp)
	jge	L140
	btl	%ecx, %esi
	jc	L140
	movl	48(%esp), %eax
	movl	_G(%eax,%ecx,4), %ebx
	testl	%ebx, %ebx
	je	L140
	movl	%esi, %ebx
	movl	(%edi), %eax
	movl	4(%edi), %edx
	btsl	%ecx, %ebx
	imull	$30, %ebx, %ebx
	addl	%ecx, %ebx
	addl	%eax, _dp(,%ebx,8)
	adcl	%edx, _dp+4(,%ebx,8)
	.p2align 4,,10
L140:
	addl	$1, %ecx
	cmpl	%ecx, 60(%esp)
	jne	L141
	movl	48(%esp), %eax
	movl	60(%esp), %edx
	movl	%esi, 56(%esp)
	addl	$8, %edi
	addl	$120, %eax
	cmpl	%eax, 52(%esp)
	jne	L142
L202:
	movl	56(%esp), %esi
L133:
	addl	$1, %esi
	addl	$240, 32(%esp)
	cmpl	28(%esp), %esi
	jne	L143
	movl	16(%esp), %eax
	movl	20(%esp), %edx
	movl	%eax, _ans
	movl	%edx, _ans+4
L131:
	movl	%edx, %esi
	xorl	%edi, %edi
	shrl	$31, %esi
	addl	%esi, %eax
	adcl	%edi, %edx
	shrdl	$1, %edx, %eax
	sarl	%edx
	movl	%eax, %esi
	movl	%edx, %eax
	movl	%edx, %edi
	orl	%esi, %eax
	je	L203
	movl	16(%esp), %eax
	movl	20(%esp), %edx
	cmpl	$-1, %eax
	movl	%edx, %eax
	sbbl	$-1, %eax
	jl	L204
L150:
	xorl	%ecx, %ecx
	jmp	L146
	.p2align 4,,10
L158:
	movl	%ebx, %ecx
L146:
	movl	%esi, (%esp)
	leal	1(%ecx), %ebx
	leal	79(%esp), %eax
	movl	%edi, 4(%esp)
	addl	%ebx, %eax
	movl	$10, 8(%esp)
	movl	$0, 12(%esp)
	movl	%ecx, 56(%esp)
	movl	%eax, 60(%esp)
	call	___moddi3
	movl	60(%esp), %edx
	addl	$48, %eax
	movb	%al, (%edx)
	movl	%esi, (%esp)
	movl	%edi, 4(%esp)
	movl	$10, 8(%esp)
	movl	$0, 12(%esp)
	call	___divdi3
	movl	56(%esp), %ecx
	movl	%eax, %esi
	movl	%edx, %eax
	movl	%edx, %edi
	orl	%esi, %eax
	jne	L158
	leal	80(%esp), %eax
	leal	(%eax,%ecx), %ebx
	jmp	L148
	.p2align 4,,10
L205:
	movl	%eax, %ebx
L148:
	movsbl	(%ebx), %eax
	leal	80(%esp), %edi
	movl	%eax, (%esp)
	call	_putchar
	leal	-1(%ebx), %eax
	cmpl	%edi, %ebx
	jne	L205
L147:
	movl	$10, (%esp)
	call	_putchar
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L112:
	cmpl	$-1, %eax
	je	L153
	movl	$1, %ebx
	cmpl	$45, %eax
	je	L206
L118:
	cmpl	$9, %edx
	ja	L153
	xorl	%edi, %edi
	.p2align 4,,10
L120:
	leal	(%edi,%edi,4), %edx
	leal	-48(%eax,%edx,2), %edi
	call	_getchar
	leal	-48(%eax), %edx
	cmpl	$9, %edx
	jbe	L120
	call	_getchar
	imull	%edi, %ebx
	leal	-48(%eax), %edx
	subl	$1, %ebx
	cmpl	$45, %eax
	jne	L207
	.p2align 4,,10
L121:
	cmpl	$-1, %eax
	je	L155
	movl	$1, 60(%esp)
	cmpl	$45, %eax
	je	L208
L127:
	cmpl	$9, %edx
	ja	L155
	xorl	%edi, %edi
	.p2align 4,,10
L129:
	leal	(%edi,%edi,4), %edx
	leal	-48(%eax,%edx,2), %edi
	call	_getchar
	leal	-48(%eax), %ecx
	cmpl	$9, %ecx
	jbe	L129
	imull	60(%esp), %edi
	leal	-1(%edi), %edx
	jmp	L123
	.p2align 4,,10
L157:
	movl	%eax, 44(%esp)
	jmp	L134
L208:
	call	_getchar
	movl	$-1, 60(%esp)
	leal	-48(%eax), %edx
	jmp	L127
L206:
	call	_getchar
	movl	$-1, %ebx
	leal	-48(%eax), %edx
	jmp	L118
L156:
	movl	$0, 44(%esp)
	jmp	L134
L203:
	movl	$48, (%esp)
	call	_putchar
	movl	16(%esp), %eax
	movl	20(%esp), %edx
	cmpl	$-1, %eax
	movl	%edx, %eax
	sbbl	$-1, %eax
	jge	L147
	movl	$45, (%esp)
	call	_putchar
	jmp	L147
L201:
	movl	%ebx, %eax
	movl	%esi, %edx
	jmp	L131
L204:
	movl	$45, (%esp)
	call	_putchar
	negl	%esi
	adcl	$0, %edi
	negl	%edi
	jmp	L150
	.p2align 4,,15
	.def	__GLOBAL__sub_I__ZN2IO1RERi;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN2IO1RERi:
	subl	$28, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN2IO1RERi
	.globl	_ans
	.bss
	.align 8
_ans:
	.space 8
	.globl	_dp
	.align 32
_dp:
	.space 251658240
	.globl	_G
	.align 32
_G:
	.space 3600
	.globl	__ZN9Alphagocc6tStartE
	.align 8
__ZN9Alphagocc6tStartE:
	.space 8
	.globl	__ZN2IO5spaceE
	.data
__ZN2IO5spaceE:
	.byte	32
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (GNU) 8.3.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	___mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef

)");