# Superlib template

This template was created when I needed to combine several libraries subprojects that I created into one. It assumes that your desired project has the following structure:

```
- superlib
    - subprojects
        - liba
            -include
                -liba
                    ...
            -src
                ...
        - libb
            -include
                -libb
                    ...
            -src
                ...
        - libc
            -include
                -libc
                    ...
            -src
                ...
```
The code bellow is used to install the sample library into the system with meson build system.
```
meson debug --prefix /usr
meson compile -C debug
meson install -C debug
```

Alternatively, you can use cmake build system.
```
mkdir debug
cmake ..
make
sudo make install
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

## Requirements
- meson==0.56
- g++>=7
- doxygen

## TODO

* **Add tests.**
* **Add code coverage.**
* **Add trevor CI.**
