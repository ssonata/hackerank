#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &num)
{
	int end_value = num[num.size()-1];
	int flag = 0;
	for(int i = num.size() - 1; i >= 1; i --)
	{
		if(num[i-1]	> end_value)
		{
			num[i] = num[i - 1];
		}
		else
		{
			flag = 1;
			num[i] = end_value;
		}

		for(int j = 0; j < num.size(); j++)
			cout<< num[j] << " ";
		cout<<endl;
		if(flag) break;
	}

	if(!flag && num[0] > end_value)		//예외조건 end_value가 젤 작을 경우
	{
		num[0] = end_value;
		for(int j = 0; j < num.size(); j++)
			cout<< num[j] << " ";
		cout<<endl;
	}
	return;
}
int main()
{
	int input_num;
	cin >> input_num;
	vector<int> V(input_num);
	for(int i = 0;  i < input_num; i ++)
	{
		cin >> V[i];
	}
	insertion_sort(V);
	return 0;
}

