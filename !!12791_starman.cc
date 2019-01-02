#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    vector<pair<int, string>> B = {{1967, "DavidBowie"},
{1969, "SpaceOddity"},
{1970, "TheManWhoSoldTheWorld"},
{1971, "HunkyDory"},
{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
{1973, "AladdinSane"},
{1973, "PinUps"},
{1974, "DiamondDogs"},
{1975, "YoungAmericans"},
{1976, "StationToStation"},
{1977, "Low"},
{1977, "Heroes"},
{1979, "Lodger"},
{1980, "ScaryMonstersAndSuperCreeps"},
{1983, "LetsDance"},
{1984, "Tonight"},
{1987, "NeverLetMeDown"},
{1993, "BlackTieWhiteNoise"},
{1995, "1.Outside"},
{1997, "Earthling"},
{1999, "Hours"},
{2002, "Heathen"},
{2003, "Reality"},
{2013, "TheNextDay"},
{2016, "BlackStar"}};
    int n, a, b;
    cin>>n;
    for(int i = 0; i < n; i++){
        int c = 0, d = -1;
        cin>>a>>b;
        for(int j = 0; j < 25; j++)
            if(B[j].first >=a && B[j].first <= b){
                c++;
                if(d == -1) d = j;
            }
        cout<<c<<"\n";
        for(int j = d; j < d+c; j++)
            cout<<B[j].first<<" "<<B[j].second<<"\n";
    }
}