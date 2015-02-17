class Solution
{
public:
    bool FindTwoSum(vector<int> num, int id, int target)
	{
		int left=id+1, right=num.size()-1;
		while(left<right)
		{
			if(num[left]+num[right]<target)
				left++;
			else if(num[left]+num[right]>target)
				right--;
			else
				return true;
		}
		return false;
	}

	bool FindThreeSum(vector<int> num, int target)
	{
		int left=0, right;
		while(left<num.size())
		{
			if(FindTwoSum(num, left, target-num[left])==true)
				return true;
			right=left+1;
			while(right<num.size()&&num[left]==num[right])
				right++;
			left=right;
		}
		return false;
	}

	int threeSumClosest(vector<int> &num, int target)
	{
		int length=0;
		sort(num.begin(), num.end());
		int sum=0;
		if(num[0]<0)
			sum=-1*num[0];
		target+=3*sum;
		for(int i=0;i<num.size();i++)
			num[i]+=sum;
		while(1)
		{
			if(FindThreeSum(num, target+length))
				return target+length-3*sum;
			if(FindThreeSum(num, target-length))
				return target-length-3*sum;
			length++;
		}
	}
};
