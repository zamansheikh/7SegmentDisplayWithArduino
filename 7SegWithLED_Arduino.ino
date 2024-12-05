#define One 12
#define Two 2
#define Three 3
#define Four 4
#define Five 5
#define Six 6
#define Seven 7
#define Eight 8
#define Echo 11
#define Trig 10

double duration; // Time taken for the echo pulse
float distance;  // Distance calculated in meters
int flag;

void setup() {
    // Set pin modes for LED outputs and sensor pins
    pinMode(One, OUTPUT);
    pinMode(Two, OUTPUT);
    pinMode(Three, OUTPUT);
    pinMode(Four, OUTPUT);
    pinMode(Five, OUTPUT);
    pinMode(Six, OUTPUT);
    pinMode(Seven, OUTPUT);
    pinMode(Eight, OUTPUT);
    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);

    // Start serial communication
    Serial.begin(9600);
}

// Function to reset all LEDs to LOW and prevent redundant switching
void low(int test) {
    if (test != flag) {
        digitalWrite(One, LOW);
        digitalWrite(Two, LOW);
        digitalWrite(Three, LOW);
        digitalWrite(Four, LOW);
        digitalWrite(Five, LOW);
        digitalWrite(Six, LOW);
        digitalWrite(Seven, LOW);
        digitalWrite(Eight, LOW);
        flag = test;
    }
}

void loop() {
    // Send a 10 µs pulse to the Trig pin
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);

    // Measure the duration of the pulse
    duration = pulseIn(Echo, HIGH);

    // Calculate distance in meters
    distance = (duration * 0.034) / 2 / 100; // Speed of sound in cm/µs, divided by 100 for meters
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" m");

    // Determine the LED pattern based on the distance
    int roundedDistance = -1; // Default case for out-of-range distances
   	if (distance > 0 && distance <= 0.1) roundedDistance = 0;
	else if (distance > 0.1 && distance <= 0.4) roundedDistance = 1;
	else if (distance > 0.4 && distance <= 0.7) roundedDistance = 2;
	else if (distance > 0.7 && distance <= 1.0) roundedDistance = 3;
	else if (distance > 1.0 && distance <= 1.3) roundedDistance = 4;
	else if (distance > 1.3 && distance <= 1.6) roundedDistance = 5;
	else if (distance > 1.6 && distance <= 1.9) roundedDistance = 6;
	else if (distance > 1.9 && distance <= 2.2) roundedDistance = 7;
	else if (distance > 2.2 && distance <= 2.5) roundedDistance = 8;
	else if (distance > 2.5 && distance <= 3.3) roundedDistance = 9;
	else roundedDistance = -1; // Out of range
    // Update LEDs using switch-case
    switch (roundedDistance) {
        case 9:
            low(9);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, LOW);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, HIGH);
            break;

        case 8:
            low(8);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, HIGH);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, HIGH);
            break;

        case 7:
            low(7);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, LOW);
            digitalWrite(Five, LOW);
            digitalWrite(Six, LOW);
            digitalWrite(Seven, LOW);
            break;

        case 6:
            low(6);
            digitalWrite(One, HIGH);
            digitalWrite(Two, LOW);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, HIGH);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, HIGH);
            break;

        case 5:
            low(5);
            digitalWrite(One, HIGH);
            digitalWrite(Two, LOW);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, LOW);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, HIGH);
            break;

        case 4:
            low(4);
            digitalWrite(One, LOW);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, LOW);
            digitalWrite(Five, LOW);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, HIGH);
            break;

        case 3:
            low(3);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, LOW);
            digitalWrite(Six, LOW);
            digitalWrite(Seven, HIGH);
            break;

        case 2:
            low(2);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, LOW);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, HIGH);
            digitalWrite(Six, LOW);
            digitalWrite(Seven, HIGH);
            break;

        case 1:
            low(1);
            digitalWrite(One, LOW);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, LOW);
            digitalWrite(Five, LOW);
            digitalWrite(Six, LOW);
            digitalWrite(Seven, LOW);
            break;

        case 0:
            low(0);
            digitalWrite(One, HIGH);
            digitalWrite(Two, HIGH);
            digitalWrite(Three, HIGH);
            digitalWrite(Four, HIGH);
            digitalWrite(Five, HIGH);
            digitalWrite(Six, HIGH);
            digitalWrite(Seven, LOW);
            break;

        default: // For out-of-range distances
            low(-1);
            digitalWrite(Eight, HIGH);
            break;
    }

    delay(1000); // Delay before the next reading
}
