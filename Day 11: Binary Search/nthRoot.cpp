#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;

int NthRoot(int n, int m) {
  int s = 0, e = m, mid = s + (e-s)/2;
  
  while(s<=e){
    mid = s + (e-s)/2;
    if(pow(mid, n) > m) e = mid-1;
    else if(pow(mid, n) < m) s = mid+1;
    else return mid;
  }

  return -1;
}

int main()
{   
    cout<<NthRoot(3, 27)<<endl;
    return 0;
}