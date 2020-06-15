
global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
	push rdi
	call ft_strlen
	;push rax ;keeping string length

	mov rdi, rax
	inc rdi
	call malloc
	test rax, rax
	jz error

;	pop rcx ;popping string length
	pop rsi
	mov rdi, rax
	
	;mov [rdi + rcx], byte 0  ;null-terminating the string
	
	call ft_strcpy
	ret

error:
	mov rax, 0
	ret