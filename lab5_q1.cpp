#include <iostream> // Added to include std::cout
#include <vector>
#include <algorithm>

// Assuming Vector is similar to std::vector
typedef std::vector<int> Vector;

void rvrs(Vector& vct){
    int n = vct.size();
    for(int i = 0; i < n / 2; i++) {
        std::swap(vct[i], vct[n - i - 1]);
    }
}

int main() {
    Vector vct = {1, 2, 3, 4, 5};
    rvrs(vct);

    // Print the reversed vector
    for(int i : vct) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // Added to print a newline after the vector

    return 0;
}