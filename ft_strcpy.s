# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcpy.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/01 15:39:49 by tim           #+#    #+#                  #
#    Updated: 2020/05/05 14:33:05 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

				section .text
                global  _ft_strcpy

_ft_strcpy:		
			xor		rcx, rcx			; dst = rdi, src = rsi
			xor		rdx, rdx			; tmp = 0
			jmp		copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx] ;move src to dst
			mov		BYTE [rdi + rcx], dl ; 
			cmp		dl, 0				 ; 
			jnz		increment
return:
			mov		rax, rdi				; return dst
			ret