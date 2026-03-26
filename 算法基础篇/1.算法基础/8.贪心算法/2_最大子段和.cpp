#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int n;
LL a[N];

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) cin >> a[i];

LL ret=-1e8;LL sum=0;
for(int i=1;i<=n;i++)
{
    if(sum<0) sum=0;
	sum+=a[i];
	ret = max(ret,sum);
}

cout<<ret<<endl;
return 0;
}