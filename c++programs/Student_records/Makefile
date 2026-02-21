#Name of excecutable that will be made
TARGET = students
#Tell the compiler to use GNU (C++ compiler)
CXX = g++
#-wall shows warnings and -std=c++17 uses C++17 standard
CXXFLAGS = -Wall -std=c++17
#List of all the source files in the project
SRCS = students.cc main.cc
#Turn .cc to .o files
OBJS = $(SRCS:.cc=.o)
#Build all object files first before building the final program
$(TARGET): $(OBJS)
#Link all the files together into an executable
	$(CXX) $(OBJS) -o $(TARGET)
#Pattern rule (How to make .o files from .cc)
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<
#Clean rule
clean:
	rm -f $(OBJS) $(TARGET)