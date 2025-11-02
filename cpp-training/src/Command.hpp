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
                if (poseHandler.IsFast()){
                    if (poseHandler.IsReverse()) {
                        poseHandler.Backward();
                    }
                    else{
                        poseHandler.Forward();
                    }
                }
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                }
                else {
                    poseHandler.Forward();
                }
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
                if (poseHandler.IsFast()){
                    if (poseHandler.IsReverse()){
                        poseHandler.Backward();}
                    else{
                        poseHandler.Forward();
                    }
                }
                if (poseHandler.IsReverse()){
                    poseHandler.TurnRight();
                }
                else{
                    poseHandler.TurnLeft();
                }
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
                if (poseHandler.IsFast()) {
                    if (poseHandler.IsReverse()) {
                        poseHandler.Backward();
                    } else {
                        poseHandler.Forward();
                    }
                }
                if (poseHandler.IsReverse()) {
                    poseHandler.TurnLeft();
                } else {
                    poseHandler.TurnRight();
                }
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
        //B指令实现
        class ReverseCommand final
        {
        public:
            void operator()(PoseHandler& poseHandler) const noexcept
            {
                poseHandler.Reverse();
            }
        };
};

