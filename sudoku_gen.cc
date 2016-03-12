#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
int sudoku[9][9] = {0};
int Right[3][3] = {{0,0,1}, {1,0,0}, {0,1,0}};

void print()
{
      for(int i =0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            cout<<sudoku[j][i]<<" ";
        }cout<<endl;
    }
}

int arr_init(vector<int> arr, int x, int pointer)
{
    if(pointer == 9) return 0;
    vector<int>::iterator pos;
    pos = arr.begin() + pointer;
    for(int i = 0; i < 9; i++)
    {
        if(pos == arr.end()) pos = arr.begin();
        sudoku[i][x] = *pos++;
    }
    arr_init(arr, x + 1, pointer + 3);
}

int multiple(int x, int y) // multiple by Right _arr
{
    int tmp = 0;
    int cnt = 0;
    int right_x = x % 3;
    if( x < 3 ) x = 0;
    else if( 3 <= x && x < 6  ) x=3;
    else x = 6;
    
    for(int i = x; i < x + 3; i++)
    {
        tmp += sudoku[i][y] * Right[right_x][cnt++];
    }
    return tmp;
}

int generate(int x, int y) // generate rest line of sudoku 
{
   for(int i = y; i < y + 3; i++)
   {
       for(int j = x; j < x + 3; j++)
       {
           sudoku[j][i+3] = multiple(j,i);
       }
   }
}

int main()
{
    vector<int> num;
    srand((unsigned int)time(NULL)); //random using by current time!
    int a, b, tmp;
    int cnt = rand() % 1000;
    for(int i = 0 ; i < 9; i++)
    {
        num.push_back(i+1);
    }
    //random swap! count, a, b are random!
    while(cnt --)
    {
        a = rand() % 9;
        b = rand() % 9;
        tmp = num[a];
        num[a] = num[b];
        num[b] = tmp;
    }
    
    arr_init(num, 0, 0); //initialize first three line!
    
    for(int k = 0; k < 7; k+=3)
    {
        for(int r = 0; r < 4; r+=3)
        {
            generate(k,r);
        }
    }
    
    print();
}

///////////////////////////////////////////////
// using right rotate multiple by Right _ arr
//  123     312
//  456  >> 645
//  789     978
/////////////////////////