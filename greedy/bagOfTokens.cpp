  int bagOfTokensScore(vector<int>& tokens, int p) {
        int score=0,ascore=0,bscore=0;
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1;
        while(l<=r && (p>=tokens[l] || ascore>0))
        {
            while(l<=r && p>=tokens[l])  // if we substract from p then this
            {                            //we subtract the small tokens or equal ones as
                                        // as much as possible to maximize points.
                ascore++;
                p-=tokens[l];
                l++;
                
            }
            score=max(ascore,score);
            if(l<=r and ascore>0) // if add to p then add largest value possible
            {                      // so that we need to subtract less from the points
                p+=tokens[r];      // and final score will be as large as possible
                ascore--;
                r--;
            }
        }
        return score;
    }
