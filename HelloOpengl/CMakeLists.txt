cmake_minimum_required(VERSION 3.17)

project(HelloOpengl)

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_SRCS)
add_executable(HelloOpengl ${DIR_SRCS})

include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/include
)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build)

set(GLFW_LIBS ${PROJECT_SOURCE_DIR}/lib/glfw3.lib)

target_link_libraries(HelloOpengl ${GLFW_LIBS} )

target_link_libraries(HelloOpengl opengl32.lib)