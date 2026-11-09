
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Min heap: {when server becomes free, server index}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        // Available servers (sorted by index)
        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Free all servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, drop the request
            if(available.empty()) {
                continue;
            }

            // Preferred server: i % k
            int server = i % k;

            // Find first available server >= preferred server
            auto it = available.lower_bound(server);

            // If not found, wrap around to smallest available
            if(it == available.end()) {
                it = available.begin();
            }

            server = *it;

            // Assign request to this server
            available.erase(it);

            count[server]++;

            // Mark server as busy
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
