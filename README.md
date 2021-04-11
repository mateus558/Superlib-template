# Superlib template

This template was created when I needed to combine several libraries subprojects that I created into one. It assumes that your desired project has the following structure:

```
- superlib
    - subprojects
        - liba
            ...
        - libb
            ...
        - libc
            ...
```

## Compiling code

After installing the project in your system, you can compile your code that utilizes these libraries in two ways, first giving the flags for the individual libraries that were used. Supose that you used all sample libraries in your code as below:

**main.cpp**
```cpp
#include <superlib/liba/liba.hpp>
#include <superlib/libb/libb.hpp>
#include <superlib/libc/libc.hpp>

int main(int argc, char* argv[]){
    liba::Liba obj_a;
    libb::Libb obj_b;
    libc::Libc obj_c;

    std::cout << obj_a.get_number() << std::endl;
    std::cout << obj_b.get_number() << std::endl;
    std::cout << obj_c.get_number() << std::endl;
}
```

You can compile this code passing all flags for the individual libraries:

```
g++ main.cpp -o main -lliba -llibb -llibc
```
Or by passing only the "super" library flag to the compiler:
```
g++ main.cpp -o main -lsuperlib
```

## TODO

* **Add tests.**
* **Add code coverage.**
* **Add trevor CI.**
* **Add docs generation with doxygen.**