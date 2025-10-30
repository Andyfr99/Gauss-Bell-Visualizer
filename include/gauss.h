#include <iostream>
#include <vector>
#include <math.h>

// calculates the average of mutliple values and returns it as a float
float avgf(std::vector<float> values, int size) {

    float sum = 0.f;

    for (int i = 0; i < size; i++) {sum += values[i];}

    return sum / size;
}

// calculates the standard deviation and returns it as a float
float sigmaf(std::vector<float> values, float avg, int size) {

    float sum = 0.f;

    for (int i = 0; i < size; i++) {sum += powf((values[i] - avg), 2.f);}

    return sqrtf(sum / size);
}

// calculates the gauss's bell histogram value of a specific value
float gaussf(float value, float sigma, float avg) {
    float formula_1 = 1.f / (sigma * sqrtf(2.f * M_PI));
    float power = (1.f / 2.f) * powf(((value - avg) / sigma), 2.f);

    return powf(formula_1, -power);
}