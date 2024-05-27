
#include <iostream>

int main() {
    int t = 0;
    int now = 0;
    int ones = 0;
    std::cin >> t;
    while (t--) {
        ones = 0;
        for (int i = 0; i < 4; i++) {
            std::cin >> now;
            if (now == 1)
                ones += 1;
        }
        if (ones == 0)
            std::cout << 0 << std::endl;
        else if (ones == 4)
            std::cout << 2 << std::endl;
        else std::cout << 1 << std::endl;
    }
}
