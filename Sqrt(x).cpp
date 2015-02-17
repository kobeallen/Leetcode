class Solution
{
public:
        int sqrt(int x)
        {
            double left=0, right=x, mid;
            for(int i=0;i<100;i++)
            {
                mid=(left+right)/2;
                if(mid*mid>=x)
                    right=mid;
                else
                    left=mid;
            }
            int ans1=left, ans2=left+1;
            if(ans2*ans2==x)
                return ans2;
            else
                return ans1;
        }
};
