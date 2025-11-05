#include "scservo.h"
#include "esphome/core/log.h"

namespace esphome {
namespace scservo {
  static const char *const TAG = "scservo";
  void SCBusServo::setup() {
    ESP_LOGI(TAG, "SCBusServo ID=%d, range %.1f-%.1f°", servo_id, min_angle, max_angle);
  }
}  // namespace scservo
}  // namespace esphome
