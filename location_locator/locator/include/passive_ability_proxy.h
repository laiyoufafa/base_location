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

#ifndef OHOS_LOCATION_PASSIVE_ABILITY_PROXY_H
#define OHOS_LOCATION_PASSIVE_ABILITY_PROXY_H

#include "iremote_object.h"
#include "iremote_proxy.h"
#include "iremote_stub.h"

#include "passive_ability_skeleton.h"

namespace OHOS {
namespace Location {
class PassiveAbilityProxy : public IRemoteProxy<IPassiveAbility> {
public:
    explicit PassiveAbilityProxy(const sptr<IRemoteObject> &impl);
    ~PassiveAbilityProxy() = default;
    void SendLocationRequest(uint64_t interval, WorkRecord &workrecord) override;
    std::unique_ptr<Location> GetCachedLocation() override;
    void SetEnable(bool state) override;
private:
    static inline BrokerDelegator<PassiveAbilityProxy> delegator_;
};
} // namespace Location
} // namespace OHOS
#endif // OHOS_LOCATION_PASSIVE_ABILITY_PROXY_H