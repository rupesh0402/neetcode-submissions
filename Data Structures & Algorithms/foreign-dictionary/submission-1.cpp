class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        int n = 26;
        vector<vector<int>> graph(n);
        vector<int> exist(n, 0);

    //only existing characters
        for(auto &word : words) {
            for(char ch: word) {
                exist[ch - 'a'] = 1;
            }
        }

        

        for(int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(), s2.size());

            if(s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len)) {
                return "";  //wrong order
            }
            for(int j = 0; j < len; j++) {

                if(s1[j] != s2[j]) {
                    graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        //topo sort
        vector<int> visited(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            if(exist[i] && visited[i] == 0)
                if(!dfs(i,graph,st,visited)){
                    return "";
                }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        string ans = "";

        for(int i : res)
            ans += (i + 'a');

        return ans;
    }

    bool dfs(int node, vector<vector<int>>& graph, stack<int>& st, vector<int>& visited){

        visited[node] = 1; //visiting

        for(int nei : graph[node]){
            if(visited[nei] == 1) {
                return false;   //cycle exist
            }

            if(visited[nei] == 0) {
                if(!dfs(nei,graph,st,visited)){
                    return false;
                }
        }
        }
        
        visited[node] = 2;
        st.push(node);

        return true;
    }
};