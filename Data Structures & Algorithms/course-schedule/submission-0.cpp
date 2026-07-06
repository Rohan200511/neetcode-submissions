class Solution {
public:

    bool isCycle(int src , vector<vector<int>>& prerequisites , vector<bool>& vis , vector<bool>& recPath){

        vis[src] = recPath[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses , false);
        vector<bool>recPath(numCourses , false);

        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(isCycle(i , prerequisites , vis , recPath)) return false;
            }
        }
        return true;
    }
};
