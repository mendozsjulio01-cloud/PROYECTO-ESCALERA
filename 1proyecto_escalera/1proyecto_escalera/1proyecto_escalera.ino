
#define S0 1
#define S1 2
#define S2 3
#define S3 4
#define OUT 5

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
#define LED5 9
#define LED6 8
#define LED7 7
#define LED8 6

const int tiempoON = 500;
const int tiempoOFF = 500;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  Serial.begin(9600);
}

void apagarTodo() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
}

void controlSerial() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    if (c == 'E') {
      digitalWrite(LED1, HIGH);
      Serial.println("LED1 ENCENDIDO");
    }
    else if (c == 'I') {
      digitalWrite(LED5, HIGH);
      Serial.println("LED5 ENCENDIDO");
    }
    else if (c == 'U') {
      digitalWrite(LED8, HIGH);
      Serial.println("LED8 ENCENDIDO");
    }
    else if (c == 'F') {
      apagarTodo();
      Serial.println("LEDs APAGADOS");
    }
  }
}

unsigned int leerColor(boolean s2, boolean s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(20);
  return pulseIn(OUT, HIGH);
}

void loop() {
  controlSerial();

  unsigned int R = leerColor(LOW, LOW);
  unsigned int G = leerColor(HIGH, HIGH);
  unsigned int B = leerColor(LOW, HIGH);

  bool esRojo  = (R < G - 10) && (R < B - 8);
  bool esVerde = (G < R - 15) && (G < B - 5);
  bool esAzul  = (B < R - 20) && (B < G - 10);

  if (!esRojo && !esVerde && !esAzul) {
    return;
  }

  if (esRojo) {
    Serial.println("Color detectado: ROJO");
    Serial.println("EQUIPO 1");
  }

  if (esVerde) {
    Serial.println("Color detectado: VERDE");
    Serial.println("EQUIPO 2");
  }

  if (esAzul) {
    Serial.println("Color detectado: AZUL");
    Serial.println("EQUIPO 3");
  }

  digitalWrite(LED1, HIGH); delay(tiempoON); digitalWrite(LED1, LOW); delay(tiempoOFF);
  digitalWrite(LED2, HIGH); delay(tiempoON); digitalWrite(LED2, LOW); delay(tiempoOFF);
  digitalWrite(LED3, HIGH); delay(tiempoON); digitalWrite(LED3, LOW); delay(tiempoOFF);
  digitalWrite(LED4, HIGH); delay(tiempoON); digitalWrite(LED4, LOW); delay(tiempoOFF);
  digitalWrite(LED5, HIGH); delay(tiempoON); digitalWrite(LED5, LOW); delay(tiempoOFF);
  digitalWrite(LED6, HIGH); delay(tiempoON); digitalWrite(LED6, LOW); delay(tiempoOFF);
  digitalWrite(LED7, HIGH); delay(tiempoON); digitalWrite(LED7, LOW); delay(tiempoOFF);
  digitalWrite(LED8, HIGH); delay(tiempoON); digitalWrite(LED8, LOW); delay(tiempoOFF);

  delay(500);
}
