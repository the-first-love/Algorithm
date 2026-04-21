#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
const int N=410;
int ret[N][N];
int n,m,x,y;

typedef pair<int,int> PII; 
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};

void bfs()
{
queue<PII> q;
q.push({x,y});
ret[x][y]=0;

while(q.size())
{
PII t=q.front();q.pop();
int a=t.first,b=t.second;//记录起点坐标

for(int i=0;i<8;i++)
{
int x=a+dx[i],y=b+dy[i];
if(x<1||x>n||y<1||y>m||ret[x][y]!=-1) continue;
ret[x][y]=ret[a][b]+1;
q.push({x,y});
}
}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m>>x>>y;
    memset(ret,-1,sizeof ret);
	bfs();
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
					cout<<ret[i][j]<<" ";
			cout<<endl;
		}

	return 0;
}