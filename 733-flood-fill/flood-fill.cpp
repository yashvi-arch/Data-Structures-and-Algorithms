class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int target,int color){
        int n=image.size();
        int m=image[0].size();
        if(row<0 || row>=n || col<0 || col>=m){
            return;
        }
        if(image[row][col]!=target){
            return;
        }else{
            image[row][col]=color;
        }
        dfs(image,row-1,col,target,color);
        dfs(image,row+1,col,target,color);
        dfs(image,row,col-1,target,color);
        dfs(image,row,col+1,target,color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target=image[sr][sc];
        if(target==color){
            return image;
        }
        dfs(image,sr,sc,target,color);
        return image;
        
    }
};