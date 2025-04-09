class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;

        //check if first rom me 0 h ?
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0) firstRow = true;
        }

        //check if first col me 0 h?
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) firstCol = true;
        }

        //Lets make the markers using 1st row and 1st col
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //Ab jha jha markers h vo row and col zero krr do
        for(int i=1; i<m; i++){
            for(int j=1; j<n;j++){
                if(matrix[i][0] ==0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //ab agr 1st row me 0 tha to use 0 krr do

        if(firstRow){
            for(int j=0; j<n; j++){
                 matrix[0][j] = 0;
            }
        }
        if(firstCol){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }

    }
};