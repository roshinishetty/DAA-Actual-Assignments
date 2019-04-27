#include <bits/stdc++.h>
#include "GrahamStack.h"

using namespace std;

GrahamStack:: GrahamStack() {

}

Point GrahamStack::getTOS() {
	return tos;
}

Point GrahamStack::getNextToTop() {
	return nextToTop;
}


void GrahamStack::pushElement(Point p) {
	stack.push_back(p);
	nextToTop = stack[ stack.size() - 2];
	tos = stack[ stack.size() - 1];
}

void GrahamStack::popElement() {
	//Point p = stack.back();
	stack.pop_back();
	tos = stack[ stack.size() - 1];
	nextToTop = stack[ stack.size() - 2];
	//return p;
}

std::vector<Point> GrahamStack::getStack() {
	//reverse(begin(stack), end(stack));
	return stack;
}