#include <iostream>
using namespace std;

int T, n, a[10000], m;

int f(int m)
{
    m = max(0, m);
    int cnt = 0;
    for(int i=0; i<n;i++)
	{
		cnt += (a[i]-m)/5 + (a[i]-m)%5/2 + (a[i]-m)%5%2;
	}
	return cnt;
}

int main()
{
   cin >> T;
   while(T--)
   {
      m = 1<<28;
      cin >> n;
      for(int i=0; i<n;i++)
	  {
		  cin >> a[i];
		  m = min(m,a[i]);
	  }

      cout <<  min(min(f(m), f(m-1)),f(m-2)) << endl;
   }
   return 0;
}
