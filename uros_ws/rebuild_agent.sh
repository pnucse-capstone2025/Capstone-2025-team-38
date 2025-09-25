#!/bin/bash

# 에러가 발생하면 즉시 스크립트를 중단합니다.
set -e

echo "### Starting custom rebuild for micro_ros_agent..."

rm -rf ./build
rm -rf /install

# 3. Navigate back to the workspace root
#echo "### => Changing back to workspace root..."
#cd /home/tmdals010126/uros_ws

# 4. Run colcon build to relink the final executable
echo "### => Relinking the final executable (colcon build)..."
colcon build

echo "###"
echo "### Rebuild complete! Your changes in Root.cpp should be applied."
echo "### You can now run the agent." 
