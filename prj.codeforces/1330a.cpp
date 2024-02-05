#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int>m;
    while (t--) {
        int n, x;
        std:: cin >> n >> x;
        std::vector<int> data(202, 0);
        for (int i = 0; i < n; ++i){
            int numb; std:: cin >> numb;
            data[numb] = 1;
        }
        for (int i = 1; i < data.size(); ++i){
            if (data[i] == 0 && x != 0) {
                x -= 1;
                data[i] = 1;
            }
            if (data[i] == 0 && x == 0) {
                m.push_back(i-1);
                break;
            }
        }
    }
    for(int i=0;i<m.size();++i){
        std::cout<<m[i]<<"\n";
    }
    return 0;
}
