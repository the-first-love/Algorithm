#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

const int N =1010;
int dist[N][N];
int a[N][N];
typedef pair<int,int> PII;

int n,m;
queue<PII> q;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs()
{
while(q.size())
{
auto t=q.front();q.pop();
int a=t.first,b=t.second;
for(int i=0;i<4;i++)
{
int x=a+dx[i],y=b+dy[i];
if(x<1||x>n||y<1||y>m||dist[x][y]!=-1) continue;
dist[x][y]=dist[a][b]+1;
q.push({x,y});
}

}

}

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	
		string s;cin>>s;
		for(int j=0;j<m;j++)
			{
				if(s[j]=='1') 
				{
					q.push({i,j+1});
					dist[i][j+1]=0;
				}
				else
				{
					dist[i][j+1]=-1;
				}
			}
	}
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}
		
	return 0;
}