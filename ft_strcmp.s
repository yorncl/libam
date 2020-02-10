section .text
	global _ft_strcmp

_ft_strcmp:

loop:
	mov cl, [rdi]
	mov al, [rsi] ; moving lower byte to dedicate registers
	inc rdi
	inc rsi
	sub rax, rcx ; if sub equals zero then go on
	jz loop

end:
	ret