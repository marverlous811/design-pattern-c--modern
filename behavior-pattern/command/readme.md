## Command

Think about a variable assignment: when the variables have an assignment, they got assigned. But nobody know it previous value, and the problem is we are unable to roll back to previus value, perform audits or do history-based debugging.

=> The command design pattern propose that, instead of working with object directly by manipulating them through their APIs, we send them commands: instructions on how to do something

### Command Query Separation (CQS)

the notions of CQS is the idea that operations in a system fall boardly into the following categories:

- Commands, which are instructions for the system to perform some operation that invloves mutation of state but yields no value

- Queries, which are requests for information that yield values but do not mutate state 

### Sumanry

The command design pattern is simple: what it basically suggests is that object can communicate with one another using speacial object that encapsulate instructions, rather than specifying those same instructions as arguments to a method.

Commands are used a lot in UI systems to encapsulate typical actions and then allow a single command to be invoked by several different means,