.text
.global main
main:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	SUBQ $40, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
	MOVQ $8, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $2, %rbx
	MOVQ %rbx, -16(%rbp)
	MOVQ -8(%rbp), %rbx
	MOVQ -16(%rbp), %r10
	ADDQ %rbx, %r10
	MOVQ %r10, -8(%rbp)
	MOVQ $1, %rbx
	MOV %rbx, %rax
	JMP .main_epilogue_epilogue
main_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
