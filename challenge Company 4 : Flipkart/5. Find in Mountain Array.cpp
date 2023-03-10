/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int n,h;
        n = h = mountainArr.length()-1;
        int peak_el, ans = INT_MAX;

        // finding the mid or peak element in array
        while(l<h){
            int mid = (l+h)/2;
            int val = mountainArr.get(mid);
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
            l = mid+1;
            else h = mid;
        }
        peak_el = l;
        if(mountainArr.get(peak_el) == target ) return peak_el;
        
        // find the target element in left part of peak
        l = 0;
        h = peak_el;
        while(l<=h){
            int mid = (l+h)/2;
            int val = mountainArr.get(mid);
            if(val == target){
                ans = min(ans, mid);
                break;
            }
            else if (val<target) l = mid+1;
            else h = mid-1;
          }

        // finding the target element in right part of peak
        l = peak_el+1,h = n;
        while(l<=h){
            int mid = (l+h)/2;
            int val = mountainArr.get(mid);
            if(val == target){
                ans = min(ans, mid);
                break;
            }
            else if (val>target) l = mid+1;
            else h = mid-1;
        }
        if (ans != INT_MAX) return ans;
        return -1;
    }
};
