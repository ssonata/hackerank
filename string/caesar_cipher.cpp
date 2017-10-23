#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define A_ASKII 65
#define Z_ASKII 90
#define a_ASKII 97
#define z_ASKII 122

//대문자 A  : 65, Z : 90
//소문자 a : 97, z : 122
//기타문자는 그대로 유지
int main()
{
	int n, diff, is_lower = 0, is_upper = 0;
	char A;
	cin >> n;
	string s;
	string output;
	cin >> s;
	int k;
	cin >> k;
	for(int i = 0; i < n ; i++)
	{
		int pure_value = s.at(i);
		if(pure_value <= 90 && pure_value >= 65)         is_lower = 1;
		else if(pure_value <= 122 && pure_value >= 97)   is_upper = 1;
		else A = (char)pure_value;

		int is_askii = pure_value + k;

		if(is_lower)
		{
			is_lower = 0;
			if(is_askii > Z_ASKII)
			{
				diff = (is_askii - Z_ASKII - 1) % 26; //diff 가 소문자 범위 넘어설 수 있으므로
				A = (char)(A_ASKII + diff);
			}
			else  A = (char)is_askii;
		}
		else if(is_upper)
		{
			is_upper = 0;
			if(is_askii > z_ASKII)
			{
				diff = (is_askii - z_ASKII - 1)%26; //diff 가 소문자 범위 넘어설 수 있으므로
				A = (char)(a_ASKII + diff);
			}
			else A = (char)is_askii;
		}
		output += A;
	}
	cout<<output<<endl;
	return 0;
}
