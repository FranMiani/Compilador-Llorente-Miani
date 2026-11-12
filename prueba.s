  .bss
  .globl x
x:
  .space 8
	.text
  .globl main
main:
  enter $32, $0
  mov $10, %r12
  mov $15, %r13
  mov %r13, %rax
  mov %r12, %rbx
  cmp %rbx, %rax
  mov $1, %r10
  jg 1f
  xor %r10, %r10
1:
  cmp $1, %r10
  jne End_if
  add %r13, $1
  mov %r14, $1
  add $1, %r14
  mov %r15, %r14
  mov -8(%rbp), %r13
  add $1, %r15
  mov %r13, %r15
  mov %r13, %r12
End_if:
  mov $20, %r13
  mov $100, %r14
  mov -16(%rbp), %r13
  add -8(%rbp), %r12
  mov %r13, %r12
  mov -24(%rbp), %r14
  add -16(%rbp), %r13
  mov %r14, %r13
  mov -32(%rbp), %r15
  add -24(%rbp), %r14
  mov %r15, %r14
  mov %r15, -32(%rbp)
  mov -32(%rbp), %rax
  leave
  ret
  leave
	.section .note.GNU-stack,"",@progbits
