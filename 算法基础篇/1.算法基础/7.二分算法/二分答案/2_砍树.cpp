#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
typedef long long LL;

LL n,m,a[N];

LL calc(LL x)
{
	LL cnt=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]>x) cnt+=a[i]-x;
	}
	return cnt;
}


int main(int argc, char const *argv[])
{
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];

LL left=0,right=2e9;
while(left<right)
{
	LL mid=(left+right+1)/2;
	if(calc(mid)>=m) left=mid;
	else right=mid-1;
}

cout<<left<<endl;
	return 0;
}