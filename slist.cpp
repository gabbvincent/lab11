#include "slist.h"

  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList::SList(){
    head = nullptr;
    size = 0;
  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  SList::~SList() {
    this->clear();
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void SList::pushFront(int value) {
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
    size++;
  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void SList::popFront() noexcept(false) {
    if (head == nullptr) {
      throw logic_error("EMPTY LIST");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
  }

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  int SList::front() noexcept(false) {
    if (head == nullptr) {
      throw logic_error("EMPTY LIST");
    }

    return head->value;
  }

  // Return the number of nodes in this list.
  unsigned int SList::getSize() const {
    return this->size;
  }

  // Check to see if this list is empty.
  bool SList::empty() const {
    return size == 0;
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void SList::clear() {
    while (!empty()) {
      popFront();
    }
  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string SList::toString() const {
    ostringstream output;
    Node* temp = head;
    while (temp != nullptr) {
      output << temp ->value;
      if (temp->next != nullptr) {
        output << ",";
      }
      temp = temp->next;
    }

    return output.str();

  }