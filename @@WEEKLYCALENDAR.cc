#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, mon, date, result[7];
    string day;
    int date_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    unordered_map<string, int> day_arr = {{"Sunday",0}, {"Monday",1}, {"Tuesday",2}, {"Wednesday",3}, {"Thursday",4}, {"Friday",5}, {"Saturday",6}};
    unordered_map<string, int>::iterator pos;
    cin>>T;
    while(T--)
    {
        cin>>mon>>date>>day;
        pos = day_arr.find(day);
        int index = (*pos).second;
        int tmp_date = date;
        for(int i = index; i < 7; i++)
        {
            result[i] = date++;
            if(date - 1 == date_arr[mon-1])
            {
                if(++mon == 12) mon = 1;
                date = 1;
            }
        }
        for(int i = index; i >= 0; i--)
        {
            result[i] = tmp_date--;
            if(tmp_date == 0)
            {
                if(--mon == 0) mon = 12;
                tmp_date = date_arr[mon-1];
            }
        }
        for(int i = 0; i < 7; i++)
            cout<<result[i]<<" ";
        cout<<"\n";
    }
}