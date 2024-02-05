#include <iostream>
 
int main() {
    int i, y, a, b, c, d;
    std::cin >> y;
    for (i = y+1; y <= 10000; i++) {
        a = i / 1000;
        b = i / 100 % 10;
        c = i % 100 / 10;
        d = i % 10;
        if (a != b && b != c && c != d && a != d && b != d && a != c) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
