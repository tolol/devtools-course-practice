all:
    mkdir -p ./build
    $(CXX) -o ./build/calc ./library/src/simplecalc.cxx ./library/src/calc_application.cxx ./sample/calc.cpp -I./

test: all
    ./build/calc
