/* 
 * @file setVoiceNumber.ino
 * @You can see the value of the digital tube changing from 0-9-0.
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      [ZhixinLiu](zhixin.liu@dfrobot.com)
 * @version  V0.1
 * @date  2020-7-1
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_VoiceRecorder.git
 */
#include "DFRobot_VoiceRecorder.h"

#define I2C_ADDRESS  0x30                                         // default IIC device address is 0x30
DFRobot_VoiceRecorder_IIC voicerecorder(&Wire, I2C_ADDRESS);      // i2c configuration parameters
int setVNumber = 4;
void setup()
{
  Serial.begin(115200);
  pinMode(setVNumber , INPUT);
  while(voicerecorder.begin() != 0) {
    Serial.println("I2c device number error");
    delay(1000);
  }

/*
  Set button mode on or off
    BUTTON_MODE_ON   0x00
    BUTTON_MODE_OFF  0x01
*/
  voicerecorder.setButtonMode(BUTTON_MODE_ON);

/*
  Set light mode on or off
    LIGHT_MODE_ON    0x01
    LIGHT_MODE_OFF   0x00
*/
  voicerecorder.setLightMode(LIGHT_MODE_ON);

/*
  Set the audio number
    VOICE_NUMBER_0    0x00
    VOICE_NUMBER_1    0x01
    VOICE_NUMBER_2    0x02
    VOICE_NUMBER_3    0x03
    VOICE_NUMBER_4    0x04
    VOICE_NUMBER_5    0x05
    VOICE_NUMBER_6    0x06
    VOICE_NUMBER_7    0x07
    VOICE_NUMBER_8    0x08
    VOICE_NUMBER_9    0x09
*/
  voicerecorder.setVoiceNumber(VOICE_NUMBER_0);
}

void loop()
{
  static uint8_t   numbers = 0;
  if(digitalRead(setVNumber)) {
    if(numbers >= 9) numbers = 0;
    else             numbers++;
    voicerecorder.setVoiceNumber(numbers);
    delay(200);
  }
}