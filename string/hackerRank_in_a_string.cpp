#include <iostream>
#include <vector>
using namespace std;
vector<string> output;
void yes_no(string &s)
{
	int k = 0;
	string str = "hackerrank";
	if(s.size() < str.size())
	{
		output.push_back("NO");
		return;
	}
	for(int i  =0; i < s.size(); i ++)
	{
		if(k < str.size() && s.at(i) == str.at(k))
		{
			k++;
		}
	}
	if(k == str.size())
	{
		output.push_back("YES");
	}
	else
	{
		output.push_back("NO");
	}
	return;
}
int main()
{
	int testcase;
	cin >> testcase;
	string ss;
	for(int i = 0; i < testcase; i ++)
	{
		cin >> ss;	
		yes_no(ss);
	}
	vector<string>::iterator iter = output.begin();
	for(;iter != output.end(); ++iter)
		cout<<*iter<<endl;
	return 0;
}
