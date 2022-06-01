	.text
	.file	"module"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	leaq	.L_Const_String_(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	leaq	.L_Const_String_.1(%rip), %rbx
	movq	%rbx, %rdi
	callq	__decrypt@PLT
	movq	%rbx, %rdi
	movl	$2020, %esi                     # imm = 0x7E4
	movl	$601, %edx                      # imm = 0x259
	xorl	%eax, %eax
	callq	printf@PLT
	movq	%rbx, %rdi
	callq	__encrypt@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.data
.L_Const_String_:
	.asciz	"BOFFE\n]EXFN\013 "
	.size	.L_Const_String_, 14

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"\017\032\036N\n\017\032\036N "
	.size	.L_Const_String_.1, 11

	.section	".note.GNU-stack","",@progbits
