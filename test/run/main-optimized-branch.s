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
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	movl	$1, %esi
	callq	func@PLT
	movl	%eax, 4(%rsp)
	leaq	.L_Const_String_(%rip), %rdi
	movl	%eax, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d\n"
	.size	.L_Const_String_, 4

	.section	".note.GNU-stack","",@progbits
