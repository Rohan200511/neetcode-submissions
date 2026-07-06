class Solution {
public:

    void dfs(int src , vector<vector<int>>& prerequisites , stack<int>& top , vector<bool>& vis){
        vis[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src)
                if(!vis[v]) dfs(v , prerequisites , top , vis);
        }
        top.push(src);
    }

    bool isCycle(int src , vector<vector<int>>& prerequisites , vector<bool>& vis , vector<bool>& recPath){
        vis[src] = recPath[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v , prerequisites , vis , recPath)) return true;
                }
                else if(recPath[v]) return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses , false);
        vector<bool>recPath(numCourses , false);

        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(isCycle(i , prerequisites , vis , recPath)) return {};
            }
        }

        vis.assign(numCourses , false);

        stack<int>top;
        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                dfs(i , prerequisites , top , vis);
            }
        }
        
        vector<int>ans;

        while(!top.empty()){
            ans.push_back(top.top());
            top.pop();
        }
        return ans;
    }
};
