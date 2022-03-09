/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
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

#ifndef OHOS_DCAMERA_HANDLER_H
#define OHOS_DCAMERA_HANDLER_H

#include "ihardware_handler.h"

#include <set>

#include "camera_info.h"
#include "camera_input.h"
#include "camera_manager.h"
#include "json/json.h"
#include "single_instance.h"
#include "types.h"

namespace OHOS {
namespace DistributedHardware {
struct ConfigInfo {
    DCStreamType type;
    std::string formatKey;
    sptr<CameraStandard::CameraInput> cameraInput;
};

class DCameraHandler : public IHardwareHandler {
DECLARE_SINGLE_INSTANCE_BASE(DCameraHandler);
public:
    int32_t Initialize() override;
    std::vector<DHItem> Query() override;
    std::map<std::string, std::string> QueryExtraInfo() override;
    bool IsSupportPlugin() override;
    void RegisterPluginListener(std::shared_ptr<PluginListener> listener) override;

    std::vector<std::string> GetCameras();

private:
    DCameraHandler() = default;
    ~DCameraHandler();

private:
    DHItem CreateDHItem(sptr<CameraStandard::CameraInfo>& info);
    std::string GetCameraPosition(camera_position_enum_t position);
    void ConfigFormatAndResolution(ConfigInfo& info, Json::Value& outputFormat, Json::Value& resolution,
                                   std::vector<camera_format_t>& formatList, std::set<camera_format_t>& formatSet);
    bool IsValid(DCStreamType type, CameraStandard::CameraPicSize& size);

    sptr<CameraStandard::CameraManager> cameraManager_;
    std::shared_ptr<PluginListener> pluginListener_;
};

#ifdef __cplusplus
extern "C" {
#endif
__attribute__((visibility("default"))) IHardwareHandler* GetHardwareHandler();
#ifdef __cplusplus
}
#endif
} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_DCAMERA_HANDLER_H