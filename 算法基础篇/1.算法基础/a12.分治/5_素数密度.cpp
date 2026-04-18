#include <iostream>
#include <algorithm>
#include<cmath>

const int N=1e6+10;
typedef long long LL;
using namespace std;
int cnt,p[N];
bool st[N],ret[N];
int l,r;

void get_prime()
{
int n=sqrt(r);
for(int i=2;i<=n;i++)
{

if(!st[i]) p[++cnt]=i;

for(int j=1;1ll*i*p[j]<=n;j++)
{
    st[i*p[j]]=true;
    if(i%p[j]==0) break;
}       
    
}
}
int main()
{
cin>>l>>r;

get_prime();

l=l==1?2:l;

for(int i=1;i<=cnt;i++)
{
 LL x=p[i];
for(LL j=max(x*2, (x+l-1) /x*x);j<=r;j+=x)
{
    ret[j-l]=true;
}
    
}

int sum=0;
for(int i=l;i<=r;i++)
{
if(!ret[i-l]) sum++;
}
cout<<sum<<endl;
    
return 0;
}