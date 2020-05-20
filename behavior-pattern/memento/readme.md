## Memento

Command design pattern => recording a list of every single change theoritically allows you to rollback the system to any point in time
But sometime you don't really care about playing back the state of system, but you care about being able to rollback the system to a particular state

=> Memento: it stores the state of the system and returns it as a dedicated, read-only object with no behavior of its own.