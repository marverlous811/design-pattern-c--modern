## 1. Motivation

- For some component it only makes sense to have one in the system

    - Database repository

    - Object Factory

- E.g the constructor call is expensive

    - We only do it once

    - We provide everyone with the same instance

- Want to prevent anyone creating additional copies

- Need to take care of lazy instantiation and thread safety

## => SINGLETON: A component which is instantiated only once

## 2. Sumary

- Making a 'safe' singleton is easy

    - Hide or delete the type's constructor, copy constructor and copy assignment operator

    - Create a static method that returns a reference to a static memeber

    - Guaranteed to be thread-safe since C++11

- Type with 'hard' dependencies on singleton are difficult to test (direct dependency is not a good idea)

    - cannot decouple the singleton and supply a fake object

- Instead of directly using singleton, consider depending on an abstraction(or interface...)

- Consider defining singleton lifetime in DI (dependency injector) container