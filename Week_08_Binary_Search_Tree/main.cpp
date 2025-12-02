#include <iostream>
#include <stack>
#include <limits>
#include <vector>

const int MIN = INT_MIN, MAX = INT_MAX;


template <class T>
class BinarySearchTree {
private:
    struct BinTreeNode {
        T value;
        BinTreeNode *left, *right;

        BinTreeNode(
            const T& val = T{},
            BinTreeNode* left = nullptr,
            BinTreeNode* right = nullptr
        ) : value(val),
            left(left),
            right(right) {}
    };

public:
    BinarySearchTree() noexcept
        : root(nullptr) {}

    BinarySearchTree(const BinarySearchTree& other)
        : root(copy(other.root)) {}

    BinarySearchTree(BinarySearchTree&& other) noexcept
        : root(other.root)
    {
        other.root = nullptr;
    }

    BinarySearchTree& operator = (const BinarySearchTree& other)
    {
        if (this != &other)
        {
            deallocate(root);
            root = copy(other.root);
        }
        return *this;
    }

    BinarySearchTree& operator = (BinarySearchTree&& other) noexcept
    {
        if (this != &other)
        {
            deallocate(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    ~BinarySearchTree()
    {
        deallocate(root);
    }
    int get_depth()
    {
        return get_depth(root);
    }
    int get_depth(const BinTreeNode* root)
    {
        if (root == nullptr)
            return 0;

        return 1 + std::max(
            get_depth(root->left),
            get_depth(root->right)
        );
    }

    bool contains(const T& element) const
    {
        return find(root, element);
    }

    void insert(const T& element)
    {
        insert(root, element);
    }

    void erase(const T& element)
    {
        erase(root, element);
    }

    void print_inorder() const
    {
        print_inorder(root);
        std::cout << std::endl;
    }


    T extract_kth(int k) const
    {
        int cnt = 0;

        for (auto it = begin(); it != end(); ++it)
        {
            ++cnt;
            if (cnt == k)
                return *it;
        }

        return T{};
    }

    void balance()
    {
        std::vector<T> arr;
        for (auto it = begin(); it != end(); ++it)
            arr.push_back(*it);
        deallocate(root);

        root = create_tree(arr, 0, arr.size() - 1);

        return;
    }

    bool is_valid() const
    {
        return is_valid(root, MIN, MAX);
    }

    class ConstIterator {
    public:
        ConstIterator() = default;

        const T& operator*() const {
            if (stack.empty())
                throw std::out_of_range("ConstIterator: dereference of end()");
            return stack.top()->value;
        }

        const T* operator->() const {
            if (stack.empty())
                throw std::out_of_range("ConstIterator: access through end()");
            return &stack.top()->value;
        }

        ConstIterator& operator++() {
            advance();
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            advance();
            return tmp;
        }

        bool operator==(const ConstIterator& other) const {
            return tree_ref == other.tree_ref &&
                ((stack.empty() && other.stack.empty()) 
                || (stack.size() == other.stack.size() && advance_cnt == other.advance_cnt));
        }

        bool operator!=(const ConstIterator& other) const {
            return !(*this == other);
        }

    private:
        std::stack<const BinTreeNode*> stack;
        const BinarySearchTree<T>* tree_ref = nullptr;
        int advance_cnt = 0;

        explicit ConstIterator(const BinTreeNode* start, const BinarySearchTree<T>* ref)
            : tree_ref(ref) 
        {
            push_left(start);
        }

        void push_left(const BinTreeNode* node) {
            while (node) {
                stack.push(node);
                node = node->left;
            }
        }

        void advance() {
            if (stack.empty())
                return;

            ++advance_cnt;
            const BinTreeNode* node = stack.top();
            stack.pop();

            if (node->right)
                push_left(node->right);
        }
        
        friend class BinarySearchTree<T>;
    };

    ConstIterator begin() const {
        return ConstIterator(root, this);
    }

    ConstIterator end() const {
        return ConstIterator(nullptr, this);
    }


    ConstIterator cbegin() const { return begin(); }
    ConstIterator cend() const { return end(); }

private:
    BinTreeNode *root;

    static BinTreeNode* copy(const BinTreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        
        return new BinTreeNode(
            root->value,
            copy(root->left), // left child
            copy(root->right) // right child
        );
    }

    static void deallocate(BinTreeNode*& root)
    {
        if (root == nullptr)
            return;

        deallocate(root->left);
        deallocate(root->right);

        delete root;
        root = nullptr;
    }

    static bool find(const BinTreeNode* root, const T& element)
    {
        if (root == nullptr)
            return false;

        if (root->value == element)
            return true;

        if (root->value < element)
            return find(root->right, element);

        return find(root->left, element);
    }

    static void insert(BinTreeNode*& root, const T& element)
    {
        if (root == nullptr)
        {
            root = new BinTreeNode(element);
            return;
        }

        if (root->value > element)
            insert(root->left, element);
        else
            insert(root->right, element);
    }

    static void erase(BinTreeNode*& root, const T& element)
    {
        if (root == nullptr)
            return;

        if (root->value > element)
        {
            erase(root->left, element);
            return;
        }

        if (root->value < element)
        {
            erase(root->right, element);
            return;
        }

        BinTreeNode* toDelete = root;
        if (root->left == nullptr && root->right == nullptr)
            root = nullptr;
        else if (root->left && root->right == nullptr)
            root = root->left;
        else if (root->left == nullptr && root->right)
            root = root->right;
        else
        {
            BinTreeNode* min_leaf = extract_min(root->right);
            min_leaf->left = root->left;
            min_leaf->right = root->right;
            root = min_leaf;
        }

        delete toDelete;
    }

    static BinTreeNode* extract_min(BinTreeNode*& root)
    {
        if (root->left)
            return extract_min(root->left);

        BinTreeNode* min_leaf = root;
        root = root->right;
        return min_leaf;
    }

    static void print_inorder(const BinTreeNode* root)
    {
        if (root == nullptr)
            return;

        print_inorder(root->left);
        std::cout << root->value << ' ';
        print_inorder(root->right);
    }


    bool is_valid(const BinTreeNode* root, int MIN, int MAX)
    {
        if (root == nullptr)
            return true;
        
        return MIN < root->value && root->value <= MAX
            && is_valid(root->left, MIN, root->value)
            && is_valid(root->right, root->value, MAX); 
    }

    BinTreeNode* create_tree(const std::vector<T>& arr, int start, int end)
    {
        if (arr.size() == 0)
            return nullptr;

        if (end < start)
            return nullptr;

        int mid_idx = start + (end - start) / 2;
        
        return new BinTreeNode(
            arr[mid_idx],
            create_tree(arr, start, mid_idx - 1),
            create_tree(arr, mid_idx + 1, end)
        );
    }
};

int main()
{
    // std::cout << "=== TEST: Insertion and print_inorder ===\n";
    // BinarySearchTree<int> bst;
    // bst.insert(8);
    // bst.insert(3);
    // bst.insert(10);
    // bst.insert(1);
    // bst.insert(6);
    // bst.insert(14);
    // bst.insert(4);
    // bst.insert(7);
    // bst.insert(13);

    // std::cout << "Inorder should be sorted:\n";
    // bst.print_inorder();  // Expected: 1 3 4 6 7 8 10 13 14

    // std::cout << "\n=== TEST: contains() ===\n";
    // std::cout << "bst.contains(6) = " << bst.contains(6) << " (expected 1)\n";
    // std::cout << "bst.contains(99) = " << bst.contains(99) << " (expected 0)\n";

    // std::cout << "\n=== TEST: Iterator traversal ===\n";
    // std::cout << "Iterator inorder: ";
    // for (auto it = bst.begin(); it != bst.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << "\n";

    // std::cout << "\n=== TEST: cbegin()/cend() ===\n";
    // for (auto it = bst.cbegin(); it != bst.cend(); ++it)
    //     std::cout << *it << " ";
    // std::cout << "\n";

    // std::cout << "\n=== TEST: Copy constructor ===\n";
    // BinarySearchTree<int> bst_copy(bst);
    // std::cout << "Copy inorder: ";
    // bst_copy.print_inorder();

    // std::cout << "\nModifying copy...\n";
    // bst_copy.insert(999);

    // std::cout << "Original should NOT have 999: ";
    // bst.print_inorder();
    // std::cout << "Copy should have 999: ";
    // bst_copy.print_inorder();

    // std::cout << "\n=== TEST: Move constructor ===\n";
    // BinarySearchTree<int> bst_moved(std::move(bst_copy));
    // std::cout << "Moved inorder: ";
    // bst_moved.print_inorder();
    // std::cout << "Original moved-from should be empty: ";
    // bst_copy.print_inorder();

    // std::cout << "\n=== TEST: Copy assignment ===\n";
    // BinarySearchTree<int> bst2;
    // bst2 = bst;
    // std::cout << "bst2 after copy assignment: ";
    // bst2.print_inorder();

    // std::cout << "\n=== TEST: Move assignment ===\n";
    // BinarySearchTree<int> bst3;
    // bst3 = std::move(bst2);
    // std::cout << "bst3 after move assignment: ";
    // bst3.print_inorder();
    // std::cout << "bst2 moved-from should be empty: ";
    // bst2.print_inorder();

    // std::cout << "\n=== TEST: erase() ===\n";

    // BinarySearchTree<int> remove_test;
    // remove_test.insert(5);
    // remove_test.insert(3);
    // remove_test.insert(7);
    // remove_test.insert(2);
    // remove_test.insert(4);
    // remove_test.insert(6);
    // remove_test.insert(8);

    // std::cout << "Original: ";
    // remove_test.print_inorder();

    // std::cout << "Erase leaf (2)\n";
    // remove_test.erase(2);
    // remove_test.print_inorder();

    // std::cout << "Erase node with one child (4)\n";
    // remove_test.erase(4);
    // remove_test.print_inorder();

    // std::cout << "Erase node with two children (7, which has 6 and 8)\n";
    // remove_test.erase(7);
    // remove_test.print_inorder();

    // std::cout << "Erase root with two children (5)\n";
    // remove_test.erase(5);
    // remove_test.print_inorder();

    // std::cout << "\n=== ALL TESTS COMPLETE ===\n";
    
    BinarySearchTree<int> bst;
    for (int i = 0; i <= 10; ++i)
        bst.insert(i);
    
    bst.print_inorder();
    std::cout << bst.get_depth() << std::endl;

    bst.balance();
    std::cout << bst.get_depth() << std::endl;
    bst.print_inorder();

    std::cout << bst.extract_kth(5) << std::endl;

    return 0;
}
