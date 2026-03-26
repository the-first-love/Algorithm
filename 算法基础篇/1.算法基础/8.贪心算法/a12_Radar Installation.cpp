#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int N=1010;
int n,d;
typedef long long LL;
 
struct node
{
	double l,r;
}a[N];

bool cmp(node& a,node& b)
{
	return a.l<b.l; 
}

int calc()
{
sort(a+1,a+1+n,cmp);
int ret=1;
double right=a[1].r;
for(int i=2;i<=n;i++)
{
if(a[i].l>right) ret++,right=a[i].r;
else right=min(right,a[i].r);
}
return ret;
}

int main(int argc, char const *argv[])
{
int cnt=0;

while(cin>>n>>d,n||d)
{
int flag=0;

for(int i=1;i<=n;i++)
{
double x,y;cin>>x>>y;
if(y>d) flag=1;
else
{
double t=sqrt(d*d-y*y);
a[i].l=x-t,a[i].r=x+t;
}
}
printf("Case %d: ",++cnt);
if(flag) cout<<-1<<endl;
else cout<<calc()<<endl;

}
	return 0;
}