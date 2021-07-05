    #define mod 1000000007
    long countVowelPermutation(int n) {
       long acount=1,ecount=1,icount=1,ocount=1,ucount=1;
        for(int i=1;i<n;i++)
        {
            long new_acount=(ucount+icount+ecount)%mod;
            long new_ecount=(acount+icount)%mod;
            long new_icount=(ecount+ocount)%mod;
            long new_ocount=(icount)%mod;
            long new_ucount=(ocount+icount)%mod;
            acount=new_acount,ecount=new_ecount,icount=new_icount;
            ocount=new_ocount,ucount=new_ucount;
        }
        return (acount+ucount+ecount+icount+ocount)%mod;
    
