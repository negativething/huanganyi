#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    vector<int> numbers;
    numbers.reserve(100);
    int i,l;
    for(i=0;i<=100;++i){
        numbers.push_back(i);
    }
auto it=numbers.begin();
while (it!=numbers.end())
{
    if(*it%2!=0){
        it=numbers.erase(it);
    }
    else{++it;}
}
cout<<numbers.size()<<endl;
    return 0;
}