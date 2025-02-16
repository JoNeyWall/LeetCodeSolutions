class Solution {
  public:
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int size1 = nums1.size();
          int size2 = nums2.size();
  
          if (size1 > size2){
              return findMedianSortedArrays(nums2, nums1);
          }
  
          int low = 0;
          int high = size1;
  
          while (low <= high){
              int mid1 = (low + high) / 2;
              int mid2 = (size1 + size2 + 1) / 2 - mid1;
  
              int left1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
              int right1 = (mid1 == size1 ? INT_MAX : nums1[mid1]);
  
              int left2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
              int right2 = (mid2 == size2 ? INT_MAX : nums2[mid2]);
  
              if (left1 <= right2 && left2 <= right1){
                  if ((size1 + size2) % 2 == 0){
                      return (max(left1, left2) + min(right1, right2)) / 2.0;
                  }
                  else{
                      return max(left1, left2);
                  }
              }
  
              if (left1 > left2){
                  high = mid1 - 1;
              }
              else{
                  low = mid1 + 1;
              }
          }
          return 0;
      }
  };