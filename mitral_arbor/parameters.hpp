#include <iostream>

#include <array>
#include <cmath>
#include <fstream>
#include <random>

#include <arbor/cable_cell.hpp>

#include <common/json_params.hpp>

struct gap_params {
    gap_params() = default;

    std::string name = "default";
    unsigned num_cells = 2;
    bool stim_tuft = false;
    double duration = 300;
    unsigned num_gj = 20;
    bool tweak = false;
    bool gj = false;
};

gap_params read_options(int argc, char** argv) {
    using sup::param_from_json;

    gap_params params;
    if (argc<2) {
        std::cout << "Using default parameters.\n";
        return params;
    }
    if (argc>2) {
        throw std::runtime_error("More than command line one option not permitted.");
    }

    std::string fname = argv[1];
    std::cout << "Loading parameters from file: " << fname << "\n";
    std::ifstream f(fname);

    if (!f.good()) {
        throw std::runtime_error("Unable to open input parameter file: "+fname);
    }

    nlohmann::json json;
    json << f;

    param_from_json(params.name, "name", json);
    param_from_json(params.stim_tuft, "stim-tuft", json);
    param_from_json(params.duration, "duration", json);
    param_from_json(params.tweak, "tweak", json);
    param_from_json(params.gj, "gap-junctions", json);

    if (!json.empty()) {
        for (auto it=json.begin(); it!=json.end(); ++it) {
            std::cout << "  Warning: unused input parameter: \"" << it.key() << "\"\n";
        }
        std::cout << "\n";
    }

    return params;
}
