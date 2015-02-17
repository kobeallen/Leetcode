class Solution {
public:
	int reverse(int x) {
		bool negative=false;
		if(x<0)
		{
			negative=true;
			x=x*-1;
		}
		int ans=0, val;
		while(x>0)
		{
			val=x%10;
			ans=10*ans+val;
			x/=10;
		}
		if(negative==true)
			ans*=-1;
		return ans;
	}
};