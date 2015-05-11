/* A program that allows any user having an RFID card to gain access
Developed by arunav and team
*/
#include <LiquidCrystal.h>
char input[12];				
int count = 0;

LiquidCrystal lcd(4,5,6,7,8,9);

void setup() {
  //serial monitor
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
}


void loop() {
    digitalWrite(13, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hi, WELCOME");
    lcd.setCursor(0,1);
    lcd.print("Place your Card");
    delay(1000);
    if(Serial.available())// check serial data ( RFID reader)
	{
		count = 0; // Reset the counter to zero
		/* Keep reading Byte by Byte from the Buffer till the RFID Reader Buffer is	empty 
		   or till 12 Bytes (the ID size of our Tag) is read */
		while(Serial.available() && count < 12) 
		{
			input[count] = Serial.read(); // Read 1 Byte of data and store it in the input[] variable
			count++; // increment counter
			delay(5);
		}
                Serial.println("I received: ");
                for(int i=0;i<12;i++)
                Serial.print(input[i]);
		Serial.println();
                lcd.clear();
		lcd.print("Card Recieved");
                delay(1000);
                digitalWrite(13, LOW);
                digitalWrite(12, HIGH);
                delay(3000);
                digitalWrite(12, LOW);
        }
   

}


