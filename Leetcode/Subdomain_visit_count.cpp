class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int>mp;
        vector<string>res;
        for(int i =0; i<cpdomains.size(); i++){
            string s;
            int z = 0, a;
            while(!isspace(cpdomains[i][z])){
                s += cpdomains[i][z];
                z++;
            }
            //cout<<z<<endl;
            a = stoi(s);
            //cout<<a<<endl;
            s.clear();
            for(int j = cpdomains[i].length() - 1; j >= z; j--){
                if(cpdomains[i][j] == '.' || j == z){
                    reverse(s.begin(), s.end());
                    if(mp.find(s) == mp.end())
                        mp[s] = a;
                    else 
                        mp[s] += a;
                    reverse(s.begin(), s.end());
                }
                s += cpdomains[i][j];
            }
            //cout<<s<<endl;
            s.clear();
        }
        for(auto i : mp){
            string st;
            st += to_string(i.second);
            st += " ";
            st += i.first;
            res.push_back(st);
        }
        return res;
    }
};