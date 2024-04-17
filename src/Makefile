CC = g++	
CFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++ --coverage
PROJ_NAME = s21_matrix_oop
SRCS = $(wildcard s21_*.cc)
OBJS = $(SRCS:.cc=.o)
TESTS = ./tests/*.cc
LEAKS = leaks -atExit --

ifeq ($(shell uname), Linux)
	LEAKS = valgrind --tool=memcheck --leak-check=yes
endif

all: style test clean

$(PROJ_NAME).a: $(OBJS)
	ar rcs $@ $^
	ranlib $@
	rm -rf *.o

test: clean $(PROJ_NAME).a
	$(CC) $(CFLAGS) $(TESTS) $(PROJ_NAME).a -o ./tests/test -lgtest
	./tests/test

leaks: test
	$(LEAKS) ./tests/test

style:
	clang-format -n --style=google *.cc *.h ./tests/*.cc ./tests/*.h
	clang-format -i --style=google *.cc *.h ./tests/*.cc ./tests/*.h

cppcheck:
	cppcheck *.cc *.h tests/*.cc tests/*.h

clean:
	rm -rf *.a *.o ./tests/test ./greport ./report ./tests/*.g* test.info