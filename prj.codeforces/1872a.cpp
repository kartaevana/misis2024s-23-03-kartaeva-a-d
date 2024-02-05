#include <iostream>
#include <cmath>

int main() {
    int a, b, c, n, k;
    float h;
    std::cin >> n;
    k = 0;
    while (n!=k) {
        std::cin >> a >> b >> c;
        h = std::abs(a-b)/2.0/c;
        if (h != static_cast<int>(h)) {
            h++;
        }
        k += 1;
        std::cout<<static_cast<int>(h)<<"\n";
    }
    return 0;
}
