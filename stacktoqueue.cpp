#include<iostream>
#include<stack>
using namespace std;

/** 
 * 用两个栈来实现一个队列，
 * 完成队列的Push和Pop操作。
 * 队列中的元素为int类型。
 */
class Solution
{
public:
    void push(int node){
        stack1.push(node);
    }
    int pop(){
        try{
	    if(stack1.empty()){
	        throw "栈已为空，pop失败";
	    }
	}catch{const char* msg){
	    cerr<<msg<<endl;
	}
	while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        value = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return value;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
