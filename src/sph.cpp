#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <eigen3/Eigen/Dense>
#include <raylib.h>

// A class for holding two neighboring paricles and their weighted distance.
class neighbor {
    int i;
    int j;
    double q;
    double q2;
};

// The particle structure holding all of the relevant information.
class particle {
    public:
    Eigen::Vector2d position;
    Eigen::Vector2d position_old;
    Eigen::Vector2d velocity;
    Eigen::Vector2d force;

    double mass;
    double rho;
    double rho_near;
    double press;
    double press_near;
    double sigma;
    double beta;
    std::vector<neighbor> neighbors;

    std::string color = "MAROON";

    particle(const double position_x, const double position_y){
        this->position = Eigen::Vector2d(position_x, position_y);
    }

};

void render(const std::vector<particle> particles){
    // change the color depend on the pressure of the particle
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // draw particles
    for (auto&& p: particles) {
        DrawCircle(p.position[0], p.position[1], 2, MAROON);
    }
}

int main(void){
    std::cout << "sph initialize start" << std::endl;
    // init sph
    std::map<std::string, double> config;
    config["g"] = 0.2 * 0.25;
    config["N"] = 1024;
    config["window_h"] = 512;
    config["window_w"] = 512;
    config["spacing"] = 2;
    config["presure_weight"] = config["spacing"] / 1000;
    config["near_presure_weight"] = config["presure_weight"] * 10;
    config["rest_density"] = 3;
    config["radius"] = config["spacing"] * 1.25;
    config["rsq"] = config["radius"] * config["radius"];
    config["size_of_world"] = 50;
    config["floor_of_world"] = 0;

    std::vector<particle> particles;

    std::cout << "sph initialize finish" << std::endl;
    std::cout << "raylib initialize start" << std::endl;
    // init raylib
    std::cout << "raylib initialize finish" << std::endl;

    int i = 0;
    while (true) {
        std::cout << "iteration : " << i << std::endl;
        // update sph
        // update raylib
    }
    
}
