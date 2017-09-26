#include <iostream>
using namespace std;

class SolutionMatrix{
	public:
		int solve(int array[][3], int rows, int columns, int index_row, int index_col){
			if(index_row == rows - 1 && index_col == columns - 1){
				return array[index_row][index_col];
			}
			if(array[index_row][index_col] == 0){
				return -1;
			}
			int r_result;
			if( index_row < rows - 1){
				r_result = solve(array, rows, columns, index_row+1, index_col);
			}
			int c_result;
			if( index_col < columns - 1){
				c_result = solve(array, rows, columns, index_row, index_col+1);
			}
			if(r_result == -1 && c_result == -1){
				return -1;
			}
			if(r_result == -1 ){
				return array[index_row][index_col] + c_result;
			}
			if(c_result == -1){
				return array[index_row][index_col] + r_result;
			}
			
			return (r_result < c_result) ? (array[index_row][index_col] + r_result) : (array[index_row][index_col] + c_result);
		}
};


int main(){
	int a[2][3] = {1,1,1,2,2,1};
	SolutionMatrix sol;
	cout << sol.solve(a, 2, 3, 0, 0);
	return 0;
}
