# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_read.s                                          :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/05 17:17:57 by tim           #+#    #+#                  #
#    Updated: 2020/05/05 17:56:22 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_read

; delete all unpreserved registers by _read

_ft_read:								
			mov		rax, 0x2000003	; delete all unpreserved registers by _read
			syscall					; fd = rdi, buffer = rsi, bytes = rdx
			jc 		error			; if read returns an error
			ret

error:		
			mov rax, -1				; if read returned an error -1 is returned