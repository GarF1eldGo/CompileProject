	.text
	.file	"module"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	subq	$7528, %rsp                     # imm = 0x1D68
	.cfi_def_cfa_offset 7536
	movl	$0, 4(%rsp)
	movl	$0, (%rsp)
	movl	$0, 24(%rsp)
	movl	$0, 12(%rsp)
	movl	$0, 16(%rsp)
	movl	$0, 20(%rsp)
	movl	$0, 8(%rsp)
	leaq	12(%rsp), %rsi
	leaq	16(%rsp), %rdx
	movl	$.L_Const_String_, %edi
	xorl	%eax, %eax
	callq	scanf
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jg	.LBB0_1
.LBB0_4:                                # %forcont
	leaq	20(%rsp), %rsi
	leaq	8(%rsp), %rdx
	movl	$.L_Const_String_.2, %edi
	xorl	%eax, %eax
	callq	scanf
	movl	$0, 4(%rsp)
	cmpl	$0, 20(%rsp)
	jg	.LBB0_5
.LBB0_8:                                # %forcont26
	movl	16(%rsp), %eax
	cmpl	20(%rsp), %eax
	je	.LBB0_10
# %bb.9:                                # %then
	movl	$.L_Const_String_.4, %edi
	xorl	%eax, %eax
	callq	printf
	jmp	.LBB0_14
	.p2align	4, 0x90
.LBB0_3:                                # %forcont5
                                        #   in Loop: Header=BB0_1 Depth=1
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_4
.LBB0_1:                                # %forloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_2 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_3
	.p2align	4, 0x90
.LBB0_2:                                # %forloop4
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	5028(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rsi
	movl	$.L_Const_String_.1, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	16(%rsp), %eax
	jl	.LBB0_2
	jmp	.LBB0_3
	.p2align	4, 0x90
.LBB0_7:                                # %forcont32
                                        #   in Loop: Header=BB0_5 Depth=1
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	20(%rsp), %eax
	jge	.LBB0_8
.LBB0_5:                                # %forloop25
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jle	.LBB0_7
	.p2align	4, 0x90
.LBB0_6:                                # %forloop31
                                        #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2528(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rsi
	movl	$.L_Const_String_.3, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jl	.LBB0_6
	jmp	.LBB0_7
.LBB0_10:                               # %else
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jg	.LBB0_11
.LBB0_13:                               # %forcont56
	movl	$0, 4(%rsp)
	cmpl	$0, 12(%rsp)
	jg	.LBB0_18
.LBB0_14:                               # %forcont109
	xorl	%eax, %eax
	addq	$7528, %rsp                     # imm = 0x1D68
	.cfi_def_cfa_offset 8
	retq
	.p2align	4, 0x90
.LBB0_12:                               # %forcont62
                                        #   in Loop: Header=BB0_11 Depth=1
	.cfi_def_cfa_offset 7536
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_13
.LBB0_11:                               # %forloop55
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_15 Depth 2
                                        #       Child Loop BB0_16 Depth 3
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jg	.LBB0_15
	jmp	.LBB0_12
	.p2align	4, 0x90
.LBB0_17:                               # %forcont73
                                        #   in Loop: Header=BB0_15 Depth=2
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jge	.LBB0_12
.LBB0_15:                               # %forloop61
                                        #   Parent Loop BB0_11 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_16 Depth 3
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	28(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	movl	$0, (%rax,%rcx,4)
	movl	$0, 24(%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_17
	.p2align	4, 0x90
.LBB0_16:                               # %forloop72
                                        #   Parent Loop BB0_11 Depth=1
                                        #     Parent Loop BB0_15 Depth=2
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
	jl	.LBB0_16
	jmp	.LBB0_17
	.p2align	4, 0x90
.LBB0_20:                               # %forcont115
                                        #   in Loop: Header=BB0_18 Depth=1
	movl	$.L_Const_String_.6, %edi
	xorl	%eax, %eax
	callq	printf
	incl	4(%rsp)
	movl	4(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_14
.LBB0_18:                               # %forloop108
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_19 Depth 2
	movl	$0, (%rsp)
	cmpl	$0, 8(%rsp)
	jle	.LBB0_20
	.p2align	4, 0x90
.LBB0_19:                               # %forloop114
                                        #   Parent Loop BB0_18 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	4(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	28(%rsp,%rax), %rax
	movslq	(%rsp), %rcx
	movl	(%rax,%rcx,4), %esi
	movl	$.L_Const_String_.5, %edi
	xorl	%eax, %eax
	callq	printf
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	8(%rsp), %eax
	jl	.LBB0_19
	jmp	.LBB0_20
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
