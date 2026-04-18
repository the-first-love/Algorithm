#include <iostream>
#include<algorithm>
using namespace std;

const int N=110;
int h[N][N];
int f[N][N];
int n,m;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int dfs(int x,int y)
{
if(f[x][y]) return f[x][y];
f[x][y]=1;
for(int i=0;i<4;i++)
{
	int a=x+dx[i],b=y+dy[i];
	//可行性剪枝
	if(a<1||b<1||a>n||b>m||h[x][y]<=h[a][b]) continue;
	f[x][y]=max(f[x][y],dfs(x+dx[i],y+dy[i])+1);
}
return f[x][y];
}

int main(int argc, char const *argv[])
{

cin>>n>>m;
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>h[i][j];

int ret=1;
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		ret=max(ret,dfs(i,j));

cout<<ret<<endl;	
return 0;
}