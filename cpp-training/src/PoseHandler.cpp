#include "PoseHandler.hpp"

#include <algorithm>

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose, VehicleType vehicleType) noexcept : pose(pose), vehicleType(vehicleType)
{
}

void PoseHandler::MoveImpl(int step) noexcept
{
    switch (pose.heading) {
    case 'E':
        pose.x += step;
        break;
    case 'W':
        pose.x -= step;
        break;
    case 'N':
        pose.y += step;
        break;
    case 'S':
        pose.y -= step;
        break;
    }
}

void PoseHandler::Forward() noexcept
{
    int steps = 1;

    if (vehicleType == VehicleType::SportsCar) {
        steps = 2;  // 跑车前进2格
    }

    if (fast) {
        steps *= 2;  // F状态加倍
    }

    MoveImpl(steps);
}

void PoseHandler::Backward() noexcept
{
    int steps = 1;

    if (vehicleType == VehicleType::SportsCar) {
        steps = 2;  // 跑车后退2格
    }

    if (fast) {
        steps *= 2;  // F状态加倍
    }

    MoveImpl(-steps);
}

void PoseHandler::ForwardOneStep() noexcept
{
    MoveImpl(1);
}

void PoseHandler::ForwardTwoSteps() noexcept
{
    MoveImpl(2);
}

void PoseHandler::BackwardOneStep() noexcept
{
    MoveImpl(-1);
}

void PoseHandler::BackwardTwoSteps() noexcept
{
    MoveImpl(-2);
}

void PoseHandler::TurnLeft() noexcept
{
    // 普通转向逻辑
    if (pose.heading == 'E')
        pose.heading = 'N';
    else if (pose.heading == 'N')
        pose.heading = 'W';
    else if (pose.heading == 'W')
        pose.heading = 'S';
    else if (pose.heading == 'S')
        pose.heading = 'E';
}

void PoseHandler::TurnRight() noexcept
{
    // 普通转向逻辑
    if (pose.heading == 'E')
        pose.heading = 'S';
    else if (pose.heading == 'S')
        pose.heading = 'W';
    else if (pose.heading == 'W')
        pose.heading = 'N';
    else if (pose.heading == 'N')
        pose.heading = 'E';
}

void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}

bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}

Pose PoseHandler::Query() const noexcept
{
    return pose;
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}
}  // namespace adas