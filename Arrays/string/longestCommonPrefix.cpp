//method-1
string longestCommonPrefix(vector<string>& strs) {
      int r=strs.size(),c=strs[0].size();
        for(int i=0;i<c;i++)
        {
            
            for(int j=1;j<r;j++)
            {
                if(i==strs[j].length()||strs[0][i]!=strs[j][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
//divide conquer
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";    
        return longestCommonPrefix(strs, 0 , strs.length - 1);
}

private String longestCommonPrefix(String[] strs, int l, int r) {
    if (l == r) {
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        String lcpLeft =   longestCommonPrefix(strs, l , mid);
        String lcpRight =  longestCommonPrefix(strs, mid + 1,r);
        return commonPrefix(lcpLeft, lcpRight);
   }
}

String commonPrefix(String left,String right) {
    int min = Math.min(left.length(), right.length());       
    for (int i = 0; i < min; i++) {
        if ( left.charAt(i) != right.charAt(i) )
            return left.substring(0, i);
    }
    return left.substring(0, min);
}
