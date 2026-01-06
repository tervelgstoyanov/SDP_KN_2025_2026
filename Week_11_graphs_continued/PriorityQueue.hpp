#include <vector>

using namespace std;


template <class T>
class PriorityQueue
{
private:

	vector<T> data;
	static size_t leftChild(size_t i);
	static size_t rightChild(size_t i);
	static size_t parent(size_t i);

	void heapify(int i);

public:
	
	PriorityQueue() = default;
	PriorityQueue(const vector<T>& v);

	void pop();
	const T& top() const;
	void push(const T& el);
	size_t size() const;
	bool empty() const;
};

template<class T>
size_t PriorityQueue<T>::leftChild(size_t i)
{
	return i * 2 + 1;
}

template<class T>
size_t PriorityQueue<T>::rightChild(size_t i)
{
	return i * 2 + 2;
}

template<class T>
inline size_t PriorityQueue<T>::parent(size_t i)
{
	return (i - 1) / 2;
}

template<class T>
void PriorityQueue<T>::heapify(int i)
{
	do
	{
		size_t leftChildIdx = leftChild(i);
		if (leftChildIdx >= data.size())
			return;

		size_t rightChildIdx = rightChild(i);

		size_t child;

		if (rightChildIdx >= data.size() || data[leftChildIdx] > data[rightChildIdx])
		{
			child = leftChildIdx;
		}
		else
		{
			child = rightChildIdx;
		}

		if (data[i] >= data[child])
			return;

		swap(data[i], data[child]);
		i = child;
	} while (true);
}

template<class T>
PriorityQueue<T>::PriorityQueue(const vector<T>& v)
{
	data = v;

	for (int i = v.size() / 2 - 1; i >= 0; i--)
	{
		heapify(i);
	}
}

template<class T>
void PriorityQueue<T>::pop()
{
	if (empty())
		throw "Empty Queue";
	swap(data[0], data[data.size() - 1]);
	data.pop_back();
	if(data.size() != 0)
		heapify(0);
}

template<class T>
const T& PriorityQueue<T>::top() const
{
	if (empty())
		throw "Empty Queue";

	return data[0];
}

template<class T>
void PriorityQueue<T>::push(const T& el)
{
	data.push_back(el);
	size_t curr = data.size() - 1;
	size_t parentIdx = parent(curr);

	while (parentIdx >=0 && data[parentIdx] > data[curr])
	{
		swap(data[parentIdx], data[curr]);
		curr = parentIdx;
		parentIdx = parent(curr);
	}
}

template<class T>
size_t PriorityQueue<T>::size() const
{
	return data.size();
}

template<class T>
bool PriorityQueue<T>::empty() const
{
	return data.size() == 0;
}
