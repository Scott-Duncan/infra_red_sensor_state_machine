#ifndef ST_IDLE_HPP
#define ST_IDLE_HPP

#include <smacc/smacc.h>
#include <smacc/smacc_state.h>

#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/client_behaviours/cb_infrared_sensor_activate.hpp>
#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/cl_arduino_infrared_sensor.hpp>
#include <infrared_sensor_state_machine/orthogonals/or_arduino_infrared_sensor.hpp>

namespace sm_infrared_sensor
{
// STATE DECLARATION
struct StIdle : smacc::SmaccState<StIdle, SmInfraRedSensor>
{
    using SmaccState::SmaccState;

    struct IdleOn : smacc::default_events::SUCCESS {};

// TRANSITION TABLE
    typedef smacc::mpl::list<
        
    smacc::Transition<EvSensorActivated<CbInfraredSensorActivated, OrArduinoInfraredSensor>, StActive, IdleOn>    
    >reactions;

// STATE FUNCTIONS
    static void staticConfigure()
    {
        configure_orthogonal<OrArduinoInfraredSensor,  CbInfraredSensorActivated>();    
    }

    void runtimeConfigure()
    {
    }

    void onEntry()
    {
        ROS_INFO("On Entry!");
    }

    void onExit()
    {
        ROS_INFO("On Exit!");
    }
    
};
} // namespace sm_calendar_week{

#endif 