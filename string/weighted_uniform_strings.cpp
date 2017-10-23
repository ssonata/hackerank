#include <vector>
#include <iostream>
using namespace std;
vector<bool>output;

void matching(string str)
{
    int previous = 0,sumofsum = 0;
    for(int i = 0; i < str.size(); i++)
    {                               
        if((int)str.at(i)-96 == previous)   sumofsum += previous;
        else								sumofsum = previous = (int)str.at(i)-96;
		output[sumofsum] = true;
    }
}
int main(){
    string str;
    int count,number;
    cin >> str >> count;
    output.assign(10e7,0);
    matching(str);
    for(int a0 = 0; a0 < count; a0++)
    {
        cin >> number;
        if(output[number])	cout<<"Yes"<<endl;
        else				cout<<"No"<<endl;
    }
    return 0;
}
