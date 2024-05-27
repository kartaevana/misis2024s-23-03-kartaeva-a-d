#include <iostream>
void a()
{
    int n, k, x, y, fix;
    std::cin >> n >> k >> x >> y;
    fixer = (k + (y - 1) % k - (x - 1) % k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + fix) % k == j % k) {
                std::cout << "X";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) a();
    return 0;
}