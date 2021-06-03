
class Trie {
public:
    /** Initialize your data structure here. */
   bool end;
    Trie* children[26];
    Trie() {
     this->end=false;
     for(int i=0;i<26;i++)
         this->children[i]=NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root=this;
        for(int i=0;i<word.length();i++)
        {
          int index=word[i]-'a';
            if(root->children[index]==NULL)
                  root->children[index]=new Trie();
            
                root=root->children[index];
              
        }
          root->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(!this) return 0;
         Trie* root=this;
        for(int i=0;i<word.length();i++)
        {
          int index=word[i]-'a';
            root=root->children[index];
            if(root==NULL)
                  return false;
            
               
                
        }
        if(root->end)
        return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
     Trie* root=this;
        for(int i=0;i<word.length();i++)
        {
          int index=word[i]-'a';
            root=root->children[index];
            if(root==NULL)
                  return false;
            
               
                
        }  
        return true;
        
    }
};
