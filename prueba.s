  .bss
  .globl x
x:
  .space 8
	.text
  .globl main
main:
  enter $304, $0
  movq $10, x(%rip)
  movq $15, -8(%rbp)
  mov -8(%rbp), %rax
  mov x(%rip), %rbx
  cmp %rbx, %rax
  mov $1, %r10
  jg 1f
  xor %r10, %r10
1:
  mov %r10, -16(%rbp)
  mov -16(%rbp), %r10
  cmp $1, %r10
  jne End_if
  mov $1, %r12
  add -8(%rbp), %r12
  add $1, %r12
  add $1, %r12
  mov %r12, x(%rip)
End_if:
  movq $20, -16(%rbp)
  movq $100, -24(%rbp)
  mov x(%rip), %r12
  add -8(%rbp), %r12
  add -16(%rbp), %r12
  add -24(%rbp), %r12
  mov %r12, -32(%rbp)
  mov x(%rip), %r12
  add -8(%rbp), %r12
  mov -16(%rbp), %r13
  add -24(%rbp), %r13
  add %r13, %r12
  mov x(%rip), %r13
  add -8(%rbp), %r13
  mov -16(%rbp), %r14
  add -24(%rbp), %r14
  add %r14, %r13
  add %r13, %r12
  mov x(%rip), %r13
  add -8(%rbp), %r13
  mov -16(%rbp), %r14
  add -24(%rbp), %r14
  add %r14, %r13
  mov x(%rip), %r14
  add -8(%rbp), %r14
  mov -16(%rbp), %r15
  add -24(%rbp), %r15
  add %r15, %r14
  add %r14, %r13
  sub %r13, %r12
  mov x(%rip), %r13
  add -8(%rbp), %r13
  mov -16(%rbp), %r14
  add -24(%rbp), %r14
  add %r14, %r13
  mov x(%rip), %r14
  add -8(%rbp), %r14
  mov -16(%rbp), %r15
  add -24(%rbp), %r15
  add %r15, %r14
  add %r14, %r13
  mov x(%rip), %r14
  add -8(%rbp), %r14
  mov -16(%rbp), %r15
  add -24(%rbp), %r15
  add %r15, %r14
  mov x(%rip), %r15
  add -8(%rbp), %r15
  mov %r12, -176(rbp)
  mov -16(%rbp), %r12
  add -24(%rbp), %r12
  add %r12, %r15
  add %r15, %r14
  sub %r14, %r13
  sub -176(%rbp), %r13
  mov %r13, -32(%rbp)
  mov -32(%rbp), %rax
  leave
  ret
  leave
	.section .note.GNU-stack,"",@progbits
