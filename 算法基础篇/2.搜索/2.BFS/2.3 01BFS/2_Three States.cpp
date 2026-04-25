#include<iostream>
#include <deque>
#include<cstring>
using namespace std;

const int N=1010;
typedef pair<int,int> PII;
int dist1[N][N],dist2[N][N],dist3[N][N];
char a[N][N];
int n,m;

deque<PII> q1,q2,q3;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(deque<PII>& q,int dist[N][N])
{
while(q.size())
{
	auto t=q.front();q.pop_front();
	int i=t.first,j=t.second;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k],y=j+dy[k];
		if(x<1||x>n||y<1||y>m||a[x][y]=='#') continue;
		//01bfs
		int w=(a[x][y]=='.'?1:0);
		if(dist[x][y]==-1)
		{
			dist[x][y]=dist[i][j]+w;
			if(w==0) q.push_front({x,y});
			else q.push_back({x,y});
		}
		else if(dist[i][j]+w<dist[x][y])
		{
			//松弛操作
			dist[x][y]=dist[i][j]+w;
		}
	}
}

}

 int main(int argc, char const *argv[])
 {
 	cin>>n>>m;
 	memset(dist1,-1,sizeof dist1);
 	memset(dist2,-1,sizeof dist2);
 	memset(dist3,-1,sizeof dist3);
 	for(int i=1;i<=n;i++)
	{   
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
			{
				q1.push_back({i,j});
				dist1[i][j]=0;
			}
			else if(a[i][j]=='2')
			{
				q2.push_back({i,j});
				dist2[i][j]=0;
			}
			else if(a[i][j]=='3')
			{
				q3.push_back({i,j});
				dist3[i][j]=0;
			}		    	
	    }
	}
	bfs(q1,dist1);
	bfs(q2,dist2);
	bfs(q3,dist3);

	int ret=1e6 + 10;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x = dist1[i][j], y = dist2[i][j], z =dist3[i][j];
			//一国不通就跳过
			if(x == -1 || y == -1 || z == -1) continue;
			
			if(a[i][j]=='.')
			{
				ret=min(ret,x+y+z-2);
			}
			else
			{
				ret=min(ret,x+y+z);
			}
		}
	}
	if(ret==1e6+10) cout<<-1<<endl;
	else cout<<ret<<endl;

 	return 0;
 }