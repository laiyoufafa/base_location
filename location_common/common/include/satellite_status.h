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

#ifndef OHOS_SATELLITE_STATUS_H
#define OHOS_SATELLITE_STATUS_H

#include <parcel.h>
#include <vector>

namespace OHOS {
namespace Location {
class SatelliteStatus : public Parcelable {
public:
    SatelliteStatus();
    explicit SatelliteStatus(SatelliteStatus &satelliteStatus);
    virtual ~SatelliteStatus() = default;

    inline int GetSatellitesNumber() const
    {
        return satellitesNumber_;
    }

    inline void SetSatellitesNumber(int num)
    {
        satellitesNumber_ = num;
    }

    inline std::vector<int> GetSatelliteIds() const
    {
        return satelliteIds_;
    }

    inline void SetSatelliteIds(std::vector<int> ids)
    {
        for (std::vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            satelliteIds_.push_back(*it);
        }
    }

    inline void SetSatelliteId(int id)
    {
        satelliteIds_.push_back(id);
    }

    inline std::vector<double> GetCarrierToNoiseDensitys() const
    {
        return carrierToNoiseDensitys_;
    }

    inline void SetCarrierToNoiseDensitys(std::vector<double> cn0)
    {
        for (std::vector<double>::iterator it = cn0.begin(); it != cn0.end(); ++it) {
            carrierToNoiseDensitys_.push_back(*it);
        }
    }

    inline void SetCarrierToNoiseDensity(double cn0)
    {
        carrierToNoiseDensitys_.push_back(cn0);
    }

    inline std::vector<double> GetAltitudes() const
    {
        return altitudes_;
    }

    inline void SetAltitudes(std::vector<double> altitudes)
    {
        for (std::vector<double>::iterator it = altitudes.begin(); it != altitudes.end(); ++it) {
            altitudes_.push_back(*it);
        }
    }

    inline void SetAltitude(double altitude)
    {
        altitudes_.push_back(altitude);
    }

    inline std::vector<double> GetAzimuths() const
    {
        return azimuths_;
    }

    inline void SetAzimuths(std::vector<double> azimuths)
    {
        for (std::vector<double>::iterator it = azimuths.begin(); it != azimuths.end(); ++it) {
            azimuths_.push_back(*it);
        }
    }

    inline void SetAzimuth(double azimuth)
    {
        azimuths_.push_back(azimuth);
    }

    inline std::vector<double> GetCarrierFrequencies() const
    {
        return carrierFrequencies_;
    }

    inline void SetCarrierFrequencies(std::vector<double> cfs)
    {
        for (std::vector<double>::iterator it = cfs.begin(); it != cfs.end(); ++it) {
            carrierFrequencies_.push_back(*it);
        }
    }

    inline void SetCarrierFrequencie(double cf)
    {
        carrierFrequencies_.push_back(cf);
    }

    void ReadFromParcel(Parcel& parcel);
    bool Marshalling(Parcel& parcel) const override;
    static std::unique_ptr<SatelliteStatus> Unmarshalling(Parcel& parcel);
private:
    int satellitesNumber_;
    std::vector<int> satelliteIds_;
    std::vector<double> carrierToNoiseDensitys_;
    std::vector<double> altitudes_;
    std::vector<double> azimuths_;
    std::vector<double> carrierFrequencies_;
};
} // Location
} // OHOS
#endif // OHOS_SATELLITE_STATUS_H