#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int n;
int a[1<<11];
string s;

void dfs(int l,int r)
{
if(l>r) return;
//先判断类型
char ret;
int sum=a[r]-a[l-1];
if(!sum) ret='B';
else if(sum==r-l+1) ret='I';
else ret='F';
//只有一个节点直接打印
if(l == r)
{
cout << ret;
return;
}
//先处理左右节点，最后再打印
int mid=(l+r)/2;
dfs(l,mid);
dfs(mid+1,r);

cout<<ret;
}

int main(int argc, char const *argv[])
{
cin>>n;
n=(1<<n);
//
s=" "+s;//前面加一个字符，使得索引从1开始
//也可以在循环中读入字符
//初始化前缀和数组
for(int i=1;i<=n;i++)
{
	a[i]=a[i-1]+s[i]-'0';
}
dfs(1,n);
return 0;
}




