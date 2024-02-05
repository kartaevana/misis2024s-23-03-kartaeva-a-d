#include <iostream>
#include <string>

int main(){
    int n = 0, k = 0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (int i = 0; i != (s.size() - 2); i++){
        if (s[i] == 'x' && s[i+1] == 'x' && s[i+2] == 'x'){
            k++;
        }
    }
    std::cout << k;
    return 0;
}
