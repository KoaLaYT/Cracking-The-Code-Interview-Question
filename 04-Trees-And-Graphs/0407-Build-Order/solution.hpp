#ifndef BUILD_ORDER_20210329
#define BUILD_ORDER_20210329

#include <list>
#include <map>
#include <vector>

/**
 * You are given a list of projects and a list of dependencies (which is a list of pairs of projects, 
 * where the second project is dependent on the first project). All of a project's dependencies must be
 * built before the project is. Find a build order that will allow the project to be built. If there is 
 * no valid build order, return an error.
 *
 * EXAMPLE:
 * input:
 *      projects: a, b, c, d, e, f
 *      dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
 * output: f, e, a, b, d, c
 */
class Work {
public:
    using Project = char;
    Work(std::vector<Project>& projects, std::vector<std::pair<Project, Project>>& dependencies);

    std::list<Project> build_order();

private:
    std::vector<Project> m_pros;
    std::map<Project, std::vector<Project>> m_deps;
};

#endif