#include<iostream>
#include<cmath>
#include<vector>

int main(){
  int t=0, m=0, k=0, l=0, d=0, mx=0;
  std::cin>>t;
  std::vector<int>mxx;
  while(t--) {
    std::cin >> m;
    for (int i = 0; i < 10; i++) {
      l = pow(10, i);
      if (l == m){
        mx=0;
        break;
      }else {
        if (m - l > 0)mx = m - l;
      }
    }
    mxx.push_back(mx);
  }
  std::cout<<"\n";
  for (int i=0; i<mxx.size(); ++i){
    std::cout<<mxx[i]<<"\n";
  }
  return 0;
}
