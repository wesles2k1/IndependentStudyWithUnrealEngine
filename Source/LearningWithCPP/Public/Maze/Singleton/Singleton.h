#pragma once

#include <iostream>

// Singleton is a generallized "static class" that holds and ensures only one unique instance of a given class is instantiated via the singleton design pattern. The Singleton class itself cannot be instantiated.
// This class allows for parent-children coexistance; for example, a class and it's parent class may both have a stored instantiation, despite technically having two instances of type Parent.
// 
// To use Singleton: 
//     1. Privatize/Protect Your Constructor
//         Lock YourClass's constructor(s) by making it protected or private. Make sure to provide a definition, even if it's empty or default.
//         (While a private/protected constructor is not required for Singleton to function properly with YourClass, failing to do this will allow normal instantiation of YourClass, which likely will defeat the whole point of using Singleton. Despite this, there may be times you might want a public constructor so as to allow instantiation of YourClass, but utilize a psudo-globally-accessible uniqueInstance to work with.)
//     2. Declare Siongleton as a Friend
//         Give Singleton access to the constructor(s) by declaring Singleton as a friend of YourClass with:
//             friend class Singleton();
//     3. Usage
//         Use the Singleton functionality with:
//             Singleton::Get<YourClass>();
//         to get (and instantiate if necessary) a pointer to the one and only instance of YourClass. This can be used anywhere in a program so long as Singleton.h is included.

// Statically retrieves or creates a one-of-a-kind instance of any desired classes
// Classes to be used must declare Singleton as a friend and should protect or privatize their constructor
// Allows parent-child coexistence
class Singleton final {
    public:
        // Retreives or creates (if necessary) a one-of-a-kind instance of a class
        template <typename T>
        static T* Get() {
            if (uniqueInstance<T> == nullptr) {
                //std::cout << "Making new instance." << std::endl;
                uniqueInstance<T> = new T();
            } else {
                //std::cout << "This instance already exists!" << std::endl;
            }
            return uniqueInstance<T>;
        }

    private:
        // Private deleted constructor to prevent instantiation of this class
        Singleton() = delete;

        // The one-of-a-kind instance of a class
        template <typename T>
        static T* uniqueInstance;
};

// Initialize instance to nullptr
template <typename T>
T* Singleton::uniqueInstance = nullptr;