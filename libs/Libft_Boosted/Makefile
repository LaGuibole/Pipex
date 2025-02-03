# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 14:59:37 by guphilip          #+#    #+#              #
#    Updated: 2025/01/30 14:59:38 by guphilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a
SRCS_DIR 		= src/
OBJS_DIR 		= obj/

# Compilateur

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -lbsd -I./includes

# Couleurs && Personnalisation

BLUE 			= \033[1;34m
GREEN			= \033[1;32m
RESET			= \033[0m

RM_LINE 		= @tput cuu1 && tput el

# Sous-Dossiers

FT_DIR 			= ft_is ft_mem ft_puts ft_str ft_to ft_lst

FT_ISDIR 		= ft_is/
FT_IS 			= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FT_MEMDIR 		= ft_mem/
FT_MEM 			= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

FT_PUTSDIR 		= ft_puts/
FT_PUTS 		= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FT_STRDIR 		= ft_str/
FT_STR 			= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr

FT_TODIR 		= ft_to/
FT_TO 			= ft_atoi ft_itoa ft_tolower ft_toupper

FT_LSTDIR 		= ft_lst/
FT_LST 			= ft_lstnew ft_lstlast ft_lstadd_back ft_lstadd_front ft_lstsize ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

# PRINTF

FT_PRINTFDIR 	= ft_printf/
FT_PRINTF 		= ft_print_c ft_print_d ft_print_p ft_print_s ft_print_u ft_print_x ft_printf

# GNL

FT_GNLDIR 		= get_next_line/
FT_GNL 			= get_next_line get_next_line_utils

SRC_FILES+=$(addprefix $(FT_ISDIR), $(FT_IS))
SRC_FILES+=$(addprefix $(FT_MEMDIR), $(FT_MEM))
SRC_FILES+=$(addprefix $(FT_PUTSDIR), $(FT_PUTS))
SRC_FILES+=$(addprefix $(FT_STRDIR), $(FT_STR))
SRC_FILES+=$(addprefix $(FT_TODIR), $(FT_TO))
SRC_FILES+=$(addprefix $(FT_LSTDIR), $(FT_LST))
SRC_FILES+=$(addprefix $(FT_PRINTFDIR), $(FT_PRINTF))
SRC_FILES+=$(addprefix $(FT_GNLDIR), $(FT_GNL))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

# REGLES DE MAKE

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(BLUE)Libraire $(NAME) creee.$(RESET)"

$(OBJS_DIR)$(FT_GNLDIR)%.o : $(SRCS_DIR)$(FT_GNLDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@echo "Compiling $< into $@ ..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@${RM_LINE}

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Libraire $(NAME) supprimee.$(RESET)"
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

