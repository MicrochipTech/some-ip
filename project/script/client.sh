#!/usr/bin/env bash

sudo route add -net 224.0.0.0/4 dev eth0
COMMONAPI_PATH=../../capicxx-core-runtime/build
COMMONAPI_SOMEIP_PATH=../../capicxx-someip-runtime/build
VSOMEIP_PATH=../../vsomeip/build
export LD_LIBRARY_PATH=../lib:${COMMONAPI_PATH}:${COMMONAPI_SOMEIP_PATH}:${VSOMEIP_PATH}:$LD_LIBRARY_PATH
export VSOMEIP_APPLICATION_NAME=client-sample
export VSOMEIP_CONFIGURATION=../config/vsomeip-client.json
../build/client
