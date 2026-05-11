class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        //we are building the adjaceny list here 
        for(auto &i: prerequisites) {
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int> state(numCourses,0);
        
        for(int i=0; i<numCourses; i++) {
            if(dfsCycle(graph, state, i)) {
                return false;
            }
        }
        return true;
    }

    bool dfsCycle(vector<vector<int>>& graph, vector<int>& state, int i) {
        
        if(state[i] == 1) return true; //cycle exist as we are visiting this Node
        if(state[i] == 2) return false; //It's already visited

        state[i] = 1;

        for(auto nei: graph[i]) {
            if(dfsCycle(graph, state, nei)) {
                return true;
            }
        }

        state[i] = 2;
        return false;
    }
};
