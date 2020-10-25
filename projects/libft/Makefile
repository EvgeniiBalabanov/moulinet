OUT				= test.out

PROJECT			= libft

FUNCS			= ft_strlen ft_atoi

MAIN			= main.c

COMPILE			= ${PROJECT}.a

WWW				= -Wall -Wextra -Werror

all:		project_all create_include
	gcc ${WWW} ${PATH_PROJECT}/${COMPILE} ${MAIN} ../ft_strlen/test.c ../ft_atoi/test.c -o ${OUT} -I ${PATH_PROJECT} -I header.h

create_include:
	echo "" > header.h
	cat ../ft_strlen/include/header.h >> header.h
	cat ../ft_atoi/include/header.h >> header.h

project_all:
	cd ${PATH_PROJECT} && make

project_fclean:
	cd ${PATH_PROJECT} && make fclean

clean:
	rm -rf *.o header.h

fclean:			clean	project_fclean
	rm -rf ${OUT}
