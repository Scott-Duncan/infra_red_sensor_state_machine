#include "infrared_sensor_state_machine/orthogonals/or_arduino_infrared_sensor.hpp"

namespace sm_infrared_sensor {
void OrArduinoInfraredSensor::onInitialize() {
  auto  arduino_infrared_sensor_client= this->createClient<ClArduinoInfraredSensor>("/sensor_activate");
  rfid_client->initialize();
}
}  // namespace fox_rt