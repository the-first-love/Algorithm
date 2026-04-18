#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=15;
int k,n;
int t[N],d[N],l[N];
bool st[N];

bool dfs(int pos,int end)
{
if(pos>n) return true;

for(int i=1;i<=n;i++)
{
if(st[i]) continue;//重复性剪枝
if(end>t[i]+d[i]) continue;//可行性剪枝

st[i]=true;
if(dfs(pos+1,max(end,t[i])+l[i])) return true;
st[i]=false;//恢复现场
}

return false;
}

int main(int argc, char const *argv[])
{
	cin>>k;
	while(k--)
	{
	memset(st , 0 , sizeof st);//每组测试前注意要清空st数组
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>d[i]>>l[i];

    if(dfs(1,0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	}

	return 0;
}