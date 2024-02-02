# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 06:34:58 by aamardou          #+#    #+#              #
#    Updated: 2024/02/02 01:43:53 by aamardou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = minishell

LIBFT =	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c \
			libft/ft_bzero.c libft/ft_memcpy.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
			libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_calloc.c libft/ft_strdup.c \
			libft/ft_atoi.c libft/ft_substr.c libft/ft_memcmp.c libft/ft_strtrim.c libft/ft_strjoin.c libft/ft_itoa.c libft/ft_strmapi.c \
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_split.c libft/ft_striteri.c \
			libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
			libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstlast.c\

SRCS  =	srcs/minishell.c \
			srcs/utils/initializer.c srcs/utils/cleaner.c srcs/utils/printer.c \
			srcs/utils/signals.c srcs/utils/error.c \
			srcs/lexer/lexer.c srcs/lexer/tokens.c srcs/lexer/utils.c \
			srcs/parser/parser.c srcs/parser/tokens_handler.c srcs/parser/tokens_utils.c \
			srcs/parser/parser_utils.c srcs/parser/parser_utils2.c srcs/parser/parser_utils3.c \
			srcs/parser/parser_utils4.c srcs/parser/parser_utils5.c srcs/parser/heredoc_handler.c  \
			srcs/builtins/builtins.c srcs/builtins/echo.c srcs/builtins/ft_unset.c  \
			srcs/builtins/ft_export.c srcs/builtins/ft_export2.c srcs/builtins/ft_export3.c \
			srcs/builtins/pwd.c srcs/builtins/env.c srcs/builtins/exit.c srcs/builtins/cd.c \
			srcs/execution/execution.c srcs/execution/execution_utils.c \
			srcs/execution/execution_utils2.c srcs/execution/execution_utils3.c \

LIBFT_OBJS = $(LIBFT:.c=.o)

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(FLAGS) -I ~/.brew/opt/readline/include/ -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(OBJS)
	$(CC) $(FLAGS) -lreadline -L ~/.brew/opt/readline/lib $(LIBFT_OBJS) $(OBJS) -o $(NAME)

clean:
	rm -f $(LIBFT_OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
