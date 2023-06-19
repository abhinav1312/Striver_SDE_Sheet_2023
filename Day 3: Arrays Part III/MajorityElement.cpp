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

int findMajorityElement(int arr[], int n) {
	// Moore's voting algo

	int cnt = 0, probMajElem;
	for(int i=0; i<n; i++){
		if(cnt == 0){
			cnt++;
			probMajElem = arr[i];
		}
		else if(probMajElem == arr[i]) cnt++;
		else cnt--;
	}

	cnt = 0;

	for(int i=0; i<n; i++){
		if(arr[i] == probMajElem) cnt++;
	}

	if(cnt > n/2) return probMajElem;
	return -1;

}

int main()
{
    int arr[] = {1, 1, 1, 2};
    int majElem = findMajorityElement(arr, 4);
    cout<<majElem<<endl;
    return 0;
}