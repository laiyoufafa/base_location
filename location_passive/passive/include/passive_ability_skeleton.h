/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_LOCATION_PASSIVE_ABILITY_SKELETON_H
#define OHOS_LOCATION_PASSIVE_ABILITY_SKELETON_H

#include "subability_common.h"
#include "iremote_object.h"
#include "iremote_proxy.h"
#include "iremote_stub.h"

namespace OHOS {
namespace Location {
class IPassiveAbility : public ISubAbility {
public:
    DECLARE_INTERFACE_DESCRIPTOR(u"location.IPassiveAbility");
};

class PassiveAbilityProxy : public IRemoteProxy<IPassiveAbility>, public SubAbilityProxy {
public:
    explicit PassiveAbilityProxy(const sptr<IRemoteObject> &impl);
    ~PassiveAbilityProxy() = default;
    void SendLocationRequest(uint64_t interval, WorkRecord &workrecord) override;
    std::unique_ptr<Location> GetCachedLocation() override;
    void SetEnable(bool state) override;
};

class PassiveAbilityStub : public IRemoteStub<IPassiveAbility> {
public:
    int32_t OnRemoteRequest(uint32_t code,
        MessageParcel &data, MessageParcel &reply, MessageOption &option) override;
private:
    static inline BrokerDelegator<PassiveAbilityProxy> delegator_;
};
} // namespace Location
} // namespace OHOS
#endif // OHOS_LOCATION_PASSIVE_ABILITY_SKELETON_H