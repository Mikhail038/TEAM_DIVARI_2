all: DO

DO: model.o experiment.o precision_analysys.o
	g++ model.o experiment.o  precision_analysys.o -o radioactivity

model.o: model.cpp
	g++ -c -o model.o model.cpp

experiment.o: experiment.cpp
	g++ -c -o experiment.o experiment.cpp

precision_analysys.o: precision_analysys.cpp
	g++ -c -o precision_analysys.o precision_analysys.cpp
