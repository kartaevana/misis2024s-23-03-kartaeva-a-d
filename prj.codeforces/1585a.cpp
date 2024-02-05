#include <iostream>
#include <vector>

int main() {
    int t = 0;
    int n = 0;
    std::vector<int> a(100, 0);
    int s = 1;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        s = 1;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        for (int j = 0; j < n - 1; j++) {
            if (a[j] == 1) {
                s += 1;
            }
            if (a[j] == 1 && a[j + 1] == 1) {
                s += 4;
            }
            if (a[j] == 0 && a[j + 1] == 0) {
                s = -1;
                break;
            }
        }
        if (a[n - 1] == 1 && s != -1) {
            s += 1;
        }
        std::cout << s << '\n';
    }
}#include <iostream>
#include <vector>

int main() {
    int t = 0;
    int n = 0;
    std::vector<int> a(100, 0);
    int s = 1;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        s = 1;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        for (int j = 0; j < n - 1; j++) {
            if (a[j] == 1) {
                s += 1;
            }
            if (a[j] == 1 && a[j + 1] == 1) {
                s += 4;
            }
            if (a[j] == 0 && a[j + 1] == 0) {
                s = -1;
                break;
            }
        }
        if (a[n - 1] == 1 && s != -1) {
            s += 1;
        }
        std::cout << s << '\n';
    }
}
