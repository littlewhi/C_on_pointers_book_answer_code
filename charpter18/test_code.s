	.file	"test_code.c"
	.text
	.globl	static_variable
	.data
	.align 4
	.type	static_variable, @object
	.size	static_variable, 4
static_variable:
	.long	5
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movl	$1, %r12d
	movl	$10, %r13d
	movl	$1, %ebx
	movl	$1, a_very_long_name_to_see_how_long_they_can_be(%rip)
	movl	%r13d, %edx
	movl	%r12d, %esi
	movl	$10, %edi
	movl	$0, %eax
	call	func_ret_int
	movl	$0, %eax
	call	func_ret_double
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movq	%rbx, %rdi
	movl	$0, %eax
	call	func_ret_char_ptr
	movq	%rax, %rbx
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.globl	func_ret_int
	.type	func_ret_int, @function
func_ret_int:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, %ecx
	movl	-24(%rbp), %eax
	subl	$6, %eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func_ret_int, .-func_ret_int
	.globl	func_ret_double
	.type	func_ret_double, @function
func_ret_double:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	.LC0(%rip), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func_ret_double, .-func_ret_double
	.globl	func_ret_char_ptr
	.type	func_ret_char_ptr, @function
func_ret_char_ptr:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	func_ret_char_ptr, .-func_ret_char_ptr
	.section	.rodata
	.align 8
.LC0:
	.long	1374389535
	.long	1074339512
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
