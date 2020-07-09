
global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
	call ft_strlen
	push rdi
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