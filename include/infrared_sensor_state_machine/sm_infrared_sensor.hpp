#ifndef SM_INFRARED_SENSOR_HPP
#define SM_INFRARED_SENSOR_HPP

#include <ros/ros.h>
#include <smacc/smacc.h>

// CLIENTS
#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/cl_arduino_infrared_sensor.hpp>

// ORTHOGONALS
#include <infrared_sensor_state_machine/orthogonals/or_arduino_infrared_sensor.hpp>

//CLIENT BEHAVIORS
#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/client_behaviours/cb_infrared_sensor_activate.hpp>


namespace sm_infrared_sensor
{

//STATES
class StActive;
class StIdle;

// struct EvToDeep : sc::event<EvToDeep>{};

// struct EvFail : sc::event<EvFail>{};

// struct EvEStop : sc::event<EvEStop>{};

// STATE MACHINE
struct SmInfraRedSensor
    : public smacc::SmaccStateMachineBase<SmInfraRedSensor, StIdle>
{
    using SmaccStateMachineBase::SmaccStateMachineBase;

    virtual void onInitialize() override
    {
        this->createOrthogonal<OrArduinoInfraredSensor>();
    }
};
} // namespace sm_infrared_sensor

//STATES
#include <infrared_sensor_state_machine/states/st_active.hpp>
#include <infrared_sensor_state_machine/states/st_idle.hpp>

#endif