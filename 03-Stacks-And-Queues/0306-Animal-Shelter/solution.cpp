#include "solution.hpp"

void AnimalQueue::enqueue(std::unique_ptr<Animal>&& animal)
{
    animal->set_id(++m_id);

    Animal* raw = animal.release();

    if (Cat* c = dynamic_cast<Cat*>(raw)) {
        m_cats.emplace_back(c);
    }
    if (Dog* d = dynamic_cast<Dog*>(raw)) {
        m_dogs.emplace_back(d);
    }
}

std::unique_ptr<Animal> AnimalQueue::dequeue_any()
{
    if (m_dogs.empty()) return dequeue_cat();
    if (m_cats.empty()) return dequeue_dog();

    std::unique_ptr<Dog>& oldest_dog = m_dogs.front();
    std::unique_ptr<Cat>& oldest_cat = m_cats.front();

    if (oldest_dog->get_id() < oldest_cat->get_id()) {
        auto dog = std::move(m_dogs.front());
        m_dogs.pop_front();
        return dog;
    } else {
        auto cat = std::move(m_cats.front());
        m_cats.pop_front();
        return cat;
    }
}

std::unique_ptr<Cat> AnimalQueue::dequeue_cat()
{
    if (m_cats.empty()) return nullptr;

    auto c = std::move(m_cats.front());
    m_cats.pop_front();
    return c;
}

std::unique_ptr<Dog> AnimalQueue::dequeue_dog()
{
    if (m_dogs.empty()) return nullptr;

    auto d = std::move(m_dogs.front());
    m_dogs.pop_front();
    return d;
}