snake: main.o World.o Snake.o Board.o Point.o Fruit.o ChilliFruit.o Grow_fruit.o tests.o
	clang++ -std=c++11 -lncurses main.o World.o Snake.o Board.o Point.o Fruit.o ChilliFruit.o Grow_fruit.o tests.o -o Snakegame

main.o: main.cpp
	clang++ -std=c++11 -c -lncurses main.cpp

World.o: World.cpp
	clang++ -std=c++11 -c -lncurses World.cpp

Snake.o: Snake.cpp
	clang++ -std=c++11 -c -lncurses Snake.cpp

Board.o: Board.cpp
	clang++ -std=c++11 -c -lncurses Board.cpp
	
Point.o: Point.cpp
	clang++ -std=c++11 -c -lncurses Point.cpp
	
Fruit.o: Fruit.cpp
	clang++ -std=c++11 -c -lncurses Fruit.cpp

ChilliFruit.o: ChilliFruit.cpp
	clang++ -std=c++11 -c -lncurses ChilliFruit.cpp

Grow_fruit.o: Grow_fruit.cpp
	clang++ -std=c++11 -c -lncurses Grow_fruit.cpp
	
tests.o: tests.cpp
	clang++ -std=c++11 -c -lncurses tests.cpp

clean:
	rm *.o Snakegame

