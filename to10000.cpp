#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int s;
    for (s=0;s<=10000;s+=1)
    {
        if (s%13==0)
        {
            cout<<s<<"\n"<<endl;
        }
    }

}