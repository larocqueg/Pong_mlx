# The name of the lib
NAME = libft.a

# Compiler
CC = cc

# Compiling flags
CFLAGS = -Wall -Wextra -Werror
LFLAGS =
SRC_DIR = .
PRINTF_DIR = ./ft_printf
FPRINTF_DIR = ./ft_fprintf
GNL_DIR = ./get_next_line

# Source files
SRCS =	$(SRC_DIR)/ft_atoi.c \
		$(SRC_DIR)/ft_atoll.c \
		$(SRC_DIR)/ft_bzero.c \
		$(SRC_DIR)/ft_calloc.c \
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memset.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_strlcpy.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_toupper.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_substr.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_strndupmod.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_itoa.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_lstnew.c \
		$(SRC_DIR)/ft_lstadd_front.c \
		$(SRC_DIR)/ft_lstsize.c \
		$(SRC_DIR)/ft_lstlast.c \
		$(SRC_DIR)/ft_lstadd_back.c \
		$(SRC_DIR)/ft_lstdelone.c \
		$(SRC_DIR)/ft_lstclear.c \
		$(SRC_DIR)/ft_lstiter.c \
		$(SRC_DIR)/ft_lstmap.c \
		$(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putchar.c \
		$(PRINTF_DIR)/ft_putnbr_base.c \
		$(PRINTF_DIR)/ft_putpointer.c \
		$(PRINTF_DIR)/ft_putstr.c \
		$(PRINTF_DIR)/ft_strchar.c \
		$(FPRINTF_DIR)/ft_fprintf.c \
		$(FPRINTF_DIR)/ft_fputchar.c \
		$(FPRINTF_DIR)/ft_fputnbr_base.c \
		$(FPRINTF_DIR)/ft_fputpointer.c \
		$(FPRINTF_DIR)/ft_fputstr.c \
		$(FPRINTF_DIR)/ft_fstrchar.c \
		$(GNL_DIR)/get_next_line.c \

# Object files
OBJS = $(SRCS:.c=.o)

# all rule
all: $(NAME)
	@echo "Checking if $(NAME) was created..."
	@test -f $(NAME) && echo "$(NAME) successfully built!" || echo "Error: $(NAME) not found!"

# Compile the lib
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Compile the object files
%.o: %.c
	@$(CC) $(CFLAGS) -I $(SRC_DIR) -I $(PRINTF_DIR) -I $(FPRINTF_DIR) -I $(GNL_DIR) $ -c $< -o $@

# clean rule removes .o from srcs
clean:
	@rm -rf $(OBJS)

# fclean rule runs clean then removes libft.a
fclean: clean
	@rm -rf $(NAME)

# re rule runs fclean then runs make again
re: fclean
	make

# Avoid name clashes
.PHONY: all clean fclean re bonus

