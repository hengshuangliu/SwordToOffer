#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size() <= 0){
        	while(stack1.size()>0){
        		int tmp = stack1.top();
        		stack1.pop();
        		stack2.push(tmp);
			}
		}
		if(stack2.size() == 0){
			throw new exception();
		}
		int result = stack2.top();
    	stack2.pop();
    	return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
	return 0;
}
