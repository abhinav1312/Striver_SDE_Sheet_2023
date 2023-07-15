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

class LRUCache {
    list<int> l; // store key : head = most recently usedm tail = lru
    map<int, int> keyVal;
    unordered_map<int, list<int>::iterator> address;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // key not present in lru
        if(address.find(key) == address.end()) return -1;

        // key present
        l.erase(address[key]);
        l.push_front(key);
        address[key] = l.begin();
        return keyVal[key];
    }
    
    void put(int key, int value) {
        // key already present
        if(address.find(key) != address.end()){
            l.erase(address[key]);
            l.push_front(key);
            address[key] = l.begin();
            keyVal[key] = value;
            return;
        }

        if(l.size() == cap){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            keyVal.erase(k);
        }

        l.push_front(key);
        address[key] = l.begin();
        keyVal[key] = value;
    }
};

int main()
{
    return 0;
}