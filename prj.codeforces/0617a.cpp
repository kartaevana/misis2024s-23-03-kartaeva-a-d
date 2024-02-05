#include <iostream>
 
int main() {
    int x, k = 0;
    std::cin >> x;
    if (0 == x % 5){
        k = x / 5;
    } else {
        k = x / 5 + 1;
    } std::cout << k;
}
