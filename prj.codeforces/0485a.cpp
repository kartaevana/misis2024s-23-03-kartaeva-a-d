#include <iostream>

int main() {
    int64_t a = 0;
    int64_t m = 0;
    bool flag = false;
    std::cin >> a;
    std::cin >> m;
    for (int i = 1; i < m; i++) {
        if (a % m == 0) {
            flag = true;
            break;
        }
        a += a % m;
    }
    if (flag == true || a % m == 0) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}