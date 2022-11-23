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

#ifndef NETWORK_ABILITY_H
#define NETWORK_ABILITY_H

#include <string>
#include <singleton.h>

#include "event_handler.h"
#include "event_runner.h"
#include "system_ability.h"

#include "common_utils.h"
#include "network_ability_skeleton.h"
#include "subability_common.h"

namespace OHOS {
namespace Location {
static constexpr int REQUEST_NETWORK_LOCATION = 1;
static constexpr int REMOVE_NETWORK_LOCATION = 2;
static constexpr std::string SERVICE_NAME = "com.huawei.hms.hmscore";
static constexpr std::string ABILITY_NAME = "LocationServiceAbility";
class NetworkHandler : public AppExecFwk::EventHandler {
public:
    explicit NetworkHandler(const std::shared_ptr<AppExecFwk::EventRunner>& runner);
    ~NetworkHandler() override;
    void ProcessEvent(const AppExecFwk::InnerEvent::Pointer& event) override;
};

class NetworkAbility : public SystemAbility, public NetworkAbilityStub, public SubAbility,
    DelayedSingleton<NetworkAbility> {
DECLEAR_SYSTEM_ABILITY(NetworkAbility);

public:
    DISALLOW_COPY_AND_MOVE(NetworkAbility);
    NetworkAbility();
    ~NetworkAbility();
    void OnStart() override;
    void OnStop() override;
    ServiceRunningState QueryServiceState() const
    {
        return state_;
    }
    void SendLocationRequest(WorkRecord &workrecord) override;
    void SetEnable(bool state) override;
    void SelfRequest(bool state) override;
    int32_t Dump(int32_t fd, const std::vector<std::u16string>& args) override;
    void RequestRecord(WorkRecord &workRecord, bool isAdded) override;
    bool EnableMock(const LocationMockConfig& config) override;
    bool DisableMock(const LocationMockConfig& config) override;
    bool SetMocked(const LocationMockConfig& config, const std::vector<std::shared_ptr<Location>> &location) override;
    void SendReportMockLocationEvent() override;
    void ProcessReportLocationMock();
    bool ConnectHms();
    void notifyConnected(const sptr<IRemoteObject>& remoteObject);
    void notifyDisConnected();
private:
    bool Init();
    static void SaDumpInfo(std::string& result);
    int32_t ReportMockedLocation(const std::shared_ptr<Location> location);

    bool connectServiceReady_ = false;
    std::mutex connectMutex_;
    sptr<IRemoteObject> cloudServiceProxy_;
    std::condition_variable connectCondition_;
    std::shared_ptr<NetworkHandler> networkHandler_;
    size_t mockLocationIndex_ = 0;
    bool registerToAbility_ = false;
    ServiceRunningState state_ = ServiceRunningState::STATE_NOT_START;
};
} // namespace Location
} // namespace OHOS
#endif // NETWORK_ABILITY_H
