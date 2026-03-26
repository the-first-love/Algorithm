#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e4+10;
typedef long long LL;

LL n,m,a[N];
LL l;

LL calc(LL x)
{
LL cnt=0;
for(int i=0;i<=n;i++)
{
int j=i+1;
while(j<=n&&a[j]-a[i]<x) j++;
cnt+=j-i-1;
i=j-1;
}
return cnt;
}

int main(int argc, char const *argv[])
{
	
cin>>l>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
a[++n]=l;

LL left=1,right=l;
while(left<right)
{
	LL mid=(left+right+1)/2;
	if(calc(mid)<=m) left=mid;
	else right=mid-1;
}
cout<<left<<endl;
return 0;
}