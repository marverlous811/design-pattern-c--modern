Chain of responsibility is a very simple pattern that lets component process a cmd or query in turn.

A more sophisticated Broker chain implementation that also leverages the mediator and Observer pattern allows us to proccess queries on an event (signal), letting each subcriber perform modification of the originally passed object before the final values are return to the client