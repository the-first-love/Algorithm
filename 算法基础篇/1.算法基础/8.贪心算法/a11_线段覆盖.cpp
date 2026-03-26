#include <iostream>
#include <algorithm>

using namespace std;

const int N=1e6+10;
int n;
typedef long long LL;

struct node
{
	int l;
	int r;
}a[N];

bool cmp(node& a,node& b)
{
	return a.l<b.l;
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) cin>>a[i].l>>a[i].r;
	
sort(a+1,a+1+n,cmp);

int right=a[1].r,ret=1;
for(int i = 2; i <= n; i++)
{
if(a[i].l<right) right=min(a[i].r,right);
else ret++,right=a[i].r;
}
cout<<ret<<endl;
return 0;
}