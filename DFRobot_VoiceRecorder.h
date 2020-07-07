#ifndef __DFRobot_VOICERECORDER_H__
#define __DFRobot_VOICERECORDER_H__
#include <Arduino.h>
#include <Wire.h>


#define BUTTON_MODE_ON         0
#define BUTTON_MODE_OFF        1

#define LIGHT_MODE_ON          1
#define LIGHT_MODE_OFF         0

#define VOICE_NUMBER_0         0
#define VOICE_NUMBER_1         1
#define VOICE_NUMBER_2         2
#define VOICE_NUMBER_3         3
#define VOICE_NUMBER_4         4
#define VOICE_NUMBER_5         5
#define VOICE_NUMBER_6         6
#define VOICE_NUMBER_7         7
#define VOICE_NUMBER_8         8
#define VOICE_NUMBER_9         9

#define EMPTY                  1
#define NO_EMPTY               0
#define RECORD_PLAY_START      1
#define RECORD_PLAY_END        0
#define DELETE_VOICE           1

#define RECORDING_STATE        1
#define RECORDEND_STATE        0

#define PLAYING_STATE          1
#define PLAYEND_STATE          0

#define IIC_ADDRESS_REGISTER   0x00
#define BUTTON_REGISTER        0x01
#define LIGHT_REGISTER         0x02
#define VOICE_NUMBER_REGISTER  0x03
#define RECORD_PLAY_REGISTER   0x04
#define EMPTY_DELETE_REGISTER  0x05
#define TIMEREMAIN_REGISTER    0x06
#define RECORDING_REGISTER     0x07
#define PLAYING_REGISTER       0x08

class DFRobot_VoiceRecorder{
public:
  DFRobot_VoiceRecorder(){};
  ~DFRobot_VoiceRecorder(){};
  
  void setButtonMode(uint8_t mode);
  void setLightMode(uint8_t mode);
  void setVoiceNumber(uint8_t number);
  void setRecordPlayState(uint8_t state);
  void setVoiceState(uint8_t state);
  
  uint8_t recordvoiceStart(void);
  uint8_t playVoiceStart(void);
  uint8_t deleteVoice(void);
  uint8_t recordVoiceEnd(void);
  uint8_t playVoiceEnd(void);
  
  uint8_t getRecording(void);
  uint8_t getPlaying(void);
  uint8_t getIICAddress(void);
  uint8_t getButtonMode(void);
  uint8_t getLightMode(void);
  uint8_t getRecordPlayState(void);
  uint8_t getVoiceNumber(void);
  uint8_t getVoiceState(void);
  uint8_t getTimeRemaining(void);
  uint8_t sendBuf[10] = {0};
  uint8_t recvBuf[10] = {0};
protected:
  virtual uint8_t readData(uint8_t Reg,uint8_t *Data,uint8_t len)=0;
  virtual void writeData(uint8_t Reg,uint8_t *Data ,uint8_t len)=0;
};

class DFRobot_VoiceRecorder_IIC:public DFRobot_VoiceRecorder{
public:
  DFRobot_VoiceRecorder_IIC(TwoWire *pWire=&Wire ,uint8_t addr=0x30);
  ~DFRobot_VoiceRecorder_IIC(){};
  void writeData(uint8_t Reg,uint8_t *Data,uint8_t len);
  uint8_t readData(uint8_t Reg,uint8_t *Data,uint8_t len);
  uint8_t begin();
private:
  TwoWire *_pWire;
  uint8_t _IIC_addr;
};
#endif