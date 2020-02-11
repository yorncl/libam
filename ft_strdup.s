

section .text
	global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push rdi
	call _ft_strlen
	;push rax ;keeping string length

	mov rdi, rax
	inc rdi
	call _malloc
	test rax, rax
	jz error

;	pop rcx ;popping string length
	pop rsi
	mov rdi, rax
	
	;mov [rdi + rcx], byte 0  ;null-terminating the string
	
	call _ft_strcpy
	ret

error:
	mov rax, 0
	ret