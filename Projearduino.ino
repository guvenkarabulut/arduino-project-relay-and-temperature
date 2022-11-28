#define role1 7
#define ledyesil 2
#define ledsari 3
#define ledkirmizi 4
#define lm35pin A0

int okunandeger = 0;
float sicaklikgerilim = 0;
float sicaklik = 0;

void setup() {
  Serial.begin(9600);
  pinMode(role1, OUTPUT);
  pinMode(ledyesil, OUTPUT);
  pinMode(ledsari, OUTPUT);
  pinMode(ledkirmizi, OUTPUT);
  Serial.println("Hoşgeldiniz Sistemi Açmak İçin a/A Yazınız Kapatmak İçin İse k/K Yazınız Sıcaklık Bilgisini Almak için s/S Yazabilirsiniz. ");
}
void loop() {
  digitalWrite(ledsari, LOW);
  digitalWrite(ledkirmizi, LOW);
  digitalWrite(ledyesil, LOW);

  okunandeger = analogRead(lm35pin);
  sicaklikgerilim = (5000.0 / 1023.0) * okunandeger;
  sicaklik = sicaklikgerilim / 10.0;
  if (sicaklik > 20 and sicaklik < 25)
  {
    digitalWrite(ledsari, LOW);
    digitalWrite(ledkirmizi, LOW);
    digitalWrite(ledyesil, HIGH);

  }
  if (sicaklik >25 and sicaklik < 30)
  {
    digitalWrite(ledyesil, LOW);
    digitalWrite(ledkirmizi, LOW);
    digitalWrite(ledsari, HIGH);
  }
  if (sicaklik > 30 and sicaklik < 35)
  {
    digitalWrite(ledyesil, LOW);
    digitalWrite(ledkirmizi, HIGH);
    digitalWrite(ledsari, LOW);
  }


  if (Serial.available() == 1)
  {
    char gelenchar = Serial.read();
    switch (gelenchar)
    {
      case 'a':
        {
          digitalWrite(role1, HIGH);
          Serial.println("Sistem Açılıyor");
          break;
        }
      case 'A':
        {
          digitalWrite(role1, HIGH);
          Serial.println("Sistem Açılıyor");
          break;
        }
      case 'k':
        {
          digitalWrite(role1, LOW);
          Serial.println("Sistem Kapanıyor");
          break;
        }
      case 'K':
        {
          digitalWrite(role1, LOW);
          Serial.println("Sistem Kapanıyor");
          break;
        }
      case 'S':
        {
          Serial.print("Ortam Sıcaklığı:");
          Serial.println(sicaklik);
          break;
        }
        case 's':
        {
          Serial.print("Ortam Sıcaklığı:");
          Serial.println(sicaklik);
          break;
        }
    }
  }
}
