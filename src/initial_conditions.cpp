#include "object.h"
#include <vector>
#include <cmath>
#include "initial_conditions.h"
#include "engine.h"

//this is almost all ai generated, because it's a lot of work to implement these data

void SagittariusA(std::vector<Object*>& objects){
    constexpr float SUN_MASS = 1000.0f;
    constexpr float KM_TO_UNITS = 5.0e-7f;
    constexpr float RADIUS_SCALE = 20.0f;
    Object* saggitarius_a = new Object("Sgr A*", Color{20, 20, 20, 255},
    696340.0f * KM_TO_UNITS * RADIUS_SCALE * 18, 4*powf(10,6),
    Vector3Zero(), Vector3Zero(), Vector3Zero());

    objects.push_back(saggitarius_a);
}

void CygnusX1(std::vector<Object*>& objects){
    constexpr float SUN_MASS = 1000.0f;
    constexpr float KM_TO_UNITS = 5.0e-7f;
    constexpr float RADIUS_SCALE = 20.0f;
    
    float cygnusMass = 21.0f * SUN_MASS;
    
    constexpr float VISIBILITY_MULTIPLIER = 5000.0f; 
    float cygnusRadius = 63.0f * KM_TO_UNITS * RADIUS_SCALE;

    Object* cygnus_x1 = new Object("Cygnus X-1", Color{120, 0, 255, 255}, 
        cygnusRadius, cygnusMass,
        Vector3Zero(), Vector3Zero(), Vector3Zero());

    objects.push_back(cygnus_x1);
}

