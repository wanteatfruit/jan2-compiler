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
	MOVQ $5, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $0, %rbx
	CMP $0, %rbx
	JE .L0
	MOVQ $15, %rbx
	MOVQ %rbx, -8(%rbp)
	JMP .L1
.L0:
	MOVQ $10, %rbx
	MOVQ %rbx, -8(%rbp)
.L1:
	MOVQ -8(%rbp), %rbx
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
