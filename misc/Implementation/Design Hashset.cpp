class MyHashSet {
    int prime;
    vector<list<int>> set;
    int hash(int key)
    {
        return key%prime;
    }
    list<int>::iterator search(int key)
    {   int h=hash(key); 
        return find(set[h].begin(),set[h].end(),key);
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
       prime=1e6+7;
       set=vector<list<int>>(prime);
    }
    
    void add(int key) {
      int h=hash(key);  
      if(!contains(key))
      {
          set[h].push_back(key);
      }
    }
    
    void remove(int key) {
        int h=hash(key); 
        auto it = search(key);
        if(it!=set[h].end())
        {
            set[h].erase(it);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h=hash(key);  
        return search(key)!=set[h].end();
    }
};
