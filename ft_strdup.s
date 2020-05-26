# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strdup.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/26 15:44:29 by tim           #+#    #+#                  #
#    Updated: 2020/05/26 16:12:05 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

							section .text
							global _ft_strdup
							extern	_malloc

_ft_strdup:									; set rdi = src
			
len_start:
			xor		rcx, rcx				; i = 0
			jmp		len_compare
len_increment:
			inc		rcx						; i++
len_compare:
			cmp		BYTE [rdi + rcx], 0		; str[i] == 0
			jne		len_increment
malloc_start:
			inc		rcx						; length++
			push	rdi						; save src
			mov		rdi, rcx
			push	rbp						; stack allignment
			mov		rbp, rsp					; stack allignment
			and		rsp, - 16				; stack allignment
			call	_malloc					; rax = _malloc(length)
			mov		rsp, rbp
			pop		rbp
			cmp		rax, 0
			pop		rdi						; restore src
			cmp		rax, 0
			jz		error					; malloc return NULL
copy_start:
			xor		rcx, rcx				; i = 0
			xor		rdx, rdx				; tmp = 0
			jmp		copy_copy
copy_increment:
			inc		rcx
copy_copy:
			mov		dl, BYTE [rdi + rcx]
			mov		BYTE [rax + rcx], dl
			cmp		dl, 0
			jnz		copy_increment
			jmp		return
error:
			xor		rax, rax
return:
			ret