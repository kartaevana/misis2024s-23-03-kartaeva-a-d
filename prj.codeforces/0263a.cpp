#include <iostream>
 
int main() {
    int i1, j1, k;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> k;
            if (k==1) {
                i1 = abs(2 - i);
                j1 = abs(2 - j);
            }
        }
    }
    std::cout << i1 + j1;
    return 0;
}
