# g++-14 -O3 -Wall -fopenmp -shared -std=c++11 -undefined dynamic_lookup $(python -m pybind11 --includes) bindings.cpp particle.cpp system.cpp  -o myvic$(python-config --extension-suffix)

CXX = g++-14
CXXFLAGS = -O3 -Wall -fopenmp -shared -std=c++11 -undefined dynamic_lookup $$(python -m pybind11 --includes) 
# PKG = $(shell pkg-config --libs --cflags sfml-all)
SRC = system.cpp particle.cpp 
OUT =  simulation
PBOUT = myvic$$(python-config --extension-suffix)

$(OUT):	$(SRC) main.cpp
	$(CXX) $(CXXFLAGS) $(PKG) $(SRC) main.cpp -o $(OUT)

pybind:	$(SRC) bindings.cpp
	$(CXX) $(CXXFLAGS) $(PKG) $(SRC) bindings.cpp -o $(PBOUT)


clean:
	rm -f $(OUT) $(PBOUT)
