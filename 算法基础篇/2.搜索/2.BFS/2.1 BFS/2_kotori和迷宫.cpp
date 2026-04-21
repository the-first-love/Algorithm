#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
const int N=35;
char a[N][N];
int dist [N][N];
int n,m,x,y;

int cnt,ret=0x3f3f3f3f;

typedef pair<int,int> PII;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs()
{
	memset(dist , -1 , sizeof dist);
	queue<PII> q;
	q.push({x ,y});
	dist[x][y] = 0;

	while(q.size())
	{
		PII t=q.front();q.pop();
		int i = t.first,j = t.second;

		for(int k=0;k<4;k++)
		{
			int x = i + dx[k],y =j + dy[k];

			if(x >= 1 && x <= n &&y >= 1 &&y <= m && a [x][y] != '*'&&
		 dist[x][y] == -1)
			{
		   	dist[x][y] = dist[i][j] + 1;
		    
			if(a[x][y]=='e')
			{
			cnt++;
			ret = min(ret, dist[x][y]);
			continue;
			}
			q.push({x ,y});
			}
		}

	}

}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			{
			cin>>a[i][j];
			if(a[i][j]=='k')
				{
				x =i;y=j;
				}
			}
	}
	bfs();
	if(cnt) cout<<cnt<<" "<<ret<<endl;
	else cout<<-1<<endl;
	return 0;
}