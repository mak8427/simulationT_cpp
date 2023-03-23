//
// Created by Mac on 23/03/23.
//

#ifndef SIMULATIONT_UTIL_H
#define SIMULATIONT_UTIL_H
#pragma once

#include <random>

extern std::random_device rd;
extern std::mt19937 gen;

int rand_in_range(int min, int max);

#endif //SIMULATIONT_UTIL_H
