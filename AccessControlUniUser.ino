/* A program for an access control system with only 1 authorised user
  Developed by Arunav and Team
*/

#include <LiquidCrystal.h>
char input[12];				
int count = 0;

char tag1[]="14006D221C47";
//char tag2[]="14006CAB24F7";

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
    boolean match = 1;
    digitalWrite(13, HIGH);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Hi, WELCOME");
    lcd.setCursor(0,1);
    lcd.print("Place your Card");
    delay(2000);
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
                Serial.println();
        
                int j= 0;
                while (match==1 && j<12){
                  
                    if(tag1[j]==input[j]){
                      match=1;
                      j++;
                    }
                    else
                    match=0;
                    
                }
                if (match == 1){
                  lcd.clear();
                  lcd.setCursor(0,0);
		  lcd.print("Card Accepted !");
                  lcd.setCursor(0,1);
                  lcd.print("You May Enter");
                  delay(1000);
                  digitalWrite(13, LOW);
                  digitalWrite(12, HIGH);
                  delay(3000);
                  digitalWrite(12, LOW);
                }
                else{
                  lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Unauthorished");
                  lcd.setCursor(4,1);
                  lcd.print("Access");
                  delay(2000);
                }
              }
                
               
        }
   




