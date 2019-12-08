# C++11 compatible tuple header-only implementation with variadic templates

For my c++ practice

## 'Installation'
```c++
#include "tuple.hpp> // just include the header file
```

## Example
```c++
#include <iostream>

#include "tuple.hpp"

int main() {
    tpl::tuple<int, std::string, double> tp{10, std::string("hello world"), 2.0};
    std::cout << tpl::get<1>(tp) << std::endl;
}
```
