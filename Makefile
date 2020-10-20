NAME	= moulinet

WWW		= -Wall -Wextra -Werror

all:
	gcc ${WWW} -o ${NAME} -fPIC src/*  -I include/