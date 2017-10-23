#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
int count;
void insertionSort(int N, int arr[]) {
   int i,j;
   int value;
   for(i=1;i<N;i++)
   {
        for(j=0; j<i;j++)
        {
			if(arr[i]<arr[j])
			{
				int temp = arr[i];
				count += i-j;
				for(int k = i-1; k >= j; k --)
				{
					arr[k+1] = arr[k];
				}
				arr[j] = temp;
			}
        }
   }
   cout<<count<<endl;
   return;
}
int main(void)
{
   int N;
   scanf("%d", &N);
   int arr[N], i;
   for(i = 0; i < N; i++)
   {
      scanf("%d", &arr[i]);
   }
   insertionSort(N, arr);
   return 0;
}
