	.text
	.file	"module"
	.globl	func                            # -- Begin function func
	.p2align	4, 0x90
	.type	func,@function
func:                                   # @func
	.cfi_startproc
# %bb.0:                                # %func
	movl	%edi, -4(%rsp)
	movl	%esi, -8(%rsp)
	xorl	%eax, %eax
	retq
.Lfunc_end0:
	.size	func, .Lfunc_end0-func
	.cfi_endproc
                                        # -- End function
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
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movl	$1, %edi
	movl	$1, %esi
	callq	func@PLT
	movl	%eax, %ebx
	movl	%eax, 4(%rsp)
	leaq	.L_Const_String_(%rip), %r14
	movq	%r14, %rdi
	callq	__decrypt@PLT
	movq	%r14, %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%r14, %rdi
	callq	__encrypt@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.data
.L_Const_String_:
	.asciz	"\017N "
	.size	.L_Const_String_, 4

	.section	".note.GNU-stack","",@progbits
