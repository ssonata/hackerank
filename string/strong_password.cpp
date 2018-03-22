#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int isspecial(char c)
{
	if(c == '!' || c == '@' || c == '#' || c == '$' || c == '%' ||
	   c == '^' || c == '&' || c == '*' || c == '(' || c == ')' ||
	   c == '-' || c == '+')
	{
		return 1;
	}
	return 0;
}
int minimumNumber(int n, string password)
{
	int security[5];
	memset(security,0,sizeof(security));
	for(int i = 0; i < password.size(); i++)
	{
		char c = password.at(i);
		if(isdigit(c))		  security[0] = 1;
		else if(isupper(c))   security[1] = 1;
		else if(islower(c))   security[2] = 1;
		else if(isspecial(c)) security[3] = 1;
	}
	if(password.size() >= 6)
	{
		security[4] = 1;
	}
	int need = 0;
	for(int j = 0; j < 5; j++)
	{
		if(security[j] == 0)
		{
			need++;
		}
	}
	if(password.size() < 6)                 //password가 6자 미만일 때 변수가 많았다..ㅠ
	{
		if(password.size() + need > 6)     // 길이와 필요한 것이 6자를 넘으면 security[4]가 증가하므로 -1을 해준다.
		{
			return need-1;
		}
		else if(password.size() + need == 6)  //길이와 필요한 것이 6자라면 security[4]가 변함없으므로 그대로 need출력
		{
			return need;
		}
		else                                 //길이가 6자를 넘어버리면 그냥 need를 출력하면 된다.
		{
			return 6-n;
		}
	}
	return need;
}

int main()
{
	int n;
	cin >> n;
	string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
