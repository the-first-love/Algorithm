#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef long long LL;

LL a[N];
LL n,k;

LL calc(LL x)
{
LL cnt=0;
for(int i=1;i<=n;i++) cnt+=a[i]/x;
return cnt;
}

int main(int argc, char const *argv[])
{
cin>>n>>k;
for(int i=1;i<=n;i++) cin>>a[i];

LL left=0,right=1e8;
while(left<right)
{
LL mid=(left+right+1)/2;
if(calc(mid)>=k) left=mid;
else right=mid-1;
}
cout<<left<<endl;
return 0;
}