#include "object.h"
#include <vector>
#include "initial_conditions.h"
#include "engine.h"

void solar_sytem_in_real_scale(std::vector<Object*>& objects){
    const float sunMass = 100.0f;
    const float GM_SUN = G * sunMass;

    const float RADIUS_SCALE = 40.0f;
    const float KM_TO_UNITS = 1.0f / 14960000.0f; // 1 jednostka odleglosci = 1 AU / 10 = 14 960 000 km
    // Mnoznik rozsuwajacy planety/planetoidy dalej od Slonca (dystanse ponizej
    // sa juz wyrazone w "jednostkach AU/10" - ten wspolczynnik skaluje je dalej).
    // Dzieki niemu Merkury przestaje niemal stykac sie z napompowanym Sloncem,
    // a dluzsze okresy orbitalne (Kepler: T ~ r^1.5 przy stalym GM) daja calce
    // wiecej krokow na orbite = lepsza stabilnosc numeryczna dla kazdej planety.
    const float DISTANCE_SCALE = 2.5f;

    Object* sun = new Object("Sun", Color{255, 255, 255, 255}, 0.04655f * RADIUS_SCALE, sunMass, Vector3Zero(), Vector3Zero(), Vector3Zero());

    float mercuryDist = 3.9f * DISTANCE_SCALE, mercuryAngle = 0.0f * DEG2RAD;
    Object* mercury = new Object("Mercury", Color{168, 168, 168, 255}, 0.0001631f * RADIUS_SCALE, 1.66e-5f,
        {mercuryDist * cosf(mercuryAngle), 0.0f, mercuryDist * sinf(mercuryAngle)},
        Vector3Scale({-sinf(mercuryAngle), 0.0f, cosf(mercuryAngle)}, sqrtf(GM_SUN / mercuryDist)),
        Vector3Zero());

    float venusDist = 7.2f * DISTANCE_SCALE, venusAngle = 45.0f * DEG2RAD;
    Object* venus = new Object("Venus", Color{230, 200, 130, 255}, 0.0004045f * RADIUS_SCALE, 2.45e-4f,
        {venusDist * cosf(venusAngle), 0.0f, venusDist * sinf(venusAngle)},
        Vector3Scale({-sinf(venusAngle), 0.0f, cosf(venusAngle)}, sqrtf(GM_SUN / venusDist)),
        Vector3Zero());

    float earthDist = 10.0f * DISTANCE_SCALE, earthAngle = 90.0f * DEG2RAD;
    Object* earth = new Object("Earth", Color{70, 130, 180, 255}, 0.0004259f * RADIUS_SCALE, 3.00e-4f,
        {earthDist * cosf(earthAngle), 0.0f, earthDist * sinf(earthAngle)},
        Vector3Scale({-sinf(earthAngle), 0.0f, cosf(earthAngle)}, sqrtf(GM_SUN / earthDist)),
        Vector3Zero());

    // Odleglosc Ksiezyca od Ziemi w realnej skali juz wystaje poza napompowany
    // (RADIUS_SCALE) promien Ziemi, wiec nie potrzeba dodatkowego mnoznika.
    float moonDist = 0.025695f, moonAngle = 0.0f * DEG2RAD;
    Object* moon = new Object("Moon", Color{200, 200, 200, 255}, 1737.4f * KM_TO_UNITS * RADIUS_SCALE, 3.6913e-6f,
        Vector3Add(earth->GetPosition(), {moonDist * cosf(moonAngle), 0.0f, moonDist * sinf(moonAngle)}),
        Vector3Add(earth->GetVelocity(), Vector3Scale({-sinf(moonAngle), 0.0f, cosf(moonAngle)}, sqrtf(G * earth->GetMass() / moonDist))),
        Vector3Zero());

    float marsDist = 15.2f * DISTANCE_SCALE, marsAngle = 135.0f * DEG2RAD;
    Object* mars = new Object("Mars", Color{193, 68, 14, 255}, 0.0002266f * RADIUS_SCALE, 3.23e-5f,
        {marsDist * cosf(marsAngle), 0.0f, marsDist * sinf(marsAngle)},
        Vector3Scale({-sinf(marsAngle), 0.0f, cosf(marsAngle)}, sqrtf(GM_SUN / marsDist)),
        Vector3Zero());

    // Ksiezyce Marsa krace bardzo blisko planety (Fobos realnie ledwo wystaje
    // poza promien Marsa) - mnoznik 20x utrzymuje je widocznymi poza
    // napompowana (RADIUS_SCALE) kula Marsa, a Deimos wciaz bezpiecznie
    // wewnatrz promienia Hilla Marsa (~0.072 jedn.).
    const float MARS_MOON_SCALE = 20.0f;

    float phobosDist = 9376.0f * KM_TO_UNITS * MARS_MOON_SCALE, phobosAngle = 0.0f * DEG2RAD;
    Object* phobos = new Object("Phobos", Color{130, 120, 110, 255}, 11.267f * KM_TO_UNITS * RADIUS_SCALE, 5.359e-13f,
        Vector3Add(mars->GetPosition(), {phobosDist * cosf(phobosAngle), 0.0f, phobosDist * sinf(phobosAngle)}),
        Vector3Add(mars->GetVelocity(), Vector3Scale({-sinf(phobosAngle), 0.0f, cosf(phobosAngle)}, sqrtf(G * mars->GetMass() / phobosDist))),
        Vector3Zero());

    float deimosDist = 23463.2f * KM_TO_UNITS * MARS_MOON_SCALE, deimosAngle = 180.0f * DEG2RAD;
    Object* deimos = new Object("Deimos", Color{120, 110, 100, 255}, 6.2f * KM_TO_UNITS * RADIUS_SCALE, 7.4218e-14f,
        Vector3Add(mars->GetPosition(), {deimosDist * cosf(deimosAngle), 0.0f, deimosDist * sinf(deimosAngle)}),
        Vector3Add(mars->GetVelocity(), Vector3Scale({-sinf(deimosAngle), 0.0f, cosf(deimosAngle)}, sqrtf(G * mars->GetMass() / deimosDist))),
        Vector3Zero());

    float jupiterDist = 52.0f * DISTANCE_SCALE, jupiterAngle = 180.0f * DEG2RAD;
    Object* jupiter = new Object("Jupiter", Color{216, 179, 130, 255}, 0.004673f * RADIUS_SCALE, 0.0955f,
        {jupiterDist * cosf(jupiterAngle), 0.0f, jupiterDist * sinf(jupiterAngle)},
        Vector3Scale({-sinf(jupiterAngle), 0.0f, cosf(jupiterAngle)}, sqrtf(GM_SUN / jupiterDist)),
        Vector3Zero());

    // Ksiezyce galileuszowe. Mnoznik 12x utrzymuje najblizszego Io wyraznie
    // poza napompowanym Jowiszem, a najdalszy Kallisto zostaje bezpiecznie
    // (~42%) wewnatrz promienia Hilla Jowisza (~3.55 jedn.).
    const float JUPITER_MOON_SCALE = 12.0f;

    float ioDist = 421700.0f * KM_TO_UNITS * JUPITER_MOON_SCALE, ioAngle = 0.0f * DEG2RAD;
    Object* io = new Object("Io", Color{230, 210, 120, 255}, 1821.6f * KM_TO_UNITS * RADIUS_SCALE, 4.4907e-6f,
        Vector3Add(jupiter->GetPosition(), {ioDist * cosf(ioAngle), 0.0f, ioDist * sinf(ioAngle)}),
        Vector3Add(jupiter->GetVelocity(), Vector3Scale({-sinf(ioAngle), 0.0f, cosf(ioAngle)}, sqrtf(G * jupiter->GetMass() / ioDist))),
        Vector3Zero());

    float europaDist = 671034.0f * KM_TO_UNITS * JUPITER_MOON_SCALE, europaAngle = 90.0f * DEG2RAD;
    Object* europa = new Object("Europa", Color{210, 190, 160, 255}, 1560.8f * KM_TO_UNITS * RADIUS_SCALE, 2.4132e-6f,
        Vector3Add(jupiter->GetPosition(), {europaDist * cosf(europaAngle), 0.0f, europaDist * sinf(europaAngle)}),
        Vector3Add(jupiter->GetVelocity(), Vector3Scale({-sinf(europaAngle), 0.0f, cosf(europaAngle)}, sqrtf(G * jupiter->GetMass() / europaDist))),
        Vector3Zero());

    float ganymedeDist = 1070412.0f * KM_TO_UNITS * JUPITER_MOON_SCALE, ganymedeAngle = 180.0f * DEG2RAD;
    Object* ganymede = new Object("Ganymede", Color{150, 140, 130, 255}, 2634.1f * KM_TO_UNITS * RADIUS_SCALE, 7.4505e-6f,
        Vector3Add(jupiter->GetPosition(), {ganymedeDist * cosf(ganymedeAngle), 0.0f, ganymedeDist * sinf(ganymedeAngle)}),
        Vector3Add(jupiter->GetVelocity(), Vector3Scale({-sinf(ganymedeAngle), 0.0f, cosf(ganymedeAngle)}, sqrtf(G * jupiter->GetMass() / ganymedeDist))),
        Vector3Zero());

    float callistoDist = 1882709.0f * KM_TO_UNITS * JUPITER_MOON_SCALE, callistoAngle = 270.0f * DEG2RAD;
    Object* callisto = new Object("Callisto", Color{110, 100, 90, 255}, 2410.3f * KM_TO_UNITS * RADIUS_SCALE, 5.4092e-6f,
        Vector3Add(jupiter->GetPosition(), {callistoDist * cosf(callistoAngle), 0.0f, callistoDist * sinf(callistoAngle)}),
        Vector3Add(jupiter->GetVelocity(), Vector3Scale({-sinf(callistoAngle), 0.0f, cosf(callistoAngle)}, sqrtf(G * jupiter->GetMass() / callistoDist))),
        Vector3Zero());

    float saturnDist = 95.8f * DISTANCE_SCALE, saturnAngle = 225.0f * DEG2RAD;
    Object* saturn = new Object("Saturn", Color{235, 214, 162, 255}, 0.003893f * RADIUS_SCALE, 0.0286f,
        {saturnDist * cosf(saturnAngle), 0.0f, saturnDist * sinf(saturnAngle)},
        Vector3Scale({-sinf(saturnAngle), 0.0f, cosf(saturnAngle)}, sqrtf(GM_SUN / saturnDist)),
        Vector3Zero());

    // Mnoznik 8x: Rhea (najblizsza z wybranych) wyraznie poza Saturnem,
    // Japet (najdalsza) bezpiecznie (~44%) wewnatrz promienia Hilla Saturna
    // (~4.38 jedn.).
    const float SATURN_MOON_SCALE = 8.0f;

    float titanDist = 1221870.0f * KM_TO_UNITS * SATURN_MOON_SCALE, titanAngle = 0.0f * DEG2RAD;
    Object* titan = new Object("Titan", Color{200, 150, 80, 255}, 2574.7f * KM_TO_UNITS * RADIUS_SCALE, 6.7632e-6f,
        Vector3Add(saturn->GetPosition(), {titanDist * cosf(titanAngle), 0.0f, titanDist * sinf(titanAngle)}),
        Vector3Add(saturn->GetVelocity(), Vector3Scale({-sinf(titanAngle), 0.0f, cosf(titanAngle)}, sqrtf(G * saturn->GetMass() / titanDist))),
        Vector3Zero());

    float rheaDist = 527108.0f * KM_TO_UNITS * SATURN_MOON_SCALE, rheaAngle = 120.0f * DEG2RAD;
    Object* rhea = new Object("Rhea", Color{190, 190, 190, 255}, 763.8f * KM_TO_UNITS * RADIUS_SCALE, 1.1596e-7f,
        Vector3Add(saturn->GetPosition(), {rheaDist * cosf(rheaAngle), 0.0f, rheaDist * sinf(rheaAngle)}),
        Vector3Add(saturn->GetVelocity(), Vector3Scale({-sinf(rheaAngle), 0.0f, cosf(rheaAngle)}, sqrtf(G * saturn->GetMass() / rheaDist))),
        Vector3Zero());

    float iapetusDist = 3560820.0f * KM_TO_UNITS * SATURN_MOON_SCALE, iapetusAngle = 240.0f * DEG2RAD;
    Object* iapetus = new Object("Iapetus", Color{150, 140, 120, 255}, 734.5f * KM_TO_UNITS * RADIUS_SCALE, 9.0779e-8f,
        Vector3Add(saturn->GetPosition(), {iapetusDist * cosf(iapetusAngle), 0.0f, iapetusDist * sinf(iapetusAngle)}),
        Vector3Add(saturn->GetVelocity(), Vector3Scale({-sinf(iapetusAngle), 0.0f, cosf(iapetusAngle)}, sqrtf(G * saturn->GetMass() / iapetusDist))),
        Vector3Zero());

    float uranusDist = 192.0f * DISTANCE_SCALE, uranusAngle = 270.0f * DEG2RAD;
    Object* uranus = new Object("Uranus", Color{172, 229, 238, 255}, 0.001695f * RADIUS_SCALE, 4.37e-3f,
        {uranusDist * cosf(uranusAngle), 0.0f, uranusDist * sinf(uranusAngle)},
        Vector3Scale({-sinf(uranusAngle), 0.0f, cosf(uranusAngle)}, sqrtf(GM_SUN / uranusDist)),
        Vector3Zero());

    // Mnoznik 6x - promien Hilla Urana (~4.69 jedn.) jest duzy wzgledem
    // realnych odleglosci jego ksiezycow, wiec zostaje spory margines
    // bezpieczenstwa nawet przy tym mnozniku.
    const float URANUS_MOON_SCALE = 6.0f;

    float titaniaDist = 436300.0f * KM_TO_UNITS * URANUS_MOON_SCALE, titaniaAngle = 0.0f * DEG2RAD;
    Object* titania = new Object("Titania", Color{170, 170, 180, 255}, 788.4f * KM_TO_UNITS * RADIUS_SCALE, 1.7093e-7f,
        Vector3Add(uranus->GetPosition(), {titaniaDist * cosf(titaniaAngle), 0.0f, titaniaDist * sinf(titaniaAngle)}),
        Vector3Add(uranus->GetVelocity(), Vector3Scale({-sinf(titaniaAngle), 0.0f, cosf(titaniaAngle)}, sqrtf(G * uranus->GetMass() / titaniaDist))),
        Vector3Zero());

    float oberonDist = 583500.0f * KM_TO_UNITS * URANUS_MOON_SCALE, oberonAngle = 180.0f * DEG2RAD;
    Object* oberon = new Object("Oberon", Color{160, 155, 150, 255}, 761.4f * KM_TO_UNITS * RADIUS_SCALE, 1.5465e-7f,
        Vector3Add(uranus->GetPosition(), {oberonDist * cosf(oberonAngle), 0.0f, oberonDist * sinf(oberonAngle)}),
        Vector3Add(uranus->GetVelocity(), Vector3Scale({-sinf(oberonAngle), 0.0f, cosf(oberonAngle)}, sqrtf(G * uranus->GetMass() / oberonDist))),
        Vector3Zero());

    float neptuneDist = 300.5f * DISTANCE_SCALE, neptuneAngle = 315.0f * DEG2RAD;
    Object* neptune = new Object("Neptune", Color{62, 84, 191, 255}, 0.001646f * RADIUS_SCALE, 5.15e-3f,
        {neptuneDist * cosf(neptuneAngle), 0.0f, neptuneDist * sinf(neptuneAngle)},
        Vector3Scale({-sinf(neptuneAngle), 0.0f, cosf(neptuneAngle)}, sqrtf(GM_SUN / neptuneDist)),
        Vector3Zero());

    // Mnoznik 8x, spory margines bezpieczenstwa (Neptun ma tylko jednego
    // duzego ksiezyca, wiec nie ma ryzyka nakladania sie orbit).
    const float NEPTUNE_MOON_SCALE = 8.0f;

    // Tryton krazy WSTECZNIE (retrogradnie) wzgledem obrotu Neptuna i reszty
    // Ukladu - jedyny taki duzy ksiezyc. Kierunek predkosci jest odwrocony
    // wzgledem konwencji uzywanej dla wszystkich innych orbit w tym pliku.
    float tritonDist = 354759.0f * KM_TO_UNITS * NEPTUNE_MOON_SCALE, tritonAngle = 0.0f * DEG2RAD;
    Object* triton = new Object("Triton", Color{225, 215, 220, 255}, 1353.4f * KM_TO_UNITS * RADIUS_SCALE, 1.0759e-6f,
        Vector3Add(neptune->GetPosition(), {tritonDist * cosf(tritonAngle), 0.0f, tritonDist * sinf(tritonAngle)}),
        Vector3Add(neptune->GetVelocity(), Vector3Scale({sinf(tritonAngle), 0.0f, -cosf(tritonAngle)}, sqrtf(G * neptune->GetMass() / tritonDist))),
        Vector3Zero());

    // Cztery najwieksze planetoidy pasa glownego, krazace bezposrednio
    // wokol Slonca jak planety - bez problemu z promieniem Hilla.
    float ceresDist = 27.675f * DISTANCE_SCALE, ceresAngle = 20.0f * DEG2RAD;
    Object* ceres = new Object("Ceres", Color{160, 150, 140, 255}, 469.7f * KM_TO_UNITS * RADIUS_SCALE, 4.7182e-8f,
        {ceresDist * cosf(ceresAngle), 0.0f, ceresDist * sinf(ceresAngle)},
        Vector3Scale({-sinf(ceresAngle), 0.0f, cosf(ceresAngle)}, sqrtf(GM_SUN / ceresDist)),
        Vector3Zero());

    float vestaDist = 23.62f * DISTANCE_SCALE, vestaAngle = 110.0f * DEG2RAD;
    Object* vesta = new Object("Vesta", Color{180, 175, 165, 255}, 262.7f * KM_TO_UNITS * RADIUS_SCALE, 1.3026e-8f,
        {vestaDist * cosf(vestaAngle), 0.0f, vestaDist * sinf(vestaAngle)},
        Vector3Scale({-sinf(vestaAngle), 0.0f, cosf(vestaAngle)}, sqrtf(GM_SUN / vestaDist)),
        Vector3Zero());

    float pallasDist = 27.72f * DISTANCE_SCALE, pallasAngle = 200.0f * DEG2RAD;
    Object* pallas = new Object("Pallas", Color{130, 125, 120, 255}, 256.0f * KM_TO_UNITS * RADIUS_SCALE, 1.0257e-8f,
        {pallasDist * cosf(pallasAngle), 0.0f, pallasDist * sinf(pallasAngle)},
        Vector3Scale({-sinf(pallasAngle), 0.0f, cosf(pallasAngle)}, sqrtf(GM_SUN / pallasDist)),
        Vector3Zero());

    float hygieaDist = 31.415f * DISTANCE_SCALE, hygieaAngle = 290.0f * DEG2RAD;
    Object* hygiea = new Object("Hygiea", Color{110, 105, 100, 255}, 217.0f * KM_TO_UNITS * RADIUS_SCALE, 4.1831e-9f,
        {hygieaDist * cosf(hygieaAngle), 0.0f, hygieaDist * sinf(hygieaAngle)},
        Vector3Scale({-sinf(hygieaAngle), 0.0f, cosf(hygieaAngle)}, sqrtf(GM_SUN / hygieaDist)),
        Vector3Zero());

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


void alpha_centauri_system(std::vector<Object*>& objects){
    const float massA = 107.88f;       
    const float massB = 90.92f;        
    const float massProxima = 12.21f;  

    const float RADIUS_SCALE = 40.0f;
    const float radiusA = 0.05693f * RADIUS_SCALE;        
    const float radiusB = 0.04017f * RADIUS_SCALE;        
    const float radiusProxima = 0.007174f * RADIUS_SCALE; 


    const float aAB = 235.0f; 
    const float eAB = 0.5179f;
    const float GM_AB = G * (massA + massB);

    const float rPeriAB = aAB * (1.0f - eAB);
    const float vPeriAB = sqrtf(GM_AB * (1.0f + eAB) / rPeriAB); 

    const float fracA = massB / (massA + massB);
    const float fracB = massA / (massA + massB); 

    Object* alphaA = new Object("Alpha Centauri A", Color{255, 241, 199, 255}, radiusA, massA,
        {-fracA * rPeriAB, 0.0f, 0.0f},
        {0.0f, 0.0f, -fracA * vPeriAB},
        Vector3Zero());

    Object* alphaB = new Object("Alpha Centauri B", Color{255, 199, 120, 255}, radiusB, massB,
        {fracB * rPeriAB, 0.0f, 0.0f},
        {0.0f, 0.0f, fracB * vPeriAB},
        Vector3Zero());


    const float aProxima = 87000.0f;
    const float eProxima = 0.50f;

    const float rPeriProxima = aProxima * (1.0f - eProxima);
    const float vPeriProxima = sqrtf(GM_AB * (1.0f + eProxima) / rPeriProxima);

    Object* proxima = new Object("Proxima Centauri", Color{255, 96, 74, 255}, radiusProxima, massProxima,
        {rPeriProxima, 0.0f, 0.0f},
        {0.0f, 0.0f, vPeriProxima},
        Vector3Zero());

    objects.push_back(alphaA);
    objects.push_back(alphaB);
    objects.push_back(proxima);
}



