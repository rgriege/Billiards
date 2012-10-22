###########################################################
# Project 1 Makefile

CC = g++
CFLAGS = -g
INCLUDE =
LIBDIR =
LIBS = -lglut -lGLU -lGL -lm

###########################################################
# Options if compiling on Mac
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
CC = g++
CFLAGS = -D__MAC__
INCLUDE = 
LIBDIR = -L/lusr/X11/lib
LIBS = -framework OpenGL -framework GLUT
endif

###########################################################
# Uncomment the following line if you are using Mesa
#LIBS = -lglut -lMesaGLU -lMesaGL -lm


###########################################################

# To add a cpp file called myfile.cpp see comments below

billiards: main.o Vec2.o RigidBody.o Polygon.o Disk.o Interval.o World.o Collision.o CollisionDD.o CollisionDP.o Matrix2.o Level.o Wall.o RainbowDisk.o # myfile.o 
#	${CC} ${CFLAGS} $(INCLUDE) -o billiards main.o ${LIBDIR} ${LIBS}
	${CC} ${CFLAGS} $(INCLUDE) -o billiards main.o Vec2.o RigidBody.o Interval.o Disk.o Polygon.o World.o Collision.o CollisionDD.o CollisionDP.o Matrix2.o Level.o Wall.o RainbowDisk.o ${LIBDIR} ${LIBS} 
# replace the first line with the previous line

main.o: main.cpp Common.h Color.h Vec2.h RigidBody.h Disk.h Polygon.h World.h Level.h constants.h
	${CC} -c ${CFLAGS} $(INCLUDE) main.cpp

# add the following lines
# myfile.o: myfile.cpp myfile.h # any additional dependencies
#	 ${CC} -c ${CFLAGS} $(INCLUDE) myfile.cpp

Vec2.o: Vec2.cpp Vec2.h Common.h Matrix2.h
	${CC} -c ${CFLAGS} $(INCLUDE) Vec2.cpp

Interval.o: Interval.cpp Interval.h Common.h
	${CC} -c ${CFLAGS} $(INCLUDE) Interval.cpp

Matrix2.o: Matrix2.cpp Matrix2.h Common.h
	${CC} -c ${CFLAGS} $(INCLUDE) Matrix2.cpp

RigidBody.o: RigidBody.cpp RigidBody.h Vec2.h Color.h Interval.h
	${CC} -c ${CFLAGS} $(INCLUDE) RigidBody.cpp

Disk.o: Disk.cpp Disk.h RigidBody.h
	${CC} -c ${CFLAGS} $(INCLUDE) Disk.cpp

Polygon.o: Polygon.cpp Polygon.h RigidBody.h
	${CC} -c ${CFLAGS} $(INCLUDE) Polygon.cpp

Collision.o: Collision.cpp Collision.h RigidBody.h Vec2.h Common.h Interval.h
	${CC} -c ${CFLAGS} $(INCLUDE) Collision.cpp

CollisionDD.o: CollisionDD.cpp CollisionDD.h Disk.h Vec2.h Common.h Interval.h
	${CC} -c ${CFLAGS} $(INCLUDE) CollisionDD.cpp

CollisionDP.o: CollisionDP.cpp CollisionDP.h Disk.h Polygon.h Vec2.h Common.h Interval.h
	${CC} -c ${CFLAGS} $(INCLUDE) CollisionDP.cpp

World.o: World.cpp World.h Vec2.h Polygon.h Disk.h CollisionDD.h CollisionDP.h Collision.h Common.h
	${CC} -c ${CFLAGS} $(INCLUDE) World.cpp

Level.o: Level.cpp Level.h World.h Wall.h constants.h RainbowDisk.h
	${CC} -c ${CFLAGS} $(INCLUDE) Level.cpp

Wall.o: Wall.cpp Wall.h Polygon.h Common.h
	${CC} -c ${CFLAGS} $(INCLUDE) Wall.cpp

RainbowDisk.o: RainbowDisk.cpp RainbowDisk.h Disk.h
	${CC} -c ${CFLAGS} $(INCLUDE) RainbowDisk.cpp
clean:
	rm -f billiards *.o
