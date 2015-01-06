// MFButton.cpp
//
// Copyright (C) 2013-2014

#include "MFButton.h"

MFButton::MFButton(uint8_t pin, String name)
{   
  _pin  = pin;
  _name = name;
  _state = 1;
  pinMode(_pin, INPUT);     // set pin to input
  digitalWrite(_pin, HIGH); // turn on pullup resistors
}

void MFButton::update()
{
    byte newState = digitalRead(_pin);
    if (newState!=_state) {     
      _state = newState;
      if (newState==LOW && _handlerList[btnOnPress]!= NULL) {
        (*_handlerList[btnOnPress])(btnOnPress, _pin, _name);
      }
      else if (_handlerList[btnOnRelease]!= NULL)
        (*_handlerList[btnOnRelease])(btnOnRelease, _pin, _name);
    }
}

void MFButton::attachHandler(byte eventId, buttonEvent newHandler)
{
  _handlerList[eventId] = newHandler;
}