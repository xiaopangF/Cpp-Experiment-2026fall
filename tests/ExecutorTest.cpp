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

}  // namespace adas
