#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBB
    #define LIBB_PUBLIC __declspec(dllexport)
  #else
    #define LIBB_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBB
      #define LIBB_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define LIBB_PUBLIC
  #endif
#endif

namespace libb {

class LIBB_PUBLIC Libb {

public:
  Libb();
  int get_number() const;

private:

  int number;

};

}

