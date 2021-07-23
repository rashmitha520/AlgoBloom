    int minNumberOperations(vector<int>& target) {
      int ups=target[0];
      for(int i=1;i<target.size();i++)
      {
          ups+=max(target[i]-target[i-1],0);
      }
       return ups; 
    }
