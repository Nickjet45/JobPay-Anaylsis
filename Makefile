CXX = g++
CXXFLAGS = -std=c++14 -Werror=return-type -Werror=uninitialized

OBJECTS = main.o ./header/Person.o 

main: $(OBJECTS)
	$(CXX) $^ -o $@
	./$@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm *.o