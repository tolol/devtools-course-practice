// Copyright 2014 Alexey Kokoshnikov
#include <string>
#ifndef CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_
#define CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_

class SimpleCalculator {
 public:
    std::string BinToHex(std::string bin);
    std::string BinToOct(std::string bin);
    std::string HexToBin(std::string hex);
    std::string OctToBin(std::string Oct);
 private:
    int BinToDec(std::string bin);
    int OctToDec(std::string oct);
    int HexToDec(std::string hex);
    std::string DecToBin(int dec);
    std::string DecToOct(int dec);
    std::string DecToHex(int dec);
};

#endif  // CODE_KOKOSHNIKOV_ALEXEY_INCLUDE_SIMPLECALCULATOR_H_
