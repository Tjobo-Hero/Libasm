# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_read.s                                          :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/05 17:17:57 by tim           #+#    #+#                  #
#    Updated: 2020/05/25 11:26:02 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_read
			extern	__error

; delete all unpreserved registers by _read

_ft_read:								
			mov		rax, 0x2000003	; delete all unpreserved registers by _read
			syscall					; bytes = rdx, fd = rdi, buffer = rsi
			jc 		error			; in case of an error read return -1
			ret

error:		mov 	r10, rax
			call	__error
			mov 	[rax], r10		; if read returned an error -1 is returned
			mov		rax, -1
			ret

