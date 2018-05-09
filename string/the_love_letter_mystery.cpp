#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void theLoveLetterMystery(string &s)
{
	int count = 0;
	int size = s.size();
	for(int i = 0; i < (s.size()/2); i++)
	{
		count += abs(s[i] - s[size-1]);
		size--;
	}
	v.push_back(count);
}
int main()
{
	int num;
	cin >> num;

	for(int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		theLoveLetterMystery(s);
	}
	vector<int>::iterator iter = v.begin();
	for(;iter != v.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
