// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        int space = (c == ' ' || c == '\t' || c == '\n' || c == '\r');
        int digit = (c >= '0' && c <= '9');
        switch (state) {
            case 0:
                if (!space) {
                    if (digit) state = 2;
                    else
                        state = 1;
                }
                break;
            case 1:
                if (space) {
                    count++;
                    state = 0;
                } else if (digit) {
                    state = 2;
                }
                break;
            case 2:
                if (space) state = 0;
                break;
        }
    }
    if (state == 1) count++;
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        int space = (c == ' ' || c == '\t' || c == '\n' || c == '\r');
        int upper = (c >= 'A' && c <= 'Z');
        int lower = (c >= 'a' && c <= 'z');
        switch (state) {
            case 0:
                if (!space) {
                    if (upper) state = 1;
                    else
                        state = 3;
                }
                break;
            case 1:
                if (space) {
                    count++;
                    state = 0;
                } else if (lower) {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (space) {
                    count++;
                    state = 0;
                } else if (!lower) {
                    state = 3;
                }
                break;
            case 3:
                if (space) state = 0;
                break;
        }
    }
    if (state == 1 || state == 2) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int words = 0;
    unsigned int total = 0;
    unsigned int len = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        int space = (c == ' ' || c == '\t' || c == '\n' || c == '\r');
        switch (state) {
            case 0:
                if (!space) {
                    len = 1;
                    state = 1;
                }
                break;
            case 1:
                if (space) {
                    words++;
                    total += len;
                    state = 0;
                } else {
                    len++;
                }
                break;
        }
    }
    if (state == 1) {
        words++;
        total += len;
    }
    if (words == 0) return 0;
    return (total + words / 2) / words;
}
