#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int>total;
int remain = 0;
int maintain = 0;
int count = 0;
int same = 1;
int maximum = 0;
int remain2 = 0;
void initialize(int x)
{
    total[x] = 1;
    maintain = x;
    count++;
    return;
}
void calcurate(int i, int j, vector <int>& arr)
{
    remain = arr.size() - j;
    printf("i:%d,j:%d, remain:%d\n",i,j,remain);
    if(remain == 1 && arr[i] >= arr[j])
    {
       initialize(j);
       return;
    }
    else if(remain == 1 && arr[i] < arr[j])
    {
       initialize(i);
       total[j] = total[i] + 1;
       remain2 = 1;
       maximum = 1;
       return;
    }
    if(arr[i] < arr[j])
    {
        maximum = 1;
		    same = 0;
        initialize(i);
        return;
    }
    else
    {
	   if(arr[i] != arr[j]) same = 0;
     calcurate(i+1,j+1, arr);
	   if(!same)   count++;
     if(remain == 1 && remain2 == 0) total[j] = count;
	   else			   total[i] = count;
    }
    return;
}
void candies(int n, vector <int>& arr)
{
    int j,k;
    total[0] = 1;
    for(int i = 0; i < arr.size();)
    {
        j = i+1;
        if(j == arr.size()) break;
        if(arr[i] < arr[j])
        {
		      	maximum = 1;
            total[j] = total[i] + 1;
            i++;
        }
        else
        {
            calcurate(i,j, arr);
            i = maintain;
            count = 0;
		      	if(!maximum) total[0] = arr.size();
            if(remain == 1) break;
        }
    }
}

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    total.assign(n,0);
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++)
    {
       cin >> arr[arr_i];
    }
    candies(n, arr);
    for(int i = 0;  i < n; i++)
    {
        if(total[i] != 0)
        {
            if(i+1 < n)
            {
                if(total[i] == total[i+1])
                {
                    if(arr[i] > arr[i+1]) total[i] += 1;
                }
            }
            printf("total[%d]=%d\n", i,total[i]);
            sum += total[i];
        }
    }
    printf("%lld\n", sum);
    return 0;
}
