#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBA
    #define LIBA_PUBLIC __declspec(dllexport)
  #else
    #define LIBA_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBA
      #define LIBA_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define LIBA_PUBLIC
  #endif
#endif

namespace liba {

class LIBA_PUBLIC Liba {

public:
  Liba();
  int get_number() const;

private:

  int number;

};

}

