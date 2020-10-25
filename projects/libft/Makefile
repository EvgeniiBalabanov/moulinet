OUT				= test.out

PROJECT			= libft

FUNCS			= ft_strlen ft_atoi

MAIN			= main.c

COMPILE			= ${PROJECT}.a

WWW				= -Wall -Wextra -Werror

add_path := $(FUNCS:%=../%/test.c)

all:		project_all create_include
	gcc ${WWW} ${PATH_PROJECT}/${COMPILE} ${MAIN} $(add_path) -o ${OUT} -I ${PATH_PROJECT} -I header.h

create_include:
	echo "" > header.h
	for var in ${FUNCS};\
	do\
		cat ../$${var}/include/header.h >> header.h;\
	done

project_all:
	cd ${PATH_PROJECT} && make

project_fclean:
	cd ${PATH_PROJECT} && make fclean

clean:
	rm -rf *.o header.h

fclean:			clean	project_fclean
	rm -rf ${OUT}
