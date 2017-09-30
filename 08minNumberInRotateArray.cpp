#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length == 0){
        	return 0;
		}
		int index1 = 0, index2 = length - 1;
		int indexMid = (index2 + index1)/2;
		while(index1 < index2){
			if(index2 - index1 == 1){
				indexMid = index2;
				break;
			}
			indexMid = (index2 + index1)/2;
			if( rotateArray[index1] == rotateArray[index2] && rotateArray[indexMid] == rotateArray[index1] ){
				return minInOrder(rotateArray, index1, index2);
			}
			
			if(rotateArray[indexMid] <= rotateArray[index2]){
				index2 = indexMid;
			}
			else if(rotateArray[index1] <= rotateArray[indexMid]){
				index1 = indexMid;
			}
		}
		return rotateArray[indexMid];
    }
    
    int minInOrder(vector<int> rotateArray, int index1, int index2){
    	int min = rotateArray[index1];
    	for(int i = index1+1; i<=index2; ++i){
    		if(rotateArray[i] < min){
    			min = rotateArray[i];
			}
		}
		return min;
	}
};


int main(){
	return 0;
}
