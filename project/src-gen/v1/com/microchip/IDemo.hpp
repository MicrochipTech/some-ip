/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201808092327.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
/*
 * description: 
 * Interface to be implemented by server
 */
#ifndef V1_COM_MICROCHIP_I_DEMO_HPP_
#define V1_COM_MICROCHIP_I_DEMO_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Types.hpp>
#include <cstdint>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace com {
namespace microchip {

class IDemo {
public:
    virtual ~IDemo() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
    
    struct GenericErrors : CommonAPI::Enumeration< int32_t> {
        enum Literal : int32_t {
            Error = 0,
            Success = 1
        };
    
        GenericErrors()
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(Literal::Error)) {}
        GenericErrors(Literal _literal)
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(_literal)) {}
    
        inline bool validate() const {
            switch (value_) {
                case static_cast< int32_t>(Literal::Error):
                case static_cast< int32_t>(Literal::Success):
                return true;
            default:
                return false;
            }
        }
    
        inline bool operator==(const GenericErrors &_other) const { return (value_ == _other.value_); }
        inline bool operator!=(const GenericErrors &_other) const { return (value_ != _other.value_); }
        inline bool operator<=(const GenericErrors &_other) const { return (value_ <= _other.value_); }
        inline bool operator>=(const GenericErrors &_other) const { return (value_ >= _other.value_); }
        inline bool operator<(const GenericErrors &_other) const { return (value_ < _other.value_); }
        inline bool operator>(const GenericErrors &_other) const { return (value_ > _other.value_); }
    
        inline bool operator==(const Literal &_value) const { return (value_ == static_cast< int32_t>(_value)); }
        inline bool operator!=(const Literal &_value) const { return (value_ != static_cast< int32_t>(_value)); }
        inline bool operator<=(const Literal &_value) const { return (value_ <= static_cast< int32_t>(_value)); }
        inline bool operator>=(const Literal &_value) const { return (value_ >= static_cast< int32_t>(_value)); }
        inline bool operator<(const Literal &_value) const { return (value_ < static_cast< int32_t>(_value)); }
        inline bool operator>(const Literal &_value) const { return (value_ > static_cast< int32_t>(_value)); }
    };
};

const char* IDemo::getInterface() {
    return ("com.microchip.IDemo:v1_0");
}

CommonAPI::Version IDemo::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}

/*
 * description: 
 * Error handling
 */

} // namespace microchip
} // namespace com
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_COM_MICROCHIP_I_DEMO_HPP_