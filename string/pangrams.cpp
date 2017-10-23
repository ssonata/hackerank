#include <iostream>
#include <vector>
using namespace std;
string s = "abcdefghijklmnopqrstuvwxyz";
char func(char in)
{
	if(in <= 'Z' && in >= 'A')
	{
		return in - ('Z' - 'z');
	}
	return in;
}
int main()
{
	string str, str2;
	getline(cin,str);
	for(int j = 0; j < str.length(); j++)
	{
		str2 += func(str.at(j));
	}
	for(int i = 0 ; i < s.size(); i++)
	{
		if(str2.find(s.at(i)) == -1)
		{
			cout<<"not pangram"<<endl;
			return 0;
		}
	}
	cout<<"pangram"<<endl;
	return 0;
}
