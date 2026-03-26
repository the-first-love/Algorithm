#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N=1e5+10;
int n;
typedef long long LL;

struct cow
{
	int x; //t
	int y; //d
}a[N];

bool cmp(cow& a,cow& b)
{
	return a.x*b.y<b.x*a.y;
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) 
cin>>a[i].x>>a[i].y;

sort(a+1,a+1+n,cmp);

LL ret=0;
int t=0;
for(int i = 1; i <= n; i++)
{
ret += a[i].y * t;
t += 2 * a[i].x;
} 
cout<<ret<<endl;
return 0;
}
