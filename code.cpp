#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
#include <SoftwareSerial.h>
// include the library code:
int sensepin = A1;

#include <stdlib.h>
#include <dht.h>
#define dht_dpin A0 
int mois1;

int i, j;
dht DHT;
char buf1[16];
char buf2[16];
char buf3[16];
char buf4[16];
String strmois1;

String stri;
String strj;
String apiKey = "USJOYY5VJ3WSLAA9";


SoftwareSerial ser(5, 6); // RX, TX

void setup()
{
// Initialize the IO and ISR
 pinMode(4, OUTPUT);        //motor
      digitalWrite(4, HIGH);
       pinMode(3, OUTPUT);        //motor
      digitalWrite(3, LOW);
       pinMode(2, OUTPUT);        //buzzer
      digitalWrite(2, LOW);
       analogReference(DEFAULT);
 lcd.begin(16,2);

      Serial.begin(9600);
       delay(800);
      ser.begin(115200);
  // reset ESP8266
  ser.println("AT+RST");
   delay(800);
  ser.println("AT+CWMODE=3");
   delay(800);
  ser.println("AT+CWJAP=\"project\",\"12345678\"");
  delay(800);
}
void loop()
{
 DHT.read11(dht_dpin);
      

 i=DHT.humidity;
      j =DHT.temperature;
     

mois1 = analogRead(A1); //mois1
mois1= map(analogRead(A1), 0, 1023, 100, 0);
lcd.setCursor(0, 0);
    lcd.print("M: ");
 lcd.print(mois1);

  lcd.print("% ");

  lcd.setCursor(0, 1);
    lcd.print("H:");
 lcd.print(i);
 lcd.print("%   ");
lcd.print("T:");
 lcd.print(j);
  lcd.print("C ");
  strmois1 = dtostrf(analogRead(A1), 4, 1, buf1);

// convert to string
 

  // convert to string

  stri = dtostrf(i, 4, 1, buf3);
strj = dtostrf(j, 4, 1, buf4);
  
  Serial.print(strmois1);
  Serial.print(" ");

    
    Serial.print(stri);
  Serial.print(" ");
   Serial.print(strj);
  Serial.print(" ");
  // TCP connection
  String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += "184.106.153.149"; // api.thingspeak.com
  cmd1 += "\",80";
  ser.println(cmd1);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr1 = "GET /update?api_key=";
  getStr1 += apiKey;
  getStr1 +="&field1=";
  getStr1 += String(strmois1);
  getStr1 += "\r\n\r\n";



  // send data length
  cmd1 = "AT+CIPSEND=";
  cmd1 += String(getStr1.length());
  ser.println(cmd1);

   

  if(ser.find(">")){
    ser.print(getStr1);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
  
      
          if(analogRead(sensepin)>500)    //no mois
          {
            
            digitalWrite(4, LOW);
      //      lcd.setCursor(0,1);
    //  lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            digitalWrite(4, HIGH);
      //      lcd.setCursor(0,1);
     // lcd.print("Motor Off");
     
           
          }    
      
  delay(16000);
    if(analogRead(sensepin)>500)    //no mois
          {
            
            digitalWrite(4, LOW);
          //  lcd.setCursor(0,1);
    //  lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            digitalWrite(4, HIGH);
         //   lcd.setCursor(0,1);
    //  lcd.print("Motor Off");
     
           
          }    
      

       

        
         
    DHT.read11(dht_dpin);
      

 i=DHT.humidity;
      j =DHT.temperature;
    

mois1 = analogRead(A1); //mois1
mois1= map(analogRead(A1), 0, 1023, 100, 0);
lcd.setCursor(0, 0);
    lcd.print("M: ");
 lcd.print(mois1);

  lcd.print("% ");

  lcd.setCursor(0, 1);
    lcd.print("H:");
 lcd.print(i);
 lcd.print("%   ");
lcd.print("T:");
 lcd.print(j);
  lcd.print("C ");
  strmois1 = dtostrf(analogRead(A1), 4, 1, buf1);

// convert to string
 

  // convert to string

  stri = dtostrf(i, 4, 1, buf3);
strj = dtostrf(j, 4, 1, buf4);
  
  Serial.print(strmois1);
  Serial.print(" ");

    
    Serial.print(stri);
  Serial.print(" ");
   Serial.print(strj);
  Serial.print(" ");
  // TCP connection
  String cmd3 = "AT+CIPSTART=\"TCP\",\"";
  cmd3 += "184.106.153.149"; // api.thingspeak.com
  cmd3 += "\",80";
  ser.println(cmd3);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr3 = "GET /update?api_key=";
  getStr3 += apiKey;
  getStr3 +="&field2=";
  getStr3 += String(stri);
  getStr3 += "\r\n\r\n";



  // send data length
  cmd3 = "AT+CIPSEND=";
  cmd3 += String(getStr3.length());
  ser.println(cmd3);

   

  if(ser.find(">")){
    ser.print(getStr3);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
  
       
       
          if(analogRead(sensepin)>500)    //no mois
          {
            
            digitalWrite(4, LOW);
     //       lcd.setCursor(0,1);
     // lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            digitalWrite(4, HIGH);
     //       lcd.setCursor(0,1);
    //  lcd.print("Motor Off");
     
           
          }    
      
  delay(16000);
  
       
       
          if(analogRead(sensepin)>500)    //no mois
          {
            
            digitalWrite(4, LOW);
       //     lcd.setCursor(0,1);
     // lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            digitalWrite(4, HIGH);
     //       lcd.setCursor(0,1);
     // lcd.print("Motor Off");
     
           
          }    
      
   DHT.read11(dht_dpin);
      

 i=DHT.humidity;
      j =DHT.temperature;
    

mois1 = analogRead(A1); //mois1
mois1= map(analogRead(A1), 0, 1023, 100, 0);
lcd.setCursor(0, 0);
    lcd.print("M: ");
 lcd.print(mois1);

  lcd.print("% ");

  lcd.setCursor(0, 1);
    lcd.print("H:");
 lcd.print(i);
 lcd.print("%   ");
lcd.print("T:");
 lcd.print(j);
  lcd.print("C ");
  strmois1 = dtostrf(analogRead(A1), 4, 1, buf1);

// convert to string
 

  // convert to string

  stri = dtostrf(i, 4, 1, buf3);
strj = dtostrf(j, 4, 1, buf4);
  
  Serial.print(strmois1);
  Serial.print(" ");

    
    Serial.print(stri);
  Serial.print(" ");
   Serial.print(strj);
  Serial.print(" ");
  // TCP connection
  String cmd4 = "AT+CIPSTART=\"TCP\",\"";
  cmd4 += "184.106.153.149"; // api.thingspeak.com
  cmd4 += "\",80";
  ser.println(cmd4);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr4 = "GET /update?api_key=";
  getStr4 += apiKey;
  getStr4 +="&field3=";
  getStr4 += String(strj);
  getStr4 += "\r\n\r\n";



  // send data length
  cmd4 = "AT+CIPSEND=";
  cmd4 += String(getStr4.length());
  ser.println(cmd4);

   

  if(ser.find(">")){
    ser.print(getStr4);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
    if(analogRead(sensepin)>500)    //no mois
          {
            Serial.println("no mois");
            digitalWrite(4, LOW);
      //      lcd.setCursor(0,1);
     // lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            Serial.println("mois");
            digitalWrite(4, HIGH);
     //       lcd.setCursor(0,1);
    //  lcd.print("Motor Off");
     
           
          } 
  delay(16000);
 
     
       
      
          if(analogRead(sensepin)>500)    //no mois
          {
            
            digitalWrite(4, LOW);
      //      lcd.setCursor(0,1);
     // lcd.print("Motor On  "); 
          
                
          }
          else if(analogRead(sensepin)<800)   //mois
          {
            digitalWrite(4, HIGH);
     //       lcd.setCursor(0,1);
    //  lcd.print("Motor Off");
     
           
          }    
      
     


}