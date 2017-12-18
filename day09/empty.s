	.file	"empty.cpp"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$4, -4(%ebp)   // 4->a, a:4  - int a = 4
	addl	$1, -4(%ebp)   // a:5        - ++a
	movl	-4(%ebp), %eax // 5->t
	addl	%eax, %eax     // 10->t      - a+=a
	movl	%eax, -4(%ebp) // 10->a, a:10
	addl	$1, -4(%ebp)   // a:11       - a++
	movl	$0, %eax
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
