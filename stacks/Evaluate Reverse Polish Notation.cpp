/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> s;
        int ans=0;
        for(int i=0;i<tokens.size();i++)
        {
            string st = tokens[i];
            if(st=="+"||st=="-"||st=="/"||st=="*")
            {
             int a=s.top();s.pop();
             int b=s.top(); s.pop();
                if(  tokens[i]=="+")
                {
                   
                    s.push(a+b);
                    
                }
               else  if(tokens[i]=="*")
                {
                    
                    s.push(a*b);
                   
                }
               else  if(tokens[i]=="/")
                {
                    
                  // if(b!=0)
                    s.push(b/a);
                    
                }
              else   if(tokens[i]=="-")
                {
                    
                    s.push(b-a);
                 
                }
            }
               else
           {    
                
                s.push(stoi(tokens[i]));
                
           }
            
        }
        return s.top();
    }
};
