#include <iostream>
#include <vector>
using namespace std;
vector<int> N;
vector<int> output;
int visit[10001];
void sum(int size)
{
	vector<int> temp(N.begin(),N.end());
	if(size != N.size())
	{
    	if(N[size] > N[size - 1])
    	{
          if(N[size] == 1 || N[size - 1] == 1)
          {
            visit[size] = 1;
            visit[size - 1] = 1;
          }
          else
          {
            if(size + 1 <= N.size())
            {
                if(N[size + 1] > N[size])
                {
                    N[size] = 1;
                    visit[size] = 1;
                    visit[size - 1] = 1;
                }
            }
            if(!visit[size -1])
            {
              N[size - 1] = 1;
              visit[size] = 1;
              visit[size - 1] = 1;
            }
            else
            {
              visit[size] = 1;
            }
          }
    	}
    	else if(N[size] < N[size - 1])
    	{
          if(N[size] == 1 || N[size - 1] == 1)
          {
              visit[size] = 1;
              visit[size - 1] = 1;
          }
          else
          {
            if(!visit[size])
            {
                N[size] = 1;
                visit[size] = 1;
                visit[size - 1] = 1;
            }
            else
            {
                visit[size - 1] = 1;
            }
    	    }
    	}
      else
      {
          if(N[size] == 1 || N[size - 1] == 1)
          {
              visit[size] = 1;
              visit[size - 1] = 1;
          }
          else if(N[size - 2] != 1)
          {
              N[size - 1] = 1;
              visit[size]  = 1;
          }
      }
    	sum(size + 1);
	}
	return;
}
void sherlock_and_cost()
{
	int count,num, total;
	cin >> count;
	for(int i = 0; i < count; i++)
	{
		cin >> num;	
		N.push_back(num);
	}
	if(N.size() == 1)
	{
		output.push_back(N[0]);
	}
	else
	{
		sum(1);
		total = 0;
		for(int i = 1; i < N.size(); i++)
		{
			total += abs(N[i] - N[i-1]);
		}
		output.push_back(total);
	}
	return;
}
int main()
{
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++)
	{
		sherlock_and_cost();
	//	N.clear();
		for(int j = 0; j < 10001; j++)
		{
			visit[j] = 0;
		}
	}
	vector<int>::iterator iter2 = N.begin();
	for(;iter2 != N.end();++iter2)
	{
		cout<<*iter2<<endl;
	}
	vector<int>::iterator iter = output.begin();
	for(;iter != output.end();++iter)
		cout<<*iter<<endl;
	return 0;
}
