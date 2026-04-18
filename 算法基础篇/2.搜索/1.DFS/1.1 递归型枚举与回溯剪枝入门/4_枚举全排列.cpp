#include <iostream>
#include<vector>
using namespace std;
int n;
const int N=30;

std::vector<int> v;
bool st[N];

void dfs()
{
if(v.size()==n)
{
for(auto x:v) printf("%5d",x);
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
	cin>>n;
	dfs();
	return 0;
}