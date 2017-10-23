#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int sum = 0;
int power_of_sum(int X, int N, int input)
{
    int value = static_cast<int>(X - pow(input, N));
    if(value < 0) return 0;
    else if(value == 0) return 1;
    else   return power_of_sum(value,N,input+1) + power_of_sum(X,N,input+1);
}
int main()
{
    int X;
    cin >> X;
    int N;
    cin >> N;
    cout<<power_of_sum(X,N,1)<<endl;
    return 0;
}
