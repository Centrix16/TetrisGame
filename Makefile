all:
	g++ main.cpp -o main `pkg-config --libs --static --cflags sfml-graphics`
rm:
	rm -f main
