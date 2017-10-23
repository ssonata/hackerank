#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> &arr, int size)
{
	vector<int> temp(100);
	vector<int> B(size+1);
	for(int i = 0; i < size; i++)
	{
		temp[arr[i]] += 1;
	}

	for(int j = 1; j < 100; j++)
	{
		temp[j] += temp[j-1];
	}
	for(int k = size-1 ; k >= 0; k--)
	{
		B[temp[arr[k]]] = arr[k];
		temp[arr[k]] -= 1;
	}

	for(int p = 1; p < size + 1; p++)
	{
		cout<<B[p]<< " ";
	}
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
