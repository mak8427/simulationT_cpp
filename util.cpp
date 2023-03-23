//
// Created by Mac on 23/03/23.
//
#include "util.h"

std::random_device rd;
std::mt19937 gen(rd());

int rand_in_range(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}
