#include <iostream>
#include <vector>
#include <string>
#include <queue>

// std::ifstream in(filename);

template <typename T>
struct Node {
    T value;
    std::vector<Node*> children;

    Node(const T& val = T{}, const std::vector<Node*>& children = std::vector<Node*>())
        : value(val), children(children) {}
};

template <typename T>
void deallocate(Node<T>*& root)
{
    if (root == nullptr)
        return;

    for (int i = 0; i < root->children.size(); ++i)
        deallocate(root->children[i]);
    
    delete root;
    root = nullptr;
}

template <typename T>
std::vector<std::vector<T>> get_elements_per_level(Node<T>* root)
{
    if (root == nullptr)
        return std::vector<std::vector<T>>();
    
    std::queue<Node<T>*> queue;
    std::vector<std::vector<T>> result;
    std::vector<T> current_level;
    queue.push(root);
    int curr_cnt = 1, next_cnt = 0;

    while (!queue.empty())
    {
        Node<T>* temp = queue.front();
        queue.pop();

        --curr_cnt;
        current_level.push_back(temp->value);

        for (Node<T>* child : temp->children)
        {
            ++next_cnt;
            queue.push(child);
        }

        if (curr_cnt == 0)
        {
            result.push_back(current_level);
            current_level.clear();

            curr_cnt = next_cnt;
            next_cnt = 0;
        }
    }

    return result;
}

int main()
{
    Node<int>* el01 = new Node(1);
    Node<int>* el02 = new Node(2);
    Node<int>* el03 = new Node(3);
    Node<int>* el04 = new Node(4);
    Node<int>* el05 = new Node(5);
    Node<int>* el06 = new Node(6);
    Node<int>* el07 = new Node(7);
    Node<int>* el08 = new Node(8);
    Node<int>* el09 = new Node(9);
    Node<int>* el10 = new Node(10);
    Node<int>* el11 = new Node(11);

    el01->children.push_back(el02);
    el01->children.push_back(el03);
    el01->children.push_back(el04);

    el02->children.push_back(el05);
    el02->children.push_back(el06);

    el03->children.push_back(el07);

    el07->children.push_back(el08);
    el07->children.push_back(el09);
    el07->children.push_back(el10);
    el07->children.push_back(el11);

    std::vector<std::vector<int>> result = get_elements_per_level<int>(el01);

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            std::cout << result[i][j] << ' ';
        std::cout << std::endl;
    }

}