void solar_sytem_in_real_scale(std::vector<Object*>& objects)
{
    constexpr float KM_TO_UNITS = 5.0e-7f;
    constexpr float AU_KM = 149597870.7f;
    constexpr float AU_TO_UNITS = AU_KM * KM_TO_UNITS;

    constexpr float DISTANCE_SCALE = 1.0f;
    constexpr float RADIUS_SCALE = 20.0f;
    constexpr float SUN_MASS = 1000.0f;

    const float sunMass      = SUN_MASS;

    const float mercuryMass  = SUN_MASS * 1.66e-7f;
    const float venusMass    = SUN_MASS * 2.45e-6f;
    const float earthMass    = SUN_MASS * 3.00e-6f;
    const float moonMass     = SUN_MASS * 3.6913e-8f;

    const float marsMass     = SUN_MASS * 3.23e-7f;
    const float phobosMass   = SUN_MASS * 5.359e-15f;
    const float deimosMass   = SUN_MASS * 7.4218e-16f;

    const float jupiterMass  = SUN_MASS * 9.55e-4f;
    const float ioMass       = SUN_MASS * 4.4907e-8f;
    const float europaMass   = SUN_MASS * 2.4132e-8f;
    const float ganymedeMass = SUN_MASS * 7.4505e-8f;
    const float callistoMass = SUN_MASS * 5.4092e-8f;

    const float saturnMass   = SUN_MASS * 2.86e-4f;
    const float titanMass    = SUN_MASS * 6.7632e-8f;
    const float rheaMass     = SUN_MASS * 1.1596e-9f;
    const float iapetusMass  = SUN_MASS * 9.0779e-10f;

    const float uranusMass   = SUN_MASS * 4.37e-5f;
    const float titaniaMass  = SUN_MASS * 1.7093e-9f;
    const float oberonMass   = SUN_MASS * 1.5465e-9f;

    const float neptuneMass  = SUN_MASS * 5.15e-5f;
    const float tritonMass   = SUN_MASS * 1.0759e-8f;

    const float ceresMass    = SUN_MASS * 4.7182e-10f;
    const float vestaMass    = SUN_MASS * 1.3026e-10f;
    const float pallasMass   = SUN_MASS * 1.0257e-10f;
    const float hygieaMass   = SUN_MASS * 4.1831e-11f;

    Object* sun = new Object(
        "Sun",
        Color{255, 255, 255, 255},
        696340.0f * KM_TO_UNITS * RADIUS_SCALE,
        sunMass,
        Vector3Zero(),
        Vector3Zero(),
        Vector3Zero()
    );

    float mercuryDist = 0.39f * AU_TO_UNITS * DISTANCE_SCALE;
    float mercuryAngle = 0.0f * DEG2RAD;

    Object* mercury = new Object(
        "Mercury",
        Color{168, 168, 168, 255},
        2439.7f * KM_TO_UNITS * RADIUS_SCALE,
        mercuryMass,
        {
            mercuryDist * cosf(mercuryAngle),
            0.0f,
            mercuryDist * sinf(mercuryAngle)
        },
        Vector3Scale(
            {-sinf(mercuryAngle), 0.0f, cosf(mercuryAngle)},
            sqrtf(G * (sunMass + mercuryMass) / mercuryDist)
        ),
        Vector3Zero()
    );

    float venusDist = 0.72f * AU_TO_UNITS * DISTANCE_SCALE;
    float venusAngle = 45.0f * DEG2RAD;

    Object* venus = new Object(
        "Venus",
        Color{230, 200, 130, 255},
        6051.8f * KM_TO_UNITS * RADIUS_SCALE,
        venusMass,
        {
            venusDist * cosf(venusAngle),
            0.0f,
            venusDist * sinf(venusAngle)
        },
        Vector3Scale(
            {-sinf(venusAngle), 0.0f, cosf(venusAngle)},
            sqrtf(G * (sunMass + venusMass) / venusDist)
        ),
        Vector3Zero()
    );

    float earthDist = 1.0f * AU_TO_UNITS * DISTANCE_SCALE;
    float earthAngle = 90.0f * DEG2RAD;

    Object* earth = new Object(
        "Earth",
        Color{70, 130, 180, 255},
        6371.0f * KM_TO_UNITS * RADIUS_SCALE,
        earthMass,
        {
            earthDist * cosf(earthAngle),
            0.0f,
            earthDist * sinf(earthAngle)
        },
        Vector3Scale(
            {-sinf(earthAngle), 0.0f, cosf(earthAngle)},
            sqrtf(G * (sunMass + earthMass) / earthDist)
        ),
        Vector3Zero()
    );

    float moonDist = 384400.0f * KM_TO_UNITS;
    float moonAngle = 0.0f * DEG2RAD;

    Object* moon = new Object(
        "Moon",
        Color{200, 200, 200, 255},
        1737.4f * KM_TO_UNITS * RADIUS_SCALE,
        moonMass,
        Vector3Add(
            earth->GetPosition(),
            {
                moonDist * cosf(moonAngle),
                0.0f,
                moonDist * sinf(moonAngle)
            }
        ),
        Vector3Add(
            earth->GetVelocity(),
            Vector3Scale(
                {-sinf(moonAngle), 0.0f, cosf(moonAngle)},
                sqrtf(G * (earthMass + moonMass) / moonDist)
            )
        ),
        Vector3Zero()
    );

    float marsDist = 1.52f * AU_TO_UNITS * DISTANCE_SCALE;
    float marsAngle = 135.0f * DEG2RAD;

    Object* mars = new Object(
        "Mars",
        Color{193, 68, 14, 255},
        3389.5f * KM_TO_UNITS * RADIUS_SCALE,
        marsMass,
        {
            marsDist * cosf(marsAngle),
            0.0f,
            marsDist * sinf(marsAngle)
        },
        Vector3Scale(
            {-sinf(marsAngle), 0.0f, cosf(marsAngle)},
            sqrtf(G * (sunMass + marsMass) / marsDist)
        ),
        Vector3Zero()
    );

    constexpr float MARS_MOON_SCALE = 10.0f;

    float phobosDist = 9376.0f * KM_TO_UNITS * MARS_MOON_SCALE;
    float phobosAngle = 0.0f * DEG2RAD;

    Object* phobos = new Object(
        "Phobos",
        Color{130, 120, 110, 255},
        11.267f * KM_TO_UNITS * RADIUS_SCALE,
        phobosMass,
        Vector3Add(
            mars->GetPosition(),
            {
                phobosDist * cosf(phobosAngle),
                0.0f,
                phobosDist * sinf(phobosAngle)
            }
        ),
        Vector3Add(
            mars->GetVelocity(),
            Vector3Scale(
                {-sinf(phobosAngle), 0.0f, cosf(phobosAngle)},
                sqrtf(G * (marsMass + phobosMass) / phobosDist)
            )
        ),
        Vector3Zero()
    );

    float deimosDist = 23463.2f * KM_TO_UNITS * MARS_MOON_SCALE;
    float deimosAngle = 180.0f * DEG2RAD;

    Object* deimos = new Object(
        "Deimos",
        Color{120, 110, 100, 255},
        6.2f * KM_TO_UNITS * RADIUS_SCALE,
        deimosMass,
        Vector3Add(
            mars->GetPosition(),
            {
                deimosDist * cosf(deimosAngle),
                0.0f,
                deimosDist * sinf(deimosAngle)
            }
        ),
        Vector3Add(
            mars->GetVelocity(),
            Vector3Scale(
                {-sinf(deimosAngle), 0.0f, cosf(deimosAngle)},
                sqrtf(G * (marsMass + deimosMass) / deimosDist)
            )
        ),
        Vector3Zero()
    );

    float jupiterDist = 5.20f * AU_TO_UNITS * DISTANCE_SCALE;
    float jupiterAngle = 180.0f * DEG2RAD;

    Object* jupiter = new Object(
        "Jupiter",
        Color{216, 179, 130, 255},
        69911.0f * KM_TO_UNITS * RADIUS_SCALE,
        jupiterMass,
        {
            jupiterDist * cosf(jupiterAngle),
            0.0f,
            jupiterDist * sinf(jupiterAngle)
        },
        Vector3Scale(
            {-sinf(jupiterAngle), 0.0f, cosf(jupiterAngle)},
            sqrtf(G * (sunMass + jupiterMass) / jupiterDist)
        ),
        Vector3Zero()
    );

    constexpr float JUPITER_MOON_SCALE = 4.0f;

    float ioDist = 421700.0f * KM_TO_UNITS * JUPITER_MOON_SCALE;
    float ioAngle = 0.0f * DEG2RAD;

    Object* io = new Object(
        "Io",
        Color{230, 210, 120, 255},
        1821.6f * KM_TO_UNITS * RADIUS_SCALE,
        ioMass,
        Vector3Add(
            jupiter->GetPosition(),
            {
                ioDist * cosf(ioAngle),
                0.0f,
                ioDist * sinf(ioAngle)
            }
        ),
        Vector3Add(
            jupiter->GetVelocity(),
            Vector3Scale(
                {-sinf(ioAngle), 0.0f, cosf(ioAngle)},
                sqrtf(G * (jupiterMass + ioMass) / ioDist)
            )
        ),
        Vector3Zero()
    );

    float europaDist = 671034.0f * KM_TO_UNITS * JUPITER_MOON_SCALE;
    float europaAngle = 90.0f * DEG2RAD;

    Object* europa = new Object(
        "Europa",
        Color{210, 190, 160, 255},
        1560.8f * KM_TO_UNITS * RADIUS_SCALE,
        europaMass,
        Vector3Add(
            jupiter->GetPosition(),
            {
                europaDist * cosf(europaAngle),
                0.0f,
                europaDist * sinf(europaAngle)
            }
        ),
        Vector3Add(
            jupiter->GetVelocity(),
            Vector3Scale(
                {-sinf(europaAngle), 0.0f, cosf(europaAngle)},
                sqrtf(G * (jupiterMass + europaMass) / europaDist)
            )
        ),
        Vector3Zero()
    );

    float ganymedeDist = 1070412.0f * KM_TO_UNITS * JUPITER_MOON_SCALE;
    float ganymedeAngle = 180.0f * DEG2RAD;

    Object* ganymede = new Object(
        "Ganymede",
        Color{150, 140, 130, 255},
        2634.1f * KM_TO_UNITS * RADIUS_SCALE,
        ganymedeMass,
        Vector3Add(
            jupiter->GetPosition(),
            {
                ganymedeDist * cosf(ganymedeAngle),
                0.0f,
                ganymedeDist * sinf(ganymedeAngle)
            }
        ),
        Vector3Add(
            jupiter->GetVelocity(),
            Vector3Scale(
                {-sinf(ganymedeAngle), 0.0f, cosf(ganymedeAngle)},
                sqrtf(G * (jupiterMass + ganymedeMass) / ganymedeDist)
            )
        ),
        Vector3Zero()
    );

    float callistoDist = 1882709.0f * KM_TO_UNITS * JUPITER_MOON_SCALE;
    float callistoAngle = 270.0f * DEG2RAD;

    Object* callisto = new Object(
        "Callisto",
        Color{110, 100, 90, 255},
        2410.3f * KM_TO_UNITS * RADIUS_SCALE,
        callistoMass,
        Vector3Add(
            jupiter->GetPosition(),
            {
                callistoDist * cosf(callistoAngle),
                0.0f,
                callistoDist * sinf(callistoAngle)
            }
        ),
        Vector3Add(
            jupiter->GetVelocity(),
            Vector3Scale(
                {-sinf(callistoAngle), 0.0f, cosf(callistoAngle)},
                sqrtf(G * (jupiterMass + callistoMass) / callistoDist)
            )
        ),
        Vector3Zero()
    );

    float saturnDist = 9.58f * AU_TO_UNITS * DISTANCE_SCALE;
    float saturnAngle = 225.0f * DEG2RAD;

    Object* saturn = new Object(
        "Saturn",
        Color{235, 214, 162, 255},
        58232.0f * KM_TO_UNITS * RADIUS_SCALE,
        saturnMass,
        {
            saturnDist * cosf(saturnAngle),
            0.0f,
            saturnDist * sinf(saturnAngle)
        },
        Vector3Scale(
            {-sinf(saturnAngle), 0.0f, cosf(saturnAngle)},
            sqrtf(G * (sunMass + saturnMass) / saturnDist)
        ),
        Vector3Zero()
    );

    constexpr float SATURN_MOON_SCALE = 3.0f;

    float titanDist = 1221870.0f * KM_TO_UNITS * SATURN_MOON_SCALE;
    float titanAngle = 0.0f * DEG2RAD;

    Object* titan = new Object(
        "Titan",
        Color{200, 150, 80, 255},
        2574.7f * KM_TO_UNITS * RADIUS_SCALE,
        titanMass,
        Vector3Add(
            saturn->GetPosition(),
            {
                titanDist * cosf(titanAngle),
                0.0f,
                titanDist * sinf(titanAngle)
            }
        ),
        Vector3Add(
            saturn->GetVelocity(),
            Vector3Scale(
                {-sinf(titanAngle), 0.0f, cosf(titanAngle)},
                sqrtf(G * (saturnMass + titanMass) / titanDist)
            )
        ),
        Vector3Zero()
    );

    float rheaDist = 527108.0f * KM_TO_UNITS * SATURN_MOON_SCALE;
    float rheaAngle = 120.0f * DEG2RAD;

    Object* rhea = new Object(
        "Rhea",
        Color{190, 190, 190, 255},
        763.8f * KM_TO_UNITS * RADIUS_SCALE,
        rheaMass,
        Vector3Add(
            saturn->GetPosition(),
            {
                rheaDist * cosf(rheaAngle),
                0.0f,
                rheaDist * sinf(rheaAngle)
            }
        ),
        Vector3Add(
            saturn->GetVelocity(),
            Vector3Scale(
                {-sinf(rheaAngle), 0.0f, cosf(rheaAngle)},
                sqrtf(G * (saturnMass + rheaMass) / rheaDist)
            )
        ),
        Vector3Zero()
    );

    float iapetusDist = 3560820.0f * KM_TO_UNITS * SATURN_MOON_SCALE;
    float iapetusAngle = 240.0f * DEG2RAD;

    Object* iapetus = new Object(
        "Iapetus",
        Color{150, 140, 120, 255},
        734.5f * KM_TO_UNITS * RADIUS_SCALE,
        iapetusMass,
        Vector3Add(
            saturn->GetPosition(),
            {
                iapetusDist * cosf(iapetusAngle),
                0.0f,
                iapetusDist * sinf(iapetusAngle)
            }
        ),
        Vector3Add(
            saturn->GetVelocity(),
            Vector3Scale(
                {-sinf(iapetusAngle), 0.0f, cosf(iapetusAngle)},
                sqrtf(G * (saturnMass + iapetusMass) / iapetusDist)
            )
        ),
        Vector3Zero()
    );

    float uranusDist = 19.2f * AU_TO_UNITS * DISTANCE_SCALE;
    float uranusAngle = 270.0f * DEG2RAD;

    Object* uranus = new Object(
        "Uranus",
        Color{172, 229, 238, 255},
        25362.0f * KM_TO_UNITS * RADIUS_SCALE,
        uranusMass,
        {
            uranusDist * cosf(uranusAngle),
            0.0f,
            uranusDist * sinf(uranusAngle)
        },
        Vector3Scale(
            {-sinf(uranusAngle), 0.0f, cosf(uranusAngle)},
            sqrtf(G * (sunMass + uranusMass) / uranusDist)
        ),
        Vector3Zero()
    );

    constexpr float URANUS_MOON_SCALE = 2.0f;

    float titaniaDist = 436300.0f * KM_TO_UNITS * URANUS_MOON_SCALE;
    float titaniaAngle = 0.0f * DEG2RAD;

    Object* titania = new Object(
        "Titania",
        Color{170, 170, 180, 255},
        788.4f * KM_TO_UNITS * RADIUS_SCALE,
        titaniaMass,
        Vector3Add(
            uranus->GetPosition(),
            {
                titaniaDist * cosf(titaniaAngle),
                0.0f,
                titaniaDist * sinf(titaniaAngle)
            }
        ),
        Vector3Add(
            uranus->GetVelocity(),
            Vector3Scale(
                {-sinf(titaniaAngle), 0.0f, cosf(titaniaAngle)},
                sqrtf(G * (uranusMass + titaniaMass) / titaniaDist)
            )
        ),
        Vector3Zero()
    );

    float oberonDist = 583500.0f * KM_TO_UNITS * URANUS_MOON_SCALE;
    float oberonAngle = 180.0f * DEG2RAD;

    Object* oberon = new Object(
        "Oberon",
        Color{160, 155, 150, 255},
        761.4f * KM_TO_UNITS * RADIUS_SCALE,
        oberonMass,
        Vector3Add(
            uranus->GetPosition(),
            {
                oberonDist * cosf(oberonAngle),
                0.0f,
                oberonDist * sinf(oberonAngle)
            }
        ),
        Vector3Add(
            uranus->GetVelocity(),
            Vector3Scale(
                {-sinf(oberonAngle), 0.0f, cosf(oberonAngle)},
                sqrtf(G * (uranusMass + oberonMass) / oberonDist)
            )
        ),
        Vector3Zero()
    );

    float neptuneDist = 30.05f * AU_TO_UNITS * DISTANCE_SCALE;
    float neptuneAngle = 315.0f * DEG2RAD;

    Object* neptune = new Object(
        "Neptune",
        Color{62, 84, 191, 255},
        24622.0f * KM_TO_UNITS * RADIUS_SCALE,
        neptuneMass,
        {
            neptuneDist * cosf(neptuneAngle),
            0.0f,
            neptuneDist * sinf(neptuneAngle)
        },
        Vector3Scale(
            {-sinf(neptuneAngle), 0.0f, cosf(neptuneAngle)},
            sqrtf(G * (sunMass + neptuneMass) / neptuneDist)
        ),
        Vector3Zero()
    );

    constexpr float NEPTUNE_MOON_SCALE = 2.0f;

    float tritonDist = 354759.0f * KM_TO_UNITS * NEPTUNE_MOON_SCALE;
    float tritonAngle = 0.0f * DEG2RAD;

    Object* triton = new Object(
        "Triton",
        Color{225, 215, 220, 255},
        1353.4f * KM_TO_UNITS * RADIUS_SCALE,
        tritonMass,
        Vector3Add(
            neptune->GetPosition(),
            {
                tritonDist * cosf(tritonAngle),
                0.0f,
                tritonDist * sinf(tritonAngle)
            }
        ),
        Vector3Add(
            neptune->GetVelocity(),
            Vector3Scale(
                {sinf(tritonAngle), 0.0f, -cosf(tritonAngle)},
                sqrtf(G * (neptuneMass + tritonMass) / tritonDist)
            )
        ),
        Vector3Zero()
    );

    float ceresDist = 2.7675f * AU_TO_UNITS;
    float ceresAngle = 20.0f * DEG2RAD;

    Object* ceres = new Object(
        "Ceres",
        Color{160, 150, 140, 255},
        469.7f * KM_TO_UNITS * RADIUS_SCALE,
        ceresMass,
        {
            ceresDist * cosf(ceresAngle),
            0.0f,
            ceresDist * sinf(ceresAngle)
        },
        Vector3Scale(
            {-sinf(ceresAngle), 0.0f, cosf(ceresAngle)},
            sqrtf(G * (sunMass + ceresMass) / ceresDist)
        ),
        Vector3Zero()
    );

    float vestaDist = 2.362f * AU_TO_UNITS;
    float vestaAngle = 110.0f * DEG2RAD;

    Object* vesta = new Object(
        "Vesta",
        Color{180, 175, 165, 255},
        262.7f * KM_TO_UNITS * RADIUS_SCALE,
        vestaMass,
        {
            vestaDist * cosf(vestaAngle),
            0.0f,
            vestaDist * sinf(vestaAngle)
        },
        Vector3Scale(
            {-sinf(vestaAngle), 0.0f, cosf(vestaAngle)},
            sqrtf(G * (sunMass + vestaMass) / vestaDist)
        ),
        Vector3Zero()
    );

    float pallasDist = 2.772f * AU_TO_UNITS;
    float pallasAngle = 200.0f * DEG2RAD;

    Object* pallas = new Object(
        "Pallas",
        Color{130, 125, 120, 255},
        256.0f * KM_TO_UNITS * RADIUS_SCALE,
        pallasMass,
        {
            pallasDist * cosf(pallasAngle),
            0.0f,
            pallasDist * sinf(pallasAngle)
        },
        Vector3Scale(
            {-sinf(pallasAngle), 0.0f, cosf(pallasAngle)},
            sqrtf(G * (sunMass + pallasMass) / pallasDist)
        ),
        Vector3Zero()
    );

    float hygieaDist = 3.1415f * AU_TO_UNITS;
    float hygieaAngle = 290.0f * DEG2RAD;

    Object* hygiea = new Object(
        "Hygiea",
        Color{110, 105, 100, 255},
        217.0f * KM_TO_UNITS * RADIUS_SCALE,
        hygieaMass,
        {
            hygieaDist * cosf(hygieaAngle),
            0.0f,
            hygieaDist * sinf(hygieaAngle)
        },
        Vector3Scale(
            {-sinf(hygieaAngle), 0.0f, cosf(hygieaAngle)},
            sqrtf(G * (sunMass + hygieaMass) / hygieaDist)
        ),
        Vector3Zero()
    );

    objects.push_back(sun);
    objects.push_back(mercury);
    objects.push_back(venus);
    objects.push_back(earth);
    objects.push_back(moon);
    objects.push_back(mars);
    objects.push_back(phobos);
    objects.push_back(deimos);
    objects.push_back(jupiter);
    objects.push_back(io);
    objects.push_back(europa);
    objects.push_back(ganymede);
    objects.push_back(callisto);
    objects.push_back(saturn);
    objects.push_back(titan);
    objects.push_back(rhea);
    objects.push_back(iapetus);
    objects.push_back(uranus);
    objects.push_back(titania);
    objects.push_back(oberon);
    objects.push_back(neptune);
    objects.push_back(triton);
    objects.push_back(ceres);
    objects.push_back(vesta);
    objects.push_back(pallas);
    objects.push_back(hygiea);
}

