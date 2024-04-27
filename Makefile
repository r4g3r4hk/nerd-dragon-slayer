FLAGS = -pedantic-errors -std=c++11

all:main

picture.o: picture.cpp picture.h
	  g++ $(FLAGS) -c $<

uti.o: uti.cpp uti.h
	  g++ $(FLAGS) -c $<

battlesys.o: battlesys.cpp battlesys.h uti.h
	  g++ $(FLAGS) -c $<
