#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>
using namespace std;

// sensor
struct TrafficSensorData {
    int vehicleCount;
};

// func to return traffic density
TrafficSensorData getTrafficData() {
    // This would actually interface with hardware
    // Here we just return some dummy data for illustration
    return { rand() % 50 };  // Random vehicle count
}


int calculateTrafficLightTiming(int vehicleCount) {
    // more vehicles mean longer green light
    if (vehicleCount < 10) {
        return 30;  // low density
    } else if (vehicleCount < 30) {
        return 60;  // medium density
    } else {
        return 90;  // high density
    }
}


void updateTrafficLight(int duration , int cars) {
    static int count=0;
    // Here we would send the duration to the traffic light controller
    // For this example/demo, we'll just print it
    
    int checkC=count%4;
    
    if(checkC==0){
        cout<<endl<<endl<<"\"NEW CIRCLE START\""<<endl;
    }
    
    switch (checkC){
        case 0:
            cout<<cars<<"->NORTH\n";
            break;
        case 1:
            cout<<cars<<"->EAST\n";
            break;
        case 2:
            cout<<cars<<"->SOUTH\n";
            break;
        case 3:
            cout<<cars<<"->WEST\n";
            break;
    }
    std::cout << "Updating traffic light duration to " << duration << " seconds." << std::endl;
    count++;
}

int main() {
    while (true) {
        // Collect traffic data
        TrafficSensorData data = getTrafficData();

        // Calculate the new traffic light duration
        int duration = calculateTrafficLightTiming(data.vehicleCount);

        // Update the traffic light
        updateTrafficLight(duration, data.vehicleCount);



        // delay -->
        // Wait for some time before checking again (simulate real-time monitoring)
        // std::this_thread::sleep_for(std::chrono::seconds(10));
        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + seconds(1));
        
        sleep(5);//sleeps for 3 secondk
        
    }

    return 0;
}
