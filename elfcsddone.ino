#include <MFRC522.h> 
#include <SPI.h>

#include <LiquidCrystal.h>
#include <Wire.h> 
#define SS_PIN 10 
#define RST_PIN 9  

#define BUZZER 6 
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);
int buzzerPin = 6;

bool access = false;
//k got no chill
MFRC522 mfrc522(SS_PIN, RST_PIN);  

int count = 0;
 
int a;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
 
double total = 0;
int count_prod = 0;
 

void setup()
{
  Serial.begin(9600);  
  SPI.begin();         
  mfrc522.PCD_Init();  
  Serial.println("Put your card to the reader...");
  Serial.println();

  
  Serial.println("Scan card");
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop()
{
  

  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
 
  Serial.print("UID tag :");
  lcd.setCursor(0,0);
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

if(content.substring(1) == "83 F0 F5 A5") 
    {
       p1++;
      total = total + 15.00;
    count_prod++;
    digitalWrite(buzzerPin, HIGH);
     
        delay(100);
        digitalWrite(buzzerPin, LOW);
         
        delay(100);
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.println("Biscuits");
    lcd.setCursor(0, 1);
    lcd.println(" 15.00 ");
    delay(5000);
    lcd.clear();
     
   
    }


if(content.substring(1) == "A3 2B A6 95") 
    {
      p2++;
      total = total + 20.00;
    count_prod++;
    digitalWrite(buzzerPin, HIGH);
    
        delay(100);
        
        digitalWrite(buzzerPin, LOW);
        delay(100);
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("icecream:");
    lcd.setCursor(0, 1);
    lcd.println(" 20.00 ");
    delay(5000);
    lcd.setCursor(0, 1);
    delay(2000);
   
    

  }
if(content.substring(1) == "D3 72 25 24") 
    {
      p3++;
      total = total + 42.00;
    count_prod++;
    digitalWrite(buzzerPin, HIGH);
    
        delay(100);
        
        digitalWrite(buzzerPin, LOW);
        delay(100);
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("nescafe:");
    lcd.setCursor(0, 1);
    lcd.println(" 42.00 ");
    delay(5000);
    lcd.setCursor(0, 1);
    delay(2000);
   
    

  }
if(content.substring(1) == "53 6F 25 24") 
    {
      p4++;
      total = total + 26.00;
    count_prod++;
    digitalWrite(buzzerPin, HIGH);
    
        delay(100);
        
        digitalWrite(buzzerPin, LOW);
        delay(100);
        digitalWrite(buzzerPin, HIGH);
        delay(100);
        digitalWrite(buzzerPin, LOW);
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("sandwich:");
    lcd.setCursor(0, 1);
    lcd.println(" 26.00 ");
    delay(5000);
    lcd.setCursor(0, 1);
    delay(2000);
   
    

  }
lcd.setCursor(0, 0);
lcd.println("BILL:-");
lcd.setCursor(0, 1);
lcd.println(total);
Serial.println("Your total BILL=");
Serial.println(total);
}