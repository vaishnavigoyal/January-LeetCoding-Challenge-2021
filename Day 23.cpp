// Day 23
// Question : Sort the Matrix Diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> temp;
        int n=mat.size();
        if(n==0||n==1)
        {
            return mat;
        }
        int m=mat[0].size();
        int i=n-1,j=0;
        int k=i;
        while(k>=0)
        {
            i=k;
            j=0;
            while(i<n&&j<m)
            {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            int y=temp.size()-1;
            i--;
            j--;
            while(y>=0)
            {
                mat[i][j]=temp[y--];
                i--;
                j--;
            }
            temp.clear();
            k--;
        }
        j=1;
        k=j;
        while(k<m)
        {
            j=k;
            i=0;
            while(i<n&&j<m)
            {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            int y=temp.size()-1;
            i--;
            j--;
            while(y>=0)
            {
                mat[i][j]=temp[y--];
                i--;
                j--;
            }
            k++;
            temp.clear();
        }
        return mat;
    }
};
