//another approach
class Solution {
public:
    bool isRobotBounded(string ins) {
       vector<pair<int,int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
       int x=0,y=0,z=0;
        for(int i=0;i<ins.size();i++){
           if(ins[i]=='L') z=(z+3)%4;
           else if(ins[i]=='R') z=(z+1)%4;
           else{
               x+=dir[z].first;
               y+=dir[z].second;
           }
        }
        return(( x==0 && y==0) || z!=0);
    }
};

//2nd approach
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0; char cur='N';
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='G'){
                y+=(cur=='N')?1:0;
                x+=(cur=='E')?1:0;
                x+=(cur=='W')?-1:0;
                y+=(cur=='S')?-1:0;
                
            }
            else{
                if(instructions[i]=='L')
                {
                    if(cur=='N') cur='W';
                    else if(cur=='S') cur='E';
                    else if(cur=='E') cur='N';
                    else if(cur=='W') cur='S';
                }
                else{
                     if(cur=='N') cur='E';
                    else if(cur=='S') cur='W';
                    else if(cur=='E') cur='S';
                    else if(cur=='W') cur='N';
                }
            }
        }
        if(x==0 && y==0 || cur!='N') return 1;
        return 0;
    }
};
