#pragma once
#include <iostream>
#include <concepts>
#include <type_traits>

namespace biology
{
    template <typename T>
    concept ANIMAL = requires(T t) {
        std::is_class_v<T>;
        t.Speak();
    };

    template <ANIMAL T>
    class Animal : public T
    {
    public:
        Animal() : T()
        {
            std::cout << "Animal constructor" << std::endl;
        }
        virtual ~Animal()
        {
            std::cout << "Animal destructor" << std::endl;
        }
        void Speak()
        {
            T::Speak();
        }
    };

}