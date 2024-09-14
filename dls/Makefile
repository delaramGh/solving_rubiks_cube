CXX = g++
CXXFLAGS = -std=c++17 -Wall -I h -c
LXXFLAGS = -std=c++17 -Ih -pthread
OBJECTS = ./obj/cube.o ./obj/dls.o ./obj/main.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
./obj/cube.o: ./cpp/cube.cpp
	$(CXX) $(CXXFLAGS) ./cpp/cube.cpp -o ./obj/cube.o
./obj/dls.o: ./cpp/dls.cpp
	$(CXX) $(CXXFLAGS) ./cpp/dls.cpp -o ./obj/dls.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
