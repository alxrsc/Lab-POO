#include <iostream>


// working for ints
// for chars it will concatenate ASCII values ( 'a' + 'b' = 9798 )
template<typename T>
std::string concatenate(T a, T b) {
    return std::to_string(a) + std::to_string(b);
}

// specialization for char
template<>
std::string concatenate(char a, char b) {
    return std::string(1, a) + std::string(1, b);
}



int main() {

    std::cout << concatenate(1, 2) << std::endl;

    std::cout << concatenate('I', 'S') << ' ' << concatenate('a', 'n') << ' ' << concatenate('I', 'I') << std::endl;

    return 0;
}
