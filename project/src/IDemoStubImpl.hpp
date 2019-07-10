#ifndef IVIDEOWINDOWSTUBIMPL_H_
#define IVIDEOWINDOWSTUBIMPL_H_
#include <v1/com/microchip/IDemoStubDefault.hpp>

class IDemoStubImpl : public v1::com::microchip::IDemoStubDefault {
	public:
            /*
             * description: 
             * constructor
             */
            IDemoStubImpl();
            /*
             * description: 
             * Retrieve Attrib
             */
            virtual void GetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, GetAttribReply_t _reply);
            /*
             * description: 
             * Set Attrib
             */
            virtual void SetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value, SetAttribReply_t _reply);
            /*
             * description: 
             * Destructor
             */
            virtual ~IDemoStubImpl();
            
};

#endif /*IVIDEOWINDOWSTUBIMPL_H_ */
