    string decodeString(string s) {
       stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string rep,num;
             
                while(!st.empty() && st.top()!='['){
                    rep=st.top()+rep;st.pop();
                }
               // if(st.top()=='[') 
                    st.pop();
                while(!st.empty() && (st.top()>='0' && st.top()<='9')){
                    num=st.top()+num;st.pop();
                }
                int count=stoi(num);
                string result;
                for(int j=0;j<count;j++){
                    result+=rep;
                }
                for(auto j:result){
                    st.push(j);
                }
            }
            else{
                st.push(s[i]);
            }
            
        }
        while(!st.empty()){
            ans=st.top()+ans;st.pop();
        }
 return ans;
    }
