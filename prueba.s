  .bss
  .globl x
x:
  .space 8
	.text
  .globl main
main:
  enter $32, $0
  mov $5, %r12
  mov %r12, %r14
  add $3, %r14
  mov %r14, %r13
  mov %r13, %rdi
  mov x(%rip), %r12
  mov -8(%rbp), %r13
  call print
  mov %rax, -24(%rbp)
  mov %r12, x(%rip)
  mov %r13, -8(%rbp)
  mov %r13, %rax
  leave
  ret
  leave
	.section .note.GNU-stack,"",@progbits
