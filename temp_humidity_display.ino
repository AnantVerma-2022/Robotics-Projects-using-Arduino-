// Import Libraries
#include <LiquidCrystal_I2C.h>
#include <dht.h>  
#include <Wire.h>  

// Declare dht_output pin    
#define outPin 8        

// Creates a DHT object
dht DHT; 

// Initialize the LCD with I2C address 0x27 and a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);               

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();  
  
  // Turn on the backlight                   
  lcd.backlight(); 

  // Set cursor at (0,0)              
  lcd.setCursor(0, 0);

  // Display initial message
  lcd.print("Initializing...");   
  delay(2000); 

  // Clear the LCD
  lcd.clear();                    
}

void loop() {

  // Read data from the DHT sensor
  int readData = DHT.read11(outPin);

  // Read temperature
  float t = DHT.temperature; 
  
  // Read humidity
  float h = DHT.humidity;

             
  // Display temperature and humidity on the Serial Monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");

  // Convert celsius to fahrenheit
  Serial.print((t*9.0)/5.0+32.0);        
  Serial.println("°F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

   // Display temperature and humidity on the I2C LCD
  lcd.setCursor(0, 0);              // Set cursor to the first line
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C ");

  lcd.setCursor(0, 1);              // Set cursor to the second line
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");

  delay(2000); // wait two seconds
}
