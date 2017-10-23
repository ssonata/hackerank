#include <iostream>
using namespace std;

void insertion_sort2(int *num, int size)
{
	for(int i = 1; i < size; i++)
	{
		for(int j = 0; j < i; j ++)
		{
			if(num[i] < num[j])					//현재 비교대상인 i값보다  뒷자리 값인 j값이 더 클경우 i~j값 사이의 값들이 shift 되어야 한다.
			{
				int goal = num[i];				//shift를 위해 i값을 변수goal 에 저장

				for(int k = i; k > j; k--)		//shifh를 하기 위해 반복하기
					num[k] = num[k-1];			//자리값 ++하기
				num[j] = goal;
			}
		}
		for(int p = 0; p < size; p++)
			cout<< num[p] << " " ;
		cout<<endl;
	}
	
	return;
}
int main()
{
	int num_count;
	cin >> num_count;
	int V[num_count];
	for(int i = 0; i < num_count; i++)
	{
		cin >> V[i];
	}
	insertion_sort2(V, num_count);
	return 0;
}
