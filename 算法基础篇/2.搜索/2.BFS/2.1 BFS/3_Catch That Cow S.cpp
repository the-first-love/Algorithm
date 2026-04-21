#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
const int N=1e5+10;
int dist[N];
int T,x,y;

void bfs()
{
queue<int> q;q.push(x);
dist[x]=0;
while(q.size())
{
	int t=q.front();q.pop();
	int a=t-1,b=t+1,c=t*2;
    
    //先加减后乘
	if(a>0&&dist[a]==-1) 
	{
		q.push(a);
		dist[a]=dist[t]+1;
	}
	if(b<=y&&dist[b]==-1) 
	{
		q.push(b);
		dist[b]=dist[t]+1;
	}
	if(c<=y&&dist[c]==-1) 
	{
		q.push(c);
		dist[c]=dist[t]+1;
	}

	if(a ==y||b ==y||c ==y) return;
}

}

int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		memset(dist,-1,sizeof dist);
		bfs();
		cout<<dist[y]<<endl;
	}
	
	return 0;
}