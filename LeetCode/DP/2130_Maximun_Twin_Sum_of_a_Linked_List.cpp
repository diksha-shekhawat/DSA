/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {

        if (!head) return 0;

        // Step 1: store all values in array
        vector<int> arr;

        ListNode* curr = head;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int n = arr.size();

        // Step 2: compute twin sums
        int maxi = 0;

        for (int i = 0; i < n / 2; i++) {
            int twinSum = arr[i] + arr[n - 1 - i];
            maxi = max(maxi, twinSum);
        }

        return maxi;
    }
};