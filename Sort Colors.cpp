class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int zero=0, one=0, two=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(A[i]==0)
                zero++;
            else if(A[i]==1)
                one++;
            else
                two++;
        }
        i=0;
        while(i<zero)
        {
            A[i]=0;
            i++;
        }
        while(i<zero+one)
        {
            A[i]=1;
            i++;
        }
        while(i<zero+one+two)
        {
            A[i]=2;
            i++;
        }
    }
};


class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left=0, mid=0, right=n-1, t;
        while(mid<=right)
        {
            if(A[mid]==0)
            {
                t=A[mid];
                A[mid]=A[left];
                A[left]=t;
                left++;
                mid++;
            }
            else if(A[mid]==1)
                mid++;
            else
            {
                t=A[mid];
                A[mid]=A[right];
                A[right]=t;
                right--;
            }
        }
    }
};
