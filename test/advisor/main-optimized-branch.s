	.text
	.file	"module"
	.globl	myStrcmp                        # -- Begin function myStrcmp
	.p2align	4, 0x90
	.type	myStrcmp,@function
myStrcmp:                               # @myStrcmp
	.cfi_startproc
# %bb.0:                                # %myStrcmp
	movl	%esi, -4(%rsp)
	movl	%ecx, -8(%rsp)
	movl	$1, -12(%rsp)
	movl	$0, -16(%rsp)
	movl	$0, -20(%rsp)
	testl	%ecx, %ecx
	jle	.LBB0_13
# %bb.1:                                # %forloop.preheader
	xorl	%eax, %eax
	.p2align	4, 0x90
.LBB0_2:                                # %forloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
	movl	$1, -12(%rsp)
	movl	$0, -20(%rsp)
	testb	%al, %al
	je	.LBB0_3
.LBB0_7:                                # %forcont5
                                        #   in Loop: Header=BB0_2 Depth=1
	cmpl	$0, -12(%rsp)
	jg	.LBB0_8
# %bb.12:                               # %else53
                                        #   in Loop: Header=BB0_2 Depth=1
	incl	-16(%rsp)
	movl	-16(%rsp), %ecx
	cmpl	-8(%rsp), %ecx
	jl	.LBB0_2
	jmp	.LBB0_13
	.p2align	4, 0x90
.LBB0_5:                                # %then
                                        #   in Loop: Header=BB0_3 Depth=2
	movl	$0, -12(%rsp)
.LBB0_6:                                # %merge
                                        #   in Loop: Header=BB0_3 Depth=2
	incl	-20(%rsp)
	cmpl	$5, -20(%rsp)
	jge	.LBB0_7
.LBB0_3:                                # %forloop7
                                        #   Parent Loop BB0_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	-20(%rsp), %rcx
	cmpb	$0, (%rdi,%rcx)
	jne	.LBB0_9
# %bb.4:                                # %forloop7
                                        #   in Loop: Header=BB0_3 Depth=2
	movslq	-16(%rsp), %rsi
	imulq	$100, %rsi, %rsi
	addq	%rdx, %rsi
	cmpb	$0, (%rcx,%rsi)
	jne	.LBB0_5
.LBB0_9:                                # %else
                                        #   in Loop: Header=BB0_3 Depth=2
	movslq	-20(%rsp), %rcx
	cmpb	$0, (%rdi,%rcx)
	je	.LBB0_11
# %bb.10:                               # %else
                                        #   in Loop: Header=BB0_3 Depth=2
	movslq	-16(%rsp), %rsi
	imulq	$100, %rsi, %rsi
	addq	%rdx, %rsi
	cmpb	$0, (%rcx,%rsi)
	je	.LBB0_5
.LBB0_11:                               # %else22
                                        #   in Loop: Header=BB0_3 Depth=2
	movslq	-16(%rsp), %rcx
	imulq	$100, %rcx, %rcx
	addq	%rdx, %rcx
	movslq	-20(%rsp), %rsi
	movzbl	(%rsi,%rcx), %ecx
	cmpb	(%rdi,%rsi), %cl
	jne	.LBB0_5
	jmp	.LBB0_6
.LBB0_13:                               # %forcont
	xorl	%eax, %eax
	retq
.LBB0_8:                                # %then52
	movl	$1, %eax
	retq
.Lfunc_end0:
	.size	myStrcmp, .Lfunc_end0-myStrcmp
	.cfi_endproc
                                        # -- End function
	.globl	boolExpression                  # -- Begin function boolExpression
	.p2align	4, 0x90
	.type	boolExpression,@function
boolExpression:                         # @boolExpression
	.cfi_startproc
