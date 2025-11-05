#include "scservo.h"
#include "esphome/core/log.h"

namespace esphome {
namespace scservo {

static const char *const TAG = "scservo";

void SCBusServo::setup() {
  ESP_LOGI(TAG, "SCBusServo initialized (ID=%d, range %.1f-%.1f°)",
           this->servo_id, this->min_angle, this->max_angle);
}

}  // namespace scservo
}  // namespace esphome