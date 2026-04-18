#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N=11;
bool row[N][N],col[N][N],st[N][N][N];
int a[N][N];

bool dfs(int i,int j)
{
if(j==9) 
{
	i++;
	j=0;
}
if(i==9) return true;

if(a[i][j]) return dfs(i,j+1);

for(int k=1;k<=9;k++)
{
//剪枝
if(row[i][k]||col[j][k]||st[i/3][j/3][k]) continue;

row[i][k]=col[j][k]=st[i/3][j/3][k]=true;
a[i][j]=k;

if(dfs(i,j+1)) return true;
//恢复现场
row[i][k]=col[j][k]=st[i/3][j/3][k]=false;
a[i][j]=0;
}
return false;
}

int main(int argc, char const *argv[])
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			{
				cin>>a[i][j];
				int x=a[i][j];
				if(x)
				{
					row[i][x]=col[j][x]=st[i/3][j/3][x]=true;
				}
			}

	dfs(0,0);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
return 0;
}