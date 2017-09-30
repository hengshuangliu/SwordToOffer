#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool found = false;
        int rows = array.size();
        int columns = 0;
        if(rows > 0){
        	columns = array[0].size();
		}
		if(rows > 0 && columns > 0){
			int row = 0;
			int column = columns - 1;
			while(row < rows && column >= 0){
				if(array[row][column] == target){
					found = true;
					break;
				}
				else if(array[row][column] < target){
					row ++;
				}
				else{
					column --;
				}
			}
		}
		return found;
    }
};
