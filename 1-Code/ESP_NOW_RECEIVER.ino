#include <esp_now.h>
#include <WiFi.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    char ch;
} struct_message;

struct_message myData;

char ch2='S';
const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 14;
// Right side Motor connections connected to out-1 and out-2
int in1 = 27;
int in2 = 26;
// Left side Motor B connections connected to out-3 and out-4
int in3 = 33;
int in4 = 32; 
long duration;
float distanceCm;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Char received from transmitter : ");
  Serial.println(myData.ch);
  ch2 = myData.ch;
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // ultrasonic sensor setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  
  if(ch2 == 'F'){
    digitalWrite(buzzer, LOW);
    Serial.println("Buzzer : LOW");
    Serial.println("Move Forward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(ch2 == 'B'){
    if(distanceCm <= 30){
      Serial.println("Obstcale Detected !");
      digitalWrite(buzzer, HIGH);
      Serial.println("Buzzer : HIGH");
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else{
      digitalWrite(buzzer, LOW);
      Serial.println("Buzzer : LOW");
      Serial.println("Move Backward");
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
  }
  else if(ch2 == 'R'){
    digitalWrite(buzzer, LOW);
    Serial.println("Buzzer : LOW");
    Serial.println("Move Right");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if(ch2 == 'L'){
    digitalWrite(buzzer, LOW);
    Serial.println("Buzzer : LOW");
    Serial.println("Move Left");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else{
    digitalWrite(buzzer, LOW);
    Serial.println("Buzzer : LOW");
    Serial.println("Stop");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  
  delay(100);
}
