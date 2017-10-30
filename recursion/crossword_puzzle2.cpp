#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct puzzle
{
  int row;
  int col;
  int dir;
  int size;
  char content[10];
  int match_num;
};

int counter;

vector<string> puzzle_word;
vector<struct puzzle> puzzle_case;

char input[12][12];


void search2(int index, int mode)
{
 int start_point = -111;
 
 if(mode == 0) // hor
 {
  for(int i=1; i<12; ++i)
  {
   if(input[index][i] != '+') 
   {
    if(start_point == -111)
    {
     start_point = i;
    }
   }
   else
   {
    if( (start_point != -111) && (i-start_point > 1) )
    {
     puzzle temp;

     temp.row = index;
     temp.col = start_point;
     temp.size = i - start_point;
     temp.dir = mode;

     for(int j=0; j<temp.size; ++j)
     {
      int current = start_point+j;

      if(input[index][current] == '-' )// && (input[index][current+1] != '+' ) )
      {
       if( (input[index-1][current] == '+' ) && (input[index+1][current] == '+' ) )
       {
        input[index][current] = '@';
       }
       else
       {
        input[index][current] = '@' + (++counter);
       }
      }
     
      temp.content[j] = input[index][current];
     } 

     puzzle_case.push_back(temp);
    }

    start_point = -111;
   }
  }

 }
 else  //ver
 {
  for(int i=1; i<12; ++i)
  {
   if(input[i][index] != '+') 
   {
    if(start_point == -111)
    {
     start_point = i;
    }
   }
   else
   {
    if( (start_point != -111) && (i-start_point > 1) )
    {
     puzzle temp;

     temp.row = start_point;
     temp.col = index ;
     temp.size = i - start_point;
     temp.dir = mode;

     for(int j=0; j<temp.size; ++j)
     {
      int current = start_point+j;

      if(input[current][index] == '-' )// && (input[index][current+1] != '+' ) )
      {
       if( (input[current][index-1] == '+' ) && (input[current][index+1] == '+' ) )
       {
        input[current][index] = '@';
       }
       else
       {
        input[current][index] = '@' + (++counter);
       }
      }
     
      temp.content[j] = input[current][index];
     } 

     puzzle_case.push_back(temp);
    }

    start_point = -111;
   }
  }
 }
}

int print_it(void)
{
 int i, j;
 
 for (vector<struct puzzle>::iterator it = puzzle_case.begin() ; it != puzzle_case.end(); ++it)
 {
  int cur_row = it->row;
  int cur_col = it->col;

  int answer_num = it->match_num;
  string str = puzzle_word[answer_num];
  
  for (i=0; i<str.length(); ++i)
  {
   input[cur_row][cur_col] = str[i];
   
   if(it->dir == 0) //hor
   {
    ++cur_col;
   }
   else
   {
    ++cur_row;
   }
  }
 }

 // coutput
 for(i=1; i<11; i++)
 {
  for(j=1; j<11; j++)
  {
   cout << input[i][j];
  }
  cout << endl;
 }  
 
 exit(1);
}


int matching(int depth) 
{
 bool isvalid = false;
 
 if(depth >= puzzle_case.size())
 {
  char check_list[40];
  
  memset(check_list, 0x00, 40);
  
  for (vector<struct puzzle>::iterator it = puzzle_case.begin() ; it != puzzle_case.end(); ++it)
  {
   for(int i=0; i<it->size; ++i)
   {
    if(it->content[i] != '@')
    {
     int temp = it->content[i] - '@' ;
     
     //cout<< "~~~~~~" << it->content[i] << "    " << it->match_num  << endl;
     
     if(check_list[temp] == 0x00)
     {
      check_list[temp] =  puzzle_word[it->match_num].at(i);
     }
     else
     {
      if(check_list[temp] != puzzle_word[it->match_num].at(i))
       return 1;
     }
    }
   }
  }
  
  print_it();
 }
 
 for(int i=0; i<puzzle_word.size(); ++i)
 {
  if(puzzle_word[i].size() == puzzle_case[depth].size)
  {
   isvalid = true;
   
   for (int j=0; j<depth; ++j)
   {
    if(puzzle_case[j].match_num == i)
    {
     isvalid = false;
     break;
    }
   }
   
   if(isvalid == true)
   {
    puzzle_case[depth].match_num = i;
    matching(depth+1);
   }
  }
 } 
 
 return 1;
}

int main()
{
 int i, j;
 string str, str2;

 counter = 0;

 for(i=0; i<12; ++i)
 {
  for(j=0; j<12; ++j)
  {
   input[i][j] = '+';
  }
 }
 
    // INPUT TABLE
 for(i=1; i<11; ++i)
 {
  getline(cin, str);
  
  for(j=1; j<11; ++j)
  {
   input[i][j] = str[j-1];
  }
 }
    
 // INPUT WORD
 getline(cin, str);
 str.push_back(';');
 str2.erase (str2.begin(), str2.end());
 
 for (i=0; i<str.length(); ++i)
 {
  if(str[i] == ';')
  {
   if(!str2.empty())
   {
    puzzle_word.push_back(str2);
    str2.erase (str2.begin(), str2.end());
   }
  }
  else
  {
   str2.push_back(str[i]);
  }
 }
 
 // search
 for(i=1; i<11; ++i)
 {
  search2(i, 0);
 }

 // search
 for(i=1; i<11; ++i)
 {
  search2(i, 1);
  
 }
    
 // matching
 matching(0);
    
/*
 // coutput
 for(i=1; i<11; i++)
 {
  for(j=1; j<11; j++)
  {
   cout << input[i][j];
  }
  cout << endl;
 }  

 //
 for (vector<string>::iterator it = puzzle_word.begin() ; it != puzzle_word.end(); ++it)
    {
  cout << *it << endl;
 }

 for (vector<struct puzzle>::iterator it = puzzle_case.begin() ; it != puzzle_case.end(); ++it)
    {
  for(i=0; i<10; ++i)
  {
   cout << it->content[i];
  }
  cout << "  " <<  it->dir  << "  " <<  it->row << "  " <<  it->col << "  " <<  it->size << endl;
 }
*/
    
    return 1;
}


