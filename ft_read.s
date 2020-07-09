global ft_read

section .text

ft_read:
	mov rax, 0
	syscall
	jl error
	ret

error:
	neg rax
	mov rcx, rax
	call __errno_location
	mov [rax], rcx
	mov rax, -1
	ret