#include <map>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	map<string, int> M;
	int n, m;
	string in;
	cin>>n>>m;
	while(n--){
		cin>>in;
		M[in] = 1;
	}
	n = 0;
	while(m--){
		cin>>in;
		if(M[in]) M[in] = -1, n++; 
	}
	cout<<n<<"\n";
	map<string, int>::iterator it = M.begin();
	for(it; it != M.end(); it++){
		if((*it).second == -1) cout<<(*it).first<<"\n";
	}
}