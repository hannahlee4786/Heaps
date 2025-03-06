#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  int m_;
  PComparator c_;
  std::vector<T> vals; // Stores the nodes
  void swap(int idx1, int idx2);
};

// Swaps two nodes in the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int idx1, int idx2) {
  T temp = vals[idx1];
  vals[idx1] = vals[idx2];
  vals[idx2] = temp;
}

// Constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m=2, PComparator c = PComparator()) : 
  m_(m), c_(c) {
}

// Destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

// Adds an item to the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  // Adds item to the back
  vals.push_back(item);

  // Sorts heap to min/max heap
  int idx = size() - 1;
  while (1) {
    int parentIdx = (idx - 1) / m_;
    if (c_(vals[idx], vals[parentIdx])) {
      swap(idx, parentIdx);
      idx = parentIdx;
    }
    else {
      break;
    }
  }
}

// Gives top element of heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  // Heap has at least 1 element, return the front
  return vals.front();
}

// Removes top element of heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }

  // Swap first and last element
  swap(0, vals.size() - 1);
  // Delete last element
  vals.pop_back();

  // If removing creates empty heap
  if(empty()) {
    return;
  }
  
  // Heapify
  int currentIdx = 0;
  while (1) {
    int bestIdx = currentIdx;
    int firstChild = m_ * currentIdx + 1;

    for (int i = 0; i < m_; i++) {
      int childIdx = firstChild + i;
      if (childIdx < vals.size() && c_(vals[childIdx], vals[bestIdx])) {
        bestIdx = childIdx;
      }
    }

    // If no swap is needed, we are done
    if (bestIdx == currentIdx) {
      break;
    }
    // Else swap
    swap(currentIdx, bestIdx);
    currentIdx = bestIdx;
  }
}

// Check if heap is empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return vals.empty();
}

// Returns the size of heap
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return vals.size();
}

#endif