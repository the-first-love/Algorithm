#include<iostream>
using namespace std;
int n,m;
const int N= 5010;
int a[N][N];
int S[N][N];

int main()
{
	cin>>n>>m;
	int x,y,v;
	while(n--)
	{
	cin>>x>>y>>v;
	//从1开始计数
	a[++x][++y]+=v;
	}
n=5001;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++) 
	{
	S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
    } 
}

int ret=0;
m=min(m,N);

for(int x2=m;x2<=n;x2++)
{
    for(int y2=m;y2<=n;y2++) 
	{
	int x1=x2-m+1,y1=y2-m+1;
	int sum=S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1];
	ret=max(sum,ret);
    } 
}

cout<<ret<<endl;

	return 0;
}