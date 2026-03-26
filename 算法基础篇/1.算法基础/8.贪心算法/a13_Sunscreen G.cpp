#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int N=2600;
int n,m;
typedef long long LL;
 
struct node
{
	int x; // 下限/防晒值
	int y; // 上限/数量  
}a[N],b[N];

bool cmp(node& a,node& b)
{
	return a.x>b.x;
}

int main(int argc, char const *argv[])
{
cin>>n>>m;
for(int i = 1; i <= n; i++) cin>>a[i].x>>a[i].y;
for(int i = 1; i <= m; i++) cin>>b[i].x>>b[i].y;

sort(a+1,a+1+n,cmp);
sort(b+1,b+1+m,cmp);

int ret=0;
for(int i = 1; i <= n; i++)
{
int l = a[i].x, r = a[i].y;
for(int j = 1; j <= m; j++) 
{
	int& sp=b[j].x,& cnt=b[j].y;
	if( sp < l) break;
	if(!cnt || sp > r) continue;
    else
    {
    ret++;
    cnt--;
    break;
    }
} 

}
cout<<ret<<endl;

return 0;
}