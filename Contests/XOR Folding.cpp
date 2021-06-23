
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            char c;
	            cin>>c;
	            if(c=='1') res++;
	        }
	    }
	    if(res%2) cout<<"YES"<<endl; //if all ones are odd then only it will be 1
	    else cout<<"NO"<<endl;
	}
	return 0;
}