// ---------------------------------------------------------------------------
// Uklad Sloneczny w skali "do ogladania" (celowo nierealnej):
//  - odleglosci planet od Slonca sciesnione: planety wewnetrzne w prawie
//    realnych proporcjach, zewnetrzne mocno przysuniete (Neptun 6x dalej od
//    Ziemi zamiast 30x), zeby caly uklad miescil sie w kadrze,
//  - promienie cial mocno powiekszone, zeby kazde bylo widoczne jako kulka,
//  - ksiezyce kraza tuz przy planetach (do ~1/4 promienia Hilla - dalej
//    plywy Slonca widocznie deformuja ich orbity),
//  - masy Ziemi i Marsa zawyzone (realne stosunki w komentarzach), inaczej
//    ich sfery Hilla bylyby za male na widoczne ksiezyce; zbyt duze masy
//    z kolei deformuja orbity sasiednich planet - stad te konkretne wartosci.
// Tempo: rok ziemski trwa EARTH_YEAR_SECONDS, reszta wynika z III prawa
// Keplera (Merkury ~7 s, Jowisz ~100 s, Neptun ~6 min, Ksiezyc ~2 s).
// ---------------------------------------------------------------------------

// Tworzy cialo na orbicie kolowej wokol `parent` (plaszczyzna XZ, faza `angleDeg`),
// dodaje je do `objects` i zwraca wskaznik, zeby mozna bylo doczepic ksiezyce.
static Object* AddOrbiter(std::vector<Object*>& objects, const std::string& name,
                          Color color, float radius, float mass,
                          const Object* parent, float distance, float angleDeg,
                          bool retrograde = false)
{
    float angle = angleDeg * DEG2RAD;
    Vector3 offset  = { distance * cosf(angle), 0.0f, distance * sinf(angle) };
    Vector3 tangent = { -sinf(angle), 0.0f, cosf(angle) };
    if (retrograde) tangent = Vector3Negate(tangent);

    float speed = sqrtf(G * (parent->GetMass() + mass) / distance);

    Object* body = new Object(name, color, radius, mass,
        Vector3Add(parent->GetPosition(), offset),
        Vector3Add(parent->GetVelocity(), Vector3Scale(tangent, speed)),
        Vector3Zero());
    objects.push_back(body);
    return body;
}

