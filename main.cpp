#include <iostream>

int sum(int numbers[], int amount) {
    int total{0};
    for (int i = 0; i < amount; ++i) {
        total += numbers[i];
    }
    return total;
}

double average(double sum, int amount) {
    double total {sum / amount};
    return total;
}

int mini(int numbers[], int amount) {
    int smallest = INT8_MAX;
    for (int i = 0; i < amount; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }
    return smallest;
}

int max(int numbers[], int amount) {
    int largest = INT8_MIN;
    for (int i = 0; i < amount; i++) {
        if (numbers[i] >largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int mostFrequent(int numbers[], int amount) {
    /* Outer loop picks each element in the list and inner loop
     * scans the entire list to count the picked up element's 
     * frequency
     */

    int maxFreq{0};  // to track the maximum frequency
    int mostFreq{-1};  // to track the most frequent element
    for (int i = 0; i < amount; i++) {
        int countFreq = 1;  // to track the frequency count of each element
        for (int j = 0; j < amount; j++) {
            // If the same number repeats -> countFreq increases by 1
            if (numbers[j] == numbers[i]) {
                countFreq += 1;
            }
        }
        // If found element with a frequency greater than maxFreq
        // -> update variables
        if (maxFreq < countFreq) {
            maxFreq = countFreq;
            mostFreq = numbers[i];
        } 
        else if (maxFreq == countFreq) {
            mostFreq = std::min(mostFreq, numbers[i]);
        }
    }
    return mostFreq;
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

    int numbers_sum = sum(numbers, amount);
    std::cout << "The sum of listed numbers is " << numbers_sum << "\n";
    // convert int to double so that the result has decimals
    std::cout << "The average of the numbers on the list is " << average(static_cast<double>(numbers_sum), amount) << "\n";
    std::cout << "The minimum value in the list is " << mini(numbers, amount) << "\n";
    std::cout << "The maximum value in the list is " << max(numbers, amount) << "\n";
    std::cout << "The most frequent value in the list is " << mostFrequent(numbers, amount) << "\n";
    std::cout << "The difference between the minimum and maximum of the list is " << (max(numbers, amount) - mini(numbers, amount)) << "\n";
    
    return 0;
}