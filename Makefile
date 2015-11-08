

CC=gcc
RM=rm -f

CFLAGS=-Wall
LDFLAGS=-lGLU -lGL -lm -I/usr/include/python2.7 -lpython2.7 -lglut
#TARGET=cube
#OBJS=cube2.c
TARGET=cube_show
OBJS=cube_show.c
.c.o:
	${CC} -c ${CFLAGS} $<

TARGET:	${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LDFLAGS}

clean :
	${RM} ${TARGET} *.o *~
