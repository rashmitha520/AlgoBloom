 list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int cap;
    LRUCache(int capacity) {
     cap=capacity;   
    }
    
    int get(int key) {
      if(mp.find(key)==mp.end()) return -1;
      auto it = mp[key];
      int val = it->second;
      mp.erase(key);
      dll.erase(it);
      dll.push_front({key,val});
      mp[key]=dll.begin();
      return val;
    }
    
    void put(int key, int value) {
     if(mp.find(key)==mp.end())
     {
         if(dll.size()==cap)
         {
            auto end = dll.rbegin();
            mp.erase(end->first);
            dll.pop_back();
         }
         
     }
    else
    {
        auto it=mp[key];
        mp.erase(key);
        dll.erase(it);
       
    }
         dll.push_front({key,value});
         mp[key]=dll.begin();
    }
};
