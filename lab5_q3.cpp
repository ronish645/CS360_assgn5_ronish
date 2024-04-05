#include <iostream>
#include <vector>
#include <algorithm> // Needed for std::sort function

// Define the Tensor class
class Tensor {
public:
    // Method to sort a given vector and print its contents
    void sort(std::vector<int>& vec) {
        // Sorting the vector in ascending order
        std::sort(vec.begin(), vec.end());

        // Iterating over the sorted vector to print each element
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl; // End the line after printing the vector
    }
};

int main() {
    // Creating an instance of the Tensor class
    Tensor tensor;

    // Defining a test vector with unsorted integers
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};

    // Printing the original, unsorted vector to the console
    std::cout << "Original vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << "\nSorted vector:   "; // Notice for starting the print of sorted vector

    // Calling the sort method of the tensor instance, which sorts and prints the vector
    tensor.sort(vec);

    return 0; // End of main function
}
