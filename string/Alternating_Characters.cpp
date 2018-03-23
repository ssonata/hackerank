#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> v;

void alternatingCharacters(string s)
{
	int count = 0;
	for(size_t i = 1; i < s.size(); i++)
	{
		if(s.at(i) - s.at(i-1) == 0)
		{
			count++;
		}
	}
	v.emplace_back(count);
}
int main() 
{
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; a0++)
	{
		string s;
		cin >> s;
		alternatingCharacters(s);
	}
	for(auto iter : v)
		cout<<iter<<endl;
	return 0;
}
