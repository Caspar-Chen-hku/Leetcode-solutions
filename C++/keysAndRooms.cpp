class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int l = rooms.size();
        vector<bool> visited(l, false);
        visit(visited, rooms, 0);
        for (bool v:visited){
            if (!v) return false;
        }
        return true;
    }
    
    void visit(vector<bool>& visited, vector<vector<int>>& rooms, int cur){
        visited[cur]=true;
        for (int i:rooms[cur]){
            if (!visited[i]){
                visit(visited, rooms, i);
            }
        }
    }
};