class Solution {
public:
    const int MIN = -100000000;
    const int MAX = 100000000;
    int BinarySearch(int K, int A[], int sizeA, int B[], int sizeB)
    {
        int left = 0, right = sizeA - 1, mid;
        int index, current, previous;
        while(left < right)
        {
            mid = (left + right) / 2;
            index = K - mid - 1;
            if(index < 0)
                right = mid - 1;
            else if(index > sizeB)
                left = mid + 1;
            else
            {
                previous = index == 0 ? MIN : B[index-1];
                current = index == sizeB? MAX: B[index];
                if(A[mid] >= previous && A[mid] <= current)
                    return A[mid];
                else if(A[mid] < previous)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        index = K - left - 1;
        if(index >= 0 && index <= sizeB)
        {
            previous = index == 0 ? MIN : B[index-1];
            current = index == sizeB ? MAX : B[index];
            if(A[left] >= previous && A[left] <= current)
                return A[left];
        }
        return -1;
    }
    
    int FindKthNumber(int K, int A[], int sizeA, int B[], int sizeB)
    {
        if(sizeA == 0)
            return B[K-1];
        if(sizeB == 0)
            return A[K-1];
        int fromA = BinarySearch(K, A, sizeA, B, sizeB);
        if(fromA != -1)
            return fromA;
        int fromB = BinarySearch(K, B, sizeB, A, sizeA);
        return fromB;
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if((m + n) % 2)
        {
            int median = (m + n + 1) / 2;
            return 1.0 * FindKthNumber(median, A, m, B, n);
        }
        else
        {
            int med1 = (m + n) / 2;
            int med2 = (m + n) / 2 + 1;
            int value1 = FindKthNumber(med1, A, m, B, n);
            int value2 = FindKthNumber(med2, A, m, B, n);
            return 1.0 * (value1 + value2) / 2;
        }
    }
};
