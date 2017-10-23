#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int user_event_count = 20;
	vector<int> timeout;
	timeout.assign(user_event_count,1);
	for(int i = 0; i < timeout.size(); i++)
		cout<<timeout[i]<<endl;
	return 0;

}
