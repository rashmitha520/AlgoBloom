#include <iostream>
#include <string>
using namespace std;
string v[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void helper(int num, string output)
{
    if(num==0||num==1) 
    {
        cout<<output<<endl;
        return;
    }
    
    int last=num%10;
    string s=v[last];
    for(int i=0;i<s.length();i++)
    {    
        helper(num/10,s[i]+output);
    }
}
void printKeypad(int num){
  string output="";

helper(num,output);


}
