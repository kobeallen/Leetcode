class Solution {
public: 
	int divide(long long dividend, long long divisor) {  // dividend and divisor must be changed into the type of long long from int
		bool negative = false;
		if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))
			negative=true;
		if(dividend==0)
			return 0;
		if(divisor==0)
			return NULL;
		if(dividend<0)	dividend*=-1;
		if(divisor<0)	divisor*=-1;
		int i=0;
		while((divisor<<i)<=dividend)
		{
			i++;
		}
		i--;
		int ans=0;
		while(dividend>=divisor)
		{
			if(dividend-(divisor<<i)>=0)
			{
				dividend=dividend-(divisor<<i);
				ans+=(1<<i);
			}
			i--;
		}
		if(negative==true) ans*=-1;
		return ans;
	}
};


class Solution {
public:
    int divide(long long dividend, long long divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dividend == 0)
            return 0;
        int negative = 0;
        if(dividend < 0)
        {
            dividend *= -1;
            negative = (negative + 1) % 2;
        }
        if(divisor < 0)
        {
            divisor *= -1;
            negative = (negative + 1) % 2;
        }
        int i = 0;
        while(divisor << i <= dividend)
        {
            ++i;
        }
        --i;
        int ans = 0;
        while(dividend >= divisor)
        {
            if(dividend - (divisor << i) >= 0)
            {
                dividend -= (divisor << i);
                ans += 1 << i;
            }
            --i;
        }
        if(negative == 0)
            return ans;
        else
            return -1 * ans;
    }
};