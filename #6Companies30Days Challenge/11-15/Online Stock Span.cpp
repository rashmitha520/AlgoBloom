    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
       int d=1;
        while(!s.empty() && price>=s.top().first){
           d+=s.top().second;
            s.pop();
        }
        s.push({price,d});
        return d;
    }
