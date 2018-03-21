#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<pair<string,string>> output;
int start;     //초기 start값
int size;      //비교대상  size크기
int size_length; //틀릴때마다 string size +1씩 증가

bool check_num(vector<string> &num)
{
	for(int j = 1; j < num.size(); j++)
	{
		if(num[j-1].substr(0,1) == "0")   //첫자리가 0인 수는 무조건 false
		{
			return false;
		}
		if(atoi(num[j].c_str()) - atoi(num[j-1].c_str()) != 1)  //An-An-1 != 1이면 무조건 false
		{
			return false;
		}
	}
	return true;
}
bool success(string &s, vector<string> &num)
{
	if(start + size == s.size())  //초기size값 + 비교대상 size크기가 전체 string길이라면 YES
	{
		output.push_back(make_pair("YES",num[0]));
		return true;
	}
	return false;
}
bool fail(string &s)
{
	if(size_length == s.size() || size_length > 16) //32자이기때문에 16자이상이거나 16자 미만의 string인 경우
		                                            //틀린 size길이와 string size값이 같을경우 false
	{
		output.push_back(make_pair("NO",""));
		return true;
	}
	return false;
}
void init(int _start, int _size, int length)    //초기화루틴 수행
{
	start = _start;
	size = _size;
	size_length = length;
	return;
}
void separateNumbers(string &s)
{
	vector<string> num;
	init(0,1,1);
	while(1)
	{
		if(fail(s) == 1) break;

		string tmp = s.substr(start, size);  //start와 비교대상 size로 문자값 뽑기

		num.push_back(tmp);           //string substr로 나온 문자값을 num vector에 넣기

		if(tmp.compare("9") == 0 |    //9로 시작하는 단어는 무조건 다음번 비교대상 size +1하기
			tmp.compare("99") == 0 |
			tmp.compare("999") == 0 |
			tmp.compare("999") == 0 |
			tmp.compare("9999") == 0|
			tmp.compare("99999") == 0|
			tmp.compare("999999") == 0|
			tmp.compare("9999999") == 0|
			tmp.compare("99999999") == 0 |
			tmp.compare("999999999") == 0 |
			tmp.compare("9999999999") == 0|
			tmp.compare("99999999999") == 0|
			tmp.compare("999999999999") == 0|
			tmp.compare("9999999999999") == 0|
			tmp.compare("99999999999999") == 0|
			tmp.compare("9999999999999999") == 0)
		{
			if(success(s, num) == 1) break;
			
			init((start+size), sizei+1, size_length);
			continue;
		}
		if(check_num(num) == true)
		{
			if(success(s, num) == 1) break;
			init((start+size), size, size_length);
		}
		else
		{
			num.clear();   //실패 시 벡터 num 초기화
			int _size = size_length += 1;
			init(0, _size, size_length);
		}
	}
	return;
}

int main()
{
	int q;
	cin >> q;
	for(int a = 0; a < q; a++)
	{
		string s;
		cin >> s;
		separateNumbers(s);
	}
	for(auto iter: output)  //c++11에서 지원하는 auto 방법 사용
	{
		cout<<iter.first<<" "<<iter.second<<endl;
	}
	return 0;
}
