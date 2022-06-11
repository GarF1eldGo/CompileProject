	.text
	.file	"module"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	subq	$7536, %rsp                     # imm = 0x1D70
	.cfi_def_cfa_offset 7568
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %rbp, -16
	movl	$0, 12(%rsp)
	movl	$0, 8(%rsp)
	movl	$0, 32(%rsp)
	movl	$0, 20(%rsp)
	movl	$0, 24(%rsp)
	movl	$0, 28(%rsp)
	movl	$0, 16(%rsp)
	leaq	.L_Const_String_(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	leaq	20(%rsp), %rsi
	leaq	24(%rsp), %rdx
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	movl	$0, 12(%rsp)
	cmpl	$0, 20(%rsp)
	jle	.LBB0_5
# %bb.1:                                # %forloop.preheader
	leaq	.L_Const_String_.1(%rip), %r14
	jmp	.LBB0_2
	.p2align	4, 0x90
.LBB0_4:                                # %forcont4
                                        #   in Loop: Header=BB0_2 Depth=1
	incl	12(%rsp)
	movl	12(%rsp), %eax
	cmpl	20(%rsp), %eax
	jge	.LBB0_5
.LBB0_2:                                # %forloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
	movl	$0, 8(%rsp)
	cmpl	$0, 24(%rsp)
	jle	.LBB0_4
	.p2align	4, 0x90
.LBB0_3:                                # %forloop6
                                        #   Parent Loop BB0_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	5036(%rsp,%rax), %rax
	movslq	8(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rbx
	movq	%r14, %rdi
	callq	__decrypt@PLT
	movq	%r14, %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%r14, %rdi
	callq	__encrypt@PLT
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	24(%rsp), %eax
	jl	.LBB0_3
	jmp	.LBB0_4
.LBB0_5:                                # %forcont
	leaq	.L_Const_String_.2(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	leaq	28(%rsp), %rsi
	leaq	16(%rsp), %rdx
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	movl	$0, 12(%rsp)
	cmpl	$0, 28(%rsp)
	jle	.LBB0_10
# %bb.6:
	leaq	.L_Const_String_.3(%rip), %r14
	jmp	.LBB0_7
	.p2align	4, 0x90
.LBB0_9:                                # %forcont33
                                        #   in Loop: Header=BB0_7 Depth=1
	incl	12(%rsp)
	movl	12(%rsp), %eax
	cmpl	28(%rsp), %eax
	jge	.LBB0_10
.LBB0_7:                                # %forloop28
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_8 Depth 2
	movl	$0, 8(%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_9
	.p2align	4, 0x90
.LBB0_8:                                # %forloop35
                                        #   Parent Loop BB0_7 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	2536(%rsp,%rax), %rax
	movslq	8(%rsp), %rcx
	leaq	(%rax,%rcx,4), %rbx
	movq	%r14, %rdi
	callq	__decrypt@PLT
	movq	%r14, %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movq	%r14, %rdi
	callq	__encrypt@PLT
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	16(%rsp), %eax
	jl	.LBB0_8
	jmp	.LBB0_9
.LBB0_10:                               # %forcont26
	movl	24(%rsp), %eax
	cmpl	28(%rsp), %eax
	je	.LBB0_13
# %bb.11:                               # %then
	leaq	.L_Const_String_.4(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	jmp	.LBB0_12
.LBB0_13:                               # %else
	movl	$0, 12(%rsp)
	cmpl	$0, 20(%rsp)
	jg	.LBB0_14
.LBB0_16:                               # %forcont58
	movl	$0, 12(%rsp)
	cmpl	$0, 20(%rsp)
	jle	.LBB0_12
# %bb.17:
	leaq	.L_Const_String_.5(%rip), %rbx
	leaq	.L_Const_String_.6(%rip), %r14
	jmp	.LBB0_18
	.p2align	4, 0x90
.LBB0_15:                               # %forcont65
                                        #   in Loop: Header=BB0_14 Depth=1
	incl	12(%rsp)
	movl	12(%rsp), %eax
	cmpl	20(%rsp), %eax
	jge	.LBB0_16
.LBB0_14:                               # %forloop60
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_21 Depth 2
                                        #       Child Loop BB0_22 Depth 3
	movl	$0, 8(%rsp)
	cmpl	$0, 16(%rsp)
	jg	.LBB0_21
	jmp	.LBB0_15
	.p2align	4, 0x90
.LBB0_23:                               # %forcont77
                                        #   in Loop: Header=BB0_21 Depth=2
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	16(%rsp), %eax
	jge	.LBB0_15
.LBB0_21:                               # %forloop67
                                        #   Parent Loop BB0_14 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_22 Depth 3
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	36(%rsp,%rax), %rax
	movslq	8(%rsp), %rcx
	movl	$0, (%rax,%rcx,4)
	movl	$0, 32(%rsp)
	cmpl	$0, 24(%rsp)
	jle	.LBB0_23
	.p2align	4, 0x90
.LBB0_22:                               # %forloop79
                                        #   Parent Loop BB0_14 Depth=1
                                        #     Parent Loop BB0_21 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	36(%rsp,%rax), %rcx
	movslq	8(%rsp), %rdx
	leaq	5036(%rsp,%rax), %rax
	movslq	32(%rsp), %rsi
	imulq	$100, %rsi, %rdi
	leaq	2536(%rsp,%rdi), %rdi
	movl	(%rax,%rsi,4), %eax
	imull	(%rdi,%rdx,4), %eax
	addl	%eax, (%rcx,%rdx,4)
	incl	32(%rsp)
	movl	32(%rsp), %eax
	cmpl	24(%rsp), %eax
	jl	.LBB0_22
	jmp	.LBB0_23
	.p2align	4, 0x90
.LBB0_20:                               # %forcont121
                                        #   in Loop: Header=BB0_18 Depth=1
	movq	%r14, %rdi
	callq	__decrypt@PLT
	movq	%r14, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%r14, %rdi
	callq	__encrypt@PLT
	incl	12(%rsp)
	movl	12(%rsp), %eax
	cmpl	20(%rsp), %eax
	jge	.LBB0_12
.LBB0_18:                               # %forloop116
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_19 Depth 2
	movl	$0, 8(%rsp)
	cmpl	$0, 16(%rsp)
	jle	.LBB0_20
	.p2align	4, 0x90
.LBB0_19:                               # %forloop123
                                        #   Parent Loop BB0_18 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	12(%rsp), %rax
	imulq	$100, %rax, %rax
	leaq	36(%rsp,%rax), %rax
	movslq	8(%rsp), %rcx
	movl	(%rax,%rcx,4), %ebp
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movl	%ebp, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	incl	8(%rsp)
	movl	8(%rsp), %eax
	cmpl	16(%rsp), %eax
	jl	.LBB0_19
	jmp	.LBB0_20
.LBB0_12:                               # %forcont114
	xorl	%eax, %eax
	addq	$7536, %rsp                     # imm = 0x1D70
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.data
.L_Const_String_:
	.asciz	"\017N\n\017N"
	.size	.L_Const_String_, 6

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"\017\034N"
	.size	.L_Const_String_.1, 4

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"\017N\n\017N"
	.size	.L_Const_String_.2, 6

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
.L_Const_String_.3:
	.asciz	"\017\034N"
	.size	.L_Const_String_.3, 4

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"cDIEGZK^CHFO\nnCGODYCEDY "
	.size	.L_Const_String_.4, 25

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
.L_Const_String_.5:
	.asciz	"\017\033\032N"
	.size	.L_Const_String_.5, 5

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
.L_Const_String_.6:
	.asciz	" "
	.size	.L_Const_String_.6, 2

	.section	".note.GNU-stack","",@progbits
