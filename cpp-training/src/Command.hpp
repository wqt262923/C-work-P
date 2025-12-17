#pragma once
#include <functional>

#include "PoseHandler.hpp"
#include "VehicleType.hpp"

namespace adas
{
class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
        } else {
            poseHandler.Forward();
        }
    }
};

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        VehicleType vehicleType = poseHandler.GetVehicleType();
        bool isFast = poseHandler.IsFast();
        bool isReverse = poseHandler.IsReverse();

        if (vehicleType == VehicleType::SportsCar) {
            // 跑车逻辑
            if (isFast && isReverse) {
                // B&F状态：先后退1格，然后右转90度，再后退1格
                poseHandler.BackwardOneStep();  // 后退1格
                poseHandler.TurnRight();        // 右转90度
                poseHandler.BackwardOneStep();  // 再后退1格
            } else if (isFast) {
                // F状态：先前进1格，然后左转90度，再前进1格
                poseHandler.ForwardOneStep();  // 前进1格
                poseHandler.TurnLeft();        // 左转90度
                poseHandler.ForwardOneStep();  // 再前进1格
            } else if (isReverse) {
                // B状态：右转90度（倒车状态下左转实际是右转）
                poseHandler.TurnRight();
            } else {
                // 正常状态：左转90度，前进1格
                poseHandler.TurnLeft();
                poseHandler.ForwardOneStep();
            }
        } else if (vehicleType == VehicleType::Bus) {
            // 巴士逻辑
            if (isFast) {
                // F状态下先移动1格
                if (isReverse) {
                    poseHandler.BackwardOneStep();
                } else {
                    poseHandler.ForwardOneStep();
                }
            }

            // 转向，不考虑倒车状态的特殊转向
            // 巴士在正常状态下：左转就是左转
            if (isReverse) {
                // 倒车状态下，巴士左转实际也是右转（与普通车一致）
                poseHandler.TurnRight();
            } else {
                poseHandler.TurnLeft();
            }

            // 巴士在正常状态（非F状态）下，L指令需要前进1格
            if (!isFast && !isReverse) {
                poseHandler.ForwardOneStep();
            }
        } else {
            // 普通车逻辑
            if (isFast) {
                // F状态下先移动1格
                if (isReverse) {
                    poseHandler.BackwardOneStep();
                } else {
                    poseHandler.ForwardOneStep();
                }
            }

            // 转向
            if (isReverse) {
                // 倒车状态下左转实际是右转
                poseHandler.TurnRight();
            } else {
                poseHandler.TurnLeft();
            }
        }
    }
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        VehicleType vehicleType = poseHandler.GetVehicleType();
        bool isFast = poseHandler.IsFast();
        bool isReverse = poseHandler.IsReverse();

        if (vehicleType == VehicleType::SportsCar) {
            // 跑车逻辑
            if (isFast && isReverse) {
                // B&F状态：先后退1格，然后左转90度，再后退1格
                poseHandler.BackwardOneStep();  // 后退1格
                poseHandler.TurnLeft();         // 左转90度
                poseHandler.BackwardOneStep();  // 再后退1格
            } else if (isFast) {
                // F状态：先前进1格，然后右转90度，再前进1格
                poseHandler.ForwardOneStep();  // 前进1格
                poseHandler.TurnRight();       // 右转90度
                poseHandler.ForwardOneStep();  // 再前进1格
            } else if (isReverse) {
                // B状态：左转90度（倒车状态下右转实际是左转）
                poseHandler.TurnLeft();
            } else {
                // 正常状态：右转90度，前进1格
                poseHandler.TurnRight();
                poseHandler.ForwardOneStep();
            }
        } else if (vehicleType == VehicleType::Bus) {
            // 巴士逻辑
            if (isFast) {
                // F状态下先移动1格
                if (isReverse) {
                    poseHandler.BackwardOneStep();
                } else {
                    poseHandler.ForwardOneStep();
                }
            }

            // 转向，不考虑倒车状态的特殊转向
            // 巴士在正常状态下：右转就是右转
            if (isReverse) {
                // 倒车状态下，巴士右转实际也是左转（与普通车一致）
                poseHandler.TurnLeft();
            } else {
                poseHandler.TurnRight();
            }

            // 巴士在正常状态（非F状态）下，R指令需要前进1格
            if (!isFast && !isReverse) {
                poseHandler.ForwardOneStep();
            }
        } else {
            // 普通车逻辑
            if (isFast) {
                // F状态下先移动1格
                if (isReverse) {
                    poseHandler.BackwardOneStep();
                } else {
                    poseHandler.ForwardOneStep();
                }
            }

            // 转向
            if (isReverse) {
                // 倒车状态下右转实际是左转
                poseHandler.TurnLeft();
            } else {
                poseHandler.TurnRight();
            }
        }
    }
};

class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};

class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};
}  // namespace adas