void solar_system(std::vector<Object*>& objects)
{
    constexpr float EARTH_DIST         = 88.0f;
    constexpr float EARTH_YEAR_SECONDS = 24.0f;
    // III prawo Keplera: M = 4 pi^2 a^3 / (G T^2)  ->  ok. 46 700
    const float SUN_MASS = 4.0f * PI * PI * EARTH_DIST * EARTH_DIST * EARTH_DIST
                         / (G * EARTH_YEAR_SECONDS * EARTH_YEAR_SECONDS);

    const size_t first = objects.size();

    Object* sun = new Object("Sun", Color{255, 225, 120, 255}, 6.0f, SUN_MASS,
                             Vector3Zero(), Vector3Zero(), Vector3Zero());
    objects.push_back(sun);

    // Planety:                                                     promien  masa [Slonca] (realnie)     odleglosc  faza
    AddOrbiter(objects,                  "Mercury", Color{168, 168, 168, 255}, 0.32f, SUN_MASS * 1.7e-7f,             sun,  40.0f,  20.0f);
    AddOrbiter(objects,                  "Venus",   Color{230, 200, 130, 255}, 0.48f, SUN_MASS * 2.5e-6f,             sun,  62.0f, 130.0f);
    Object* earth   = AddOrbiter(objects, "Earth",   Color{ 70, 130, 180, 255}, 0.50f, SUN_MASS * 4.0e-4f, /*3.0e-6*/ sun,  88.0f, 250.0f);
    Object* mars    = AddOrbiter(objects, "Mars",    Color{193,  68,  14, 255}, 0.42f, SUN_MASS * 3.0e-4f, /*3.2e-7*/ sun, 122.0f,  70.0f);
    Object* jupiter = AddOrbiter(objects, "Jupiter", Color{216, 179, 130, 255}, 1.60f, SUN_MASS * 8.0e-4f, /*9.5e-4*/ sun, 230.0f, 310.0f);
    Object* saturn  = AddOrbiter(objects, "Saturn",  Color{235, 214, 162, 255}, 1.40f, SUN_MASS * 5.0e-4f, /*2.9e-4*/ sun, 320.0f, 150.0f);
    Object* uranus  = AddOrbiter(objects, "Uranus",  Color{172, 229, 238, 255}, 0.95f, SUN_MASS * 1.5e-4f, /*4.4e-5*/ sun, 430.0f,  40.0f);
    Object* neptune = AddOrbiter(objects, "Neptune", Color{ 62,  84, 191, 255}, 0.95f, SUN_MASS * 1.5e-4f, /*5.2e-5*/ sun, 540.0f, 220.0f);

    // Pas planetoid (miedzy Marsem a Jowiszem)
    AddOrbiter(objects, "Vesta",  Color{180, 175, 165, 255}, 0.12f, SUN_MASS * 1.3e-10f, sun, 152.0f, 300.0f);
    AddOrbiter(objects, "Ceres",  Color{160, 150, 140, 255}, 0.16f, SUN_MASS * 4.7e-10f, sun, 160.0f, 180.0f);
    AddOrbiter(objects, "Pallas", Color{130, 125, 120, 255}, 0.12f, SUN_MASS * 1.0e-10f, sun, 166.0f,  15.0f);
    AddOrbiter(objects, "Hygiea", Color{110, 105, 100, 255}, 0.11f, SUN_MASS * 4.2e-11f, sun, 175.0f, 100.0f);

    // Ksiezyce (masy realne wzgledem Slonca - dynamicznie bez znaczenia)
    AddOrbiter(objects, "Moon",     Color{200, 200, 200, 255}, 0.13f, SUN_MASS * 3.7e-8f, earth,   1.2f,   0.0f);

    AddOrbiter(objects, "Phobos",   Color{130, 120, 110, 255}, 0.07f, SUN_MASS * 1.0e-9f, mars,    1.0f,   0.0f);
    AddOrbiter(objects, "Deimos",   Color{120, 110, 100, 255}, 0.06f, SUN_MASS * 1.0e-9f, mars,    1.5f, 180.0f);

    AddOrbiter(objects, "Io",       Color{230, 210, 120, 255}, 0.20f, SUN_MASS * 4.5e-8f, jupiter, 2.3f,   0.0f);
    AddOrbiter(objects, "Europa",   Color{210, 190, 160, 255}, 0.17f, SUN_MASS * 2.4e-8f, jupiter, 2.8f,  90.0f);
    AddOrbiter(objects, "Ganymede", Color{150, 140, 130, 255}, 0.25f, SUN_MASS * 7.5e-8f, jupiter, 3.3f, 180.0f);
    AddOrbiter(objects, "Callisto", Color{110, 100,  90, 255}, 0.23f, SUN_MASS * 5.4e-8f, jupiter, 3.9f, 270.0f);

    AddOrbiter(objects, "Rhea",     Color{190, 190, 190, 255}, 0.13f, SUN_MASS * 1.2e-9f, saturn,  2.2f, 120.0f);
    AddOrbiter(objects, "Titan",    Color{200, 150,  80, 255}, 0.25f, SUN_MASS * 6.8e-8f, saturn,  3.0f,   0.0f);
    AddOrbiter(objects, "Iapetus",  Color{150, 140, 120, 255}, 0.12f, SUN_MASS * 9.0e-10f, saturn, 4.2f, 240.0f);

    AddOrbiter(objects, "Titania",  Color{170, 170, 180, 255}, 0.13f, SUN_MASS * 1.7e-9f, uranus,  1.7f,   0.0f);
    AddOrbiter(objects, "Oberon",   Color{160, 155, 150, 255}, 0.13f, SUN_MASS * 1.5e-9f, uranus,  2.3f, 180.0f);

    AddOrbiter(objects, "Triton",   Color{225, 215, 220, 255}, 0.18f, SUN_MASS * 1.1e-8f, neptune, 2.1f,   0.0f, /*retrograde*/ true);

    // Wyzeruj ped calkowity ukladu: Slonce startuje w spoczynku, a planety maja
    // niezerowy ped, wiec bez tego caly uklad powoli odplywalby od srodka sceny.
    Vector3 momentum  = Vector3Zero();
    float   totalMass = 0.0f;
    for (size_t i = first; i < objects.size(); i++){
        momentum   = Vector3Add(momentum, Vector3Scale(objects[i]->GetVelocity(), objects[i]->GetMass()));
        totalMass += objects[i]->GetMass();
    }
    Vector3 driftVelocity = Vector3Scale(momentum, 1.0f / totalMass);
    for (size_t i = first; i < objects.size(); i++){
        objects[i]->AddToVelocity(Vector3Negate(driftVelocity));
    }
}

