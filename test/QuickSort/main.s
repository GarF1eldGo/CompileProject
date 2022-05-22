	.text
	.file	"module"
	.globl	quickSort                       # -- Begin function quickSort
	.p2align	4, 0x90
	.type	quickSort,@function
quickSort:                              # @quickSort
	.cfi_startproc
# %bb.0:                                # %quickSort
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -16
	movl	%esi, 24(%rsp)
	movl	%edx, 20(%rsp)
	movl	$0, 8(%rsp)
	movl	$0, 12(%rsp)
	movl	$0, 28(%rsp)
	movl	$0, 16(%rsp)
	cmpl	%edx, %esi
	jge	.LBB0_11
# %bb.1:                                # %else
	movq	%rdi, %rbx
	movslq	24(%rsp), %rax
	movl	(%rdi,%rax,4), %ecx
	movl	%ecx, 16(%rsp)
	movl	%eax, 8(%rsp)
	movl	20(%rsp), %ecx
	movl	%ecx, 12(%rsp)
	cmpl	%ecx, %eax
	jl	.LBB0_2
.LBB0_10:                               # %whilecont
	movslq	8(%rsp), %rax
	movl	16(%rsp), %ecx
	movl	%ecx, (%rbx,%rax,4)
	movl	8(%rsp), %edx
	decl	%edx
	movl	24(%rsp), %esi
	movq	%rbx, %rdi
	callq	quickSort
	movl	8(%rsp), %esi
	incl	%esi
	movl	20(%rsp), %edx
	movq	%rbx, %rdi
	callq	quickSort
.LBB0_11:                               # %then
	addq	$32, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.LBB0_9:                                # %whilecont40
                                        #   in Loop: Header=BB0_2 Depth=1
	.cfi_def_cfa_offset 48
	movslq	12(%rsp), %rax
	movslq	8(%rsp), %rcx
	movl	(%rbx,%rcx,4), %ecx
	movl	%ecx, (%rbx,%rax,4)
	movl	8(%rsp), %eax
	cmpl	12(%rsp), %eax
	jge	.LBB0_10
	.p2align	4, 0x90
.LBB0_2:                                # %whileloop
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movslq	12(%rsp), %rax
	cmpl	%eax, 8(%rsp)
	jge	.LBB0_5
# %bb.3:                                # %whileloop
                                        #   in Loop: Header=BB0_2 Depth=1
	movl	16(%rsp), %ecx
	cmpl	%ecx, (%rbx,%rax,4)
	jl	.LBB0_5
# %bb.4:                                # %whileloop13
                                        #   in Loop: Header=BB0_2 Depth=1
	decl	12(%rsp)
	jmp	.LBB0_2
.LBB0_5:                                # %whilecont14
                                        #   in Loop: Header=BB0_2 Depth=1
	movslq	8(%rsp), %rax
	movslq	12(%rsp), %rcx
	movl	(%rbx,%rcx,4), %ecx
	movl	%ecx, (%rbx,%rax,4)
	.p2align	4, 0x90
.LBB0_6:                                # %whilecont14
                                        #   Parent Loop BB0_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	8(%rsp), %rax
	cmpl	12(%rsp), %eax
	jge	.LBB0_9
# %bb.7:                                # %whilecont14
                                        #   in Loop: Header=BB0_6 Depth=2
	movl	16(%rsp), %ecx
	cmpl	%ecx, (%rbx,%rax,4)
	jg	.LBB0_9
# %bb.8:                                # %whileloop39
                                        #   in Loop: Header=BB0_6 Depth=2
	incl	8(%rsp)
	jmp	.LBB0_6
.Lfunc_end0:
	.size	quickSort, .Lfunc_end0-quickSort
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	subq	$400008, %rsp                   # imm = 0x61A88
	.cfi_def_cfa_offset 400016
	movl	$0, 4(%rsp)
	movl	$0, (%rsp)
	leaq	4(%rsp), %rsi
	movl	$.L_Const_String_, %edi
	xorl	%eax, %eax
	callq	scanf
	movl	$0, (%rsp)
	cmpl	$0, 4(%rsp)
	jle	.LBB1_2
	.p2align	4, 0x90
.LBB1_1:                                # %forloop
                                        # =>This Inner Loop Header: Depth=1
	movslq	(%rsp), %rax
	leaq	8(%rsp,%rax,4), %rsi
	movl	$.L_Const_String_.1, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	4(%rsp), %eax
	jl	.LBB1_1
.LBB1_2:                                # %forcont
	movl	4(%rsp), %edx
	decl	%edx
	leaq	8(%rsp), %rdi
	xorl	%esi, %esi
	callq	quickSort
	movl	$0, (%rsp)
	cmpl	$0, 4(%rsp)
	jle	.LBB1_4
	.p2align	4, 0x90
.LBB1_3:                                # %forloop12
                                        # =>This Inner Loop Header: Depth=1
	movslq	(%rsp), %rax
	movl	8(%rsp,%rax,4), %esi
	movl	$.L_Const_String_.2, %edi
	xorl	%eax, %eax
	callq	printf
	incl	(%rsp)
	movl	(%rsp), %eax
	cmpl	4(%rsp), %eax
	jl	.LBB1_3
.LBB1_4:                                # %forcont13
	xorl	%eax, %eax
	addq	$400008, %rsp                   # imm = 0x61A88
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d"
	.size	.L_Const_String_, 3

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%d"
	.size	.L_Const_String_.1, 3

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"%d\n"
	.size	.L_Const_String_.2, 4

	.section	".note.GNU-stack","",@progbits
