#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

// Задание 1
void calculateSum(const int* arr, int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
}

void filterArray(const int* arr, int size, std::vector<int>& result) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            result.push_back(arr[i]);
        }
    }
}

void symmetricDifference(const std::set<int>& setA, const std::set<int>& setB, std::set<int>& result) {
    for (int elem : setA) {
        if (setB.find(elem) == setB.end()) {
            result.insert(elem);
        }
    }
    for (int elem : setB) {
        if (setA.find(elem) == setA.end()) {
            result.insert(elem);
        }
    }
}

int main() {
    const int sizeA = 10;
    int A[sizeA];
    std::vector<int> B;

    std::cout << "Type 10 elements of array A:" << std::endl;
    for (int i = 0; i < sizeA; i++) {
        std::cin >> A[i];
    }

    filterArray(A, sizeA, B);

    int sumA = 0, sumB = 0;
    calculateSum(A, sizeA, sumA);
    calculateSum(B.data(), B.size(), sumB);

    std::cout << "Array B (elements of A that are divisible by 3): ";
    for (int elem : B) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Sum of Array A elements: " << sumA << std::endl;
    std::cout << "Sum of Array B elements: " << sumB << std::endl;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // Задание 2
    int main() {
        std::set<int> A_set, B_set, symDiff;
        int nA, nB, elem;

        std::cout << "Type the number of elements of the set A: ";
        std::cin >> nA;
        std::cout << "Type the elements of the set A:" << std::endl;
        for (int i = 0; i < nA; i++) {
            std::cin >> elem;
            A_set.insert(elem);
        }

        std::cout << "Type the number of elements of the set B: ";
        std::cin >> nB;
        std::cout << "Type the elements of the set B:" << std::endl;
        for (int i = 0; i < nB; i++) {
            std::cin >> elem;
            B_set.insert(elem);
        }

        symmetricDifference(A_set, B_set, symDiff);

        std::cout << "\nThe symmetric difference contains " << symDiff.size() << " elements." << std::endl;
        std::cout << "Elements of symmetric difference: ";
        for (int x : symDiff) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        return 0;
    }