void alpha_centauri_system(std::vector<Object*>& objects)
{
    constexpr float SOLAR_MASS_UNIT = 1000.0f;

    const float massA       = 1.0788f * SOLAR_MASS_UNIT;
    const float massB       = 0.9092f * SOLAR_MASS_UNIT;
    const float massProxima = 0.1221f * SOLAR_MASS_UNIT;

    constexpr float ALPHA_AU_TO_UNITS = 0.30f;
    constexpr float ALPHA_RADIUS_SCALE = 100.0f;

    const float radiusA =
        0.005693f * ALPHA_AU_TO_UNITS * ALPHA_RADIUS_SCALE;

    const float radiusB =
        0.004017f * ALPHA_AU_TO_UNITS * ALPHA_RADIUS_SCALE;

    const float radiusProxima =
        0.0007174f * ALPHA_AU_TO_UNITS * ALPHA_RADIUS_SCALE;

    const float massAB = massA + massB;

    const float aAB = 23.5f * ALPHA_AU_TO_UNITS;
    const float eAB = 0.5179f;

    const float rPeriAB = aAB * (1.0f - eAB);

    const float vRelAB =
        sqrtf(
            G * massAB *
            (1.0f + eAB) /
            rPeriAB
        );

    const float fracA = massB / massAB;
    const float fracB = massA / massAB;

    const float aProxima =
        8700.0f * ALPHA_AU_TO_UNITS;

    const float eProxima = 0.50f;

    const float rPeriProxima =
        aProxima * (1.0f - eProxima);

    const float totalMass =
        massAB + massProxima;

    const float vRelProxima =
        sqrtf(
            G * totalMass *
            (1.0f + eProxima) /
            rPeriProxima
        );

    const float fracABOuter =
        massProxima / totalMass;

    const float fracProximaOuter =
        massAB / totalMass;

    Vector3 posABcenter = {
        -fracABOuter * rPeriProxima,
        0.0f,
        0.0f
    };

    Vector3 velABcenter = {
        0.0f,
        0.0f,
        -fracABOuter * vRelProxima
    };

    Vector3 posProxima = {
        fracProximaOuter * rPeriProxima,
        0.0f,
        0.0f
    };

    Vector3 velProxima = {
        0.0f,
        0.0f,
        fracProximaOuter * vRelProxima
    };

    Vector3 posA = Vector3Add(
        posABcenter,
        {-fracA * rPeriAB, 0.0f, 0.0f}
    );

    Vector3 velA = Vector3Add(
        velABcenter,
        {0.0f, 0.0f, -fracA * vRelAB}
    );

    Object* alphaA = new Object(
        "Alpha Centauri A",
        Color{255, 241, 199, 255},
        radiusA,
        massA,
        posA,
        velA,
        Vector3Zero()
    );

    Vector3 posB = Vector3Add(
        posABcenter,
        {fracB * rPeriAB, 0.0f, 0.0f}
    );

    Vector3 velB = Vector3Add(
        velABcenter,
        {0.0f, 0.0f, fracB * vRelAB}
    );

    Object* alphaB = new Object(
        "Alpha Centauri B",
        Color{255, 199, 120, 255},
        radiusB,
        massB,
        posB,
        velB,
        Vector3Zero()
    );

    Object* proxima = new Object(
        "Proxima Centauri",
        Color{255, 96, 74, 255},
        radiusProxima,
        massProxima,
        posProxima,
        velProxima,
        Vector3Zero()
    );

    objects.push_back(alphaA);
    objects.push_back(alphaB);
    objects.push_back(proxima);
}