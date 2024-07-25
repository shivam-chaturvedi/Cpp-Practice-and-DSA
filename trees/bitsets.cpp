#include <iostream>
#include <bitset>

const int BIT_SIZE = 200; // Adjust size as needed
const int RESULT_SIZE = BIT_SIZE * 2; // Result size is double the size of the input bitsets

// Function to perform bitwise multiplication
std::bitset<BIT_SIZE> bitwiseMultiply(std::bitset<BIT_SIZE>& a, std::bitset<BIT_SIZE>& b) {
    std::bitset<BIT_SIZE> result; // To store the result
    std::bitset<BIT_SIZE> multiplicand = a;
    
    for (int i = 0; i < BIT_SIZE; ++i) {
        if (b[i]) { // If the ith bit of b is 1
            result ^= (multiplicand << i); // Add (shifted multiplicand) to result
        }
    }

    return result;
}

void printBitset(std::bitset<BIT_SIZE>& bs) {
    // Print from the most significant bit
    for (int i = bs.size() - 1; i >= 0; --i) {
        std::cout << bs[i];
        if (i % 8 == 0 && i != bs.size() - 1) std::cout << ' '; // Add space every 8 bits
    }
    std::cout << std::endl;
}

int main() {
    // Create bitsets for large numbers
    std::bitset<BIT_SIZE> a; // Example number 13
    std::bitset<BIT_SIZE> b; // Example number 11
    for(int i=0;i<6;i++){
        a.set(i);
        b.set(i);
    }

    // Perform bitwise multiplication
    std::bitset<BIT_SIZE> result = bitwiseMultiply(a, b);

    std::cout << "Multiplicand (a): ";
    printBitset(a);

    std::cout << "Multiplier (b): ";
    printBitset(b);

    std::cout << "Result: ";
    printBitset(result);


    return 0;
}
