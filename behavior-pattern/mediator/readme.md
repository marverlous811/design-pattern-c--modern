## Mediator

A large proportion of the code we write has different components communicating with one another through direct references or pointer. But you don't want to be aware of each other's presence, or you don't want them to communicate through pointers or references because it maybe changed in some component that you can't control.

Mediator is a mechanism for facilitating communication between the components. Naturally, the mediator itself needs to be accessible to every component taking part, which means it should either be a global static variable or, alternatively, just a reference that gets injected every component.