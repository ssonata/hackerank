//기존에는 sort정렬을 먼저하지 않고 for문 중첩을 가지고 smallest를 찾고 그것을
//output 벡터에 넣어 출력하였다. 하지만 아래와 같은 방법을 취한다면
//시간복접도는 O(n)이다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int testcase,smallest = 1000000;
	cin >> testcase;
	vector<int> V(testcase);
	for(int i = 0; i < testcase; i++)
	{
		cin >> V[i];
	}
	sort(V.begin(), V.end());  //출력 값이 제 멋대로이니, 오름차순 sorting 작업
	for(int j = 0; j < testcase - 1; j++)
	{
		int number = abs(V[j]-V[j+1]);
		if(smallest > number)
		{
			smallest = number;			//작으면 smallest 대입
		}
	}
	for(int i = 0; i < testcase ; i ++)
	{
		int number = abs(V[i] - V[i+1]);
		if(smallest == number)
			cout<<V[i]<<" " <<V[i+1]<<" ";
	}
	cout<<endl;
	return 0;
}
