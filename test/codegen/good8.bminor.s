.data
x:	.quad 1
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
	MOVQ $0, %rbx
	MOVQ %rbx, x
.L0:
	CMP $0, %rbx
	JE .L1
	JMP .L0
.L1:
	MOVQ $0, %rbx
	MOVQ %rbx, -8(%rbp)
.L2:
	CMP $0, %rbx
	JE .L3
	JMP .L2
.L3:
	MOVQ $0, %rbx
	MOVQ %rbx, x
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
