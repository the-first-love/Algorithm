#include <iostream>
#include<vector>
using namespace std;
int n,k;
const int N=30;

std::vector<int> v;
bool st[N];

void dfs()
{
if(v.size()==k)
{
for(auto x:v) cout<<x<<" ";

cout<<endl;
return;
}

for(int i=1;i<=n;i++)
{
	if(st[i]) continue;
	v.push_back(i);st[i]=true;
	dfs();
	v.pop_back();st[i]=false;
}

}

int main(int argc, char const *argv[])
{
	cin>>n>>k;
	dfs();
	return 0;
}