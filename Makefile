FLAGS = -pedantic-errors -std=c++11

all:main

picture.o: picture.cpp picture.h
	  g++ $(FLAGS) -c $<

uti.o: uti.cpp uti.h
	  g++ $(FLAGS) -c $<

battlesys.o: battlesys.cpp battlesys.h uti.h
	  g++ $(FLAGS) -c $<

main.o: main.cpp uti.h picture.h battlesys.h
	  g++ $(FLAGS) -c $<

main: main.o uti.o picture.o battlesys.o
	  g++ $(FLAGS) $^ -o $@

clean:
	  rm -f main main.o battlesys.o picture.o uti.o

.PHONY: clean
