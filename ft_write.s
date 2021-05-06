; ssize_t ft_write(int fd, const void *buf, size_t count);
; fd = rdi, buf = rsi, count = rdx
section .text
	extern __errno_location
	global ft_write

ft_write:			; https://www.mztn.org/lxasm64/x86_x64_table.html
	mov	rax, 1		; システムコールを利用するために、システムコール番号1(write, 32/64bitで数字は異なる)を rax に入れる。
	syscall			; syscall で rax に入っている番号に対応するシステムコールが呼ばれる。
	cmp	rax, 0		; syscall の戻り値と0を比較
	jl	.error		; rax が0より小さければ(syscall write がエラーだったら) .error ラベルにジャンプ
	jmp .end

.error:
	neg rax			; オペランドの値を2の補数に置き換える。(正負を反転させる。)
	push rax		; スタックに rax(write の返り値)を積む。
	call __errno_location wrt ..plt ; errno を呼び出す。 スタックに積んだraxを引数に取る。errno (rax) 
									; pltのfunctionを呼び出す。 https://keichi.dev/post/plt-and-got/
									; PLT (Procedure Linkage Table): アプリケーションから直接呼ばれる．GOTから対応する共有ライブラリ関数のアドレスを取得し，間接ジャンプする．
	pop qword [rax]	; スタックから qword(8byte,64bit)分の rax の値を読み込む。
	mov rax, -1

.end:
	ret