#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // seed for random number generation
    int numberToGuess = rand() % 100 + 1; // generate a random number between 1 and 100
    int numberOfTries = 0; // counter for the number of tries

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (true) {
        int guess;
        std::cout << "Take a guess: ";
        std::cin >> guess;
        numberOfTries++;

        if (guess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You found the number in " << numberOfTries << " tries." << std::endl;
            break;
        }
    }

    return 0;
}


