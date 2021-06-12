    
/*Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
*/
static bool cmp(string& a,string& b)
{ 
  return a.length()>b.length();
}

//to return duplicates
    set<string> dup(vector<string>& strs)
    {
        set<string> dupli,orig;
        for(auto i:strs)
        {
            if(orig.find(i)!=orig.end())
                dupli.insert(i);
            else
                orig.insert(i);
            
             
        }
        return dupli;
    }
//to check if its subsequence of other string
    bool subs(string& a,string& b)
    {
       int i=0,j=0;
        while(i<a.length() and j<b.length())
        {
            if(a[i]==b[j]) j++;
            i++;
                
        }
        return j==b.length();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),cmp);//so that longest strings come up
        set<string> duplicate = dup(strs);
        for(int i=0;i<strs.size();i++)
        {
            if(duplicate.find(strs[i])==duplicate.end())
             { 
            if(i==0)  return strs[0].length(); //if no duplicates then 1st one is the longest uncommon subsequence
            for(int j=0;j<i;j++)
            {
                if(subs(strs[j],strs[i])) break;
                if(j==i-1) return strs[i].length();
            }
             
        }
            
        }
        return -1;
    }
