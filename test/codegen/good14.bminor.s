.data
x:	.quad 5
.text
.globl fxnCall
fxnCall:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	SUBQ $40, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
	MOVQ x, %rbx
	MOVQ $4, %r10
	MOVQ %rbx, %rax
	IMULQ %r10
	MOVQ %rax, %r10
	MOV %r10, %rax
	JMP .fxnCall_epilogue
.fxnCall_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
.text
.globl fxnCall2
fxnCall2:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	PUSHQ %rdi
	SUBQ $40, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
	MOVQ 8(%rbp), %rbx
	MOVQ $2, %r10
	MOVQ %rbx, %rax
	IMULQ %r10
	MOVQ %rax, %r10
	MOV %r10, %rax
	JMP .fxnCall2_epilogue
.fxnCall2_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
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
	MOVQ -8(%rbp), %rbx
	PUSHQ %r10
	PUSHQ %r11
	CALL fxnCall
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %r10
	MOVQ $14, %r11
	MOVQ %r11, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL fxnCall2
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %r11
	ADDQ %r10, %r11
	ADDQ %rbx, %r11
	MOVQ %r11, -8(%rbp)
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
