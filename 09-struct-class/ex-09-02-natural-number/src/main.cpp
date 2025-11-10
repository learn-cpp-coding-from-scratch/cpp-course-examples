#include<iostream>
#include <string>
#include "NaturalNumber.hpp"


int main() {
    NaturalNumber a{100};
    NaturalNumber b{};
    b = theNextNumber(a);

    std::cout << a.toString() << ' ' 
         << b.toString() << '\n'; 
         
    NaturalNumber num{};

    const int N = 10;

    for(int i = 1; i <= N; ++i) {
        std::cout << num.toString() << ' ';
        num = theNextNumber(num);
    }
    std::cout << '\n';
}