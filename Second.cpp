#include <iostream>
#include<cmath>
using namespace std;

int add(int a, int b)
{
    return 0;
}

int add(int a,int b);
int main()
{
    int x=7,y=8;
    int result = x+y;
    cout<<"x="<<x<<",y="<<y<<endl;
    cout <<x<<"+"<<y<<"="<<result<<endl;
    return 0;
}
