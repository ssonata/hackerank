#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int count;
	cin >> count;
	vector<int> factory(count);
	for(int i = 0 ; i < count; i++)
	{
		cin >> factory[i];
	}
	sort(factory.begin(),factory.end());
	cout<<factory[count/2]<<endl;
	return 0;
}
