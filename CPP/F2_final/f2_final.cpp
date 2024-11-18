#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <unistd.h>
using namespace std;

// sensor
int vehicleCount;
int emg[4]={0};



/*****************  Emergency Vehicle  *****************/
// data from sensor
void getRange(){
    // resetting values
    for(int i=0; i<4; i++){
        emg[i]=0;
    }

    if((rand()%1000) < 100){
        emg[0]=1;
    }
    if((rand()%1000) < 100){
        emg[1]=1;
    }
    if((rand()%1000) < 100){
        emg[2]=1;
    }
    if((rand()%1000) < 100){
        emg[3]=1;
    }

}

void emergencyMode(){
    bool north = emg[0];
    bool east = emg[1];
    bool south = emg[2];
    bool west = emg[3];

    if(north || east || west || south){
        cout<<"Emergency Vehicle Detected : "<<"\a";

        if(north)   cout<<"North, "<<endl;
        if(east)   cout<<"East, "<<endl;
        if(south)   cout<<"South, "<<endl;
        if(west)   cout<<"West, "<<endl;

        cout<<"Entering Emergency Mode"<<endl;
        sleep(5);
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
    cout << "Traffic light duration to " << duration << " seconds." << endl;
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
        getRange();

        // emergency vehicle checking
        emergencyMode();

        cout<<"............"<<endl;


        // delay -->
        // some delay before checking again 
        sleep(3); // sleeps in seconds
    }

    return 0;
}