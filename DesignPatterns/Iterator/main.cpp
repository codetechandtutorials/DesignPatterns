#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
class Iterator {
public:
  typedef typename std::vector<T>::iterator it_type;

  Iterator(U* container) : _data_ref(container) {
    _it = _data_ref->_data.begin();
  }

  void First() {
    _it = _data_ref->_data.begin();
  }

  void Next() {
    _it++;
  }

  bool AtEnd() {
    return (_it == _data_ref->_data.end());
  }

  it_type Current() {
    return _it;
  }

private:
  U* _data_ref;
  it_type _it;
};

template <typename T>
class Container {
  friend class Iterator<T, Container>;

public:
  void Add(T new_data) {
    _data.push_back(new_data);
  }

  Iterator<T, Container>* CreateIterator() {
    return new Iterator<T, Container>(this);
  }

private:
  std::vector<T> _data;
};


int main() {

  Container<int> our_data_bag;
  for (int i = 0; i < 10; i++) {
    our_data_bag.Add(i);
  }
  auto* our_iterator = our_data_bag.CreateIterator();

  for (our_iterator->First(); !our_iterator->AtEnd(); our_iterator->Next()) {
    std::cout << *our_iterator->Current() << std::endl;
  }

  return EXIT_SUCCESS;
}