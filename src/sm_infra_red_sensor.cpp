#include <infra_red_sensor_state_machine/sm_infra_red_sensor.hpp>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "InfraRedSensorSM.");
    smacc::run<sm_infra_red_sensor::SmInfraRedSensor>();
}
