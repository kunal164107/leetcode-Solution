/* O(n^2) time and O(1) space */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        throw "No Solution Exist!";
    }
};

-------------------------------------------------------------------------------------------------

/* O(n) time and O(n) space */
/* Two iteration of hash-table */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]].push_back(i);
        }
				
        /*
        // to view the content in hash-table
        for(auto itr=m.begin();itr!=m.end();itr++) {
            cout<<itr->first<<" ";
            for(int i=0;i<itr->second.size();i++) {
              cout<<itr->second[i]<<" ";
            }
            cout<<endl;
        }
        */
        
        for(int i=0;i<nums.size();i++) {
            auto itr = m.find(target-nums[i]);
            if(itr!=m.end()) {
                if(itr->second.size()==1 && itr->second[0]!=i) return {i,itr->second[0]};
                else if(itr->second.size()!=1){
                    return {i,itr->second[1]};
                }
            }
        }
       throw "No Solution Exist!";
    }
};

-------------------------------------------------------------------------------------------------

/* O(n) time and O(n) space */
/* Two iteration of hash-table */
/* Take advantage of this line "each input would have exactly one solution" */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++) {
            auto itr = m.find(target-nums[i]);
            if(itr!=m.end() && itr->second!=i) {
                return {i,itr->second};
            }
        }
       throw "No solution exists!";
    }
};

--------------------------------------------------------------------------------------------------

/* O(n) time and O(n) space */
/* One iteration of hash-table */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            auto itr = m.find(target-nums[i]);
            if(itr!=m.end() && itr->second!=i) {
                return {itr->second,i};
            }
            m[nums[i]] = i;
        }
       throw "No solution exists!";
    }
};
