
#include <iostream>
#include <vector>

using namespace std;

class AtmosphericEngine {
public:
    AtmosphericEngine(int volume, int numCylinders)
    : volume_(volume), numCylinders_(numCylinders) {
    }

    int get_power() {
        return 50 * volume_ + numCylinders_;
    }
private:
    int volume_;
    int numCylinders_;
};

class TurboEngine : public AtmosphericEngine {
public:
    TurboEngine(int volume, int numCylinders)
    : AtmosphericEngine(volume, numCylinders) {
    }

    int get_power()  {
        return AtmosphericEngine::get_power() + 30;
    }

};

int main() {
    int n;
    cin >> n;
    vector<AtmosphericEngine*> engines;
    for (int i = 0; i < n; ++i) {
        string engine_type;
        int volume;
        int numCylinders;
        cin >> engine_type >> volume >> numCylinders;
        if (engine_type == "atmospheric") {
            engines.push_back(new AtmosphericEngine(volume, numCylinders));
        } else {
            engines.push_back(new TurboEngine(volume, numCylinders));
        }
    }

    int total_power = 0;
    for (auto engine : engines) {

        total_power += engine->get_power();
    }
    cout << total_power << endl;

    for (auto engine : engines) {
        delete engine;
    }
    engines.clear();

    return 0;
}