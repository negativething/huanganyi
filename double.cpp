#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int sum=0,a[1001],e1,e2,e,i=0,k,l,x;
    srand(time(NULL));
    e1=rand()%10;
    e2=rand()%10;
    sum=e1+e2;
    while(sum<=100)
    {   
        x=rand()%2;
        if(x==0)
        {
            cout <<"我要成为视觉高手\n";
            k=e;
            e=e1+e2;
            e1=e2;
            e2=k;
            sum+=e;
            l=e/2;
            cout<<sum<<"\n";
        }
        else
        {
            cout <<"我要成为打瓦高手\n";
            sum-=l;
            cout<<sum<<"\n";
        }

    }
    cout <<"YOU ARE WELCOME TO JOIN PIONNER";
    return 0;
}