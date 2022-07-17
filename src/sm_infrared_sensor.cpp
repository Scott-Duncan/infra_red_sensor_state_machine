#include "infrared_sensor_state_machine/sm_infrared_sensor.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "InfraredSensorSM");
    smacc::run<sm_infrared_sensor::SmInfraRedSensor>();
}
