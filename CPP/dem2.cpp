#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>
using namespace std;

// Hypothetical sensor data structure
struct TrafficSensorData {
    int vehicleCount;
};

// Function to simulate collecting data from sensors
TrafficSensorData getTrafficData() {
    // This would actually interface with hardware
    // Here we just return some dummy data for illustration
    return { rand() % 50 };  // Random vehicle count
}

// Function to calculate the timing for the traffic light
int calculateTrafficLightTiming(int vehicleCount) {
    // Basic logic: more vehicles mean longer green light
    if (vehicleCount < 10) {
        return 30;  // 30 seconds for low density
    } else if (vehicleCount < 30) {
        return 60;  // 60 seconds for medium density
    } else {
        return 90;  // 90 seconds for high density
    }
}

// Function to update the traffic light
void updateTrafficLight(int duration) {
    static int count=0;
    // Here we would send the duration to the traffic light controller
    // For this example, we'll just print it
    
    int checkC=count%4;
    
    if(checkC==0){
        cout<<endl<<endl<<"\"NEW CIRCLE START\""<<endl;
    }
    
    switch (checkC){
        case 0:
            cout<<"NORTH\n";
            break;
        case 1:
            cout<<"EAST\n";
            break;
        case 2:
            cout<<"SOUTH\n";
            break;
        case 3:
            cout<<"WEST\n";
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
        updateTrafficLight(duration);

        // Wait for some time before checking again (simulate real-time monitoring)
        // std::this_thread::sleep_for(std::chrono::seconds(10));
        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + seconds(1));
        
        sleep(2);//sleeps for 3 second
    }

    return 0;
}
