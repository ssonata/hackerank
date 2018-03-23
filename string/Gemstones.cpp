#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> store;
multiset<int> ms;
int gemstones(vector<string> arr, int size)
{
	int result = 0;
	for(int i = 0; i < size; i++)
	{
		for(int h = 0; h <arr[i].size(); h++)
		{
			store.insert(arr[i][h]);
		}
		set<int>::iterator iter = store.begin();
		for(;iter != store.end(); ++iter)
		{
		//	cout<<*iter<<endl;
			ms.insert(*iter);
		}
		store.clear();
	}
	for(int alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if(ms.count(alpha)== size)
		{
			result++;
		}
	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int arr_i = 0; arr_i < n; arr_i++)
	{
		cin >> arr[arr_i];
	}
	int result = gemstones(arr,n);
	cout << result << endl;
	return 0;
}
