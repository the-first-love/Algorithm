#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N=20;
int a[N],s[N];//猫的重量和每辆车目前总重
int n,w;
int ret=N;//最优解
int cnt;//当前用了多少车

bool cmp(int a,int b)
{
	return a>b;
}

void dfs(int pos)
{
//最优性剪枝 	
if(cnt>=ret) return;
//cnt<ret,递归出口即可更新最优解
if(pos>n) 
{
	ret=cnt;
	return;
}

//优化搜索顺序：先考虑安排在已有车辆上
for(int i=1;i<=cnt;i++)
{
//可行性剪枝
if(a[pos]+s[i]>w) continue;
s[i]+=a[pos];
dfs(pos+1);
s[i]-=a[pos];
}
//再考虑新开一辆车
cnt++;
s[cnt]=a[pos];
dfs(pos+1);
s[cnt]=0;
cnt--;
}

int main(int argc, char const *argv[])
{
	cin>>n>>w;
	for (int i = 1; i <=n; ++i) cin >> a[i];

	//优化搜索顺序，从大到小选，快速得到一个结果
	sort(a+1,a+1+n,cmp);

	dfs(1);
	cout<<ret<<endl;
	
	return 0;
}
