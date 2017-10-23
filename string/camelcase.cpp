#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string alpha;
	int count = 1;
	cin >> alpha;
	for(int i = 0; i < alpha.length(); i++)
	{
		if(isupper(alpha.at(i)))	count++;
	}
	cout<<count<<endl;
	return 0;
}

