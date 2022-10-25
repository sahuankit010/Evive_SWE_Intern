output: evive.o
	g++ evive.cpp

evive.o: evive.cpp
	g++ -c evive.cpp	

clean:
	rm *.o
