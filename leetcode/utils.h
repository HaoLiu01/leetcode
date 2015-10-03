#include <iostream>
#include <string>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL)
    {
    }
};

namespace util
{
void title(const char *s)
{
    std::cout << s << std::endl;
}

void output(vector<int> &vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << std::endl;
}

void output(vector<vector<int> > &input)
{
    for (vector<int> vec : input)
        output(vec);
}

void output(vector<string> vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << std::endl;
}
}
