/******************************************************************************************
 * Copyright (C) 2015 Microchip Technology Germany II GmbH & Co. KG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Information: You may also obtain this software under a propriety license from Microchip.
 * Please contact Microchip for further information.
 ******************************************************************************************/
/* Function: Server hosting Multiple services based on SOME-IP
 ******************************************************************************************/

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "IDemoStubImpl.hpp"


int main() {
	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
	std::shared_ptr<IDemoStubImpl> demoService = std::make_shared<IDemoStubImpl>();
	runtime->registerService("local", "com.microchip.demo", demoService);
	while (true) {
		std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
	return 0;

} 
