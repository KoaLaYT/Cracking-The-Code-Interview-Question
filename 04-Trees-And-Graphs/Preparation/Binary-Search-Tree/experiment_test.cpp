#include <algorithm>
#include <cstdio>
#include <iterator>
#include <random>
#include <vector>

#include "solution.hpp"

class RandomVector {
public:
    explicit RandomVector(int size)
    {
        m_v.reserve(size);
        for (int i = 0; i < size; ++i) {
            m_v.push_back(i + 1);
        }
        std::random_device rd;
        m_g = std::mt19937{rd()};
    }

    void shuffle() { std::shuffle(m_v.begin(), m_v.end(), m_g); }

    const std::vector<int>& data() { return m_v; }

    void print()
    {
        for (auto& e : m_v) {
            std::printf("%d, ", e);
        }
        std::printf("\n");
    }

private:
    std::vector<int> m_v;
    std::mt19937 m_g;
};

int main(int argc, char* argv[])
{
    int size = 100;
    int size_loop = 6;
    constexpr int CAL_LOOP = 100;

    while (--size_loop > 0) {
        size *= 10;
        RandomVector rv{size};
        int total = 0;
        for (int i = 0; i < CAL_LOOP; ++i) {
            rv.shuffle();
            Tree t;
            for (auto e : rv.data()) {
                t.insert(e);
            }
            total += t.height();
        }
        std::printf("For size = %10d, average tree height = %.2f\n", size, (double)total / CAL_LOOP);
    }
}