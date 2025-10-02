#include<iostream>
using namespace std;
int main()
{
    int x, s;
    cout<<"请输入一个分数："<<endl;
    cin>>x;
    if(x>=60)
    {
        s=0;
    }
    else
    {
        s=1;
    }
    switch (s)
    {
    case 0:
        cout<<"合格"<<endl;
        break;
    default:cout<<"不合格"<<endl;
        break;
    }
    return 0;
}