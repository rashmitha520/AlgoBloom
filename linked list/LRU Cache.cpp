    list<pair<int,int>> dll;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int cap;
    LRUCache(int capacity) {
     cap=capacity;   
    }
    
    int get(int key) {
      if(mp.find(key)==mp.end()) return -1;
      //obtaining pointer address of key node   
      auto it = mp[key];
      int val = it->second;
      //erase previous positions
      mp.erase(key);
      dll.erase(it);
      //add at first as it has been the most recently used 
      dll.push_front({key,val});
      mp[key]=dll.begin();
      return val; //return value
    }
    
    void put(int key, int value) {
     if(mp.find(key)==mp.end()) //if not present at first
     {
         if(dll.size()==cap) //if capacity exceeds remove the last one
         {
            auto end = dll.rbegin();//pointer to last node
            mp.erase(end->first);
            dll.pop_back();
         }
         
     }
    else
    {
        auto it=mp[key]; //delete the current position of the node and the node too
        mp.erase(key);
        dll.erase(it);
       
    }
         dll.push_front({key,value}); // add at front Appl. for both cases
         mp[key]=dll.begin();
    }
};
