// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/

Note : This Is A real Interiew Question So Your Ans shuld prepair Like Fallowing sequential
way Starting with O(N*N) naive approch To O(N) & constant Space :)

Let's Start :: = >

1. Bruteforce Apprch
Idea - Do Check Double Time For Each element

Time Complexcity - O(N*N) <=Give You TLE
Space Complexcity - O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j])continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
2.Using Sort Solution
Idea - Do sort The array First Then Track Adjcent Element Is Same Or Not [Can be Done By XOR or Have an count Element]

Time Complexcity - O(N*Log N)
Space Complexcity - O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        sort(begin(nums),end(nums));
        int s = nums[0];
        for(int i=1;i<nums.size();i++){
            if(!(s^nums[i])){
                ans.push_back(nums[i]),i+=1;
                if(i<nums.size())s=nums[i];
                else break;
            }
                else s = nums[i];
        }
        return ans;
    }
};
3. Using Unordered map

Idea - Take An unordered_map To store frequency Of each Element And Return those Having Frequency 2
Time Complexcity - O(N)
Space Complexcity - O(N)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int no:nums)mp[no]++;
        for(auto it:mp)if(it.second==2)ans.push_back(it.first);
        return ans;
    }
};
4. Most Efficent Solution
Idea -
If you Look This ->array of integers, 1 ≤ a[i] ≤ n (n = size of array)constrain [ given ]
We Can Easily Identify That All element's Are greater Then or equal 1 and Less Then or Equall size of the array
And 2 . Constrain elements appear twice and others appear once

So try To Use Those Information To Come Up better a solution

What We can Do is That We Can Use That Given Array As an Frequency Array
and Instade of Count The each Element we Can Use -[minus] To track Each Element we are traverse Or Not [as They said That any element can occoure max Twice]
While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array

Lastly Return ANS array

For More Clearfy This Approch let's take an Example

Assume I/O Array   A -[ 4,   3,   2,   7,   8,    2,   3,    1   ]
          index -       0     1    2   3    4     5    6      7
		  
				   
				   index                 element                       Todo                               
				    0                      A[0] = 4                   A[4-1] Not negative
					                                                  do it negetive mean we visited 4
																	  array - [4,3,2,-7,8,2,3,1]
																	 
					1                     A[1] = 3                      A[3-1] Not negative
					                                                    do it negetive mean we visited 3
					                                                    array - [4,3,-2,-7,8,2,3,1]
																	  
                   2                      A[2] = 2                      A[2-1] Not negative
				                                                        do it negetive mean we visited 2
																	    array - [4,-3,-2,-7,8,2,3,1]
																	 
				   3                        A[3]=7                      A[7-1] Not negative
				                                                        do it negetive mean we visited 7
																        Array- [4,-3,-2,-7,8,2,-3,1]
																 
				   4                       A[4]=8                      A[8-1] Not negative
				                                                       do it negetive mean we visited 8
																        Array- [4,-3,-2,-7,8,2,-3,-1]
																 
				   5                     A[5]=2                       A[2-1] is Negative Mean It is A 
				                                                      duplicate ele so Put it into ans array  
																     Array- [4,-3,-2,-7,8,2,-3,-1]
																
                    6                   A[6]=3                        A[3-1] is Negative Mean It is A 
                                                                     duplicate ele so Put it into ans array  
                                                                      Array- [4,-3,-2,-7,8,2,-3,-1]
																
					7                  A[7] = 1                     A[1-1] Not negative
					                                                do it negetive mean we visited 1
                                                                     Array- [-4,-3,-2,-7,8,2,-3,-1]
															   
	So we Have {2 , 3 }  <= Here For ans
Now Hope Everything Will Be clear :)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};