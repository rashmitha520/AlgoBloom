#include<vector>
string encode(string src)
{     
  
  string s="";int c=0;
  vector<int> v(26,0);
  for(int i=0;i<src.length();i++){
      if(i==0){
          s+=(src[i]);
         
          v[src[i]-'a']++;
         
      }
      else if(v[src[i]-'a']==0) {
          s+=(v[src[i-1]-'a']+'0');
          s+=(src[i]);
         
          v[src[i-1]-'a']=0;
          v[src[i]-'a']++;
       
      }
      else{
          v[src[i]-'a']++;
      }
  }
  s+=(v[src[src.length()-1]-'a']+'0');
  
  return s;
} 
