#include <iostream>
#include  <deque>
#include<cstring>
using namespace std;

const int N =510;
int dist[N][N];
char a[N][N];
typedef pair<int,int> PII;

int n,m;
int x1,y1,x2,y2;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs()
{
	if(x1 == x2 &&y1 ==y2) 
	{
		dist[x2][y2]=0;
		return;
	}

	memset(dist,-1,sizeof dist);
	deque<PII> q;
	q.push_back({x1,y1});
	dist[x1][y1]=0;

	while(q.size())
	{
		auto t=q.front(); q.pop_front();
		int i=t.first,j=t.second;
		if(i == x2 && j ==y2) return;//剪枝，出列一定是最优解了

		for(int k=0;k<4;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if(x<1||x>n||y<1||y>m) continue;
		
			char cur=a[i][j],next=a[x][y];
			int w=(cur==next?0:1);
			if(dist[x][y]==-1)
			{
				dist[x][y]=dist[i][j]+w;
				if(w==0) 
					q.push_front({x,y});
				else 
				 	q.push_back({x,y});
			}
			else if(dist[i][j]+w<dist[x][y])//虽然第二次遇到,但是这种情况更优
			{
				//松弛操作
				dist[x][y]=dist[i][j]+w;
			}
			//不能在这里返回，因为不确定是最优解
			//if(x == x2 && y ==y2) return;
		}

	}
}

int main()
{
	while(cin>>n>>m,n&&m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		
		cin>>x1>>y1>>x2>>y2;
		x1++,y1++,x2++,y2++;
		bfs();
        cout << dist[x2][y2] << endl;
	}
	return 0;
}