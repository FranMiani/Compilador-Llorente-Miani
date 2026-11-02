  .bss
  .globl x
x:
  .space 8
	.text
  .globl max
max:
  enter $32, $0
  mov %rdi, -8(%rbp)
  mov %rsi, -16(%rbp)
  mov %rdx, -24(%rbp)
  mov -24(%rbp), %rax
  leave
  ret
  .globl main
main:
  enter $32, $0
  mov %rdi, -8(%rbp)
  mov %rsi, -16(%rbp)
  mov %rdx, -24(%rbp)
  movq $5, -8(%rbp)
  movq $1, -32(%rbp)
  mov $2, %rax
  leave
  ret
  movq $0, -32(%rbp)
  leave
	.section .note.GNU-stack,"",@progbits
