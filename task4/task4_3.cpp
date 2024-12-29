#include <vector>
#include <iostream>
#include <chrono>

int main() {
    int size = 10000000;
    // default initialization and add elements with push_back
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<float> v1;
    for (int i = 0; i < size; i++)
        v1.push_back(i);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"Default initialization of "<<v1.size()<<" elements: "<<elapsed.count()<<"ms"<<std::endl;

    // initialized with required size and add elements with direct access
    start = std::chrono::high_resolution_clock::now();
    std::vector<float> v2(size);
    for (int i = 0; i < size; i++)
        v2[i] = i;
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"Initialization with size of "<<v2.size()<<" elements: "<<elapsed.count()<<"ms"<<std::endl;
}