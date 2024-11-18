#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

// range is in meters

int getRange(){
    return ( rand() % 1000 );
}

bool checkRange(int range){
    static int count=-1;
    count++;
    int checkC = count % 4;



    if(range<=200){

        // direction
        switch (checkC){
        case 0:
            cout<<"NORTH->";
            break;
        case 1:
            cout<<"EAST->";
            break;
        case 2:
            cout<<"SOUTH->";
            break;
        case 3:
            cout<<"WEST->";
            break;
        }
        return true;

    }
    else{
        return false;
    }
    
}

int main(){

    while(true){
        int range = getRange();
        if(checkRange(range)){
            // we can send alerts using hardware
            cout<<"\a";
            cout<<"Emergeny Vehicle Detected"<<endl;
        }
        else{
            cout<<"............"<<endl;
        }
        sleep(1);
    }

    return 0;
}