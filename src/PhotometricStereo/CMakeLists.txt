cmake_minimum_required (VERSION 3.28)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (PhotometricStereo)

# 将源代码添加到此项目的可执行文件。
add_executable (PhotometricStereo "PhotometricStereo.cpp" "PhotometricStereo.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PhotometricStereo PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
