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


double duration;
int distance;

void setup()
{
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
	Serial.begin(9600); 
  
  
  
}
int flag; 

void low( int test ){
	if( test != flag){
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


void loop()
{
  	digitalWrite(Trig, LOW);
	delayMicroseconds(2);
	digitalWrite(Trig, HIGH);
	delayMicroseconds(10);
  	digitalWrite(Trig, LOW);
  	
  	duration = pulseIn(Echo, HIGH);
    //distance=(duration *.034/2);
    Serial.println(duration);
  	//Serial.println(distance);
    if(duration <=  19398 && duration >=  17242) {
    low(9);
    digitalWrite(One, HIGH);
    digitalWrite(Two, HIGH);
    digitalWrite(Three, HIGH);
    digitalWrite(Four, HIGH);
    digitalWrite(Five, LOW);
    digitalWrite(Six, HIGH);
    digitalWrite(Seven, HIGH);
    }
  
    else if (duration <=  17242 && duration >=  15088 ) {
      low(8);
      digitalWrite(One, HIGH);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, HIGH);
      digitalWrite(Five, HIGH);
      digitalWrite(Six, HIGH);
      digitalWrite(Seven, HIGH);
    }
  
    else if (duration <=  15088 && duration >=  12933) {
      low(7);
      digitalWrite(One, HIGH);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, LOW);
      digitalWrite(Five, LOW);
      digitalWrite(Six, LOW);
      digitalWrite(Seven, LOW);
    }
   else if (duration <=  12933 && duration >=  10778) {
      low(6);
      digitalWrite(One, HIGH);
      digitalWrite(Two, LOW);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, HIGH);
      digitalWrite(Five, HIGH);
      digitalWrite(Six, HIGH);
      digitalWrite(Seven, HIGH);
    }
   else if (duration <=  10778 && duration >=  8623) {
      low(5);
      digitalWrite(One, HIGH);
      digitalWrite(Two, LOW);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, HIGH);
      digitalWrite(Five, LOW);
      digitalWrite(Six, HIGH);
      digitalWrite(Seven, HIGH);
    }
   else if (duration <=  8623 && duration >=  6468) {
      low(4);
      digitalWrite(One, LOW);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, LOW);
      digitalWrite(Five, LOW);
      digitalWrite(Six, HIGH);
      digitalWrite(Seven, HIGH);
    }
   else if (duration <=  6468 && duration >=  4313) {
      low(3);
      digitalWrite(One, HIGH);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, HIGH);
      digitalWrite(Five, LOW);
      digitalWrite(Six, LOW);
      digitalWrite(Seven, HIGH);
    }
  else if (duration <=  4313 && duration >=  2158) {
      low(2);
      digitalWrite(One, HIGH);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, LOW);
      digitalWrite(Four, HIGH);
      digitalWrite(Five, HIGH);
      digitalWrite(Six, LOW);
      digitalWrite(Seven, HIGH);
    }
  else if (duration <=  2158 && duration >=  0) {
      low(1);
      digitalWrite(One, LOW);
      digitalWrite(Two, HIGH);
      digitalWrite(Three, HIGH);
      digitalWrite(Four, LOW);
      digitalWrite(Five, LOW);
      digitalWrite(Six, LOW);
      digitalWrite(Seven, LOW);
    }
                                                                                                                                                                                  
  else {
    digitalWrite(Eight, HIGH);
    low(-1);
    } 	
}