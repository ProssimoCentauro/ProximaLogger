#Declarations
NAME = proximaLogger.a
HEADERSF = ./includes/
SRCSF = ./srcs/
INITF = ./srcs/logger_init_funcs/

#Main sourcers
SRCS = $(SRCSF)log_write.c $(INITF)create_logger.c

#Variables to convert SRCS and BONUS *.c in *.o (object files)
OBJS = $(SRCS:.c=.o)

#Flags
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
IFLAG = -I $(HEADERSF)

#All files must exist
$(NAME): $(OBJS)
	$(AR) $@ $^

#Every *.c must be compiled in *.o files
%.o: %.c
	$(CC) $(CFLAGS) $(IFLAG) -c $< -o $@

#Main target (Executed if the user execute make)
all: $(NAME)

#Rule that delete all the *.o files
clean:
	$(RM) $(OBJS)

#Rule that delete all the *.o files and also $(NAME)
fclean: clean
	$(RM) $(NAME)

#Rule that compile everything with new files and no cached one
re: fclean all

.PHONY: all clean fclean re

