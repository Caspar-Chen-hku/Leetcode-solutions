class Solution {
public:
    using Pyramid = vector<vector<char>>;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        sort(allowed.begin(), allowed.end());

        Pyramid pyramid(bottom.length());
        pyramid[0].insert(pyramid[0].begin(), bottom.begin(), bottom.end());
        return dfs(allowed, pyramid, 1, 0);
    }

    bool dfs(const vector<string> &allowed, Pyramid &pyramid, const size_t level, const size_t index) {
        const auto width_of_level = pyramid[0].size() - level;
        const auto &level_below = pyramid[level - 1];
        auto &current_level = pyramid[level];
        current_level.resize(width_of_level);

        const auto left_block = level_below[index];
        const auto right_block = level_below[index + 1];
        for (const auto &pattern : allowed) {
            if (pattern[0] > left_block) {
                break;
            }
            if (pattern[0] == left_block && pattern[1] > right_block) {
                break;
            }
            if (pattern[0] == left_block && pattern[1] == right_block) {
                current_level[index] = pattern[2];
                const size_t next_index = (index == width_of_level - 1) ? 0 : index + 1;
                const size_t next_level = (index == width_of_level - 1) ? level + 1 : level;
                if (next_level >= pyramid.size()) {
                    return true;
                }

                if (dfs(allowed, pyramid, next_level, next_index)) {
                    return true;
                }
            }
        }

        return false;
    }
};