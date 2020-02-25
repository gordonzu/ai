// gordon zuehlke

#ifndef AICPP_WALL_H
#define AICPP_WALL_H

#include "environment/environment_obj.h"

class Wall : public EnvironmentObj {
public:
    Wall() { 
        hashval = hash_it();
    }

    virtual ~Wall() = default;

    virtual bool is_wall() const {
        return isWall;
    }

    bool operator==(const EnvironmentObj& other) const {
        if (!EnvironmentObj::operator==(other))
            return false;

        auto p = dynamic_cast<const Wall*>(&other);
        if (!p) return false;

        return hashval == p->hashval;
    }

    size_t hash_it() {
        hashval = reinterpret_cast<uint64_t>(this);
        return hashval;
    }

private:
    bool isWall{true};
    size_t hashval{0};
};
#endif 
