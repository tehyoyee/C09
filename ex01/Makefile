NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f
AR = ar
CRS = crs
SRCDIR = srcs
INCDIR = includes
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)
	
$(NAME): $(OBJS)
	$(AR) $(CRS) $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
