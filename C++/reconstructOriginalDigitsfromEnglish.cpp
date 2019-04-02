class Solution {
public:
    string originalDigits(string s) {
        string result = "";
        map<char,int> chars;
        for (char c:s){
            chars[c]++;
        }
        while (chars.count('z')>0 && chars['z']>0){
            result.push_back('0');
            chars['z']--; chars['e']--; chars['r']--; chars['o']--;
        }
        while (chars.count('w')>0 && chars['w']>0){
            result.push_back('2');
            chars['t']--; chars['w']--; chars['o']--;
        }
        while (chars.count('u')>0 && chars['u']>0){
            result.push_back('4');
            chars['f']--; chars['o']--; chars['u']--; chars['r']--;
        }
        while (chars.count('x')>0 && chars['x']>0){
            result.push_back('6');
            chars['s']--; chars['i']--; chars['x']--;
        }
        while (chars.count('g')>0 && chars['g']>0){
            result.push_back('8');
            chars['e']--; chars['i']--; chars['g']--; chars['h']--; chars['t']--;
        }
        while (chars.count('o')>0 && chars['o']>0){
            result.push_back('1');
            chars['o']--; chars['n']--; chars['e']--;
        }
        while (chars.count('h')>0 && chars['h']>0){
            result.push_back('3');
            chars['t']--; chars['h']--; chars['r']--; chars['e']-=2;
        }
        while (chars.count('f')>0 && chars['f']>0){
            result.push_back('5');
            chars['f']--; chars['i']--; chars['v']--; chars['e']--;
        }
        while (chars.count('s')>0 && chars['s']>0){
            result.push_back('7');
            chars['s']--; chars['e']-=2; chars['v']--; chars['n']--;
        }
        while (chars.count('e')>0 && chars['e']>0){
            result.push_back('9');
            chars['n']-=2; chars['i']--; chars['e']--;
        }
        sort(result.begin(),result.end());
        return result;
    }
};