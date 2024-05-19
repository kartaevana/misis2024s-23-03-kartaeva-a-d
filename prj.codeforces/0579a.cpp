#include <iostream>

int main() {
    int a = 0;
    int count = 0;
    std::cin >> a;
    while (a > 0) {
        count += (a % 2);
        a /= 2;
    }
    std::cout << count;
}