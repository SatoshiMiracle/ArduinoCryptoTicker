#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
String inBytes;
String previousBytes;

void setup() {
    lcd.init();
    lcd.backlight();
    pinMode(2, OUTPUT); //BUZZER
    pinMode(4, OUTPUT); //GREEN LED
    pinMode(5, OUTPUT); //RED LED
    previousBytes = "0";
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        inBytes = Serial.readStringUntil('\n');
        lcd.setCursor(2, 0);
        lcd.print("BTC: $");
        lcd.print(inBytes);

        previousBytes = previousBytes.toInt();
        inBytes = previousBytes.toInt();
        
        if (previousBytes > inBytes) {
            digitalWrite(5, HIGH);
            tone(2, 1000);
            delay(1000);
            digitalWrite(5, LOW);
            lcd.clear();
            noTone(2);
        }

        else {
            digitalWrite(4, HIGH);
            delay(1000);
            digitalWrite(4, LOW);
            lcd.clear();
        }

        previousBytes = inBytes;
}
