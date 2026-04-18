#include <iostream>
#include<vector>
using namespace std;
int n,k;
const int N=30;

std::vector<int> v;

void dfs(int begin)
{
if(v.size()==k)
{
	for(auto x:v)
	{
		cout<< x <<" ";
	}
	cout<<endl;
	return;
}

for(int i=begin;i<=n;i++)
{
    v.push_back(i);
	dfs(i+1);
	//恢复现场
	v.pop_back();
}
}

int main(int argc, char const *argv[])
{
	cin>>n>>k;
	dfs(1);
	return 0;
}

