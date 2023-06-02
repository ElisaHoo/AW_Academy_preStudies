#include <iostream>

int sum(int numbers[], int amount) {
    int total{0};
    for (int i = 0; i < amount; ++i) {
        total += numbers[i];
    }
    return total;
}


int main() {
    std::cout << "Please enter how many numbers you want on the list: ";
    int amount{};
    std::cin >> amount;

    std::cout << "Next, enter the numbers.\n";
    int numbers[amount]{};
    for (int i = 0; i < amount; i++) {
        std::cout << (i+1) << ". number: ";
        std::cin >> numbers[i];
    }

    std::cout << "The sum of listed numbers is " << sum(numbers, amount) << "\n";

    return 0;
}