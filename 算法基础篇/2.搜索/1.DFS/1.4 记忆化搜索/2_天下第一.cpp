#include <iostream>

#include<algorithm>
using namespace std;
const int N=1e4+1;
int T,p;
char f[N][N];

char dfs(int x,int y)
{
if(f[x][y]) return f[x][y];
f[x][y]='3';

if(x==0) f[x][y]='1';
else if(y==0) f[x][y]='2';
else f[x][y]=dfs((x+y)%p,(x+y+y)%p);

return f[x][y];
}

int main(int argc, char const *argv[])
{
	cin>>T>>p;
	while(T--)
	{
		int x,y;cin>>x>>y;
		char ret=dfs(x,y);
		if(ret=='3') cout<<"error"<<endl;
		else cout<<ret<<endl;
	}
	return 0;
}