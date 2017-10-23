#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int find_value,count;
	cin >> find_value;
	cin >> count;
	vector<int> V(count);
	for(int j = 0; j < count; j++)
	{
		cin >> V[j];
	}

	for(int k = 0; k < V.size(); k++)
	{
		if(V[k] == find_value)
		{
			cout<<k<<endl;
			break;
		}
	}
	return 0;
}
