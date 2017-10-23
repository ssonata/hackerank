#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int> &ar)
{
	int pivot = ar[0];
	int left[ar.size()];
	int right[ar.size()];
	int j = 0, k = 0;
	for(int i = 1; i< ar.size(); i++)
	{
		if(ar[i] >= pivot)	right[j++] = ar[i];
		else		left[k++] = ar[i];
	}
	left[k++] = pivot;

	for(int r = 0; r <= j; r++)
		left[k++] = right[r];

	for(j = 0; j < ar.size(); j++)
		cout<<left[j]<< " ";
	cout<<endl;
	return;
}

int main()
{
	int ar_size;
	cin >> ar_size;
	vector<int> ar(ar_size);
	for(int i = 0 ; i < ar_size; i++)
	{
		cin >> ar[i];
	}
	partition(ar);
	return 0;
}
