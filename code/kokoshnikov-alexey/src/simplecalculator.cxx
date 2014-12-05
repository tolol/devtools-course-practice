// Copyright 2014 Alexey Kokoshnikov

#include "include/simplecalculator.h"

#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <string>
#include <cstdlib>
int SimpleCalculator::BinToDec(std::string bin) {
    int k = 0;
    if (bin[0] == '-') {
        bin.erase(0, 1);
        k = -1;
    } else {
        k = 1;
    }
    int dec = 0;
    int tmp = 0;
    int i = 0;
    for (int j = (static_cast<int>(bin.size()) - 1); j >= 0; j--) {
        if ((bin.c_str()[j] >= 48) && (bin.c_str()[j] <=  49)) {
               tmp = bin.c_str()[j] - 48;
        } else {
               throw std::string("Invalid parameters");
        }
        dec = dec + tmp*static_cast<int>(pow(2, i));
        if (dec < 0) {
           throw std::string("Big data");
        }
        i++;
    }
    return dec*k;
}

int SimpleCalculator::OctToDec(std::string oct) {
    int k = 0;
    if (oct[0] == '-') {
        oct.erase(0, 1);
        k = -1;
    } else {
        k = 1;
    }
    int dec = 0;
    int tmp = 0;
    int i = 0;
    for (int j = (static_cast<int>(oct.size()) - 1); j >= 0; j--) {
        if ((oct.c_str()[j] >= 48) && (oct.c_str()[j] <=  55)) {
               tmp = oct.c_str()[j] - 48;
        } else {
               throw std::string("Invalid parameters");
        }
        dec = dec + tmp*static_cast<int>(pow(8, i));
        if (dec < 0) {
           throw std::string("Big data");
        }
        i++;
    }
    return dec*k;
}

int SimpleCalculator::HexToDec(std::string hex) {
    int k = 0;
    if (hex[0] == '-') {
        hex.erase(0, 1);
        k = -1;
    } else {
        k = 1;
    }
    int dec = 0;
    int tmp = 0;
    int i = 0;
    for (int j = (static_cast<int>(hex.size()) - 1); j >= 0; j--) {
        if ((hex.c_str()[j] >= 48) && (hex.c_str()[j] <=  57)) {
               tmp = hex.c_str()[j] - 48;
        } else if ((hex.c_str()[j] >= 97) && (hex.c_str()[j] <=  102)) {
                      tmp = hex.c_str()[j] - 87;
               } else {
                       throw std::string("Invalid parameters");
               }
        dec = dec + tmp*static_cast<int>(pow(16, i));
        if (dec < 0) {
           throw std::string("Big data");
        }
        i++;
    }
    return dec*k;
}

std::string SimpleCalculator::DecToBin(int dec) {
    char k = '0';
    if (dec == abs(dec)) {
        dec = abs(dec);
    } else {
        dec = abs(dec);
        k = '-';
    }
    std::string bin;
    std::string bin_tmp;
    std::string tmp;
    int tmp_dec = 0;
    while (dec > 0) {
        tmp_dec = dec%2;
        tmp = std::to_string(tmp_dec);
        dec = dec/2;
        bin_tmp = bin;
        bin = tmp + bin_tmp;
    }
    if (k == '-') {
        bin_tmp = bin;
        tmp = "-";
        bin = tmp + bin_tmp;
    }
    return bin;
}

std::string SimpleCalculator::DecToOct(int dec) {
    char k = '0';
    if (dec == abs(dec)) {
        dec = abs(dec);
    } else {
        dec = abs(dec);
        k = '-';
    }
    std::string oct;
    std::string oct_tmp;
    std::string tmp;
    int tmp_dec = 0;
    while (dec > 0) {
        tmp_dec = dec%8;
        tmp = std::to_string(tmp_dec);
        dec = dec/8;
        oct_tmp = oct;
        oct = tmp + oct_tmp;
    }
    if (k == '-') {
        oct_tmp = oct;
        tmp = "-";
        oct = tmp + oct_tmp;
    }
    return oct;
}

std::string SimpleCalculator::DecToHex(int dec) {
    char k = '0';
    if (dec == abs(dec)) {
        dec = abs(dec);
    } else {
        dec = abs(dec);
        k = '-';
    }
    std::string hex;
    std::string hex_tmp;
    std::string tmp;
    int tmp_dec = 0;
    while (dec > 0) {
        tmp_dec = dec%16;
        tmp = std::to_string(tmp_dec);
        dec = dec/16;
        if ((tmp_dec >= 0) && (tmp_dec <=  9)) {
               hex_tmp = hex;
               hex = tmp + hex_tmp;
        } else if ((tmp_dec >= 10) && (tmp_dec <=  15)) {
               tmp = static_cast<char>(tmp_dec + 87);
               hex_tmp = hex;
               hex = tmp + hex_tmp;
               }
    }
    if (k == '-') {
        hex_tmp = hex;
        tmp = "-";
        hex = tmp + hex_tmp;
    }
    return hex;
}
std::string SimpleCalculator::BinToHex(std::string bin) {
    int dec = BinToDec(bin);
    return DecToHex(dec);
}
std::string SimpleCalculator::BinToOct(std::string bin) {
    int dec = BinToDec(bin);
    return DecToOct(dec);
}
std::string SimpleCalculator::HexToBin(std::string hex) {
    int dec = HexToDec(hex);
    return DecToBin(dec);
}
std::string SimpleCalculator::OctToBin(std::string oct) {
    int dec = OctToDec(oct);
    return DecToBin(dec);
}

