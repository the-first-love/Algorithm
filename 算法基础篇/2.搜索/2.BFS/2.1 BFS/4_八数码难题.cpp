#include <iostream>
#include<string>
#include <queue>
#include <unordered_map>

using namespace std;

string s;
string aim="123804765";
unordered_map<string,int> dist;

// 方向向量
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
queue<string> q;
q.push(s);
dist[s]=0;

while(q.size())
{
string t=q.front();q.pop();
//找零的位置
int pos = t.find('0');
int x = pos / 3, y = pos % 3;

for(int i=0;i<4;i++)
{
	int a=x+dx[i],b=y+dy[i];
	if(a<0||a>2||b<0||b>2) continue;

	int p=a*3+b;
	string next=t;
	swap(next[pos],next[p]);
	if(dist.count(next)) continue;

	dist[next]=dist[t]+1;
	q.push(next);

	if(next==aim) return;
}

}
}

int main(int argc, char const *argv[])
{
	cin>>s;
	bfs();
	cout<<dist[aim]<<endl;
	return 0;
}