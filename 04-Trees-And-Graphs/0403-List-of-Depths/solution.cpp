#include "solution.hpp"

#include <queue>

std::vector<std::list<Node*>> Tree::each_depths()
{
    std::vector<std::list<Node*>> result;
    if (!m_root) return result;

    std::queue<Node*> q;
    q.push(m_root);
    while (!q.empty()) {
        int size = q.size();
        std::list<Node*> list;
        for (int i = 0; i < size; ++i) {
            Node* front = q.front();
            q.pop();
            list.push_back(front);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        result.push_back(list);
    }

    return result;
}