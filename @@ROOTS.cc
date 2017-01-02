#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define LLIMIT -11
#define HLIMIT 11
using namespace std;
vector<double> coef;
double f(double x)
{
    int size = coef.size();
    double ret = 0;
    for(int i = 0; i < size; i++)
        ret += pow(x,size-i-1)*coef[i];
    return ret;
}
vector<double> differential(vector<double> & set3)
{
    vector<double> ret;
    int size = set3.size()-1;
    for(int i = 0; i < size; i++)
        ret.push_back(set3[i]*(size-i));
    return ret;
}
vector<double> find_value(vector<double> &set2)
{
    vector<double> ret;
    if(set2.size() == 2) ret.push_back(set2[1]/set2[0]);
    else
    {
        double temp = pow(set2[1],2)-4*set2[0]*set2[2];
        if(temp < 0) return ret; // if equation don't have x
        temp = sqrt(temp);
        ret.push_back((-temp-set2[1])/(2*set2[0]));
        double value = (temp-set2[1])/(2*set2[0]);
        if(value == ret[0]) return ret;
        ret.push_back(value);
    }
    return ret;
}
vector<double> roots(vector<double> &set)
{
    int size = set.size();
    if(size <= 3) return find_value(set);
    vector<double> diff = differential(set);
    vector<double> result = roots(diff), ret;
    result.insert(result.begin(), LLIMIT);
    result.insert(result.end(), HLIMIT);
    coef = set;
    for(int i = 0; i < result.size()-1; i++)
    {
        double lo = result[i];
        double hi = result[i+1];
        if(f(lo)*f(hi) > 0) continue;
        if(f(lo) > 0) swap(lo, hi);
        if(f(lo) == 0) continue;  // if lo == multiple root -> already included when value of hi is multiple root
        for(int j = 0; j < 100; j++)
        {
            double mid = (lo+hi)/2;
            double fmid = f(mid);
            if(fmid > 0) hi = mid;
            else lo = mid;
        }
        ret.push_back((lo+hi)/2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main()
{
    cout.setf(ios_base::floatfield, ios_base::fixed);
    cout.precision(11);
    int t, n;;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<double> arr(n+1);
        for(int i = 0; i < arr.size(); i++)
            cin>>arr[i];
        vector<double> ans = roots(arr);
        for(double data : ans)
            cout<<data<<" ";
        cout<<"\n";
    }
}