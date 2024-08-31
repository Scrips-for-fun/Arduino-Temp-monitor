#include <DHT.h>

// Define the pin where the DHT11 data line is connected
#define DHTPIN 2

// Define the type of DHT sensor being used
#define DHTTYPE DHT11

// Create an instance of the DHT class
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read humidity (percent)
  float humidity = dht.readHumidity();

  // Read temperature in Celsius
  float temperatureC = dht.readTemperature();

  // Convert temperature to Fahrenheit
  float temperatureF = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print humidity and temperature in Fahrenheit to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println(" *F");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" *C");
}
// You need to open Serial monitor, Go to tools, and scroll down to Serial moniter, click it, and your good :)
