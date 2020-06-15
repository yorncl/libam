global ft_write

section .text

ft_write:
	mov rax, 1
	syscall
	jc error
	ret

error:
	mov rax, -1
	ret