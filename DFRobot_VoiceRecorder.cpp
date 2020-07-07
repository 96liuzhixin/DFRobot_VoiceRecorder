#include "DFRobot_VoiceRecorder.h"
/*
DFRobot_VoiceRecorder::DFRobot_VoiceRecorder()
{
}

DFRobot_VoiceRecorder::~DFRobot_VoiceRecorder()
{
}
*/

void DFRobot_VoiceRecorder::setButtonMode(uint8_t mode)
{
  sendBuf[0] = mode;
  writeData(BUTTON_REGISTER ,sendBuf ,1);
}

void DFRobot_VoiceRecorder::setLightMode(uint8_t mode)
{
  sendBuf[0] = mode;
  writeData(LIGHT_REGISTER ,sendBuf ,1);
}

void DFRobot_VoiceRecorder::setVoiceNumber(uint8_t number)
{
  sendBuf[0] = number;
  writeData(VOICE_NUMBER_REGISTER ,sendBuf ,1);
}

void DFRobot_VoiceRecorder::setRecordPlayState(uint8_t state)
{
  sendBuf[0] = state;
  writeData(RECORD_PLAY_REGISTER ,sendBuf ,1);
}

void DFRobot_VoiceRecorder::setVoiceState(uint8_t state)
{
  sendBuf[0] = state;
  writeData(EMPTY_DELETE_REGISTER ,sendBuf ,1);
}

uint8_t DFRobot_VoiceRecorder::recordvoiceStart(void)
{
  if(getRecording() == RECORDING_STATE) {
    return 2;                                // The current number is recording or playing. Please finish recording or playing first
  }else{
    if(getVoiceState() == EMPTY) {           // if number as is empty
      setRecordPlayState(RECORD_PLAY_START);
      return 1;
    }else{                                   // The current numbered sound is not empty. 
      return 0;
    }
  }
}

uint8_t DFRobot_VoiceRecorder::playVoiceStart(void)
{
  if(getPlaying() == PLAYING_STATE) {
    return 2;                               // The current number is recording or playing. Please finish recording or playing first
  }else{
    if(getVoiceState() == EMPTY) {
      return 0;                              // There are no songs in the current number
    }else{
      setRecordPlayState(RECORD_PLAY_START);
      return 1;
    }
  }
}

uint8_t DFRobot_VoiceRecorder::deleteVoice(void)
{
  if(getRecording() == RECORD_PLAY_START || getPlaying() == RECORD_PLAY_START) {
    return 2;                               // The current number is recording or playing. Please finish recording or playing first
  }else{
    if(getVoiceState() == EMPTY) {           // if number as is empty
      return 0;                              // You don't need to delete
    }else{
      setVoiceState(DELETE_VOICE);
      while(getVoiceState() == EMPTY)        // Waiting for deletion to complete
        delay(10);
      return 1;
    }
  }
}

uint8_t DFRobot_VoiceRecorder::recordVoiceEnd(void)
{
  if(getRecording() == RECORD_PLAY_END) {
    return 0;                                // No beginning
  }else{
    setRecordPlayState(RECORD_PLAY_END);
    return 1;
  }
}

uint8_t DFRobot_VoiceRecorder::playVoiceEnd(void)
{
  if(getPlaying() == RECORD_PLAY_END) {
    return 0;                                // No beginning no end
  }else{
    setRecordPlayState(RECORD_PLAY_END);
    return 1;
  }
}

uint8_t DFRobot_VoiceRecorder::getIICAddress(void)
{
  readData(IIC_ADDRESS_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getButtonMode(void){
  readData(BUTTON_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getLightMode(void)
{
  readData(LIGHT_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getVoiceNumber(void)
{
  readData(VOICE_NUMBER_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getRecordPlayState(void)
{
  readData(RECORD_PLAY_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}
uint8_t DFRobot_VoiceRecorder::getVoiceState(void)
{
  readData(EMPTY_DELETE_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getTimeRemaining(void)
{
  readData(TIMEREMAIN_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

uint8_t DFRobot_VoiceRecorder::getRecording(void)
{
  readData(RECORDING_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}
  
uint8_t DFRobot_VoiceRecorder::getPlaying(void)
{
  readData(PLAYING_REGISTER ,recvBuf ,1);
  return recvBuf[0];
}

DFRobot_VoiceRecorder_IIC::DFRobot_VoiceRecorder_IIC(TwoWire *pWire, uint8_t addr)
{
  _pWire = pWire;
  this->_IIC_addr = addr;
}

uint8_t DFRobot_VoiceRecorder_IIC::begin(void)
{
  _pWire->begin();
  _pWire->beginTransmission(_IIC_addr);
  if(_pWire->endTransmission() == 0)
    return 0;
  return 1;
}

void DFRobot_VoiceRecorder_IIC::writeData(uint8_t Reg ,uint8_t *Data ,uint8_t len)
{
  _pWire->beginTransmission(this->_IIC_addr);
  _pWire->write(Reg);
  for(uint8_t i = 0; i < len; i++)
    _pWire->write(Data[i]);
  _pWire->endTransmission();
}

uint8_t DFRobot_VoiceRecorder_IIC::readData(uint8_t Reg,uint8_t *Data,uint8_t len)
{
  int i=0;
  _pWire->beginTransmission(this->_IIC_addr);
  _pWire->write(Reg);
  _pWire->endTransmission();
  _pWire->requestFrom((uint8_t)this->_IIC_addr,(uint8_t)len);
  while (_pWire->available()){
    Data[i++]=_pWire->read();
  }
}