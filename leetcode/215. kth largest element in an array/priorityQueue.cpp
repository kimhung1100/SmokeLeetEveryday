<<<<<<< HEAD
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
=======
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
};