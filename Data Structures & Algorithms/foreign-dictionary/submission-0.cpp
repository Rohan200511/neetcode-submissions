class Solution {
public:
    unordered_map<char , unordered_set<char>>adj;

    bool dfs(vector<bool>& vis, vector<bool>& recPath, char u, string& ans){
        vis[u - 'a'] = true;
        recPath[u - 'a'] = true;

        for(char v : adj[u]){
            if(!vis[v - 'a']){
                if(dfs(vis, recPath, v, ans)) return true;
            }
            else if(recPath[v - 'a']) return true;
        }

        ans.push_back(u);
        recPath[u - 'a'] = false;
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        vector<bool>vis(26 , false);
        vector<bool>recPath(26 , false);

        unordered_set<char>nodes;

        for(string& word : words){
            for(char& ch : word){
                nodes.insert(ch);
            }
        }

        for(int i = 0 ; i < words.size() - 1 ; i++){
            string& u = words[i];
            string& v = words[i + 1];

            int len = min(u.length() , v.length());
            int j = 0;

            while (j < len && u[j] == v[j]) {
                j++;
            }

            if(j < len){
                adj[u[j]].insert(v[j]);
            }
            else if(u.length() > v.length()) return "";
        }

        string ans = "";

        for(char ch : nodes){
            if(!vis[ch - 'a']){
                if(dfs(vis, recPath, ch, ans)) return "";
            }
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};
