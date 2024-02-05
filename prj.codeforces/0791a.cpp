#include<iostream>

int main(){
  int a=0, b=0,  k=0;
  std::cin>>a>>b;
  for(int i=0;i<10000; i++){
    a*=3;
    b*=2;
    k++;
    if(a>b){
      std::cout<<k;
      break;
    }
  }
  return 0;
}
