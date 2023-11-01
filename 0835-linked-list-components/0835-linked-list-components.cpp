class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); // Initialize set with vector elements
        int cc = 0;
        
        bool inComponent = false; // To track if we are inside a component

        while(head != nullptr) {
            if(s.find(head->val) != s.end()) { // If current value is in set
                inComponent = true; // Mark that we are inside a component
            } else if(inComponent) { // If we were inside a component and the current value is not in set
                cc++; // Increment component count
                inComponent = false; // Mark that we are no longer inside a component
            }
            
            head = head->next; // Move to next node
        }

        // If the list ends and we are still inside a component
        if(inComponent) {
            cc++;
        }

        return cc;
    }
};
