# install for icon ------> brew install librsvg gnome-icon-theme <---
# install for mac  ------> brew install gtk-mac-integration <--------

#	Library output
NAME = corewar

#	GCC flags
CFLAGS = -Wall -Wextra -Werror -Ofast

# Flags for Opencl compatibility

#	Includes directories
INC_RT = includes
INCLUDES += $(addprefix -iquote , $(INC_RT))

#	Sources
RT_SOURCES = $(shell find vm | grep "\.c$$" | sed "s/\.c$$//g")
SRCS = $(addsuffix .c, $(RT_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de Corewar"
	@gcc $(OBJS) -o $(NAME) -L./libft/ -lft
	@echo "Terminée"

# To obtain object files
%.o: %.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

lftclean:
	make -C libft clean

lftfclean:
	make -C libft fclean

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push
