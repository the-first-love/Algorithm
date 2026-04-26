#include<iostream>
#include <queue>
#include<cstring>
using namespace std;

const int N = 40;

int n,m;
int g[N][N];
bool st[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(int i,int j)
{
	queue<pair<int,int>> q;
	q.push({i,j});
	g[i][j]=2;
	st[i][j]=true;

	while(q.size())
	{
		auto [a,b]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int x=a+dx[i],y=b+dy[i];
			if(x<1||x>n||y<1||y>n||st[x][y]) continue;
			if(g[x][y]==0) 
			{
				st[x][y]=true;
				g[x][y]=2;
				q.push({x,y});
			}
		}
	}
}

void dfs(int i,int j)
{
st[i][j]=true;

for(int k=0;k<4;k++)
{
	int x=i+dx[k],y=j+dy[k];
	if(x>=0&&x<=n+1&&y>=0&&y<=n+1&&!st[x][y]&&g[x][y]==0)
	{
		dfs(x,y);
	}
}
}

int main(int argc, char const *argv[])
{
	cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
  	//标记外层0
  	dfs(0,0);
    int ret=0;
  	for(int i=1;i<=n;i++)
	{   
		for(int j=1;j<=n;j++)
		{
			if(g[i][j] == 0 && !st[i][j])
			{
		    bfs(i ,j);
		 	}

		}
	}
   for(int i = 1; i <= n; i++)
    {    
    	for(int j = 1; j <= n; j++)
            cout<<g[i][j]<<" ";
    	cout<<endl;
    }

	return 0;
}