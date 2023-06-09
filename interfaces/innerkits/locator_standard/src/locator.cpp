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
#include "locator.h"
#include "lbs_log.h"
#include "locator_impl.h"

namespace OHOS {
namespace Location {
Locator::~Locator()
{}

std::unique_ptr<Locator> Locator::GetInstance(int systemAbilityId)
{
    std::unique_ptr<LocatorImpl> locator = std::make_unique<LocatorImpl>(systemAbilityId);
    if (locator != nullptr) {
        if (locator->Init()) {
            LBSLOGI(LOCATOR_STANDARD, "init successfully!");
            return locator;
        }
    }
    LBSLOGE(LOCATOR_STANDARD, "new locator_standard failed!");
    return nullptr;
}
}  // namespace Location
}  // namespace OHOS
