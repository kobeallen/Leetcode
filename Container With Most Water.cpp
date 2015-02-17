struct node
{
	int id;
	int height;
};

bool CMP(const node &A, const node &B)
{
	if(A.height!=B.height)
		return A.height<B.height;
	else
		return A.id<B.id;
}

int Max(int a, int b)
{
	return a>b?a:b;
}

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int ans, result;
		vector<node> array;
		vector<bool> hash;
		int i,j;
		for(i=0;i<height.size();i++)
		{
			node t;
			t.id=i, t.height=height[i];
			array.push_back(t);
			hash.push_back(false);
		}
		sort(array.begin(), array.end(), CMP);
		int left=0, right=array.size()-1;
		ans=0;
		for(i=0;i<array.size();i++)
		{
			int width=Max(array[i].id-left, right-array[i].id);
			hash[array[i].id]=true;
			while(left<array.size()&&hash[left]==true)
			left++;
			while(right>=0&&hash[right]==true)
			right--;
			result=array[i].height*width;
			if(ans<result)
				ans=result;
		}
		return ans;
	}
};



struct node
{
    int id;
    int height;
};

bool CMP(const node &A, const node &B)
{
    if(A.height != B.height)
        return A.height < B.height;
    else
        return A.id < B.id;
}

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> array;
        for(int i = 0; i < height.size(); ++i)
        {
            node t;
            t.id = i;
            t.height = height[i];
            array.push_back(t);
        }
        sort(array.begin(), array.end(), CMP);
        int min[height.size()];
        int max[height.size()];
        int result = 100000;
        for(int i = array.size() - 1; i >= 0; --i)
        {
            if(result > array[i].id)
                result = array[i].id;
            min[i] = result;
        }
        result = -1;
        for(int i = array.size() - 1; i >= 0; --i)
        {
            if(result < array[i].id)
                result = array[i].id;
            max[i] = result;
        }
        int ans = 0;
        for(int i = 0; i < array.size(); ++i)
        {
            result = (max[i] - min[i]) * array[i].height;
            if(ans < result)
                ans = result;
        }
        return ans;
    }
};