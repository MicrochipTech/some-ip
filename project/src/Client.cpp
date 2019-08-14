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
/* Function: Navigation client based on SOME-IP
 ******************************************************************************************/

#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/com/microchip/IDemoProxy.hpp>
#include <termios.h>

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<v1::com::microchip::IDemoProxy<>> demoProxy = runtime->buildProxy<v1::com::microchip::IDemoProxy>("local", "com.microchip.demo");
    
    std::cout << "Checking availability!" << std::endl;
    while (!demoProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    // lets map keyboard keys with map directions
    static struct termios termios_old, termios_new;         // configure termios for getchar()
    tcgetattr(0, &termios_old);
    termios_new = termios_old;
    termios_new.c_lflag &= ~(ICANON | ECHO);                // non-canonical mode, echo off
    termios_new.c_cc[VMIN] = 0;                             // don't block if no char available
    termios_new.c_cc[VTIME] = 0;                            //
    tcsetattr(0, TCSANOW, &termios_new);
    
    bool bRun = true;
    bool gFlag = false;
    while (bRun) {
        int32_t result;
        int c = getchar();
        fflush( stdin );
        
        CommonAPI::CallStatus callStatus;
        v1::com::microchip::IDemo::GenericErrors error;
        switch( c ) {
            case 'g':
            {   
                bool data;
                demoProxy->GetAttrib(callStatus, error, data);
                std::cout << (data ? "true": "false") << std::endl;
                break;
            }
            case 's':
                gFlag = !gFlag;
                demoProxy->SetAttrib(gFlag, callStatus, error);
                std::cout << "value set to "<< (gFlag ? "true": "false") <<std::endl;
                break;		
            case 'x':
                bRun = false;
                break;
        }
    }        
    
    tcsetattr(0, TCSANOW, &termios_old);            // restore terminal settings before exit	
    return 0;
} 
