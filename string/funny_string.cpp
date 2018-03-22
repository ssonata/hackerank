#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
vector<string> output;
void funnyString(string s)
{
	string r;
	r = s;
	reverse(r.begin(),r.end());

	vector<int> s_vector;
	vector<int> r_vector;

	for(int i = 1; i < s.size(); i++)
	{
		s_vector.emplace_back(abs(s[i] - s[i-1]));
		r_vector.emplace_back(abs(r[i] - r[i-1]));
	}
	if(s_vector == r_vector) output.emplace_back("Funny");
	else output.emplace_back("Not Funny");
}

int main()
{
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; a0++)
	{
		string s;
		cin >> s;
		funnyString(s);
	}
	for(auto iter : output)
		cout<<iter<<endl;
	return 0;
}
