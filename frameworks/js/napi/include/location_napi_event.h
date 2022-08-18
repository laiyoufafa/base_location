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

#ifndef LOCATION_NAPI_EVENT_H
#define LOCATION_NAPI_EVENT_H

#include <string>
#include "cached_locations_callback_host.h"
#include "geofence_state.h"
#include "gnss_status_callback_host.h"
#include "location_switch_callback_host.h"
#include "locator_callback_host.h"
#include "napi/native_api.h"
#include "nmea_message_callback_host.h"
#include "request_config.h"
#include "want_agent_helper.h"

namespace OHOS {
namespace Location {
void InitOffFuncMap();
void InitOffSingleFuncMap();
bool UnsubscribeAllLocationSwitchCallback(napi_env& env);
bool UnsubscribeAllLocationChangeCallback(napi_env& env);
bool UnsubscribeAllGnssStatusCallback(napi_env& env);
bool UnsubscribeAllNmeaMessageCallback(napi_env& env);
bool UnsubscribeAllCachedLocationsCallback(napi_env& env);
bool UnsubscribeAllFenceStatueCallback(napi_env& env);
bool UnsubscribeAllCountryCodeCallback(napi_env& env);
bool OffSingleLocationServiceStateCallback(napi_env& env, napi_value& handler);
bool OffSingleLocationChangeCallback(napi_env& env, napi_value& handler);
bool OffSingleGnssStatusCallback(napi_env& env, napi_value& handler);
bool OffSinglenNmeaMessageCallback(napi_env& env, napi_value& handler);
bool OffSingleCachedLocationCallback(napi_env& env, napi_value& handler);
bool OffSingleCountryCodeChangeCallback(napi_env& env, napi_value& handler);
void SubscribeLocationServiceState(napi_env& env,
    napi_ref& handlerRef, sptr<LocationSwitchCallbackHost>& switchCallbackHost);
void SubscribeGnssStatus(napi_env& env, napi_ref& handlerRef,
    sptr<GnssStatusCallbackHost>& gnssStatusCallbackHost);
void SubscribeNmeaMessage(napi_env& env, napi_ref& handlerRef,
    sptr<NmeaMessageCallbackHost>& nmeaMessageCallbackHost);
void SubscribeLocationChange(napi_env& env, const napi_value& object,
    napi_ref& handlerRef, sptr<LocatorCallbackHost>& locatorCallbackHost);
void SubscribeCacheLocationChange(napi_env& env, const napi_value& object,
    napi_ref& handlerRef, sptr<CachedLocationsCallbackHost>& cachedCallbackHost);
void SubscribeFenceStatusChange(napi_env& env, const napi_value& object, napi_value& handler);
void UnSubscribeLocationChange(sptr<ILocatorCallback>& callback);
void UnSubscribeFenceStatusChange(napi_env& env, const napi_value& object, napi_value& handler);
void UnSubscribeCacheLocationChange(sptr<ICachedLocationsCallback>& callback);
void UnSubscribeLocationServiceState(sptr<LocationSwitchCallbackHost>& switchCallbackHost);
void UnSubscribeGnssStatus(sptr<GnssStatusCallbackHost>& gnssStatusCallbackHost);
void UnSubscribeNmeaMessage(sptr<NmeaMessageCallbackHost>& nmeaMessageCallbackHost);
bool IsCallbackEquals(napi_env& env, napi_value& handler, napi_ref& savedCallback);
void GenRequestConfig(napi_env& env, const napi_value* argv,
    size_t& objectArgsNum, std::unique_ptr<RequestConfig>& requestConfig);
napi_value RequestLocationOnce(napi_env& env, const size_t argc, const napi_value* argv);
napi_value On(napi_env env, napi_callback_info cbinfo);
napi_value Off(napi_env env, napi_callback_info cbinfo);
napi_value GetCurrentLocation(napi_env env, napi_callback_info cbinfo);
}  // namespace Location
}  // namespace OHOS
#endif // LOCATION_NAPI_EVENT_H
