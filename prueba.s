	.text
  .globl max
max:
  enter $64, $0
  mov %rdi, -8(%rbp)
  mov %rsi, -16(%rbp)
  mov %rdx, -24(%rbp)
  mov %rcx, -32(%rbp)
  mov %r8, -40(%rbp)
  mov %r9, -48(%rbp)
  mov 16(%rbp), %r11
  mov %r11, -56(%rbp)
  mov -8(%rbp), %rax
  leave
  ret
  .globl main
main:
  enter $80, $0
  movq $0, -8(%rbp)
  mov $1, %rdi
  mov $2, %rsi
  mov $3, %rdx
  mov $4, %rcx
  mov $5, %r8
  mov $6, %r9
  push $7
  call max
  mov %rax, -16(%rbp)
  add $8, %rsp
  mov $1, %rax
  add $1, %rax
  mov %rax, -24(%rbp)
  mov $2, %rax
  mov -24(%rbp), %rbx
  cmp %rbx, %rax
  mov $1, %r10
  je 1f
  mov $0, %r10
1:
  mov %r10, -32(%rbp)
  mov -32(%rbp), %r10
  cmp $1, %r10
  jne Else
  movq $2, -40(%rbp)
  jmp End_if
Else:
  movq $2, -48(%rbp)
End_if:
  mov $1, %rax
  cqto
  mov $2, %r11
  idiv %r11
  mov %rdx, -56(%rbp)
  mov -56(%rbp), %r11
  mov %r11, -8(%rbp)
  call getInt
  mov %rax, -64(%rbp)
  mov -64(%rbp), %rdi
  call print
  mov %rax, -72(%rbp)
  mov $1, %rax
  leave
  ret
	.section .note.GNU-stack,"",@progbits
