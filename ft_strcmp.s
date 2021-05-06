; int strcmp(const char *s1, cont char *s2)
; s1 = rdi, s2 = rsi
section .text
	global ft_strcmp

ft_strcmp:
	mov byte bl, [rdi]	; rdi の先頭の値(1byte)を bl にコピー
	mov byte cl, [rsi]	; rsi の先頭の値(1byte)を cl にコピー
	cmp byte bl, cl		; byte 同士の比較は al 等の8bit レジスタに入れなきゃダメ？
	jne .end			; [rdi] != [rsi] であれば .end にジャンプ。
	cmp byte bl, 0
	je .end				; [rdi] == '\0' であれば .end にジャンプ。
	inc rdi
	inc	rsi
	jmp ft_strcmp

.end:
	sub bl, cl			; bl = bl - cl
	movsx rax, bl		; bl の値を rax に格納
						; movsx : レジスタ、またはメモリをより大きなサイズ（たとえば 8 ビットから 64 ビット）に符号拡張する命令。
						; rax は64bit bl は8bit
	ret