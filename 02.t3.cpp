#include <iostream>
using namespace std;

void buildTestTree(int* tree, int n);
void preorderTraversal(const int* tree, int n, int i);
void inorderTraversal(const int* tree, int n, int i);
void postorderTraversal(const int* tree, int n, int i);

int main()
{ 
    int i=0;
    int tree[]={1,2,3,4,5,-1,-1};
    int n=7;
    buildTestTree(tree,n);
    cout<<"前序遍历:"<<endl;
    preorderTraversal(tree, n, i); //前序
    cout<<endl;
    cout<<"中序遍历:"<<endl;
    inorderTraversal(tree, n,i); //中序
    cout<<endl;
    cout<<"后序遍历:"<<endl;
    postorderTraversal(tree,n,i); //后序
    cout<<endl;
    return 0;
}
void buildTestTree(int* tree, int n) //填充数组
{
    for(int i=0;i<n;i++)
    {
        cin>>*tree;
        tree++;
    }

}

void preorderTraversal(const int* tree, int n, int i)
{
    if(i>=n||tree[i]==-1) return;
    cout<<tree[i]<<" "; //根
    preorderTraversal(tree,n,2*i+1); //左
    preorderTraversal(tree,n,2*i+2);  //右
}
void inorderTraversal(const int* tree, int n, int i)
{
    if(i>=n||tree[i]==-1) return;
    inorderTraversal(tree,n,2*i+1);  //左
    cout<<tree[i]<<" ";  //根
    inorderTraversal(tree,n,2*i+2); //右
}

void postorderTraversal(const int* tree, int n, int i)
{
    if(i>=n||tree[i]==-1) return;
    postorderTraversal(tree,n,2*i+1); //左
    postorderTraversal(tree,n,2*i+2);  //右
    cout<<tree[i]<<" "; //根
}

