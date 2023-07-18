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

bool knows(int a, int b){
    // implemented by the platform itself (Coding Ninjas)
}

int findCelebrity(int n) {
    stack<int> st;
 	for(int i=0; i<n; i++){
        st.push(i);
    }

    while(st.size() > 1){
        int top1 = st.top();
        st.pop();
        int top2 = st.top();
        st.pop();

        if(knows(top1, top2) && !knows(top2, top1)) st.push(top2);
        else if(knows(top2, top1) && !knows(top1, top2)) st.push(top1);
    }
    
    if(st.empty()) return -1;
    
    int probableCeleb = st.top();
    for(int i=0; i<n; i++){
        if(probableCeleb != i && !knows(i, probableCeleb)) return -1;
    }
    return probableCeleb;
    
}

int main()
{
    return 0;
}