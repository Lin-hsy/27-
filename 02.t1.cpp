#include <iostream>
using namespace std;

void reverseArray(int*arr,int n); //函数声明

int main()
{
    int n;  //定义变量
    int arr[100];
    cin>>n;
    if(n<=0||n>100) return 0;//限定n在范围内            
    for(int i=0;i<n;i++) //遍历有效数组赋值
    {
        cin>>arr[i];
    }
    
    reverseArray(arr,n); //调用函数

    for(int j=0;j<n;j++) //遍历数组输出
    {
        cout<<arr[j]<<" ";
    }
    return 0;

}

void reverseArray(int*arr,int n)
{
    int* end=arr+n-1; //定义新指针指向结尾
    for(int i=0;i<n/2;i++)
    {
        int t=*end; //左右对称交换
        *end=*arr;
        *arr=t;
        arr++; //指针向中间移动
        end--;
    }

}