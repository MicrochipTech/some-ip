# SOMEIP
The below steps show how to compile the dependencies so as to build and execute SOME/IP applications across different nodes.
We use CodeGenerator for Generating Interface code specific to our application, as well as Glue code for binding to either DBus or SOME/IP for communication

NOTE: I'm adding the source for 3 libraries which are essential for creating SOME/IP based applications. These 3 libraries are compatible with each other (Some versions might not be compatible) - Hence adding the code.

## Primary Requirements
It is assumed that, you have 2 machines, preferably Raspberry PI's for testing the build. We would be running the server and client on 2 different nodes. This repository should be present on both the machines. 

```bash
sudo apt-get update
sudo apt-get install doxygen asciidoc graphviz source-highlight libboost-system-dev libboost-thread-dev libboost-log-dev
```
Any boost version above 1_55 would be good, you can check the version with this command:
```bash
cat /usr/include/boost/version.hpp | grep "BOOST_LIB_VERSION"
```
## Build Instructions
If you plan to build the dependencies from svn repository follow the instructions below. 

Please note that **build instruction** would help you kick start with SOME-IP. 

> If you are planning to develop new features, please do refer the
> "**How to extend**" section First

Start compiling:
```bash
cd ~/SOME-IP/trunk/capicxx-core-runtime/
mkdir build && cd build
cmake .. && make
```
You should now find the libraries in the capicxx-core-runtime/build folder.
```bash
cd ../..
cd vsomeip
mkdir build && cd build
cmake .. && make
```
You should now find the libraries in the vsomeip/build folder.

```bash
cd ../..
cd capicxx-someip-runtime
mkdir build && cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF .. ; make
```
You should now find the libraries in the capicxx-someip-runtime/build folder.
Once all the libraries are build, you can directly build the applications. These 3 libraries are a **MUST** for developing SomeIP applications using the code generator. Later on we might refer the above libraries as "SomeIP libraries" for ease.

Now lets build the project developed using the above library
```bash
cd ../..
cd project
mkdir build && cd build
cmake .. && make
```
SomeIP has a lot of user defined configurations. It is almost impossible to list them as command line parameters. We use a `json` file for doing the same.
Edit the `json ` files present in the config folder to reflect the correct network parameter of the machines like ip-address and subnet-mask.

eg: 
```json
client node with ip 10.40.32.110
{
	"unicast" : "10.40.32.110",
		"netmask" : "255.255.255.0",
		"logging" :
		{
service node with ip 10.40.32.89
{
	"unicast" : "10.40.32.89",
		"logging" :
		{
```
Also in the service `json` file, make sure you give the correct  *`service ID`* and *`Instance ID`* 
```json
	"services" :
		[
		{
			"service" : "0x10",
			"instance" : "22136",
			"reliable" : { "port" : "30509", "enable-magic-cookies" : "false" },
			"unreliable": "31000"
		}
		],
```
This data can be found from the corresponding *`fdepl`* files
```json
define org.genivi.commonapi.someip.deployment for interface com.microchip.IDemo {

	SomeIpServiceID = 16
```
This is the *`service ID`* in decimal 
```json
define org.genivi.commonapi.someip.deployment for provider Service {
	instance com.microchip.IDemo {
		 InstanceId = "com.microchip.demo"
		SomeIpInstanceID = 22136
	}
}
```
This is the *`Instance ID`* in decimal. This step would only be relevant if you plan on adding new interfaces in the fidl folder. For the Demo interface, the author has already set the instance and service ID's properly.

please use the the `service.sh` files present in the 
```bash
> cd project/scripts
> ./service.sh
```
to execute the service. Likewise, you can find the `client .sh` in  

```bash
> cd project/config
> ./client.sh
```
folder. The `client.sh` and `service.sh` would set the proper environment variables and execute the service and client by passing the proper `json` files as parameters. 

## How to extend

Edit the *`fidl`* files and corresponding *`fdepl`* files to add new interfaces/methods/attributes. You can find the *`fidl`* files and *`fdepl`* files in 

```bash
cd project/fidl
```
A detailed description on how to edit the *`fidl`* files is present in 

```bash
SOME-IP/trunk/CommonAPICppUserGuide.pdf
```
Once you have added your interface and methods, Its time to generate the corresponding source files. For this we need a Linux-x86 machine. I used a Ubuntu 16.04 running on x86_64. We are using pre-build executables to generate code from *`fidl`*/*`fdepl`*. There is no executable for a Linux-arm machine. Checkout the 

```bash
SOME-IP/trunk/project
```
onto your Ubuntu machine. Do the following  

```bash
cd SOME-IP/trunk/project/cgen
unzip commonapi_someip_generator.zip -d commonapi_someip_generator
unzip commonapi-generator.zip -d commonapi-generator
cd ..
rm -rf src_gen
```
Edit `gen_src.sh` file to point to the right *`fidl`* and *`fdepl`* files. For eg: If we have added 2 new files `New.fidl` and `New.fdepl`, edit the file to

```vim
./cgen/commonapi-generator/commonapi-generator-linux-x86_64 -sk ./fidl/New.fidl
./cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 ./fidl/New.fdepl

```
Save the file. Run the script by

```bash
./gen_src.sh
```
This would create a src_gen folder which would contain all the generated source files. Now you can develop your application by implementing the interfaces that you have defined in the *`fidl`*/*`fdepl`*. A detailed description of writing application with the generated source files are given in 

```bash
SOME-IP/trunk/CommonAPICppUserGuide.pdf
```
Once the applications are ready,  Proceed as per the **Build** section