#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> &arr, int size)
{
	vector<int> temp(size);
	for(int i = 0; i < size; i++)
	{
		temp[arr[i]] += 1;
	}

	for(int j = 0; j < 100; j++)
		cout<<temp[j]<< " ";
	cout<<endl;
	return;
}
int main()
{
	int arr_size;
	cin >> arr_size;
	vector<int> arr(arr_size);
	for(int i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}
	counting_sort(arr, arr_size);
	return 0;
}
