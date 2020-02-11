section .text
	global _ft_strcmp

zero:
	cmp cl, byte 0
	je end
	inc rdi
	inc rsi

_ft_strcmp:
	mov al, [rdi]
	mov cl, [rsi]
	cmp al, cl
	je zero

end:
	ret