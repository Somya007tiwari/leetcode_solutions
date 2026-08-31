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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        int firstIdx = -1, lastIdx = -1;
        int minDist = INT_MAX;

        while (curr && curr->next) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;

            if (isMax || isMin) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDist = min(minDist, idx - lastIdx);
                }
                lastIdx = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (firstIdx == -1 || firstIdx == lastIdx) {
            return {-1, -1};
        }

        int maxDist = lastIdx - firstIdx;
        return {minDist, maxDist};
    }
};