#include "solution.hpp"

Work::Work(
    std::vector<Project>& projects,
    std::vector<std::pair<Project, Project>>& dependencies)
    : m_pros{projects}
{
    for (auto& pair : dependencies) {
        if (m_deps.find(pair.first) == m_deps.end()) {
            m_deps[pair.first] = std::vector<Project>{};
        }
        m_deps[pair.first].push_back(pair.second);
    }
}

namespace detail {

struct DFSInfo {
    enum class Color {
        White,
        Gray,
        Black
    };

    Color c{Color::White};
};

void dfs(
    Work::Project p,
    std::map<Work::Project, DFSInfo>& info,
    std::map<Work::Project, std::vector<Work::Project>>& deps,
    std::list<Work::Project>& result)
{
    if (info[p].c != DFSInfo::Color::White) return;

    info[p].c = DFSInfo::Color::Gray;
    if (deps.find(p) != deps.end()) {
        for (auto& dep : deps[p]) {
            if (info[dep].c == DFSInfo::Color::Gray) {
                throw std::runtime_error{"No Valid Build Order"};
            }
            dfs(dep, info, deps, result);
        }
    }
    info[p].c = DFSInfo::Color::Black;
    result.push_front(p);
}

};  // namespace detail

std::list<Work::Project> Work::build_order()
{
    std::list<Work::Project> result{};

    std::map<Work::Project, detail::DFSInfo> info;
    for (Work::Project p : m_pros) {
        info[p] = detail::DFSInfo{};
    }

    for (Work::Project p : m_pros) {
        detail::dfs(p, info, m_deps, result);
    }

    return result;
}