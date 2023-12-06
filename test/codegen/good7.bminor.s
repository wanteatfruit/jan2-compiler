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
	MOVQ $0, %rbx
	CMP $0, %rbx
	JE .L0
	MOVQ $15, %rbx
	MOVQ %rbx, x
	JMP .L1
.L0:
	MOVQ $10, %rbx
	MOVQ %rbx, x
.L1:
	MOVQ $1, %rbx
	CMP $0, %rbx
	JE .L2
	MOVQ $0, %rbx
	MOV %rbx, %rax
	JMP .main_epilogue
	JMP .L3
.L2:
	MOVQ $0, %rbx
	MOV %rbx, %rax
	JMP .main_epilogue
.L3:
.main_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
