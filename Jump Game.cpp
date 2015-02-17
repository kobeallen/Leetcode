class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_id=0;
        for(int i=0;i<n;i++)
        {
            if(max_id>=i)
            {
                int id=i+A[i];
                if(id>max_id)
                    max_id=id;
            }
            else
                return false;
        }
        return true;
    }
};
