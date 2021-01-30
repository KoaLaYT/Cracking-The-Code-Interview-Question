#include "solution.hpp"

#include <cassert>
#include <cmath>
#include <cstdio>

constexpr int BASE = 256;
constexpr int PRIME = 101;

class RabinKarpSearcher;

class Pattern {
public:
    explicit Pattern(const std::string& pattern)
        : m_pattern{pattern}
    {
        for (int i = 0; i < m_pattern.length(); ++i) {
            m_hash = (BASE * m_hash + m_pattern[i]) % PRIME;
        }
    }

private:
    const std::string& m_pattern;
    int m_hash{0};
    friend class RabinKarpSearcher;
};

class RabinKarpSearcher {
public:
    RabinKarpSearcher(int window_size, const std::string& text)
        : m_window_size{window_size},
          m_text{text}
    {
        for (int i = 0; i < m_window_size; ++i) {
            m_hash = (BASE * m_hash + m_text[i]) % PRIME;
            if (i < m_window_size - 1) {
                m_digits = (m_digits * BASE) % PRIME;
            }
        }
    }

    bool hash_eq(const Pattern& pattern) { return pattern.m_hash == m_hash; }

    bool has_next() { return m_index < m_text.length() - m_window_size + 1; }

    std::vector<size_t> result() { return std::move(m_result); }

    void check(const Pattern& pattern)
    {
        for (int i = 0; i < pattern.m_pattern.length(); ++i) {
            if (pattern.m_pattern[i] != m_text[m_index + i])
                return;
        }
        m_result.push_back(m_index);
    }

    void next_hash()
    {
        if (m_index < m_text.length() - m_window_size) {
            m_hash = ((m_hash - m_text[m_index] * m_digits) * BASE + m_text[m_index + m_window_size]) % PRIME;
            if (m_hash < 0) m_hash += PRIME;
        }
        m_index++;
    }

private:
    int m_digits{1};
    int m_hash{0};
    int m_index{0};
    const std::string& m_text;
    int m_window_size;
    std::vector<size_t> m_result{};
};

std::vector<size_t> search(const std::string& pattern, const std::string& text)
{
    int p_len = pattern.length();
    int t_len = text.length();
    //! text must longer than the pattern
    assert(p_len <= t_len);

    Pattern pat{pattern};
    RabinKarpSearcher searcher{p_len, text};

    while (searcher.has_next()) {
        if (searcher.hash_eq(pat)) {
            searcher.check(pat);
        }
        searcher.next_hash();
    }

    return searcher.result();
}