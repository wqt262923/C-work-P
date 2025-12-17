#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
#include "VehicleType.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose, VehicleType vehicleType) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;
    VehicleType GetVehicleType() const noexcept override
    {
        return vehicleType;
    }

private:
    PoseHandler poseHandler;
    VehicleType vehicleType;
};
}  // namespace adas