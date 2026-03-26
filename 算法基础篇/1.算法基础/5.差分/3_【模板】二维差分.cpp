#include<iostream>
using namespace std;

const int N=1010;
typedef long long LL;
LL f[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,LL k)
{
f[x1][y1]+=k;
f[x1][y2+1]-=k;f[x2+1][y1]-=k;
f[x2+1][y2+1]+=k;
}

int main()
{
    cin>>n>>m>>q;
    //初始化差分数组
    for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=m;j++)
    {
    LL a;cin>>a;
    insert(i,j,i,j,a);
    }
    }
    while(q--)
    {
    int a,b,c,d;LL k;cin>>a>>b>>c>>d>>k;
    insert(a,b,c,d,k);
    }
    
   for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=m;j++)
    {
    f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    cout << f[i][j] << " ";
    }
    cout << endl;
    }
    return 0;
}