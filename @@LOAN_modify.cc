#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
    int t, m;
    double n, p;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>p;
        double hell = (p/12)/100;
        double lo = 0;
        double hi = n+(n*hell)+1; // max value of hi added 1 
        for(int i= 0; i < 54; i++) // 54 -> max(lo-hi) 크게잡아 10^9, 2^54 ~= 10^16  
        {
            double mid = lo + (hi-lo)/2;
            double temp = n;
            for(int j = 0; j < m; j++)
            {
                temp += (temp * hell), temp -= mid;
                if(temp < 0) break;
            }
            if(temp < 0) hi = mid;
            else lo = mid;
        }
        cout<<(lo+(hi-lo)/2)<<"\n";
    }
}