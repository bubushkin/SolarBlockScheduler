/*
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <softPwm.h>
#include <math.h>
#include <wiringPiI2C.h>
#include <ads1115.h>
#include <pcf8591.h>
#define ledPin 0x00

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

#define ledPin 0
#define Z_PIN 1

//https://create.arduino.cc/projecthub/instrumentation-system/acs712-current-sensor-87b4a6#:~:text=ACS712%20is%20a%20current%20sensor,on%20both%20AC%20and%20DC.&text=The%20output%20of%20this%20current,Read%20pin%20or%20ADC%20pin

#define motorPin1 2
#define motorPin2 0
#define enablePin 3


int _fd;
int address;
int cmd;


//map the value from a range to another range;
long map(long value, long fromLow, long fromHigh, long toLow, long toHigh){
    return (toHigh - toLow) * (value - fromLow) / (fromHigh - fromLow) + fromLow;
}

void motor(int ADC){
    int value = ADC - 128;
    if(value > 0){
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        printf("Rotate Forward\n");

    } else if(value < 0){
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        printf("Rotate Backwards\n");

    } else{
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        printf("Motor STOP\n");
    }
    softPwmWrite(enablePin, map(abs(value), 0, 128, 0, 100));
    printf("The PWM cycle is %d%%\n", abs(value) * 100 / 127);

}
void setup(void){

    softPwmCreate(ledPinRed, 0, 100);
    softPwmCreate(ledPinGreen, 0, 100);
    softPwmCreate(ledPinBlue, 0, 100);
}

void setLedColor(int r, int g, int b){
    softPwmWrite(ledPinRed, r);
    softPwmWrite(ledPinGreen, g);
    softPwmWrite(ledPinBlue, b);
}

int detectI2C(int address){
    _fd = wiringPiI2CSetup(address);
    if(_fd < 0){
        printf("Error address: 0x%x \n", address);
        return 0;
    } else{
        if(wiringPiI2CWrite(_fd, 0x0) < 0x0){
            printf("No device found at address 0x%x\n", address);
            return 0;
        } else{
            printf("Found device at address 0x%x\n", address);
            return 1;
        }
    }
}


PCF8591(int addr)
{
    address = addr;
    cmd = 0x40;         //The default command for PCF8591 is 0x40.
    wiringPiSetup();
    detectI2C(address);
    printf("PCF8591 setup successful! \n");
}
int PCF8591_analogRead(int chn){
    wiringPiI2CWrite(_fd, cmd+chn);
    wiringPiI2CRead(_fd);
    wiringPiI2CWrite(_fd, cmd+chn);
    return wiringPiI2CRead(_fd);
}
int PCF8591_analogWrite(int value){
    return wiringPiI2CWriteReg8(_fd, cmd, value);
}

int main() {

#define BASE 120
#define A0 BASE+0
#define A1 BASE+0
#define A2 BASE+0
#define A3 BASE+0
    if(detectI2C(0x48)){
        wiringPiSetup();
        pcf8591Setup(BASE,0x48);
        while(1)
        {
            int value = analogRead(A0);
            float voltage = value * 5.0 / 255;
            float current = (voltage - 2.5) / 0.066;
            printf("AOUT: %d VOLTAGE: %f CURRENT: %f\n",value, voltage, current);
            delay(500);
        }
    }

    return 0;

//    if(detectI2C(0x48)){
//        PCF8591(0x48);
//        wiringPiSetup();
//        pinMode(Z_PIN, INPUT);
//        pullUpDnControl(Z_PIN, PUD_UP);
//        while(1){
//            int z_val = digitalRead(Z_PIN);
//            int y_val = PCF8591_analogRead(0);
//            int x_val = PCF8591_analogRead(1);
//            printf("x: %d, y: %d, z: %d \n", x_val, y_val, z_val);
//            delay(100);
//        }
//    }
//
//    return 0;

//    if(detectI2C(0x48)){
//        PCF8591(0x48);
//        wiringPiSetup();
//        softPwmCreate(ledPin, 0, 100);
//        while(1){
//            int adcValue = PCF8591_analogRead(0);
//            softPwmWrite(ledPin, adcValue * 100/255);
//            float voltage = (float) adcValue / 255.0 * 3.3;
//            printf("ADC Value: %d, \tVoltage: %.2fV\n", adcValue, voltage);
//            delay(100);
//        }
//    }
//
//    return 0;


//    wiringPiSetup();
//
//    setup();
//
//    while(1){
//        int r = random() % 100;
//        int g = random() % 100;
//        int b = random() % 100;
//
//        setLedColor(r, g, b);
//        printf("r: %d, g: %d, b: %d\n", r, g, b);
//        delay(300);
//
//    }


//    printf("Program is starting..");
//    wiringPiSetup();
//
//    softPwmCreate(ledPin, 0, 100);
//
//    while(1){
//        for(int i = 0; i < 100; i++){
//            softPwmWrite(ledPin, i);
//            delay(20);
//        }
//        delay(300);
//        for(int i = 100; i > 0; i--){
//            softPwmWrite(ledPin, i);
//            delay(20);
//        }
//        delay(300);
//    }


//    printf("Starting..\n");
//    wiringPiSetup();
//
//    for(int i = 0; i < ledCounts; i++)
//        pinMode(pins[i], OUTPUT);
//
//    while(1){
//        for(int i = 0; i < ledCounts; i++){
//            digitalWrite(pins[i], HIGH);
//            delay(100);
//
//        }
//
//        for(int i = ledCounts; i > -1; i--){
//            digitalWrite(pins[i], LOW);
//            delay(100);
//        }
//
//    }


//    printf("Starting Button LED\n");
//
//    wiringPiSetup();
//
//    pinMode(ledPin, OUTPUT);
//    pinMode(buttonPin, INPUT);
//
//    pullUpDnControl(buttonPin, PUD_UP);
//
//    while(1){
//        if(digitalRead(buttonPin) == LOW){
//            digitalWrite(ledPin, HIGH);
//            printf("Button is pressed\n");
//        } else{
//            digitalWrite(ledPin, LOW);
//            printf("Button is released\n");
//        }
//    }

}
*/