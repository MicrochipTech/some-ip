#include "IDemoStubImpl.hpp"


IDemoStubImpl::IDemoStubImpl(){
	std::cout << "Starting demo service" << std::endl;
}

void IDemoStubImpl::GetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, GetAttribReply_t _reply) {
    _reply(v1::com::microchip::IDemo::GenericErrors::Success, getAttribBoolAttribute());
}

void IDemoStubImpl::SetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value, SetAttribReply_t _reply) {
    setAttribBoolAttribute(_value);
    _reply(v1::com::microchip::IDemo::GenericErrors::Success);
}


IDemoStubImpl::~IDemoStubImpl() {
}


