#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char,char>> V;
vector<pair<char,char>> P;
void distinct(string str)
{
	for(int i = 0;  i < str.length(); i ++)
	{
		for(int j = i+1; j < str.length(); j++)
		{
			if(str.at(i) != str.at(j))
			{
				pair<char, char> p(str.at(i),str.at(j));
				if(find(V.begin(),V.end(), p) != V.end())	continue;
				else
				{
					V.push_back(make_pair(str.at(i),str.at(j)));
					V.push_back(make_pair(str.at(j),str.at(i)));
					P.push_back(make_pair(str.at(i),str.at(j)));
				}
			}
		}
	}
}
bool is_distinct(string temp)
{
	for(int i = 1; i < temp.length(); i++)
	{
		if(temp.at(i) == temp.at(i-1))	return false;
	}
	return true;
}
void compare_string(string &str, string &temp2, vector<pair<char,char>> &P)
{
	int maxlength = 0;
	vector<pair<char,char>>::iterator iter = P.begin();
	for(; iter != P.end(); ++iter)
	{
		temp2.clear();
		for(int i = 0; i < str.length(); i++)
		{
			if(str.at(i) == iter->first || str.at(i) == iter->second)	temp2 += str.at(i);
		}
		if(is_distinct(temp2))
		{
			int size = temp2.length();
			if(maxlength < size)
			{
				//cout<<"빙고 : "<<temp2<<endl;
				maxlength = size;
			}
		}
	}
	cout<<maxlength<<endl;
	return;
}
int main()
{
	string str, temp2;
	int count;
	cin >> count;
	char A;
	for(int i = 0; i < count; i++)
	{
		cin >> A;
		str += A;
	}
	if(str.size() == 1)
	{
		cout<<0<<endl;
		return 0;
	}

	distinct(str);

	compare_string(str, temp2, P);
	return 0;
}
