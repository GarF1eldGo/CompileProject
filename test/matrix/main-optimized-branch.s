	.text
	.file	"module"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$7528, %rsp                     # imm = 0x1D68
	.cfi_def_cfa_offset 7552
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movl	$0, 4(%rsp)
	movl	$0, (%rsp)
	movl	$0, 24(%rsp)
	movl	$0, 12(%rsp)
	movl	$0, 16(%rsp)
	movl	$0, 20(%rsp)
	movl	$0, 8(%rsp)
	leaq	.L_Const_String_(%rip), %rdi
	leaq	12(%rsp), %rsi
	leaq	16(%rsp), %rdx
	xorl	%eax, %eax
	callq	scanf@PLT
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jle	.LBB0_5
# %bb.1:                                # %forloop.preheader
	leaq	.L_Const_String_.1(%rip), %rbx
	jmp	.LBB0_2
	.p2align	4, 0x90
.LBB0_4:                                # %forcont4
                                        #   in Loop: Header=BB0_2 Depth=1
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_5
.LBB0_2:                                # %forloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_4
	.p2align	4, 0x90
.LBB0_3:                                # %forloop6
                                        #   Parent Loop BB0_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	5028(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rsi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	scanf@PLT
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	16(%rsp), %eax
	jl	.LBB0_3
	jmp	.LBB0_4
.LBB0_5:                                # %forcont
	leaq	.L_Const_String_.2(%rip), %rdi
	leaq	20(%rsp), %rsi
	leaq	8(%rsp), %rdx
	xorl	%eax, %eax
	callq	scanf@PLT
	movl	$0, 4(%rsp)
	cmpl	$0, 20(%rsp)
	jle	.LBB0_10
# %bb.6:
	leaq	.L_Const_String_.3(%rip), %rbx
	jmp	.LBB0_7
	.p2align	4, 0x90
.LBB0_9:                                # %forcont33
                                        #   in Loop: Header=BB0_7 Depth=1
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	20(%rsp), %eax
	jge	.LBB0_10
.LBB0_7:                                # %forloop28
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_8 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jle	.LBB0_9
	.p2align	4, 0x90
.LBB0_8:                                # %forloop35
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2528(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rsi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	scanf@PLT
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jl	.LBB0_8
	jmp	.LBB0_9
.LBB0_10:                               # %forcont26
	movl	16(%rsp), %eax
	cmpl	20(%rsp), %eax
	je	.LBB0_13
# %bb.11:                               # %then
	leaq	.L_Const_String_.4(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	jmp	.LBB0_12
.LBB0_13:                               # %else
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jg	.LBB0_14
.LBB0_16:                               # %forcont58
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jle	.LBB0_12
# %bb.17:
	leaq	.L_Const_String_.5(%rip), %rbx
	leaq	.L_Const_String_.6(%rip), %r14
	jmp	.LBB0_18
	.p2align	4, 0x90
.LBB0_15:                               # %forcont65
                                        #   in Loop: Header=BB0_14 Depth=1
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_16
.LBB0_14:                               # %forloop60
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_21 Depth 2
                                        #       Child Loop BB0_22 Depth 3
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jg	.LBB0_21
	jmp	.LBB0_15
	.p2align	4, 0x90
.LBB0_23:                               # %forcont77
                                        #   in Loop: Header=BB0_21 Depth=2
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jge	.LBB0_15
.LBB0_21:                               # %forloop67
                                        #   Parent Loop BB0_14 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_22 Depth 3
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	28(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	movl	$0, (%rax,%rcx,4)
	movl	$0, 24(%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_23
	.p2align	4, 0x90
.LBB0_22:                               # %forloop79
                                        #   Parent Loop BB0_14 Depth=1
                                        #     Parent Loop BB0_21 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	28(%rsp,%rax), %rcx
	movslq	(%rsp), %rdx
	leaq	5028(%rsp,%rax), %rax
	movslq	24(%rsp), %rsi
	imulq	$100, %rsi, %rdi
	leaq	2528(%rsp,%rdi), %rdi
	movl	(%rax,%rsi,4), %eax
	imull	(%rdi,%rdx,4), %eax
	addl	%eax, (%rcx,%rdx,4)
	incl	24(%rsp)
	movl	24(%rsp), %eax
	cmpl	16(%rsp), %eax
	jl	.LBB0_22
	jmp	.LBB0_23
	.p2align	4, 0x90
.LBB0_20:                               # %forcont121
                                        #   in Loop: Header=BB0_18 Depth=1
	movq	%r14, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_12
.LBB0_18:                               # %forloop116
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_19 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jle	.LBB0_20
	.p2align	4, 0x90
.LBB0_19:                               # %forloop123
                                        #   Parent Loop BB0_18 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	28(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	movl	(%rax,%rcx,4), %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jl	.LBB0_19
	jmp	.LBB0_20
.LBB0_12:                               # %forcont114
	xorl	%eax, %eax
	addq	$7528, %rsp                     # imm = 0x1D68
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d %d"
	.size	.L_Const_String_, 6

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%6d"
	.size	.L_Const_String_.1, 4

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"%d %d"
	.size	.L_Const_String_.2, 6

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
.L_Const_String_.3:
	.asciz	"%6d"
	.size	.L_Const_String_.3, 4

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"Incompatible Dimensions\n"
	.size	.L_Const_String_.4, 25

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
.L_Const_String_.5:
	.asciz	"%10d"
	.size	.L_Const_String_.5, 5

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
.L_Const_String_.6:
	.asciz	"\n"
	.size	.L_Const_String_.6, 2

	.section	".note.GNU-stack","",@progbits
