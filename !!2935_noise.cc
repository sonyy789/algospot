#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string a, b; 
    char op;
    int lenA, lenB;
    cin>>a>>op>>b;
    lenA = a.size(); lenB = b.size();
    if(op == '+'){
        int len = (lenA>lenB?lenA:lenB);
        if(lenA == lenB) cout<<"2", len--;
        for(int i = len; i > 0; i--){
            if(i == lenA || i == lenB) cout<<"1";
            else cout<<"0";
        }
    }else{
        lenA--; lenB--; lenA += lenB;
        cout<<"1";
        for(int i = 0; i < lenA; i++) cout<<"0";
    }
}