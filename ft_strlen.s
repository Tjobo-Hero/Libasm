# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strlen.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: tim <tim@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/25 11:29:51 by tim           #+#    #+#                  #
#    Updated: 2020/04/30 13:07:34 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

                section .text
                global  _ft_strlen

_ft_strlen:
                xor     rax, rax                ; i = 0
                jmp     compare
increment:
                inc     rax                     ; i++
compare:
                cmp     BYTE [rdi + rax], 0     ; str[i] == 0
                jne     increment               ; if it is not equal to termanting character
done:
                ret                             ; return the i
