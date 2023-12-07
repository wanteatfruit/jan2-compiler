.text
.globl main
main:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	SUBQ $40, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
.data
.L0:
	.quad 1
	.quad 2
	.quad 3
.text
	LEAQ .L0, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $20, %rbx
	MOVQ -8(%rbp), %r10
	MOVQ $1, %r11
	MOVQ %r11, %rax
	IMULQ $8
	ADDQ %r10, %rax
	MOVQ %rbx, (%rax)
	MOVQ $0, %rbx
	MOV %rbx, %rax
	JMP .main_epilogue
.main_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
