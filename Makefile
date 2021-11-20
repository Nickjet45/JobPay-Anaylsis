CXX = g++
CXXFLAGS = -std=c++14 -Werror=return-type -Werror=uninitialized

OBJECTS = main.o ./header/Person.o ./header/Country.o ./header/Stats.o ./header/State.o

main: $(OBJECTS)
	$(CXX) $^ -o $@
	./$@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm *.o