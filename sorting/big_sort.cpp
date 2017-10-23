#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int i , j, q;
string x;
void bubble_sort(vector<string> & num)
{
	for(int i = num.size() -1; i >= 0; i--)
	{
		for(int j = 0; j <  i; j++)
		{
			if(num[j].length() > num[i].length())
				swap(num[i], num[j]);
			else if(num[j].length() == num[i].length())
			{
				if(num[j] > num[i])	swap(num[i], num[j]);
			}
		}
	}
	return;
}
bool func(string A, string B)
{
	int i = A.length();
	int j = B.length();
	if(i == j)	return (A < B);
	return i < j;
	
}
int main()
{
	int n ; 
	cin >> n;
	vector<string> unsorted(n);
	for(int i = 0; i < n; i++)
	{
		cin >> unsorted[i];
	}
	sort(unsorted.begin(),unsorted.end(), func);
	//bubble_sort(unsorted);
	vector<string>::iterator iter = unsorted.begin();
	for(;iter != unsorted.end();++iter)
		cout<<*iter<<endl;
	return 0;
}
