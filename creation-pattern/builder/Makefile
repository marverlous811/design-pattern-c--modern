.PHONY: person-builder person builder build

person-builder:
	g++ -std=c++17 -c -o PersonBuilder.o PersonBuilder.cpp
person: 
	g++ -std=c++17 -c -o Person.o Person.cpp
builder:
	g++ -std=c++17 -c -o builderFacets.o builderFacets.cpp
build:
	g++ -std=c++17 -o builderFacets Person.o PersonBuilder.o builderFacets.o