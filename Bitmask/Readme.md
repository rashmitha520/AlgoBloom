# Bitmasking for these strings types:
1. in the mask , each digit or level represents a character.
2. Here , for a,e,i,o,u  : _ _ _ _ _ _ a can be 00001,e can be 00010, i can be 00100 etc.
3. masking here is nothing but 0^1^2^3^4 types.
4. DRY RUN:
 **leetcodeisgreat:**
 mask=0;
 **iter-1:** mask=0;
**iter-2:** mask=0^1
 m[1]=1;
 res = max(res,1-1) = 0;
 
 **iter-3:** mask=1
 mask=1^1=0
 m[0]=-1;
 So, res=max(res,2-(-1)) = 3 ("lee")
 
Like this , We find the longest substring with even number of vowels.

