global ft_strcmp

section .text

ft_strcmp:
	mov dl, [rdi]
	mov cl, [rsi]
	
	cmp dl, cl
	jne end
	
	cmp dl, byte 0
	je end
	
	inc rdi
	inc rsi
	jmp ft_strcmp


end:
	movzx rax, dl
	movzx rdx, cl
	sub rax, rdx
	cmp rax, 0
	jg putone
	jl putminusone
	mov rax, 0
	ret

putone:
	mov rax, 1
	ret

putminusone:
	mov rax, -1
	ret