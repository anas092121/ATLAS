#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>
using namespace std;

// sensor
int vehicleCount;




/*****************  Emergency Vehicle  *****************/
// data from sensor
int getRange(){
    return (rand() % 1000);
}

bool checkRange(int range){
    static int countV = -1;
    countV++;
    int checkC = countV % 4;

    if (range <= 200){
        // direction
        switch (checkC){
            case 0:
                cout << "NORTH->";
                break;
            case 1:
                cout << "EAST->";
                break;
            case 2:
                cout << "SOUTH->";
                break;
            case 3:
                cout << "WEST->";
                break;
        }
        return true;
    }
    else{
        return false;
    }
}

int getTrafficData(){
    // This would actually interface with hardware
    // Here we just return some dummy data for illustration

    return (rand()%50); // Random vehicle count
}

int calculateTrafficLightTiming(int vehicleCount){
    if (vehicleCount < 10){
        return 30; // low density
    }
    else if (vehicleCount < 30){
        return 60; // medium density
    }
    else{
        return 90; // high density
    }
}

void updateTrafficLight(int duration, int cars){
    // Here we would send the duration to the traffic light controller

    static int count = 0;
    int checkC = count % 4;

    if (checkC == 0){
        cout << endl
             << endl
             << "\"NEW CIRCLE START\"" << endl;
    }

    switch (checkC){
        case 0:
            cout << cars << "->NORTH\n";
            break;
        case 1:
            cout << cars << "->EAST\n";
            break;
        case 2:
            cout << cars << "->SOUTH\n";
            break;
        case 3:
            cout << cars << "->WEST\n";
            break;
    }
    std::cout << "Traffic light duration to " << duration << " seconds." << std::endl;
    count++;
}



int main(){
    while (true){
        // Collect traffic data
        vehicleCount = getTrafficData();

        // Calculate the new traffic light duration
        int duration = calculateTrafficLightTiming(vehicleCount);

        // Update the traffic light
        updateTrafficLight(duration, vehicleCount);


        // check if Emergency Vehicle
        int range = getRange();
        if(checkRange(range)){
            // we can send alerts using hardware
            cout<<"\a";
            cout<<"Emergeny Vehicle Detected"<<endl;
            sleep(5);
        }
        else{
            cout<<"............"<<endl;
        }

        // delay -->
        // Wait for some time before checking again (simulate real-time monitoring)

        sleep(3); // sleeps seconds
    }

    return 0;
}
