global ft_strcmp

section .text

zero:
	cmp cl, byte 0
	je end
	inc rdi
	inc rsi

ft_strcmp:
	mov al, [rdi]
	mov cl, [rsi]
	cmp al, cl
	je zero

end:
	ret