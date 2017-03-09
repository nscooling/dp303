# Copyright (c) <year> <author> (<email>)
# Distributed under the MIT License.
# See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT

include_directories(AFTER "${PROJECT_PATH}/feabhOS/C/common/inc")
include_directories(AFTER "${PROJECT_PATH}/feabhOS/C/POSIX/inc")
include_directories(AFTER "${PROJECT_PATH}/feabhOS/C++/inc")

# Set project source files.
set(SRC
  "${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_condition.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_interrupts.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_memory.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_mutex.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_queue.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_scheduler.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_semaphore.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_signal.c"
"${PROJECT_PATH}/feabhOS/C/POSIX/src/feabhOS_task.c"
"${PROJECT_PATH}/feabhOS/C++/src/Scheduler.cpp"
)

