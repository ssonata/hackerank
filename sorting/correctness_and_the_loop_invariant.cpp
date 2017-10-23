#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
void insertionSort(int N, int arr[]) {
   int i,j;
   int value;
   for(i=1;i<N;i++)
   {
        for(j=0; j<i;j++)
        {
			if(arr[i]< arr[j])	swap(arr[i],arr[j]);
        }
   }
   for(j=0;j<N;j++)
   {
       printf("%d",arr[j]);
       printf(" ");
   }
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
