#include <iostream>

int main()
{
    long long t;
    std::cin>>t;
    while(t--) {
        int n,m,x,y,d;
        std::cin>>n>>m>>x>>y>>d;
        int v1 = x-d, v2 = x+d, v3=y-d, v4=y+d;
        if((v1<=1&&v3<=1) || (v2>=n && v4>=m) || (v1<=1 && v2>=n) || (v3<=1 && v4>=m)){
            std::cout<<"-1";
        }else{
            std::cout<<n+m-2;
        }
        std::cout << "\n";
    }

    return 0;
}
