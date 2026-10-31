#include "Executor.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace adas {
namespace {
void ExpectPose(const Pose& expected, const Pose& actual)
{
    EXPECT_EQ(expected.x, actual.x);
    EXPECT_EQ(expected.y, actual.y);
    EXPECT_EQ(expected.heading, actual.heading);
}
}  // namespace

TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'E'}));
    ASSERT_NE(nullptr, executor);
    ExpectPose(Pose{3, -2, 'E'}, executor->Query());
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    ASSERT_NE(nullptr, executor);
    ExpectPose(Pose{0, 0, 'N'}, executor->Query());
}

TEST(ExecutorTest, should_move_one_grid_when_facing_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'E'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("M");
    ExpectPose(Pose{4, -2, 'E'}, executor->Query());
}

TEST(ExecutorTest, should_move_one_grid_when_facing_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'W'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("M");
    ExpectPose(Pose{2, -2, 'W'}, executor->Query());
}

TEST(ExecutorTest, should_move_one_grid_when_facing_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'N'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("M");
    ExpectPose(Pose{3, -1, 'N'}, executor->Query());
}

TEST(ExecutorTest, should_move_one_grid_when_facing_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'S'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("M");
    ExpectPose(Pose{3, -3, 'S'}, executor->Query());
}

TEST(ExecutorTest, should_face_N_after_L_when_facing_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'E'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("L");
    ExpectPose(Pose{3, -2, 'N'}, executor->Query());
}

TEST(ExecutorTest, should_face_S_after_L_when_facing_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'W'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("L");
    ExpectPose(Pose{3, -2, 'S'}, executor->Query());
}

TEST(ExecutorTest, should_face_W_after_L_when_facing_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'N'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("L");
    ExpectPose(Pose{3, -2, 'W'}, executor->Query());
}

TEST(ExecutorTest, should_face_E_after_L_when_facing_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'S'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("L");
    ExpectPose(Pose{3, -2, 'E'}, executor->Query());
}

TEST(ExecutorTest, should_face_S_after_R_when_facing_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'E'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("R");
    ExpectPose(Pose{3, -2, 'S'}, executor->Query());
}

TEST(ExecutorTest, should_face_N_after_R_when_facing_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'W'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("R");
    ExpectPose(Pose{3, -2, 'N'}, executor->Query());
}

TEST(ExecutorTest, should_face_E_after_R_when_facing_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'N'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("R");
    ExpectPose(Pose{3, -2, 'E'}, executor->Query());
}

TEST(ExecutorTest, should_face_W_after_R_when_facing_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({3, -2, 'S'}));
    ASSERT_NE(nullptr, executor);
    executor->Execute("R");
    ExpectPose(Pose{3, -2, 'W'}, executor->Query());
}

}  // namespace adas
