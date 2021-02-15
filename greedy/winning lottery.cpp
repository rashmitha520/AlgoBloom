/*
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D.
You have to help Harshit and print the winning lottery number.
*/
int main() {

	// Write your code here
    int s,d;
    cin>>s>>d;
   vector<long long> num(d,0);num[0]=1;s=s-1;
    for(int i=d-1;i>=0;i--)
    {
        if(s<=9){num[i]=s;break;}
        else if(s>9){num[i]=9;s=s-9;}
    }
    for(int i=0;i<d;i++) 
        cout << num[i];
}
