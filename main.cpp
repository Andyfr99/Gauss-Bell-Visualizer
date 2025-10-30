#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <gauss.h>
#include <histogram.h>


// all functions are declared here so i can use them in main while specifying their use after main
char chooseMode();
std::vector<float> randomMode();
std::vector<float> manualMode();
int sizeSelect();

template <typename T>

// check if user input is valid
void checkValidInput(T& input) {

    // runs until valid
    while (true) {
        std::cin >> input;

        // if invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        } else {break;}
    }
}


int main(int argc, char*argv[]){

    // vector containing all the values
    std::vector<float> values;

    // asks user to select a mode
    char mode = chooseMode();

     // runs the appropriate function depending on the choice
    switch (mode)
    {
    case '1':
        values = randomMode();
        break;
    
    case '2':
        values = manualMode();
        break;
    }
    
    // shrinks values vector to match the size and not waste memory space
    values.shrink_to_fit();

    // sorts array (so the bell is visible)
    std::sort(values.begin(), values.end());

    // size of the values vector
    int values_size = values.size();
    
    // prints all the values
    std::cout << "values: ";
    for (int i = 0; i < values_size; i++) {if (i == values_size - 1) {std::cout << values[i] << "\n";} else {std::cout << values[i] << ", ";};}
    
    // creates an empty array with the same size as the 'values' vector that will contain the histogram's values to make the gauss's bell
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    
    // codes finishùd successfully
    return 0;
}

// this function chooses the mode of value typing
char chooseMode() {
    std::cout << "Select The Mode:\n" << "1 | Random\n" << "2 | Manual\n";

    // asks user to choose the mode. repeats until the user types a valid answer.
    char user_select_input;
    do {std::cin >> user_select_input;} while (user_select_input != '1' && user_select_input != '2');

    return user_select_input;
}

// random mode code
std::vector<float> randomMode() {

    std::cout << "Random Mode Selected\n";

    // how many values to generate 
    int size = sizeSelect();
    
    // range setup
    std::cout << "Select the range\n";

    std::cout << "minimum: "; 
    float min; // minimum value range
    checkValidInput(min); // repeats until valid input // repeats until valid input

    std::cout << "maximum: "; 
    float max; // maximum value
    do {checkValidInput(max);} while (max <= min); // repeats until valid input; // repeats until valid input

    // creates the vector
    std::vector<float> values;

    // generate random values and put them inside the vector

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<float> number(min, max); // define the range
    for (int i=0; i < size; i++) {values.push_back(number(gen));} // put a random value for how big the size is

    // new line
    std::cout << "\n";

    return values;
}

// manual mode code
std::vector<float> manualMode() {
    std::cout << "Manual Mode Selected\n";

    // how many values to generate 
    int size = sizeSelect();

    // creates the vector
    std::vector<float> values;

    //fills vector with user written values
    for (int i=0; i < size; i++) {

        std::cout << "Value " << i << ": ";
        float value;
        checkValidInput(value); // repeats until valid input

        values.push_back(value);

        // new line
        std::cout << "\n";
    }

    // new line
    std::cout << "\n";

    return values;
}

// function to setup how many values to generate 
int sizeSelect() {

    std::cout << "Select How Many Values To Generate\n";
    int size; // size of the vector

    // repeats until valid input and size bigger than 1
    do {checkValidInput(size);} while (size <= 1);

    return size;
}