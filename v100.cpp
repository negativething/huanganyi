#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    vector<int> multiplies;
    multiplies.reserve(100/13);
    int i;
    for(i=1;i<=100;i+=1){
        if(i%13==0){
        multiplies.push_back(i);}
    }
    cout<<multiplies.size()<<endl;
    return 0;
}