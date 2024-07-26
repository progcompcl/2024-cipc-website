#include <bits/stdc++.h>
using namespace std; 

int main(){
  int n;
  int D, E;
  cin >> n >> D >> E;
  int mn = n;
  while(n >= 0){
    mn = min(mn, n % D);
    n -= 5*E;
  }
  cout << mn << "\n";
}
