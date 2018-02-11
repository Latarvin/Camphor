class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_tot = nums1.size() + nums2.size();
        
        if(len_tot == 1) {
            if(nums1.empty() == true)
                return nums2[0];
            else
                return nums1[0];
        }
        
        // merge sort
        vector<int> merge_result;
        int i1 = 0, i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
          if (nums1[i1] < nums2[i2]) {
            merge_result.push_back(nums1[i1]);
            i1++;
          } else {
            merge_result.push_back(nums2[i2]);
            i2++;
          }
        }

        while (i1 < nums1.size()) {
          merge_result.push_back(nums1[i1]);
          i1++;
        }

        while (i2 < nums2.size()) {
          merge_result.push_back(nums2[i2]);
          i2++;
        }

        // return median
        if( len_tot % 2 == 0)
            return (merge_result[len_tot / 2 -1] + merge_result[len_tot / 2]) / 2.0;
        else
            return merge_result[len_tot / 2];
        
    }
};