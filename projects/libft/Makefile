OUT				= test.out

PROJECT			= libft

MAIN			= main.c

COMPILE			= ${PROJECT}.a

WWW				= -Wall -Wextra -Werror

project_all:
	cd ${PATH_PROJECT} && make

project_fclean:
	cd ${PATH_PROJECT} && make fclean

all: project_all
	gcc ${WWW} ${PATH_PROJECT}/${COMPILE} ${MAIN} -o ${OUT}

clean:
	rm -rf *.o

fclean:			clean	project_fclean
	rm -rf ${OUT}
