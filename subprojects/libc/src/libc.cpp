#include "libc/libc.hpp"

namespace libc {

Libc::Libc() {
    number = 7;
}

int Libc::get_number() const {
  return number;
}

}
