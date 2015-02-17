class Solution {
public:
	void DFS(int depth, int size, string digits, string &result, vector<string> &ans, int pos[9])
	{
		if(depth==size)
		{
			ans.push_back(result);
			return ;
		}
		int num=digits[depth]-'2';
		int i=pos[num], j=pos[num+1];
		while(i<j)
		{
			char c='a'+i;
			result[depth]=c;
			DFS(depth+1, size, digits, result, ans, pos);
			i++;
		}
	}
	vector<string> letterCombinations(string digits) {
		int pos[9]={0,3,6,9,12,15,19,22,26};
		vector<string> ans;
		string result;
		int size=digits.size();
		if(digits.size()==0)
		{
			ans.push_back(result);
			return ans;
		}
		for(int i=0;i<size;i++)
			result+=' ';
		DFS(0, size, digits, result, ans, pos);
	}
};