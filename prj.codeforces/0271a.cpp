#include <iostream>

using namespace std;

int main () {
    int y = 0;
    std::cin >> y;
    for (y +=1; y <= 9999; y +=1) {
        int s1 = y / 1000;
        int s2 = (y - 1000*s1) / 100;
        int s3 = (y - 1000*s1 - 100*s2)/10;
        int s4 = y % 10;
        if (s1 != s2 && s1 != s3 && s1 != s4 && s2 != s3 && s2 != s4 && s3 != s4) {
            std::cout << y;
            break;
        }
    }
}