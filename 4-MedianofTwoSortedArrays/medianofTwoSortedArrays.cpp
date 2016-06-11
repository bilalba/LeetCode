class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int one = nums1.size();
        int two = nums2.size();
        if (one == 0 && two == 0)
            // cout << "LOLL";
            return 0;
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
        // else.
        
    
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
        
        // check if 
        
        
        
        int total = one + two;
        if ((total)%2 == 0) { // even number.
            // find the (t-1)/2
            
            // find the (t)/2
            
            
        }  // odd numb.
            // find the (t)/2 index.
        bool turn = false; // element from large array.
        int ind = large/2;
        int elem = *(big)[ind];
        while (true) {
            if (!turn) {
                elem = *(big)[ind];
                int other_ind = total/2 - ind;
                if (other_ind != 0) // necessary to not make invalid comparison.
                    if (*(small)[other_ind-1] > elem ) { // we have a wrong element. 
                        turn = !turn;
                        ind = other_ind-1;
                        continue;
                    }
                        // flip side and choose this element.
                if (other_ind != tiny) // necessary to not make invalid comparison.
                    if (*(small)[other_ind] < elem ) {
                        turn = !turn;//flip side and choose this elemnt
                        ind = other_ind;
                        continue;
                    }
                // we have found correct element and we r da winners. 
                break;
                    
                        .
            } else {
                elem = *(small)[ind];
                int other_ind = total/2 - ind;
                if (other_ind != 0) // necessary to not make invalid comparison.
                    if (*(big)[other_ind-1] > elem ) { // we have a wrong element. 
                        turn = !turn;
                        ind = other_ind-1;
                        continue;
                    }
                        // flip side and choose this element.
                if (other_ind != tiny) // necessary to not make invalid comparison.
                    if (*(big)[other_ind] < elem ) {
                        turn = !turn;//flip side and choose this elemnt
                        ind = other_ind;
                        continue;
                    }
                // we have found correct element and we r da winners. 
                break;
            }
            
        }
        
        return 0;
    }
};