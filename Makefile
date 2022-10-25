output: evive.o
	g++ evive.cpp -o output

evive.o: evive.cpp
	g++ -c evive.cpp	

clean:
	rm *.o
