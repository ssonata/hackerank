#include <iostream>
#include <sstream>
#include <string>
using namespace std;
long long sum = 0;
void super_digit(stringstream &ss, int k)
{
	sum = 0;    
	string temp = ss.str();
//	cout<<"length::"<<temp.length()<<endl;
	if(temp.length() == 1)
	{
		cout<< temp.at(0) - '0' <<endl;
		return;
	}

	for(int i = 0; i < temp.length(); i++)
	{
		sum += temp.at(i) - '0';
	}

	ss.str("");
//	cout<<"sum::"<<sum<<endl;
	if(k)	ss << sum*k;
	else	ss << sum;

	super_digit(ss,0);
	return;
}
int main()
{
	stringstream ss;
	ss.str("");
	string temp;
	int k;
	cin >> temp;
	cin >> k;
	ss << temp;
	super_digit(ss, k);

	return 0;
}
