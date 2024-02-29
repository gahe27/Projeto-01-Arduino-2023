#define AnalogLDR A0
int Leitura = 0;
float VoltagemLDR;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Leitura = analogRead(AnalogLDR);
  VoltagemLDR = Leitura * (5.0/1024);
  Serial.print("Leitura sensor LDR = ");
  
  if(VoltagemLDR <= 2.4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(VoltagemLDR <= 3 && VoltagemLDR > 2.4){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(VoltagemLDR > 3){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  
  Serial.println(VoltagemLDR);
  delay(500);
}