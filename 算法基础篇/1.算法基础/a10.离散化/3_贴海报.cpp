#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1e7 + 10;
int n,m;
int pos;
int l[N],r[N];//原始起点和终点
int disc[N*4];//离散化结果数组

int w[N*4];
bool mp[N];

int find(int x)
{
	int l=1,r=pos;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(disc[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}

int main(int argc, char const *argv[])
{
cin>>n>>m;
for(int i=1;i<=m;i++) 
{
cin>>l[i]>>r[i];
disc[++pos]=l[i],disc[++pos]=l[i]+1;
disc[++pos]=r[i],disc[++pos]=r[i]+1;
}
//1.离散化
sort(disc+1,disc+1+pos);
pos=unique(disc+1,disc+1+pos)-(disc+1);
//2.模拟贴海报
for(int i = 1; i <= m; i++)
{
int x = find(l[i]), y = find(r[i]);
for(int j = x; j <= y; j++) w[j] = i;
}
//3.统计有多少个不同的数
int cnt=0;
for(int i = 1; i <= n; i++)
{
	int x=w[i];

	if(!x) continue;//注意0是没海报，不要统计
	if(mp[x]) continue; 

	mp[x]=true;
	cnt++;
}
cout<<cnt<<endl;
return 0;
}