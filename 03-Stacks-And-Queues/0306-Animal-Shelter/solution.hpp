#ifndef ANIMAL_SHELTER_20210306
#define ANIMAL_SHELTER_20210306

#include <iostream>
#include <list>

/**
 * An animal shelter, which holds only cats and dogs, operates on a strictly
 * "first in, first out" basis. People must adopt either the "oldest" (based on
 * arrival time) of all animals on the shelter, or they can select whether they
 * would perfer a dog or a cat. They cannot select which specific animal they 
 * would like. Create the data structures to maintain this system and implement
 * operations such as `enqueue`, `dequeueAny`, `dequeueCat` and `dequeueDog`. You
 * may use the built-in `LinkedList` data structure.
 */

class Animal {
public:
    virtual ~Animal() {}
    virtual void make_sound() = 0;

    int get_id() { return m_id; }
    void set_id(int id) { m_id = id; }

protected:
    int m_id{0};
};

class Cat : public Animal {
public:
    void make_sound() override { std::cout << "Miao\n"; }
};

class Dog : public Animal {
public:
    void make_sound() override { std::cout << "Woff\n"; }
};

class AnimalQueue {
public:
    void enqueue(std::unique_ptr<Animal>&& animal);
    std::unique_ptr<Animal> dequeue_any();
    std::unique_ptr<Cat> dequeue_cat();
    std::unique_ptr<Dog> dequeue_dog();

private:
    std::list<std::unique_ptr<Cat>> m_cats;
    std::list<std::unique_ptr<Dog>> m_dogs;
    int m_id{0};
};

#endif