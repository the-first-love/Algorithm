#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
int n,k,ret;
const int N=30;
LL sum;
int a[N];

bool is_prime(LL x)
{
if(x<=1) return false;
for(int i=2;i<=x/i;i++)
{
if(x%i==0) return false;
}
return true;
}

void dfs(int begin,int cnt)
{
if(cnt==k)
{
	if(is_prime(sum)) ret++;
	return;
}
for(int i=begin;i<=n;i++)
{
sum+=a[i];
dfs(i+1,cnt+1);
sum-=a[i];
}

}

int main(int argc, char const *argv[])
{
cin>>n>>k;

for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+1+n);
dfs(1,0);
cout<<ret<<endl;
return 0;
}