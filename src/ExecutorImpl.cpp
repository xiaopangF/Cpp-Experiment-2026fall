#include "ExecutorImpl.hpp"

#include <new>

namespace adas {
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new (std::nothrow) ExecutorImpl(initialPose);
}

ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept : pose(initialPose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    (void)commands;
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
