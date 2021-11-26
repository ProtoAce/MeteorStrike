all: compile link

compile:
	g++ -I src/include -c main.cpp spaceship.cpp game.cpp bullet.cpp meteorite.cpp score.cpp explosion.cpp mainMenu.cpp settings.cpp highscores.cpp background.cpp powerUps.cpp shield.cpp gameMusic.cpp constants.h

link:
	g++ main.o spaceship.o game.o bullet.o meteorite.o score.o explosion.o mainMenu.o settings.o highscores.o background.o powerUps.o shield.o gameMusic.o -o MeteorStrike -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio

clean:
	rm -f main main.exe *.o