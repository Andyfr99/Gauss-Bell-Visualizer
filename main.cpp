#include <iostream>
#include <string>
#include <gauss.h>
#include <histogram.h>

int main(int argc, char*argv[]){

    // creates an array containing all values obtained
    float values[50] = {0.52f, 0.53f, 0.54f, 0.55f, 0.54f, 0.56f, 0.57f, 0.58f, 0.59f, 0.60f,
         0.61f, 0.62f, 0.63f, 0.73f, 0.74f, 0.75f, 0.74f, 0.76f, 0.77f, 0.78f, 0.79f, 0.80f,
          0.81f, 0.82f, 0.92f, 0.93f, 0.94f, 0.95f, 0.96f, 0.95f, 0.97f, 0.98f, 0.99f, 1.00f,
           1.01f, 1.00f, 1.10f, 1.09f, 1.10f, 1.11f, 1.12f, 1.13f, 1.23f, 1.24f, 1.25f, 1.26f,
            1.25f, 1.27f, 1.28f, 1.29f};
    
    // size of the values array
    int values_size = sizeof(values) / sizeof(values[0]);
    
    // prints all the values
    std::cout << "values: ";
    for (int i = 0; i < values_size; i++) {if (i == values_size - 1) {std::cout << values[i] << "\n";} else {std::cout << values[i] << ", ";};}
    
    // creates an empty array with the same size as the 'values' array that will contain the histogram's values to make the gauss's bell
    float gauss_values[values_size];
    
    // calculates the average of all the values
    float avg = avgf(values, values_size);
    
    // prints the average
    std::cout << "average: " << avg << "\n";
    
    // calculates the standard deviation of the values
    float sigma = sigmaf(values, avg, values_size);
    
    // prints the standard deviation
    std::cout << "sigma: " << sigma << "\n";
    
    // calculates all the histogram's values to make the gauss's bell and append them to the 'gauss_values' array
    for (int i = 0; i < values_size; i++) {gauss_values[i] = gaussf(values[i], sigma, avg);}
    
    // new line
    std::cout << "\n";
    
    // creates a pointer array that will contain the strings to make the histogram
    std::string *histogram_values;
    
    // sets the 'histogram_values' array to the array returned by the 'make_histogram' function
    histogram_values = make_histogram(gauss_values, values_size);
    
    // prints all the values of the 'histogram_values' array to display the histogram in the console
    for (int i = 0; i < values_size + 1; i++) {std::cout << histogram_values[i] << "\n";}

    // tells the user that the program finished running
    std::cout << "program finished with code 0" << "\n";
    
    // waits for user input to close
    std::cout << "press ENTER to close";
    std::string temp;
    std::getline(std::cin, temp);
    
    // codes finished successfully
    return 0;
}
