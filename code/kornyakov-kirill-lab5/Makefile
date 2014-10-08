all:
	mkdir -p ./build
	$(CXX) -o ./build/calc ./sample/calc.cpp ./library/src/simplecalc.cxx ./library/src/calc_application.cxx -I./

test: all
	./build/calc
