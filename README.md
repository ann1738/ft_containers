# ft_containers 
Re-implementation of STL's std:vector, std::map, std::stack, and std::set complying with c++98 standards along with a .

# Vector
Vector is best described as the combination of the best features of a static array and a linked list. A static array enables extremely fast access of stored elements but is limited to the size allocated to the array. A linked-list allows the ability to add/remove elements after initial allocation but  restricts the speed of element access.

The result of this union is a dynamic array that would automatically reallocate memory as needed depending on element insertion. Vector also destructs (frees the memory associated with it) automatically free the user from memory management!

# Map
Map is an ordered data structure who's core building block is a pair of key and a corresponding value. It's typically implemented as a balanced binary search tree. The binary search tree I implemented for map is the AVL binary search tree, which remains strictly balanced as the elements are inserted. This allows my map to have pretty quick speeds in terms searching/finding a key.

# Stack
Stack is a container adapter. That means stack takes a container and allows only a subset of its functions. For example, stack does not contain iterators even if the underlying container has iterators. Additionally, stack works under a Last-In First-Out (LIFO) context, which means that as the user inserts elements, they stack up such that the last inserted element is on top and and this same element is the first to be removed. 

# Set
Set, similar to map, is a binary search tree. The specific type of the tree I implemented for set is a red-black tree. A red-black tree comprimises strict balancing that an AVL tree possesses for quicker insertion and deletion. Set, unlike map, has only a key in each of its elements.
