#include <iostream>
#include <algorithm>
#include<cstring>
typedef long long LL;
using namespace std;

const int N=2e5+10;

int a[N];
int n;

LL sum(int l,int r)
{
if(l==r) return a[l];

LL ret=-0x3f3f3f3f;
int mid=(l+r)/2;
ret=max(sum(l,mid),sum(mid+1,r));

LL sum=0,lmax=-0x3f3f3f3f,rmax=-0x3f3f3f3f;
int cur1=mid,cur2=mid+1;
while(l<=cur1)
{
sum+=a[cur1--];
lmax=max(lmax,sum);
}
sum=0;
while(cur2<=r)
{
sum+=a[cur2++];
rmax=max(rmax,sum);
}
return max(ret,lmax+rmax);
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];

cout<<sum(1,n)<<endl;

return 0;
}