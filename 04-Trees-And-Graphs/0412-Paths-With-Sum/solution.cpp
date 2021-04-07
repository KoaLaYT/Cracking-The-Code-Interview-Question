#include "solution.hpp"

#include <map>

namespace impl {

static int path_sum(Node* node,
                    int target,
                    int current,
                    std::map<int, int>& record)
{
    if (!node) return 0;
    int count = 0;

    int sum = current + node->value;
    if (sum == target) count += 1;
    if (record.find(sum - target) != record.end()) {
        count += record[sum - target];
    }

    if (record.find(sum) == record.end()) {
        record[sum] = 0;
    }
    record[sum] += 1;

    count += path_sum(node->left, target, sum, record) +
             path_sum(node->right, target, sum, record);

    record[sum] -= 1;

    return count;
}

};  // namespace impl

int path_with_sum(Node* root, int sum)
{
    std::map<int, int> record;
    return impl::path_sum(root, sum, 0, record);
}