#define sensor1 A0
#define LED 13
int licznik;
int Trig = 9;                    //pin do którego podłączamy Trig
int Echo = 8;                    //pin do którego podłączamy Echo

int CzasEcho;                    // Czas trwania sygnału ECHO
int Odleglosc;                   // Odległość w centymetrach
int MaksymalnaOdleglosc = 200;   // Maksymalna odległość
int MinimalnaOdleglosc = 2;      // Minimalna odległość 
 //silniki
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
 //czujnik linii
  pinMode(sensor1, INPUT);
  pinMode(LED, OUTPUT);

  //czujnik odleglosci
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT); 
  digitalWrite(Trig, LOW);  
  Serial.begin(9600);

  //silniki
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);
 
}
 
void loop()
{
  
 //czujnik linii
  int odczyt = analogRead(sensor1);
  
  Serial.print("CNY70: ");
  Serial.println(odczyt);
 
  if(odczyt >= 500)           //jeżeli wykryto czarną linię
  {
  //zapal diodę
  digitalWrite(LED, HIGH);
    
  }
  else                       //jeżeli nie wykryto linii
  {
  //zgas diode
  digitalWrite(LED, LOW);
  delay(100);
  } 
  
 //czujnik odleglosci
 //Rozpocznij Pomiar odleglosci 
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10);  
  digitalWrite(Trig, LOW); 
  //Pomiar zakończony
 
  //Odczyt czasu odbioru
  CzasEcho = pulseIn(Echo, HIGH);
 
  // Obliczamy odległość
  Odleglosc = CzasEcho / 58; //wynik w centymetrach
 

  if (Odleglosc >= MaksymalnaOdleglosc) 
  {
    Serial.println("Nie widze nic w odleglosci 2 metrow");  
  }  
  
  if( Odleglosc >= MinimalnaOdleglosc)
  {
       
    Serial.print("Odleglosc: ");
    Serial.println(Odleglosc);  
  }

  
  //Silniki
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(10, 255); //ENA pin
  analogWrite(11, 255); //ENB pin
 
  if(odczyt >= 500, Odleglosc < 70)
  {
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor2pin1,HIGH);
  delay(200);
  }
  else(odczyt < 500);
  {
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin2,LOW);

  }
}
