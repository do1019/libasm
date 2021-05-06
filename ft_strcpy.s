; char *strcpy(char *dest, const char *src);
section .text
	global ft_strcpy

ft_strcpy:
	;mov rax, rdi		; rdi(dest) の先頭アドレスを rax にコピー。 途中で rax が変わってしまう。 
						; best なのは push で退避させること？
	;push rdi
	mov	rcx, rdi			; rcx に退避させて最後に rax に移すと問題ない。
	;cld					; movsbで代入後レジスタの値を増やすためのフラグをセット。減らす場合はstd

.loop:
	cmp byte [rsi], 0	; rsi(src) の値を0と比較。
	jne	.copy_inc		; *src != '\0' .copy_inc ラベルへジャンプ
	jmp .end			; 1つ前のジャンプが行われなかった *src == '\0' の場合に .end ラベルへ移動 

.copy_inc:
	mov byte al, [rsi]	; rsi(src)の値を al にコピー。　al レジスタ 8bitのレジスタ
						; http://wisdom.sakura.ne.jp/programming/asm/assembly3.html
	mov byte [rdi], al	; al の値を rdi(dest)の値にコピー。
	inc rsi				; rsi(src) のアドレスを1進める。
	inc rdi				; rdi(dest) のアドレスを1進める。
	;movsb				; 上4行をまとめたもの。
	jmp .loop			; .loop ラベルへジャンプ

.end:
	mov byte al, [rsi]	;'\0' までコピーするのでもう一度 rsi から rdi にコピー。
	mov byte [rdi], al
	inc rsi				; rsi(src) のアドレスを1進める。
	inc rdi				; rdi(dest) のアドレスを1進める。
	;movsb				; movsbだと動くけど上4行だと動かない。なぜ？ → mov rax, rdi で途中でraxのアドレスが変更されていたため
	mov	rax, rcx		; rcx に移しておいた rdi の先頭アドレスを rax に代入。
	;pop rax
	ret					; rax に代入したrdiの先頭アドレスが返る。

