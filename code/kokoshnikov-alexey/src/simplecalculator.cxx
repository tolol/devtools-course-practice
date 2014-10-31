// Copyright 2014 Alexey Kokoshnikov

#include "include/simplecalculator.h"

#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <string>
#include <cstdlib>
SimpleCalculator::SimpleCalculator() {}
SimpleCalculator::~SimpleCalculator() {}

int SimpleCalculator::BinToDec(int bin) {
    int k = 0;
    if (bin == abs(bin)) {
        bin = abs(bin);
        k = 1;
    } else {
        bin = abs(bin);
        k = -1;
    }
    int dec = 0;
    int tmp = 0;
    int i = 0;
    while ((bin/10) > 0) {
        tmp = bin%10;
        if (tmp > 1) {
            return 0;
        }
        tmp = tmp*static_cast<int>(pow(2, i));
        dec = dec + tmp;
        bin = bin/10;
        i++;
    }
    tmp = bin;
    if (tmp > 1) {
        return 0;
    }
    tmp = tmp*static_cast<int>(pow(2, i));
    dec = dec + tmp;
    return dec*k;
}

int SimpleCalculator::OctToDec(int oct) {
    int k = 0;
    if (oct == abs(oct)) {
        oct = abs(oct);
        k = 1;
    } else {
        oct = abs(oct);
        k = -1;
    }
    int dec = 0;
    int tmp = 0;
    int i = 0;
    while ((oct/10) > 0) {
        tmp = oct%10;
        if (tmp > 7) {
            return 0;
        }
        tmp = tmp*static_cast<int>(pow(8, i));
        dec = dec + tmp;
        oct = oct/10;
        i++;
    }
    tmp = oct;
    if (tmp > 7) {
        return 0;
    }
    tmp = tmp*static_cast<int>(pow(8, i));
    dec = dec + tmp;
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
        switch (hex.c_str()[j]) {
        case '0': {
            tmp = 0;
            break;
        }
        case '1': {
            tmp = 1;
            break;
        }
        case '2': {
            tmp = 2;
            break;
        }
        case '3': {
            tmp = 3;
            break;
        }
        case '4': {
            tmp = 4;
            break;
        }
        case '5': {
            tmp = 5;
            break;
        }
        case '6': {
            tmp = 6;
            break;
        }
        case '7': {
            tmp = 7;
            break;
        }
        case '8': {
            tmp = 8;
            break;
        }
        case '9': {
            tmp = 9;
            break;
        }
        case 'a': {
            tmp = 10;
            break;
        }
        case 'b': {
            tmp = 11;
            break;
        }
        case 'c': {
            tmp = 12;
            break;
        }
        case 'd': {
            tmp = 13;
            break;
        }
        case 'e': {
            tmp = 14;
            break;
        }
        case 'f': {
            tmp = 15;
            break;
        }
        default: return 0;
        }
        dec = dec + tmp*static_cast<int>(pow(16, i));
        i++;
    }
    return dec*k;
}

int SimpleCalculator::DecToBin(int dec) {
    int k = 0;
    if (dec == abs(dec)) {
        dec = abs(dec);
        k = 1;
    } else {
        dec = abs(dec);
        k = -1;
    }
    int bin = 0;
    int tmp = 0;
    int i = 0;
    while (dec > 0) {
        tmp = dec%2;
        dec = dec/2;
        bin = bin + tmp*static_cast<int>(pow(10, i));
        i++;
    }
    return bin*k;
}

int SimpleCalculator::DecToOct(int dec) {
    int k = 0;
    if (dec == abs(dec)) {
        dec = abs(dec);
        k = 1;
    } else {
        dec = abs(dec);
        k = -1;
    }
    int oct = 0;
    int tmp = 0;
    int i = 0;
    while (dec > 0) {
        tmp = dec%8;
        dec = dec/8;
        oct = oct + tmp*static_cast<int>(pow(10, i));
        i++;
    }
    return oct*k;
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
        switch (tmp_dec) {
        case 0: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 1: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 2: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 3: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 4: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 5: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 6: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 7: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 8: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 9: {
            hex_tmp = hex;
            hex = tmp + hex_tmp;
            break;
        }
        case 10: {
            hex_tmp = hex;
            tmp = "a";
            hex = tmp + hex_tmp;
            break;
        }
        case 11: {
            hex_tmp = hex;
            tmp = "b";
            hex = tmp + hex_tmp;
            break;
        }
        case 12: {
            hex_tmp = hex;
            tmp = "c";
            hex = tmp + hex_tmp;
            break;
        }
        case 13: {
            hex_tmp = hex;
            tmp = "d";
            hex = tmp + hex_tmp;
            break;
        }
        case 14: {
            hex_tmp = hex;
            tmp = "e";
            hex = tmp + hex_tmp;
            break;
        }
        case 15: {
            hex_tmp = hex;
            tmp = "f";
            hex = tmp + hex_tmp;
            break;
        }
        }
    }
    if (k == '-') {
        hex_tmp = hex;
        tmp = "-";
        hex = tmp + hex_tmp;
    }
    return hex;
}
std::string SimpleCalculator::BinToHex(int bin) {
    int dec = BinToDec(bin);
    return DecToHex(dec);
}
int SimpleCalculator::BinToOct(int bin) {
    int dec = BinToDec(bin);
    return DecToOct(dec);
}
int SimpleCalculator::HexToBin(std::string hex) {
    int dec = HexToDec(hex);
    return DecToBin(dec);
}
int SimpleCalculator::OctToBin(int oct) {
    int dec = OctToDec(oct);
    return DecToBin(dec);
}

