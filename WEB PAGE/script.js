// Hypothetical sensor data structure
class TrafficSensorData {
    constructor(vehicleCount) {
        this.vehicleCount = vehicleCount;
    }
}

// Function to simulate collecting data from sensors
function getTrafficData() {
    // Simulating real sensor data with a random vehicle count
    return new TrafficSensorData(Math.floor(Math.random() * 50));
}

// Function to calculate the timing for the traffic light
function calculateTrafficLightTiming(vehicleCount) {
    if (vehicleCount < 10) {
        return 30;  // 30 seconds for low density
    } else if (vehicleCount < 30) {
        return 60;  // 60 seconds for medium density
    } else {
        return 90;  // 90 seconds for high density
    }
}

// Function to update the traffic light and display on the webpage
let count = 0;

function updateTrafficLight(duration) {
    let checkC = count % 4;
    const directions = ['north', 'east', 'south', 'west'];

    // Remove active class from all directions
    directions.forEach(dir => {
        document.getElementById(dir).classList.remove('active');
    });

    // Add active class to the current direction
    const currentDirection = directions[checkC];
    document.getElementById(currentDirection).classList.add('active');

    // Update the duration display
    document.getElementById('duration').textContent = duration;

    count++;
}

// Main loop simulation
function trafficControlSystem() {
    setInterval(() => {
        // Collect traffic data
        let data = getTrafficData();

        // Calculate the new traffic light duration
        let duration = calculateTrafficLightTiming(data.vehicleCount);

        // Update the traffic light
        updateTrafficLight(duration);

    }, 2000); // Wait for 2 seconds between each cycle
}

// Start the traffic control system
trafficControlSystem();
