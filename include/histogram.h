#include <iostream>
#include <string>

/* creates a string array that when displayed value by value will display an histogram of the values
    the histogram value will be it's value and a certain amount of stars depending on how big the value is
    histogram example:
        0.2 | ** 
        0.5 | ****
        -----------
        (amount of stars in this example may be inaccurate on the actual amount of stars displayed for that value)
*/
std::string * make_histogram(float values[], int size) {

    // creates the array with its size increased by 1 and sets the last value to a purely decorative string
    std::string *histogram_values = new std::string[size + 1];
    histogram_values[size] = "-------------------------------------------------";

    // parses every value of the array and adds the histogram string
    for (int i = 0; i < size; i++) {
        histogram_values[i] = std::to_string(values[i]) + " | " + std::string(values[i] * 20, '*');
    }

    return histogram_values;
}