/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.someip 3.1.12.v201801251434.
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
#include <v1/com/microchip/IDemoSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace com {
namespace microchip {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createIDemoSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< IDemoSomeIPProxy>(_address, _connection);
}

void initializeIDemoSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:com.microchip.IDemo:v1_0:com.microchip.demo",
        0x10, 0x5678, 1, 0);
     CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
         IDemo::getInterface(),
         &createIDemoSomeIPProxy);
}

INITIALIZER(registerIDemoSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeIDemoSomeIPProxy);
}

IDemoSomeIPProxy::IDemoSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection )
,          attribBool_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x1b58), CommonAPI::SomeIP::event_id_t(0x20), CommonAPI::SomeIP::method_id_t(0x1e), false, false, CommonAPI::SomeIP::method_id_t(0x1f), false, static_cast< CommonAPI::EmptyDeployment* >(nullptr))
,          status_(*this, 0x80e8, CommonAPI::SomeIP::event_id_t(0x80e8), false, false, std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)))
    {
    }

    IDemoSomeIPProxy::AttribBoolAttribute& IDemoSomeIPProxy::getAttribBoolAttribute() {
        return attribBool_;
    }

    IDemoSomeIPProxy::StatusEvent& IDemoSomeIPProxy::getStatusEvent() {
        return status_;
    }

    /*
     * description: 
     * Retrieve Attrib
     */
        void IDemoSomeIPProxy::GetAttrib(CommonAPI::CallStatus &_internalCallStatus, IDemo::GenericErrors &_error, bool &_data, const CommonAPI::CallInfo *_info) {
            CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t> deploy_error(static_cast< ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t * >(nullptr));
            CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_data(static_cast< CommonAPI::EmptyDeployment* >(nullptr));
            CommonAPI::SomeIP::ProxyHelper<
                CommonAPI::SomeIP::SerializableArguments<
                >,
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        IDemo::GenericErrors,
                        ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t
                    >,
                    CommonAPI::Deployable<
                        bool,
                        CommonAPI::EmptyDeployment
                    >
                >
            >::callMethodWithReply(
            *this,
            CommonAPI::SomeIP::method_id_t(0x5a),
            false,
            false,
    (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
    _internalCallStatus,
    deploy_error,
    deploy_data);
    _error = deploy_error.getValue();
    _data = deploy_data.getValue();
    }
    std::future<CommonAPI::CallStatus> IDemoSomeIPProxy::GetAttribAsync(GetAttribAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t> deploy_error(static_cast< ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t * >(nullptr));
        CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_data(static_cast< CommonAPI::EmptyDeployment* >(nullptr));
        return CommonAPI::SomeIP::ProxyHelper<
            CommonAPI::SomeIP::SerializableArguments<
            >,
            CommonAPI::SomeIP::SerializableArguments<
                CommonAPI::Deployable<
                    IDemo::GenericErrors,
                    ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t
                >,
                CommonAPI::Deployable<
                    bool,
                    CommonAPI::EmptyDeployment
                >
            >
        >::callMethodAsync(
            *this,
            CommonAPI::SomeIP::method_id_t(0x5a),
            false,
            false,
            (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
            [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t > _deploy_error, CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment > _data) {
                if (_callback)
                    _callback(_internalCallStatus, _deploy_error.getValue(), _data.getValue());
            },
            std::make_tuple(deploy_error, deploy_data));
    }
    /*
     * description: 
     * Set Attrib
     */
        void IDemoSomeIPProxy::SetAttrib(const bool &_value, CommonAPI::CallStatus &_internalCallStatus, IDemo::GenericErrors &_error, const CommonAPI::CallInfo *_info) {
            CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t> deploy_error(static_cast< ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t * >(nullptr));
            CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_value(_value, static_cast< CommonAPI::EmptyDeployment* >(nullptr));
            CommonAPI::SomeIP::ProxyHelper<
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        bool,
                        CommonAPI::EmptyDeployment
                    >
                >,
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        IDemo::GenericErrors,
                        ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t
                    >
                >
            >::callMethodWithReply(
            *this,
            CommonAPI::SomeIP::method_id_t(0x5b),
            false,
            false,
    (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
    deploy_value,
    _internalCallStatus,
    deploy_error);
    _error = deploy_error.getValue();
    }
    std::future<CommonAPI::CallStatus> IDemoSomeIPProxy::SetAttribAsync(const bool &_value, SetAttribAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t> deploy_error(static_cast< ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t * >(nullptr));
        CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_value(_value, static_cast< CommonAPI::EmptyDeployment* >(nullptr));
        return CommonAPI::SomeIP::ProxyHelper<
            CommonAPI::SomeIP::SerializableArguments<
                CommonAPI::Deployable<
                    bool,
                    CommonAPI::EmptyDeployment
                >
            >,
            CommonAPI::SomeIP::SerializableArguments<
                CommonAPI::Deployable<
                    IDemo::GenericErrors,
                    ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t
                >
            >
        >::callMethodAsync(
            *this,
            CommonAPI::SomeIP::method_id_t(0x5b),
            false,
            false,
            (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
            deploy_value,
            [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< IDemo::GenericErrors, ::v1::com::microchip::IDemo_::GenericErrorsDeployment_t > _deploy_error) {
                if (_callback)
                    _callback(_internalCallStatus, _deploy_error.getValue());
            },
            std::make_tuple(deploy_error));
    }



    void IDemoSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
    }

} // namespace microchip
} // namespace com
} // namespace v1
