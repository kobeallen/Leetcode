class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = m + n -1;
        --m, --n;
        while(n >= 0)
        {
            if(m < 0)
            {
                A[pos] = B[n];
                --pos, --n;
            }
            else
            {
                if(A[m] > B[n])
                {
                    A[pos] = A[m];
                    --pos, --m;
                }
                else
                {
                    A[pos] = B[n];
                    --pos, --n;
                }
            }
        }
    }
};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = m - 1, b = n - 1, c = m + n - 1;
        while(b >= 0)
        {
            if(a >= 0 && A[a] > B[b])
            {
                A[c] = A[a];
                --a;                
            }
            else
            {
                A[c] = B[b];
                --b;
            }
            --c;
        }
    }
};