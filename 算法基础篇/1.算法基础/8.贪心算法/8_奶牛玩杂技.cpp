#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N=5e4+10;
int n;
typedef long long LL;

struct cow
{
	int w; 
	int s; 
}a[N];

bool cmp(cow& a,cow& b)
{
	return max(-a.s,a.w-b.s)< max(-b.s,b.w-a.s);
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) 
cin>>a[i].w>>a[i].s;

sort(a+1,a+1+n,cmp);

LL ret=-1e9,w=0;
for(int i = 1; i <= n; i++)
{
ret=max(ret,w-a[i].s);
w+=a[i].w;
} 
cout<<ret<<endl;
return 0;
}