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
	MOVQ x, %rbx
	MOVQ $10, %r10
	MOVQ -8(%rbp), %r11
	MOVQ %r10, %rax
	IMULQ %r11
	MOVQ %rax, %r11
	MOVQ x, %r10
	MOVQ $4, %r12
	MOVQ %r10, %rax
	IMULQ %r12
	MOVQ %rax, %r12
	SUBQ %r12, %r11
	ADDQ %rbx, %r12
	MOV %r12, %rax
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
