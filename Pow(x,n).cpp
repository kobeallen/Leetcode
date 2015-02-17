class Solution {
public:
    double POW(double x, int n)
    {
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        double ans;
        if(n%2==0)
        {
            ans=POW(x, n/2);
            ans*=ans;
        }
        else
        {
            ans=POW(x, n/2);
            ans=ans*ans*x;
        }
        return ans;
    }
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool positive=true;
        if(n<0)
        {
            n=n*-1;
            positive=false;
        }
        double ans=POW(x, n);
        if(positive==false)
            ans=1/ans;
        return ans;
    }
};

class Solution {
public:
    double Cal(double x, int n)
    {
        if(n == 0)
            return 1.0;
        else if(n == 1)
            return x;
        double result = Cal(x, n / 2);
        if(n % 2)
            return result * result * x;
        else
            return result * result;
    }
    
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0)
            return 1.0;
        bool positive = true;
        if(n < 0)
        {
            positive = false;
            n *= -1;
        }
        double result = Cal(x, n);
        if(positive == true)
            return result;
        else
            return 1.0 / result;
    }
};
