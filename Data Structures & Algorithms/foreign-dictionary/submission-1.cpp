class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char , unordered_set<char>>adj;

        unordered_set<char>nodes;

        for(string& word : words){
            for(char c : word){
                nodes.insert(c);
            }
        }

        for(int i = 0 ; i < words.size() - 1 ; i++){
            string& u = words[i];
            string& v = words[i+1];

            int len = min(u.length() , v.length());

            int j = 0;

            while(j < len && u[j] == v[j]) j++;

            if(j < len){
                adj[u[j]].insert(v[j]);
            }
            else if(u.length() > v.length()) return "";
        }

        unordered_map<char , int>indegree;

        for(char c : nodes) indegree[c] = 0;

        for(auto& it : adj){
            for(char nei : it.second){
                indegree[nei]++;
            }
        }

        queue<char>q;

        for(char c : nodes){
            if(indegree[c] == 0) q.push(c);
        }

        string ans;

        while(!q.empty()){
            char node = q.front();
            q.pop();

            ans.push_back(node);

            for(char v : adj[node]){
                indegree[v]--;

                if(indegree[v] == 0) q.push(v);
            }
        }

        if(ans.length() != nodes.size()) return "";

        return ans;
    }
};
