#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int,int>,string>> comp;
int func(pair<pair<int,int>,string>& A, pair<pair<int,int>,string>& B)
{
	if(A.first.second != B.first.second)	return A.first.second < B.first.second;
	else									return A.first.first < B.first.first;
}
void full_counting_sort(vector<pair<pair<int,int>,string>>& arr, int num_count)
{
	int mid = num_count/2;
	vector<pair<pair<int,int>,string>>::iterator iter = arr.begin();
	for(int i = 0; iter != arr.end(); i++, ++iter)
	{
		if(i < mid)	iter->second = "-";
		else break;
	}
	sort(arr.begin(),arr.end(),func);
	iter = arr.begin();
	for(; iter != arr.end(); ++iter)
		cout<<iter->second<< " ";
	cout<<endl;
	return ;
}
int main()
{
	int num_count;
	cin >> num_count;
	vector<pair<pair<int,int>,string>> arr;

	int num;
	string str;
	for(int i = 0; i < num_count; i ++)
	{
		cin >> num >> str;
		arr.push_back(make_pair(make_pair(i,num),str));
	}
	full_counting_sort(arr, num_count);
}
