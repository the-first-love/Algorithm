#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

const int N =1010;
int p[N][N];
bool st[N][N];
int n,m;
typedef pair<int,int> PII;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool bfs(int P)
{
	memset(st,0,sizeof st);
	queue<PII> q;
	for(int j=1;j<=m;j++) 
	{
		q.push({1,j});
		st[1][j]=true;
	}

	while(q.size())
	{
		auto t=q.front();q.pop();
		int a=t.first,b=t.second;

		for(int i=0;i<4;i++)
		{
		int x=a+dx[i],y=b+dy[i];
		if(x<1||x>n||y<1||y>m||st[x][y]) continue;//越界或走过了
		if(p[x][y]>P) continue;//伤害比p高走不了
		if(x==n) return true;
		q.push({x,y});
		st[x][y]=true;
		}
	}

	return false;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];

	int left=0,right=1000;
	while(left<right)
	{
		int mid=(left+right)/2;
		if(bfs(mid)) right=mid;
		else left=mid+1;
	}
	cout<<left<<endl;
	return 0;
}

