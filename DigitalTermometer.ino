#include <microDS18B20.h> // To import microDS18B20 follow this URL: https://github.com/GyverLibs/microDS18B20
#include <LiquidCrystal.h>

uint8_t addr[] = {0x28, 0x7F, 0xB2, 0xBF, 0x0, 0x0, 0x0, 0x65};
// to define your sensor address follow these steps: https://github.com/GyverLibs/microDS18B20?tab=readme-ov-file#%D1%87%D1%82%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B0%D0%B4%D1%80%D0%B5%D1%81%D0%B0

MicroDS18B20 <A0, addr> sensor;
float tempCelsius = 0;
float tempKelvin = 0;
float tempFahrenheit = 0;
float tempReaumur = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte smallDegreeChar[] = { 6, 9, 9, 6, 0, 0, 0, 0 };
// b00110
// b01001
// b01001
// b00110
// b00000
// b00000
// b00000
// b00000

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, smallDegreeChar);
}

void loop() {
  static uint32_t timer = millis();
  if(millis() - timer >= 1000) {
    timer = millis();
    if(sensor.readTemp()) {
      tempCelsius = sensor.getTemp();
      tempKelvin = celsiusToKelvin(tempCelsius);
      tempFahrenheit = celsiusToFahrenheit(tempCelsius);
      tempReaumur = celsiusToReaumur(tempCelsius);
      lcd.clear();
      displayAllTemperatures(tempCelsius, tempKelvin, tempFahrenheit, tempReaumur);
    }
    sensor.requestTemp();
  }
}

float celsiusToKelvin(float tempCelsius) {
  return tempCelsius + 273.15;
}

float celsiusToFahrenheit(float tempCelsius) {
  return tempCelsius * 9 / 5 + 32;
}

float celsiusToReaumur(float tempCelsius) {
  return tempCelsius * 0.8;
}

void displayAllTemperatures(float tempCelsius, float tempKelvin, float tempFahrenheit, float tempReaumur) {
  displayTemperature(0, 0, tempCelsius, 'C');
  displayTemperature(8, 0, tempKelvin, 'K');
  displayTemperature(0, 1, tempFahrenheit, 'F');
  displayTemperature(8, 1, tempReaumur, 'R');
}

void displayTemperature(uint8_t startSymbol, uint8_t startRow, float temp, char shortScaleName) {
  lcd.setCursor(startSymbol, startRow);
  displaySignFor(temp);
  lcd.print(temp, 1);
  lcd.write((uint8_t)0);
  lcd.print(shortScaleName);
}

void displaySignFor(float temp) {
  if (temp > 0) {
    lcd.print("+");
  }
}