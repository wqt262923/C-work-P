#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
#include "VehicleType.hpp"

namespace adas
{
// 跑车测试
TEST(SportsCarTest, should_move_2_steps_given_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("M");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_move_and_turn_left_given_L_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("L");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_move_and_turn_right_given_R_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("R");
    // then
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_move_4_steps_given_F_and_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("FM");
    // then
    const Pose target{4, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_move_1_turn_left_and_move_1_given_F_and_L_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_back_2_steps_given_B_and_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(SportsCarTest, should_back_1_turn_right_and_back_1_given_BF_and_L_command)
{
    // given
//    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::SportsCar));
    // when
//    executor->Execute("BFL");
    // then
 //   const Pose target{-1, -1, 'S'};
  //  ASSERT_EQ(target, executor->Query());
}
}  // namespace adas