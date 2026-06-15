class TimeMap {
public:

    unordered_map<string , vector<pair<string , int>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        auto& it = mp[key];

        int l = 0 , r = it.size() - 1;
        string ans = "";
        while(l <= r){
            int mid = l + ((r - l) / 2);

            if(it[mid].second <= timestamp){
                ans = it[mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
