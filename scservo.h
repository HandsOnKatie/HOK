#pragma once
#include "esphome.h"

class SCBusServo : public Component, public UARTDevice {
 public:
  uint8_t servo_id = 1;
  float min_angle = 0.0f;
  float max_angle = 180.0f;
  const float SCALE = 5.12f;

  SCBusServo(UARTComponent *parent) : UARTDevice(parent) {}

  void setup() override;

  void write_angle(float deg) {
    if (deg < min_angle) deg = min_angle;
    if (deg > max_angle) deg = max_angle;

    uint16_t pos = (uint16_t) lroundf(deg * SCALE);

    uint8_t pkt[11];
    int i = 0;
    pkt[i++] = 0xFF;
    pkt[i++] = 0xFF;
    pkt[i++] = servo_id;
    pkt[i++] = 0x07;
    pkt[i++] = 0x03;  // WRITE
    pkt[i++] = 0x2A;  // GOAL_POS
    pkt[i++] = (uint8_t)(pos & 0xFF);
    pkt[i++] = (uint8_t)(pos >> 8);

    uint8_t sum = 0;
    for (int j = 2; j < i; ++j) sum += pkt[j];
    pkt[i++] = (uint8_t)(~sum);

    this->write_array(pkt, i);
    this->flush();
  }
};