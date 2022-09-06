# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPatterns")

# Include sub-projects.
add_subdirectory("DesignPatterns/Factory")
add_subdirectory("DesignPatterns/Singleton")
add_subdirectory("DesignPatterns/Factory2")
add_subdirectory("DesignPatterns/ObjectPool")
add_subdirectory("DesignPatterns/Decorator")
add_subdirectory("DesignPatterns/Decorator2")
add_subdirectory("DesignPatterns/Facade")
add_subdirectory("DesignPatterns/Adapter")
add_subdirectory("DesignPatterns/Composite")
add_subdirectory("DesignPatterns/Proxy")
add_subdirectory("DesignPatterns/Flyweight")
add_subdirectory("DesignPatterns/Visitor")
add_subdirectory("DesignPatterns/Observer")
add_subdirectory("DesignPatterns/Observer2")

