#pragma once
#include "Executor.hpp"
#include "VehicleType.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose, VehicleType vehicleType = VehicleType::Car) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Forward(void) noexcept;
    void ForwardOneStep(void) noexcept;   // 前进1格
    void ForwardTwoSteps(void) noexcept;  // 前进2格

    void Backward(void) noexcept;
    void BackwardOneStep(void) noexcept;   // 后退1格
    void BackwardTwoSteps(void) noexcept;  // 后退2格

    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;

    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;

    Pose Query(void) const noexcept;

    void Reverse(void) noexcept;
    bool IsReverse(void) const noexcept;

    VehicleType GetVehicleType() const noexcept
    {
        return vehicleType;
    }

private:
    void MoveImpl(int step) noexcept;

    Pose pose;
    bool fast{false};
    bool reverse{false};
    VehicleType vehicleType;
};
}  // namespace adas