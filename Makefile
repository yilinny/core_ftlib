FLAGS = -Wall -Werror -Wextra
OBJS = ft_mems.o ft_strlen.o ft_ctype.o ft_alpha.o ft_last.o ft_additional.o ft_itoa.o
LFLAGS = -L. -lft

.PHONY: clean
all: test_prog

test_prog: test.o libft.a
	cc test.o libft.a -o test_prog $(LFLAGS)

test.o : libft_tests.c
	cc $(FLAGS) -c libft_tests.c -o test.o

libft.a : $(OBJS)
	ar rcs libft.a $(OBJS)
	@echo "library is built"


#generic rule to compile all c files to o files 

%.o : %.c
	cc $(FLAGS) -c $< -o $@
#% is used to match a non-empty substring. To find file.o, compile using file.c. < is the first dependency while @ is the target 

test: test_prog
	./test_prog

clean:
	rm -f $(OBJS) libft.a test.o test_prog
