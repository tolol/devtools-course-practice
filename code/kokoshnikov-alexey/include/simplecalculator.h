// Copyright 2014 Alexey Kokoshnikov
#include <string>
#ifndef CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_
#define CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_

class SimpleCalculator {
 public:
    std::string BinToHex(int bin);
    int BinToOct(int bin);
    int HexToBin(std::string hex);
    int OctToBin(int Oct);
 private:
    int BinToDec(int bin);
    int OctToDec(int oct);
    int HexToDec(std::string hex);
    int DecToBin(int dec);
    int DecToOct(int dec);
    std::string DecToHex(int dec);
};

#endif  // CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_
