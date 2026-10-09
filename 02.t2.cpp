#include <iostream>
using namespace std;

long long climbStairsIter(int n);
long long climbStairsRecur(int n);

int main()
{
    int n;
    cin>>n;
    if(n<0||n>40) return 0; //检查参数是否在定义域中 
    cout<<"迭代:"<<endl;
    long long result=climbStairsIter(n); 
    cout<<result<<endl; 
    cout<<"递归"<<endl;
    long long result2=climbStairsRecur(n);
    cout<<result2<<endl; 

    return 0;
}

long long climbStairsIter(int n) //迭代
{
    long long f1=1;
    long long f2=2;
    long long f3;
    if(n==0||n==1) return f1; 
    if(n==2) return f2;
    for(int i=3;i<=n;i++)
    {
        f3=f1+f2;  
        f1=f2;
        f2=f3;
    }
    return f3;
}

long long climbStairsRecur(int n) //递归
{
    if(n==0||n==1) return 1;  
    if(n==2) return 2;
    return (climbStairsIter(n-1)+climbStairsRecur(n-2));
}

