#include <iostream>

using namespace std;

int main () {
    int w = 0;
    int count = 0;
    std::cin >> w;
    while (w > 5) {
        count = count + 1;
        w -= 5;
    }
    if (w > 0) {
        count = count + 1;
    }
    std::cout << count;
}