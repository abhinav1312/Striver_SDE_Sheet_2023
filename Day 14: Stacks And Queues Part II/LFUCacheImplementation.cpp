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

class LFUCache {
  map<int, list<int>> freqList;          // same frequncy elements in list
  map<int, list<int>::iterator> address; // store the address
  map<int, int> keyFreq;
  map<int, int> keyVal;
  int minFreq;
  int cap;
  int size;

public:
  LFUCache(int capacity) {
    minFreq = 0;
    cap = capacity;
    size = 0;
  }

  int get(int key) {
    if (keyFreq.find(key) == keyFreq.end()){
      return -1;

    }
    // store frequency of the key
    int freq = keyFreq[key];

    // delelte element from freqList and add to adjacent key
    // ie.e if element freq was 1, delete it from 1 and insert in 2
    freqList[freq].erase(address[key]);

    // push key in freq+1
    freqList[freq + 1].push_front(key);

    // update address
    address[key] = freqList[freq + 1].begin();

    // update frequency
    keyFreq[key]++;

    // update minFreq if required
    if (freqList[freq].size() == 0 && minFreq == freq) {
          minFreq = freq+1;
        }
    return keyVal[key];
}

  void put(int key, int value) {
    // if key already present
    if (keyFreq.find(key) != keyFreq.end()) {
      int val = keyVal[key];
      // store frequency of the key
      int freq = keyFreq[key];

        // delelte element from freqList and add to adjacent key
        // ie.e if element freq was 1, delete it from 1 and insert in 2
        freqList[freq].erase(address[key]);

        // push key in freq+1
        freqList[freq + 1].push_front(key);

        // update address
        address[key] = freqList[freq + 1].begin();

        // update frequency
        keyFreq[key]++;
        keyVal[key] = value;

        // update minFreq if required
        if (freqList[freq].size() == 0 && minFreq == freq) {
          minFreq = freq+1;
        }
      return;
    }
    else{
        // key not yet present
        if(size == cap){ // lfu full
            int k = freqList[minFreq].back();
            // cout<<"K: "<<k<<endl;

            // delete key
            freqList[minFreq].pop_back();

            // remove its frequency
            keyFreq.erase(k);

            // remove its address
            address.erase(k);

            // remove value
            keyVal.erase(k);
            size--;
        } 
        freqList[1].push_front(key);
        address[key] = freqList[1].begin();
        keyFreq[key] = 1;
        keyVal[key] = value;
        size++;
        minFreq = 1;
    }
  }
};

int main()
{
    return 0;
}