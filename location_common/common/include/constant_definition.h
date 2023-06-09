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

#ifndef OHOS_LOCATION_CONSTANT_DEFINITION_H
#define OHOS_LOCATION_CONSTANT_DEFINITION_H

#include <string>

namespace OHOS {
namespace Location {
// error type
const int ERROR_PERMISSION_NOT_GRANTED = 0x0100;
const int ERROR_SWITCH_UNOPEN = 0x0101;
const int SESSION_START = 0x0002;
const int SESSION_STOP = 0x0003;

const int DEFAULT_TIMEOUT_30S = 30000;

const int STATE_OPEN = 1;
const int STATE_CLOSE = 0;
const int32_t PER_USER_RANGE = 100000;
const int PRIVACY_TYPE_OTHERS = 0;
const int PRIVACY_TYPE_STARTUP = 1;
const int PRIVACY_TYPE_CORE_LOCATION = 2;

const int32_t UNKNOW_USER_ID = -1;
const int32_t SUBSCRIBE_TIME = 5;
const int32_t DEFAULT_TIME_INTERVAL = 30 * 60; // app receive location every 30 minutes in frozen state
const int32_t REQUESTS_NUM_MAX = 1;
const std::string FEATURE_SWITCH_PROP = "ro.config.locator_background";
const std::string TIME_INTERVAL_PROP = "ro.config.locator_background.timeInterval";
const std::string PROC_NAME = "system";

enum {
    SCENE_UNSET = 0x0300,
    SCENE_NAVIGATION = 0x0301,
    SCENE_TRAJECTORY_TRACKING = 0x0302,
    SCENE_CAR_HAILING = 0x0303,
    SCENE_DAILY_LIFE_SERVICE = 0x0304,
    SCENE_NO_POWER = 0x0305
};

enum {
    PRIORITY_UNSET = 0x0200,
    PRIORITY_ACCURACY = 0x0201,
    PRIORITY_LOW_POWER = 0x0202,
    PRIORITY_FAST_FIRST_FIX = 0x0203
};

typedef struct {
    int reportingPeriodSec;
    bool wakeUpCacheQueueFull;
} CachedGnssLocationsRequest;

typedef struct {
    int scenario;
    std::string command;
} LocationCommand;

typedef struct {
    double latitude;
    double longitude;
    double radius;
    double expiration;
} GeoFence;

typedef struct {
    int priority;
    int scenario;
    GeoFence geofence;
} GeofenceRequest;
} // namespace Location
} // namespace OHOS
#endif // OHOS_LOCATION_CONSTANT_DEFINITION_H