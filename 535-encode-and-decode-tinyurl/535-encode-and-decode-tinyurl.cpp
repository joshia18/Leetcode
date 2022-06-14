class Solution {
public:
    unordered_map<string, string> mp;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++;
        string temp = "http://tinyurl.com/";
        string tinyurl = temp + to_string(num);
        mp[tinyurl] = longUrl;
        return tinyurl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));