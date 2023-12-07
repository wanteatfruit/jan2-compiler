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
	MOVQ $10, %rbx
	MOVQ %rbx, -8(%rbp)
	MOVQ $5, %rbx
	MOVQ %rbx, -16(%rbp)
	MOVQ x, %rbx
	MOVQ -16(%rbp), %r10
	CMPQ %r10, %rbx
	JGE .L2
	MOVQ $0, %rbx
	JMP .L3
.L2:
	MOVQ $1, %rbx
.L3:
	CMP $0, %rbx
	JE .L0
.data
.L4:
	.string "should be printed\n"
.text
	LEAQ .L4, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L1
.L0:
.data
.L5:
	.string "shouldn't be printed\n"
.text
	LEAQ .L5, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L1:
	MOVQ -8(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JG .L8
	MOVQ $0, %rbx
	JMP .L9
.L8:
	MOVQ $1, %rbx
.L9:
	CMP $0, %rbx
	JE .L6
.data
.L10:
	.string "should be printed\n"
.text
	LEAQ .L10, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L7
.L6:
.data
.L11:
	.string "shouldn't be printed\n"
.text
	LEAQ .L11, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L7:
	MOVQ -16(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JE .L14
	MOVQ $0, %rbx
	JMP .L15
.L14:
	MOVQ $1, %rbx
.L15:
	CMP $0, %rbx
	JE .L12
.data
.L16:
	.string "should be printed\n"
.text
	LEAQ .L16, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L13
.L12:
.data
.L17:
	.string "shouldn't be printed\n"
.text
	LEAQ .L17, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L13:
	MOVQ x, %rbx
	MOVQ -8(%rbp), %r10
	CMPQ %r10, %rbx
	JLE .L20
	MOVQ $0, %rbx
	JMP .L21
.L20:
	MOVQ $1, %rbx
.L21:
	CMP $0, %rbx
	JE .L18
.data
.L22:
	.string "should be printed\n"
.text
	LEAQ .L22, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L19
.L18:
.data
.L23:
	.string "shouldn't be printed\n"
.text
	LEAQ .L23, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L19:
	MOVQ x, %rbx
	MOVQ -8(%rbp), %r10
	CMPQ %r10, %rbx
	JNE .L26
	MOVQ $0, %rbx
	JMP .L27
.L26:
	MOVQ $1, %rbx
.L27:
	CMP $0, %rbx
	JE .L24
.data
.L28:
	.string "should be printed\n"
.text
	LEAQ .L28, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L25
.L24:
.data
.L29:
	.string "shouldn't be printed\n"
.text
	LEAQ .L29, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L25:
	MOVQ -16(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JL .L32
	MOVQ $0, %rbx
	JMP .L33
.L32:
	MOVQ $1, %rbx
.L33:
	CMP $0, %rbx
	JE .L30
.data
.L34:
	.string "shouldn't be printed\n"
.text
	LEAQ .L34, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L31
.L30:
.data
.L35:
	.string "should be printed\n"
.text
	LEAQ .L35, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L31:
	MOVQ -8(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JL .L38
	MOVQ $0, %rbx
	JMP .L39
.L38:
	MOVQ $1, %rbx
.L39:
	CMP $0, %rbx
	JE .L36
.data
.L40:
	.string "shouldn't be printed\n"
.text
	LEAQ .L40, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L37
.L36:
.data
.L41:
	.string "should be printed\n"
.text
	LEAQ .L41, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L37:
	MOVQ -16(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JNE .L44
	MOVQ $0, %rbx
	JMP .L45
.L44:
	MOVQ $1, %rbx
.L45:
	CMP $0, %rbx
	JE .L42
.data
.L46:
	.string "shouldn't be printed\n"
.text
	LEAQ .L46, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L43
.L42:
.data
.L47:
	.string "should be printed\n"
.text
	LEAQ .L47, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L43:
	MOVQ -8(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JLE .L50
	MOVQ $0, %rbx
	JMP .L51
.L50:
	MOVQ $1, %rbx
.L51:
	CMP $0, %rbx
	JE .L48
.data
.L52:
	.string "shouldn't be printed\n"
.text
	LEAQ .L52, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L49
.L48:
.data
.L53:
	.string "should be printed\n"
.text
	LEAQ .L53, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L49:
	MOVQ -8(%rbp), %rbx
	MOVQ x, %r10
	CMPQ %r10, %rbx
	JE .L56
	MOVQ $0, %rbx
	JMP .L57
.L56:
	MOVQ $1, %rbx
.L57:
	CMP $0, %rbx
	JE .L54
.data
.L58:
	.string "shouldn't be printed\n"
.text
	LEAQ .L58, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
	JMP .L55
.L54:
.data
.L59:
	.string "should be printed\n"
.text
	LEAQ .L59, %rbx
	MOVQ %rbx, %rdi
	PUSHQ %r10
	PUSHQ %r11
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOVQ %rax, %rbx
.L55:
.main_epilogue:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	RET
