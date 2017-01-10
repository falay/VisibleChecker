CC = gcc

all: Main.o Array.o linkedCell.o resList.o
	${CC} $^ -o VisChecker

%.o: %.c
	${CC} $< -c

clean:
	rm -rf *.o VisChecker