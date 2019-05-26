class Solution {
public:
    string pushDominoes(string dominoes) {
        char lastPush = 'L';
        int lastInd = -1;
        string res = "";
        for (int i=0; i<dominoes.size(); i++){
            if (dominoes[i]=='L'){
                if (lastPush=='L'){
                    res += string(i-lastInd, 'L');
                }else{
                    res += string((i-lastInd+1)/2, 'R');
                    res += string((i-lastInd+1)%2, '.');
                    res += string((i-lastInd+1)/2, 'L');
                }
                lastPush = 'L'; lastInd = i;
            }else if(dominoes[i]=='R'){
                if (lastPush=='L'){
                    res += string(i-lastInd-1,'.');     
                }else{
                    res += string(i-lastInd, 'R');
                }
                lastPush = 'R'; lastInd = i;
            }
        }
        if (lastPush=='R'){
            res += string(dominoes.size()-lastInd, 'R');
        }else if (lastPush=='L'){
            res += string(dominoes.size()-1-lastInd, '.');
        }
        return res;
    }
};