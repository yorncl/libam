section	.text
	global _ft_strlen

_ft_strlen:
	mov	rax, 0

loop:
	cmp [rdi + rax], byte 0
	je end
	inc rax
	jmp loop

end:
	ret