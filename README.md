**Project Description**

The WiFi synched clock and climate monitoring project is an IoT-based project that monitors and displays real-time temperature and humidity levels from both local and online sources. It also keeps track of accurate time with the help of the NTP server API and an RTC module.
#Project Objectives
The objectives of this project are:
Get time updates from the Internet: The system should be able to connect to the Internet using a Wi-Fi module and periodically get the current time from an NTP server.
Read temperature and humidity values: The system should be able to read temperature and humidity values from a DHT11 sensor connected to the Arduino board.
Read time from an RTC module :The system should be able to read the current time from an RTC module connected to the Arduino board.
Get time updates from the NTP Server API: The system should be able to connect to the NTP Server API using a Wi-Fi module and periodically get the current time.
Get temperature and humidity updates from OpenWeatherMap: The system should be able to connect to the OpenWeatherMap API using a Wi-Fi module and periodically get the current temperature and humidity values.
Display values on an LCD screen: The system should be able to display the current time, temperature, and humidity values on a 16x2 LCD screen connected to the Arduino board.
Send data to an IoT dashboard: The system should be able to send the current time, temperature, and humidity values to an IoT dashboard for remote monitoring and analysis. The IoT dashboard should be able to display the values in a graphical format.
Update values periodically: The system should be abBy accomplishing the above objectives, this project will enable the user to monitor the current time, temperature, and humidity values remotely, making it useful for a range of applications, including home automation, weather monitoring, and indoor climate control.
le to update the current time, temperature, and humidity values periodically (e.g., every 10 seconds) on the LCD screen and IoT dashboard.

#Materials Required

Arduino board (Uno, Nano, etc.)
Real-time clock (RTC) module (e.g., DS1307, DS3231)
DHT11 temperature and humidity sensor
Wi-Fi module (e.g., ESP8266)
16x2 LCD display
Jumper wires
Breadboard
The purpose of an RTC or a real-time clock is to provide precise time and date which can be used for various applications.
The ESP8266 is a low-cost Wi-Fi microchip, with built-in TCP/IP networking software, and microcontroller capability
DHT11 Temperature & Humidity Sensor features a temperature & humidity sensor complex with a calibrated digital signal output. By using the exclusive digital-signal-acquisition technique and temperature & humidity sensing technology, it ensures high reliability and excellent long-term stability. This sensor includes a resistive-type humidity measurement component and an NTC temperature measurement component, and connects to a high performance 8-bit microcontroller, offering excellent quality, fast response, anti-interference ability and cost-effectiveness.
OpenWeather platform is a set of elegant and widely recognisable APIs. Powered by convolutional machine learning solutions, it is capable of delivering all the weather information necessary for decision-making for any location on the globe.
Software Required
Arduino IDE
WiFiNINA library
NTPClient library
DHT library
LiquidCrystal_I2C library
Adafruit IO Arduino library (for IoT dashboard)

#Implementation

The project is implemented as follows:
Connect the hardware components to the Arduino board as follows:
Set up the Arduino board and connect the DHT11 sensor, RTC module, and LCD screen to the board using jumper wires and a breadboard.
RTC module: Connect the VCC pin to 5V, GND pin to GND, SDA pin to A4, and SCL pin to A5.
DHT11 sensor: Connect the VCC pin to 5V, GND pin to GND, and data pin to digital pin 2.
LCD display: Connect the VSS pin to GND, VDD pin to 5V, VO pin to a 10k potentiometer's middle pin, RS pin to digital pin 12, RW pin to GND, E pin to digital pin 11, D4-D7 pins to digital pins 5-8.
Wi-Fi module: Connect the VCC pin to 3.3V, GND pin to GND, RX pin to TX, and TX pin to RX.
Install the required libraries in the Arduino IDE.
Connect to Wi-Fi:
Use the WiFi.begin() function to connect to a Wi-Fi network with your SSID and password.
Set up a WiFi connection using the WiFiNINA library.
Get time from the Internet:
Use the NTPClient library to get the time from an NTP server. You can set the time zone using the setTimeOffset() function. This allows the device to have accurate time readings.
Read temperature and humidity from DHT11 sensor:
Use the DHT.read() function to read temperature and humidity values from the sensor. You can convert the temperature value to Celsius using the DHT.temperature() function.
Read time from RTC module:
Use the RTC.now() function to read the current time from the RTC module.
Use the OpenWeatherMap API to retrieve current weather data from the internet. This provides online temperature and humidity readings.
Display values on the LCD:
Use the LiquidCrystal library to display the values on the LCD display.
Send data to IoT dashboard:
Use a third-party IoT dashboard service (e.g., Thingspeak, Blynk) to send the data to the cloud. You can use the Wi-Fi module and HTTP requests to send data to the dashboard. (Adafruit IO Arduino library to send the data to an IoT dashboard.)
Repeat the above steps periodically:
Use the delay() function to set a time interval (e.g., 10 seconds) and repeat the above steps periodically.

#Conclusion

By accomplishing the above objectives, this project will enable the user to monitor the current time, temperature, and humidity values remotely, making it useful for a range of applications, including home automation, weather monitoring, and indoor climate control.
Here are some potential use cases for the project:
Home Automation: The project can be used to monitor temperature and humidity levels in a home environment. This can be useful for controlling heating and cooling systems, and ensuring that the environment is comfortable and healthy.
Agriculture: The project can be used to monitor temperature and humidity levels in an agricultural setting, such as a greenhouse or farm. This can help to optimize plant growth and ensure that crops are healthy.
Weather Monitoring: The project can be used to monitor weather conditions in a specific location. This can be useful for weather enthusiasts, hobbyists, or professionals who need to collect accurate data.
IoT Dashboard: The project can be modified to send data to an IoT dashboard, allowing the data to be monitored remotely and accessed from anywhere. This can be useful for monitoring environmental conditions in a wide range of settings, such as offices, homes, factories, and warehouses.
Predictive analytics: The data collected from the project can be used to build predictive models that can forecast future temperature and humidity levels. This can be useful in agriculture, weather forecasting, and building automation.
Research: The project can be used as a basis for scientific research, particularly in fields such as climate science, environmental monitoring, and data analysis. The data collected can be analyzed and used to gain insights into various environmental factors and how they affect the world around us
# IOT-project
