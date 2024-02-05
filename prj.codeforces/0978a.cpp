#include <iostream>
#include <vector>

int main(){
    int n, t = 0;
    std::cin >> n;
    std::vector<int> a(n), coun(1001, 0);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--){
        if (coun[a[i]] == 0){
            coun[a[i]] = 1;
            t++;
        } else {
            a[i] = 0;
        }
    }
    std::cout << t << "\n";
    for (int i = 0; i < n; i++){
        if (a[i] != 0) {
            std::cout << a[i] << " ";
        }
    }
    return 0;
}
