NAME = get_next_line

NAMEBONUS = get_next_line_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = get_next_line.c get_next_line_utils.c tester.c

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c tester_bonus.c

OBJECTS = $(SOURCES:.c=.o)

OBJECTSBONUS = $(BONUS:.c=.o)

%.o : %.c
ifndef BUFFER
		$(CC) -c $(CFLAGS) $< -o $@ -I ./
else
		$(CC) -c $(CFLAGS) $< -o $@ -I ./ -D BUFFER_SIZE=$(BUFFER)
endif
	
	

.PHONY : all clean fclean re bonus buffer bonus_buffer

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJECTS) $(OBJECTSBONUS)

fclean : clean
	$(RM) $(NAME) $(NAMEBONUS)

re : fclean all

bonus : $(OBJECTSBONUS)
	$(CC) $(CFLAGS) $(OBJECTSBONUS) -o $(NAMEBONUS)

buffer : fclean $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -D BUFFER_SIZE=$(BUFFER)

bonus_buffer : fclean $(OBJECTSBONUS)
	$(CC) $(CFLAGS) $(OBJECTSBONUS) -o $(NAMEBONUS) -D BUFFER_SIZE=$(BUFFER)
