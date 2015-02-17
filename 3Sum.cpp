class Solution
{
public:
    void Find(vector<int> num, int id, vector<vector<int> > &ans, int target)
	{
		int left=id+1, right=num.size()-1;
		while(left<right)
		{
			if(num[left]+num[right]<target)
				left++;
			else if(num[left]+num[right]>target)
				right--;
			else
			{
				vector<int> result;
				result.push_back(num[id]);
				result.push_back(num[left]);
				result.push_back(num[right]);
				ans.push_back(result);
				int l=left+1, r=right-1;
				while(l<num.size()&&num[left]==num[l])
					l++;
				left=l;
				while(r>=0&&num[right]==num[r])
					r--;
				right=r;
			}
		}
	}

	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > ans;
		if(num.size()==0)
			return ans;
		sort(num.begin(), num.end());
		int i,j,size=num.size();
		int sum=0;
		if(num[0]<0)
			sum=-1*num[0];
		for(i=0;i<size;i++)
			num[i]+=sum;
		int left=0, right;
		while(left<size)
		{
			Find(num, left, ans, 3*sum-num[left]);
			right=left+1;
			while(right<size&&num[left]==num[right])
				right++;
			left=right;
		}
		for(i=0;i<ans.size();i++)
		{
			for(j=0;j<3;j++)
				ans[i][j]-=sum;
		}
		return ans;
	}
};
