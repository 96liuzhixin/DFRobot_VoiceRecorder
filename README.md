# DFRobot_VoiceRecorder
The recording module can record 10 sounds, 100 seconds each, which can be controlled by IIC and manually.

## DFRobot_VoiceRecorder
---------------------------------------------------------
DFRobot_VoiceRecorder


## Table of Contents

* [Summary](#Summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>


## Summary

You can set button mode, light mode, manual control number and IIC control, to achieve the recording function

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

  /**
   * @brief initialization parameters for i2c
   * @return 0 or 1, 0 is iic begin success, 1 is iic begin error
   */
  uint8_t begin();

  /**
   * @brief Set button mode
   * @param BUTTON_MODE_ON   0x00
   * @param BUTTON_MODE_OFF  0x01
   */
  void setButtonMode(uint8_t mode);

  /**
   * @brief Set light mode
   * @param LIGHT_MODE_OFF   0x00
   * @param LIGHT_MODE_ON    0x01
   */
  void setLightMode(uint8_t mode);

  /**
   * @brief set voice number
   * @param VOICE_NUMBER_0   0x00
   * @param VOICE_NUMBER_1   0x01
   * @param VOICE_NUMBER_2   0x02
   * @param VOICE_NUMBER_3   0x03
   * @param VOICE_NUMBER_4   0x04
   * @param VOICE_NUMBER_5   0x05
   * @param VOICE_NUMBER_6   0x06
   * @param VOICE_NUMBER_7   0x07
   * @param VOICE_NUMBER_8   0x08
   * @param VOICE_NUMBER_9   0x09
   */
  void setVoiceNumber(uint8_t number);

  /**
   * @brief get iic device address
   * @return iic device address
   */
  uint8_t getIICAddress();

  /**
   * @brief get Button Mode
   * @return Mode 
   *    BUTTON_MODE_ON   0x00
   *    BUTTON_MODE_OFF  0x01
   */
  uint8_t getButtonMode(void);
  
  /**
   * @brief get light Mode
   * @return Mode 
   *    LIGHT_MODE_OFF   0x00
   *    BUTTON_MODE_OFF  0x01
   */
  uint8_t getButtonMode(void);

  /**
   * @brief get voice number
   * @return number 
   *    VOICE_NUMBER_0   0x00
   *    VOICE_NUMBER_1   0x01
   *    VOICE_NUMBER_2   0x02
   *    VOICE_NUMBER_3   0x03
   *    VOICE_NUMBER_4   0x04
   *    VOICE_NUMBER_5   0x05
   *    VOICE_NUMBER_6   0x06
   *    VOICE_NUMBER_7   0x07
   *    VOICE_NUMBER_8   0x08
   *    VOICE_NUMBER_9   0x09
   */
  uint8_t getVoiceNumber(void);

  /**
   * @brief get voice state
   * @return state 0 is Current position has audio 1 is empty
   */
  uint8_t getVoiceState(void);

  /**
   * @brief get time reamaining
   * @return The time range is 0-100
   */
  uint8_t getTimeRemaining();

  /**
   * @brief start record
   * @return 1 is start record ,2 is repeat recording or playback,0 is Audio already exists, delete and record
   */
  uint8_t recordvoiceStart(void);

  /**
   * @brief start play
   * @return 1 is start play ,2 is repeat recording or playback,0 is no songs in the current number
   */
  uint8_t playVoiceStart(void);

  /**
   * @brief delete voice
   * @return 1 is delete success ,2 is repeat recording or playback,0 is no songs in the current number
   */
  uint8_t deleteVoice(void);

  /**
   * @brief End of the tape
   * @return 1 is end success ,0 is no begin record
   */
  uint8_t recordVoiceEnd(void);

  /**
   * @brief End play
   * @return 1 is end success ,0 is no begin record
   */
  uint8_t playVoiceEnd(void);

```
## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560           |      √       |              |             | 
Lenardo            |      √       |              |             | 
ESP32              |      √       |              |             | 

## History

-  May 21, 2020 - Version 1.0 released.

## Credits

Written by kaixingPeng(kaixing.peng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))