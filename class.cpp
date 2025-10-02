#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    class Ball{
    private:
    double size;
    double price;
    public:
    Ball():size(10.0),price(20.0){}
    Ball(double s,double p):size(s),price(p){}
    Ball(const Ball& other):
    size(other.size),
    price(other.price){}
    void setSize(double s){
        if (s>0){
            size=s;
        }
        else
        cout<<"请输入正数"<<endl;
    }
        double getSize() const{
            return size;
        }
    void setPrice(double p){
        if (p>=0){
            price=p;
        }
        else {
            cout<<"请输入正数"<<endl;
        }
    }
    double getPrice() const{
        return price;
    }
};
    class Projectile : public Ball {};
    int sum=0,a[1001],e1,e2,e,i=0,k,l,x,m;
    srand(time(NULL));
    e1=rand()%10;
    e2=rand()%10;
    sum=e1+e2;
    while(sum<=100)
    {   
        x=rand()%2;
        if(x==0);
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
    m=rand()%2;
    switch (m)
    {
    case 0:
        cout<<"奖励大弹丸\n尺寸为"<<s<<"\n价格为"<<p<<endl;
        break;
    
    default:
        cout<<"奖励小弹丸\n尺寸为"<<s<<"\n价格为"<<price<<endl;
        break;
    }
    return 0;
};
