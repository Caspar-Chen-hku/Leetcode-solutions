class Solution {
public:
    
    vector<string> m;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m.push_back(longUrl);
        return to_string(m.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));