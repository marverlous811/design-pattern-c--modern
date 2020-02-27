# BUILDER 
### when construction gets a little bit too complicated

## 1. Motivation

- Some object are simple and can be created in a single contructor call
- Other object require a lot of ceremny to create
- Having an object with 10 constructor argument is not productive
- Instead, opt for piecewise constrution
- Builder privdes an API for constructing an object step-by-step

### => when piecewise object construction is complicated provide an API for doing it succinctly.

## 2.Sumary

- A builder is a separate component for building object
- Can either give builder a constructor or return it via a static function
- To make builder fluent return this
- Different facets of an object can be build with different builders working in tandem via a base class