#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int c=0;
    for(int i=n-1;i>=2;i--)
    {  if(v[i]==i+1) continue;
     else{
        //if(v[i]-i>2) {cout<<"NO";return 0;}
        if(v[i-1]==i+1 ) {
            c++; 
            swap(v[i],v[i-1]);
        }
        else if(v[i-2]==i+1) {
            c+=2;
           swap(v[i-2],v[i-1]);
            swap(v[i-1],v[i]);
            
        }
         else{cout<<"NO";return 0;}
     }
    }
    if(v[0]==2 && v[1]==1)
	{
		v[0] = 1;
		v[1] = 2;
		c += 1;
		cout << "YES" << endl << c;
	}
	else if(v[0]==1 && v[1]==2)
	{
		cout << "YES" << endl << c;
	}
	else
	{
		cout << "NO";
	}
}
