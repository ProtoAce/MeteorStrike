all: compile link

compile:
	g++ -I src/include -c main.cpp spaceship.cpp game.cpp bullet.cpp meteorite.cpp score.cpp explosion.cpp mainMenu.cpp settings.h

link:
	g++ main.o spaceship.o game.o bullet.o meteorite.o score.o explosion.o mainMenu.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system