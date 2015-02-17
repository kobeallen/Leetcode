struct node
{
	int id;
	int num;
};

bool CMP(const node &A, const node &B)
{
	return A.num<B.num;
}

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> ans;
		if(numbers.size()==0)
			return ans;
		int i, size=numbers.size();
		vector<node> array;
		for(i=0;i<size;i++)
		{
			node t;
			t.id=i+1;
			t.num=numbers[i];
			array.push_back(t);
		}
		sort(array.begin(), array.end(), CMP);
		int left=0, right=size-1;
		while(left<right)
		{
			if(array[left].num+array[right].num<target)
				left++;
			else if(array[left].num+array[right].num>target)
				right--;
			else
				break;
		}
		if(array[left].id<array[right].id)
		{
			ans.push_back(array[left].id);
			ans.push_back(array[right].id);
		}
		else
		{
			ans.push_back(array[right].id);
			ans.push_back(array[left].id);
		}
		return ans;
	}
};