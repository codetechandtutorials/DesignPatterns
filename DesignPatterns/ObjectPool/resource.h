#include <cstdlib>
// example derived from https://sourcemaking.com/design_patterns/object_pool/cpp/1
class Resource {
private:
  int value;
public:
  Resource() {
    value = 0;
  }
  void reset() {
    value = 0;
  }
  int getValue() {
    return value;
  }
  void setValue(int number) {
    value = number;
  }
};