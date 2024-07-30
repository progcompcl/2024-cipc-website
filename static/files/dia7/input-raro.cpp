#include <iostream>
#include <string>
#include <sstream>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long

/*

in:
2 3 5
3 2
1 2 3 4 2 3

1

out:
linea con 3 numeros
2 3 5 
linea con 2 numeros
3 2 
linea con 6 numeros
1 2 3 4 2 3 
linea con 0 numeros

linea con 1 numeros
1 

*/



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        int x;
        vector<int> v;
        while(ss >> x){
            v.push_back(x);
        }
        cout << "linea con " << v.size() << " numeros" << endl;
        for(int y: v){
            cout << y << ' ';
        }
        cout << endl;
    }
}