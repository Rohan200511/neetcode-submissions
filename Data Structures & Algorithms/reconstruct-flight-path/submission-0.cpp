class Solution {
public:
    unordered_map<string , priority_queue<string, vector<string>, greater<string>>>adj;
    vector<string>ans;

    void dfs(string src){

        while(!adj[src].empty()){
            string next = adj[src].top();
            adj[src].pop();
            dfs(next);
        }

        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto& t : tickets){
            string u = t[0];
            string v = t[1];

            adj[u].push(v);
        }

        dfs("JFK");

        reverse(ans.begin() , ans.end());
        return ans;
    }
};
