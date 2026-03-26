#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
typedef long long LL;

LL a[N],c,n;

int main(int argc, char const *argv[])
{
cin>>n>>c;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+1+n);
LL ret=0;
for(int i=2;i<=n;i++)
{
LL b=a[i]-c;
ret+=upper_bound(a+1,a+i,b)-lower_bound(a+1,a+i,b);
}

cout<<ret;
return 0;
}