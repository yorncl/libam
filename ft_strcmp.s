global ft_strcmp

section .text

ft_strcmp:
	mov rax, [rdi]
	mov rcx, [rsi]
	cmp al, cl
	jne end
	cmp cl, byte 0
	je end
	inc rdi
	inc rsi
	jmp ft_strcmp


end:
	sub al, cl
	cmp al, 0
	jg putone
	jl putminusone
	ret

putone:
	mov rax, 1
	ret

putminusone:
	mov rax, -1
	ret