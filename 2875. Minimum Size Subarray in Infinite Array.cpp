// solution to https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int size=nums.size();
        map<int,int>mymap;
        mymap[0]=0;
        long long sum=0;
        for(int i=1;i<=size;i++){
            sum+=(long long)nums[i-1];
            mymap[sum]=i;
        }
        int ans=INT_MAX;
        long long preSum=0;
        for(int  i=0;i<size;i++){
            if(i!=0)
                preSum+=(long long)nums[i-1];
            long long postSum=sum-preSum;
            if(target>postSum){
                int temp=target-postSum;
                int round=temp/sum;
                int rem=temp%sum;
                if(mymap.find(rem)!=mymap.end()){
                    ans=min(ans,size-i+round*size+mymap[rem]);
                }
            }
            else{
                if(mymap.find(preSum+target)!=mymap.end()){
                    ans=min(ans,mymap[preSum+target]-i);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
