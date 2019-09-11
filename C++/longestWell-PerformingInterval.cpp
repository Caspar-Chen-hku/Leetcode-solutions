class Solution {
public:
    int longestWPI(vector<int>& hours) {
        size_t max_len = 0;
		int count = 0;
		int min_count = 0;
		auto map = unordered_map<int, size_t>();
		for (auto h = hours.begin(); h < hours.end(); ++h) {
			const bool isTiring = *h > 8;
			const size_t i = h - hours.begin();
			count = (isTiring) ? count + 1 : count - 1;
			if (count > 0) {
				max_len = i + 1;
				continue;
			}
			if (isTiring)
				max_len = max(max_len, i - map[count - 1]);
			if (count < min_count) {
				min_count = count;
				map.insert(make_pair(min_count, i));
			}
		}
		return max_len;
    }
};