#include <iostream>
#include <vector>
using namespace std;
int sudoku[9][9] = {0};
int Right[3][3] = {{0,0,1}, {1,0,0}, {0,1,0}};

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
int multiple(int x, int y)
{
    cout<< x << " "<<y<<endl;
    int tmp = 0;
    int cnt = 0;
    int right_x = x % 3;
    if( x < 3 ) x = 0;
    else if( 3 <= x < 6  ) x = 3;
    else x = 6;
    
    for(int i = x; i < x + 3; i++)
    {
        tmp += sudoku[i][y] * Right[right_x][cnt++];
    }
    return tmp;
}

int generate(int x, int y)
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
    for(int i = 0 ; i < 9; i++)
    {
        num.push_back(i+1);
    }
    arr_init(num, 0, 0);
    generate(6,0);
    for(int i =0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            cout<<sudoku[j][i]<<" ";
        }cout<<endl;
    }
    cout<<sudoku[6][0]<<endl;
}