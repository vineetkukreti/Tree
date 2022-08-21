#include <vector>
using namespace std;
template<typename T>
class Tree
{
public:
    T data;
    vector<Tree<T> *> children;
};