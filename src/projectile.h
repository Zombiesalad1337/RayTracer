#pragma once
#include "point.h"
#include "vec.h"

class Projectile{
public:
    rt::Point position;
    rt::Vec velocity;

    //p = Projectile(p.position, p.velocity, p.tick + 1)
    //std::move may cause problem here, so using const ref instead
    //no point of move and new projectile is created inside tick function
    //here p and v are created, p and v will be destroyed anyway after tick returns so just pass cosnt ref, const ref faster than move
    Projectile(const rt::Point& position, const rt::Vec& velocity);
};

class Environment{
public: 
    rt::Vec gravity;
    rt::Vec wind;
    
    //initialized only once, std::move will work
    //but why move when I can just call braced initialiazed vector and let it be destroy after constructor call is over
    Environment(const rt::Vec& gravity, const rt::Vec& wind);
};

Projectile tick(const Projectile& proj, const Environment& env, float seconds);
