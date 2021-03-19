class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     vector<string> v;map<string,int> st;int n=s.length();
        for(int i=0;i<n-9;i++)
        {//generate respective substrings of length 10
          string sub=(s.substr(i,10));
            //increment count 
                st[sub]++;
            //if repeated once then push back
               if(st[sub]==2)
                {
                   v.push_back(sub);
               }
                
        }
        
        
        return v;
    }
};
