#include <set>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_CHAR 2000
char login[MAX_CHAR];
set<string> wrongmatched;

int matchPassword(vector<string> &pwords,
        const char *login, vector<int> &correct_idx, int &done)
{
    if (!*login)
    {
      done = 1;
      return 1; //login string has been reduced
    }

    if (wrongmatched.find(login) != wrongmatched.end())  return 0;

    for(int i=0; i<pwords.size()&&!done; ++i)
    {
        if (!strncmp(login, pwords[i].c_str(), pwords[i].size()))
        {
            correct_idx.push_back(i);
            if (!matchPassword(pwords, login+pwords[i].size(), correct_idx, done))
            {
                correct_idx.pop_back();
                wrongmatched.insert(login);
            }
        }
    }
    return done;
}

void crackPassword(vector<string> &pwords, const char *login)
{
    vector<int> correct_idx;
    int done = 0;
    matchPassword(pwords, login, correct_idx, done);
    string s;

    wrongmatched.clear();
    if (done && correct_idx.size())
    {
        for(int i =0; i<correct_idx.size(); ++i)
        {
            cout<< pwords[correct_idx[i]].c_str() << " ";
        }
        cout<<endl;
    } else   cout<< "WRONG PASSWORD" << endl;
}

int main()
{
    int testcase, seperated_string_count;

    cin >> testcase;

    while(--testcase)
    {
        vector<string> pwords(seperated_string_count);
        cin >> seperated_string_count;
        for(int i = 0; i < seperated_string_count; i++)
            cin >> pwords[i];
        cin >>login;
        crackPassword(pwords, login);
    }
}

