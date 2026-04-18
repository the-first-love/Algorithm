#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N=15;
int n,ret; 
bool col[N],dia1[2*N],dia2[2*N];
vector<int> path;

void dfs(int i)
{
if(i>n) 
{
	ret++;
	if(ret <=3)
	{
    for(auto x : path) cout << x << " ";
    cout << endl;
    }
	return;
}

for(int j=1;j<=n;j++)
{
if(col[j]||dia1[i-j+n]||dia2[i+j]) continue; 
path.push_back(j);
col[j]=dia1[i-j+n]=dia2[i+j]=true;
dfs(i+1);
path.pop_back();
col[j]=dia1[i-j+n]=dia2[i+j]=false;
}

}


int main(int argc, char const *argv[])
{
	cin>>n;
	dfs(1);
	cout<<ret<<endl;
	return 0;
}