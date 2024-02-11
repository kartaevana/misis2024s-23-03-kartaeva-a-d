#include<iostream>
#include<string>

int main()
{
    int n=0;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    int a=0,b=0,z=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')a++;
        else b++;
        if(a==b)
        {
            if(s[i+1]==s[i])z++;
        }
    }
    std::cout<<z;
}
