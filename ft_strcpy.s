section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, rdi

loop;
	mov [rdi] [rsi]
	inc rdi
	inc rsi
	cmp [rdi] , byte 0
	je end
	jmp loop

end;
	mov [rdi] [rsi]
	ret