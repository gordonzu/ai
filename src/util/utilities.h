// Gordon Zuehlke 2/22/20

#ifndef AICPP_UTILITIES_H
#define AICPP_UTILITIES_H

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include "util/attribute.h"
#include "environment/environment_obj.h"

using envObjs = std::vector<std::shared_ptr<EnvironmentObj>>;
using attributes = std::vector<Attribute>;
using attribute_map = std::map<Attribute, Attribute>;
using attribute_table = std::map<Attribute, attribute_map>; 

namespace ut {



}
#endif // AICPP_UTILITIES_H
