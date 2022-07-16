#pragma once

#include <ros/ros.h>
#include <smacc/smacc.h>

// CLIENTS
#include <infra_red_sensor_state_machine/clients/cl_arduino_infra_red_sensor_service_server.hpp>

// ORTHOGONALS
#include <infra_red_sensor_state_machine/orthogonols/or_infra_red_sensor.hpp>

//CLIENT BEHAVIORS
#include <infra_red_sensor_state_machine/clients/client_behaviours>

namespace sm_infra_red_sensor
{

//STATES
class StActive
class StIdle

// struct EvToDeep : sc::event<EvToDeep>{};

// struct EvFail : sc::event<EvFail>{};

// struct EvEStop : sc::event<EvEStop>{};

// STATE MACHINE
struct SmInfraRedSensor
    : public smacc::SmaccStateMachineBase<SmInfraRedSensor, MsWorkweek>
{
    using SmaccStateMachineBase::SmaccStateMachineBase;

    virtual void onInitialize() override
    {
        this->createOrthogonal<OrInfraRedSensor>();
    }
};
} // namespace sm_infra_red_sensor

//STATES
#include <infra_red_sensor_state_machine/states/st_active.hpp>
#include <infra_red_sensor_state_machine/states/st_idle.hpp>