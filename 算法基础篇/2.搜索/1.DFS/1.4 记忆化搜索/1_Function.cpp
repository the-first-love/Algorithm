#include <iostream>

#include<algorithm>

using namespace std;
typedef long long LL;
const int N=21;
LL a,b,c;
LL w[N][N][N];

LL dfs(LL a,LL b,LL c)
{
if(a<=0||b<=0||c<=0) return 1;
if(a>20||b>20||c>20) return dfs(20,20,20);

if(w[a][b][c]) return w[a][b][c];
else
{
if(a<b&&b<c) w[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
else w[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);

return w[a][b][c];
}

}

int main(int argc, char const *argv[])
{
	while(cin>>a>>b>>c)
	{
	//多组测试用例使用相同的备忘录不需要清空
	if(a == -1 && b == -1 && c == -1) break;
    printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));
	}
	return 0;
}