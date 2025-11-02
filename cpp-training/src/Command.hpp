#pragma once
#include <functional>
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;
    //     virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
    // };
        //move指令
        class MoveCommand final //: public ICommand
        {
        public:
            // void DoOperate(PoseHandler& poseHandler) const noexcept override
            // {
            //     if (poseHandler.IsFast()) {
            //         poseHandler.Move();
            //     }
            //     poseHandler.Move();
            // }
            void operator()(PoseHandler& poseHandler) const noexcept
            {
                if (poseHandler.IsFast())
                {
                    poseHandler.Move();
                }
                poseHandler.Move();
            }
        };
        //左转指令
        class TurnLeftCommand final //: public ICommand
        {
        public:
            // void DoOperate(PoseHandler& poseHandler) const noexcept override
            // {
            //     if (poseHandler.IsFast()) {
            //         poseHandler.Move();
            //     }
            //     poseHandler.TurnLeft();
            // }
            void operator()(PoseHandler& poseHandler) const noexcept
            {
                if (poseHandler.IsFast())
                {
                    poseHandler.Move();
                }
                poseHandler.TurnLeft();
            }
        };
        //右转指令
        class TurnRightCommand final //: public ICommand
        {
        public:
            // void DoOperate(PoseHandler& poseHandler) const noexcept override
            // {
            //     if (poseHandler.IsFast()) {
            //         poseHandler.Move();
            //     }
            //     poseHandler.TurnRight();
            // }
            void operator()(PoseHandler& poseHandler) const noexcept
            {
                if (poseHandler.IsFast())
                {
                    poseHandler.Move();
                }
                poseHandler.TurnRight();
            }
        };
        //F指令功能代码实现：FastCommand类建立
        class FastCommand final //: public ICommand
        {
        public:
            // void DoOperate(PoseHandler& poseHandler) const noexcept override
            // {
            //      poseHandler.Fast();
            // }
            void operator()(PoseHandler& poseHandler) const noexcept
            {
                poseHandler.Fast();
            }
        };
};

