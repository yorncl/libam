
global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
	push rdi
	call ft_strlen
	mov rdi, rax
	inc rdi
	call malloc
	test rax, rax
	jz error
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret

error:
	mov rax, 0
	ret