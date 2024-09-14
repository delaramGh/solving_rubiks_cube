CXX = g++
CXXFLAGS = -std=c++17 -Wall -I h -c
LXXFLAGS = -std=c++17 -Ih -pthread
OBJECTS = ./obj/cube.o ./obj/bidirectional.o ./obj/main.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
./obj/cube.o: ./cpp/cube.cpp
	$(CXX) $(CXXFLAGS) ./cpp/cube.cpp -o ./obj/cube.o
./obj/bidirectional.o: ./cpp/bidirectional.cpp
	$(CXX) $(CXXFLAGS) ./cpp/bidirectional.cpp -o ./obj/bidirectional.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
