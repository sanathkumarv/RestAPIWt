all: cli
Libs=-lpthread -lmongoclient -lboost_thread -lboost_system -lboost_regex -lstdc++ -lm -lpthread
cli: cli.o
	gcc -o cli cli.o $(Libs)

