#include<iostream>

using namespace std;
typedef long long ll;
int n,m,q;
const int N= 1e4;
ll a[N][N];
ll S[N][N];

int main()
{
	cin>>n>>m>>q;

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++) cin>>a[i][j];
}

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++) 
	S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j]; 
}

int x1,y1,x2,y2;
while(q--)
{
cin>>x1>>y1>>x2>>y2;

cout<<S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1]<<endl;
}
	return 0;
}