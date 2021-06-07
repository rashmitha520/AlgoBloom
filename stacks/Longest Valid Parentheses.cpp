 
 int longestValidParentheses(string s) {
        int l=0,r=0,maxi=0;
        for(int i=0;i<s.length();i++) //left to right
        {
            if(s[i]=='(') l++;
            else  r++;
            if(l==r) maxi=max(l+r,maxi);
            else if(r>l) r=l=0;
            
            
        }
        l=r=0;
        for(int i=s.length()-1;i>=0;i--) //right to left
        {
             if(s[i]=='(') l++;
            else  r++;
            if(l==r) maxi=max(l+r,maxi);
            else if(l>r) r=l=0;
            
        }
        return maxi;
    }

//stack approach
 int longestValidParentheses(string str) {
          int n = str.length(); 
  
    // Create a stack and push -1 as  
    // initial index to it. 
    stack<int> stk; 
    stk.push(-1); 
  
    // Initialize result 
    int result = 0; 
  
    // Traverse all characters of given string 
    for (int i = 0; i < n; i++) 
    { 
        // If opening bracket, push index of it 
        if (str[i] == '(') 
            stk.push(i); 
          
        // If closing bracket, i.e.,str[i] = ')' 
        else 
        { 
            // Pop the previous opening 
            // bracket's index 
            if (!stk.empty())  
            { 
                stk.pop(); 
            } 
              
            // Check if this length formed with base of 
            // current valid substring is more than max 
            // so far 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
  
            // If stack is empty. push current index as 
            // base for next valid substring (if any) 
            else
                stk.push(i); 
        } 
    } 
  
    return result; 
    }
