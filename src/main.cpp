// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char *s1 = "sun rain w1nd cloud st0rm sky";
    const char *s2 = "Moscow London paris New york Berlin";
    const char *s3 = "war and peace";

    std::cout << "faStr1: слова без цифр в \"" << s1 << "\": "
              << faStr1(s1) << std::endl;
    std::cout << "faStr2: слова с заглавной в \"" << s2 << "\": "
              << faStr2(s2) << std::endl;
    std::cout << "faStr3: средняя длина в \"" << s3 << "\": "
              << faStr3(s3) << std::endl;
    return 0;
}
