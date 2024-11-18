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

let count = 0;
const directions = ['north', 'east', 'south', 'west'];

function updateTrafficLights(duration) {
    let currentDirection = directions[count % 4];

    // Reset all lights to red
    directions.forEach(dir => {
        setRedLight(dir);
    });

    // Turn on the green light for the current direction
    setGreenLight(currentDirection);

    // Update the status display
    document.getElementById('current-direction').textContent = capitalize(currentDirection);
    document.getElementById('duration').textContent = duration;

    count++;
}

// Helper functions to set light colors
function setRedLight(direction) {
    document.querySelector(`#${direction}-light .red`).classList.remove('off');
    document.querySelector(`#${direction}-light .yellow`).classList.add('off');
    document.querySelector(`#${direction}-light .green`).classList.add('off');
}

function setGreenLight(direction) {
    document.querySelector(`#${direction}-light .red`).classList.add('off');
    document.querySelector(`#${direction}-light .yellow`).classList.add('off');
    document.querySelector(`#${direction}-light .green`).classList.remove('off');
}

// Utility function to capitalize the first letter
function capitalize(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
}

// Main loop simulation
function trafficControlSystem() {
    setInterval(() => {
        // Collect traffic data
        let data = getTrafficData();

        // Calculate the new traffic light duration
        let duration = calculateTrafficLightTiming(data.vehicleCount);

        // Update the traffic lights
        updateTrafficLights(duration);

    }, 2000); // Wait for 2 seconds between each cycle
}

// Start the traffic control system
trafficControlSystem();
