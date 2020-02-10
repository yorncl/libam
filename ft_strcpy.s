section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, rdi

loop:
	mov rcx, [rsi]
	mov [rdi], rcx
	inc rdi
	inc rsi
	cmp [rsi] , byte 0
	jne loop

end:
	mov [rdi], byte 0
	ret