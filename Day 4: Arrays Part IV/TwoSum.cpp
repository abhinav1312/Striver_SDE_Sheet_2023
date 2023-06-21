// CODING NINJAS PAIR SUM 
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

vector<vector<int> > pairSum(vector<int> &arr, int s){

   vector<vector<int> > ans;
   
   map<int, int> mp;
   // store occurence of numbers in a map on traversing
   for(int i=0; i<arr.size(); i++){
      int num1 = arr[i];
      int num2 = s-arr[i];

      bool found = mp.find(num2) != mp.end();
      if(found){
         int num2Occ = mp[num2]; // total occurences of num2

         int minNum = num1 <= num2 ? num1 : num2;
         int maxNum = num1 > num2 ? num1 : num2;
         vector<int> temp;
         temp.push_back(minNum);
         temp.push_back(maxNum);

         // while loop if number occured multiple times, pair has to made for all of them
         while(num2Occ--){
            ans.push_back(temp);
         }
      }

      mp[arr[i]]++;
   }
   sort(ans.begin(), ans.end());
   return ans;
}

int main()
{   
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    vector<vector<int> > ans = pairSum(arr, 5);

    // print
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    cout<<endl;
    return 0;
}