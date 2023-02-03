all:
	g++ Graph.cpp Dijkstra.cpp -o ./dijkstra.out

clean:
	rm *.out
