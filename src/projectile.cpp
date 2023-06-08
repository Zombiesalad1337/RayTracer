#include "projectile.h"


Projectile::Projectile(const rt::Point& position, const rt::Vec& velocity) : position(position), velocity(velocity) {};

Environment::Environment(const rt::Vec& gravity, const rt::Vec& wind) : gravity(gravity), wind(wind) {}; 
    

//TODO: Remove move constructors where const ref would suffice
Projectile tick(const Projectile& proj, const Environment& env, float seconds){
    rt::Point p = proj.position + (proj.velocity * seconds);
    rt::Vec v = proj.velocity + (env.gravity + env.wind) * seconds;
    return Projectile(p, v);
}