# %bb.0:                                # %boolExpression
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	subq	$40, %rsp
	.cfi_def_cfa_offset 80
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %rbx
	movl	%edx, 36(%rsp)
	movl	%ecx, 24(%rsp)
	movl	%r9d, 32(%rsp)
	movslq	%r9d, %rax
	movl	(%r8,%rax,4), %esi
	movl	%esi, 8(%rsp)
	movl	$0, 28(%rsp)
	incl	%eax
	movl	%eax, 16(%rsp)
	movl	$1, 20(%rsp)
	movl	%edx, 12(%rsp)
	cmpl	%ecx, %edx
	jge	.LBB1_16
# %bb.1:                                # %boolExpression
	movl	$1, %eax
	testl	%eax, %eax
	je	.LBB1_16
# %bb.2:                                # %forloop.preheader
	movq	%r8, %r14
	movq	%rdi, %r15
	.p2align	4, 0x90
.LBB1_3:                                # %forloop
                                        # =>This Inner Loop Header: Depth=1
	movslq	12(%rsp), %rax
	cmpb	$44, (%rbx,%rax)
	jne	.LBB1_7
# %bb.4:                                # %then
                                        #   in Loop: Header=BB1_3 Depth=1
	cmpl	$1, 8(%rsp)
	jne	.LBB1_12
# %bb.5:                                # %then
                                        #   in Loop: Header=BB1_3 Depth=1
	movslq	16(%rsp), %rax
	cmpl	$1, (%r14,%rax,4)
	jne	.LBB1_12
# %bb.6:                                # %then14
                                        #   in Loop: Header=BB1_3 Depth=1
	movl	$1, 8(%rsp)
	jmp	.LBB1_13
	.p2align	4, 0x90
.LBB1_7:                                # %else
                                        #   in Loop: Header=BB1_3 Depth=1
	movslq	12(%rsp), %rax
	cmpb	$59, (%rbx,%rax)
	jne	.LBB1_14
# %bb.8:                                # %then27
                                        #   in Loop: Header=BB1_3 Depth=1
	movl	8(%rsp), %ebp
	movl	12(%rsp), %edx
	incl	%edx
	movl	24(%rsp), %ecx
	movl	16(%rsp), %r9d
	movl	80(%rsp), %eax
	movl	%eax, (%rsp)
	movq	%r15, %rdi
	movq	%rbx, %rsi
	movq	%r14, %r8
	callq	boolExpression@PLT
	cmpl	$1, %ebp
	je	.LBB1_10
# %bb.9:                                # %then27
                                        #   in Loop: Header=BB1_3 Depth=1
	cmpl	$1, %eax
	jne	.LBB1_11
.LBB1_10:                               # %then34
                                        #   in Loop: Header=BB1_3 Depth=1
	movl	$1, 8(%rsp)
.LBB1_11:                               # %merge36
                                        #   in Loop: Header=BB1_3 Depth=1
	movl	$0, 20(%rsp)
	jmp	.LBB1_14
	.p2align	4, 0x90
.LBB1_12:                               # %else15
                                        #   in Loop: Header=BB1_3 Depth=1
	movl	$0, 8(%rsp)
.LBB1_13:                               # %merge
                                        #   in Loop: Header=BB1_3 Depth=1
	incl	16(%rsp)
.LBB1_14:                               # %merge
                                        #   in Loop: Header=BB1_3 Depth=1
	incl	12(%rsp)
	movl	12(%rsp), %eax
	cmpl	24(%rsp), %eax
	jge	.LBB1_16
# %bb.15:                               # %merge
                                        #   in Loop: Header=BB1_3 Depth=1
	cmpl	$1, 20(%rsp)
	je	.LBB1_3
