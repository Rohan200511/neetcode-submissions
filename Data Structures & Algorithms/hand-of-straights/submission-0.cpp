class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int , int>freq;

        for(int num : hand) freq[num]++;

        sort(hand.begin() , hand.end()); 

        for(int num : hand){
            if(freq[num] == 0) continue;
            for(int i = num ; i < num + groupSize ; i++){
                if(freq[i] == 0) return false;
                freq[i]--; 
            }
        }
        return true;
    }
};
