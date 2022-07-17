#include <include/infra_red_sensor_state_machine/orthogonols/or_arduino_infrared_seonsor.hpp>

namespace sm_infra_red_sensor {
void OrArduinoInfraredSensor::onInitialize() {
  auto  arduino_infrared_sensor_client= this->createClient<ClArduinoInfraredSensor>("/sensor_activate");
  rfid_client->initialize();
}
}  // namespace fox_rt