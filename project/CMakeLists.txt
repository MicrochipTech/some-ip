cmake_minimum_required(VERSION 2.8)

get_filename_component(RUNTIME_PATH ../ ABSOLUTE)
message(STATUS ${RUNTIME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
	src-gen
	${RUNTIME_PATH}/capicxx-core-runtime/include
	${RUNTIME_PATH}/capicxx-someip-runtime/include
	${RUNTIME_PATH}/vsomeip/interface
	)
link_directories(
	${RUNTIME_PATH}/capicxx-core-runtime/build
	${RUNTIME_PATH}/capicxx-someip-runtime/build
	${RUNTIME_PATH}/vsomeip/build
	)
add_executable(client
	src/Client.cpp
	./src-gen/v1/com/microchip/IDemoSomeIPProxy.cpp
	./src-gen/v1/com/microchip/IDemoSomeIPDeployment.cpp
	)
target_link_libraries(client CommonAPI CommonAPI-SomeIP vsomeip)

add_executable(service
	./src/Service.cpp
	./src/IDemoStubImpl.cpp
	./src-gen/v1/com/microchip/IDemoStubDefault.cpp
	./src-gen/v1/com/microchip/IDemoSomeIPStubAdapter.cpp
	./src-gen/v1/com/microchip/IDemoSomeIPDeployment.cpp
	)
target_link_libraries(service CommonAPI CommonAPI-SomeIP vsomeip)
