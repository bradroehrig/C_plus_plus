#include <iostream>

class Drone {
private:
    double positionX;
    double positionY;
    double altitude;

public:
    Drone() : positionX(0), positionY(0), altitude(0) {}

    void setPosition(double x, double y, double alt) {
        positionX = x;
        positionY = y;
        altitude = alt;
    }

    void printPosition() const {
        std::cout << "Drone Position: (" << positionX << ", " << positionY << ", " << altitude << ")\n";
    }
};

class DroneController {
public:
    static void takeOff(Drone& drone) {
        drone.setPosition(0, 0, 10); // Assuming initial position at (0, 0) and altitude 10 meters
        std::cout << "Drone taking off...\n";
    }

    static void moveTo(Drone& drone, double x, double y, double alt) {
        drone.setPosition(x, y, alt);
        std::cout << "Drone moving to position: (" << x << ", " << y << ", " << alt << ")\n";
    }

    static void land(Drone& drone) {
        drone.setPosition(drone.getPositionX(), drone.getPositionY(), 0); // Landing at altitude 0
        std::cout << "Drone landing...\n";
    }
};

int main() {
    Drone myDrone;
    DroneController::takeOff(myDrone);
    myDrone.printPosition();

    DroneController::moveTo(myDrone, 5, 5, 15);
    myDrone.printPosition();

    DroneController::land(myDrone);
    myDrone.printPosition();

    return 0;
}
