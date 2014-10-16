.globl zfunction
zfunction:
	push %ebp
	mov %esp, %ebp
	mov 8(%ebp), %eax
	and $0xFFF00FFF, %eax
	shr $0x4, %eax
	pop %ebp
	ret
