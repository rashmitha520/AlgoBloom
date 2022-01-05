
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        string ans;int count=1;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='D'){
                st.push(count);
                count++;
            }
            else{
               st.push(count);
               count++;
               while(st.size()>0){
                   ans+=st.top()+'0';st.pop();
               }
            }
            
        }
        st.push(count);
         while(st.size()>0){
                   ans+=st.top()+'0';st.pop();
               }
               return ans;
    }
};

