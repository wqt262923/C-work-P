#pragma once
#include <string>

#include "VehicleType.hpp"

namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;
};

class Executor
{
public:
    // 新增车辆类型参数
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}, VehicleType vehicleType = VehicleType::Car) noexcept;

public:
    Executor(void) = default;
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

public:
    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
    virtual VehicleType GetVehicleType() const noexcept = 0;
};
}  // namespace adas