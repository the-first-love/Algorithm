#include <iostream>
#include <algorithm>

using namespace std;
const int N=15;
int n=13,m=4;
int a[N][6];

int cnt[N];//记录每堆牌未被翻的牌数

void dfs(int x)
{
if(x==13) return;

int t=a[x][cnt[x]];
--cnt[x];

dfs(t);
}

int main(int argc, char const *argv[])
{
	for(int i=1;i<=n;i++)
	{
		cnt[i]=4;
		for(int j=1;j<=m;j++)
        {
        	char x;cin>>x;
        	if(x=='0') a[i][j]=10;
        	else if(x=='A') a[i][j]=1;
        	else if(x=='J') a[i][j]=11;
        	else if(x=='Q') a[i][j]=12;
        	else if(x=='K') a[i][j]=13;
        	else a[i][j]=x-'0';
        }
	}

for(int i=1;i<=m;i++)
{
	dfs(a[n][i]);
}

int ret=0;
for(int i=1;i<=n;i++)
{
	if(!cnt[i]) ret++;
}
cout<<ret<<endl;
return 0;
}