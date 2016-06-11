class Solution {
public:

    // int findKth()
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int one = nums1.size();
        int two = nums2.size();
        if (one == 0 && two == 0)
            return 0;
            
        if (one == 1 && two == 1)
            return (nums1[0] + nums2[0])/2.0;
            
        else if (one == 0 || two == 0) {
            if (one == 0) {
                if (two %2 == 1)
                    return nums2[two/2];
                else 
                    return (nums2[(two-1)/2] + nums2[(two)/2])/2.0;
            }
            if (two == 0) {
                if (one %2 == 1)
                    return nums1[one/2];
                else 
                    return (nums1[(one-1)/2] + nums1[(one)/2])/2.0;
            }
        }
        vector<int> *big;
        vector<int> *small;
        int large;
        int tiny;
        if (one > two) {
            big= &nums1; large = one;
            small = &nums2; tiny = two;
        } else {
            big= &nums2; large = two;
            small = &nums1; tiny = one;
        }
        int total = one + two;
          // odd numb.
            // find the (t)/2 index.
        bool turn = false; // element from large array.
        int ind = large/2;
        int elem = (*big)[ind];
        int smallboy = 0;
        while (true) {
         
            if (!turn) {
                elem = (*big)[ind];
                int other_ind = total/2 - ind;
                if (other_ind > 0) // necessary to not make invalid comparison.
                    if ((*small)[other_ind-1] > elem ) { // we have a wrong element. 
                        turn = !turn;
                        ind = other_ind-1;
                        continue;
                    } else {
                        smallboy =(*small)[other_ind-1];
                    }
                        // flip side and choose this element.
                if (other_ind < tiny) // necessary to not make invalid comparison.
                    if ((*small)[other_ind] < elem ) {
                        turn = !turn;//flip side and choose this elemnt
                        ind = other_ind;
                        continue;
                    }
                // we have found correct element and we r da winners. 
                break;
            } else {
                elem = (*small)[ind];
                int other_ind = total/2 - ind;
                if (other_ind > 0) // necessary to not make invalid comparison.
                    if ((*big)[other_ind-1] > elem ) { // we have a wrong element. 
                        turn = !turn;
                        ind = other_ind-1;
                        continue;
                    } else {
                        smallboy = (*big)[other_ind-1];
                    }
                        // flip side and choose this element.
                if (other_ind < large) // necessary to not make invalid comparison.
                    if ((*big)[other_ind] < elem ) {
                        turn = !turn;//flip side and choose this elemnt
                        ind = other_ind;
                        continue;
                    }
                // we have found correct element and we r da winners. 
                break;
            }
            
        }
        if ((total)%2 == 0) { // even number.
              if (!turn) {
                if (ind > 0) {
                    if (smallboy > (*big)[ind-1]){
                        return (smallboy + elem)/2.0;
                     }else {
                        return ((*big)[ind-1] + elem)/2.0;}
                } else {
                    return (smallboy + elem)/2.0;
                }
            } else {
                if (ind > 0) {
                    if (smallboy > (*small)[ind-1]){
                        return (smallboy + elem)/2.0;
                     }else {
                        return ((*small)[ind-1] + elem)/2.0;}
                } else {
                    return (smallboy + elem)/2.0;
                }
            }
        }
        return elem;
    }
};