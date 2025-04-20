#include "sia/sia_impl.hpp"

namespace sia {

std::shared_ptr<Sia> SiaImpl::AddBool(bool b) {
  content.push_back(b ? 1 : 0);
  return shared_from_this();
}

bool SiaImpl::ReadBool() {
  if (index >= content.size())
    return false;
  return content[index++] != 0;
}

} // namespace sia