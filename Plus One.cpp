class Solution
{
public:
	void Reverse(vector<int> &digit)
	{
		int left=0, right=digit.size()-1;
		while(left<right)
		{
			int t=digit[left];
			digit[left]=digit[right];
			digit[right]=t;
			left++, right--;
		}
	}
	vector<int> plusOne(vector<int> &digits)
	{
		Reverse(digits);
		int i=1, size=digits.size();
		int val=digits[0]+1;
		int d=val/10;
		digits[0]=val%10;
		while(i<size)
		{
			val=digits[i]+d;
			digits[i]=val%10;
			d=val/10;			
			i++;
		}		
		if(d>0)
		{
			digits.push_back(d);
		}		
		Reverse(digits);
		return digits;
	}
};