.LBB1_16:                               # %forcont
	movl	8(%rsp), %eax
	addq	$40, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	boolExpression, .Lfunc_end1-boolExpression
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$22408, %rsp                    # imm = 0x5788
	.cfi_def_cfa_offset 22464
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movl	$100, 104(%rsp)
	movl	$100, 100(%rsp)
	movl	$5, 96(%rsp)
	movl	$0, 24(%rsp)
	movl	$0, 80(%rsp)
	movl	$1, 28(%rsp)
	movl	$0, 76(%rsp)
	movl	$0, 16(%rsp)
	movl	$0, 72(%rsp)
	movl	$0, 40(%rsp)
	movl	$0, 36(%rsp)
	movl	$0, 88(%rsp)
	movl	$0, 68(%rsp)
	movl	$0, 64(%rsp)
	movl	$0, 56(%rsp)
	movl	$0, 84(%rsp)
	movl	$0, 60(%rsp)
	movl	$0, 12(%rsp)
	movl	$0, 52(%rsp)
	movl	$0, 48(%rsp)
	movl	$0, 32(%rsp)
	movl	$0, 44(%rsp)
	movl	$0, 92(%rsp)
	movl	$0, 8(%rsp)
	movl	$0, 20(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_2
	.p2align	4, 0x90
.LBB2_1:                                # %forloop
                                        # =>This Inner Loop Header: Depth=1
	movslq	8(%rsp), %rax
	movl	$0, 1208(%rsp,%rax,4)
	movl	$0, 808(%rsp,%rax,4)
	movl	$0, 2008(%rsp,%rax,4)
	movl	$0, 1608(%rsp,%rax,4)
	movb	$0, 608(%rsp,%rax)
	incl	%eax
	movl	%eax, 8(%rsp)
	cmpl	$100, 8(%rsp)
	jl	.LBB2_1
.LBB2_2:                                # %forcont
	movl	$0, 8(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_7
# %bb.3:                                # %forloop23.preheader
	xorl	%eax, %eax
	jmp	.LBB2_4
	.p2align	4, 0x90
.LBB2_6:                                # %forcont27
                                        #   in Loop: Header=BB2_4 Depth=1
	incl	8(%rsp)
	cmpl	$100, 8(%rsp)
	jge	.LBB2_7
.LBB2_4:                                # %forloop23
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_5 Depth 2
	movl	$0, 12(%rsp)
	testb	%al, %al
	jne	.LBB2_6
	.p2align	4, 0x90
.LBB2_5:                                # %forloop29
                                        #   Parent Loop BB2_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	8(%rsp), %rcx
	imulq	$100, %rcx, %rcx
	leaq	2408(%rsp,%rcx), %rcx
	movslq	12(%rsp), %rdx
	movb	$0, (%rdx,%rcx)
	movslq	8(%rsp), %rcx
	imulq	$100, %rcx, %rcx
	leaq	12408(%rsp,%rcx), %rcx
	movslq	12(%rsp), %rdx
	movb	$0, (%rdx,%rcx)
	incl	12(%rsp)
	cmpl	$5, 12(%rsp)
	jl	.LBB2_5
	jmp	.LBB2_6
.LBB2_7:                                # %forcont21
	movl	$0, 8(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_12
# %bb.8:
	xorl	%eax, %eax
	movq	preCourse@GOTPCREL(%rip), %rcx
	jmp	.LBB2_9
	.p2align	4, 0x90
.LBB2_11:                               # %forcont57
                                        #   in Loop: Header=BB2_9 Depth=1
	incl	8(%rsp)
	cmpl	$100, 8(%rsp)
	jge	.LBB2_12
.LBB2_9:                                # %forloop53
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_10 Depth 2
	movl	$0, 12(%rsp)
	testb	%al, %al
	jne	.LBB2_11
	.p2align	4, 0x90
.LBB2_10:                               # %forloop59
                                        #   Parent Loop BB2_9 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	8(%rsp), %rdx
	imulq	$200, %rdx, %rdx
	addq	%rcx, %rdx
	movslq	12(%rsp), %rsi
	movb	$0, (%rsi,%rdx)
	incl	12(%rsp)
	cmpl	$200, 12(%rsp)
	jl	.LBB2_10
	jmp	.LBB2_11
.LBB2_12:                               # %forcont51
	movl	$0, 8(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_14
	.p2align	4, 0x90
.LBB2_13:                               # %forloop78
                                        # =>This Inner Loop Header: Depth=1
	movslq	8(%rsp), %rax
	movb	$0, 108(%rsp,%rax)
	incl	%eax
	movl	%eax, 8(%rsp)
	cmpl	$300, 8(%rsp)                   # imm = 0x12C
	jl	.LBB2_13
.LBB2_14:                               # %forcont76
	cmpl	$0, 80(%rsp)
	je	.LBB2_15
.LBB2_20:                               # %whilecont
	movl	$0, 8(%rsp)
	cmpl	$0, 24(%rsp)
	jg	.LBB2_21
.LBB2_27:                               # %forcont267
	cmpl	$0, 36(%rsp)
	je	.LBB2_29
# %bb.28:                               # %then365
	movss	40(%rsp), %xmm0                 # xmm0 = mem[0],zero,zero,zero
	cvtsi2ssl	36(%rsp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, 40(%rsp)
.LBB2_29:                               # %merge367
	movss	40(%rsp), %xmm0                 # xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	leaq	.L_Const_String_.2(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	movl	36(%rsp), %esi
	leaq	.L_Const_String_.3(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	88(%rsp), %esi
	leaq	.L_Const_String_.4(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	68(%rsp), %esi
	leaq	.L_Const_String_.5(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	leaq	.L_Const_String_.6(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	cmpl	$0, 68(%rsp)
	je	.LBB2_30
# %bb.60:                               # %else382
	movl	$0, 8(%rsp)
	cmpl	$0, 56(%rsp)
	jle	.LBB2_68
# %bb.61:                               # %forloop390.preheader
	movq	preCourse@GOTPCREL(%rip), %rbp
	xorl	%r14d, %r14d
	leaq	.L_Const_String_.9(%rip), %rbx
	leaq	708(%rsp), %r13
	leaq	12408(%rsp), %r12
	leaq	.L_Const_String_.12(%rip), %r15
	jmp	.LBB2_62
	.p2align	4, 0x90
.LBB2_23:                               # %then278
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	8(%rsp), %rax
	cmpl	$0, 808(%rsp,%rax,4)
	je	.LBB2_24
.LBB2_25:                               # %merge291
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	8(%rsp), %rax
	movl	1208(%rsp,%rax,4), %ecx
	addl	%ecx, 68(%rsp)
	movslq	56(%rsp), %rcx
	movl	%eax, 2008(%rsp,%rcx,4)
	incl	56(%rsp)
.LBB2_26:                               # %merge280
                                        #   in Loop: Header=BB2_21 Depth=1
	xorps	%xmm0, %xmm0
	cvtsi2ssl	84(%rsp), %xmm0
	mulss	60(%rsp), %xmm0
	addss	40(%rsp), %xmm0
	movss	%xmm0, 40(%rsp)
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	24(%rsp), %eax
	jge	.LBB2_27
.LBB2_21:                               # %forloop269
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_58 Depth 2
	movslq	8(%rsp), %rax
	movl	1208(%rsp,%rax,4), %ecx
	movl	%ecx, 84(%rsp)
	movl	$0, 60(%rsp)
	movl	808(%rsp,%rax,4), %eax
	cmpl	$-1, %eax
	je	.LBB2_23
# %bb.22:                               # %forloop269
                                        #   in Loop: Header=BB2_21 Depth=1
	testl	%eax, %eax
	je	.LBB2_23
# %bb.57:                               # %else279
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	8(%rsp), %rax
	xorps	%xmm0, %xmm0
	cvtsi2ssl	808(%rsp,%rax,4), %xmm0
	movss	%xmm0, 60(%rsp)
	movl	1208(%rsp,%rax,4), %ecx
	addl	%ecx, 36(%rsp)
	addl	%ecx, 88(%rsp)
	movl	$0, 12(%rsp)
	imulq	$100, %rax, %rax
	cmpb	$0, 2408(%rsp,%rax)
	je	.LBB2_59
	.p2align	4, 0x90
.LBB2_58:                               # %forloop329
                                        #   Parent Loop BB2_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	64(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	12408(%rsp,%rax), %rax
	movslq	12(%rsp), %rcx
	movslq	8(%rsp), %rdx
	imulq	$100, %rdx, %rdx
	leaq	2408(%rsp,%rdx), %rdx
	movzbl	(%rcx,%rdx), %edx
	movb	%dl, (%rcx,%rax)
	incl	12(%rsp)
	movslq	8(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	12(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_58
.LBB2_59:                               # %forcont327
                                        #   in Loop: Header=BB2_21 Depth=1
	incl	64(%rsp)
	jmp	.LBB2_26
.LBB2_24:                               # %then289
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	8(%rsp), %rax
	movl	1208(%rsp,%rax,4), %eax
	addl	%eax, 36(%rsp)
	jmp	.LBB2_25
	.p2align	4, 0x90
.LBB2_88:                               # %forcont581
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.13(%rip), %rdi
.LBB2_66:                               # %merge400
                                        #   in Loop: Header=BB2_62 Depth=1
	movl	$10, %esi
	xorl	%eax, %eax
	callq	printf@PLT
.LBB2_67:                               # %merge400
                                        #   in Loop: Header=BB2_62 Depth=1
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	56(%rsp), %eax
	leaq	.L_Const_String_.9(%rip), %rbx
	jge	.LBB2_68
.LBB2_62:                               # %forloop390
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_70 Depth 2
                                        #     Child Loop BB2_72 Depth 2
                                        #       Child Loop BB2_73 Depth 3
                                        #       Child Loop BB2_76 Depth 3
                                        #     Child Loop BB2_87 Depth 2
                                        #     Child Loop BB2_64 Depth 2
	movslq	8(%rsp), %rax
	movslq	2008(%rsp,%rax,4), %rax
	movl	%eax, 12(%rsp)
	imulq	$200, %rax, %rax
	cmpb	$0, (%rbp,%rax)
	je	.LBB2_63
# %bb.69:                               # %else399
                                        #   in Loop: Header=BB2_62 Depth=1
	movl	$0, 52(%rsp)
	testb	%r14b, %r14b
	jne	.LBB2_71
	.p2align	4, 0x90
.LBB2_70:                               # %forloop435
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	52(%rsp), %rax
	movl	$0, 1608(%rsp,%rax,4)
	movb	$0, 608(%rsp,%rax)
	incl	%eax
	movl	%eax, 52(%rsp)
	cmpl	$100, 52(%rsp)
	jl	.LBB2_70
.LBB2_71:                               # %forcont433
                                        #   in Loop: Header=BB2_62 Depth=1
	movl	$0, 32(%rsp)
	movl	$0, 44(%rsp)
	movl	$0, 20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$200, %rax, %rax
	cmpb	$0, (%rbp,%rax)
	jne	.LBB2_72
.LBB2_85:                               # %forcont451
                                        #   in Loop: Header=BB2_62 Depth=1
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rdi
	movl	44(%rsp), %ecx
	movl	32(%rsp), %eax
	movl	%eax, (%rsp)
	leaq	608(%rsp), %rsi
	xorl	%edx, %edx
	leaq	1608(%rsp), %r8
	xorl	%r9d, %r9d
	callq	boolExpression@PLT
	movl	%eax, 92(%rsp)
	testl	%eax, %eax
	jle	.LBB2_67
# %bb.86:                               # %then574
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.11(%rip), %rdi
	movl	$32, %esi
	movl	$32, %edx
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$0, 20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	cmpb	$0, 2408(%rsp,%rax)
	je	.LBB2_88
	.p2align	4, 0x90
.LBB2_87:                               # %forloop583
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	movzbl	(%rcx,%rax), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_87
	jmp	.LBB2_88
	.p2align	4, 0x90
.LBB2_83:                               # %else547
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	32(%rsp), %rax
	movl	$0, 1608(%rsp,%rax,4)
.LBB2_84:                               # %merge548
                                        #   in Loop: Header=BB2_72 Depth=2
	incl	32(%rsp)
	incl	20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%rbp, %rax
	movslq	20(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	je	.LBB2_85
.LBB2_72:                               # %forloop453
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB2_73 Depth 3
                                        #       Child Loop BB2_76 Depth 3
	movl	$0, 48(%rsp)
	testb	%r14b, %r14b
	jne	.LBB2_74
	.p2align	4, 0x90
.LBB2_73:                               # %forloop463
                                        #   Parent Loop BB2_62 Depth=1
                                        #     Parent Loop BB2_72 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movslq	48(%rsp), %rax
	movb	$0, 708(%rsp,%rax)
	incl	%eax
	movl	%eax, 48(%rsp)
	cmpl	$5, 48(%rsp)
	jl	.LBB2_73
.LBB2_74:                               # %forcont461
                                        #   in Loop: Header=BB2_72 Depth=2
	movl	$0, 28(%rsp)
	movslq	12(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%rbp, %rax
	movslq	20(%rsp), %rcx
	movb	(%rcx,%rax), %al
	cmpb	$44, %al
	je	.LBB2_79
	.p2align	4, 0x90
.LBB2_76:                               # %forcont461
                                        #   Parent Loop BB2_62 Depth=1
                                        #     Parent Loop BB2_72 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	cmpb	$59, %al
	je	.LBB2_79
# %bb.77:                               # %forcont461
                                        #   in Loop: Header=BB2_76 Depth=3
	testb	%al, %al
	je	.LBB2_79
# %bb.78:                               # %whileloop474
                                        #   in Loop: Header=BB2_76 Depth=3
	movslq	28(%rsp), %rax
	movslq	20(%rsp), %rcx
	movslq	12(%rsp), %rdx
	imulq	$200, %rdx, %rdx
	addq	%rbp, %rdx
	movzbl	(%rcx,%rdx), %ebx
	movb	%bl, 708(%rsp,%rax)
	incl	%eax
	movl	%eax, 28(%rsp)
	leal	1(%rcx), %eax
	movl	%eax, 20(%rsp)
	movslq	20(%rsp), %rax
	movzbl	(%rax,%rdx), %eax
	cmpb	$44, %al
	jne	.LBB2_76
.LBB2_79:                               # %whilecont475
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	12(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%rbp, %rax
	movslq	20(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	je	.LBB2_81
# %bb.80:                               # %then527
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	44(%rsp), %rax
	movslq	12(%rsp), %rcx
	imulq	$200, %rcx, %rcx
	addq	%rbp, %rcx
	movslq	20(%rsp), %rdx
	movb	(%rdx,%rcx), %cl
	movb	%cl, 608(%rsp,%rax)
	incl	%eax
	movl	%eax, 44(%rsp)
.LBB2_81:                               # %merge529
                                        #   in Loop: Header=BB2_72 Depth=2
	movl	28(%rsp), %esi
	movl	64(%rsp), %ecx
	movq	%r13, %rdi
	movq	%r12, %rdx
	callq	myStrcmp@PLT
	testl	%eax, %eax
	jle	.LBB2_83
# %bb.82:                               # %then546
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	32(%rsp), %rax
	movl	$1, 1608(%rsp,%rax,4)
	jmp	.LBB2_84
	.p2align	4, 0x90
.LBB2_63:                               # %then398
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.8(%rip), %rdi
	movl	$32, %esi
	movl	$32, %edx
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$0, 20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	cmpb	$0, 2408(%rsp,%rax)
	je	.LBB2_65
	.p2align	4, 0x90
.LBB2_64:                               # %forloop410
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	movzbl	(%rcx,%rax), %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	20(%rsp)
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_64
.LBB2_65:                               # %forcont408
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.10(%rip), %rdi
	jmp	.LBB2_66
.LBB2_15:                               # %whileloop.preheader
	xorl	%r12d, %r12d
	leaq	.L_Const_String_(%rip), %r14
	leaq	108(%rsp), %r15
	leaq	.L_Const_String_.1(%rip), %rbx
	movq	preCourse@GOTPCREL(%rip), %rbp
	jmp	.LBB2_16
	.p2align	4, 0x90
.LBB2_19:                               # %then
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$1, 80(%rsp)
.LBB2_48:                               # %merge
                                        #   in Loop: Header=BB2_16 Depth=1
	cmpl	$0, 80(%rsp)
	jne	.LBB2_20
.LBB2_16:                               # %whileloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_17 Depth 2
                                        #     Child Loop BB2_43 Depth 2
                                        #     Child Loop BB2_33 Depth 2
                                        #     Child Loop BB2_36 Depth 2
                                        #     Child Loop BB2_39 Depth 2
	movl	$0, 8(%rsp)
	testb	%r12b, %r12b
	jne	.LBB2_18
	.p2align	4, 0x90
.LBB2_17:                               # %forloop93
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	8(%rsp), %rax
	movb	$0, 108(%rsp,%rax)
	incl	%eax
	movl	%eax, 8(%rsp)
	cmpl	$300, 8(%rsp)                   # imm = 0x12C
	jl	.LBB2_17
.LBB2_18:                               # %forcont91
                                        #   in Loop: Header=BB2_16 Depth=1
	movq	%r14, %rdi
	movq	%r15, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	cmpb	$10, 108(%rsp)
	je	.LBB2_19
# %bb.31:                               # %else
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$1, 28(%rsp)
	movl	$0, 76(%rsp)
	testb	%r12b, %r12b
	je	.LBB2_43
.LBB2_32:                               # %whilecont111
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$0, 16(%rsp)
	cmpb	$124, 108(%rsp)
	je	.LBB2_34
	.p2align	4, 0x90
.LBB2_33:                               # %whileloop134
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	24(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2408(%rsp,%rax), %rax
	movslq	16(%rsp), %rcx
	movzbl	108(%rsp,%rcx), %edx
	movb	%dl, (%rcx,%rax)
	incl	16(%rsp)
	movslq	16(%rsp), %rax
	cmpb	$124, 108(%rsp,%rax)
	jne	.LBB2_33
.LBB2_34:                               # %whilecont135
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	16(%rsp)
	.p2align	4, 0x90
.LBB2_36:                               # %whileloop156
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	16(%rsp), %rax
	cmpb	$124, 108(%rsp,%rax)
	je	.LBB2_37
# %bb.35:                               # %whileloop156
                                        #   in Loop: Header=BB2_36 Depth=2
	movslq	24(%rsp), %rax
	movslq	16(%rsp), %rcx
	movzbl	108(%rsp,%rcx), %edx
	addl	$-48, %edx
	movl	%edx, 1208(%rsp,%rax,4)
	leal	1(%rcx), %eax
	movl	%eax, 16(%rsp)
	jmp	.LBB2_36
	.p2align	4, 0x90
.LBB2_45:                               # %merge121
                                        #   in Loop: Header=BB2_43 Depth=2
	cmpl	$0, 76(%rsp)
	jne	.LBB2_32
.LBB2_43:                               # %whileloop110
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	28(%rsp), %rax
	leaq	108(%rsp,%rax), %rsi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	scanf@PLT
	incl	28(%rsp)
	movl	28(%rsp), %eax
	decl	%eax
	cltq
	cmpb	$10, 108(%rsp,%rax)
	jne	.LBB2_45
# %bb.44:                               # %then119
                                        #   in Loop: Header=BB2_43 Depth=2
	movl	28(%rsp), %eax
	decl	%eax
	cltq
	movb	$0, 108(%rsp,%rax)
	movl	$1, 76(%rsp)
	jmp	.LBB2_45
	.p2align	4, 0x90
.LBB2_37:                               # %whilecont157
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	16(%rsp)
	movl	$0, 72(%rsp)
	.p2align	4, 0x90
.LBB2_39:                               # %whileloop178
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	16(%rsp), %rax
	cmpb	$124, 108(%rsp,%rax)
	je	.LBB2_40
# %bb.38:                               # %whileloop178
                                        #   in Loop: Header=BB2_39 Depth=2
	movslq	24(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%rbp, %rax
	movslq	72(%rsp), %rcx
	movslq	16(%rsp), %rdx
	movzbl	108(%rsp,%rdx), %edx
	movb	%dl, (%rcx,%rax)
	incl	16(%rsp)
	incl	72(%rsp)
	jmp	.LBB2_39
	.p2align	4, 0x90
.LBB2_40:                               # %whilecont179
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	16(%rsp)
	movslq	16(%rsp), %rax
	cmpb	$0, 108(%rsp,%rax)
	je	.LBB2_46
# %bb.41:                               # %then202
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	16(%rsp), %rax
	cmpb	$65, 108(%rsp,%rax)
	jne	.LBB2_49
# %bb.42:                               # %then209
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$4, 808(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_46:                               # %else203
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$-1, 808(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_49:                               # %else210
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	16(%rsp), %rax
	cmpb	$66, 108(%rsp,%rax)
	jne	.LBB2_51
# %bb.50:                               # %then219
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$3, 808(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_51:                               # %else220
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	16(%rsp), %rax
	cmpb	$67, 108(%rsp,%rax)
	jne	.LBB2_53
# %bb.52:                               # %then229
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$2, 808(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_53:                               # %else230
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	16(%rsp), %rax
	cmpb	$68, 108(%rsp,%rax)
	jne	.LBB2_55
# %bb.54:                               # %then239
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$1, 808(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_55:                               # %else240
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	16(%rsp), %rax
	cmpb	$70, 108(%rsp,%rax)
	jne	.LBB2_47
# %bb.56:                               # %then249
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	movl	$0, 808(%rsp,%rax,4)
	.p2align	4, 0x90
.LBB2_47:                               # %merge204
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	24(%rsp)
	jmp	.LBB2_48
.LBB2_30:                               # %then381
	leaq	.L_Const_String_.7(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
.LBB2_68:                               # %forcont388
	xorl	%eax, %eax
	addq	$22408, %rsp                    # imm = 0x5788
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.type	preCourse,@object               # @preCourse
	.bss
	.globl	preCourse
	.p2align	4
preCourse:
	.zero	20000
	.size	preCourse, 20000

	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%c"
	.size	.L_Const_String_, 3

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%c"
	.size	.L_Const_String_.1, 3

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"GPA: %0.1f\n"
	.size	.L_Const_String_.2, 12

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
	.p2align	4
.L_Const_String_.3:
	.asciz	"Hours Attempted: %d\n"
	.size	.L_Const_String_.3, 21

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"Hours Completed: %d\n"
	.size	.L_Const_String_.4, 21

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
	.p2align	4
.L_Const_String_.5:
	.asciz	"Credits Remaining: %d\n\n"
	.size	.L_Const_String_.5, 24

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
	.p2align	4
.L_Const_String_.6:
	.asciz	"Possible Courses to Take Next\n"
	.size	.L_Const_String_.6, 31

	.type	.L_Const_String_.7,@object      # @_Const_String_.7
	.p2align	4
.L_Const_String_.7:
	.asciz	"  None - Congratulations!\n"
	.size	.L_Const_String_.7, 27

	.type	.L_Const_String_.8,@object      # @_Const_String_.8
.L_Const_String_.8:
	.asciz	"%c%c"
	.size	.L_Const_String_.8, 5

	.type	.L_Const_String_.9,@object      # @_Const_String_.9
.L_Const_String_.9:
	.asciz	"%c"
	.size	.L_Const_String_.9, 3

	.type	.L_Const_String_.10,@object     # @_Const_String_.10
.L_Const_String_.10:
	.asciz	"%c"
	.size	.L_Const_String_.10, 3

	.type	.L_Const_String_.11,@object     # @_Const_String_.11
.L_Const_String_.11:
	.asciz	"%c%c"
	.size	.L_Const_String_.11, 5

	.type	.L_Const_String_.12,@object     # @_Const_String_.12
.L_Const_String_.12:
	.asciz	"%c"
	.size	.L_Const_String_.12, 3

	.type	.L_Const_String_.13,@object     # @_Const_String_.13
.L_Const_String_.13:
	.asciz	"%c"
	.size	.L_Const_String_.13, 3

	.section	".note.GNU-stack","",@progbits
