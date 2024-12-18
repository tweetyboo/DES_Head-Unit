/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_speed_STUB_HPP_
#define V1_COMMONAPI_speed_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/speed.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service speed. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class speedStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual speed {
 public:
    ///Notifies all remote listeners about a change of value of the attribute Speed.
    virtual void fireSpeedAttributeChanged(const float &Speed) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockSpeedAttribute(bool _lockAccess) {
        if (_lockAccess) {
            speedMutex_.lock();
        } else {
            speedMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex speedMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for speed.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class speedStubRemoteEvent
{
public:
    virtual ~speedStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute Speed
    virtual bool onRemoteSetSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, float _value) = 0;
    /// Action callback for remote set requests on the attribute Speed
    virtual void onRemoteSpeedAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service speed to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class speedStub
    : public virtual CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>
{
public:

    virtual ~speedStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute Speed
    virtual const float &getSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireSpeedAttributeChanged(float _value) {
    auto stubAdapter = CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireSpeedAttributeChanged(_value);
    }
    void lockSpeedAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockSpeedAttribute(_lockAccess);
    }


    using CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<speedStubAdapter, speedStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef speedStubRemoteEvent RemoteEventType;
    typedef ::v1::commonapi::speed StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_speed_STUB_HPP_
