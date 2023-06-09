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

#include "passive_ability_skeleton.h"

#include "ipc_skeleton.h"

#include "common_utils.h"

namespace OHOS {
namespace Location {
int PassiveAbilityStub::OnRemoteRequest(uint32_t code,
    MessageParcel &data, MessageParcel &reply, MessageOption &option)
{
    pid_t lastCallingPid = IPCSkeleton::GetCallingPid();
    pid_t lastCallinguid = IPCSkeleton::GetCallingUid();
    LBSLOGI(PASSIVE, "OnRemoteRequest cmd = %{public}u, flags= %{public}d, pid= %{public}d, uid= %{public}d",
        code, option.GetFlags(), lastCallingPid, lastCallinguid);
    if (lastCallinguid > SYSTEM_UID) {
        LBSLOGE(PASSIVE, "this remote request is not allowed");
        return EXCEPTION;
    }
    if (data.ReadInterfaceToken() != GetDescriptor()) {
        LBSLOGE(PASSIVE, "invalid token.");
        return EXCEPTION;
    }

    int ret = 0;
    switch (code) {
        case SEND_LOCATION_REQUEST: {
            int64_t interval = data.ReadInt64();
            std::unique_ptr<WorkRecord> workrecord = WorkRecord::Unmarshalling(data);
            if (workrecord != nullptr) {
                SendLocationRequest((uint64_t)interval, *workrecord);
            }
            break;
        }
        case GET_CACHED_LOCATION: {
            std::unique_ptr<Location> location = GetCachedLocation();
            if (location != nullptr) {
                location->Marshalling(reply);
            }
            break;
        }
        case SET_ENABLE: {
            SetEnable(data.ReadBool());
            break;
        }
        default:
            ret = IPCObjectStub::OnRemoteRequest(code, data, reply, option);
    }
    return ret;
}
} // namespace Location
} // namespace OHOS
