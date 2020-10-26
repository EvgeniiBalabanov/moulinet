OUT				= test.out

PROJECT			= libft

FUNCS			= ft_strlen ft_atoi ft_strjoin ft_strcmp ft_strncmp ft_itoa ft_isascii ft_isprint ft_isdigit ft_isalpha ft_isalnum

MAIN			= main.c

DATA			= data.csv

COMPILE			= ${PROJECT}.a

WWW				= -Wall -Wextra -Werror

add_path := $(FUNCS:%=../%/test.c)

all:		project_all create_include create_data
	gcc ${WWW} ${PATH_PROJECT}/${COMPILE} ${MAIN} $(add_path) -o ${OUT} -I ${PATH_PROJECT} -I header.h

create_data:
	> ${DATA}
	for var in ${FUNCS};\
	do\
		sed "/^/s/^/$${var} /" ../$${var}/${DATA} >> ${DATA};\
	done
# cat ../$${var}/${DATA} >> data.txt;

create_include:
	> header.h
	for var in ${FUNCS};\
	do\
		cat ../$${var}/include/header.h >> header.h;\
	done

project_all:
	cd ${PATH_PROJECT} && make

project_fclean:
	cd ${PATH_PROJECT} && make fclean

clean:
	rm -rf *.o 
	# header.h ${DATA}

fclean:			clean	project_fclean
	rm -rf ${OUT}
