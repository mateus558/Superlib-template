#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBC
    #define LIBC_PUBLIC __declspec(dllexport)
  #else
    #define LIBC_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBC
      #define LIBC_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define LIBC_PUBLIC
  #endif
#endif

namespace libc {

class LIBC_PUBLIC Libc {

public:
  Libc();
  int get_number() const;

private:

  int number;

};

}

