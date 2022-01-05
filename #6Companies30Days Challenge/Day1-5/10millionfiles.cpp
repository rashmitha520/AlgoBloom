//method-1
sort(files.begin(),files.end());
for(int i=0;i<10;i++)
  cout<<files[i]<<" ";

//method-2
priority_queue<int> func(vector<int> files)
{priority_queue<int> p;

for(int i=0;i<files.size();i++)
{
  p.push(files[i]);
  while(p.size()>10)
  {
    p.pop();
  }
}
return p;
}
