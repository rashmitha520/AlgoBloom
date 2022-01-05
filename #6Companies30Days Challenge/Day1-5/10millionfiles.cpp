//method-1
sort(files.begin(),files.end());
for(int i=0;i<10;i++)
  cout<<files[i]<<" ";

//method-2
void func(vector<int> files)
{priority_queue<int, vector<int>, greater<int>> p;

for(int i=0;i<files.size();i++)
{
  p.push(files[i]);
  while(p.size()>10)
  {
    p.pop();
  }
}
while(p.size()>0){
  cout<<p.top()<<endl;
  p.pop();
}
}
