#include<iostream>
using namespace std;
const int N=1e5+10;
int f[N];
int n,m,ret;

int main()
{
cin>>n>>m;
int x;cin>>x;
//利用差分性质创建差分数组
while(--m)
{
int y;cin>>y;
if(y>x)
{
f[x]++;
f[y]--;
}
else
{
f[y]++;
f[x]--;
}
x=y;
}
//前缀和还原原数组
for(int i=1;i<n;i++)
{
f[i]=f[i]+f[i-1];
}

for(int i=1;i<n;i++)
{
int a,b,c;
cin>>a>>b>>c;
ret+=min(a*f[i],c+f[i]*b);
}
cout << ret << endl;
    return 0;
}