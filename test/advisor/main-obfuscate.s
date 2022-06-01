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
	subq	$22424, %rsp                    # imm = 0x5798
	.cfi_def_cfa_offset 22480
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movl	$100, 120(%rsp)
	movl	$100, 116(%rsp)
	movl	$5, 112(%rsp)
	movl	$0, 32(%rsp)
	movl	$0, 88(%rsp)
	movl	$1, 36(%rsp)
	movl	$0, 84(%rsp)
	movl	$0, 24(%rsp)
	movl	$0, 80(%rsp)
	movl	$0, 48(%rsp)
	movl	$0, 44(%rsp)
	movl	$0, 96(%rsp)
	movl	$0, 76(%rsp)
	movl	$0, 72(%rsp)
	movl	$0, 64(%rsp)
	movl	$0, 92(%rsp)
	movl	$0, 68(%rsp)
	movl	$0, 20(%rsp)
	movl	$0, 60(%rsp)
	movl	$0, 56(%rsp)
	movl	$0, 40(%rsp)
	movl	$0, 52(%rsp)
	movl	$0, 100(%rsp)
	movl	$0, 16(%rsp)
	movl	$0, 28(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_2
	.p2align	4, 0x90
.LBB2_1:                                # %forloop
                                        # =>This Inner Loop Header: Depth=1
	movslq	16(%rsp), %rax
	movl	$0, 1224(%rsp,%rax,4)
	movl	$0, 824(%rsp,%rax,4)
	movl	$0, 2024(%rsp,%rax,4)
	movl	$0, 1624(%rsp,%rax,4)
	movb	$0, 724(%rsp,%rax)
	incl	%eax
	movl	%eax, 16(%rsp)
	cmpl	$100, 16(%rsp)
	jl	.LBB2_1
.LBB2_2:                                # %forcont
	movl	$0, 16(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_7
# %bb.3:                                # %forloop23.preheader
	xorl	%eax, %eax
	jmp	.LBB2_4
	.p2align	4, 0x90
.LBB2_6:                                # %forcont27
                                        #   in Loop: Header=BB2_4 Depth=1
	incl	16(%rsp)
	cmpl	$100, 16(%rsp)
	jge	.LBB2_7
.LBB2_4:                                # %forloop23
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_5 Depth 2
	movl	$0, 20(%rsp)
	testb	%al, %al
	jne	.LBB2_6
	.p2align	4, 0x90
.LBB2_5:                                # %forloop29
                                        #   Parent Loop BB2_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	16(%rsp), %rcx
	imulq	$100, %rcx, %rcx
	leaq	2424(%rsp,%rcx), %rcx
	movslq	20(%rsp), %rdx
	movb	$0, (%rdx,%rcx)
	movslq	16(%rsp), %rcx
	imulq	$100, %rcx, %rcx
	leaq	12424(%rsp,%rcx), %rcx
	movslq	20(%rsp), %rdx
	movb	$0, (%rdx,%rcx)
	incl	20(%rsp)
	cmpl	$5, 20(%rsp)
	jl	.LBB2_5
	jmp	.LBB2_6
.LBB2_7:                                # %forcont21
	movl	$0, 16(%rsp)
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
	incl	16(%rsp)
	cmpl	$100, 16(%rsp)
	jge	.LBB2_12
.LBB2_9:                                # %forloop53
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_10 Depth 2
	movl	$0, 20(%rsp)
	testb	%al, %al
	jne	.LBB2_11
	.p2align	4, 0x90
.LBB2_10:                               # %forloop59
                                        #   Parent Loop BB2_9 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	16(%rsp), %rdx
	imulq	$200, %rdx, %rdx
	addq	%rcx, %rdx
	movslq	20(%rsp), %rsi
	movb	$0, (%rsi,%rdx)
	incl	20(%rsp)
	cmpl	$200, 20(%rsp)
	jl	.LBB2_10
	jmp	.LBB2_11
.LBB2_12:                               # %forcont51
	movl	$0, 16(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB2_14
	.p2align	4, 0x90
.LBB2_13:                               # %forloop78
                                        # =>This Inner Loop Header: Depth=1
	movslq	16(%rsp), %rax
	movb	$0, 224(%rsp,%rax)
	incl	%eax
	movl	%eax, 16(%rsp)
	cmpl	$300, 16(%rsp)                  # imm = 0x12C
	jl	.LBB2_13
.LBB2_14:                               # %forcont76
	cmpl	$0, 88(%rsp)
	je	.LBB2_15
.LBB2_20:                               # %whilecont
	movl	$0, 16(%rsp)
	cmpl	$0, 32(%rsp)
	jg	.LBB2_21
.LBB2_27:                               # %forcont267
	cmpl	$0, 44(%rsp)
	je	.LBB2_29
# %bb.28:                               # %then365
	movss	48(%rsp), %xmm0                 # xmm0 = mem[0],zero,zero,zero
	cvtsi2ssl	44(%rsp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, 48(%rsp)
.LBB2_29:                               # %merge367
	movss	48(%rsp), %xmm0                 # xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	movsd	%xmm0, 104(%rsp)                # 8-byte Spill
	leaq	.L_Const_String_.2(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movsd	104(%rsp), %xmm0                # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movb	$1, %al
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	movl	44(%rsp), %ebx
	leaq	.L_Const_String_.3(%rip), %rbp
	movq	%rbp, %rdi
	callq	__decrypt@PLT
	movq	%rbp, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbp, %rdi
	callq	__encrypt@PLT
	movl	96(%rsp), %ebx
	leaq	.L_Const_String_.4(%rip), %rbp
	movq	%rbp, %rdi
	callq	__decrypt@PLT
	movq	%rbp, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbp, %rdi
	callq	__encrypt@PLT
	movl	76(%rsp), %ebx
	leaq	.L_Const_String_.5(%rip), %rbp
	movq	%rbp, %rdi
	callq	__decrypt@PLT
	movq	%rbp, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbp, %rdi
	callq	__encrypt@PLT
	leaq	.L_Const_String_.6(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	cmpl	$0, 76(%rsp)
	je	.LBB2_30
# %bb.60:                               # %else382
	movl	$0, 16(%rsp)
	cmpl	$0, 64(%rsp)
	jle	.LBB2_68
# %bb.61:                               # %forloop390.preheader
	movq	preCourse@GOTPCREL(%rip), %r15
	xorl	%r12d, %r12d
	leaq	.L_Const_String_.9(%rip), %r13
	leaq	124(%rsp), %rbp
	leaq	.L_Const_String_.12(%rip), %r14
	jmp	.LBB2_62
	.p2align	4, 0x90
.LBB2_23:                               # %then278
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	16(%rsp), %rax
	cmpl	$0, 824(%rsp,%rax,4)
	je	.LBB2_24
.LBB2_25:                               # %merge291
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	16(%rsp), %rax
	movl	1224(%rsp,%rax,4), %ecx
	addl	%ecx, 76(%rsp)
	movslq	64(%rsp), %rcx
	movl	%eax, 2024(%rsp,%rcx,4)
	incl	64(%rsp)
.LBB2_26:                               # %merge280
                                        #   in Loop: Header=BB2_21 Depth=1
	xorps	%xmm0, %xmm0
	cvtsi2ssl	92(%rsp), %xmm0
	mulss	68(%rsp), %xmm0
	addss	48(%rsp), %xmm0
	movss	%xmm0, 48(%rsp)
	incl	16(%rsp)
	movl	16(%rsp), %eax
	cmpl	32(%rsp), %eax
	jge	.LBB2_27
.LBB2_21:                               # %forloop269
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_58 Depth 2
	movslq	16(%rsp), %rax
	movl	1224(%rsp,%rax,4), %ecx
	movl	%ecx, 92(%rsp)
	movl	$0, 68(%rsp)
	movl	824(%rsp,%rax,4), %eax
	cmpl	$-1, %eax
	je	.LBB2_23
# %bb.22:                               # %forloop269
                                        #   in Loop: Header=BB2_21 Depth=1
	testl	%eax, %eax
	je	.LBB2_23
# %bb.57:                               # %else279
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	16(%rsp), %rax
	xorps	%xmm0, %xmm0
	cvtsi2ssl	824(%rsp,%rax,4), %xmm0
	movss	%xmm0, 68(%rsp)
	movl	1224(%rsp,%rax,4), %ecx
	addl	%ecx, 44(%rsp)
	addl	%ecx, 96(%rsp)
	movl	$0, 20(%rsp)
	imulq	$100, %rax, %rax
	cmpb	$0, 2424(%rsp,%rax)
	je	.LBB2_59
	.p2align	4, 0x90
.LBB2_58:                               # %forloop329
                                        #   Parent Loop BB2_21 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	72(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	12424(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	movslq	16(%rsp), %rdx
	imulq	$100, %rdx, %rdx
	leaq	2424(%rsp,%rdx), %rdx
	movzbl	(%rcx,%rdx), %edx
	movb	%dl, (%rcx,%rax)
	incl	20(%rsp)
	movslq	16(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	20(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_58
.LBB2_59:                               # %forcont327
                                        #   in Loop: Header=BB2_21 Depth=1
	incl	72(%rsp)
	jmp	.LBB2_26
.LBB2_24:                               # %then289
                                        #   in Loop: Header=BB2_21 Depth=1
	movslq	16(%rsp), %rax
	movl	1224(%rsp,%rax,4), %eax
	addl	%eax, 44(%rsp)
	jmp	.LBB2_25
	.p2align	4, 0x90
.LBB2_88:                               # %forcont581
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.13(%rip), %rbx
.LBB2_66:                               # %merge400
                                        #   in Loop: Header=BB2_62 Depth=1
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movl	$10, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	leaq	124(%rsp), %rbp
.LBB2_67:                               # %merge400
                                        #   in Loop: Header=BB2_62 Depth=1
	incl	16(%rsp)
	movl	16(%rsp), %eax
	cmpl	64(%rsp), %eax
	jge	.LBB2_68
.LBB2_62:                               # %forloop390
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_70 Depth 2
                                        #     Child Loop BB2_72 Depth 2
                                        #       Child Loop BB2_73 Depth 3
                                        #       Child Loop BB2_76 Depth 3
                                        #     Child Loop BB2_87 Depth 2
                                        #     Child Loop BB2_64 Depth 2
	movslq	16(%rsp), %rax
	movslq	2024(%rsp,%rax,4), %rax
	movl	%eax, 20(%rsp)
	imulq	$200, %rax, %rax
	cmpb	$0, (%r15,%rax)
	je	.LBB2_63
# %bb.69:                               # %else399
                                        #   in Loop: Header=BB2_62 Depth=1
	movl	$0, 60(%rsp)
	testb	%r12b, %r12b
	jne	.LBB2_71
	.p2align	4, 0x90
.LBB2_70:                               # %forloop435
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	60(%rsp), %rax
	movl	$0, 1624(%rsp,%rax,4)
	movb	$0, 724(%rsp,%rax)
	incl	%eax
	movl	%eax, 60(%rsp)
	cmpl	$100, 60(%rsp)
	jl	.LBB2_70
.LBB2_71:                               # %forcont433
                                        #   in Loop: Header=BB2_62 Depth=1
	movl	$0, 40(%rsp)
	movl	$0, 52(%rsp)
	movl	$0, 28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$200, %rax, %rax
	cmpb	$0, (%r15,%rax)
	jne	.LBB2_72
.LBB2_85:                               # %forcont451
                                        #   in Loop: Header=BB2_62 Depth=1
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rdi
	movl	52(%rsp), %ecx
	movl	40(%rsp), %eax
	movl	%eax, (%rsp)
	leaq	724(%rsp), %rsi
	xorl	%edx, %edx
	leaq	1624(%rsp), %r8
	xorl	%r9d, %r9d
	callq	boolExpression@PLT
	movl	%eax, 100(%rsp)
	testl	%eax, %eax
	jle	.LBB2_67
# %bb.86:                               # %then574
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.11(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movl	$32, %esi
	movl	$32, %edx
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	movl	$0, 28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	cmpb	$0, 2424(%rsp,%rax)
	je	.LBB2_88
	.p2align	4, 0x90
.LBB2_87:                               # %forloop583
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	28(%rsp), %rcx
	movzbl	(%rcx,%rax), %ebp
	movq	%r14, %rdi
	callq	__decrypt@PLT
	movq	%r14, %rdi
	movl	%ebp, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%r14, %rdi
	callq	__encrypt@PLT
	incl	28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	28(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_87
	jmp	.LBB2_88
	.p2align	4, 0x90
.LBB2_83:                               # %else547
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	40(%rsp), %rax
	movl	$0, 1624(%rsp,%rax,4)
.LBB2_84:                               # %merge548
                                        #   in Loop: Header=BB2_72 Depth=2
	incl	40(%rsp)
	incl	28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%r15, %rax
	movslq	28(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	je	.LBB2_85
.LBB2_72:                               # %forloop453
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB2_73 Depth 3
                                        #       Child Loop BB2_76 Depth 3
	movl	$0, 56(%rsp)
	testb	%r12b, %r12b
	jne	.LBB2_74
	.p2align	4, 0x90
.LBB2_73:                               # %forloop463
                                        #   Parent Loop BB2_62 Depth=1
                                        #     Parent Loop BB2_72 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movslq	56(%rsp), %rax
	movb	$0, 124(%rsp,%rax)
	incl	%eax
	movl	%eax, 56(%rsp)
	cmpl	$5, 56(%rsp)
	jl	.LBB2_73
.LBB2_74:                               # %forcont461
                                        #   in Loop: Header=BB2_72 Depth=2
	movl	$0, 36(%rsp)
	movslq	20(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%r15, %rax
	movslq	28(%rsp), %rcx
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
	movslq	36(%rsp), %rax
	movslq	28(%rsp), %rcx
	movslq	20(%rsp), %rdx
	imulq	$200, %rdx, %rdx
	addq	%r15, %rdx
	movzbl	(%rcx,%rdx), %ebx
	movb	%bl, 124(%rsp,%rax)
	incl	%eax
	movl	%eax, 36(%rsp)
	leal	1(%rcx), %eax
	movl	%eax, 28(%rsp)
	movslq	28(%rsp), %rax
	movzbl	(%rax,%rdx), %eax
	cmpb	$44, %al
	jne	.LBB2_76
.LBB2_79:                               # %whilecont475
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	20(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%r15, %rax
	movslq	28(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	je	.LBB2_81
# %bb.80:                               # %then527
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	52(%rsp), %rax
	movslq	20(%rsp), %rcx
	imulq	$200, %rcx, %rcx
	addq	%r15, %rcx
	movslq	28(%rsp), %rdx
	movb	(%rdx,%rcx), %cl
	movb	%cl, 724(%rsp,%rax)
	incl	%eax
	movl	%eax, 52(%rsp)
.LBB2_81:                               # %merge529
                                        #   in Loop: Header=BB2_72 Depth=2
	movl	36(%rsp), %esi
	movl	72(%rsp), %ecx
	movq	%rbp, %rdi
	leaq	12424(%rsp), %rdx
	callq	myStrcmp@PLT
	testl	%eax, %eax
	jle	.LBB2_83
# %bb.82:                               # %then546
                                        #   in Loop: Header=BB2_72 Depth=2
	movslq	40(%rsp), %rax
	movl	$1, 1624(%rsp,%rax,4)
	jmp	.LBB2_84
	.p2align	4, 0x90
.LBB2_63:                               # %then398
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.8(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movl	$32, %esi
	movl	$32, %edx
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	movl	$0, 28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	cmpb	$0, 2424(%rsp,%rax)
	je	.LBB2_65
	.p2align	4, 0x90
.LBB2_64:                               # %forloop410
                                        #   Parent Loop BB2_62 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	28(%rsp), %rcx
	movzbl	(%rcx,%rax), %ebp
	movq	%r13, %rdi
	callq	__decrypt@PLT
	movq	%r13, %rdi
	movl	%ebp, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%r13, %rdi
	callq	__encrypt@PLT
	incl	28(%rsp)
	movslq	20(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	28(%rsp), %rcx
	cmpb	$0, (%rcx,%rax)
	jne	.LBB2_64
.LBB2_65:                               # %forcont408
                                        #   in Loop: Header=BB2_62 Depth=1
	leaq	.L_Const_String_.10(%rip), %rbx
	jmp	.LBB2_66
.LBB2_15:                               # %whileloop.preheader
	xorl	%r12d, %r12d
	leaq	.L_Const_String_(%rip), %r15
	leaq	224(%rsp), %r14
	leaq	.L_Const_String_.1(%rip), %rbp
	movq	preCourse@GOTPCREL(%rip), %r13
	jmp	.LBB2_16
	.p2align	4, 0x90
.LBB2_19:                               # %then
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$1, 88(%rsp)
.LBB2_48:                               # %merge
                                        #   in Loop: Header=BB2_16 Depth=1
	cmpl	$0, 88(%rsp)
	jne	.LBB2_20
.LBB2_16:                               # %whileloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_17 Depth 2
                                        #     Child Loop BB2_43 Depth 2
                                        #     Child Loop BB2_33 Depth 2
                                        #     Child Loop BB2_36 Depth 2
                                        #     Child Loop BB2_39 Depth 2
	movl	$0, 16(%rsp)
	testb	%r12b, %r12b
	jne	.LBB2_18
	.p2align	4, 0x90
.LBB2_17:                               # %forloop93
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	16(%rsp), %rax
	movb	$0, 224(%rsp,%rax)
	incl	%eax
	movl	%eax, 16(%rsp)
	cmpl	$300, 16(%rsp)                  # imm = 0x12C
	jl	.LBB2_17
.LBB2_18:                               # %forcont91
                                        #   in Loop: Header=BB2_16 Depth=1
	movq	%r15, %rdi
	callq	__decrypt@PLT
	movq	%r15, %rdi
	movq	%r14, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%r15, %rdi
	callq	__encrypt@PLT
	cmpb	$10, 224(%rsp)
	je	.LBB2_19
# %bb.31:                               # %else
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$1, 36(%rsp)
	movl	$0, 84(%rsp)
	testb	%r12b, %r12b
	je	.LBB2_43
.LBB2_32:                               # %whilecont111
                                        #   in Loop: Header=BB2_16 Depth=1
	movl	$0, 24(%rsp)
	cmpb	$124, 224(%rsp)
	je	.LBB2_34
	.p2align	4, 0x90
.LBB2_33:                               # %whileloop134
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	32(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2424(%rsp,%rax), %rax
	movslq	24(%rsp), %rcx
	movzbl	224(%rsp,%rcx), %edx
	movb	%dl, (%rcx,%rax)
	incl	24(%rsp)
	movslq	24(%rsp), %rax
	cmpb	$124, 224(%rsp,%rax)
	jne	.LBB2_33
.LBB2_34:                               # %whilecont135
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	24(%rsp)
	.p2align	4, 0x90
.LBB2_36:                               # %whileloop156
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	24(%rsp), %rax
	cmpb	$124, 224(%rsp,%rax)
	je	.LBB2_37
# %bb.35:                               # %whileloop156
                                        #   in Loop: Header=BB2_36 Depth=2
	movslq	32(%rsp), %rax
	movslq	24(%rsp), %rcx
	movzbl	224(%rsp,%rcx), %edx
	addl	$-48, %edx
	movl	%edx, 1224(%rsp,%rax,4)
	leal	1(%rcx), %eax
	movl	%eax, 24(%rsp)
	jmp	.LBB2_36
	.p2align	4, 0x90
.LBB2_45:                               # %merge121
                                        #   in Loop: Header=BB2_43 Depth=2
	cmpl	$0, 84(%rsp)
	jne	.LBB2_32
.LBB2_43:                               # %whileloop110
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	36(%rsp), %rax
	leaq	224(%rsp,%rax), %rbx
	movq	%rbp, %rdi
	callq	__decrypt@PLT
	movq	%rbp, %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%rbp, %rdi
	callq	__encrypt@PLT
	incl	36(%rsp)
	movl	36(%rsp), %eax
	decl	%eax
	cltq
	cmpb	$10, 224(%rsp,%rax)
	jne	.LBB2_45
# %bb.44:                               # %then119
                                        #   in Loop: Header=BB2_43 Depth=2
	movl	36(%rsp), %eax
	decl	%eax
	cltq
	movb	$0, 224(%rsp,%rax)
	movl	$1, 84(%rsp)
	jmp	.LBB2_45
	.p2align	4, 0x90
.LBB2_37:                               # %whilecont157
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	24(%rsp)
	movl	$0, 80(%rsp)
	.p2align	4, 0x90
.LBB2_39:                               # %whileloop178
                                        #   Parent Loop BB2_16 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	24(%rsp), %rax
	cmpb	$124, 224(%rsp,%rax)
	je	.LBB2_40
# %bb.38:                               # %whileloop178
                                        #   in Loop: Header=BB2_39 Depth=2
	movslq	32(%rsp), %rax
	imulq	$200, %rax, %rax
	addq	%r13, %rax
	movslq	80(%rsp), %rcx
	movslq	24(%rsp), %rdx
	movzbl	224(%rsp,%rdx), %edx
	movb	%dl, (%rcx,%rax)
	incl	24(%rsp)
	incl	80(%rsp)
	jmp	.LBB2_39
	.p2align	4, 0x90
.LBB2_40:                               # %whilecont179
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	24(%rsp)
	movslq	24(%rsp), %rax
	cmpb	$0, 224(%rsp,%rax)
	je	.LBB2_46
# %bb.41:                               # %then202
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	cmpb	$65, 224(%rsp,%rax)
	jne	.LBB2_49
# %bb.42:                               # %then209
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$4, 824(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_46:                               # %else203
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$-1, 824(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_49:                               # %else210
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	cmpb	$66, 224(%rsp,%rax)
	jne	.LBB2_51
# %bb.50:                               # %then219
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$3, 824(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_51:                               # %else220
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	cmpb	$67, 224(%rsp,%rax)
	jne	.LBB2_53
# %bb.52:                               # %then229
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$2, 824(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_53:                               # %else230
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	cmpb	$68, 224(%rsp,%rax)
	jne	.LBB2_55
# %bb.54:                               # %then239
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$1, 824(%rsp,%rax,4)
	jmp	.LBB2_47
.LBB2_55:                               # %else240
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	24(%rsp), %rax
	cmpb	$70, 224(%rsp,%rax)
	jne	.LBB2_47
# %bb.56:                               # %then249
                                        #   in Loop: Header=BB2_16 Depth=1
	movslq	32(%rsp), %rax
	movl	$0, 824(%rsp,%rax,4)
	.p2align	4, 0x90
.LBB2_47:                               # %merge204
                                        #   in Loop: Header=BB2_16 Depth=1
	incl	32(%rsp)
	jmp	.LBB2_48
.LBB2_30:                               # %then381
	leaq	.L_Const_String_.7(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
.LBB2_68:                               # %forcont388
	xorl	%eax, %eax
	addq	$22424, %rsp                    # imm = 0x5798
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
	.data
.L_Const_String_:
	.asciz	"%c"
	.size	.L_Const_String_, 3

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%c"
	.size	.L_Const_String_.1, 3

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"mzk\020\n\017\032\004\033L "
	.size	.L_Const_String_.2, 12

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
	.p2align	4
.L_Const_String_.3:
	.asciz	"bE_XY\nk^^OGZ^ON\020\n\017N "
	.size	.L_Const_String_.3, 21

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"bE_XY\niEGZFO^ON\020\n\017N "
	.size	.L_Const_String_.4, 21

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
	.p2align	4
.L_Const_String_.5:
	.asciz	"iXONC^Y\nxOGKCDCDM\020\n\017N  "
	.size	.L_Const_String_.5, 24

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
	.p2align	4
.L_Const_String_.6:
	.asciz	"zEYYCHFO\niE_XYOY\n^E\n~KAO\ndOR^ "
	.size	.L_Const_String_.6, 31

	.type	.L_Const_String_.7,@object      # @_Const_String_.7
	.p2align	4
.L_Const_String_.7:
	.asciz	"\n\ndEDO\n\007\niEDMXK^_FK^CEDY\013 "
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
