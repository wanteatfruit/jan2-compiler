.data
x:	.quad 5
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
	MOVQ $2, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $10, %rbx
	MOVQ -8(%rbp), %r10
	MOVQ %rbx, %rax
	IMULQ %r10
	MOVQ %rax, %r10
	MOVQ x, %rbx
	MOVQ $4, %r11
	MOVQ %rbx, %rax
	IMULQ %r11
	MOVQ %rax, %r11
	SUBQ %r11, %r10
	MOV %r11, %rax
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
