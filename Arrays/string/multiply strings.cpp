class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.length(),l2=num2.length();
        vector<int> v(l1+l2,0);
        if(num1=="0"||num2=="0") return "0";
        for(int i=l1-1;i>=0;i--)
        {
            for(int j=l2-1;j>=0;j--)
            {
                
                v[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                //carry
                v[j+i]+=v[j+i+1]/10;
                //if digit > = 10 then carry is eleiminated
                v[i+j+1]%=10;
                
                
            }
        }
        string s="";
        int i=0;
        //to eliminate extra 0s e.g. 3*2=06
        while(i<(l1+l2) && v[i]==0) i++; 
        //conversion into string
        while(i<(l1+l2)) {s.push_back(v[i]+'0');i++;}
        return s;
    }
};
