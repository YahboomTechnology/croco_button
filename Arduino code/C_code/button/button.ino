/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         button
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Button control doorbell
* @details
* @par History  
*
*/

#define Ding 1322
#define Dong 1049


int buzzer = 13;//Set the digital IO pin for controlling the buzzer
int button = 4;//Define the number 4 interface as the key interface
int val;//Define val
int i = 0;

/*DingDong*/
int tune[]=   //List each frequency according to the notation
{
  Ding, Dong,
};

float durt[]= //List each durt according to the notation
{
  1, 2,
};

/*
* Function       PlayTest
* @author        Jessica
* @date          2019.8.21
* @brief         Play music
* @param[in]     void
* @retval        void
* @par History   no
*/
void PlayTest()
{
 int length = sizeof(tune)/sizeof(tune[0]);   
 for(int x=0; x < length;x++)
  {
    tone(buzzer,tune[x]);
    delay(500*durt[x]);   
    noTone(buzzer);
  }
  
}

/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup() 
{ 
    Serial.begin(9600);
    pinMode(buzzer,OUTPUT);
    pinMode(button,INPUT);
    digitalWrite(button ,HIGH);
} 

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         mian function
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{ 
    val=digitalRead(button);//Read digital level 2 and assign it to val
    if(val==LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
    {
        Serial.println("high");//Serial port prints "high" string
        PlayTest();  //Call the doorbell function
        delay(2000); //delay 2s
     }
     else
     {
        Serial.println("low");//Serial port prints "low" string
     }
}
