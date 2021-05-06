; char *strdup(const char *s);
; s = rdi
section .text
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	global ft_strdup

ft_strdup:
	mov rbx, rdi			; s を rbx にコピー
	call ft_strlen			; ft_strlen を呼び、返り値が rax に格納される
	inc rax					; ft_strlen の返り値をヌル文字分増やす
	mov rdi, rax			; malloc の引数にするために rax を rdi にコピー
	call malloc wrt ..plt	; malloc を呼ぶ
	cmp rax, 0				; メモリが足りなくてmallocが落ちた場合の確認
	je .error_end			; rax == NULL だったら .error_end にジャンプ
	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy			; ft_strcpy を呼ぶ
	ret

.error_end:
	mov rax, 12				; ENOMEM 12 を rax にセット
	push rax
	call __errno_location wrt ..plt
	pop qword [rax]
	xor rax, rax			; rax を 0(NULL)に初期化
	ret
