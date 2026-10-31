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
    for (const char command : commands) {
        if (command == 'M') {
            switch (pose.heading) {
                case 'E': ++pose.x; break;
                case 'W': --pose.x; break;
                case 'N': ++pose.y; break;
                case 'S': --pose.y; break;
            }
        } else if (command == 'L' || command == 'R') {
            // Clockwise order makes either quarter turn an index shift.
            constexpr char HEADINGS[] = {'N', 'E', 'S', 'W'};
            int index = 0;
            while (HEADINGS[index] != pose.heading) {
                ++index;
            }
            const int offset = command == 'R' ? 1 : 3;
            pose.heading = HEADINGS[(index + offset) % 4];
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
