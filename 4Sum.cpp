class Solution
{
public:
	void FindTwoSum(vector<int> &num, int id1, int id2, int target, vector<vector<int> > &ans)
	{
			int left=id2+1, right=num.size()-1;
			while(left<right)
			{
				if(num[left]+num[right]<target)
					left++;
				else if(num[left]+num[right]>target)
					right--;
				else
				{
					vector<int> result;
					result.push_back(num[id1]);
					result.push_back(num[id2]);
					result.push_back(num[left]);
					result.push_back(num[right]);
					ans.push_back(result);
					int l=left+1, r=right-1;
					while(l<num.size()&&num[l]==num[left])
						l++;
					left=l;
					while(r>=0&&num[r]==num[right])
						r--;
					right=r;
				}
			}
	}

	vector<vector<int> > fourSum(vector<int> &num, int target)
	{
		vector<vector<int> > ans;
		if(num.size()==0)
			return ans;
		sort(num.begin(), num.end());
		int sum=0;
		if(num[0]<0)
			sum=-1*num[0];
		for(int i=0;i<num.size();i++)
			num[i]+=sum;
		target+=4*sum;
		int left1, right1, left2, right2;
		left1=0;
		while(left1<num.size())
		{
			left2=left1+1;
			while(left2<num.size())
			{
				FindTwoSum(num, left1, left2, target-num[left1]-num[left2], ans);
				right2=left2+1;
				while(right2<num.size()&&num[right2]==num[left2])
					right2++;
				left2=right2;
			}
			right1=left1+1;
			while(right1<num.size()&&num[right1]==num[left1])
				right1++;
			left1=right1;
		}
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<4;j++)
			{
				ans[i][j]-=sum;
			}
		}
		return ans;
	}
};