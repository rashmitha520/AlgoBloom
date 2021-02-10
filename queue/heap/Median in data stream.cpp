class MedianFinder {
     
public:
   priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    MedianFinder() {
        
    }
      double findMedian() {
       if(maxi.size()==0 && mini.size()==0) return 0;   
    else if(maxi.size()<mini.size()) return mini.top();
    else if(maxi.size()>mini.size()) return maxi.top();
       return ((double)maxi.top()+mini.top())*0.5;
    }
    void addNum(int num) {
       int median=findMedian();
      if(maxi.size()==mini.size())
      {
          if(num<median)
              maxi.push(num);
          
          else mini.push(num);
      }
      if(maxi.size()<mini.size())
      {
          if(num<median)
              maxi.push(num);
          else 
          {
              maxi.push(mini.top());
             // if(mini.size()!=0)
              mini.pop();
              mini.push(num);
          }
      }
        else
      {
          if(num>median)
              mini.push(num);
          else 
          {
               mini.push(maxi.top());
             // if(maxi.size()!=0)
              maxi.pop();
              maxi.push(num);
          }
      }
    }
    
  
};
