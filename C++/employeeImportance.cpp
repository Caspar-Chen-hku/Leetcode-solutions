/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,int> values;
        map<int, vector<int>> suborts; 
        vector<int> target;
        int res;
        for (Employee* e:employees){
            if (e->id==id){
                target = e->subordinates;
                res = e->importance;
            }
            values[e->id] = e->importance;
            if (!e->subordinates.empty()) suborts[e->id] = e->subordinates;
        }
        int temp;
        while (!target.empty()){
            temp = target.back();
            target.pop_back();
            res += values[temp];
            if (suborts.count(temp)>0){
                target.insert(target.end(), suborts[temp].begin(), suborts[temp].end());
            }
        }
        return res;
    }
};