#include<iostream>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL f[N];

int n,m;

int main()
{
cin>>n>>m;
//利用差分性质创建差分数组
for(int i=1;i<=n;i++)
{
LL x;cin>>x;
f[i]+=x;
f[i+1]-=x;
}
//集中操作
while(m--)
{
int l,r;LL k;
cin>>l>>r>>k;
f[l]+=k;f[r+1]-=k;
}
//前缀和还原原数组
for(int i=1;i<=n;i++)
{
f[i]=f[i]+f[i-1];
cout <<f[i]<< " " ;
}

    return 0;
}