# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_write.s                                         :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 11:06:02 by tim           #+#    #+#                  #
#    Updated: 2020/05/25 11:32:27 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_write
			extern	__error

; delete all unpreserved registers by _write

_ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x2000004
			syscall
			jc		error
			ret
			
error:		mov		rax, -1
			ret