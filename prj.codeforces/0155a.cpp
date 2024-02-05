#include <iostream>
#include <vector>

int main(){
    int n, k=0, mn, mx;//k - кол-во удивит выступлений
    std::cin >> n;
    std::vector<int> a(n);
    for (int i=0; i<n;i++){
        std::cin >> a[i];
    }
    mn = a[0];
    mx = a[0];
    for (int i=1; i<n; i++){
        if (a[i]<mn){
            mn = a[i];
            k++;
        }
        if (a[i] > mx){
            mx = a[i];
            k++;
        }
    }
    std::cout << k;
    return 0;
}
