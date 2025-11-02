class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0)); // (grid was not given so had to make it)

        for(int i=0;i<guards.size();i++){
                //marking all guards by 1
                int idxr=guards[i][0];
                int idxc=guards[i][1];
                grid[idxr][idxc]=1;
            
        }
       
        for(int i=0;i<walls.size();i++){
            for(int j=0;j<walls[0].size();j++){
                //marking all walls by 2
                int idxr=walls[i][0];
                int idxc=walls[i][1];
                 grid[idxr][idxc]=2;

            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int r=i; int c=j;
                    //found a guard, see around (top, botton, left and right)
                    //top  

                    r=i-1; 
                    while(r>=0){
                         if(i==2 && j==3){
                            cout<<r<<" ";
                        }
                        if(grid[r][j]==1 || grid[r][j]==2){
                            //found wall or another guard
                            break;
                        }
                        else{
                            grid[r][j]=3; // blocked used as 3
                        }
                        r--;
                    }
                    r=i+1;
                    c=j;
                    //bottom
                     while(r<m){
                       
                        if(grid[r][j]==1 || grid[r][j]==2){
                            //found wall or another guard
                            break;
                        }
                        else{
                            grid[r][j]=3; // blocked used as 3
                        }
                        r++;
                    }

                    r=i;
                    c=j-1;

                    //left
                    while(c>=0){
                       
                        if(grid[i][c]==1 || grid[i][c]==2){
                            //found wall or another guard
                            break;
                        }
                        else{
                           
                            grid[i][c]=3; // blocked used as 3
                        }
                        c--;
                    }

                    r=i;
                    c=j+1;

                    //right
                       while(c<n){
                       
                        if(grid[i][c]==1 || grid[i][c]==2){
                            //found wall or another guard
                            break;
                        }
                        else{
                            grid[i][c]=3; // blocked used as 3
                        }
                        c++;
                    }
                }
            }
        }

        int ctr=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ctr++;
                }
            }
        }
        return ctr;
        return 0;
    }
};

