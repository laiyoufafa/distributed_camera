/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef DISTRIBUTED_CAMERA_PROVIDER_CALLBACK_H
#define DISTRIBUTED_CAMERA_PROVIDER_CALLBACK_H

#include "dcamera_provider_callback_stub.h"

namespace OHOS {
namespace DistributedHardware {
class DCameraProviderCallback : public DCameraProviderCallbackStub {
public:
    DCameraProviderCallback() = default;
    virtual ~DCameraProviderCallback() = default;

public:
    virtual DCamRetCode OpenSession(const std::shared_ptr<DHBase> &dhBase) override;
    virtual DCamRetCode CloseSession(const std::shared_ptr<DHBase> &dhBase) override;
    virtual DCamRetCode ConfigureStreams(const std::shared_ptr<DHBase> &dhBase,
                                         const std::vector<std::shared_ptr<DCStreamInfo>> &streamInfos) override;
    virtual DCamRetCode ReleaseStreams(const std::shared_ptr<DHBase> &dhBase,
                                       const std::vector<int> &streamIds) override;
    virtual DCamRetCode StartCapture(const std::shared_ptr<DHBase> &dhBase,
                                     const std::vector<std::shared_ptr<DCCaptureInfo>> &captureInfos) override;
    virtual DCamRetCode StopCapture(const std::shared_ptr<DHBase> &dhBase) override;
    virtual DCamRetCode UpdateSettings(const std::shared_ptr<DHBase> &dhBase,
                                       const std::vector<std::shared_ptr<DCameraSettings>> &settings) override;
};
} // end namespace DistributedHardware
} // end namespace OHOS
#endif // DISTRIBUTED_CAMERA_PROVIDER_CALLBACK_H