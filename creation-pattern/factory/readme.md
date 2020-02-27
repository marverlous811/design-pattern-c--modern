## 1. Motivation
- Object creation logic becomes too convoluted 

- Contructor is not descriptive 
  
  * Name mandated by name of containing type

  * Cannot overload with same sets of arguments with different name

  * Can turn into "optional param hell"

- Object creation (non-piecewise, unlike builder) can be outsourced to

  * A saperate function (Factory method)

  * That may exist in a separate class (Factory)

  * Can create hierachy of factory with an Abstract Factory

### Factory: A component responsible solely for the wholesale (not piecewise) creation of object

## 2. Summary

- A factory method is static method that creates objects

- A factory can take care of object creation

- A factory can be external or reside inside the object as an inner class

- hierarchies of factories can be used to create related objects