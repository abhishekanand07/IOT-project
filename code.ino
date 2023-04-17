#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define DHTPIN 2
#define DHTTYPE DHT11

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

const String openWeatherMapApiKey = "YOUR_OPENWEATHERMAP_API_KEY";
const String openWeatherMapLocation = "YOUR_LOCATION";
const String openWeatherMapUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + openWeatherMapLocation + "&appid=" + openWeatherMapApiKey + "&units=metric";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, gmtOffset_sec, daylightOffset_sec);
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  delay(5000);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  timeClient.begin();
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Syncing time...");
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  lcd.clear();
  lcd.print("Time synced!");
  delay(5000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  String currentTime = timeClient.getFormattedTime();
  String currentWeather = getCurrentWeather();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: " + currentTime);
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(temperature) + "C  Hum: " + String(humidity) + "%");
  delay(10000);
}

String getCurrentWeather() {
  HTTPClient http;
  http.begin(openWeatherMapUrl);
  int httpResponseCode = http.GET();
  String payload = "{}";
  if (httpResponseCode > 0) {
    payload = http.getString();
  }
  http.end();
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, payload);
  JsonObject main = doc["main"];
  float temperature = main["temp"];
  int humidity = main["humidity"];
  return "Temp: " + String(temperature) + "C  Humidity: " + String(humidity) + "%";
}
