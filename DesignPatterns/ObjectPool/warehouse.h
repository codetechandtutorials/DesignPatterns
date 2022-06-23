#include "resource.h"
#include <list>

// example derived from https://sourcemaking.com/design_patterns/object_pool/cpp/1

class Warehouse {
private:
  static Warehouse* instance;
  std::list<Resource*> resources;
  Warehouse() {}
public:
  /**
   * Static method for accessing class instance.
   * Part of Singleton design pattern.
   *
   * @return Warehouse instance.
   */
  static Warehouse* getInstance() {
    if (instance == 0) {
      instance = new Warehouse;
    }
    return instance;
  }
  /**
   * Returns instance of Resource.
   *
   * New resource will be created if all the resources
   * were used at the time of the request.
   *
   * @return Resource instance.
   */
  Resource* getResource() {
    if (resources.empty()) {
      std::cout << "Creating new." << std::endl;
      return new Resource();
    } else {
      std::cout << "Reusing existing." << std::endl;
      Resource* resource = resources.front();
      resources.pop_front();
      return resource;
    }
  }
  /**
   * Return resource back to the pool.
   *
   * The resource must be initialized back to
   * the default settings before someone else
   * attempts to use it.
   *
   * @param object Resource instance.
   * @return void
   */
  void returnResource(Resource* object) {
    object->reset();
    resources.push_back(object);
  }
};


Warehouse* Warehouse::instance = nullptr;