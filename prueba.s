  .bss
	.text
  .globl main
main:
  enter $16, $0
  call mm
  mov %rax, -8(%rbp)
  mov -8(%rbp), %rax
  leave
  ret
  leave
	.section .note.GNU-stack,"",@progbits
