# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrusts@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/20 11:05:23 by alkrusts      #+#    #+#                  #
#    Updated: 2020/07/11 17:41:33 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = GNL 

HEADER = get_next_line.h

CFLAGS = -Wall -Werror -Wextra -g 

SRC = get_next_line.c get_next_line_utils.c 

SRC_OBJ = $(SRC:.c=.o)

#BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_lstsize.c ft_lstlast.c

#BONUS_OBJ = $(BONUS_SRC:.c=.o)

#ifdef WITH_BONUS
#	OBJ = $(SRC_OBJ) $(BONUS_OBJ)
#else
#	OBJ = $(SRC_OBJ)
#endif

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(SRC_OBJ) -g -o $(NAME) 

#bonus:
#	$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
