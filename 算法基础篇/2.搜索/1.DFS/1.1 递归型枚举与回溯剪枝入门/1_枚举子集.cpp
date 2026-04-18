#include <iostream>
using namespace std;
int n;
string path;

void dfs()
{
if(path.size()==n)
{
	cout<<path<<endl;
	return;
}
path+='N';
dfs();
path.pop_back();//回溯

path+='Y';
dfs();
path.pop_back();//回溯

}

int main(int argc, char const *argv[])
{
	cin>>n;
	dfs();
	return 0;
}