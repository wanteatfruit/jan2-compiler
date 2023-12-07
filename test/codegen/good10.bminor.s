.data
i:	.quad 105
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
	MOVQ $110, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $104, %rbx
	MOVQ $100, %r10
	MOVQ i, %r11
	MOVQ %rbx, %rdi
	MOVQ %r10, %rsi
	MOVQ %r11, %rdx
	PUSHQ %r10
	PUSHQ %r11
	CALL print_character
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	MOVQ $100, %rbx
	MOVQ i, %r10
	MOVQ %rbx, %rdi
	MOVQ %r10, %rsi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_character
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	MOVQ i, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_character
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
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
