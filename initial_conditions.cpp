#include "object.h"
#include <vector>
#include "initial_conditions.h"
#include "engine.h"

void solar_sytem_in_real_scale(std::vector<Object*>& objects){
    const float sunMass = 100.0f;
    const float GM_SUN = G * sunMass;

    const float RADIUS_SCALE = 40.0f;

    Object* sun = new Object("Sun", Color{253, 184, 19, 255}, 0.04655f * RADIUS_SCALE, sunMass, Vector3Zero(), Vector3Zero(), Vector3Zero());

    float mercuryDist = 3.9f, mercuryAngle = 0.0f * DEG2RAD;
    Object* mercury = new Object("Mercury", Color{168, 168, 168, 255}, 0.0001631f * RADIUS_SCALE, 1.66e-5f,
        {mercuryDist * cosf(mercuryAngle), 0.0f, mercuryDist * sinf(mercuryAngle)},
        Vector3Scale({-sinf(mercuryAngle), 0.0f, cosf(mercuryAngle)}, sqrtf(GM_SUN / mercuryDist)),
        Vector3Zero());

    float venusDist = 7.2f, venusAngle = 45.0f * DEG2RAD;
    Object* venus = new Object("Venus", Color{230, 200, 130, 255}, 0.0004045f * RADIUS_SCALE, 2.45e-4f,
        {venusDist * cosf(venusAngle), 0.0f, venusDist * sinf(venusAngle)},
        Vector3Scale({-sinf(venusAngle), 0.0f, cosf(venusAngle)}, sqrtf(GM_SUN / venusDist)),
        Vector3Zero());

    float earthDist = 10.0f, earthAngle = 90.0f * DEG2RAD;
    Object* earth = new Object("Earth", Color{70, 130, 180, 255}, 0.0004259f * RADIUS_SCALE, 3.00e-4f,
        {earthDist * cosf(earthAngle), 0.0f, earthDist * sinf(earthAngle)},
        Vector3Scale({-sinf(earthAngle), 0.0f, cosf(earthAngle)}, sqrtf(GM_SUN / earthDist)),
        Vector3Zero());

    float marsDist = 15.2f, marsAngle = 135.0f * DEG2RAD;
    Object* mars = new Object("Mars", Color{193, 68, 14, 255}, 0.0002266f * RADIUS_SCALE, 3.23e-5f,
        {marsDist * cosf(marsAngle), 0.0f, marsDist * sinf(marsAngle)},
        Vector3Scale({-sinf(marsAngle), 0.0f, cosf(marsAngle)}, sqrtf(GM_SUN / marsDist)),
        Vector3Zero());

    float jupiterDist = 52.0f, jupiterAngle = 180.0f * DEG2RAD;
    Object* jupiter = new Object("Jupiter", Color{216, 179, 130, 255}, 0.004673f * RADIUS_SCALE, 0.0955f,
        {jupiterDist * cosf(jupiterAngle), 0.0f, jupiterDist * sinf(jupiterAngle)},
        Vector3Scale({-sinf(jupiterAngle), 0.0f, cosf(jupiterAngle)}, sqrtf(GM_SUN / jupiterDist)),
        Vector3Zero());

    float saturnDist = 95.8f, saturnAngle = 225.0f * DEG2RAD;
    Object* saturn = new Object("Saturn", Color{235, 214, 162, 255}, 0.003893f * RADIUS_SCALE, 0.0286f,
        {saturnDist * cosf(saturnAngle), 0.0f, saturnDist * sinf(saturnAngle)},
        Vector3Scale({-sinf(saturnAngle), 0.0f, cosf(saturnAngle)}, sqrtf(GM_SUN / saturnDist)),
        Vector3Zero());

    float uranusDist = 192.0f, uranusAngle = 270.0f * DEG2RAD;
    Object* uranus = new Object("Uranus", Color{172, 229, 238, 255}, 0.001695f * RADIUS_SCALE, 4.37e-3f,
        {uranusDist * cosf(uranusAngle), 0.0f, uranusDist * sinf(uranusAngle)},
        Vector3Scale({-sinf(uranusAngle), 0.0f, cosf(uranusAngle)}, sqrtf(GM_SUN / uranusDist)),
        Vector3Zero());

    float neptuneDist = 300.5f, neptuneAngle = 315.0f * DEG2RAD;
    Object* neptune = new Object("Neptune", Color{62, 84, 191, 255}, 0.001646f * RADIUS_SCALE, 5.15e-3f,
        {neptuneDist * cosf(neptuneAngle), 0.0f, neptuneDist * sinf(neptuneAngle)},
        Vector3Scale({-sinf(neptuneAngle), 0.0f, cosf(neptuneAngle)}, sqrtf(GM_SUN / neptuneDist)),
        Vector3Zero());

    objects.push_back(sun);
    objects.push_back(mercury);
    objects.push_back(venus);
    objects.push_back(earth);
    objects.push_back(mars);
    objects.push_back(jupiter);
    objects.push_back(saturn);
    objects.push_back(uranus);
    objects.push_back(neptune);
}