# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 11:05:27 by guphilip          #+#    #+#              #
#    Updated: 2025/02/03 17:04:18 by guphilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands

RM		= /usr/bin/rm -f
ECHO	= /usr/bin/echo

# Directories

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INC_DIR = includes
LIB_DIR = libs
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

# Couleurs && Personnalisation

BLUE 			= \033[1;34m
GREEN			= \033[1;32m
RESET			= \033[0m

RM_LINE 		= @tput cuu1 && tput el

# LIBFT

LIBFT_GIT = https://github.com/LaGuibole/Libft_Boosted.git
LIBFT_DIR = Libft_Boosted
LIBFT_PATH = $(LIB_DIR)/$(LIBFT_DIR)
LIBFT_H = libft.h
LIBFT_H_PATH = $(LIBFT_PATH)/includes/$(LIBFT_H)
LIBFT_INC_H = $(INC_DIR)/$(LIBFT_H)
LIBFT_TARGET = libft.a
LIBFT_TARGET_PATH = $(LIBFT_PATH)/$(LIBFT_TARGET)

# PIPEX

SRC_FILES = pipex pipex_errors pipex_paths 
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# PIPEX BONUS
BONUS_SRC_FILES = pipex_bonus pipex_bonus_errors pipex_bonus_utils
BONUS_SRC = $(addprefix $(SRC_BONUS_DIR)/, $(addsuffix .c, $(BONUS_SRC_FILES)))
BONUS_OBJS = $(addprefix $(OBJ_BONUS_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))
# TARGET

NAME = pipex
BONUS_NAME = pipex_bonus

# FLAGS && COMPIL

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I$(INC_DIR)

.PHONY: all re clean fclean cleanlibs fcleanlibs relibs norminette

all: $(NAME)

# PIPEX TARGET

$(NAME): $(LIBFT_INC_H) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	@echo "$(BLUE) $(NAME) cree. $(RESET)"

# PIPEX BONUS TARGET

$(BONUS_NAME): $(LIBFT_INC_H) $(BONUS_OBJS) $(OBJ_DIR)/pipex_errors.o $(OBJ_DIR)/pipex_paths.o
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(OBJ_DIR)/pipex_errors.o $(OBJ_DIR)/pipex_paths.o $(LIBFT_TARGET)
	@echo "$(BLUE) $(BONUS_NAME) cree. $(RESET)"

# OBJECT DIR

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

# COMPILE REGULAR .O FILES

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $< into $@ ..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@${RM_LINE}

# COMPILE BONUS .O FILES
$(OBJ_BONUS_DIR)/%.o : $(SRC_BONUS_DIR)/%.c
	@echo "Compiling $< into $@ ..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@${RM_LINE}

clean:
	$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

cleanlibs:
	$(MAKE) clean -C $(LIBFT_PATH)

fcleanlibs:
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(LIBFT_TARGET)
	$(RM) $(LIBFT_INC_H)

relibs: fcleanlibs $(LIBFT_INC_H)

re: fclean relibs all

bonus: $(BONUS_NAME)

norminette:
	@norminette $(SRC_DIR) $(BONUS_SRC) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
	&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
	|| $(ECHO) -e '\033[1;32mNorminette OK!'

# Binary compilation

# Libs compilation

# $@ prend le nom de la regle
$(LIBFT_INC_H): $(LIBFT_TARGET)
	@cp $(LIBFT_H_PATH) $@

$(LIBFT_TARGET):
	@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
		printf "Cloning lib \"%s\" into \"%s\"..." $(LIBFT_GIT) $(LIBFT_PATH);\
		git clone $(LIBFT_GIT) $(LIBFT_PATH);\
	fi
	@printf "Making \"%s\"..." $@
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT_TARGET_PATH) ./
	@printf "Done copying archive \"%s\"..." $@
