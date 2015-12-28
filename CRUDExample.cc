#include <iostream>

#include <opencog/atomspace/AtomSpace.h>
#include <opencog/atomspace/types.h>

using namespace opencog;

int main(int argc, char ** args)
{
	opencog::AtomSpace as;
        std::cout << "Lets inset (ConceptNode \"Hello-Worold!\") and print to stdout" << std::endl;
	as.add_node(CONCEPT_NODE,"Hello-World!");
	std::cout << as << std::endl;
	return 0;
}
