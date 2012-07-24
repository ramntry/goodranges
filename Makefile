CFLAGS = -g3

goodranges: badblocks_wrapper.o goodranges.o main.o
	g++ ${CFLAGS} $^ -o goodranges

.cpp.o:
	g++ ${CFLAGS} -c $^ -o $@
.c.o:
	g++ ${CFLAGS} -c $^ -o $@

clean:
	rm *.o

