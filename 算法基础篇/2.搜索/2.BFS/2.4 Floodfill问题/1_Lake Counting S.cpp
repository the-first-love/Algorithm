#include<iostream>
#include <queue>
#include<cstring>
using namespace std;
const int N = 110;

int n,m;
char g[N][N];
bool st[N][N];

int dx[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};

void bfs(int i,int j)
{
	queue<pair<int,int>> q;
	q.push({i,j});
	st[i][j]=true;

	while(q.size())
	{
		auto [a,b]=q.front();q.pop();
		for(int i=0;i<8;i++)
		{
			int x=a+dx[i],y=b+dy[i];
			if(x<1||x>n||y<1||y>m||st[x][y]) continue;
			if(g[x][y]=='W') 
			{
				st[x][y]=true;
				q.push({x,y});
			}
		}
	}
}

void dfs(int i,int j)
{
	st[i][j]=true;

for(int k=0;k<8;k++)
{
	int x=i+dx[k],y=j+dy[k];
	if(x>=1&&x<=n&&y>=1&&y<=m&&!st[x][y]&&g[x][y]=='W')
	{
		dfs(x,y);
	}
}
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
  	
    int ret=0;
  	for(int i=1;i<=n;i++)
	{   
		for(int j=1;j<=m;j++)
		{
			if(g[i][j] == 'W' && !st[i][j])
			{
			ret++;
            // 从[i, j]位置开始，把所有的水标记一下
			//dfs(i, j); 
		    bfs(i ,j);
		 	}

		}
	}
	cout<<ret<<endl;
	return 0;
}