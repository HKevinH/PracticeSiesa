
#include "pch.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


inline std::string convertToBase(int num, int base) {
    if (base < 2 || base > 16) {
        return "Base no soportada.";
    }

    std::string result;
    std::string baseDigits = "0123456789ABCDEF";

    do {
        int remainder = num % base;
        result = baseDigits[remainder] + result; // Prepend the corresponding base digit.
        num /= base;
    } while (num > 0);

    return result;
}