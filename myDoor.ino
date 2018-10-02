#define RelPin 3
#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define KEY "Code"
#include <SoftwareSerial.h>
SoftwareSerial BT1(4,2); // RX, TX
 
void setup()
	{
		Serial.begin(38400);
		BT1.begin(9600);
	}

void loop()
	{
		char get_char = ' ';  // Para leer BT1
		if (BT1.available()>0){			
			get_char = BT1.read();
			delay(25);
			if (get_char != START_CMD_CHAR){
				return;
			}
			else {
				String s = GetLine();
				Serial.println(s);
				if (s == KEY){
          digitalWrite(RelPin, HIGH);
				}
			}
		}
   digitalWrite(RelPin, LOW);
}

String GetLine()
	{	String S = "" ;
		if (BT1.available())
			{  char c = BT1.read(); ;
				while ( c != END_CMD_CHAR)	 //Hasta que el caracter sea END_CMD_CHAR
				  {  S = S + c ;
					  delay(25) ;
					  c = BT1.read();
				  }
				return( S ) ;
			}
	}
