#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, h, w, r, c;
int best, size, msize;
vector<vector<int>> board;
vector<vector<pair<int, int>>> lst;
vector<vector<int>> rotate(vector<vector<int>> &set)
{
    vector<vector<int>> rest(set[0].size(), vector<int>(set.size(), 0));
    for(int i = 0; i < set.size(); i++)
        for(int j = 0; j < set[0].size(); j++)
            rest[j][set.size()-1-i] = set[i][j];
    return rest;
}
bool cover(int x, int y, int idx, int stat)
{
    int cnt = -1;
    for(int i = 0; i < lst[idx].size(); i++)
    {
        int x1 = x + lst[idx][i].first;
        int y1 = y + lst[idx][i].second;
        if(x1 >= w || x1 < 0 || y1 >= h || y1 < 0 || board[y1][x1] == stat) break;
        board[y1][x1] = stat;
        cnt++;
    }
    if(cnt != lst[idx].size()-1)
    {
        for(int i = cnt; i >= 0; i--)
        {
            int x1 = x + lst[idx][i].first;
            int y1 = y + lst[idx][i].second;
            board[y1][x1] = !stat;
        }
        return false;
    }
    board[y][x] = stat ? 1:0;
    return true;
}
void boardcover2(int sum, int rest)
{
	if(sum + rest / size <= best) return;
	int y = -1, x = -1;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
			if(board[i][j] == 0)
			{
				y = i, x = j;
				break;
			}
		if(y != -1)
			break;
	}
	if(y == -1) {best = max(best, sum); return; }
	for(int i=0; i < lst.size(); i++)
		if(cover(x,y,i,1))
		{
			boardcover2(sum+1, rest - size);
			cover(x,y, i, 0);
		}
	board[y][x] = 1;
	boardcover2(sum, rest - 1);
	board[y][x] = 0;
}
int main()
{
    char input;
    cin>>t;
    while(t--)
    {
        cin>>h>>w>>r>>c;
        board = vector<vector<int>>(h, vector<int>(w, 0));
        vector<vector<int>> block(r, vector<int>(c, 0)), temp[4], blk;
        lst = vector<vector<pair<int, int>>>(4);
        best = msize = size = 0;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
            {
                cin>>input;
                if(input == '#') {board[i][j] = 1; continue;}
                msize++;
            }
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                cin>>input;
                if(input == '#') block[i][j] = 1, size++;
            }
        temp[0] = block;
        for(int i = 1; i <= 3; i++)
            temp[i] = rotate(temp[i-1]);
        for(int i = 0; i < 4; i++)
        {
            int x1 = -1, y1 = -1;
            for(int y = 0; y < temp[i].size(); y++)
                for(int x = 0; x < temp[i][0].size(); x++)
                    if(temp[i][y][x])
                    {
                        if(y1 == -1) {x1 = x, y1= y; continue;}
                        lst[i].push_back(make_pair(x-x1, y-y1));
                    }
        }
        sort(lst.begin(), lst.end());
        lst.erase(unique(lst.begin(), lst.end()), lst.end());
        boardcover2(0, msize);
        cout<<best<<"\n";
    }
}
