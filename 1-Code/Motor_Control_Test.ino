// Right side Motor connections
int in1 = 27;
int in2 = 26;
// Left side Motor B connections
int in3 = 25;
int in4 = 33;
int count=0;

void setup() {
  // Set all the motor control pins to outputs
  Serial.begin(115200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
    // Forward
  Serial.println("FORWRAD");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(7000);
  
  // Backward
  Serial.println("BACKWRAD");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(7000);

  // Right
  Serial.println("RIGHT");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(7000);

  // Left
  Serial.println("LEFT");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(7000);

  // Stop 
  Serial.println("STOP");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.print("count : ");
  Serial.println(count);
  count++;
  Serial.print("------------------------------------");
  
  delay(3000);
}
