.SILENT:
FROM_RE = 0

SRC = ./src/main.c

OBJ_DIR = obj/
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))

NAME = minishell

GCC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

MESSAGE_ALL = "All files are compiled."
MESSAGE_ALREADY = "All files are already up-to-date."
MESSAGE_C = "All files are clean."
MESSAGE_FC = "All files and name are clean."

yellow = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) subsystems
	@$(GCC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@$(MAKE) title
	@echo "$(yellow)"
	@echo "$(MESSAGE_ALL)"
	@echo "$(RESET)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(GCC) $(CFLAGS) -c -o $@ $<

subsystems:
	@$(MAKE) -C $(LIBFT_PATH) all

# si tu veux desactiver le ascii Art il faut simplement enlever cette ligne "$(MAKE) title; \" dans les clean, fclean et all

title:
	@echo "$(yellow)"
	@sleep 0.1 && echo "███╗   ███╗ ██╗ ███╗   ██╗ ██╗  ██████╗ ██╗  ██╗ ███████╗██╗      ██╗"
	@sleep 0.1 && echo "████╗ ████║ ██║ ████╗  ██║ ██║ ██╔════╝ ██║  ██║ ██╔════╝██║      ██║"
	@sleep 0.1 && echo "██╔████╔██║ ██║ ██╔██╗ ██║ ██║ ╚█████╗  ███████║ █████╗  ██║      ██║"
	@sleep 0.1 && echo "██║╚██╔╝██║ ██║ ██║╚██╗██║ ██║  ╚═══██╗ ██╔══██║ ██╔══╝  ██║      ██║"
	@sleep 0.1 && echo "██║ ╚═╝ ██║ ██║ ██║ ╚████║ ██║ ██████╔╝ ██║  ██║ ███████╗███████╗ ███████╗"
	@sleep 0.1 && echo "╚═╝     ╚═╝ ╚═╝ ╚═╝  ╚═══╝ ╚═╝ ╚═════╝  ╚═╝  ╚═╝ ╚══════╝╚══════╝ ╚══════╝"
	@sleep 0.1 && echo "               Welcome to minishell !               "
	@echo "$(RESET)"

clean:
	@if [ -d "$(OBJ_DIR)" ] && [ "$$(ls -A $(OBJ_DIR))" ]; then \
		$(MAKE) title; \
		$(MAKE) -C $(LIBFT_PATH) clean; \
		rm -rf $(OBJ_DIR); \
		echo "$(yellow)"; \
		echo "$(MESSAGE_C)"; \
		echo "$(RESET)"; \
	else \
		echo "$(yellow)"; \
		echo "Already clean."; \
		echo "$(RESET)"; \
	fi

fclean:
	@if [ -f "$(NAME)" ] || [ -d "$(OBJ_DIR)" ]; then \
		if [ "$(FROM_RE)" = "0" ]; then \
			$(MAKE) title; \
		fi; \
		$(MAKE) -C $(LIBFT_PATH) fclean; \
		rm -f $(NAME); \
		rm -rf $(OBJ_DIR); \
		echo "$(yellow)"; \
		echo "$(MESSAGE_FC)"; \
		echo "$(RESET)"; \
	else \
		if [ "$(FROM_RE)" = "0" ]; then \
			echo "$(yellow)"; \
			echo "Nothing to fclean."; \
			echo "$(RESET)"; \
		fi; \
	fi

re:
	$(MAKE) fclean FROM_RE=1
	$(MAKE) all

.PHONY: all clean fclean re title subsystems
