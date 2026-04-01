#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 2e4 + 10;
int n;
int pos;
int l[N],r[N];//原始起点和终点
int disc[N*2],f[N*2];//离散化数据和差分数组

int main(int argc, char const *argv[])
{
//1.离散化
cin>>n;
for(int i=1;i<=n;i++) 
{
cin>>l[i]>>r[i];
disc[++pos]=l[i];disc[++pos]=r[i];
}
sort(disc+1,disc+1+pos);
int m=unique(disc+1,disc+1+pos)-(disc+1);
unordered_map<int,int> id;
int cnt=0;
for(int i=1;i<=pos;i++)
{
	if(id.count(disc[i])) continue;
	id[disc[i]]=++cnt;
}
//2.对离散数组进行差分
for(int i=1;i<=n;i++)
{
//左闭右开刚好吻合差分操作
f[id[l[i]]]++;f[id[r[i]]]--;
}
//还原离散数组
for(int i=1;i<=cnt;i++) f[i]+=f[i-1];

// 统计所有非0区间长度
int sum=0;
for(int i=1;i<=cnt;i++)
{
	if(f[i]<=0) continue;
	int j=i;
	while(j<=pos&&f[j]>0) j++;
    sum+=disc[j]-disc[i];
	i=j;
}
cout<<sum<<endl;

return 0;
}