#include<iostream>
#include<string>
using namespace std;

string s;
int mp[26],kind;

int main(int argc, char const *argv[])
{
cin>>s;
int left=0,right=0,ret=s.size();

while(right<s.size())
{
if(mp[s[right]-'a']++==0) kind++;
while(kind==26)
{	
ret=min(ret,right-left+1);
if(mp[s[left]-'a']--==1) kind--;
left++;
}
right++;
}

cout<<ret;

return 0;
}