class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int n1, n2;
        
        for (auto c: tokens){

            if (c=="+" || c=="-" || c=="*" || c=="/"){
                n1 = nums.top();
                nums.pop();
                n2 = nums.top();
                nums.pop();

                if (c == "+") {
                nums.push(n1 + n2);
                } else if (c == "-") {
                    nums.push(n2 - n1);
                } else if (c == "*") {
                    nums.push(n1 * n2);
                } else if (c == "/") {
                    nums.push(n2 / n1);
                } 
        }   
            else{
                nums.push(stoi(c));
            }
        }

        return nums.top();
    }
};
